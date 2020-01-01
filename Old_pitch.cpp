
#include "pitch.h"

namespace FisMoll {

	// Create memory bank of pitches past
	unordered_map<string, int> FisMemPath({
		{"fis",0},{"gis",0},{"a",0},{"b",0},{"bis",0},{"cis",0},{"d",0},{"dis",0},{"e",0},{"f",0}
		});

	// increment map value for key 'c'
	void SetStepCountFisPathMem(string c) {
		FisMemPath[c]++;
	};

	//-------------------------------------------------------------
	// construct PitchClass

	Pitch::Pitch(ePitchFisMoll pp) : current_pitch{ pp } { } // initializes pitch with a member of enum class Fis Moll

	//--------------------------------------------------------------

	// Function definitions

	ePitchFisMoll Pitch::GetCurrentPitch() { return current_pitch; }

	string Pitch::GetCurrentPitchString(){ return current_pitch_string; }

	void Pitch::SetCurrentPitch(Pitch cp) { current_pitch = cp.GetCurrentPitch(); }
	void Pitch::SetCurrentPitchString(Pitch cp) { current_pitch_string = cp.GetCurrentPitchString(); }

	//-------------------------------------------------------------------------------------------

	string Pitch::GetPitchAsString(Pitch p) {
		switch (p.GetCurrentPitch()) { // returns the current pitch from ePitchFisMoll
		case ePitchFisMoll::fis:
			return "fis";              // return transposed pitch
			break;
		case ePitchFisMoll::gis:
			return "gis";
			break;
		case ePitchFisMoll::a:
			return "a";
			break;
		case ePitchFisMoll::b:
			return "b";
			break;
		case ePitchFisMoll::bis:
			return "bis";
			break;
		case ePitchFisMoll::cis:
			return "cis";
			break;
		case ePitchFisMoll::d:
			return "d";
			break;
		case ePitchFisMoll::dis:
			return "dis";
			break;
		case ePitchFisMoll::e:
			return "e";
			break;
		case ePitchFisMoll::f:
			return "f";
			break;
		}
	};


	//--------------------------------------------------------------	

	// Define transposition functions
	//
	// up a fifth()
	ePitchFisMoll Pitch::TransposeUpFifth(Pitch p) {
		// switch over input
		switch (p.GetCurrentPitch()) {
		case ePitchFisMoll::fis:                     // for a case where current pitch is F#
			p.SetCurrentPitch(ePitchFisMoll::cis);   // transpose current pitch up a 5th to C# 
			return p.GetCurrentPitch();                     // return transposed pitch
			break;
		case ePitchFisMoll::gis:
			p.SetCurrentPitch(ePitchFisMoll::dis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::a:
			p.SetCurrentPitch(ePitchFisMoll::e);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::b:
			p.SetCurrentPitch(ePitchFisMoll::fis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::bis:
			p.SetCurrentPitch(ePitchFisMoll::gis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::cis:
			p.SetCurrentPitch(ePitchFisMoll::gis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::d:
			p.SetCurrentPitch(ePitchFisMoll::a);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::dis:
			p.SetCurrentPitch(ePitchFisMoll::b);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::e:
			p.SetCurrentPitch(ePitchFisMoll::b);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::f:
			p.SetCurrentPitch(ePitchFisMoll::bis);
			return p.GetCurrentPitch();
			break;
		}

	};



	// up a third()
	ePitchFisMoll Pitch::TransposeUpThird(Pitch p) {
		// switch over input
		switch (p.GetCurrentPitch()) {
		case ePitchFisMoll::fis:
			p.SetCurrentPitch(ePitchFisMoll::a);
			return p.GetCurrentPitch();              // return transposed pitch
			break;
		case ePitchFisMoll::gis:
			p.SetCurrentPitch(ePitchFisMoll::b);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::a:
			p.SetCurrentPitch(ePitchFisMoll::cis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::b:
			p.SetCurrentPitch(ePitchFisMoll::d);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::bis:
			p.SetCurrentPitch(ePitchFisMoll::e);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::cis:
			p.SetCurrentPitch(ePitchFisMoll::e);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::d:
			p.SetCurrentPitch(ePitchFisMoll::f);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::dis:
			p.SetCurrentPitch(ePitchFisMoll::fis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::e:
			p.SetCurrentPitch(ePitchFisMoll::gis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::f:
			p.SetCurrentPitch(ePitchFisMoll::a);
			return p.GetCurrentPitch();
			break;
		}
	};

	// down a sixth()
	ePitchFisMoll Pitch::TransposeDownSixth(Pitch p) {
		// switch over input
		switch (p.GetCurrentPitch()) {
		case ePitchFisMoll::fis:
			p.SetCurrentPitch(ePitchFisMoll::a);
			return p.GetCurrentPitch();                            // return transposed pitch
			break;
		case ePitchFisMoll::gis:
			p.SetCurrentPitch(ePitchFisMoll::bis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::a:
			p.SetCurrentPitch(ePitchFisMoll::cis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::b:
			p.SetCurrentPitch(ePitchFisMoll::dis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::bis:
			p.SetCurrentPitch(ePitchFisMoll::e);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::cis:
			p.SetCurrentPitch(ePitchFisMoll::f);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::d:
			p.SetCurrentPitch(ePitchFisMoll::fis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::dis:
			p.SetCurrentPitch(ePitchFisMoll::fis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::e:
			p.SetCurrentPitch(ePitchFisMoll::gis);
			return p.GetCurrentPitch();
			break;
		case ePitchFisMoll::f:
			p.SetCurrentPitch(ePitchFisMoll::a);
			return p.GetCurrentPitch();
			break;
		}
	};
	//------------------------------------------------------------------

	// Define Path One (ePitchFisMoll p)
	void Pitch::SetPositionOnPathOne(Pitch p) {  // Move the pitch along path
		int step_counter = 0;                    // count steps in local path (path is a short, recursive loop)
		ePitchFisMoll trans_pitch;
		while (step_counter < 4) {
			if (step_counter < 3) {                                    // if no of steps less than two
				trans_pitch = TransposeUpFifth(p.GetCurrentPitch());   // current pitch moved up a fifth
				step_counter++;
				p.IncrementSteps();                                    // count steps taken in path
				p.SetCurrentPitch(trans_pitch);                        // update current pitch
				SetCurrentPitchString(p);                              // convert current pitch to string  
				SetStepCountFisPathMem(p.GetCurrentPitchString());     // add pass of new pitch to memory of pitches past
			}
			else if (step_counter < 4) {                               // if path steps is more than two 
				trans_pitch = TransposeUpThird(p);                     // current pitch += up_a_third(current pitch)
				step_counter++;                                        // count steps taken in path
				p.IncrementSteps();
				p.SetCurrentPitch(trans_pitch);
				SetCurrentPitchString(p);                              // convert current pitch to string  
				SetStepCountFisPathMem(p.GetCurrentPitchString());     // add pass of new pitch to memory of pitches past
			}
			else break;
		}
	};

	//--------------------------------------------------------------


	// Steph through each path recursively

	// for x iterations
	// track pitch p along pathOne
	void Pitch::TracePathOne(Pitch init_pitch) {                    // initialize this function with a starting pitch
		for (int i = 0; i < 5000; ++i) {                           // step through the path 5000 times
			init_pitch.SetCurrentPitch(init_pitch);                // update enum pitch each time
			init_pitch.SetPositionOnPathOne(init_pitch);             // update current pitch location each time
		}
	};

	// follow pathTwo(pitch p)

	//------------------------------------------------------------------


}
