#include "file.h"
#include "interface.h"

void input(Cities*& objects, int& amount, char* fileName) {
	amount = 0;
	int N;
	int continent;
	cout << "Введите количество городов >>> ";
	cin >> N;
	cin.ignore();
	amount += N;
	Cities* temp = new Cities[amount];
	for (int i = 0; i < amount - N; i++)
		temp[i] = objects[i];
	objects = new Cities[amount];
	for (int i = 0; i < amount - N; i++)
		objects[i] = temp[i];
	delete[] temp;
	for (int i = 0; i < amount; i++) {
		cout << endl << "Введите название города >>> ";
		cin.getline(objects[i].nameOfCity, 20);
		cout << "Введите количесвто жителей в городе >>> ";
		cin >> objects[i].amountOfCitizens;
		cin.ignore();
		cout << "Введите название главной достопримечательности >>> ";
		cin.getline(objects[i].mainSight, 20);
		cout << "Введите континент города(1 - Европа, 2 - Азия, 3 - Африка, 4 - Австралия, 5 - Южная Америка, 6 - Северная Америка) >>> ";
		cin >> continent;
		switch (continent) {
		case(objects[i].Continent_Europe):
			strcpy_s(objects[i].continent, "Европа");
			break;
		case(objects[i].Continent_Asia):
			strcpy_s(objects[i].continent, "Азия");
			break;
		case(objects[i].Continent_Australia):
			strcpy_s(objects[i].continent, "Австралия");
			break;
		case(objects[i].Continent_Africa):
			strcpy_s(objects[i].continent, "Африка");
			break;
		case(objects[i].Continent_NorthAmerica):
			strcpy_s(objects[i].continent, "Северная Америка");
			break;
		case(objects[i].Continent_SouthAmerica):
			strcpy_s(objects[i].continent, "Южная Америка");
		default:
			cout << "Неверный ввод!" << endl;
			strcpy_s(objects[i].continent, "Не указано");
			break;
		}
		cout << "Данный город имеет выход к морю?(1 - да, 2- нет) >>> ";
		cin >> objects[i].access.hasAccess;
		if (objects[i].access.hasAccess == 1)
			objects[i].access.flag = '+';
		else if (objects[i].access.hasAccess == 2)
			objects[i].access.flag = '-';
		else {
			cout << "Неверный ввод!";
			objects[i].access.flag = '?';
			cout << endl;
		}
		cin.ignore();
	}
	txtOutput(objects, amount, fileName);
}

void add(Cities*& objects, int& amount, char* fileName) {
	ofstream out(fileName, ios_base::app);
	int amountOfCities;
	cout << "Сколько городов добавить? >>> ";
	cin >> amountOfCities;
	Cities* citiesToAdd = new Cities[amountOfCities];
	for (int i = 0; i < amountOfCities; i++) {
		cout << endl << "Введите название города >>> ";
		cin.ignore();
		cin.getline(citiesToAdd[i].nameOfCity, 20);
		cout << "Введите количесво жителей в городе >>> ";
		cin >> citiesToAdd[i].amountOfCitizens;
		cin.ignore();
		cout << "Введите название главной достопримечательности >>> ";
		cin.getline(citiesToAdd[i].mainSight, 20);
		cout << "Введите континент города(1 - Европа, 2 - Азия, 3 - Африка, 4 - Австралия, 5 - Южная Америка, 6 - Северная Америка) >>> ";
		int continent;
		cin >> continent;
		switch (continent) {
		case(citiesToAdd[i].Continent_Europe):
			strcpy_s(citiesToAdd[i].continent, "Европа");
			break;
		case(citiesToAdd[i].Continent_Asia):
			strcpy_s(citiesToAdd[i].continent, "Азия");
			break;
		case(citiesToAdd[i].Continent_Australia):
			strcpy_s(citiesToAdd[i].continent, "Австралия");
			break;
		case(citiesToAdd[i].Continent_Africa):
			strcpy_s(citiesToAdd[i].continent, "Африка");
			break;
		case(citiesToAdd[i].Continent_NorthAmerica):
			strcpy_s(citiesToAdd[i].continent, "Северная Америка");
			break;
		case(citiesToAdd[i].Continent_SouthAmerica):
			strcpy_s(citiesToAdd[i].continent, "Южная Америка");
		default:
			cout << "Неверный ввод!" << endl;
			strcpy_s(citiesToAdd[i].continent, "Не указано");
			break;
		}
		cout << "Данный город имеет выход к мрю?(1 - да, 2- нет) >>> ";
		cin >> citiesToAdd[i].access.hasAccess;
		if (citiesToAdd[i].access.hasAccess == 1)
			citiesToAdd[i].access.flag = '+';
		else if (citiesToAdd[i].access.hasAccess == 2)
			citiesToAdd[i].access.flag = '-';
		else {
			cout << "Неверный ввод!";
			citiesToAdd[i].access.flag = '?';
			cout << endl;
		}
		out << setw(5) << left << amount + 1;
		out << setw(15) << left << citiesToAdd[i].nameOfCity;
		out << setw(20) << left << citiesToAdd[i].amountOfCitizens;
		out << setw(20) << left << citiesToAdd[i].mainSight;
		out << setw(17) << left << citiesToAdd[i].continent;
		out << setw(14) << left << citiesToAdd[i].access.flag << endl;
		amount++;
	}
	out.close();
	txtInput(objects, amount, fileName);
}

