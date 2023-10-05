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
	int chislo, check, check1, checkchislo, start = 0, end = 9, r = 4, plus = 0, chislocomp = 0, minus = 0;
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
void monach() {
    setlocale(LC_ALL, "Russian");
    int monachinfo[600][3]{ 0 };
    int nummonach[600]{ 0 };
    int uchitel, uchenik1, uchenik2, uchenik3, n, n1, checkmonah, checkmonah2, r = 0, r1 = 0,perm1,perm2;
    cout << "Введите количество строк данных: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Введите учителя и его учеников: ";
        cin >> uchitel >> uchenik1 >> uchenik2 >> uchenik3;
        monachinfo[uchitel][0] = uchenik1;
        monachinfo[uchitel][1] = uchenik2;
        monachinfo[uchitel][2] = uchenik3;
        nummonach[uchitel] = 1;
        nummonach[uchenik1] = 1;
        nummonach[uchenik2] = 1;
        nummonach[uchenik3] = 1;
    }
    cout << "Введите количество проверяемых монахов для части <1>:";
    cin >> n1;
    for (int k = 0; k < n1; k++) {
        int uchmonaha[600]{ 0 };
        r = 0;
        cout << "Введите проверяемого монаха:";
        cin >> checkmonah;
        perm1 = checkmonah;
        if (nummonach[checkmonah] == 1) {
            cout << checkmonah << " - монах, его учителя ";
            for (int i = perm1; i >= 0; i--) {
                for (int j = 0; j < 3; j++) {
                    if (monachinfo[i][j] == checkmonah && r < 2) {
                        uchmonaha[checkmonah] = i;
                        checkmonah = i;
                        r++;
                    }
                }
            }
            for (int i = perm1; i >= 0; i--) {
                if (uchmonaha[i] != 0) cout << uchmonaha[i]  << " ";
            }
            cout << endl;
        }
        else {
            cout << checkmonah << " - не монах" << endl;
        }
    }
    cout << "Введите количество проверяемых монахов для части <2>:";
    cin >> n1;
    for (int k = 0; k < n1; k++) {
        int uchmonaha1[600]{ 0 };
        int uchmonaha2[600]{ 0 };
        r1 = 0;
        cout << "Введите проверяемых монахов:";
        cin >> checkmonah >> checkmonah2;
        perm1 = checkmonah;
        perm2 = checkmonah2;
        if (nummonach[checkmonah] == 1 && nummonach[checkmonah2] == 1) {
            cout << checkmonah << " и " << checkmonah2 << " - оба монахи, и их общий учитель ";
            for (int i = perm1; i >= 0; i--) {
                for (int j = 0; j < 3; j++) {
                    if (monachinfo[i][j] == checkmonah) {
                        uchmonaha1[checkmonah] = i;
                        checkmonah = i;
                    }
                }
            }
            for (int i = perm2; i >= 0; i--) {
                for (int j = 0; j < 3; j++) {
                    if (monachinfo[i][j] == checkmonah2) {
                        uchmonaha2[checkmonah2] = i;
                        checkmonah2 = i;
                    }
                }
            }
            for (int i = max(perm1,perm2); i >= 0; i--) {
                for (int j = max(perm1, perm2); j >= 0; j--) {
                    if (uchmonaha1[i]==uchmonaha2[j] && uchmonaha1[i]!=0 && r1==0) {
                        cout << uchmonaha1[i] << " ";
                        r1++;
                    }
                }
            }
            cout << endl;
        }
        else {
            if (nummonach[checkmonah] != 1 && nummonach[checkmonah2] != 1) cout << checkmonah << " и " << checkmonah2 << " - оба не монахи" << endl;
            else {
                if (nummonach[checkmonah2] == 1) {
                    cout << checkmonah << " - не монах" << endl;
                }
                else cout << checkmonah2 << " - не монах" << endl;
            }
        }
    }
}
int main()
{
    //bk();
    monach();
	//dz4_4();

}
