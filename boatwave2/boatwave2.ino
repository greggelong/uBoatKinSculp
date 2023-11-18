// moves from random high and low values smoothly

#include <Servo.h>

Servo wave;
int newLow = 45;
int curLow = 45;
int newHigh = 135;
int curHigh = 135;

int d = 20;

void setup() {
  wave.attach(9);
  wave.write(90);

  delay(5000);

  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  // get new low for right

  newLow = floor(random(35, 90)); //
  // move from that low to new low smoothly
  // one of two options
  if (newLow > curLow) {
    for (int i = curLow; i < newLow; i++) {
      wave.write(i);
      delay(d);
    }
  } else {
    for (int i = curLow; i > newLow; i--) {
      wave.write(i);
      delay(d);
    }

  }

  // swap
  curLow = newLow;
  Serial.println(curLow);

  // move from cur low to curr high
  for (int i = curLow; i < curHigh; i++) {
    wave.write(i);
    delay(d);
  }
  // get new high for left
  newHigh = floor(random(90, 135));
  Serial.println(newHigh);

  // move from that high to new high smoothly
  if (newHigh < curHigh) {
    for (int i = curHigh; i > newHigh; i--) {
      wave.write(i);
      delay(d);
    }
  } else {
    for (int i = curHigh; i < newHigh; i++) {
      wave.write(i);
      delay(d);
    }

  }

  // swap high
  curHigh = newHigh;
  Serial.println(curHigh);

  // move form curHigh to curLow
  for (int i = curHigh; i > curLow; i--) {
    wave.write(i);
    delay(d);
  }


}
