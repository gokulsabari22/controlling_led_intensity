/*
Description:
This Arduino code controls the intensity of an LED using pulse-width modulation (PWM)
based on the input of two push buttons. The LED is connected to pin 3 via a 220-ohm resistor.
Two push buttons are connected to pins 6 and 9, respectively. Each push button is supplied
with +5V power and connected to its respective pin. A 10k-ohm resistor is connected
between each push button's pin and ground.
*/


// Define LED pin and button pins
const int LEDPIN = 3;
const int PUSHBUTTON1 = 6;
const int PUSHBUTTON2 = 9;

// Variables to store Button state 
int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  // Initialize LED pin as output
  pinMode(LEDPIN, OUTPUT);
  // Initialize Button pin as input
  pinMode(PUSHBUTTON1, INPUT_PULLUP);
  pinMode(PUSHBUTTON2, INPUT_PULLUP);
}

void loop() {
  // Read the state of the button
  buttonState1 = digitalRead(PUSHBUTTON1);
  buttonState2 = digitalRead(PUSHBUTTON2);

  // Adjust LED intensity based on button states
  if (buttonState1 == LOW && buttonState2 == LOW){
    analogWrite(LEDPIN, 255); // 100% intensity
  } else if (buttonState1 == LOW){
    analogWrite(LEDPIN, 191); // 75% intensity
  } else if (buttonState2 == LOW){
    analogWrite(LEDPIN, 127); // 50% intensity
  } else{
    analogWrite(LEDPIN, 64); // 25% intensity
  }
}
