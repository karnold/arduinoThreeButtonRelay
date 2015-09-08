const int lightPins[] = {2, 3, 4};
const int switchPins[] = {5, 6, 7};
const int triggerPin = 8;

const int pinOrder[] = { 0, 1, 2};
const int triggerDelay = 10000;

boolean pinState[] = { false, false , false};

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i < 3; i++) {
    pinMode(lightPins[i], OUTPUT);
    pinMode(switchPins[i], INPUT); 
  }
  
  pinMode(triggerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  for (int i=0; i < 3; i++) {
    
    if (digitalRead(switchPins[i]) == HIGH) {
      digitalWrite(lightPins[i], LOW);
    } else {
      digitalWrite(lightPins[i], HIGH);
    }
  }

  if (pinState[pinOrder[0]] == false) {
    Serial.println("step 1");

    if (digitalRead(switchPins[pinOrder[0]]) == HIGH) {
      digitalWrite(lightPins[pinOrder[0]], LOW);
      pinState[pinOrder[0]] = true;
    }

    return;
  }

  if (pinState[pinOrder[1]] == false) {
    Serial.println("step 2");
    if (digitalRead(switchPins[pinOrder[1]]) == HIGH) {
      digitalWrite(lightPins[pinOrder[1]], LOW);
      pinState[pinOrder[1]] = true;
    }

    return;
  }

  if (pinState[pinOrder[2]] == false) {
    Serial.println("step 3");
    if (digitalRead(switchPins[pinOrder[2]]) == HIGH) {
      pinState[pinOrder[2]] = true;
//      digitalWrite(lightPins[pinOrder[2]], LOW);

      pinState[0] = false;
      pinState[1] = false;
      pinState[2] = false;
      
      digitalWrite(triggerPin, HIGH);
      delay(triggerDelay);
      digitalWrite(triggerPin, LOW);
    }

    return;
  }
}
