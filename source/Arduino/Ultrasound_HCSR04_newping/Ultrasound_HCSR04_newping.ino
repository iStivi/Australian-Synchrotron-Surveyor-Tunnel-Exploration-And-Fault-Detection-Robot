#include <NewPing.h>

const int MAX_DISTANCE = 300;

const int NUMBER_OF_SENSORS = 6;
const String sensorName[NUMBER_OF_SENSORS] = {"nw","n","ne","sw","s","se"};
NewPing sonar[NUMBER_OF_SENSORS] = {
  NewPing(2, 2, MAX_DISTANCE),
  NewPing(3, 3, MAX_DISTANCE),
  NewPing(4, 4, MAX_DISTANCE),
  NewPing(5, 5, MAX_DISTANCE),
  NewPing(6, 6, MAX_DISTANCE),
  NewPing(7, 7, MAX_DISTANCE)
};  

void setup() {
  
  // initialize serial communication:
  Serial.begin(9600);
}

void loop()
{

  for(int sensor_no = 0; sensor_no < NUMBER_OF_SENSORS; sensor_no++){
    Serial.print(sensorName[sensor_no]);
    Serial.print(" ");
   
    unsigned int uS = sonar[sensor_no].ping();
    long distance = uS / US_ROUNDTRIP_CM;
    Serial.print(" ");
    Serial.print(distance);
    Serial.print("cm");  
    Serial.println();
    delay(60);
  }
}

long usToCm(long microseconds)
{
  
  return microseconds / 58;
}
