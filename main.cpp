
#include "pitch.h"
#include <stdexcept>   // for exception, runtime_error, out_of_range

int main()
try {
	using namespace FisMoll;

	Pitch TestPitch{ePitchFisMoll::fis};

	std::cout << "here is the current pitch: " << TestPitch.ConvertPitchToString(TestPitch) << '\n';
	

	
	std::cout << "here it is up a fifth: " 
		<< TestPitch.ConvertPitchToString(TestPitch.TransposeUpFifth(TestPitch)) << '\n';

	//std::cout << "here is a test pitch as int: " << TestPitch.CurrentPitch() << '\n';
	//std::cout << "here is a default test pitch as int: " << TestDefaultPitch.CurrentPitch() << '\n';

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