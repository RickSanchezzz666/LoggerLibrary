#define CATCH_CONFIG_RUNNER
#include <catch2/catch_all.hpp>

#include <iostream>
#include <chrono>
#include <string>

int main(int argc, char* argv[]) {

    std::cout << "Started running test cases..\n\n";

    auto startParsing = std::chrono::steady_clock::now();

    int result = Catch::Session().run(argc, argv);

    auto endParsing = std::chrono::steady_clock::now();

    auto parsingDurationS = std::chrono::duration_cast<std::chrono::seconds>(endParsing - startParsing);
    auto parsingDurationMl = std::chrono::duration_cast<std::chrono::milliseconds>(endParsing - startParsing);

    std::cout << "Tests done in " + std::to_string(parsingDurationS.count()) + "." + std::to_string(parsingDurationMl.count()) + " s.\n";

    return result;
}
