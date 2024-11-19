cmake_minimum_required (VERSION 3.8)

project ("LoggerLibraryTests")

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.3.2
)

FetchContent_MakeAvailable(Catch2)

add_executable(LoggerLibraryTests 
	"test_main.cpp"
	"testRunner.hpp"
   "Tests/test_LogFile.cpp")

target_link_libraries(LoggerLibraryTests PRIVATE Catch2::Catch2WithMain)