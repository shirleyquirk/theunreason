int relays = 48;           //number of relays to use
int strt = 6;
int side = 24;

const int sideA[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
const int sideB[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46};
const int seatA[] = {23, 24, 25};
const int seatB[] = {47, 48, 49};
const int rearA[] = {26, 27};
const int rearB[] = {50, 51};
const int headA[] = {29, 28};
const int headB[] = {52, 53};

int sideA_length = sizeof(sideA) / sizeof(int);
int sideB_length = sizeof(sideB) / sizeof(int);
int seatA_length = sizeof(seatA) / sizeof(int);
int seatB_length = sizeof(seatB) / sizeof(int);
int rearA_length = sizeof(rearA) / sizeof(int);
int rearB_length = sizeof(rearB) / sizeof(int);
int headA_length = sizeof(headA) / sizeof(int);
int headB_length = sizeof(headB) / sizeof(int);

int side_length = sideA_length;
int seat_length = seatA_length;
int rear_length = rearA_length;
int head_length = headA_length;

const int BUTTON_PIN = 69;

int buttonCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

#define N_RELAYS 48
#define N_SIDE 17
#define N_SEAT 3
#define N_REAR 2
#define N_HEAD 2

int count = 0;
int o = 0;

const int ON = LOW;
const int OFF = HIGH;

void setup() {
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");

  pinMode(A15, INPUT_PULLUP);

  for (int i = strt; i < strt + relays; i++) {
    pinMode(i, OUTPUT);                 // initiate relays to digital outputs on arduino
    digitalWrite(i, HIGH);              // turn all off to being with
  }
  Serial.println("<SETUP COMPLETE>");

} // end of setup
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {

  delay(5);

  buttonState = digitalRead(BUTTON_PIN);
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      buttonCounter = (buttonCounter + 1) % 11;
      // turn off all the lights on pattern change
      allOff();
      count = 0;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonCounter);
    } else {
      Serial.println("off");
    }
    delay(5);    // Delay a little bit to avoid bouncing
  }
  lastButtonState = buttonState;



  /*
     buttonCounter = (buttonCounter) % 2;
    ///// returning

      switch (buttonCounter) {
        case 0:
          allOff();
          break;
        case 1:
          whoop(100, 0);
          allOff();
      //      delay(50);
          headLights(ON);
          rearLights(ON);
          break;
      }
  */



  buttonCounter = (buttonCounter) % 3;
  ///// arriving

  switch (buttonCounter) {
    case 0:
      chase(80, 50);
      break;
    case 1:
      jump(25, 5);
      break;
    case 2:
      headLights(ON);
      rearLights(ON);
      break;
    case 3:
      allOff();
      break;

  }


  /*
  
  

    switch (buttonCounter) {
      case 0:
        allOff();
        break;
      case 1:
        chase(80, 50);
        break;
      case 2:
        whoop(100, 0);
        allOff();
        headLights(ON);
        rearLights(ON);
        break;
      case 3:
        fillUp(20);
        delay(100);
        allOff();
        delay(50);
        allOn();
        delay(50);
        allOff();
        delay(1000);
        break;
      case 4:
        jump(25, 5);
        break;
      case 5:
        landing(100, 1000);
        break;
      case 6:
        lighthouse(100, 50);
        break;
      case 7:
        fairground(150, 150);
        break;
      case 8:
        whoop(50, 10);
        break;
      case 9:
        superCruise(60, 10);
        break;
      case 10:
        flight(50, 30);
        break;
      default:
        allOff();
        break;
    }
  */

  //      delay(50);
//      headLights(OFF);
//      rearLights(OFF);
//      delay(50);
//      headLights(ON);
//      rearLights(ON);
//      allOn();
//      delay(50);
//      allOff();
  
  // to do
  // flight rear lights on
}

