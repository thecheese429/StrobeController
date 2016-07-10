#include <BitBool.h>
#include <OnewireKeypad.h>

#include "patterns.h"

int mode = DEFAULTMODE;

class Channel {
  private:
    const long* intervals;
    int length;
    int pinNum;
    int index = 0;
    long previousTime;

  public:
    Channel(int channelIndex, int pinNum){
      this->previousTime = 0;
    }
    void add(const long *intervals, int pinNum) {
//      Serial.print("set interval ");
      this->intervals = intervals;
//      Serial.print("set pinNum ");
      this->pinNum = pinNum;
//      Serial.print("set previousTime ");
      this->previousTime = 0;
      
      pinMode(this->pinNum,OUTPUT);
//      Serial.print("set pinMode ");
      
      //calculate size of intervals array
      this->length = 0;
//      Serial.print("set length 0");
      while (pgm_read_word_near(intervals + this->length) != -1) { this->length++; }
//      Serial.print("calc length ");
      int i;
      for (i=0; i<length; i++){
//        Serial.print(pgm_read_word_near(intervals + i));
//        Serial.print(" ");
      }
//      Serial.println();
    }
    void updateChannel(long currTime) {
      Serial.print("time: ");
      Serial.print(currTime);
      Serial.print(" priev: ");
      Serial.print(this->previousTime);
      Serial.print(" interval: ");
      Serial.print(pgm_read_word_near(intervals + index));
      Serial.print(" index: ");
      Serial.print(index);
      Serial.print(" length: ");
      Serial.print(this->length);
      if ( currTime - previousTime >= pgm_read_word_near(intervals + index) ) {
        previousTime = currTime;
        if ( index % 2 == 1){ //if the current step in the interval sequence is odd, turn the pin on. Otherwise, turn it off.
          digitalWrite(pinNum, HIGH);
          Serial.print(" Odd");
        }
        else {
          digitalWrite(pinNum, LOW);
          Serial.print(" Even");
        }
        if ( index < this->length - 1 )  {//if the current interval is the last one in the array of intervals, reset to index 1
          index++;
          Serial.print(" Index++");
        }
        else {
          index = 0;
          Serial.print(" Index=0");
        }
      }
      Serial.println();
    }
};

class Mode {
    Channel channels[MAXPINS];
    int channelIndex = 0;
    int mode_pins_length;
    int mode_pins[8];
    int intervals_length[];
    int a, i, j, len;
  public:
    Mode(int modeNumber) {
      switch(modeNumber){
        case 1:
//          read in pin numbers
//          get length of pin numbers array
            for(i=0; a = pgm_read_word_near(mode1_pins + i)!=-1; i++){
              mode_pins[i] = a;
            }
            mode_pins_length = i;

//          get length of intervals
            for(j=0;j<mode_pins_length;j++){
              for(i=0; pgm_read_word_near(mode1_intervals[j][i])!=-1; i++){
              }
              intervals_length[j] = i;
              
              Serial.print("channel ");
              Serial.print(j);
              Serial.print(" is on pin ");
              Serial.print(mode_pins[j]);              
              Serial.print(" and the number of intervals is ");
              Serial.println(intervals_length[j]);
            }

            for(channelIndex=0; channelIndex<mode_pins_length; channelIndex++){
              channels[channelIndex] = Channel(channelIndex, mode_pins[channelIndex]);
            }
//add rest of cases, up to 12
          break;
        }
      }
    void updateChannels(long t) {
      int i;
      for (i=0; i < mode_pins_length; i++) {
        channels[i].updateChannel(t);
      }
    }
};

void updateMode() {
//read in mode from one wire keypad
}

void setup() {

  Serial.begin(9600);
  while (!Serial);
  
  Mode mode = Mode(DEFAULTMODE);
  Serial.println("end of setup");
}

void loop() {
//  Serial.println("loop");
    updateMode();
    mode.updateChannels(millis());
    }
}
