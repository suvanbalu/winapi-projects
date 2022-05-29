## Windows API keylogger

#### Description -
Using C++ winapi to record keystrokes from keyboard entered by the users.

#### Headers -
```cpp
#include <Windows.h>  //winapi 
#include <iostream>
#include <string>      
#include <fstream>    //filestream
#include <stdio.h>
#include <ctime>    
```

#### Methods and Terminology
```
write_log() => Gets string input and writes it to the logfile
key_list() => Checks for a given key, if present written in log or false is returned
GetAsyncKeyState() => Checks whether a key is down

VK -> Virtual Key
ASCII value range -> 1 - 128
Printable character range -> 32-128