void landing(int time1, int time2) {
  digitalWrite(sideA[0], ON);
  digitalWrite(sideA[1], ON);
  digitalWrite(sideA[11], ON);
  digitalWrite(sideA[12], ON);

  digitalWrite(sideB[0], ON);
  digitalWrite(sideB[1], ON);
  digitalWrite(sideB[11], ON);
  digitalWrite(sideB[12], ON);
  ///////////////////////////////////////////////////////
  delay (time1);
  ///////////////////////////////////////////////////////
  digitalWrite(sideA[0], OFF);
  digitalWrite(sideA[1], OFF);
  digitalWrite(sideA[11], OFF);
  digitalWrite(sideA[12], OFF);

  digitalWrite(sideB[0], OFF);
  digitalWrite(sideB[1], OFF);
  digitalWrite(sideB[11], OFF);
  digitalWrite(sideB[12], OFF);
  ///////////////////////////////////////////////////////
  delay (time1);
  ///////////////////////////////////////////////////////
  digitalWrite(sideA[0], ON);
  digitalWrite(sideA[1], ON);
  digitalWrite(sideA[11], ON);
  digitalWrite(sideA[12], ON);

  digitalWrite(sideB[0], ON);
  digitalWrite(sideB[1], ON);
  digitalWrite(sideB[11], ON);
  digitalWrite(sideB[12], ON);
  ///////////////////////////////////////////////////////
  delay (time1);
  ///////////////////////////////////////////////////////
  digitalWrite(sideA[0], OFF);
  digitalWrite(sideA[1], OFF);
  digitalWrite(sideA[11], OFF);
  digitalWrite(sideA[12], OFF);

  digitalWrite(sideB[0], OFF);
  digitalWrite(sideB[1], OFF);
  digitalWrite(sideB[11], OFF);
  digitalWrite(sideB[12], OFF);
  ///////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////
  delay (time2);
}

void allOn() {
  for (int i = 0; i < sideA_length; i++) digitalWrite(sideA[i], ON);
  for (int i = 0; i < sideB_length; i++) digitalWrite(sideB[i], ON);
  for (int i = 0; i < seatA_length; i++) digitalWrite(seatA[i], ON);
  for (int i = 0; i < seatB_length; i++) digitalWrite(seatB[i], ON);
  for (int i = 0; i < rearA_length; i++) digitalWrite(rearA[i], ON);
  for (int i = 0; i < rearB_length; i++) digitalWrite(rearB[i], ON);
  for (int i = 0; i < headA_length; i++) digitalWrite(headA[i], ON);
  for (int i = 0; i < headB_length; i++) digitalWrite(headB[i], ON);
}

void allOff() {
  for (int i = 0; i < sideA_length; i++) digitalWrite(sideA[i], OFF);
  for (int i = 0; i < sideB_length; i++) digitalWrite(sideB[i], OFF);
  for (int i = 0; i < seatA_length; i++) digitalWrite(seatA[i], OFF);
  for (int i = 0; i < seatB_length; i++) digitalWrite(seatB[i], OFF);
  for (int i = 0; i < rearA_length; i++) digitalWrite(rearA[i], OFF);
  for (int i = 0; i < rearB_length; i++) digitalWrite(rearB[i], OFF);
  for (int i = 0; i < headA_length; i++) digitalWrite(headA[i], OFF);
  for (int i = 0; i < headB_length; i++) digitalWrite(headB[i], OFF);
}

void jump(int onTime, int offTime) {
  /// red lights pulsing
  onTime *= 0.85;
  offTime *= 0.85;
  if (count < 21) {
    for (int i = 0; i < side_length; i++) {
      digitalWrite(sideA[i], ON);
      if (i > 10 && i < 14) digitalWrite(seatA[i - 11], ON);
      digitalWrite(sideB[i], ON);
      if (i > 10 && i < 14) digitalWrite(seatB[i - 11], ON);
      ////////////////////////////////////////////////////////////////////
      delay(onTime);
      ////////////////////////////////////////////////////////////////////
      digitalWrite(sideA[i], OFF);
      if (i > 10 && i < 14) digitalWrite(seatA[i - 11], OFF);
      digitalWrite(sideB[i], OFF);
      if (i > 10 && i < 14) digitalWrite(seatB[i - 11], OFF);
      ////////////////////////////////////////////////////////////////////
      delay(offTime);
      ////////////////////////////////////////////////////////////////////
      if (i < count)    {
        digitalWrite(sideA[i], ON);
        if (i > 10 && i < 14) digitalWrite(seatA[i - 11], ON);
        digitalWrite(sideB[i], ON);
        if (i > 10 && i < 14) digitalWrite(seatB[i - 11], ON);
      }
    }
  }
  if (count == 21) {
    headLights(ON);
    rearLights(ON);
  }
  count = (count + 1);
  if (count > 21) count = 21;
}

