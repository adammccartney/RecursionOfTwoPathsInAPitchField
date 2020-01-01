#include "pitch.h"

namespace PitchPath {

	Pitch operator++(Pitch& p)
	{
		p = (p == Pitch::h) ? Pitch::c : Pitch(int(p) + 1); // wrap around
		return p;
	}
	
	//-------------------------------------------------------------
	// construct PitchClass

	// default
	PitchClass::PitchClass() : p{ 0 }, tp{ {'\0'} } { }
	PitchClass::PitchClass(int p, std::vector<int> tp) 
		: p{ p }, tp{ tp }
	{
		//if (!is_valid())throw Invalid{}; // if valid, initializes pitch with a member of enum class Fis Moll
	}

	void PitchClass::PrintRecursionMap()
	{
		for (auto& e : recursion_map) {
			std::cout << '{' << e.first << "," << e.second << '}' << '\n';
		}
	}


	//----------------------------------------------------------------

	/*
	bool PitchClass::is_valid()
	{
		if(p < 0 || 11 > p)return false; // there are 12 pitches in an octave
		{
			// if pitch is valid, initialize
			PitchClass::p = p;
			PitchClass::tp = tp;
		}
		return true;
	}
	*/
	//------------------------------------------------------------------------

	void PitchClass::AddPitch(int n)
	{
		bool lastPitch = false;
		// if day exceeds last pitch in the octave, roll on to next octave and set pitch to 0
		for (int i = 0; i < n; ++i)
		{
			if (p == 11)
				lastPitch = true;
				p = (p == 11) ? 0 : ++p; // at h, roll on to c if pitch = 11, otherwise ++
		}
	}

	//------------------------------------------------------------------------

	// arguments are starting pitch, tranpositions, number of interations
	void PitchClass::Transpose(const int& p, const std::vector<int>& tp, int x)  
	{
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < tp.size(); ++j) {
				AddPitch(tp[j]);
				CountPitchRecursion(GetPitch());
			}
		}
	}
};//PitchPath
