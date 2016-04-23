/*
HC-06 Bluetooth simple setup sketch

*** Important. If you change the HC-06 baud rate, you must change the "myserial" baud to match what was just set. 
* Steps:

Changing default 9600 baud to 57600 baud needed to communicate raw data from TGAM1 chip
1) uncomment (remove the double backslash) the line:  //btSerial.begin(9600); 
2) uncomment the line:  //btSerial.print("AT+BAUD7"); // Set baudrate to 57600
3) run the sketch.  This will set the baud to 57600.  However, you may not see the response OK. 
4) comment out (add double backslash back) the line btSerial.begin(9600);
5) uncomment the line //btSerial.begin(57600); and compile and load the sketch again - this sets "btSerial" to the new setting.
6) open the serial monitor from the Arduino IDE - this will restart the sketch.  Be sure that the communication speed 
on the serial monitor is set to 57600.  If all is well you should see a secomd line after "Hello Bluetooth"
that will show the BT module responding to the change.
7) you can verify the connection by typing "AT" in the serial terminal and sending.  You should recieve "OK" back


*/
#include <SoftwareSerial.h>

SoftwareSerial btSerial(3, 4); // RX, TX

void setup()
{
pinMode(3, INPUT_PULLUP);
//Serial.begin(9600);
//Serial.begin(57600);
Serial.println("Hello Bluetooth"); //prints in serial monitor when it is opened
//hc-06Serial.begin(9600);
//hc-06Serial.begin(57600);  //if you change the baud and want to re-run this sketch, make sure this baud rate matches the new rate.

//delay(1000);
//hc-06Serial.println("AT+RESET");
delay(1000);

btSerial.print("AT"); //pings the HC-06 - should send back OK to serial monitor
delay(1000);
btSerial.print("AT+PIN1234"); // Set pin to 1234
//delay(1000);
//hc-06Serial.print("AT+NAMEBrain"); // Set the name to Brain
//delay(1000);
//btSerial.print("AT+BAUD4"); // Set baudrate to 9600
//hc-06Serial.print("AT+BAUD7"); // Set baudrate to 57600
//Serial.write(mySerial.read());
delay(1000);
}

void loop() // run over and over
{
if (btSerial.available())
Serial.write(btSerial.read());
//Serial.println(btSerial.read());
if (Serial.available())
btSerial.write(Serial.read());
}
