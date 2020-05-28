#include "file.h"
#include "interface.h"

void txtOutput(Cities* objects, int amount, char* fileName) {
	ofstream out(fileName);
	out << setw(5) << left << "#" << setw(20) << left << "Название города" << setw(20) << left << "Количество жителей" << setw(35) << left << "Главная достопримечательность" << setw(17) << left << "Континент" << setw(14) << "Выход к морю" << endl;
	for (int i = 0; i < amount; i++) {
		out << setw(5) << left << i + 1;
		out << setw(20) << left << objects[i].nameOfCity;
		out << setw(20) << left << objects[i].amountOfCitizens;
		out << setw(35) << left << objects[i].mainSight;
		out << setw(17) << left << objects[i].continent;
		out << setw(14) << left << objects[i].access.flag << endl;
	}
	out.close();
}

void txtInput(Cities*& objects, int& amount, char* fileName) {
	amount = 0;
	ifstream in(fileName);
	if (in.peek() == EOF) {
		cout << endl << "Текстовый файл пуст!" << endl << endl;
		input(objects, amount, fileName);
	}
	else {
		cout << endl << "Текстовый файл существует - данные будут считаны" << endl;
		int count;
		char temp[256];
		in.getline(temp, 256);
		for (int i = 0; !in.eof(); i++) {
			amount++;
			Cities* tmp = new Cities[amount - 1];
			for (int k = 0; k < amount - 1; k++)
				tmp[k] = objects[k];
			objects = new Cities[amount];
			for (int k = 0; k < amount - 1; k++)
				objects[k] = tmp[k];
			delete[] tmp;
			in >> count >> objects[i].nameOfCity >> objects[i].amountOfCitizens >> objects[i].mainSight >> objects[i].continent >> objects[i].access.flag;
		}
		amount -= 1;
		in.close();
	}
}