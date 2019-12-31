/*

 Short program to model recursion in an extended diatonic pitch field.

 Given two starting points and the definition of two paths,
 the program counts the number of occurances of discrete 
 pitches along the each path and then outputs a set of key,value
 pairs that indicate the predominance of certain pitches.

 The method is inspired by some of the ideas found in Symmetry in Chaos
 by Field and Golubitsky.




*/

#include "pitch.cpp"
#include <iterator>


	//------------------------------------------------------------------

	// Define Two Paths

	// Define Path Two (PitchFisMoll p)
	// if first step
	// current pitch += up_a_fifth(p)
	// add pass of new pitch to memory of pitches past
	// count steps taken in path
	// if second or third step
	// current pitch += up_a_third(current pitch)
	// add pass of new pitch to memory of pitches past
	// count steps taken in path
	// if fourth step
	// current pitch += down_a_sixth(current pitch)
	// add pass of new pitch to memory of pitches past
	// count steps taken in path
	// reset steps to 0
	//--------------------------------------------------------------


int main()
try {
	using namespace FisMoll;

	PPathOne.TracePathOne(PPathOne);
	for (auto& e : FisMemPath) {
		cout << '{' << e.first << ", " << e.second << '}' << '\n';
	};

	// Print data to file 

}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}