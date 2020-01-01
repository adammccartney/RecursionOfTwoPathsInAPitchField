
#include "pitch.h"
#include <stdexcept>   // for exception, runtime_error, out_of_range

int main()
try {
	using namespace PitchPath;

	int fis = 7;
	std::vector<int> fft= { 7,7,4 };
	PitchClass fisOne = { fis,fft };

	int e = 6;
	std::vector<int> ttff = { 4,4,7,7 };
	PitchClass eOne = { e,ttff };

	fisOne.Transpose(fis, fft, 100000);
	fisOne.PrintRecursionMap();

	eOne.Transpose(e, ttff, 100000);
	eOne.PrintRecursionMap();

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
