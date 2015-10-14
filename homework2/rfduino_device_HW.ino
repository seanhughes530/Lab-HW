#include <RFduinoGZLL.h>

device_t role = DEVICE1;

// pin for the light sensor
int pot = 2;


int xpin = 2;
int ypin = 4;
int zpin = 6;

int xval = 0;
int yval = 0;
int zval = 0;

int xvalp = 0;
int yvalp = 0;
int zvalp = 0;

double x;
double y;
double z;



void setup()
{
  Serial.begin(9600);
  pinMode(pot, INPUT);
//  pinMode(xpin, INPUT);
//  pinMode(ypin, INPUT);
//  pinMode(zpin, INPUT);

  RFduinoGZLL.txPowerLevel = 0;

  // start the GZLL stack
  RFduinoGZLL.begin(role);
}

void loop()
{
  char xdata[4];   //declaring character array
  char ydata[4];
  char zdata[4];
  char mydata[12];

  String xstr;
  String ystr;
  String zstr;//declaring string
  String mystr;

  xval = analogRead(xpin);
  yval = analogRead(ypin);
  zval = analogRead(zpin);
//  xval = 100;
//  yval = 200;
//  zval = 300;

  
  if (xval > 999) {
    xval = 999;
  }
  
  if (xval >= 100)
  {
    xstr = String(xval);
  }
  else if (xval < 100 && xval >= 10) {
    xstr = String(0) + String(xval);
  }
  else if (xval < 10) {
    xstr = String(0) + String(0) + String(xval);
  }
  
  
  if (yval >= 100)
  {
    ystr = String(yval);
  }
  else if (yval < 100 && yval >= 10) {
    ystr = String(0) + String(yval);
  }
  else if (yval < 10) {
    ystr = String(0) + String(0) + String(yval);
  }
  
  
  if (zval >= 100)
  {
    zstr = String(zval);
  }
  else if (zval < 100 && zval >= 10) {
    zstr = String(0) + String(zval);
  }
  else if (xval < 10) {
    zstr = String(0) + String(0) + String(zval);
  }

  xstr.toCharArray(xdata, 4); //passing the value of the string to the character array
  ystr.toCharArray(ydata, 4);
  zstr.toCharArray(zdata, 4);
 

  mystr = "F" + xstr;

  mystr.toCharArray(mydata, 5); 

// Serial.print(xdata);
//  Serial.print(", ");
//  Serial.print(ydata);
//  Serial.print(", ");
//  Serial.print(zdata);
//  Serial.print(", ");
  Serial.println(mydata);

 RFduinoGZLL.sendToHost(mydata, 5);
    delay(250);


}

//void RFduinoGZLL_onReceive(device_t device, int rssi, char *data, int len)
//{
//  // ignore acknowledgement without payload
//  if (len > 0)
//  {
//    // set the Green led if this device is the closest device
//    device_t closest_device = (device_t)data[0];
//    Serial.println((device_t)data[0]);
//    //digitalWrite(green_led, (role == closest_device));
//  }
//}