void output(Cities* objects, int amount) {
	cout << setw(5) << left << "#" << setw(20) << left << "Название города" << setw(20) << left << "Количество жителей" << setw(35) << left << "Главная достопримечательность" << setw(17) << left << "Континент" << setw(14) << "Выход к морю" << endl;
	for (int i = 0; i < amount; i++) {
		cout << setw(5) << left << i + 1;
		cout << setw(20) << left << objects[i].nameOfCity;
		cout << setw(20) << left << objects[i].amountOfCitizens;
		cout << setw(35) << left << objects[i].mainSight;
		cout << setw(17) << left << objects[i].continent;
		cout << setw(14) << left << objects[i].access.flag;
		cout << endl;
	}
}

void del(Cities* objects, int& amount, char* fileName) {
	char city_to_del[20];
	cout << endl << "С каким городом структуру вы хотите удалить? >>> ";
	cin.ignore();
	cin.getline(city_to_del, 20);
	for (int i = 0; i < amount; i++) {
		if (strcmp(objects[i].nameOfCity, city_to_del) == 0) {
			amount--;
			for (int k = i; k < amount; k++)
				objects[k] = objects[k + 1];
			i--;
		}
	}
	txtOutput(objects, amount, fileName);
}

void fieldCorrection(Cities*& objects, int amount, char* fileName) {
	cout << "Введите название города, который надо откорректировать >>> ";
	char cityToCorrect[20];
	cin.ignore();
	cin.getline(cityToCorrect, 20);
	for (int i = 0; i < amount; i++) {
		if (strcmp(cityToCorrect, objects[i].nameOfCity) == 0) {
			int choice = 0;
			while (choice != 6) {
				cout << endl << "Выберите действие:\n1)Откорректировать название\n2)Откорректировать количество жителей города\n3)Откорректировать главную достопримечательность\n4)Откорректировать континент города\n5)Откорректровать выход к морю\n6)Выход\nВыберите действие >>> ";
				cin >> choice;
				if (choice == 1) {
					cout << "Введите новое название города >>> ";
					char newNameOfCity[20];
					cin.ignore();
					cin.getline(newNameOfCity, 20);
					strcpy_s(objects[i].nameOfCity, newNameOfCity);
				}
				else if (choice == 2) {
					cout << "Введите новое количество жителей в городе >>> ";
					int newAmountOfCitizens;
					cin >> newAmountOfCitizens;
					objects[i].amountOfCitizens = newAmountOfCitizens;
				}
				else if (choice == 3) {
					cout << "Введите новую главуню достопримечательность >>> ";
					char newMainSight[20];
					cin.ignore();
					cin.getline(newMainSight, 20);
					strcpy_s(objects[i].mainSight, newMainSight);
				}
				else if (choice == 4) {
					cout << "Введите новый континент города(1 - Европа, 2 - Азия, 3 - Африка, 4 - Австралия, 5 - Южная Америка, 6 - Северная Америка) >>> ";
					int newContinent;
					cin >> newContinent;
					switch (newContinent) {
					case(objects[i].Continent_Europe):
						strcpy_s(objects[i].continent, "Европа");
						break;
					case(objects[i].Continent_Asia):
						strcpy_s(objects[i].continent, "Азия");
						break;
					case(objects[i].Continent_Australia):
						strcpy_s(objects[i].continent, "Австралия");
						break;
					case(objects[i].Continent_Africa):
						strcpy_s(objects[i].continent, "Африка");
						break;
					case(objects[i].Continent_NorthAmerica):
						strcpy_s(objects[i].continent, "Северная Америка");
						break;
					case(objects[i].Continent_SouthAmerica):
						strcpy_s(objects[i].continent, "Южная Америка");
					default:
						cout << "Неверный ввод!" << endl;
						strcpy_s(objects[i].continent, "Не указано");
						break;
					}
				}
				else if (choice == 5) {
					cout << "Город имеет выход к морю??(1 - Да, 2 - Нет) >>> ";
					int accessChoice;
					cin >> accessChoice;
					objects[i].access.hasAccess = accessChoice;
					if (objects[i].access.hasAccess == 1)
						objects[i].access.flag = '+';
					else if (objects[i].access.hasAccess == 2)
						objects[i].access.flag = '-';
					else {
						cout << "Неверный ввод!";
						objects[i].access.flag = '?';
						cout << endl;
					}
				}
				else if(choice < 1 || choice > 6) cout << endl << "Неверный ввод!" << endl;
			}
			txtOutput(objects, amount, fileName);
			return;
		}
	}
	cout << endl << "Структуры с таким шифром не существует!" << endl;
}

