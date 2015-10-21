#include <RFduinoGZLL.h>

//Look into PWM for servo instead of using servo lib because both depend on timing

int servo = 4;
int pos = 0;

device_t role = HOST;

char state = 0;

int pot = 2;
int val = 0;
int r = 0;
int g = 0;
int b = 0;

void setup() {
  Serial.begin(9600);
  //pinMode(pot, INPUT);

  RFduinoGZLL.txPowerLevel = 0;

  RFduinoGZLL.begin(role);


}

void loop() {
  val = analogRead(pot);
  Serial.println(val);
  RFduinoGZLL.sendToHost(val);
  delay(250);

  
  for (int movement = 0; movement <= pos; movement += 5) {
    analogWrite(servo, movement);
    delay(30);
  }

}

void RFduinoGZLL_onReceive(device_t device, int rssi, char *data, int len)
{
  
//  Serial.print(device);
//  Serial.print(",");
//  Serial.print(abs(rssi));
//  Serial.print(",");
//  Serial.println(data);
//  Serial.print(",");
//  Serial.print(len);
  String data1 = data;
  if (data1[0] = 'B'){
    Serial.println(data1.substring(1,5));
    int pos = data1[1,5];
  }
  
  
//  if (device == DEVICE1)  // relay the last known state to DEVICE1
//    RFduinoGZLL.sendToDevice(device, state);
}
