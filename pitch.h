#ifndef PITCH_GUARD
#define PITCH_GUARD

#include <iostream>
#include <string>
#include <unordered_map>


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
		ePitchFisMoll GetPitch() { return p; };

		std::string ConvertPitchToString(Pitch p);

		std::string GetPitchString() { return current_pitch_string; }


		//modifying operations
		void SetPitch(ePitchFisMoll pp) { p = pp; }


		ePitchFisMoll TransposeUpFifth(Pitch p);
		ePitchFisMoll TransposeUpThird(Pitch p);
		ePitchFisMoll TransposeDownSixth(Pitch p);
		

	private:
		int steps{ 1 };
		ePitchFisMoll p;
		//int ip;
		std::string current_pitch_string;
		bool is_valid();

	};

	//std::ostream& operator<<(std::ostream& os, Pitch& p) const;
	// Create memory bank of pitches past
	std::unordered_map<std::string, int> FisMemPath({
		{"fis",0},{"gis",0},{"a",0},{"b",0},{"bis",0},{"cis",0},{"d",0},{"dis",0},{"e",0},{"f",0}
		});

	// increment map value for key 'c'
	void SetStepCountFisMemPath(std::string c) {FisMemPath[c]++;};


};//FisMoll
#endif

