#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	float a, b, c;
	float f = 0, shag, Xnach, Xkon, x;
	cout << "labaSuvorov\n";
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
	//if ((Xnach < 3) && (b != 0))
		//cout << " i=\n  " << i << "  " << "znach";
		for (i = Xnach; i <= Xkon; i += shag)
		{
			if((i<3)&&(b !=0)) { f = float(a * (i*i) - (b*i) + c); cout << "\n  " << i << "  1usl f=" << f;
					cout << " ";
			}
			else 
			{
				if ((i > 3) && (b == 0)) { f = float((i - a) / (i - c)); cout << "\n  " << i << " 2usl f=" << f; }
				else
				{
					f = i / c; cout << "\n  " << i << "else  f=" << f;
				}
			}
		}


	system("PAUSE");
}

