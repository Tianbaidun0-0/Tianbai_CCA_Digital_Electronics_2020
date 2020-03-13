/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/
int red = 9;
int green = 10;
int blue = 11;
int Rbrightness = 0; //R
int Gbrightness = 0; //G
int Bbrightness = 0; //B how bright the LED is
int RfadeAmount = 5;    // how many points to fade the LED by
int GfadeAmount = 7;
int BfadeAmount = 9;
int threshold = 26  ;

int redMin = 0;
int redMax = 255;

// S tab of the Temperature Sensor connected to A3
int sensorPin = A3; 
int fan = 8;
int fanSpeed = 0;
int fadeAmount = 5;

 
// the setup routine runs once when you press reset:
void setup() {
  // Initialize Serial, set the baud rate to 9600 bps.
  Serial.begin(9600);
  // Set the temperature sensor pin as an INPUT:
  pinMode(sensorPin, INPUT);
  // declare LED pins to be outputs:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(fan, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

// ++ temperature sensor code
   // Variable to store raw temperature
  long rawTemp;

  // Variable to store voltage calculation
  float voltage;

  // Variable to store Fahrenheit value
  float fahrenheit;

  // Variable to store Celsius value
  float celsius;

// TEMPERATURE SENSOR  ++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Read the raw 0-1023 value of temperature into a variable.
  rawTemp = analogRead(sensorPin);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++

  
// FAN ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // fan coding
    fanSpeed = Rbrightness;
    analogWrite(fan, fanSpeed);
    
  
//  fanSpeed = Rbrightness + fadeAmount;
//  if (Rbrightness <= 0 || Rbrightness >= 255) {
//    fadeAmount = -fadeAmount;
//  }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  

  // Calculate the voltage, based on that value.
  // Multiply by maximum voltage (5V) and divide by maximum ADC value (1023).
  // If you plan on using this with a LilyPad Simple Arduino on USB power, change to 4.2
  voltage = rawTemp * (5 / 1023.0);
  //Serial.print("Voltage: "); // Print voltage reading to serial monitor
  //Serial.println(voltage);

  // Calculate the celsius temperature, based on that voltage..
  celsius = (voltage - 0.5) * 100;
  Serial.print("Celsius: "); // Print celcius temp to serial monitor
  Serial.println(celsius);

  // Use a common equation to convert celsius to Fahrenheit. F = C*9/5 + 32.
 // fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  //Serial.print("Fahrenheit: "); // Print Fahrenheit temp to serial monitor
  //Serial.println(fahrenheit); 
  // Print a blank line
  // Serial.println();       

  // Wait 1 second between readings
  delay(10); 

// ++++++++++++++++++++++++++++++++++++++++++++++++++++

  // if temperature sensor is higher than 20 Celcius
  // LED will be RED

     //Rbrightness = map(celsius, 20, 40, 0, 255);
     //Bbrightness = map(celsius, 19, 20, 255, 0);
     
  
if(celsius > threshold){
//  // make LED red
Rbrightness = 255;
Bbrightness = 0;
 } else {
Rbrightness = 0; 
Bbrightness = 255;
}

  // if temperature sensor is lower than 20 Celcius
  // LED will be BLUE
  
  // set the brightness of LEDs:
  analogWrite(red, Rbrightness);
  analogWrite(green, Gbrightness);
  analogWrite(blue, Bbrightness);
 //+++++++++++++++++++++++++++++++++++++++++++++++++++++
 //potentionmeter coding
  int analogValue = analogRead(A1);

  // scales it to brightness (value between 0 and 255)
 Gbrightness = map(analogValue, 0, 1023, 0, 255);
//
//  // sets the brightness LED that connects to  pin 3
analogWrite(green, Gbrightness);

//print out the value
 //Serial.print("redMin ");
  Serial.print(analogValue);
Serial.print( "Rbightness" );
Serial.println(Gbrightness);
delay(400);
 



}
