#include <Arduino.h>

int ledPin = 13;
int dotDuration = 200; // milliseconds for a dot

String inputMessage = ""; // String to hold the incoming message
bool newMessage = false;  // Flag to indicate a new message is ready

void morseDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(dotDuration);
}

void morseDash() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration * 3);
  digitalWrite(ledPin, LOW);
  delay(dotDuration);
}

void playMorse(char character) {
  // Convert character to lowercase to simplify checks
  character = toLowerCase(character);

  switch (character) {
    case 'a':
      morseDot(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'b':
      morseDash(); morseDot(); morseDot(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;  

    case 'c':
      morseDash(); morseDot(); morseDash(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'd':
      morseDash(); morseDot(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'e':
       morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'f':
      morseDot(); morseDot(); morseDash(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'g':
      morseDash(); morseDash(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'h':
      morseDot(); morseDot(); morseDot(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'i':
      morseDot(); morseDot(); 
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'j':
      morseDot(); morseDash(); morseDash(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'k':
      morseDash(); morseDot(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'l':
      morseDot(); morseDash(); morseDot(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'm':
      morseDash(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'n':
      morseDash(); morseDot(); 
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'o':
      morseDash(); morseDash(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'p':
      morseDot(); morseDash(); morseDash(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 'q':
      morseDash(); morseDash(); morseDot(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;  

    case 'r':
      morseDot(); morseDash(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;  

    case 's':
      morseDot(); morseDot(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;

    case 't':
      morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;  

    case 'u':
      morseDot(); morseDot();  morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;  

    case 'v':
      morseDot(); morseDot(); morseDot(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;  

    case 'w':
      morseDot(); morseDot(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;     

    case 'x':
      morseDash(); morseDot(); morseDot(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;  

    case 'y':
      morseDash();  morseDot(); morseDash(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;  

    case 'z':
      morseDash();  morseDash(); morseDot(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;  

    case '1':
       morseDot(); morseDash();  morseDash(); morseDash(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;     

    case '2':
       morseDot(); morseDot();   morseDash(); morseDash(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;  

    case '3':
       morseDot(); morseDot();  morseDot(); morseDash(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break; 

    case '4':
       morseDot(); morseDot();  morseDot(); morseDot(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break;    

    case '5':
       morseDot(); morseDot();  morseDot(); morseDot(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break;    

    case '6':
       morseDash(); morseDot();  morseDot(); morseDot(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break; 

    case '7':
       morseDash(); morseDash();  morseDot(); morseDot(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break; 

    case '8':
       morseDash(); morseDash();  morseDash(); morseDot(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break; 

    case '9':
       morseDash(); morseDash();  morseDash(); morseDash(); morseDot();
      delay(dotDuration * 2); // Gap between letters
      break; 

    case '0':
       morseDash(); morseDash();  morseDash(); morseDash(); morseDash();
      delay(dotDuration * 2); // Gap between letters
      break; 

    case ' ':
      delay(dotDuration * 4); // Gap between words (longer)
      break;
    default:
      // Ignore characters that don't have Morse code defined
      break;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("Morse Code Interpreter Ready!");
  Serial.println("Type a word (e.g., 'sos') and press Enter:");
}

void loop() {
  // Check if data is available on the serial port
  while (Serial.available() > 0) {
    // Read the incoming byte:
    char inChar = (char)Serial.read();

    // If the incoming character is a newline (Enter), set a flag
    // so the main loop can process the message
    if (inChar == '\n') {
      newMessage = true;
    } else {
      // Add the character to the inputMessage String
      inputMessage += inChar;
    }
  }

  // Check if a new message is complete and ready to process
  if (newMessage) {
    Serial.print("Playing: ");
    Serial.println(inputMessage);

    // Loop through each character in the message and play its Morse code
    for (int i = 0; i < inputMessage.length(); i++) {
      playMorse(inputMessage[i]);
    }

    Serial.println("Done. Type a new word:");
    
    // Clear the string and reset the flag for the next message
    inputMessage = "";
    newMessage = false;
  }
}

