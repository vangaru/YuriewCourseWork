#include "menu.h"

int main() {
	setlocale(0, "");
	int amount = 0;
	Cities* objects = new Cities[amount];
	menu(objects, amount);
	delete[] objects;
}



