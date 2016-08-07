#include <BitBool.h>
#include <OnewireKeypad.h>
#include "constants.h"

OnewireKeypad <Print, 12> keyPad(Serial, KEYS, Rows, Cols, Pin, Row_Res, Col_Res );
int modeReadCounts = 0;
int modeReadSum = 0;

class Channel {
  private:
    const int* intervals;
		int currentInterval;
    int length;
    byte pinNum;
		
    long timeLastToggled;
    int pos = 0;

  public:
    Channel(){
      this->intervals = NULL;
      this->currentInterval = 0;
      this->length = 0;
      this->pinNum = 0;
      this->timeLastToggled = 0;
			
    }
    Channel(const int* intervals, byte pinNum){
      this->intervals = intervals;
      this->length = 0;
      this->pinNum = pinNum;
      this->timeLastToggled = 0;
			int pos = 0;
      pinMode(this->pinNum,OUTPUT);
			Serial.print(" inter: ");
			int j, val;
      //calculate size of intervals array
      while ( (int) pgm_read_word_near( intervals + this->length ) != 0) {
				this->length++; 
			}
			this->currentInterval = (int) pgm_read_word_near( intervals + 0 );
			
			
			
    }
    long update(long currTime) {			
      if ( currTime >= ( abs( this->currentInterval ) + timeLastToggled ) || timeLastToggled == 0) {
        timeLastToggled = currTime;
				this->currentInterval = (int) pgm_read_word_near( intervals + pos );
				//if the current interval is positive, turn on the light, and if it is negative, turn it off.
        if ( this->currentInterval > 0 ) {
          digitalWrite(pinNum, HIGH);
					// Serial.print("this->currentInterval: ");
					// Serial.print(this->currentInterval);
					// Serial.print("pin: ");
					// Serial.print(pinNum);
					// Serial.println(" Up.");
        } else {
          digitalWrite(pinNum, LOW);
					// Serial.print("this->currentInterval: ");
					// Serial.print(this->currentInterval);
					// Serial.print("pin: ");
					// Serial.print(pinNum);
					// Serial.println(" Down.");
        }
				//if the current interval is the last one in the array of intervals, reset to index 0
        if ( pos < this->length - 1 ) {
          pos++;
        } else {
          pos = 0;
        }
      }
			return abs( this->currentInterval + timeLastToggled ) - currTime;
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

// int modeNum = 0;
Mode updateMode(Mode mode) {
// int incomingByte = -1;
	char modeChar = '~';
	
	if( keyPad.Key_State() == 3){
   modeChar = keyPad.Getkey();
	 Serial.print("I have received ");
	 Serial.print(modeChar);
	 Serial.println(" as the current mode.");
  } 
	
	
	switch (modeChar) {
		case '1':
			mode = Mode(mode0_data, mode0_pins);
			break;
		case '2':
			mode = Mode(mode1_data, mode1_pins);
			break;
		case '3':
			mode = Mode(mode2_data, mode2_pins);
			break;
		case '4':
			mode = Mode(mode3_data, mode3_pins);
			break;
		case '5':
			mode = Mode(mode4_data, mode4_pins);
			break;
		case '6':
			mode = Mode(mode5_data, mode5_pins);
			break;
		case '7':
			mode = Mode(mode6_data, mode6_pins);
			break;
		case '8':
			mode = Mode(mode7_data, mode7_pins);
			break;
		case '9':
			mode = Mode(mode8_data, mode8_pins);
			break;
		case '*':
			mode = Mode(mode9_data, mode9_pins);
			break;
		case '0':
			mode = Mode(mode10_data, mode10_pins);
			break;
		case '#':
			mode = Mode(mode11_data, mode11_pins);
			break;
		default:
			break;
	}
	// if(modeChar != '~'){
		// Serial.print("Mode ");
		// Serial.print(modeChar);
		// Serial.println(" has been selected.");
	// }
	return mode;
}

Mode mode = Mode();
int modeVolt[12];


void setup() {
	 Serial.begin(9600);
  // while (!Serial);
	pinMode(A7, INPUT);
	keyPad.SetHoldTime(200);
	
	
	// for(int i = 0; i<=8; i++){
		// pinMode(i,INPUT_PULLUP);
		// }
 
  Serial.println("seting mode to mode0");
  mode = Mode(mode0_data, mode0_pins);
  Serial.println("end of setup");
	
	//Generate table of voltages for mode switch
	// int modeVoltIndex = 0;
	// for(int row=0; row<=3; row++){	
		// for(int col=0; col<=2; col++){
			// modeVolt[modeVoltIndex] = 50000 * COLRES / ( COLRES * col + ROWRES * row );
			
			// Serial.print("Mode ");
			// Serial.print(modeVoltIndex);			
			// Serial.print(" at (");
			// Serial.print(col);			
			// Serial.print(",");
			// Serial.print(row);
			// Serial.print(") should be around ");
			// Serial.print(modeVolt[modeVoltIndex]);
			// Serial.println(" millivolts.");
			
			// modeVoltIndex++;
		// }
	// }
}

void loop() {
	mode = updateMode(mode);
	// waits until a pin needs to be updated.
	static int soonest;
	// if (millis() > soonest) {
		soonest = mode.update(millis());
	// }
}