void superCruise(int onTime, int offTime) {
  onTime *= 0.85;
  offTime *= 0.85;
  digitalWrite(headA[0], ON);
  digitalWrite(headB[0], ON);
  rearLights(ON);

  for (int i = 0; i < side_length; i++) {
    digitalWrite(sideA[i], ON);
    if (i > 10 && i < 14) digitalWrite(seatA[i - 11], ON);
    digitalWrite(sideB[i], ON);
    if (i > 10 && i < 14) digitalWrite(seatB[i - 11], ON);
    ////////////////////////////////////////////////////////////////////
    delay(onTime);
    ////////////////////////////////////////////////////////////////////
    digitalWrite(sideA[i], OFF);
    if (i > 10 && i < 14) digitalWrite(seatA[i - 11], OFF);
    digitalWrite(sideB[i], OFF);
    if (i > 10 && i < 14) digitalWrite(seatB[i - 11], OFF);
    ////////////////////////////////////////////////////////////////////
    delay(offTime);
    ////////////////////////////////////////////////////////////////////
  }
}


void fairground(int time1, int time2) {
  // swtich ON all the EVEN numbered LIGHTS
  for (int i = 0; i < side_length; i += 2) {
    digitalWrite(sideA[i], ON);
    digitalWrite(sideB[i], ON);
  }
  for (int i = 0; i < seat_length; i += 2) {
    digitalWrite(seatA[i], ON);
    digitalWrite(seatB[i], ON);
  }
  /////////////////////////////////////////////////////////////////
  delay(time1);
  /////////////////////////////////////////////////////////////////
  // swtich OFF all the EVEN numbered LIGHTS
  for (int i = 0; i < side_length; i += 2) {
    digitalWrite(sideA[i], OFF);
    digitalWrite(sideB[i], OFF);
  }
  for (int i = 0; i < seat_length; i += 2) {
    digitalWrite(seatA[i], OFF);
    digitalWrite(seatB[i], OFF);
  }

  /////////////////////////////////////////////////////////////////
  // swtich ON all the ODD numbered LIGHTS
  for (int i = 1; i < side_length; i += 2) {
    digitalWrite(sideA[i], ON);
    digitalWrite(sideB[i], ON);
  }
  for (int i = 1; i < seat_length; i += 2) {
    digitalWrite(seatA[i], ON);
    digitalWrite(seatB[i], ON);
  }

  /////////////////////////////////////////////////////////////////
  delay(time2);
  /////////////////////////////////////////////////////////////////
  // swtich OFF all the ODD numbered LIGHTS
  for (int i = 1; i < side_length; i += 2) {
    digitalWrite(sideA[i], OFF);
    digitalWrite(sideB[i], OFF);
  }
  for (int i = 1; i < seat_length; i += 2) {
    digitalWrite(seatA[i], OFF);
    digitalWrite(seatB[i], OFF);
  }
  headLights(ON);
  rearLights(ON);
}

void flight(int onTime, int offTime) {
  headLights(ON);
  for (int i = 0; i < side_length + rear_length; i++) {
    if (i < side_length)  digitalWrite(sideA[i], ON);
    if (i > 10 && i < 14) digitalWrite(seatA[i - 11], ON);
    if (i < side_length)  digitalWrite(sideB[i], ON);
    if (i > 10 && i < 14) digitalWrite(seatB[i - 11], ON);
    if (i >= side_length) digitalWrite(rearA[i], ON);
    if (i >= side_length) digitalWrite(rearB[i], ON);
    delay(onTime - (i * 1.5));
  }
  headLights(OFF);
  rearLights(OFF);
  /////////////////////////////////////////////////////////////////
  for (int i = 0; i < side_length; i++) {
    digitalWrite(sideA[i], OFF);
    if (i > 10 && i < 14) digitalWrite(seatA[i - 11], OFF);
    digitalWrite(sideB[i], OFF);
    if (i > 10 && i < 14) digitalWrite(seatB[i - 11], OFF);
    delay(offTime - (i * 1.5));
  }
  rearLights(ON);

}

