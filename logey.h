#include <iostream>
#include <Windows.h>
#include <stdio.h>

using namespace std;

/*
*	Global debug variable
*	If true, the console will be shown and show live output.
*/
bool debug = false;


void keys(int key, const char *filename);
void hideConsole();
char findLetter(int key);