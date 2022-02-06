#define txPin 9 //пин передатчика
#define ledPin 13 //пин передатчика


void setup()
{
  pinMode(txPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(921600);  // тут поставьте свою скорость
  Serial.println("Came started");
}

void loop() {
  // это раскомментить и вместо 3693 вписать свой код для шлагбаума
  digitalWrite(ledPin, HIGH);
  SendCame4(2218);
  digitalWrite(ledPin, LOW);
  delay(15000);
}

// функция отправляет код в эфир
void SendCame4(long Code) {
  for (int j = 0; j < 10; j++) { // посылку посылаем 4 раза подряд.
    // время стартового импульса 
    digitalWrite(txPin, HIGH);
    delayMicroseconds(320);
    digitalWrite(txPin, LOW);
    for (int i = 12; i > 0; i--) {
      byte b = bitRead(Code, i - 1); // побитово перебираем и посылаем код
      if (b) {
        digitalWrite(txPin, LOW); // 1
        delayMicroseconds(640);
        digitalWrite(txPin, HIGH);
        delayMicroseconds(320);
      }
      else {
        digitalWrite(txPin, LOW); // 0
        delayMicroseconds(320);
        digitalWrite(txPin, HIGH);
        delayMicroseconds(640);
      }
    }
    digitalWrite(txPin, LOW);
    delayMicroseconds(11520);
  }
}
