// Aahanaa (Atibrewa)

#include <stdio.h>
#include <assert.h>
#include <math.h>

//declarations
unsigned int convertDouble(double v);
unsigned int convertFloat(float v);
int float_le(float x, float y);
int float_ge(float x, float y);
void uint_binary(unsigned int input, char* result);

int main() {
	// Defining variables at all edges and some in between values:
	float pos_infinity = INFINITY;
	float largest_pos_norm = 3.4e+38;
	float pos_norm = 23.5; // Random positive normalised number
	float pos_one = 1;
	float smallest_pos_norm = 1.18e-38;
	float largest_pos_denorm = 1.17e-38;
	float pos_denorm = 1.9e-40; // Random positive denormalised number
	float smallest_pos_denorm = 1.4e-45;
	float pos_zero = 0;
	float neg_zero = -0; // +/- zero actually get saved as the same thing!
	float smallest_neg_denorm = -1.4e-45;
	float neg_denorm = -1.9e-40; // Random negative denormalised number
	float largest_neg_denorm = -1.17e-38;
	float smallest_neg_norm = -1.18e-38;
	float neg_norm = -0.5; // Random negative normalised number
	float neg_one = -1;
	float largest_neg_norm = -3.4e+38;
	float neg_infinity = -INFINITY;

	float x;
	float y;

	// Some random preliminary tests!

	x = 57.9023;
	y = -578.5;
	assert(float_le(x,y) == 0);
	assert(float_ge(x,y) == 1);

	x = 5.0;
	y = 5.0;
	assert(float_le(x,y) == 1);
	assert(float_ge(x,y) == 1);

	////// A test that shows how the operator <= would get converted
	////// into a macro function by the machine when used in a
	///// relational expression (in a loop in this case).
	///// The code you would normally write would be:
	////    while (x <= y) { ... }
	x = 5.0;
	y = 10.0;
	while (float_le(x,y)) {
		assert(float_le(x,y) == 1);
		assert(float_ge(x,y) == (x >= y));
		x = x + 1.0;
	}
	/////

	/*
	 * Comprehensive testing!
	 * 
	 * In the following sections, I test each of the edge cases against
	 * evey other edge with both float_le() and float_ge().
	 * This serves the purpose of testing each range (positive normalised, positive denorm ...)
	 * against itself as well as against every other range! (with some overkill which a realised a little late)
	 * 
	*/

	// + infinity
	x = pos_infinity;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 0);
	assert(float_le(x, pos_norm) == 0);
	assert(float_le(x, pos_one) == 0);
	assert(float_le(x, smallest_pos_norm) == 0);
	assert(float_le(x, largest_pos_denorm) == 0);
	assert(float_le(x, pos_denorm) == 0);
	assert(float_le(x, smallest_pos_denorm) == 0);
	assert(float_le(x, pos_zero) == 0);
	assert(float_le(x, neg_zero) == 0);
	assert(float_le(x, smallest_neg_denorm) == 0);
	assert(float_le(x, neg_denorm) == 0);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 1);
	assert(float_ge(x, largest_pos_norm) == 1);
	assert(float_ge(x, pos_norm) == 1);
	assert(float_ge(x, pos_one) == 1);
	assert(float_ge(x, smallest_pos_norm) == 1);
	assert(float_ge(x, largest_pos_denorm) == 1);
	assert(float_ge(x, pos_denorm) == 1);
	assert(float_ge(x, smallest_pos_denorm) == 1);
	assert(float_ge(x, pos_zero) == 1);
	assert(float_ge(x, neg_zero) == 1);
	assert(float_ge(x, smallest_neg_denorm) == 1);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Largest Positive Normalised number
	x = largest_pos_norm;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 0);
	assert(float_le(x, pos_one) == 0);
	assert(float_le(x, smallest_pos_norm) == 0);
	assert(float_le(x, largest_pos_denorm) == 0);
	assert(float_le(x, pos_denorm) == 0);
	assert(float_le(x, smallest_pos_denorm) == 0);
	assert(float_le(x, pos_zero) == 0);
	assert(float_le(x, neg_zero) == 0);
	assert(float_le(x, smallest_neg_denorm) == 0);
	assert(float_le(x, neg_denorm) == 0);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 1);
	assert(float_ge(x, pos_norm) == 1);
	assert(float_ge(x, pos_one) == 1);
	assert(float_ge(x, smallest_pos_norm) == 1);
	assert(float_ge(x, largest_pos_denorm) == 1);
	assert(float_ge(x, pos_denorm) == 1);
	assert(float_ge(x, smallest_pos_denorm) == 1);
	assert(float_ge(x, pos_zero) == 1);
	assert(float_ge(x, neg_zero) == 1);
	assert(float_ge(x, smallest_neg_denorm) == 1);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// A Positive Normalised number
	x = pos_norm;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 0);
	assert(float_le(x, smallest_pos_norm) == 0);
	assert(float_le(x, largest_pos_denorm) == 0);
	assert(float_le(x, pos_denorm) == 0);
	assert(float_le(x, smallest_pos_denorm) == 0);
	assert(float_le(x, pos_zero) == 0);
	assert(float_le(x, neg_zero) == 0);
	assert(float_le(x, smallest_neg_denorm) == 0);
	assert(float_le(x, neg_denorm) == 0);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 1);
	assert(float_ge(x, pos_one) == 1);
	assert(float_ge(x, smallest_pos_norm) == 1);
	assert(float_ge(x, largest_pos_denorm) == 1);
	assert(float_ge(x, pos_denorm) == 1);
	assert(float_ge(x, smallest_pos_denorm) == 1);
	assert(float_ge(x, pos_zero) == 1);
	assert(float_ge(x, neg_zero) == 1);
	assert(float_ge(x, smallest_neg_denorm) == 1);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Positive One
	x = pos_one;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 0);
	assert(float_le(x, largest_pos_denorm) == 0);
	assert(float_le(x, pos_denorm) == 0);
	assert(float_le(x, smallest_pos_denorm) == 0);
	assert(float_le(x, pos_zero) == 0);
	assert(float_le(x, neg_zero) == 0);
	assert(float_le(x, smallest_neg_denorm) == 0);
	assert(float_le(x, neg_denorm) == 0);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 1);
	assert(float_ge(x, smallest_pos_norm) == 1);
	assert(float_ge(x, largest_pos_denorm) == 1);
	assert(float_ge(x, pos_denorm) == 1);
	assert(float_ge(x, smallest_pos_denorm) == 1);
	assert(float_ge(x, pos_zero) == 1);
	assert(float_ge(x, neg_zero) == 1);
	assert(float_ge(x, smallest_neg_denorm) == 1);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Smallest Positive Normalised number
	x = smallest_pos_norm;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 0);
	assert(float_le(x, pos_denorm) == 0);
	assert(float_le(x, smallest_pos_denorm) == 0);
	assert(float_le(x, pos_zero) == 0);
	assert(float_le(x, neg_zero) == 0);
	assert(float_le(x, smallest_neg_denorm) == 0);
	assert(float_le(x, neg_denorm) == 0);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 1);
	assert(float_ge(x, largest_pos_denorm) == 1);
	assert(float_ge(x, pos_denorm) == 1);
	assert(float_ge(x, smallest_pos_denorm) == 1);
	assert(float_ge(x, pos_zero) == 1);
	assert(float_ge(x, neg_zero) == 1);
	assert(float_ge(x, smallest_neg_denorm) == 1);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Largest Positive Denormalised number
	x = largest_pos_denorm;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 0);
	assert(float_le(x, smallest_pos_denorm) == 0);
	assert(float_le(x, pos_zero) == 0);
	assert(float_le(x, neg_zero) == 0);
	assert(float_le(x, smallest_neg_denorm) == 0);
	assert(float_le(x, neg_denorm) == 0);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 1);
	assert(float_ge(x, pos_denorm) == 1);
	assert(float_ge(x, smallest_pos_denorm) == 1);
	assert(float_ge(x, pos_zero) == 1);
	assert(float_ge(x, neg_zero) == 1);
	assert(float_ge(x, smallest_neg_denorm) == 1);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// A Positive Denormalised number
	x = pos_denorm;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 1);
	assert(float_le(x, smallest_pos_denorm) == 0);
	assert(float_le(x, pos_zero) == 0);
	assert(float_le(x, neg_zero) == 0);
	assert(float_le(x, smallest_neg_denorm) == 0);
	assert(float_le(x, neg_denorm) == 0);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 0);
	assert(float_ge(x, pos_denorm) == 1);
	assert(float_ge(x, smallest_pos_denorm) == 1);
	assert(float_ge(x, pos_zero) == 1);
	assert(float_ge(x, neg_zero) == 1);
	assert(float_ge(x, smallest_neg_denorm) == 1);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Smallest Positive Denormalised number
	x = smallest_pos_denorm;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 1);
	assert(float_le(x, smallest_pos_denorm) == 1);
	assert(float_le(x, pos_zero) == 0);
	assert(float_le(x, neg_zero) == 0);
	assert(float_le(x, smallest_neg_denorm) == 0);
	assert(float_le(x, neg_denorm) == 0);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 0);
	assert(float_ge(x, pos_denorm) == 0);
	assert(float_ge(x, smallest_pos_denorm) == 1);
	assert(float_ge(x, pos_zero) == 1);
	assert(float_ge(x, neg_zero) == 1);
	assert(float_ge(x, smallest_neg_denorm) == 1);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Positive Zero
	x = pos_zero;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 1);
	assert(float_le(x, smallest_pos_denorm) == 1);
	assert(float_le(x, pos_zero) == 1);
	assert(float_le(x, neg_zero) == 1);
	assert(float_le(x, smallest_neg_denorm) == 0);
	assert(float_le(x, neg_denorm) == 0);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 0);
	assert(float_ge(x, pos_denorm) == 0);
	assert(float_ge(x, smallest_pos_denorm) == 0);
	assert(float_ge(x, pos_zero) == 1);
	assert(float_ge(x, neg_zero) == 1);
	assert(float_ge(x, smallest_neg_denorm) == 1);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Negative Zero
	x = neg_zero;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 1);
	assert(float_le(x, smallest_pos_denorm) == 1);
	assert(float_le(x, pos_zero) == 1);
	assert(float_le(x, neg_zero) == 1);
	assert(float_le(x, smallest_neg_denorm) == 0);
	assert(float_le(x, neg_denorm) == 0);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 0);
	assert(float_ge(x, pos_denorm) == 0);
	assert(float_ge(x, smallest_pos_denorm) == 0);
	assert(float_ge(x, pos_zero) == 1);
	assert(float_ge(x, neg_zero) == 1);
	assert(float_ge(x, smallest_neg_denorm) == 1);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Smallest Negative Denormalised number
	x = smallest_neg_denorm;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 1);
	assert(float_le(x, smallest_pos_denorm) == 1);
	assert(float_le(x, pos_zero) == 1);
	assert(float_le(x, neg_zero) == 1);
	assert(float_le(x, smallest_neg_denorm) == 1);
	assert(float_le(x, neg_denorm) == 0);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 0);
	assert(float_ge(x, pos_denorm) == 0);
	assert(float_ge(x, smallest_pos_denorm) == 0);
	assert(float_ge(x, pos_zero) == 0);
	assert(float_ge(x, neg_zero) == 0);
	assert(float_ge(x, smallest_neg_denorm) == 1);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// A Negative Denormalised number
	x = neg_denorm;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 1);
	assert(float_le(x, smallest_pos_denorm) == 1);
	assert(float_le(x, pos_zero) == 1);
	assert(float_le(x, neg_zero) == 1);
	assert(float_le(x, smallest_neg_denorm) == 1);
	assert(float_le(x, neg_denorm) == 1);
	assert(float_le(x, largest_neg_denorm) == 0);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 0);
	assert(float_ge(x, pos_denorm) == 0);
	assert(float_ge(x, smallest_pos_denorm) == 0);
	assert(float_ge(x, pos_zero) == 0);
	assert(float_ge(x, neg_zero) == 0);
	assert(float_ge(x, smallest_neg_denorm) == 0);
	assert(float_ge(x, neg_denorm) == 1);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Largest Negative Denormalised number
	x = largest_neg_denorm;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 1);
	assert(float_le(x, smallest_pos_denorm) == 1);
	assert(float_le(x, pos_zero) == 1);
	assert(float_le(x, neg_zero) == 1);
	assert(float_le(x, smallest_neg_denorm) == 1);
	assert(float_le(x, neg_denorm) == 1);
	assert(float_le(x, largest_neg_denorm) == 1);
	assert(float_le(x, smallest_neg_norm) == 0);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 0);
	assert(float_ge(x, pos_denorm) == 0);
	assert(float_ge(x, smallest_pos_denorm) == 0);
	assert(float_ge(x, pos_zero) == 0);
	assert(float_ge(x, neg_zero) == 0);
	assert(float_ge(x, smallest_neg_denorm) == 0);
	assert(float_ge(x, neg_denorm) == 0);
	assert(float_ge(x, largest_neg_denorm) == 1);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Smallest Negative Normalised number
	x = smallest_neg_norm;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 1);
	assert(float_le(x, smallest_pos_denorm) == 1);
	assert(float_le(x, pos_zero) == 1);
	assert(float_le(x, neg_zero) == 1);
	assert(float_le(x, smallest_neg_denorm) == 1);
	assert(float_le(x, neg_denorm) == 1);
	assert(float_le(x, largest_neg_denorm) == 1);
	assert(float_le(x, smallest_neg_norm) == 1);
	assert(float_le(x, neg_norm) == 0);
	assert(float_le(x, neg_one) == 0);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 0);
	assert(float_ge(x, pos_denorm) == 0);
	assert(float_ge(x, smallest_pos_denorm) == 0);
	assert(float_ge(x, pos_zero) == 0);
	assert(float_ge(x, neg_zero) == 0);
	assert(float_ge(x, smallest_neg_denorm) == 0);
	assert(float_ge(x, neg_denorm) == 0);
	assert(float_ge(x, largest_neg_denorm) == 0);
	assert(float_ge(x, smallest_neg_norm) == 1);
	assert(float_ge(x, neg_norm) == 1);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Negative One
	x = neg_one;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 1);
	assert(float_le(x, smallest_pos_denorm) == 1);
	assert(float_le(x, pos_zero) == 1);
	assert(float_le(x, neg_zero) == 1);
	assert(float_le(x, smallest_neg_denorm) == 1);
	assert(float_le(x, neg_denorm) == 1);
	assert(float_le(x, largest_neg_denorm) == 1);
	assert(float_le(x, smallest_neg_norm) == 1);
	assert(float_le(x, neg_norm) == 1);
	assert(float_le(x, neg_one) == 1);
	assert(float_le(x, largest_neg_norm) == 0);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 0);
	assert(float_ge(x, pos_denorm) == 0);
	assert(float_ge(x, smallest_pos_denorm) == 0);
	assert(float_ge(x, pos_zero) == 0);
	assert(float_ge(x, neg_zero) == 0);
	assert(float_ge(x, smallest_neg_denorm) == 0);
	assert(float_ge(x, neg_denorm) == 0);
	assert(float_ge(x, largest_neg_denorm) == 0);
	assert(float_ge(x, smallest_neg_norm) == 0);
	assert(float_ge(x, neg_norm) == 0);
	assert(float_ge(x, neg_one) == 1);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);
	
	// Largest Negative Normalised number
	x = largest_neg_norm;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 1);
	assert(float_le(x, smallest_pos_denorm) == 1);
	assert(float_le(x, pos_zero) == 1);
	assert(float_le(x, neg_zero) == 1);
	assert(float_le(x, smallest_neg_denorm) == 1);
	assert(float_le(x, neg_denorm) == 1);
	assert(float_le(x, largest_neg_denorm) == 1);
	assert(float_le(x, smallest_neg_norm) == 1);
	assert(float_le(x, neg_norm) == 1);
	assert(float_le(x, neg_one) == 1);
	assert(float_le(x, largest_neg_norm) == 1);
	assert(float_le(x, neg_infinity) == 0);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 0);
	assert(float_ge(x, pos_denorm) == 0);
	assert(float_ge(x, smallest_pos_denorm) == 0);
	assert(float_ge(x, pos_zero) == 0);
	assert(float_ge(x, neg_zero) == 0);
	assert(float_ge(x, smallest_neg_denorm) == 0);
	assert(float_ge(x, neg_denorm) == 0);
	assert(float_ge(x, largest_neg_denorm) == 0);
	assert(float_ge(x, smallest_neg_norm) == 0);
	assert(float_ge(x, neg_norm) == 0);
	assert(float_ge(x, neg_one) == 0);
	assert(float_ge(x, largest_neg_norm) == 1);
	assert(float_ge(x, neg_infinity) == 1);

	// Negative Infinity
	x = neg_infinity;
	assert(float_le(x, pos_infinity) == 1);
	assert(float_le(x, largest_pos_norm) == 1);
	assert(float_le(x, pos_norm) == 1);
	assert(float_le(x, pos_one) == 1);
	assert(float_le(x, smallest_pos_norm) == 1);
	assert(float_le(x, largest_pos_denorm) == 1);
	assert(float_le(x, pos_denorm) == 1);
	assert(float_le(x, smallest_pos_denorm) == 1);
	assert(float_le(x, pos_zero) == 1);
	assert(float_le(x, neg_zero) == 1);
	assert(float_le(x, smallest_neg_denorm) == 1);
	assert(float_le(x, neg_denorm) == 1);
	assert(float_le(x, largest_neg_denorm) == 1);
	assert(float_le(x, smallest_neg_norm) == 1);
	assert(float_le(x, neg_norm) == 1);
	assert(float_le(x, neg_one) == 1);
	assert(float_le(x, largest_neg_norm) == 1);
	assert(float_le(x, neg_infinity) == 1);

	assert(float_ge(x, pos_infinity) == 0);
	assert(float_ge(x, largest_pos_norm) == 0);
	assert(float_ge(x, pos_norm) == 0);
	assert(float_ge(x, pos_one) == 0);
	assert(float_ge(x, smallest_pos_norm) == 0);
	assert(float_ge(x, largest_pos_denorm) == 0);
	assert(float_ge(x, pos_denorm) == 0);
	assert(float_ge(x, smallest_pos_denorm) == 0);
	assert(float_ge(x, pos_zero) == 0);
	assert(float_ge(x, neg_zero) == 0);
	assert(float_ge(x, smallest_neg_denorm) == 0);
	assert(float_ge(x, neg_denorm) == 0);
	assert(float_ge(x, largest_neg_denorm) == 0);
	assert(float_ge(x, smallest_neg_norm) == 0);
	assert(float_ge(x, neg_norm) == 0);
	assert(float_ge(x, neg_one) == 0);
	assert(float_ge(x, largest_neg_norm) == 0);
	assert(float_ge(x, neg_infinity) == 1);

}