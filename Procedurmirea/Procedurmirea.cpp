#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>
using namespace std;
void dz2_1() {
    setlocale(LC_ALL, "Russian");
    float V, h, l, r, R, S;
    cout << "Введите R: ";
    cin >> R;
    cout << "Введите h: ";
    cin >> h;
    cout << "Введите r: ";
    cin >> r;
    V = 1.0 / 3 * M_PI * h * (R * R + R * r + r * r);
    l = sqrt(h * h + pow((R - r), 2));
    S = M_PI * (R * R + (R + r) * l + r * r);
    cout << "V= " << V << " " << "S= " << S;

}
void dz2_2() {
    setlocale(LC_ALL, "Russian");
    float w, a, x;
    cout << "Введите  x: ";
    cin >> x;
    cout << "Введите a: ";
    cin >> a;
    cout << " ";
    if (abs(x) < 1) {
        if (abs(x) > 0) {
            if (a != 0) w = a * log(abs(x));
            else w = 0;
            cout << w;
        }
        else cout << "ошибка";
    }
    else {
        if (sqrt(a - x * x) >= 0) {
            w = sqrt(a - x * x);
            cout << w;
        }
        else cout << "ошибка";
    }
}
void dz2_3() {
    float z, b, y, x;
    cin >> b >> x >> y;
    if (b - y > 0 && b - x >= 0) {
        z = log(b - y) * sqrt(b - x);
        cout << z;
    }
    else cout << "ошибка";

}
void dz2_4() {
    int N;
    cin >> N;
    if (N > 0) cout << N << " ";
    for (int i = 0; i < 9; i++) {
        N++;
        if (N > 0) cout << N << " ";
    }
}
void dz2_5() {
    setlocale(LC_ALL, "Russian");
    float y;
    for (float x = -4; x <= 4; x += 0.5) {
        if (x - 1 != 0) {
            y = (x * x - 2 * x + 2) / (x - 1);
            cout << "x= " << x << " y= " << y << endl;
        }
        else cout << "x= " << x << " y= не существ " << endl;
    }
}
void dz3_1() {
    float m, S, n, r;
    int p;
    cin >> S >> p >> n;
    r = p / 100.0;
    if (12 * (pow(1 + r, n) - 1) != 0) {
        m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
        cout << m;
    }
    else cout << "no result";
}
void dz3_2() {
    double m, S, n, r, m1;
    int p;
    float razbr = 0.125;
    cout << "Ввдите S:";
    cin >> S;
    cout << "Ввдите n:";
    cin >> n;
    cout << "Ввдите m:";
    cin >> m1;
    for (p = 0; p < 100; p++) {
        r = p / 100.0;
        if ((12 * (pow(1 + r, n) - 1)) != 0) {
            m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
            if (m1 - m<razbr && m1 - m>-razbr) cout << p;
        }
    }

}
void dz3_3() {
    ifstream Fin("3_3.txt");
    float f = 1, f1 = 0;
    while (!Fin.eof()) {
        Fin >> f;
        cout << f << endl;
    }
}
void dz3_4() {
    ifstream Fin("3_4.txt");
    string f;
    int len;
    string n;
    while (!Fin.eof()) {
        Fin >> f;
        len = f.length();
        for (int i = 0; i < len; i++) {
            if (f[i] > 47 && f[i] < 58) cout << f[i];
        }
    }
}
void dz4_1() {
    ofstream File;
    File.open("4_1.txt");
    int k, sum = 0;
    for (int i = 0; i < 10; i++) {
        cin >> k;
        File << k << endl;
    }
    File.close();
    ifstream Fin("4_1.txt");
    for (int i = 0; i < 10; i++) {
        Fin >> k;
        sum += k;
    }
    cout << sum;
}
void dz4_2() {
    int x;
    cin >> x;
    if (x > 0) {
        cout << "1";
    }
    if (x < 0) {
        cout << "-1";
    }
    if (x == 0) {
        cout << "0";
    }

}
void dz4_4() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 31;
    for (int i = 0; i < 6; i++) {
        k = 31;
        SetConsoleTextAttribute(hConsole, k);
        cout << "* * * * * * * * ";
        if (i % 2 == 0) k = 68;
        else k =255;
        SetConsoleTextAttribute(hConsole, k);
        cout << "                " << endl;
    }
    for (int i = 0; i < 7; i++) {
        if (i % 2 == 0) k = 68;
        else k = 255;
        SetConsoleTextAttribute(hConsole, k);
        cout << "                                " << endl;
    }
    k = 7;
    SetConsoleTextAttribute(hConsole, k);
}
void sinusoida() {
    int yg, newy, newx, razm = 0;
    double y, x;
    char cord[317][317];
    for (int o = 0; o < 317; o++) {
        for (int l = 0; l < 317; l++) {
            cord[o][l] = ' ';
        }
    }
    for (x = M_PI; x <= M_PI * 8; x += M_PI / 30) {  //30 заменить на нужный шаг
        yg = x * 180 / M_PI;
        if (yg / 180 == 0) y = 0;
        else y = sin(x);
        y = (int(y * 100) / 100.0) * 30; //30 выбор размера
        y = round(y);
        newx = (int(x * 100) / 10.0 - 31);
        newy = int(y + 30); //30 заменить на нужный шаг
        cord[newx][newy] = '&';
        razm++;
        //cout << razm <<" " << newx <<" " << newy << endl;
    }
    for (int i = 0; i < 61; i++) {
        for (int j = 0; j < 222; j++) {
            if (i == 30 && cord[j][i] != '&') {
                cord[j][i] = '-';
                cout << cord[j][i];
            }
            else {
                cout << cord[j][i];
            }
        }
        cout << endl;
    }

}
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
void test() {
    srand(time(0));
    int start = 0, end = 9, r = 4, plus = 0;
    int random = rand() % (end - start + 1) + start;
    cout << random;
}
int main()
{
	dz4_4();
}
