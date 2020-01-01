Recursion in a Pitch Field
==========================

Simple program that models the path traveled by individual pitches of a melody 
as they are transposed through a pitch field. In other words, these pitches
are transposed by a set of diatonic intervals a number of times and the number of 
times that a specific pitch occurs is counted. The idea is an attempt to model
the types of recursive algorithms used to generate strange attractors and other
similar types of chaotic symmetries. 

As in it's a music by numbers generator. Recurring pitches will be *colored*
according to a statistical distribution. Color in this case refers to the 
use of a specific type of orchestration to differentiate between pitches. 
That's not part of the program, but maybe it helps to know.

Code has been generated from pseudocode, so the
comments *should* convey a detailed description of the idea and what's happening.


### Update 1.1.20 
Putting the program back together one function at a time to test for errors, 
working so far, having tested the *convert to string, set, get and transpose*
functions. It seems like I might be short a member variable in the class definition.


### Update 31.12.19 
Had the header files in a bit of a mess and was getting multiple declaration
errors. Peared it back to the Pitch class definition and was able to locate
the source of error. 
Removed the std_lib_facilities.h as it was probably a source of error
and I shouldn't have been using it anyway.
