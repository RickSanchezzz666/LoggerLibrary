#include "logger_module.hpp"
#include <iostream>

int main() {
	LogFile logFile("fileName", FileFormat::TXT, "..\\");
	
	if (!logFile.isInfoValid()) {
		std::cerr << "File info is not valid!\n";
	} else std::cout << "Everything is fine!\n";

	return 0;
}