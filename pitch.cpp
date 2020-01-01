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
		return os << p.GetPitch() << '\n';
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
		switch (p.GetPitch()) { // returns the current pitch from ePitchFisMoll
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
		switch (p.GetPitch()) {
		case ePitchFisMoll::fis:                     // for a case where current pitch is F#
			return ePitchFisMoll::cis;                     // return transposed pitch
			break;
		case ePitchFisMoll::gis:
			return ePitchFisMoll::dis;
			break;
		case ePitchFisMoll::a:
			return ePitchFisMoll::e;
			break;
		case ePitchFisMoll::b:
			return ePitchFisMoll::fis;
			break;
		case ePitchFisMoll::bis:
			return ePitchFisMoll::gis;
			break;
		case ePitchFisMoll::cis:
			return ePitchFisMoll::gis;
			break;
		case ePitchFisMoll::d:
			p.SetPitch(ePitchFisMoll::a);
			return p.GetPitch();
			break;
		case ePitchFisMoll::dis:           
			return ePitchFisMoll::b;              // not a fifth because of value returned from d
			break;
		case ePitchFisMoll::e:
			return ePitchFisMoll::b;
			break;
		case ePitchFisMoll::f:
			return ePitchFisMoll::bis;
			break;
		}

	};

	
	// up a third()
	ePitchFisMoll Pitch::TransposeUpThird(Pitch p) {
		// switch over input
		switch (p.GetPitch()) {
		case ePitchFisMoll::fis:
			return ePitchFisMoll::a;              // return transposed pitch
			break;
		case ePitchFisMoll::gis:
			return ePitchFisMoll::b;
			break;
		case ePitchFisMoll::a:
			return ePitchFisMoll::cis;
			break;
		case ePitchFisMoll::b:
			return ePitchFisMoll::d;
			break;
		case ePitchFisMoll::bis:
			return ePitchFisMoll::e;
			break;
		case ePitchFisMoll::cis:
			return ePitchFisMoll::e;
			break;
		case ePitchFisMoll::d:
			return ePitchFisMoll::f;
			break;
		case ePitchFisMoll::dis:
			return ePitchFisMoll::fis;
			break;
		case ePitchFisMoll::e:
			return ePitchFisMoll::gis;
			break;
		case ePitchFisMoll::f:
			return ePitchFisMoll::a;
			break;
		}
	};
	
	
	// down a sixth()
	ePitchFisMoll Pitch::TransposeDownSixth(Pitch p) {
		// switch over input
		switch (p.GetPitch()) {
		case ePitchFisMoll::fis:
			return ePitchFisMoll::a;                            // return transposed pitch
			break;
		case ePitchFisMoll::gis:
			return ePitchFisMoll::bis;
			break;
		case ePitchFisMoll::a:
			return ePitchFisMoll::cis;
			break;
		case ePitchFisMoll::b:
			return ePitchFisMoll::dis;
			break;
		case ePitchFisMoll::bis:
			return ePitchFisMoll::e;
			break;
		case ePitchFisMoll::cis:
			return ePitchFisMoll::f;
			break;
		case ePitchFisMoll::d:
			return ePitchFisMoll::fis;
			break;
		case ePitchFisMoll::dis:
			return ePitchFisMoll::fis;
			break;
		case ePitchFisMoll::e:
			return ePitchFisMoll::gis;
			break;
		case ePitchFisMoll::f:
			return ePitchFisMoll::a;
			break;
		}
	};
	
};//FisMoll
