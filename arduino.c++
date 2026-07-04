#include <LiquidCrystal.h> //includes LCD library.
LiquidCrystalMyLCD(2, 3, 4, 5, 6, 7); // Defining LCD.
int Sensor_pin = A5; // LM 35 is connected to A5 Pin.

void setup()
{
Serial.begin(9600);
MyLCD.begin(16, 2);
MyLCD.clear(); // Clearing LCD
MyLCD.home();
MyLCD.print("INITIALIZE MODEM");
delay(12000);
Serial.println("AT+CMGF=1");
delay(3000);
}

void loop()
{
int temp;
MyLCD.clear(); // Clearing LCD
MyLCD.home();
MyLCD.print("ADC VALUE: ");
MyLCD.setCursor(0,1);

51
MyLCD.print("STATUS: ");
MyLCD.setCursor(10,0);
temp = analogRead(Sensor_pin);
MyLCD.print(temp);
if(temp > 100)
{
SendSMS();
while(1);
}
else
{
MyLCD.setCursor(0,8);
MyLCD.print("NORMAL");
}
delay(1000);
}

void SendSMS() // sends message to consumers
{
MyLCD.setCursor(0,1);
MyLCD.print(" SEND SMS... ");
Serial.println("AT+CMGS=\"+917871625136\"\r");
delay(12000);
Serial.println(" WARNING THEFT.. ");
delay(200);
Serial.println((char)26);
delay(20000);
MyLCD.setCursor(0,0);
MyLCD.print("DETECTION THEFT ");

52

MyLCD.setCursor(0,1);
MyLCD.print(" SMS TX NUM_1 ");

//Serial.println("AT+CMGS=\"+917871625136\"\r");
//delay(12000);
//Serial.println("WARNING OVER LOAD!");
//delay(200);
//Serial.println((char)26);
//delay(5000);
//MyLCD.setCursor(0,1);
//MyLCD.print(" SMS TX NUM_2 ");
}