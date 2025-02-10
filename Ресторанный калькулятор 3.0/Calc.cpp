// Ресторанный калькулятор 3.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>


struct drinks {
	char name[20];
	double price;
};

struct guest {
	std::string name;
	double sum;
	short order[8];
};

void print_line() {
	for (int i = 0; i < 51; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
}

void print_2line() {
	for (int i = 0; i < 51; i++) {
		std::cout << "=";
	}
	std::cout << std::endl;
}

void menu(drinks* arr, short size) {
	print_2line();
	std::cout << std::endl << "\t\tMenu:" << std::endl;
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			std::cout << i + 1 << " - " << arr[i].name << "\t" << arr[i].price << "\t";
		}
		else {
			std::cout << i + 1 << " - " << arr[i].name << "\t" << arr[i].price << "\t" << std::endl;
		}
	}
	std::cout << size + 1 << " - Exit." << std::endl;
	print_line();
}

void choice_menu_g(long cntr_guest) { // меню выбора гостя
	print_line();
	std::cout << "\nChoice number of guest 1 - " << cntr_guest << " | \tExit - "
		<< cntr_guest + 1 << std::endl;
	print_line();
	std::cout << "Your choice: ";
}

void choice_menu_main() { // главное меню
	print_2line();
	std::cout << "1 - add drinks    \t|\t2 - delete drinks" << std::endl
		<< "3 - view the order\t|\t4 - discount" << std::endl << "5 - cancel discount\t|\t6 - exit" << std::endl;
	print_line();
	std::cout << "Your choice: ";
}

void add_drinks1(drinks* arr, short size, guest* arr1) {
	short op1 = 1;
	std::cout << "Your choice: ";
	std::cin >> op1;
	if (op1 == size + 1) {
		print_line();
		return;
	}
	if (op1 > size + 1 || op1 < 1) {
		std::cout << "Mistake. Try again." << std::endl;
		add_drinks1(arr, size, arr1);
	}
	else {
		arr1[0].sum += arr[op1 - 1].price;
		arr1[0].order[op1 - 1] += 1;
		add_drinks1(arr, size, arr1);
	}
}

void add_drinks(drinks* arr, short size, guest* arr1, short op) { // добавление напитков
	short op1 = 1;
	std::cout << "Your choice: ";
	std::cin >> op1;
	if (op1 == size + 1) {
		print_line();
		return;
	}
	if (op1 > size + 1 || op1 < 1) {
		std::cout << "Mistake. Try again." << std::endl;
		add_drinks(arr, size, arr1, op);
	}
	else {
		arr1[op - 1].sum += arr[op1 - 1].price;
		arr1[op - 1].order[op1 - 1] += 1;
		add_drinks(arr, size, arr1, op);
	}
}

void delete_drinks(drinks* arr, short size, guest* arr1, short op) { // удаление напитков
	short op1;
	std::cout << "Your choice: ";
	std::cin >> op1;
	if (op1 == size + 1) {
		print_line();
		return;
	}
	if (op1 > size + 1 || op1 < 1) {
		std::cout << "Mistake. Try again." << std::endl;
		delete_drinks(arr, size, arr1, op);
	}
	else {
		if (arr1[op - 1].order[op1 - 1] == 0) {
			std::cout << "mistake" << std::endl;
			delete_drinks(arr, size, arr1, op);
		}
		else {
			arr1[op - 1].sum -= arr[op1 - 1].price;
			arr1[op - 1].order[op1 - 1] -= 1;
			delete_drinks(arr, size, arr1, op);
		}
	}
}

void delete_drinks1(drinks* arr, short size, guest* arr1) {
	short op1;
	std::cout << "Your choice: ";
	std::cin >> op1;
	if (op1 == size + 1) {
		print_line();
		return;
	}
	if (op1 > size + 1 || op1 < 1) {
		std::cout << "Mistake. Try again." << std::endl;
		delete_drinks1(arr, size, arr1);
	}
	else {
		if (arr1[0].order[op1 - 1] == 0) {
			std::cout << "mistake" << std::endl;
			delete_drinks1(arr, size, arr1);
		}
		else {
			arr1[0].sum -= arr[op1 - 1].price;
			arr1[0].order[op1 - 1] -= 1;
			delete_drinks1(arr, size, arr1);
		}
	}
}

void discount(guest* arr1, guest* arr_new, short size) { // скидка
	for (int i = 0; i < size; i++) {
		arr_new[i].name = arr1[i].name;
		arr_new[i].sum = arr1[i].sum;
		for (int j = 0; j < 8; j++) {
			arr_new[i].order[j] = arr1[i].order[j];
		}
	}
	short disc;
	std::cout << "Enter the discount percentage- ";
	std::cin >> disc;
	for (int i = 0; i < size; i++) {
		if (arr1[i].sum != 0) {
			arr1[i].sum = arr1[i].sum - arr1[i].sum / 100 * disc;
		}
	}
}

void discount1(guest* arr1, guest* arr_new) {
	arr_new[0].name = arr1[0].name;
	arr_new[0].sum = arr1[0].sum;
	for (int j = 0; j < 8; j++) {
		arr_new[0].order[j] = arr1[0].order[j];
	}
	short disc;
	std::cout << "Enter the discount percentage- ";
	std::cin >> disc;
	if (arr1[0].sum != 0) {
		arr1[0].sum = arr1[0].sum - arr1[0].sum / 100 * disc;
	}
}

