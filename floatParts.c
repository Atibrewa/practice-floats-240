// Aahanaa (Atibrewa)

#include <limits.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
 * 
 * Takes in a double value and returns
 * the binary bit pattern of the double (acc to IEEE),
 * as an unsigned long value for bitwise comparison
 */
unsigned long convertDouble(double v) {

  double * d = &v;
  unsigned long * ulongp = (unsigned long *) d;
  unsigned long val = *ulongp;
  return val;
}

/*
 * 
 * Takes in a float value and returns
 * the binary bit pattern of the float (acc to IEEE),
 * as an unsigned int value for bitwise comparison
 */
unsigned int convertFloat(float v) {
  float * f = &v;
  unsigned int * uintp = (unsigned int *) f;
  unsigned int val = *uintp;
  return val;
}

/*
 *
 * Returns whether or not x is less than or equal to y
 * by examining its underlying bit level representation.
 * A return value of 1 indicates x is <= y.
 */
 int float_le(float x, float y) {
	unsigned ux = convertFloat(x);
	unsigned uy = convertFloat(y);
	unsigned sx = ux >> 31; 			// signed bit of x
	unsigned sy = uy >> 31;				// signed bit of y
	unsigned inx = ux & 0x7FFFFFFF;		// everything after signed bit
	unsigned iny = uy & 0x7FFFFFFF;		// everything after signed bit

	if (sx > sy) {							// if x is negative, y is positive, x < y
		return 1;
	} else if ((sx == 1) & (sy == 1)) {		// if both are negative, check the rest
		if (inx >= iny) {
			return 1;
		} // escape to return zero at the end
	} else if (sx | sy == 0) {				// if both are positive, check the rest
		if (inx <= iny) {
			return 1;
		} // esc to zero
	}

	return 0;

}

/*
 *
 * Returns whether or not x is greater than or equal to y
 * by examining its underlying bit level representation.
 * A return value of 1 indicates x is >= y.
 */
int float_ge(float x, float y) {
	unsigned ux = convertFloat(x);
	unsigned uy = convertFloat(y);
	unsigned sx = ux >> 31; 			// signed bit of x
	unsigned sy = uy >> 31;				// signed bit of y
	unsigned inx = ux & 0x7FFFFFFF;		// everything after signed bit
	unsigned iny = uy & 0x7FFFFFFF;		// everything after signed bit

	if (sx > sy) {							// if x is negative, y is positive, x < y
		return 0;
	} else if ((sx == 1) & (sy == 1)) {		// if both are negative, check the rest
		if (inx > iny) {
			return 0;
		} // escape to return zero at the end
	} else if (sx | sy == 0) {				// if both are positive, check the rest
		if (inx < iny) {
			return 0;
		} // esc to zero
	}

	return 1;
    
}

/*
 *
 *  This function creates a string representing the binary
 *  number that is stored for a given input unsigned integer.
 */
void uint_binary(unsigned int input, char* result) {
	int most_significant_bit = (sizeof( unsigned int)*8) - 1;

	strcpy(result, "");

    int i;
    for(i = most_significant_bit; i >= 0; --i) {
        if(input & (1 << i)) {
            strcat(result, "1");
        } else {
			strcat(result, "0");
		}
		if ((i % 4) == 0 && i != 0) {   //pretty print a space between 4 bits
      	 strcat(result, " ");
      	}
	}
}
