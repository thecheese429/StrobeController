#include <avr/pgmspace.h>
#define MAXPINS 8

#define LEFT 7
#define CENTER 6
#define BLUE 5
#define RRED 4
#define RIGHT 3

#define MODE0 0
#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4
#define MODE5 5
#define MODE6 6


//define the pin number of the digital pins used for changing the mode
#define MODE1PIN 0
#define MODE2PIN 1
#define MODE3PIN 2
#define MODE4PIN 3

#define UPDATECYCLES 10

#define DEFAULTMODE MODE1


//The maximum number of pins that can be used for outputs is
//the total number of digital pins minus the number of pins
//used for reading the mode. For this instance, we have
//fourteen digital pins and we are using four to read the
//mode = 10 pins output maximum
#define MAXPINS 10

//define the millisecond intervals between toggling the state of a given channel
//the first value is discarded - enter any value then start actual interval with position 2
const int mode0_1[] PROGMEM = {25,35,25,35,25,35,25,35,25,35,35, -1};
const int mode0_2[] PROGMEM = {40,20,40,20,40,20,40,20,40,20,40, -1};
const int mode0_3[] PROGMEM = {3,30,30,30,30,30,30,30,30,35, -1};
const int mode0_4[] PROGMEM = {35,25,35,25,35,25,35,25,35,25,35, -1};
const int mode0_5[] PROGMEM = {35,25,35,25,35,25,35,25,35,25,35, -1};
const int* const mode0_data[] PROGMEM = {mode0_1, mode0_2, mode0_3, mode0_4, mode0_5};
const byte mode0_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode1_1[] PROGMEM = {10, 1000, -1};
const int mode1_2[] PROGMEM = {20, 1000, -1};
const int mode1_3[] PROGMEM = {30, 1000, -1};
const int mode1_4[] PROGMEM = {40, 1000, -1};
const int mode1_5[] PROGMEM = {50, 1000, -1};
const int* const mode1_data[] PROGMEM = {mode1_1, mode1_2, mode1_3, mode1_4, mode1_5};
const byte mode1_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode2_1[] PROGMEM = {500,250, -1};
const int mode2_2[] PROGMEM = {40,20,40,20,40,20,40,20,40,20,40,1300, -1};
const int mode2_3[] PROGMEM = {300, -1};
const int mode2_4[] PROGMEM = {35,25,35,250,500,25,35,25,35,25,35,25,35, -1};
const int mode2_5[] PROGMEM = {35,25,35,250,500,25,35,25,35,25,35,25,35, -1};
const int* const mode2_data[] PROGMEM = {mode2_1, mode2_2, mode2_3, mode2_4};
const byte mode2_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode3_1[] PROGMEM = {500,25,35,25,35,25,35,25,35,25,35,250,35, -1};
const int mode3_2[] PROGMEM = {40,20,40,20,40,20,40,20,40,20,40,1300, -1};
const int mode3_3[] PROGMEM = {300,30,30,30,30,30,30,30,30,600,35, -1};
const int mode3_4[] PROGMEM = {35,25,35,250,500,25,35,25,35,25,35,25,35, -1};
const int mode3_5[] PROGMEM = {35,25,35,250,500,25,35,25,35,25,35,25,35, -1};
const int* const mode3_data[] PROGMEM = {mode3_1, mode3_2, mode3_3, mode3_4};
const byte mode3_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode4_1[] PROGMEM = {500,25,35,25,35,25,35,25,35,25,35,250,35, -1};
const int mode4_2[] PROGMEM = {40,20,40,20,40,20,40,20,40,20,40,1300, -1};
const int mode4_3[] PROGMEM = {300,30,30,30,30,30,30,30,30,600,35, -1};
const int mode4_4[] PROGMEM = {35,25,35,250,500,25,35,25,35,25,35,25,35, -1};
const int mode4_5[] PROGMEM = {35,25,35,250,500,25,35,25,35,25,35,25,35, -1};
const int* const mode4_data[] PROGMEM = {mode4_1, mode4_2, mode4_3, mode4_4};
const byte mode4_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins
