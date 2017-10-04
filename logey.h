#include <iostream>
#include <Windows.h>

using namespace std;

/*
*	Global debug variable
*	If true, the console will be shown and show live output.
*/
bool debug = false;


void keys(int key, char *filename);
void hideConsole();