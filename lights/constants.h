#include <avr/pgmspace.h>

#define LEFT 7
#define CENTER 4
#define BLUE 3
#define RRED 6
#define RIGHT 0

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


#define DEFAULTMODE MODE0


// The number of channels used as output on the board: 8
#define MAXPINS 8

//define the millisecond intervals between toggling the state of a given channel
//Positive numbers are ON intervals, and negative numbers are OFF intervals.
//The last number must be 0 or the program will not work.
const int mode0_1[] PROGMEM = {1000, -500, 0};
const int mode0_2[] PROGMEM = {1000, -500, 0};
const int mode0_3[] PROGMEM = {1000, -500, 0};
const int mode0_4[] PROGMEM = {1000, -500, 0};
const int mode0_5[] PROGMEM = {1000, -500, 0};
const int* const mode0_data[] PROGMEM = {mode0_1, mode0_2, mode0_3, mode0_4, mode0_5};
const byte mode0_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names or pin numbers of the given output pins

const int mode1_1[] PROGMEM = {10, 1000, 0};
const int mode1_2[] PROGMEM = {20, 1000, 0};
const int mode1_3[] PROGMEM = {30, 1000, 0};
const int mode1_4[] PROGMEM = {40, 1000, 0};
const int mode1_5[] PROGMEM = {50, 1000, 0};
const int* const mode1_data[] PROGMEM = {mode1_1, mode1_2, mode1_3, mode1_4, mode1_5};
const byte mode1_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode2_1[] PROGMEM = {500,250, 0};
const int mode2_2[] PROGMEM = {40,20,40,20,40,20,40,20,40,20,40,1300, 0};
const int mode2_3[] PROGMEM = {300, 0};
const int mode2_4[] PROGMEM = {35,25,35,250,500,25,35,25,35,25,35,25,35, 0};
const int mode2_5[] PROGMEM = {35,25,35,250,500,25,35,25,35,25,35,25,35, 0};
const int* const mode2_data[] PROGMEM = {mode2_1, mode2_2, mode2_3, mode2_4};
const byte mode2_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode3_1[] PROGMEM = {500,25,35,25,35,25,35,25,35,25,35,250,35, 0};
const int mode3_2[] PROGMEM = {40,20,40,20,40,20,40,20,40,20,40,1300, 0};
const int mode3_3[] PROGMEM = {300,30,30,30,30,30,30,30,30,600,35, 0};
const int mode3_4[] PROGMEM = {35,25,35,250,500,25,35,25,35,25,35,25,35, 0};
const int mode3_5[] PROGMEM = {35,25,35,250,500,25,35,25,35,25,35,25,35, 0};
const int* const mode3_data[] PROGMEM = {mode3_1, mode3_2, mode3_3, mode3_4};
const byte mode3_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode4_1[] PROGMEM = {1000, 0, 0};
const int mode4_2[] PROGMEM = {1000, 0, 0};
const int mode4_3[] PROGMEM = {1000, 0, 0};
const int mode4_4[] PROGMEM = {1000, 0, 0};
const int mode4_5[] PROGMEM = {1000, 0, 0};
const int* const mode4_data[] PROGMEM = {mode4_1, mode4_2, mode4_3, mode4_4};
const byte mode4_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode5_1[] PROGMEM = {10, 10, 0};
const int mode5_2[] PROGMEM = {10, 10, 0};
const int mode5_3[] PROGMEM = {10, 10, 0};
const int mode5_4[] PROGMEM = {10, 10, 0};
const int mode5_5[] PROGMEM = {10, 10, 0};
const int* const mode5_data[] PROGMEM = {mode5_1, mode5_2, mode5_3, mode5_4, mode5_5};
const byte mode5_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode6_1[] PROGMEM = {10, 10, 0};
const int mode6_2[] PROGMEM = {10, 10, 0};
const int mode6_3[] PROGMEM = {10, 10, 0};
const int mode6_4[] PROGMEM = {10, 10, 0};
const int mode6_5[] PROGMEM = {10, 10, 0};
const int* const mode6_data[] PROGMEM = {mode6_1, mode6_2, mode6_3, mode6_4, mode6_5};
const byte mode6_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode7_1[] PROGMEM = {10, 10, 0};
const int mode7_2[] PROGMEM = {10, 10, 0};
const int mode7_3[] PROGMEM = {10, 10, 0};
const int mode7_4[] PROGMEM = {10, 10, 0};
const int mode7_5[] PROGMEM = {10, 10, 0};
const int* const mode7_data[] PROGMEM = {mode7_1, mode7_2, mode7_3, mode7_4, mode7_5};
const byte mode7_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode8_1[] PROGMEM = {30, -30, 30, -30, 30, -30, 30, 30, -30, 30, -30, 30, -30, 30, -300, 300, -100, 100, -100, 100, -100, 100, -100, 0};
const int mode8_2[] PROGMEM = { 20, -60, 20, -60, 20, -60, 20, -60, 20, -60, 20, -620, 0};
const int mode8_3[] PROGMEM = {20, -50, 20, -50, 20, -50, 20, -900, 0};
const int mode8_4[] PROGMEM = {-520, 20, -60, 20, -60, 20, -60, 20, -60, 20, -60, 20, -100, 0};
const int mode8_5[] PROGMEM = {300, -100, 100, -100, 100, -100, 100, -100, 30, -30, 30, -30, 30, -30, 30, 30, -30, 30, -30, 30, -30, 30, -300, 0};
const int* const mode8_data[] PROGMEM = {mode8_1, mode8_2, mode8_3, mode8_4, mode8_5};
const byte mode8_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode9_1[] PROGMEM = {50, -50, 50, -50, 50, -50, 50, -50, 50, -50, 500, -1000, 0};
const int mode9_2[] PROGMEM = {-200, 200, -200, 200, -200, 3000, 0};
const int mode9_3[] PROGMEM = {-700, 30, 0};
const int mode9_4[] PROGMEM = {60, -60, 60, -60, 60, -60, 60, -1300, 0};
const int mode9_5[] PROGMEM = {-1000, 50, -50, 50, -50, 50, -50, 50, -50, 50, -50, 500, 0};
const int* const mode9_data[] PROGMEM = {mode9_1, mode9_2, mode9_3, mode9_4, mode9_5};
const byte mode9_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode10_1[] PROGMEM = {-10, 10, 0};
const int mode10_2[] PROGMEM = {-10, 10, 0};
const int mode10_3[] PROGMEM = {-10, 10, 0};
const int mode10_4[] PROGMEM = {-10, 10, 0};
const int mode10_5[] PROGMEM = {-10, 10, 0};
const int* const mode10_data[] PROGMEM = {mode10_1, mode10_2, mode10_3, mode10_4, mode10_5};
const byte mode10_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins

const int mode11_1[] PROGMEM = { 20,-200, 0};
const int mode11_2[] PROGMEM = { 20,-200, 0};
const int mode11_3[] PROGMEM = { 20,-200, 0};
const int mode11_4[] PROGMEM = { 20,-200, 0};
const int mode11_5[] PROGMEM = { 20,-200, 0};
const int* const mode11_data[] PROGMEM = {mode11_1, mode11_2, mode11_3, mode11_4, mode11_5};
const byte mode11_pins[] PROGMEM = {LEFT, CENTER, BLUE, RRED, RIGHT, 255};//define the names of the given output pins


