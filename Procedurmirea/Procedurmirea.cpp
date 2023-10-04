#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
void bk() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int randomcheck[10]{ 0 };
	int chislo, check, check1, checkchislo;
	int start = 0, end = 9, r = 4, plus = 0;
	int chislocomp = 0, minus = 0;
	for (int i = 0; i < r; i++) {
		int random = rand() % (end - start + 1) + start;
		if (i == 0 && random == 0) i--;
		else {
			if (randomcheck[random] == 0) {
				chislocomp += random * pow(10, r - 1 - i);
				randomcheck[random]++;
			}
			else i--;
		}
	}
	cout << chislocomp << endl;
	while (true) {
		checkchislo = chislocomp;
		plus = 0;
		minus = 0;
		int minuscheck[10]{ 0 };
		cout << "Введите 4 - x значное число : ";
		cin >> chislo;
		while (chislo > 0) {
			check = chislo % 10;
			check1 = checkchislo % 10; \
				minuscheck[check]++;
			chislo /= 10;
			checkchislo /= 10;
			if (check1 == check) {
				plus++;
			}
			r--;
		}
		checkchislo = chislocomp;
		while (checkchislo > 0) {
			check1 = checkchislo % 10;
			if (minuscheck[check1] != 0) minus++;
			checkchislo /= 10;
		}
		if (plus == 4) {
			cout << "Верно!" << endl;
			break;
		}
		else cout << plus << " Плюса " << minus - plus << " Минуса" << endl;
	}
}
int main()
{
	bk();
}