void headLights(int state) {
  digitalWrite(headA[0], state);
  digitalWrite(headA[1], state);
  digitalWrite(headB[0], state);
  digitalWrite(headB[1], state);
}
void rearLights(int state) {
  digitalWrite(rearA[0], state);
  digitalWrite(rearA[1], state);
  digitalWrite(rearB[0], state);
  digitalWrite(rearB[1], state);
}

void allFlash(int on, int off) {
  for (int i = strt; i < strt + relays; i++) {
    digitalWrite(i, LOW);                 // side A
  }
  delay(on);                            // on time

  for (int i = strt; i < strt + relays; i++) {
    digitalWrite(i, HIGH);                 // side A
  }
  delay(off);                            // off time
}

void whoop(int onTime, int offTime) {
  // turn one bulb on after the other down both sides, bulbs stay on.
  for (int i = 0; i < side_length; i++) {
    digitalWrite(sideA[i], ON);                   // side A one after the other and stay on
    digitalWrite(sideB[i], ON);                   // side B one after the other and stay on
    if (i > 10  && i < 14) {
      digitalWrite(seatA[i - 11], ON);
      digitalWrite(seatB[i - 11], ON);
    }
    delay(onTime - (onTime * i / 30));            // time between bulbs coming on decreases as they fill up
  }
  // headlights and rearlights come on together at the end of sequence
  headLights(ON);
  rearLights(ON);
  delay(onTime * 2);
  delay(offTime);
  allOff();
}

void fillUp(int onTime) {
  // turn one bulb on after the other down both sides, bulbs stay on.
  for (int i = 0; i < side_length; i++) {
    digitalWrite(sideA[i], ON);                 // side A
    if (i > 10 && i < 14) digitalWrite(seatA[i - 11], ON);
    digitalWrite(sideB[i], ON);                 // side B
    if (i > 10 && i < 14) digitalWrite(seatB[i - 11], ON);
    delay(onTime);                              // on time
  }


}

void chase(int onTime, int offTime) {

   haedLights(ON);
    delay(onTime * 2);                                        // on time
    headLights(OFF);
    delay(offTime * 2);                                      // off time
  
  
  for (int i = 0; i < side_length; i++) {
    digitalWrite(sideA[i], ON);
    if (i > 10 && i < 14) digitalWrite(seatA[i - 11], ON);
    digitalWrite(sideB[i], ON);
    if (i > 10 && i < 14) digitalWrite(seatB[i - 11], ON);
    delay(onTime);                                          // on time
    /////////////////////////////////////////////////////////////////////////////
    digitalWrite(sideA[i], OFF);
    if (i > 10 && i < 14) digitalWrite(seatA[i - 11], OFF);
    digitalWrite(sideB[i], OFF);
    if (i > 10 && i < 14) digitalWrite(seatB[i - 11], OFF);
    delay(offTime);                                        // off time
    /////////////////////////////////////////////////////////////////////////////
  }

    rearLights(ON);
    delay(onTime * 2);                                        // on time
    rearLights(OFF);
    delay(offTime * 2);                                      // off time

  
  }
}

void lighthouse(int onTime, int offTime) {
  for (int i = side_length; i >= 0; i--)    {
    digitalWrite(sideB[i], ON);
    delay(onTime);
    digitalWrite(sideB[i], OFF);
  }
  digitalWrite(headB[1], ON);
  delay(onTime);
  digitalWrite(headB[1], OFF);
  digitalWrite(headB[0], ON);
  delay(onTime);
  digitalWrite(headB[0], OFF);

  digitalWrite(headA[0], ON);
  delay(onTime);
  digitalWrite(headA[0], OFF);
  digitalWrite(headA[1], ON);
  delay(onTime);
  digitalWrite(headA[1], OFF);

  for (int i = 0; i < sideA_length; i++)    {
    digitalWrite(sideA[i], ON);
    delay(onTime);
    digitalWrite(sideA[i], OFF);
  }

  for (int i = 0; i < rear_length; i++)   {
    digitalWrite(rearA[i], ON);
    digitalWrite(rearB[i], ON);
    delay(onTime);
    digitalWrite(rearA[i], OFF);
    digitalWrite(rearB[i], OFF);
  }


}
