

#include <Arduino_HTS221.h>

int seq=0;

void setup() {

  pinMode(2,OUTPUT);


  Serial.begin(9600);
  while (!Serial);

  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }
}

void loop() {
  // read all the sensor values
  seq = seq%3;
  float temperature = HTS.readTemperature();
 

  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");



  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(500);

  switch(seq){

    case 0:

      if(temperature > 30){

        digitalWrite(2,true);
  
        delay(6e5);
        seq++;
        }
  
      break;

    case 1:

      if(temperature > 30){

        digitalWrite(2,false);
        delay(500);
        digitalWrite(2,true);
        
  
        }
      else{
        seq++;
        }
      break;

    case 2:
      digitalWrite(2,false);
      seq++;
      break;

  }


    
  
    

}
