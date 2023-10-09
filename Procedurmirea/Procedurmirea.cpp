#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>
#include <string>
#include <algorithm>
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
void file2() {
    setlocale(LC_ALL, "Russian");
    int n = 10;
    int zoloto, bronza, cerebro, schet, vsego;
    int topschet[10]{ 0 };
    int topvsego[10]{ 0 };
    int topzoloto[10]{ 0 };
    int topbronza[10]{ 0 };
    int topcerebro[10]{ 0 };
    string topcountry[10], country;
    ifstream Fin("file2.txt");
    for (int i = 0; i < 10; i++) {
        Fin >> country;
        cout << country << " -> ";
        cin >> zoloto >> cerebro >> bronza;
        vsego = zoloto + cerebro + bronza;
        schet = zoloto * 7 + cerebro * 6 + bronza * 5;
        for (int k = 0; k < 10; k++) {
            if (schet >= topschet[k]) {
                for (int j = n - 2; j >= k; j--) {
                    topschet[j + 1] = topschet[j];
                    topvsego[j + 1] = topvsego[j];
                    topzoloto[j + 1] = topzoloto[j];
                    topcerebro[j + 1] = topcerebro[j];
                    topbronza[j + 1] = topbronza[j];
                    topcountry[j + 1] = topcountry[j];
                }
                topschet[k] = schet;
                topvsego[k] = vsego;
                topzoloto[k] = zoloto;
                topcerebro[k] = cerebro;
                topbronza[k] = bronza;
                topcountry[k] = country;
                k += 11;
            }
        }
    }
    ofstream File("top.txt");
    File << "\t" << "Страна" << "\t" << "Золото" << "\t" << "Серебро" << "\t" << "Бронза" << "\t" << "Всего" << "\t" << "Очков" << endl;
    File << endl;
    for (int i = 0; i < n; i++) {
        File << i + 1 << "\t" << topcountry[i] << "\t" << topzoloto[i] << "\t" << topcerebro[i] << "\t" << topbronza[i] << "\t" << topvsego[i] << "\t" << topschet[i] << endl;

    }

}
int poisk(int *n, int k) {
    if (k != 1) { 
        if (n[k] != 0) {
            poisk(n, k = n[k]);
            return k;
        }
        else return 0;
    }
}
void optimizmonach() {
    int uchmonaha[600]{ 0 };
    int uchenik[3]{ 0 };
    int uchitel, uchenik1, uchenik2, n, n1;
    cout << "Введите количество строк данных: "; 
    cin >> n;
    for (int i = 0; i < n; i++) { 
        cout << "Введите учителя и его учеников: "; 
        cin >> uchitel; 
        for (int i = 0; i < 3; i++) {
            cin >> uchenik[i]; 
            uchmonaha[uchenik[i]] = uchitel;
        }
    }
    cout << "Введите количество проверяемых монахов для части <1>:";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> uchenik1; 
        int num=uchenik1; 
        for (int j = 0; j < n; j++) { 
            uchenik1 = poisk(uchmonaha, uchenik1);
            if (uchenik1 >1) cout << uchenik1<<" ";
            else {
                if(uchenik1==0) cout <<num << " - не монах" << endl;
                break;
            }
        }
    }
    cout << "Введите количество проверяемых монахов для части <2>:";
    cin >> n1;
    for (int i = 0; i < n1; i++) { 
        cin >> uchenik1 >> uchenik2;
        if (uchmonaha[uchenik1] == 0 && uchmonaha[uchenik2] == 0) {
            cout << " - оба не монахи";
            break;
        }
        if (uchmonaha[uchenik1] == 0) {
            cout << uchenik1 << " -не монах";
            break;
        }
        else if (uchmonaha[uchenik2] == 0) {
            cout << uchenik2 << " - не монах";
            break;
        }
        int cycle1 = max(uchenik1, uchenik2);
        for (int i = 0; i < cycle1; i++) {
            if (uchenik1 > uchenik2) uchenik1 = poisk(uchmonaha, uchenik1);
            else {
                if (uchenik1 < uchenik2) uchenik2 = poisk(uchmonaha, uchenik2);
                if (uchenik1 == uchenik2) {
                    cout << uchenik1;
                    break;
                }
            }
        }
    }
}
bool perestanovka(int* kol, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (kol[i] == i)
        {
            return true;
        }
    }
    return false;
}
long double factorial(int N)
{
    if (N < 0) 
        return 0;
    if (N == 0) 
        return 1;
    else
        return N * factorial(N - 1);
}
int shariki() {
    int res = 0, n, factor;
    cin >> n;
    factor = factorial(n);
    int* kol = new int[n] {0};
    for (int i = 0; i < n; i++) {
        kol[i] = i;
    }
    for (int i = 0; i < factor; i++)
    {
        next_permutation(kol, kol +n);
        if (perestanovka(kol, n)==1)
            res++;
    }
    cout << res << endl;

    return 0;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    //bk();
    optimizmonach();
    //sinusoida();
	//dz4_4();
    //shariki();
}
