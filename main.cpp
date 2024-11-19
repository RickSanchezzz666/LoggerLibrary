#include "logger_module.hpp"
#include <iostream>

int main() {

	Logger::logToFile(".\\fileName", "message1;info", false);
	return 0;
}