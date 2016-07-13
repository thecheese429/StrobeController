#include "constants.h"

//Set the number of the mode which will run when first powered on.
#define DEFAULTMODE 1

//define the millisecond intervals between toggling the state of a given channel
//the last value int the intervals list must be -1.
const PROGMEM long mode1_pins[] = {13, 12, 3, 4, -1};
const PROGMEM long mode1_intervals[8][100]={{50, 2000, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, -1},
											{100, 3000, 100, 100, 100, 100, -1},
											{60, 1500, 60, 60, 60, 60, -1},
											{50, 50, 50, 50, 50, 50, 50, 2000, 50, 50, 50, 50, -1}};

const PROGMEM long mode2_pins[] = {13, 12, 3, 4, -1};
const PROGMEM long mode2_intervals[8][100]={{100, 5000, -1},
											{100, 5000, -1},
											{100, 5000, -1},
											{50, 50, 50, 50, 50, 50, 50, 2000, 50, 50, 50, 50, -1}};
                                
const PROGMEM long mode3_pins[] = {13, 12, 3, 4, -1};
const PROGMEM long mode3_intervals[8][100]={{100, 5000, -1},
											{100, 5000, -1},
											{100, 5000, -1},
											{50, 50, 50, 50, 50, 50, 50, 2000, 50, 50, 50, 50, -1}};


