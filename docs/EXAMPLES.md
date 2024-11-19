# General
```
	File Path should only be in this formats depending on your System:
	Windows:
		Absolute: "D:\\Folder1\\Folder2"
		Relative: ".\\Folder1" or "..\\Folder2"
	Linux:
		Absolute: "/home/Folder1"
		Relative: "./Folder1" or "../Folder2"

	File Name have restrictions on naming depending on your System:
		Windows Restricted symbols: "\\/:*?\"<>|"
		Linux Restricted symbols:	"\\/"

    Available File Formats: .txt, .csv, .log.
```

# 1. Logging using LogFile with header
```
#include "logger_module.hpp"

int main() {
	LogFile logFile("fileName", FileFormat::TXT, ".\\", "type;message");
	
	if (!logFile.isInfoValid()) {
		std::cerr << "File info is not valid!\n";
	} else std::cout << "Everything is fine!\n";

	Logger::logToFile(logFile, "info;test message");

	return 0;
}
```
### Output in log file
```
type;message
[HH:MM:SS] info;test message
```

# 2. Logging using LogFile with/no header
```
#include "logger_module.hpp"

int main() {
	LogFile logFile("fileName", FileFormat::TXT, ".\\");
	
	if (!logFile.isInfoValid()) {
		std::cerr << "File info is not valid!\n";
	} else std::cout << "Everything is fine!\n";

	Logger::logToFile(logFile, "info;test message");

	return 0;
}
```
### Output in log file
```
[HH:MM:SS] info;test message
```

# 3. Logging using LogFile with/no timestamps
```
#include "logger_module.hpp"

int main() {
	LogFile logFile("fileName", FileFormat::CSV, ".\\");
	
	if (!logFile.isInfoValid()) {
		std::cerr << "File info is not valid!\n";
	} else std::cout << "Everything is fine!\n";

	Logger::logToFile(logFile, "info;test message", false);

	return 0;
}
```
### Output in log file
```
info;test message
```

# 4. Logging using relative path
```
#include "logger_module.hpp"

int main() {
	Logger::logToFile(".\\fileName.txt", "info;test message");

	return 0;
}
```
### Output in log file
```
[HH:MM:SS] info;test message
```

# 5. Logging using absolute path
```
#include "logger_module.hpp"

int main() {
	Logger::logToFile("D:\\Folder\\fileName.txt", "info;test message");

	return 0;
}
```
### Output in log file
```
[HH:MM:SS] info;test message
```

# 6. Logging using path with/no timestamps
```
#include "logger_module.hpp"

int main() {
	Logger::logToFile(".\\fileName.txt", "info;test message", false);

	return 0;
}
```
### Output in log file
```
info;test message
```
# 7. Usage of Getters/Setters in LogFile
```
#include "logger_module.hpp"

int main() {
	LogFile logFile("fileName", FileFormat::CSV, ".\\");

    std::cout << logFile.getFileName() << "\n";

    logFile.setFileName("newFileName");

    std::cout << logFile.getFileName() << "\n";

    if (!logFile.isInfoValid()) {
		std::cerr << "File info is not valid!\n";
	} else std::cout << "Everything is fine!\n";

	return 0;
}
```
### Output in Console
```
fileName
newFileName
Everything is fine!
```