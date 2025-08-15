int led1 = 5;
void setup() 
{
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
}

void loop() 
{
  while(!Serial.available());
  byte value = Serial.read();
  switch(value)
  {
    case 'A':
      digitalWrite(led1,HIGH);
      break;
    case 'F':
      digitalWrite(led1,LOW);
      break; 
  }
}

