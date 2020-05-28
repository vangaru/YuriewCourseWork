#include "menu.h"

void menu(Cities* objects, int amount) {
	char fileName[15];
	cout << endl << "������� ��� ����� >>> ";
	cin.getline(fileName, 15);
	strcat_s(fileName, ".txt");
	int choice = 0;
	while (choice != 6) {
		cout << endl << "���� ��������������" << endl;
		cout << "\n1)���� ������\n2)���������� ��������� � ������ ��������\n3)����� ������ �� �����\n4)������������� ���������\n5)�������� ���������\n6)�����\n�������� �������� >>> ";
		cin >> choice;
		switch (choice) {
		case(1):
			txtInput(objects, amount, fileName);
			break;
		case(2):
			add(objects, amount, fileName);
			break;
		case(3):
			cout << endl;
			output(objects, amount);
			break;
		case(4):
			fieldCorrection(objects, amount, fileName);
			break;
		case(5):
			del(objects, amount, fileName);
			break;
		}
	}
}