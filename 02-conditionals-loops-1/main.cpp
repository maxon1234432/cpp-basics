#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;
int main()
{
	int a, b, c;
	float f = 0, shag, Xnach, Xkon, x;
	cout << "1abaSuvorov\n";
	cout << "10var\n";
	cout << "vvediteznach a=\n";
	cin >> a;
	cout << "vvediteznach b=\n";
	cin >> b;
	cout << "vvediteznach c=\n";
	cin >> c;
	cout << "vvediteznach Xnach=\n";
	cin >> Xnach;
	cout << "vvediteznach Xkon=\n";
	cin >> Xkon;
	cout << "vvediteznach shag=\n";
	cin >> shag;

	cout << "\n";

	int i;
	if ((Xnach < 3) && (b != 0))
		//cout << " i=\n  " << i << "  " << "znach";
		for (i = Xnach; i <= Xkon; i += shag)
		{

			f = float(a * (i*i) - (b*i) + c); cout << "\n  " << i << "  " << f;
			cout << " ";

		}

	if ((Xnach > 3) && (b == 0))
		for (i = Xnach; i <= Xkon; i += shag)
		{
			f = float((i - a) / (i - c)); cout << "\n  " << i << "  " << f;
		}
	else
		for (i = Xnach; i <= Xkon; i += shag) { f = i / c; cout << "\n  " << i << "  " << f; }
	cout << "\n ";


	system("PAUSE");
}

