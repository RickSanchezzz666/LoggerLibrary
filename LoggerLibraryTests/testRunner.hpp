#ifndef TEST_RUNNER_HPP
#define TEST_RUNNER_HPP

#include <iostream>
#include <string>

static void printStartTest(const std::string& test_name, const std::string& test_case) {
	std::cout << test_name << " testing `" << test_case << "` ..\n";
}

#endif // TEST_RUNNER_HPP