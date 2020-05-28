#include "menu.h"

void menu(Cities* objects, int amount) {
	char fileName[15];
	cout << endl << "Введите имя файла >>> ";
	cin.getline(fileName, 15);
	strcat_s(fileName, ".txt");
	int choice = 0;
	while (choice != 6) {
		cout << endl << "МЕНЮ ВЗАИМОДЕЙСТВИЯ" << endl;
		cout << "\n1)Ввод данных\n2)Добавление структуры в массив структур\n3)Вывод данных на экран\n4)Корректировка структуры\n5)Удаление структуры\n6)Выход\nВыберите действие >>> ";
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