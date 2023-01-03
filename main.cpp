#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

int randomaizer(int z) {
	srand(time(NULL));
	int k = rand() % z;
	while (k % 2 != 0) {
		k = rand() % z;
	}
	return k;
}

int main(int argc, char *argv[]) {
	std::ifstream fin("file.txt");
	std::ifstream pin("pleasurs.txt");
	std::vector<std::string> str, pleasurs;
	std::string s;
	int n = 0;
	char enter, mode, ans;
	while (!fin.eof()) {
		getline(fin, s);
		str.push_back(s);
		n++;
	}
	while (!pin.eof()) {
		getline(pin, s);
		pleasurs.push_back(s);
	}
	fin.close();
	
	std::cout << "Введите способ выбора вопросов (l - вопросы подряд до первой ошибки, r - случайный вопрос): ";
	std::cin >> mode;
	
	int i;
	switch (mode) {
		case 'r':
			bool answersComplited[254];
			for (int i = 0; i < 254; i++) answersComplited[i] = false;
			while (true) {
				i = randomaizer(n);
				std::cin.get();
				std::cout << str[i];
				std::cin.get();
				i++;
				std::cout << str[i] << '\n';
				std::cout << "Вы правильно ответили на вопрос? [y/n]: ";
				std::cin >> ans;
				
				if (ans == 'y') {
					std::cout << pleasurs[randomaizer(20)] << '\n' << '\n';
					answersComplited[i-1] = true;
					answersComplited[i] = true;
					for (int i = 0; i < 254; i++) {
						if (answersComplited[i] == false) break;
						else {
							std::cout << "Молодец, ты ответила на все вопросы! Я тебя недостоин(((" << '\n';
							return 0;
						}
					}
				}
				else std::cout << pleasurs[randomaizer(20) + 1] << '\n' << '\n';
				
			}
		case 'l':
			i = 0;
			int numOfQuestion = 1;
			while (i < n) {
				std::cout << numOfQuestion << ". " << str[i];
				enter = getchar();
				std::cin.get();
				i++;
				std::cout << str[i] << '\n';
				i++;
				numOfQuestion++;
				std::cout << "Вы правильно ответили на вопрос? [y/n]: ";
				std::cin >> ans;
				if (ans == 'n') {
					i = 0;
					numOfQuestion = 1;
					std::cout << pleasurs[randomaizer(20) + 1] << '\n' << '\n';
				}
				else {
					std::cout << pleasurs[randomaizer(20)] << '\n' << '\n';
					if (i == 254)
						std::cout << "Молодец, ты ответила на все вопросы! Я тебя недостоин(((" << '\n';
				}
			}
	}
	
	return 0;
}