char rec;
int se=A0;
int sp=7;
void setup() {
 pinMode(11,OUTPUT);
 pinMode(7,OUTPUT);
 digitalWrite(sp,LOW);
 Serial.begin(115200);
}
int readData(){
  digitalWrite(sp,HIGH);
  delay(1);
  int val=analogRead(A0);
  digitalWrite(sp,LOW);
  return val;
}
void loop() {
  int level=readData();
  Serial.print("Water level is: ");
  Serial.println(level);
  delay(10);
  if(Serial.available()>0)
  {
    rec=Serial.read();
    if(rec=='2')
    {
      analogWrite(11,55);
    }
    else if(rec=='1')
    {
      analogWrite(11,190);
    }
    else if(rec=='0')
    {
      analogWrite(11,255);
    }
  }
}