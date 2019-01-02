// Written for Teensy++ 2.0
// Example for Teensy keyboard:
// http://www.pjrc.com/teensy/td_keyboard.html
// In Tools>USB type, set to "Keyboard + Mouse + Joystick"
// Ctrl+Shift+Alt+F10 key combo == Play or Pause
// Ctrl+Shift+Alt+F11 key combo == Next song 
// Ctrl+Shift+Alt+F9 key combo == Previous song
// Enter these key combos in foobar's Configure>General>Keyboard Shortcuts
// menu. Hit "Add New" in the upper section. Find the desired Action
// in the lower section. It may be helpful to filter by "Play" and look
// in the Playback section. Select the desired action. Then type the 
// key combo in the Key entry field in the lower section, and check 
// the Global Hotkey box so that the key combo is recognized regardless
// of what other program has focus at any given time. 

byte LEDpin = 6;
byte prevPin = 7; 
byte playPin = 8;
byte skipPin = 9;

void setup() {
  // Make playPin and skipPin digital inputs
  // and activate their internal pullup resistors
  pinMode(playPin, INPUT_PULLUP);
  pinMode(skipPin, INPUT_PULLUP);
  pinMode(prevPin, INPUT_PULLUP);
  // Set the LED on pin 6 to output mode
  pinMode(LEDpin, OUTPUT);
  digitalWrite(LEDpin, LOW);


  // initialize control over the keyboard:
  Keyboard.begin();
  // Optional serial monitor code for debug:
//  Serial.begin(115200);
//  while(!Serial);
//  Serial.println("Hello");
}

void loop() {

    if (digitalRead(playPin) == LOW){
      digitalWrite(LEDpin, HIGH);
      pressPlay();
      delay(200);
      digitalWrite(LEDpin, LOW);
    } // end of if statement
    if (digitalRead(skipPin) == LOW){
      digitalWrite(LEDpin, HIGH);
      pressSkip();
      delay(200);
      digitalWrite(LEDpin, LOW);
    }
    if (digitalRead(prevPin) == LOW){
      digitalWrite(LEDpin, HIGH);
      pressPrev();
      delay(200);
      digitalWrite(LEDpin, LOW);
    }
} // end of main loop

// Function to send Ctrl+Shift+Alt+F10 key combo
// to computer, should play/pause FooBar.
void pressPlay(void){
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT | MODIFIERKEY_ALT);
//  keyboard_modifier_keys = KEY_CTRL | KEY_SHIFT | KEY_ALT; 
  Keyboard.send_now();
  delay(50);
  Keyboard.set_key1(KEY_F10);
  Keyboard.send_now();
  delay(100);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(350);
}

// Function to send Ctrl+Shift+Alt+F11 key combo
// to computer, should skip to the next song in FooBar.
void pressSkip(void){
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT | MODIFIERKEY_ALT);
//  keyboard_modifier_keys = KEY_CTRL | KEY_SHIFT | KEY_ALT; 
  Keyboard.send_now();
  delay(50);
  Keyboard.set_key1(KEY_F11);
  Keyboard.send_now();
  delay(100);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(150);
}

// Function to send Ctrl+Shift+Alt+F9 key combo
// to computer, should skip to the prev song in FooBar.
void pressPrev(void){
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT | MODIFIERKEY_ALT);
//  keyboard_modifier_keys = KEY_CTRL | KEY_SHIFT | KEY_ALT; 
  Keyboard.send_now();
  delay(50);
  Keyboard.set_key1(KEY_F9);
  Keyboard.send_now();
  delay(100);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(150);
}
