#include <SoftwareSerial.h>

SoftwareSerial esp8266(2,3);

void setup() 
{
  Serial.begin(9600);
  esp8266.begin(9600);
 
}

void loop()
{
  while(esp8266.available())
  {
    char c = esp8266.read();
    Serial.write(c);
  }

  if(Serial.available())
  {
    delay(1000);

    String command="";

    while(Serial.available())
    {
      command += (char)Serial.read();
    }
    esp8266.println(command);
  }
}
