#include "constants.h"
// #include <BitBool.h>


class Channel {
  private:
    const int* intervals;
    int length;
    byte pinNum;
		
    long previousTime;
    int pos = 0;

  public:
    Channel(){
      this->intervals = NULL;
      this->length = 0;
      this->pinNum = 0;
      this->previousTime = 0;
    }
    Channel(const int* intervals, byte pinNum){
      this->intervals = intervals;
      this->length = 0;
      this->pinNum = pinNum;
      this->previousTime = 0;
      pinMode(this->pinNum,OUTPUT);
			int j, val;
      //calculate size of intervals array
      while ( (int) pgm_read_word_near( intervals + this->length ) != 0) {
				this->length++; 
			}
			
			// Serial.print(" pin:");
			// Serial.print(this->pinNum);
			// Serial.print(" pos:");
			// Serial.print(pos);
			// Serial.print(" length:");
			// Serial.print(this->length);
			// Serial.println();
    }
    long update(long currTime) {
			
			long remainingTime;
			int currentInterval;
			// Serial.print(" curr:");
			// Serial.print(currTime);
			// Serial.print(" prev:");
			// Serial.print(previousTime);
			// Serial.print(" target:");
			// Serial.print((int) pgm_read_word_near( intervals + pos ));
			// Serial.print(" length:");
			// Serial.print(this->length);
			// Serial.println();
			//check if channel state should be updated.
			currentInterval = pgm_read_word_near( intervals + pos );
      if ( remainingTime = (currTime - previousTime) >= (int) abs( currentInterval ) ) {
        previousTime = currTime;
				//if the current interval is positive, turn on the light, and if it is negative, turn it off.
        if ( currentInterval > 0 ) { 
          digitalWrite(pinNum, HIGH);
					Serial.print("currentInterval: ");
					Serial.print(currentInterval);
					Serial.print("pin: ");
					Serial.print(pinNum);
					Serial.println(" Up.");
        } else {
          digitalWrite(pinNum, LOW);
					Serial.print("currentInterval: ");
					Serial.print(currentInterval);
					Serial.print("pin: ");
					Serial.print(pinNum);
					Serial.println(" Down.");
        }
				//if the current interval is the last one in the array of intervals, reset to index 0
        if ( pos < this->length - 1 ) {
          pos++;
        } else {
          pos = 0;
        }
      }
			return currTime + remainingTime;
    }
};

class Mode {
	private:
		Channel channels[MAXPINS];
		byte channel_count;
 public:
  Mode() {
    this->channel_count = 0;
  }
	Mode(const int* const* channels, const byte* pins) {
		this->channel_count = 0;
		//count channels
		int i;
    byte pin;
		for (i=0; (pin = (byte)pgm_read_byte_near(pins + i)) != 255; i++){
			// Serial.print("pinNum: ");
			// Serial.print(pin);
			// Serial.print(" ");
			//make channel from pointer channel
			this->channels[i] = Channel( (const int*)pgm_read_ptr_near(channels+i), pin );
		}
		this->channel_count = i;
	}
//TODO return soonest update time
  long update(long t) {
		long soonest=10000;
		long time;
    int i;
    for (i=0; i < channel_count; i++) {
			if ( (time = channels[i].update(t)) < soonest){
				soonest = time;
			}
    }
		return soonest;
  }
};

Mode updateMode(Mode mode) {
	int modeNum = -1;
	// send data only when you receive data:
 	if (Serial.available() > 0) {
		// read the incoming byte:
		modeNum = Serial.read() - '0' ;
	}
	
	for(int i = 13; i>=8; i--){
		if(digitalRead(i)==LOW){
			modeNum = i-8;
			break;
		}
	}
	switch (modeNum) {
		case 0:
			mode = Mode(mode0_data, mode0_pins);
			break;
		case 1:
			mode = Mode(mode1_data, mode1_pins);
			break;
		case 2:
			mode = Mode(mode2_data, mode2_pins);
			break;
		default:
			// stops method immediately.
			return mode;
	}
	Serial.print("Mode ");
	Serial.print(modeNum);
	Serial.println(" has been selected.");
	return mode;
}

Mode mode = Mode();

void setup() {
	Serial.begin(9600);
	while (!Serial);

	for(int i = 13; i>=8; i--){
		pinMode(i,INPUT_PULLUP);
		}

	Serial.println("seting mode to mode0");
	mode = Mode(mode0_data, mode0_pins);
	Serial.println("end of setup");
}

void loop() {
	mode = updateMode(mode);
	// waits until a pin needs to be updated.
	static int soonest;
	if (millis() > soonest) {
		// TODO loop through each mode and set soonest to the smallest value.
		mode.update(millis());
	}
}
