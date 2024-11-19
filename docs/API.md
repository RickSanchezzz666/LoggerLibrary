# GlobalStructures
- Global:
    - END_LINE - "\n"
    - enum PathType { **ABS, REL, INVALID** }; // ABS - absolute path, 
    - enum FileFormat { **TXT, CSV, LOG** };

- Windows:
    - PATH_SEP - '\\'
    - REL_STAY - ".\\"
    - REL_LEAVE - "..\\"
- UNIX:
    - PATH_SEP - '/'
    - REL_STAY - "./"
    - REL_LEAVE - "../"

# LogFile
- ## Constructors
    - **```LogFile(const std::string& file_name, FileFormat file_format, const std::string& folder_path = REL_STAY, const std::string& header = "")```**

    #### Usage
        Creation of the LogFile class instance
    #### Parameters
        - const std::string& file_name - name for your file: 
            - Example: "filename"
        - FileFormat file_format - format of your log file: .txt, .csv, .log.
	        - Example: FileFormat::LOG
        - const std::string& folder_path (default: REL_STAY) - absolute or relative path to folder where to store logs.
	        - Example: "../folder" Win - "..\\"
        - const std::string& header (default: "") - your header in the log file.
	        - Example: "name,date" or "name;time;count"

    - **```LogFile(const char* file_name, FileFormat file_format, const char* folder_path = REL_STAY, const char* header = "")```**

    #### Usage
        Creation of the LogFile class instance
    #### Parameters
        - const char* file_name - name for your file: 
            - Example: "filename"
        - FileFormat file_format - format of your log file: .txt, .csv, .log.
	        - Example: FileFormat::LOG
        - const char* folder_path (default: REL_STAY) - absolute or relative path to folder where to store logs.
	        - Example: "../folder" Win - "..\\"
        - const char* header (default: "") - your header in the log file.
	        - Example: "name,date" or "name;time;count"
- ## Methods
    ### isInfoValid
    - #### Usage:
        Check if info that was provided in the constructor of the LogFile is valid to be used as a Logging File
    - #### Parameters
        Output type: bool
    - #### Output
        True - if the file is valid \
        False - is not valid
        
    ### getFileName
    - #### Usage:
        Get name of the logging file
    - #### Parameters
        Output type: *const* std::string
    - #### Output
        "fileName": str

    ### getFileFormat
    - #### Usage:
        Get file format of the logging file
    - #### Parameters
        Output type: *const* [FileFormat](#GlobalStructures)
    - #### Output
        "FileFormat::TXT": FileFormat

    ### getFullFileName
    - #### Usage:
        Get full file name with the format extension of the logging file
    - #### Parameters
        Output type: *const* std::string
    - #### Output
        "fileName.txt": str
    
    ### getFullPath
    - #### Usage:
        Get full path to the logging file
    - #### Parameters
        Output type: *const* std::string
    - #### Output
        "D:\\Folder\\fileName.txt": str

    ### setFileName
    - #### Usage:
        Set new file name for the logging file
    - #### Parameters
        - *const std::string&* newFileName

    ### setFileFormat
    - #### Usage:
        Set new file format for the logging file
    - #### Parameters
        - *const [FileFormat](#GlobalStructures)&* newFileFormat

- ## Methods usage Examples
    ### isInfoValid
        isInfoValid(); -> bool
    ### getFileName
        getFileName(); -> string
    ### getFileFormat
        getFileFormat(); -> FileFormat
    ### getFullFileName
        getFullFileName(); -> string
    ### getFullPath
        getFullPath(); -> string
    ### setFileName
        setFileName("newFileName");
    ### setFileFormat
        setFileFormat(FileFormat::CSV);

# Logger
- ## Methods
    ### logToFile - static
    - #### Usage:
        Function is used to log messages in to log file
    - #### Parameters
        - const std::string& file_path - absolute or relative path to your file including it's name and extension
        - const std::string& log_message - message to log
        - bool add_timestamp (default: true) - adding timestamp in format "%H:%M:%S" to the beginning of the log message True to keep on/False to turn off \
        Output type: bool
    - #### Output
        True - if the logging is successful \
        False - if the logging is unsuccessful 

    ### logToFile - static
    - #### Usage:
        Function is used to log messages in to log file
    - #### Parameters
        - LogFile& file - LogFile instance of your logging file
        - const std::string& log_message - message to log
        - bool add_timestamp (default: true) - adding timestamp in format "%H:%M:%S" to the beginning of the log message True to keep on/False to turn off \
        Output type: bool
    - #### Output
        True - if the logging is successful \
        False - if the logging is unsuccessful 