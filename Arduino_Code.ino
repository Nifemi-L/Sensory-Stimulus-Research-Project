int butPinA = 4;
int butPinB = 8;
int butPinC = 9;
int butPinD = 10;
int tonePin = 2;
int ledGreenPin = 13;
int ledRedPin = 12;
int valA;
int valB;
int valC;
int valD;
int question = 1;
int correct = 0;
bool resultA = false;
bool resultB = false;
bool resultC = false;
bool resultD = false;

void setup() {
  Serial.begin(9600);
  pinMode(butPinA, INPUT);
  pinMode(butPinB, INPUT);
  pinMode(butPinC, INPUT);
  pinMode(butPinD, INPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);
}

void correctFunc() {
  correct++;
  question++;
  digitalWrite(ledGreenPin, HIGH);
  tone(tonePin, 440, 100);
  delay(200);
  tone(tonePin, 440, 100);
  delay(200);
  tone(tonePin, 440, 100);
  delay(100);
  digitalWrite(ledGreenPin, LOW);
}

void wrongFunc() {
  question++;
  digitalWrite(ledRedPin, HIGH);
  tone(tonePin, 220, 500);
  delay(500);
  digitalWrite(ledRedPin, LOW);
}

void results() {
  Serial.println("Results: ");
  Serial.print(correct);
  Serial.print("/");
  Serial.print(question - 1);
  Serial.println(" questions correct");
  if (resultA == true) {
    Serial.println("Question A: Correct");
  } else {
    Serial.println("Question A: Incorrect");
  }
  if (resultB == true) {
    Serial.println("Question B: Correct");
  } else {
    Serial.println("Question B: Incorrect");
  }
  if (resultC == true) {
    Serial.println("Question C: Correct");
  } else {
    Serial.println("Question C: Incorrect");
  }
  if (resultD == true) {
    Serial.println("Question D: Correct");
  } else {
    Serial.println("Question D: Incorrect");
  }
}

void loop() {
  valA = digitalRead(butPinA);
  valB = digitalRead(butPinB);
  valC = digitalRead(butPinC);
  valD = digitalRead(butPinD);
  
  if (question == 1) {
    if (valB == HIGH || valA == HIGH || valD == HIGH) {
      wrongFunc();
    } else if (valC == HIGH) {
      correctFunc();
      resultA = true;
    }
  } else if (question == 2) {
    if (valC == HIGH || valA == HIGH || valD == HIGH) {
      wrongFunc();
    } else if (valB == HIGH) {
      correctFunc();
      resultB = true;
    }
  } else if (question == 3) {
    if (valB == HIGH || valA == HIGH || valD == HIGH) {
      wrongFunc();
    } else if (valC == HIGH) {
      correctFunc();
      resultC = true;
    }
  } else if (question == 4) {
    if (valB == HIGH || valC == HIGH || valD == HIGH) {
      wrongFunc();
      results();
    } else if (valA == HIGH) {
      correctFunc();
      resultD = true;
      results();
    }
  }
}