void canc_discount(guest* arr1, guest* arr_new, short size) { // отмена скидки
	for (int i = 0; i < size; i++) {
		arr1[i] = arr_new[i];
		arr_new[i].sum = 0;
		for (int j = 0; j < 8; j++) {
			arr_new[i].order[j] = 0;
		}
	}
}

void canc_discount1(guest* arr1, guest* arr_new) {
	arr1[0] = arr_new[0];
	arr_new[0].sum = 0;
	for (int j = 0; j < 8; j++) {
		arr_new[0].order[j] = 0;
	}
}

void print_order(guest* arr, drinks* arr1, short size) {
	short op1 = 1;
	std::cout << "Enter number of guest - ";
	std::cin >> op1;
	if (op1 > size || op1 < 1) {
		std::cout << "Mistake." << std::endl;
		return ;
	}
	std::cout << "Amount = " << arr[op1 - 1].sum << std::endl;
	for (int i = 0; i < 8; i++) {
		if (arr[op1 - 1].order[i] != 0) {
			std::cout << arr1[i].name << " - " << arr[op1 - 1].order[i] << std::endl;
		}
	}
}

void print_order1(guest* arr, drinks* arr1, short size) {
	std::cout << "\t\t" << arr[0].name << std::endl;
	std::cout << "Amount = " << arr[0].sum << std::endl;
	for (int i = 0; i < 8; i++) {
		if (arr[0].order[i] != 0) {
			std::cout << arr1[i].name << " - " << arr[0].order[i] << std::endl;
		}
	}
}

int main()
{
	const short size_dr = 8;
	drinks array[size_dr];
	array[0] = { "Assam", 350.0 };
	array[1] = { "Assam with thyme", 370.0 };
	array[2] = { "Americano", 200.0 };
	array[3] = { "Xenessy VSOP", 560.0 };
	array[4] = { "Jamesson", 480.0 };
	array[5] = { "Amaretto    ", 370.0 };
	array[6] = { "Moxito", 400.0 };
	array[7] = { "Moxito b/a   ", 350.0 };
	std::cout << "Enter the number of guests - ";
	short cntr_guest;
	std::cin >> cntr_guest;
	guest* guests = new guest[cntr_guest];
	guest* disc = new guest[cntr_guest]; // временное хранилище
	// обнуление хранилища)
	for (int i = 0; i < cntr_guest; i++) {
		guests[i].sum = 0;
		disc[i].sum = 0;
		for (int j = 0; j < 8; j++) {
			guests[i].order[j] = 0;
			disc[i].order[j] = 0;
		}
	}
	for (int i = 0; i < cntr_guest; i++) {
		std::cout << "Enter name of guest " << i + 1 << " - ";
		std::cin >> guests[i].name;
	}
	if (cntr_guest == 1) {
		short operation1 = 1;
		while (operation1 != 6) {
			choice_menu_main();
			std::cin >> operation1;
			switch (operation1)
			{
			case 1:
				menu(array, size_dr);
				add_drinks1(array, size_dr, guests);
				break;
			case 2:
				menu(array, size_dr);
				delete_drinks1(array, size_dr, guests);
				break;
			case 3:
				print_order1(guests, array, cntr_guest);
				break;
			case 4:
				discount1(guests, disc);
				break;
			case 5:
				canc_discount1(guests, disc);
				break;
			}
		}
	}
	else {
		short operation1 = 1, operation2, operation3;
		while (operation1 != 6) {
			choice_menu_main();
			std::cin >> operation1;
			switch (operation1)
			{
			case 1:
				choice_menu_g(cntr_guest);
				std::cin >> operation2;
				if (operation2 == cntr_guest + 1) {
					break;
				}
				if (operation2 > cntr_guest + 1 || operation2 < 1) {
					while (operation2 > cntr_guest || operation2 < 1) {
						std::cout << "Mistake!!!\nYour choice: ";
						std::cin >> operation2;
					}
				}
				menu(array, size_dr);
				add_drinks(array, size_dr, guests, operation2);
				break;
			case 2:
				choice_menu_g(cntr_guest);
				std::cin >> operation3;
				if (operation3 == cntr_guest + 1) {
					break;
				}
				if (operation3 > cntr_guest + 1 || operation3 < 1) {
					while (operation3 > cntr_guest || operation3 < 1) {
						std::cout << "Mistake!!!\nYour choice: ";
						std::cin >> operation3;
					}
				}
				menu(array, size_dr);
				delete_drinks(array, size_dr, guests, operation3);
				break;
			case 3:
				print_order(guests, array, cntr_guest);
				break;
			case 4:
				discount(guests, disc, cntr_guest);
				break;
			case 5:
				canc_discount(guests, disc, cntr_guest);
				break;
			}
		}
	}
	for (int i = 0; i < cntr_guest; i++) {
		if (guests[i].sum != 0) {
			std::cout << guests[i].name << std::endl;
			std::cout << "Amount = " << guests[i].sum << std::endl;
			for (int j = 0; j < 8; j++) {
				if (guests[i].order[j] != 0) {
					std::cout << array[j].name << " - " << guests[i].order[j] << std::endl;
				}
			}
			print_line();
		}
	}
	delete[] guests;
	delete[] disc;
}
	