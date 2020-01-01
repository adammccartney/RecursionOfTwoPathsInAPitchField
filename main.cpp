
#include "pitch.h"
#include <stdexcept>   // for exception, runtime_error, out_of_range

int main()
try {
	using namespace FisMoll;

	Pitch TestPitch{ePitchFisMoll::fis};

	std::cout << "here is the current pitch: " << TestPitch.ConvertPitchToString(TestPitch) << '\n';
	
	TestPitch.SetPitch(TestPitch.TransposeDownSixth(TestPitch)); // test transpose function
	std::cout << "here it is down a sixth: " 
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';    // confirm it works
	SetStepCountFisMemPath(TestPitch.GetPitchString());          // count action in map
	TestPitch.SetPitch(TestPitch.TransposeDownSixth(TestPitch)); // repeat
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	std::cout << "and again: "
		<< TestPitch.ConvertPitchToString(TestPitch) << '\n';
	SetStepCountFisMemPath(TestPitch.GetPitchString());
	for (auto& e : FisMemPath) {
		std::cout << '{' << e.first << "," << e.second << '}' << '\n';
	}

}
catch (std::runtime_error& e) {
	std::cout << "Caught a runtime_error exception: "
		<< e.what() << '\n';
}
catch (std::exception& e) {
	std::cout << "Caught an exception of an unexpected type: "
		<< e.what() << '\n';
}
catch (...) {
	std::cout << "Caught an unknown exception\n";
}
