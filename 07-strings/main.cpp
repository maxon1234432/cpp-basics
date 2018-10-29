#include <iostream>
#include <string> // ���������� ������
#include <fstream> // ���������� �����
#include <regex> // ���������� �����

using namespace std; // ���������� ����������� ������������ ����

int main()
{
	string buffer = ""; // ���� ����� ������ ��������� ������
	string str = ""; // ���� ����� ������ ��������� �����
	ifstream file("C:\\data.txt"); // ���� �� �������� ������ (��� ������ ���� ����� ��������� �� �������)
	std::regex reg("([A-Za-z]+)"); // ����� ��� �����
	std::regex rx("([A-Z][a-z]*)"); // ����� ��� ����� � ������� �����
	std::cmatch res;
	while (getline(file, buffer)) { // ���� �� ��������� ����� ����� ������ ��������� ������ � ����������
		while (true) {
			std::regex_search(buffer.c_str(), res, reg); // ���� �����
			if (res.size() != 0) { // ���� ����� �������
				str = res[1]; // �������� ��� � ����������
				buffer = res.suffix(); // ��������� ����� ���������� � �����
				std::regex_match(str.c_str(), res, rx); // �������� �� ������� ������� �����
				if (res.size() != 0) { // ���� ������ ������������� �����
					std::cout << res[1] << "\n"; // ������� �� �����
				}
			}
			else // ���� ����� �� �������
				break; // ����������� ������ � ������� (������� �� �����)
		}
	}
	system("PAUSE");
	file.close(); // ����������� ��������� ���� ��� �� �� ��������� ���
}
