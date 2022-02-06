int inPin = 7; 
boolean val = 0;  
boolean val_old = 1;
int sch=0;  
unsigned long t=0;
unsigned long time=0;
unsigned long time_old=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //устанавливаем скорость 9600 бит/сек
  pinMode(inPin, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inPin);
  if(val!=val_old){
    t=micros();
    time=t-time_old;
    time_old=t;
    Serial.print(val_old);
    Serial.println(time);
    val_old=val;
  }
  //Serial.write(val);
}
