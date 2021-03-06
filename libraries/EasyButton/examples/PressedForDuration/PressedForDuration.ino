/*
 Name:		PressedForDuration.ino
 Created:	9/5/2018 10:49:52 AM
 Author:	Evert Arias
 Description: Example to demostrate how to use the library to detect a pressed for a given duration on a button.
*/

#include <EasyButton.h>

// Arduino pin where the button is connected to.
#define BUTTON_PIN 26

// Instance of the button.
EasyButton button(BUTTON_PIN);

// Callback function to be called when the button is pressed.
void onPressedForDuration() {
	Serial.println("Button has been pressed!");
}

void setup() {
	// Initialize Serial for debuging purposes.
	Serial.begin(115200);
	// Initialize the button.
	button.begin();
	// Add the callback function to be called when the button is pressed for at least the given time.
	button.onPressedFor(2000, onPressedForDuration);
}

void loop() {
	// Continuously read the status of the button. 
	button.read();
}
