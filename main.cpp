#include "logger_module.hpp"
#include <iostream>

int main() {
	LogFile logFile("fileName", FileFormat::TXT, ".\\", "name;time");
	
	if (!logFile.isInfoValid()) {
		std::cerr << "File info is not valid!\n";
	} else std::cout << "Everything is fine!\n";

	Logger::logToFile(logFile, "message1;2021");
	return 0;
}