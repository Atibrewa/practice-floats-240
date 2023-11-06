# Relational Operations on Floating Point numbers

Here you will look at how floating point numbers are actually compared by the machine by implementing it yourself.

**Starter Code:** `floatParts.c` and `test.c` 

**Name of Executable:** `fp_relational_ops`

You create the Makefile.

We should be able to run these commands for your code:

    make clean
    make
    ./fp_relational_ops

## Background

One of the useful features of the IEEE 754 floating point representation is that the binary representation of the parts, *exp* and *frac*, which encode the values M and E described in the book and in class, is that the bit-level representation can be used to compare two values and determine which one is less than or equal to the other or conversely which one is greater than or equal to the other.

We shouldn't ever use floats or doubles as counters in for loops or when checking for equality, but we often have code that might look like this, where we are checking whether some value (perhaps read in or streaming in from some data source) meets some threshold that would cause us to take action:

    double value, threshold;

    ...

    if (value >= threshold) {
      // take action
    }

A useful property of floating point numbers is that we can treat the binary representation of each of two float values or double values as unsigned integers, get the sign bit of each, and then use a combination of shift, and logical operators (!, ==, ||, &&) to test certain cases and to combine the cases into one expression to determine whether the values are either <= or >= each other. This is how the machine can do faster comparisons of these numbers- they do not have to be treated as actual mathematical numbers (nor can they).

## Goal of assignment

You are given a file called `floatParts.c` that you must complete. There are TODO tags where you need to either describe what an existing function does or where you need to complete the function given a description and some starter code.

You are also given a `test.c` file that contains some code to get you started. The asserts will fail until you get your functions working properly. The while loop shown as a test will not work correctly either until you have completed the functions.

Your need to create sufficient tests to ensure that your code works with all valid float numbers. **Please be aware that it will take a fairly large number of test cases to ensure that your functions are correct.** Remember that there are two types of encodings for M and E that create the exp and frac portions of a single precision floating point number: denormalized (really small fractional numbers) and normalized numbers. There are "edge cases" for each of these: smallest and largest values. These numbers are positive and negative. Then there are the special cases that we talked about in class: infinity and NaN. In this case, you can assume that it is not possible to use relational operations when a float value is NaN, so you do not have to test that. Another aspect to consider is that your functions will be testing for equality as well as less than and greater than. If you think carefully about all of this, it adds up to a very large number of cases that you need to try.

Keep the mantra of this kind of testing in mind: zero, 1, many, and the edges, in both positive and negative directions.

### Important

If you want to try to obtain the limits of floats for testing, there is a library in C for floating point numbers called float.h that has values called FLOAT_MIN and FLOAT_MAX. This does not help you for finding values in both the denormalized and normalized ranges of numbers. You will in this case need to devise numbers that are close to the limits for the smallest and largest denormalized and normalized numbers. Please don't feel the need to get exactly the limit, but rather get numbers very close, but not beyond the limits. Don't forget negative numbers.



Because there are so many test cases, **you must use asserts in your tests**. The printf statements given to you in test.c are *solely for initial debugging purposes*. You will want to comment these out once you determine that your asserts are working in your tests.

### Grading Criteria

1. compiles and runs, creating an executable named `fp_relational_ops`
1. code follows the coding guidelines, including descriptions of the functions you write
1. correctness
1. only used bitwise and relational operators in your functions
1. use of asserts in tests, including in loops that complete successfully
