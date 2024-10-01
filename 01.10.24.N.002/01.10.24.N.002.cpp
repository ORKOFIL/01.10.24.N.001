//13:44//
//12:56//
#include <iostream>

using namespace std;

int main() {
	char mystr[] = "Hello, world!";
	int i = 0;
	do
	{
		cout << mystr[i];
		i++;
	} while (mystr[i] != 0);

}
