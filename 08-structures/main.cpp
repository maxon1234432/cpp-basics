#include <iostream>
#include <string> // ���������� ������

using namespace std; // ���������� ����������� ������������ ����

struct MARSH // ���������
{
	string nachPunkt, konechPunkt; // �������� ���������� ������ � ������ �����
	int number; // ����� ��������
};

int main()
{
	MARSH listMarsh[8]; // ������ ���������
	for (int i = 0; i < 8; i++) { // ����� ���������� ��������
		cout << "vvedite nachPunkt dla stancii #" << i + 1 << "\n";
		cin >> listMarsh[i].nachPunkt;
		cout << "vvedite konechPunkt dla stancii #" << i + 1 << "\n";
		cin >> listMarsh[i].konechPunkt;
		cout << "vvedite number dla stancii #" << i + 1 << "\n";
		cin >> listMarsh[i].number;
	}
	for (int i = 0; i < 8; i++) { // ���������� ��������� �� ������
		for (int j = 1; j < 8 - i; j++) {
			if (listMarsh[j - 1].number > listMarsh[j].number) {
				MARSH marshCup;
				marshCup = listMarsh[j - 1];
				listMarsh[j - 1] = listMarsh[j];
				listMarsh[j] = marshCup;
			}
		}
	}
	for (int i = 0; i < 8; i++) { // ����� ��������� �� �����
		cout << i + 1 << ")nachPunkt = " << listMarsh[i].nachPunkt;
		cout << " ; konechPunkt = " << listMarsh[i].konechPunkt;
		cout << " ; number = " << listMarsh[i].number << "\n";
	}
	cout << "Vvedite nomer marshruta" << "\n";
	int number; // �������� �����
	cin >> number;
	bool naiden = false; // ���������� ���������� �� ���������� ��������
	for (int i = 0; i < 8; i++) {
		if (number == listMarsh[i].number) {
			naiden = true; // �������� ������ ���� ������� ������ � ������ ��� �� �����
			cout << i + 1 << ")nachPunkt = " << listMarsh[i].nachPunkt;
			cout << " ; konechPunkt = " << listMarsh[i].konechPunkt;
			cout << " ; number = " << listMarsh[i].number << "\n";
		}
	}
	if (!naiden) // ���� ������� �� ������ ��������� ���������
		cout << "Marshrut ne naiden \n";
}
