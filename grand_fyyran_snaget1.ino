
const int buttonPin = 2;   
const int ledPin = 13;      
int ledState = LOW;    
int buttonState=HIGH;             
int lastButtonState =LOW;
int counter=0;
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
   
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        counter++;
        Serial.print("Button Pressed!Count: ");
        Serial.println(counter);
        digitalWrite(ledPin,HIGH);
        delay(100);
        digitalWrite(ledPin,LOW);
      }
    }
  }
  lastButtonState = reading;
}