#ifndef PITCH_GUARD
#define PITCH_GUARD

#include<string>
#include "c:\Users\Adam\Documents\pppuc++\std_lib_facilities.h"

namespace FisMoll {

	// Create pitch space
	enum class ePitchFisMoll {
		fis = 1, gis, a, b, bis, cis, d, dis, e, f
	};

class Pitch {
public:	
	Pitch();                // default constructor 
	Pitch(ePitchFisMoll p); // initialize with pitch from F# minor and 1 steps

	// nonmodifying operations
	string GetPitchAsString(Pitch p);
	ePitchFisMoll GetCurrentPitch();
	string GetCurrentPitchString();

	// modifying operations
	ePitchFisMoll TransposeUpFifth(Pitch p);
	ePitchFisMoll TransposeUpThird(Pitch p);
	ePitchFisMoll TransposeDownSixth(Pitch p);
	void SetCurrentPitch(Pitch cp);
	void SetCurrentPitchString(Pitch cp);

	void SetPositionOnPathOne(Pitch p);

	void IncrementSteps() { steps++; }

	void TracePathOne(Pitch init_pitch);

private:
	int steps = 1;
	ePitchFisMoll current_pitch{ePitchFisMoll::fis};
	string current_pitch_string{"fis"};

};

// Declare Specific Pitch Objects
Pitch PPathOne(ePitchFisMoll::fis);  // initial pitch on PathOne

}//FisMoll
#endif
