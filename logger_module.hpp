/*
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
*/

#ifndef LOGGER_MODULE_HPP
#define LOGGER_MODULE_HPP


#include <string>
#include <algorithm> // remove_if
#include <cctype> // ::isspace
#include <fstream> // ofstream

#ifdef _WIN32

#define PATH_SEP '\\'
#define REL_STAY ".\\"
#define REL_LEAVE "..\\"

#else

#define PATH_SEP '/'
#define REL_STAY "./"
#define REL_LEAVE "../"

#endif


enum PathType { ABS, REL, INVALID };

enum FileFormat {
	TXT,
	CSV,
	LOG
};

// LogFile
class LogFile {
public:
	/*
	- file_name - name for your log file: 
	Example: "filename"
	- file_format - format of your log file: .txt, .csv, .log.
	Example: FileFormat::LOG
	- folder_path - absolute or relative path to folder where to store logs.
	Example: "../folder" Win - "..\\"
	*/
	LogFile(const std::string& file_name, FileFormat file_format, const std::string& folder_path = REL_STAY)
		: fileName(file_name), fileFormat(file_format), fullPath(folder_path) 
	{
		fileName.erase(std::remove_if(fileName.begin(), fileName.end(), ::isspace), fileName.end());
		if (fileName.length() > 256) fileName = fileName.substr(0, 256);

		pathRemoveLeadingSpaces();

		isPathAbsolute();

		concatFullName();
		
		if (pathType != INVALID) initLogFile();
	};

	/*
	- file_name - name for your log file:
	Example: "filename"
	- file_format - format of your log file: .txt, .csv, .log.
	Example: FileFormat::LOG
	- folder_path - absolute or relative path to folder where to store logs.
	Example: "../folder" Win - "..\\"
	*/
	LogFile(const char* file_name, FileFormat file_format, const std::string& folder_path = REL_STAY)
		: fileName(std::string(file_name)), fileFormat(file_format), fullPath(folder_path) 
	{
		fileName.erase(std::remove_if(fileName.begin(), fileName.end(), ::isspace), fileName.end());
		if (fileName.length() > 256) fileName = fileName.substr(0, 256);

		pathRemoveLeadingSpaces();
		
		isPathAbsolute();

		concatFullName();
		
		if (pathType != INVALID) {
			bool fileInit = initLogFile();
			if (!fileInit) pathType == INVALID;
		}
	};

	// File info validation
	bool isInfoValid() {
		return (isNameValid(fileName) && isPathValid() && initLogFile());
	}


	const std::string& getFileName() const { return fileName; }
	const FileFormat& getFileFormat() const { return fileFormat; }
	const std::string& getFullFileName() const { return fileFullName; }

	const std::string getFullPath() const { 
		if (pathType != INVALID) {
			if (pathType == REL && (fullPath == REL_STAY || fullPath == REL_LEAVE)) return fullPath + fileFullName;
			else return fullPath + PATH_SEP + fileFullName;
		}
		return REL_STAY;
	}

	// set new file name
	void setFileName(const std::string& newFileName) { 
		if (isNameValid(newFileName)) {
			fileName = newFileName;
			concatFullName();
		}
	}

	// set new file format: .csv, .txt, .log
	void setFileFormat(const FileFormat& newFileFormat) {
		fileFormat = newFileFormat;
		concatFullName();
	}

	~LogFile() {};

private:
	// Initialization of log file
	bool initLogFile() {
		const std::string fullFilePath = getFullPath();
		std::ifstream fileExists(fullFilePath);
		if (!fileExists.good()) {
			std::ofstream logFile(fullFilePath);
			logFile.close();
		}
		return fileExists.good();
	}

	// deleting unnecessary spaces before path
	void pathRemoveLeadingSpaces() {
		size_t firstNonSpace = fullPath.find_first_not_of(' ');
		if (firstNonSpace != std::string::npos) {
			fullPath = fullPath.substr(firstNonSpace);
		}
	}

	// Check method for invalid symbols in name
	bool isNameValid(const std::string& file_name) {
#ifdef _WIN32
		const std::string forbiddenChars = "\\/:*?\"<>|";
#else
		const std::string forbiddenChars = "\\/";
#endif
		return (file_name.find_first_of(forbiddenChars) == std::string::npos && !file_name.empty());
	};

	// Check method for invalid symbols and format in path
	bool isPathValid() {
		if (fullPath.empty()) return false;
#ifdef _WIN32
		if (pathType == ABS && (fullPath.find(PATH_SEP) == std::string::npos 
			|| (fullPath[1] != ':' && fullPath[2] != PATH_SEP))) return false;
		else if (pathType == REL && fullPath[1] == ':') return false;
#else
		if (pathType == ABS && (fullPath.find(PATH_SEP) == std::string::npos || fullPath[0] != PATH_SEP)) return false;
		else if (pathType == REL && fullPath[0] == '/') return false;
#endif
		return pathType != INVALID;
	};

	//Check method if path is absolute or relative
	void isPathAbsolute() {
		if (fullPath.empty()) return;

#ifdef _WIN32
		if (fullPath.find(REL_STAY) == 0 || fullPath.find(REL_LEAVE) == 0) pathType = REL;
		else if (fullPath[1] == ':' && fullPath[2] == PATH_SEP) pathType = ABS;
		else pathType = INVALID;
#else
		if (fullPath.find(REL_STAY) == 0 || fullPath.find(REL_LEAVE) == 0) pathType = REL;
		else if (fullPath[0] == '/') pathType = ABS;
		else pathType = INVALID;
#endif
	}

	// Concatenate file name and format to full name: example.txt
	void concatFullName() {
		if (!isNameValid(fileName)) return;
		switch (fileFormat)
		{
		case TXT:
			fileFullName = fileName + ".txt";
			break;
		case CSV:
			fileFullName = fileName + ".csv";
			break;
		case LOG:
			fileFullName = fileName + ".log";
			break;
		default:
			// default: .txt
			fileFullName = fileName + ".txt";
			break;
		}
	}

private:
	PathType pathType = REL;

	std::string fileName = "logs";
	FileFormat fileFormat = FileFormat::TXT;

	std::string fileFullName = "logs.txt";
	std::string fullPath = REL_STAY;

public:
	//For Testing
	bool isInfoValid(bool TEST) {
		return (isNameValid(fileName) && isPathValid());
	}
};

// Logger
class Logger {
public:
	static void logToFile(LogFile& file) {};
	static void logToFile(const std::string& file_path) {};
};

#endif // LOGGER_MODULE_HPP
