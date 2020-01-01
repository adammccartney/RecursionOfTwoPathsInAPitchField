#ifndef PITCH_GUARD
#define PITCH_GUARD

#include <iostream>
#include <string>


namespace FisMoll {

	
	// Create pitch space
	enum class ePitchFisMoll { fis = 1, gis, a, b, bis, cis, d, dis, e, f };
	
	class Pitch {
	public:
		Pitch();                // default constructor 
		Pitch(ePitchFisMoll p); // initialize with pitch from F# minor and 1 steps
		//Pitch(int p); // test with int as pitch

		// nonmodifying operations
		//int CurrentPitch();
		ePitchFisMoll GetCurrentPitch() { return p; };
		std::string ConvertPitchToString(Pitch p);
		void SetCurrentPitchString(Pitch cp) { current_pitch_string = cp.GetCurrentPitchString(); }
		std::string GetCurrentPitchString() { return current_pitch_string; }


		//modifying operations
		void SetCurrentPitch(ePitchFisMoll transposed_pitch) { p = transposed_pitch; }
		ePitchFisMoll TransposeUpFifth(Pitch p);
		

	private:
		int steps{ 1 };
		ePitchFisMoll p;
		//int ip;
		std::string current_pitch_string;
		bool is_valid();

	};

	//std::ostream& operator<<(std::ostream& os, Pitch& p) const;

};//FisMoll
#endif

