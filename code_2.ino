#include <LiquidCrystal.h>   // Library for LCD

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(2,3,4,5,6,7);

// Device state variables (0 = OFF, 1 = ON)
int L1=0, F1=0, F2=0, L2=0, AC=0, c=0;

int Tempsensor = A0;   // Temperature sensor connected to A0
int led1 = 8;          // LIGHT1 pin
int led2 = 10;         // LIGHT2 pin
int motor1 = 9;        // FAN1 pin
int motor2 = 11;       // FAN2 pin

// Custom character: UP arrow
byte up[8] = 
{
  B00100,
  B01110,
  B10101,
  B00100,
  B00100,
  B00100,
  B00100,
  B00000
};

// Custom character: DOWN arrow
byte down[8] = 
{
  B00100,
  B00100,
  B00100,
  B00100,
  B10101,
  B01110,
  B00100,
  B00000
};

// Function to clear a specific LCD row
void clearLine(int row)
{
  lcd.setCursor(0, row);
  lcd.print("                ");  // 16 spaces (for 16x4 LCD)
}

// Initialize LCD
void LcdBegin()
{
  lcd.begin(16,4);           // 16 columns, 4 rows
  lcd.createChar(0, up);     // Store UP arrow in memory location 0
  lcd.createChar(1, down);   // Store DOWN arrow in memory location 1
}

// Display Main Menu
void MainScreen()
{
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("1.LIGHT1 OFF ");
  lcd.setCursor(14, 0);
  lcd.write((byte)1);   // Show DOWN arrow

  lcd.setCursor(0, 1);
  lcd.print("2.FAN1 OFF ");
  lcd.setCursor(14, 1);
  lcd.write((byte)1);

  lcd.setCursor(0, 2);
  lcd.print("3.LIGHT2 OFF ");
  lcd.setCursor(14, 2);
  lcd.write((byte)1);

  lcd.setCursor(0, 3);
  lcd.print("4.AC OFF ");
  lcd.setCursor(14, 3);
  lcd.write((byte)1);
}

// Scroll screen to show FAN2 option
void ScrollupScreen()
{
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("2.FAN1 OFF ");
  lcd.setCursor(14, 0);
  lcd.write((byte)1);

  lcd.setCursor(0, 1);
  lcd.print("3.LIGHT2 OFF ");
  lcd.setCursor(14, 1);
  lcd.write((byte)1);

  lcd.setCursor(0, 2);
  lcd.print("4.AC OFF ");
  lcd.setCursor(14, 2);
  lcd.write((byte)1);

  lcd.setCursor(0, 3);
  lcd.print("5.FAN2 OFF ");
  lcd.setCursor(14, 3);
  lcd.write((byte)1);
}

void setup() 
{
  // Set pin directions
  pinMode(Tempsensor, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);

  LcdBegin();     // Initialize LCD
  MainScreen();   // Show main menu
  
  Serial.begin(9600);  // Start serial communication
}

void loop() 
{
  // Read temperature sensor value
  int sensorValue = analogRead(Tempsensor);
  
  // Convert ADC value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Convert voltage to temperature (for LM35: 10mV per °C)
  int Templevel = voltage * 100;
  
  // Check if data received from Serial
  if (Serial.available() > 0) 
  {
    char received = Serial.read();  // Read command

    // ---- LIGHT1 CONTROL ----
    if (received == '7') 
    {
      L1 = !L1;   // Toggle state

      if(L1==1)
      { 
        clearLine(0);
        lcd.setCursor(0, 0);
        lcd.print("1.LIGHT1 ON");
        lcd.setCursor(14, 0);
        lcd.write((byte)0);   // UP arrow
        lcd.blink();          // Blink cursor
        digitalWrite(led1, HIGH);
      }
      else
      {
        lcd.setCursor(0, 0);
        lcd.print("1.LIGHT1 OFF");
        lcd.setCursor(14, 0);
        lcd.write((byte)1);   // DOWN arrow
        lcd.noBlink();
        digitalWrite(led1, LOW);
      }
      delay(300);
    }

    // ---- FAN1 CONTROL ----
    else if (received == '8') 
    {
      F1 = !F1;

      if(F1)
      { 
        clearLine(1);
        lcd.setCursor(0, 1);
        lcd.print("2.FAN1 ON");
        lcd.setCursor(14, 1);
        lcd.write((byte)0);
        lcd.blink();
        digitalWrite(motor1, HIGH);
      }
      else
      {
        lcd.setCursor(0, 1);
        lcd.print("2.FAN1 OFF");
        lcd.setCursor(14, 1);
        lcd.write((byte)1);
        lcd.noBlink();
        digitalWrite(motor1, LOW);
      }
      delay(300);
    }

    // ---- LIGHT2 CONTROL ----
    else if (received == '9') 
    {
      L2 = !L2;

      if(L2)
      { 
        clearLine(2);
        lcd.setCursor(0, 2);
        lcd.print("3.LIGHT2 ON");
        lcd.setCursor(14, 2);
        lcd.write((byte)0);
        lcd.blink();
        digitalWrite(led2, HIGH);
      }
      else
      {
        lcd.setCursor(0, 2);
        lcd.print("3.LIGHT2 OFF");
        lcd.setCursor(14, 2);
        lcd.write((byte)1);
        lcd.noBlink();
        digitalWrite(led2, LOW);
      }
      delay(300);
    }

    // ---- AC CONTROL ----
    else if (received == '4') 
    {
      AC = !AC;

      if(AC)
      { 
        clearLine(3);
        lcd.setCursor(0, 3);
        lcd.print("4.AC ON- T:");
        lcd.setCursor(14, 3);
        lcd.write((byte)0);
      }
      else
      {
        clearLine(3);
        lcd.setCursor(0, 3);
        lcd.print("4.AC OFF");
        lcd.setCursor(14, 3);
        lcd.write((byte)1);
        lcd.noBlink();
      }
      delay(300);
    }

    // ---- FAN2 CONTROL WITH SCROLL ----
    else if (received == '5') 
    {
      if(c==0)
      {
        lcd.clear();
        delay(200);
        ScrollupScreen();
        delay(300);
        c++;
      }
     
      F2 = !F2;

      if(F2)
      { 
        clearLine(3);
        lcd.setCursor(0, 3);
        lcd.print("5.FAN2 ON");
        lcd.setCursor(14, 3);
        lcd.write((byte)0);
        lcd.blink();
        digitalWrite(motor2, HIGH);
      }
      else
      {
        lcd.setCursor(0, 3);
        lcd.print("5.FAN2 OFF");
        lcd.setCursor(14, 3);
        lcd.write((byte)1);
        lcd.noBlink();
        digitalWrite(motor2, LOW);
        c=0;  // Reset scroll state
      }
      delay(300);
    }
    else
    {
      MainScreen();  // If invalid key, return to main menu
    }
  }

  // If AC is ON, continuously display temperature
  if(AC)
  {
    lcd.setCursor(11,3);
    lcd.print("   ");        // Clear old temp
    lcd.setCursor(11,3);
    lcd.print(Templevel);    // Print new temp
    lcd.blink();
  }

  delay(200);
}
