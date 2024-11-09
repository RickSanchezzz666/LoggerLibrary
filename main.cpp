#include "logger_module.hpp"
#include <iostream>

int main() {
	LogFile logFile("fileName", FileFormat::TXT, ".\\asd");
	if (!logFile.isInfoValid()) {
		std::cerr << "File info is not valid!";
	} else std::cout << "Everything is fine!";
	return 0;
}