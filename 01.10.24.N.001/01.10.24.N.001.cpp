//13:30//

#include <iostream>
#include <string>

using namespace std;

static void change(int& f, int& s) {
	int c = f;
	f = s;
	s = c;
}

int main() {
	int f = 2;
	int s = 4;

	cout << "f=" << f;
	cout << "s=" << s << endl;

	change(f, s);

	cout << "f=" << f;
	cout << "s=" << s;

}

