/*
 * Dice
 * Turns on LEDs in pattern to represent a six sided dice roll.
 *
 * MIT License 2015 Chris Ryan
 */

// assign names to pin numbers 
int roll = 9;
int dotA = 5;
int dotB = 2;
int dotC = 3;
int dotD = 4;
int dotE = 6;
int dotF = 7;
int dotG = 8;

// test mode variables
bool test = false;
int currNum = 0;

void setup() {                
  // initialize the digital pin as an input for our switch.
  pinMode(roll, INPUT);
  
  // initialize the dots for output
  pinMode(dotA, OUTPUT);
  pinMode(dotB, OUTPUT);
  pinMode(dotC, OUTPUT);
  pinMode(dotD, OUTPUT);
  pinMode(dotE, OUTPUT);
  pinMode(dotF, OUTPUT);
  pinMode(dotG, OUTPUT);
  
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
}

void loop() {
  if (digitalRead(roll) == LOW) {
    if (test) {
      updateTest();
      return;
    }
    
    spin();
    int num = random(1, 7);
    for(int i = 0; i < 3; i++) {
      showNum(num);
      delay(500);
      showZero();
      delay(100);
    }
    
    showNum(num);
    delay(1000);
    showZero();
  }
}

void updateTest() {
  currNum++;
  if (currNum > 6) {
    currNum = 0;
  }
  
  showNum(currNum);
  delay(1000);
}

void spin() {
  int last = 0;
  for (int i = 0; i < 10; i++) {
    int now = last;
    while(now == last) {
      now = random(1, 7);
    }
    
    last = now;
    showNum(last);
    delay(50 * i);
  }
}

void showNum(int num) {
  switch (num) {
    case 1:
      showOne();
      break;
    case 2:
      showTwo();
      break;
    case 3:
      showThree();
      break;
    case 4:
      showFour();
      break;
    case 5:
      showFive();
      break;
    case 6:
      showSix();
      break;
    default:
      showZero();
  };
}

void showZero() {
  digitalWrite(dotA, LOW);
  digitalWrite(dotB, LOW);
  digitalWrite(dotC, LOW);
  digitalWrite(dotD, LOW);
  digitalWrite(dotE, LOW);
  digitalWrite(dotF, LOW);
  digitalWrite(dotG, LOW);
}

void showOne() {
  showZero();
  digitalWrite(dotA, HIGH);
}

void showTwo() {
  showZero();
  digitalWrite(dotB, HIGH);
  digitalWrite(dotG, HIGH);
}

void showThree() {
  showZero();
  digitalWrite(dotA, HIGH);
  digitalWrite(dotB, HIGH);
  digitalWrite(dotG, HIGH);
}

void showFour() {
  showZero();
  digitalWrite(dotB, HIGH);
  digitalWrite(dotD, HIGH);
  digitalWrite(dotE, HIGH);
  digitalWrite(dotG, HIGH);
}

void showFive() {
  showZero();
  digitalWrite(dotA, HIGH);
  digitalWrite(dotB, HIGH);
  digitalWrite(dotD, HIGH);
  digitalWrite(dotE, HIGH);
  digitalWrite(dotG, HIGH);
}

void showSix() {
  showZero();
  digitalWrite(dotB, HIGH);
  digitalWrite(dotC, HIGH);
  digitalWrite(dotD, HIGH);
  digitalWrite(dotE, HIGH);
  digitalWrite(dotF, HIGH);
  digitalWrite(dotG, HIGH);
}


