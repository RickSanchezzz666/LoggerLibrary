Single-Header Library for Simple logging in file using Plain C++ for Windows and Linux with No Dependencies needed.

## Quick Start
- Download latest release - [**CLICK HERE**](https://github.com/RickSanchezzz666/LoggerLibrary/releases/latest)
 - Copy .hpp file **logger_module.hpp** into your source folder
 - Include header file in your source files - **#include logger_module.hpp**
 - And use it!:
    - Create LogFile instance:
    ```
    LogFile logFile(file_name: str, file_format: FileFormat, path: str)
    Logger::logToFile(logFile: LogFile, message: str);
    ```
    - If you already have existing file: 
        ```
        Logger::logToFile(filePath: str, message: str);
        ```
- Additionally: To ensure that created LogFile instance contains correct information you can use method: **isInfoValid()**: 
    - Example: 
    ```
    if (!logFile.isInfoValid()) {
		std::cerr << "File info is not valid!\n";
	} else std::cout << "Everything is fine!\n";
    ```
- Available File Formats: **.txt, .csv, .log**.

### To access full documentation follow -> [**FULL DOCUMENTATION**](docs/DOCUMENTATION.md)
