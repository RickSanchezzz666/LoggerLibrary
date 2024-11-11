#include <catch2/catch_all.hpp>

#define TEST_NAME "[LogFile]"

#include "../testRunner.hpp"

#include "../../logger_module.hpp"

#include <string>

TEST_CASE("Create LogFile Class", TEST_NAME) {
	printStartTest(TEST_NAME, "Create LogFile Class");

	SECTION("LogFile Constructor 1") {
		GIVEN("const char* fileName") {
			const char* fileName = "testing";
			THEN("Class creation") {
				LogFile logFile(fileName, FileFormat::TXT);

				REQUIRE(logFile.getFileName() == fileName);
			}
		}
	}

	SECTION("LogFile Constructor 2") {
		GIVEN("const std::string fileName") {
			const std::string fileName = "testing";
			THEN("Class creation") {
				LogFile logFile(fileName, FileFormat::TXT);

				REQUIRE(logFile.getFileName() == fileName);
			}
		}
	}
}

TEST_CASE("Class Methods", TEST_NAME) {
	printStartTest(TEST_NAME, "Class Methods");

	WHEN("isInfoValid is called") {
		SECTION("Info is valid") {
			GIVEN("Valid information") {
				const std::string fileName = "testing";
#ifdef _WIN32
				const std::string filePathAbs = "D:\\testing\\folder";
				const std::string filePathRel = ".\\testing\\folder";
#else
				const std::string filePathAbs = "./testing/folder";
				const std::string filePathRel = "/testing/folder";
#endif
				THEN("Class creation with Absolute Path and Correct Filename") {
					LogFile logFile(fileName, FileFormat::TXT, filePathAbs);

					REQUIRE(logFile.isInfoValid());
				}
				AND_THEN("Class creation with Relative Path and Correct Filename") {
					LogFile logFile(fileName, FileFormat::TXT, filePathRel);

					REQUIRE(logFile.isInfoValid());
				}
			}
		}

		SECTION("Info is invalid") {
			GIVEN("Invalid information") {
				WHEN("Filename is invalid") {
#ifdef _WIN32
					const std::string fileName1 = "";
					const std::string fileName2 = "<file>";
					const std::string fileName3 = "\\filename";
					const std::string fileName4 = "\"filename\"";
#else
					const std::string fileName1 = "";
					const std::string fileName2 = "/filename";
					const std::string fileName3 = "file\\name";
					const std::string fileName4 = " ";
#endif
					THEN("Class creation") {
						LogFile logFile1(fileName1, FileFormat::TXT);
						LogFile logFile2(fileName2, FileFormat::TXT);
						LogFile logFile3(fileName3, FileFormat::TXT);
						LogFile logFile4(fileName4, FileFormat::TXT);

						REQUIRE(!logFile1.isInfoValid());
						REQUIRE(!logFile2.isInfoValid());
						REQUIRE(!logFile3.isInfoValid());
						REQUIRE(!logFile4.isInfoValid());
					}
				}
				AND_WHEN("File Path is invalid") {
					const std::string fileName = "testing";
#ifdef _WIN32
					const std::string filePath1 = "";
					const std::string filePath2 = "D:d\\folder";
					const std::string filePath3 = "./relative";
					const std::string filePath4 = "...\\path";
#else
					const std::string filePath1 = "";
					const std::string filePath2 = "D:\\folder";
					const std::string filePath3 = ".\\relative";
					const std::string filePath4 = ".../path";
#endif
					THEN("Class creation") {
						LogFile logFile1(fileName, FileFormat::TXT, filePath1);
						LogFile logFile2(fileName, FileFormat::TXT, filePath2);
						LogFile logFile3(fileName, FileFormat::TXT, filePath3);
						LogFile logFile4(fileName, FileFormat::TXT, filePath4);

						REQUIRE(!logFile1.isInfoValid());
						REQUIRE(!logFile2.isInfoValid());
						REQUIRE(!logFile3.isInfoValid());
						REQUIRE(!logFile4.isInfoValid());
					}
				}
			}
		}
	}
	AND_WHEN("FileName getter and setter") {
		SECTION("Valid information") {
			const std::string oldFileName = "oldFileName";
			GIVEN("New file name") {
				const std::string newFileName = "newFile";
				THEN("Class creation") {
					LogFile logFile(oldFileName, FileFormat::TXT);

					REQUIRE(logFile.getFileName() == oldFileName);
					AND_THEN("Set new name") {
						logFile.setFileName(newFileName);

						REQUIRE(logFile.getFileName() == newFileName);
					}
				}
			}
		}

		SECTION("Invalid information") {
			const std::string oldFileName = "oldFileName";
			GIVEN("New file name") {
				const std::string newFileName = "newFile";
				THEN("Class creation") {
					LogFile logFile(oldFileName, FileFormat::TXT);

					REQUIRE(logFile.getFileName() == oldFileName);
					AND_THEN("Set new name") {
						logFile.setFileName(newFileName);

						REQUIRE(logFile.getFileName() != oldFileName);
					}
				}
			}
		}
	}
	AND_WHEN("FileFormat getter and setter") {
		SECTION("Valid information") {
			const FileFormat oldFileFormat = FileFormat::TXT;
			GIVEN("New file format") {
				const FileFormat newFileFormat = FileFormat::CSV;
				THEN("Class creation") {
					LogFile logFile("testing", oldFileFormat);

					REQUIRE(logFile.getFileFormat() == oldFileFormat);
					AND_THEN("Set new format") {
						logFile.setFileFormat(newFileFormat);

						REQUIRE(logFile.getFileFormat() == newFileFormat);
					}
				}
			}
		}

		SECTION("Invalid information") {
			const FileFormat oldFileFormat = FileFormat::TXT;
			GIVEN("New file format") {
				const FileFormat newFileFormat = FileFormat::CSV;
				THEN("Class creation") {
					LogFile logFile("testing", oldFileFormat);

					REQUIRE(logFile.getFileFormat() == oldFileFormat);
					AND_THEN("Set new format") {
						logFile.setFileFormat(newFileFormat);

						REQUIRE(logFile.getFileFormat() != oldFileFormat);
					}
				}
			}
		}
	}
	AND_WHEN("FullFileName getter") {
		SECTION("Valid information") {
			WHEN("New file format") {
				const FileFormat oldFileFormat = FileFormat::TXT;
				GIVEN("New file format") {
					const FileFormat newFileFormat = FileFormat::CSV;
					THEN("Class creation") {
						LogFile logFile("testing", oldFileFormat);

						REQUIRE(logFile.getFullFileName() == "testing.txt");
						AND_THEN("Set new format") {
							logFile.setFileFormat(newFileFormat);

							REQUIRE(logFile.getFullFileName() == "testing.csv");
						}
					}
				}
			}
			AND_WHEN("New file name") {
				const std::string oldFileName = "oldFileName";
				GIVEN("New file name") {
					const std::string newFileName = "newFile";
					THEN("Class creation") {
						LogFile logFile(oldFileName, FileFormat::TXT);

						REQUIRE(logFile.getFullFileName() == oldFileName + ".txt");
						AND_THEN("Set new name") {
							logFile.setFileName(newFileName);

							REQUIRE(logFile.getFullFileName() == newFileName + ".txt");
						}
					}
				}
			}
		}

		SECTION("Invalid information") {
			WHEN("New file format") {
				const FileFormat oldFileFormat = FileFormat::TXT;
				GIVEN("New file format") {
					const FileFormat newFileFormat = FileFormat::CSV;
					THEN("Class creation") {
						LogFile logFile("testing", oldFileFormat);

						REQUIRE(logFile.getFullFileName() == "testing.txt");
						AND_THEN("Set new format") {
							logFile.setFileFormat(newFileFormat);

							REQUIRE(logFile.getFullFileName() != "testing.txt");
						}
					}
				}
			}
			AND_WHEN("New file name") {
				const std::string oldFileName = "oldFileName";
				GIVEN("New file name") {
					const std::string newFileName = "newFile";
					THEN("Class creation") {
						LogFile logFile(oldFileName, FileFormat::TXT);

						REQUIRE(logFile.getFullFileName() == oldFileName + ".txt");
						AND_THEN("Set new name") {
							logFile.setFileName(newFileName);

							REQUIRE(logFile.getFullFileName() != oldFileName + ".txt");
						}
					}
				}
			}
		}
	}
}

