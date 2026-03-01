#include <Keypad.h>   // Library for 4x4 Matrix Keypad

// Define number of rows and columns
const byte rows = 4;
const byte cols = 4;

// Key layout (as printed on keypad)
char keys[rows][cols] = 
{
  {'1','2','3','A'},   // Row 1
  {'4','5','6','B'},   // Row 2
  {'7','8','9','C'},   // Row 3
  {'*','0','#','D'}    // Row 4
};

// Arduino pins connected to keypad rows
byte rowPins[rows] = {9,8,7,6};

// Arduino pins connected to keypad columns
byte colPins[cols] = {5,4,3,2};

// Create keypad object
// makeKeymap(keys) maps the physical keys
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

void setup() 
{
  Serial.begin(9600);   // Start serial communication at 9600 baud rate
}

void loop() 
{
  // Read pressed key (returns character if pressed, else NO_KEY)
  char key = keypad.getKey();
  
  // If a key is pressed
  if (key) 
  {
    Serial.write(key);   // Send key value to Serial Monitor or another device
  }
}
