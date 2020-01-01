#include "pitch.h"

namespace FisMoll {
	
	ePitchFisMoll operator++(ePitchFisMoll& p)
	{
		p = (p == ePitchFisMoll::f) ? ePitchFisMoll::fis : ePitchFisMoll(int(p) + 1); // wrap around
		return p;
	}
	
	//-------------------------------------------------------------
	// construct PitchClass

	// default
	Pitch::Pitch() : p{ ePitchFisMoll::fis } {}

	Pitch::Pitch(ePitchFisMoll p) : p{ p } { } // initializes pitch with a member of enum class Fis Moll
	//Pitch::Pitch(int ip) : ip{ip} { }

	//----------------------------------------------------------------
	
	/*
	std::ostream& operator<<(std::ostream& os, Pitch& p) const
	{
		return os << p.GetCurrentPitch() << '\n';
	}
	*/

	bool Pitch::is_valid()
	{
		if(p < ePitchFisMoll::fis || ePitchFisMoll::f < p)return false;
		{
			// if pitch is valid, initialize
			Pitch::p = p;
		}
		return true;
	}
	

	//---------------------------------------------------------------------------

	// non modifying function definitions
	std::string Pitch::ConvertPitchToString(Pitch p)
	{
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
	}

	// ----------------------------------------------------------------------

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


};//FisMoll