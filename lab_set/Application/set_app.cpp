#include "../Set/set.h"
#include <iostream>
#include <Windows.h>

#define USE_SET

#ifdef USE_SET
void eratosthenes_alghoritm(int n) {
    std::cout << "---===Решето Эратосфена через множества===---" << std::endl;
    TSet U(n);
    U = ~U;
    for (int i = 2; i < n; i++) {
        for (int j = i * i; j < n; j += i) {
            U.DelElem(j);
        }
    }
    std::cout << U;
}
#else
void eratosthenes_alghoritm(int n) {
    std::cout << "---===Решето Эратосфена через битовые поля===---" << std::endl;
    TBitField U(n);
    U = ~U;
    for (int i = 2; i < n; i++) {
        for (int j = i * i; j < n; j += i) {
            U.reset(j);
        }
    }
    std::cout << U;
}
#endif USE_SET


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool flag = 1;
    TSet A(1);
    TSet B(1);
    std::string title = ("---====МЕНЮ====---\n\n");
    const std::string menu = " 1.Задать множество A;\n 2.Задать множество B;\n 3.Найти объединение множеств A + B;\n 4.Найти разность множества A - B\n 5.Найти пересечение множеств A * B\n 6.Найти дополнение множества\n 7.Запустить демонстрационный пример\n 8.Выход\n";
    const std::string in = " Ваш выбор: ";
    while (flag)
    {
        std::cout << title;
        std::cout << menu;
        std::cout << in;
        int x;
        std::cin >> x;
        system("cls");
        switch (x)
        {
        case 1:
        {
            int power;
            std::cout << "Введите мощность множества A: ";
            std::cin >> power;
            TSet ts(power);
            std::cout << "Задать поле: ";
            std::cin >> ts;
            A = ts;
            std::cout << A;
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            int power;
            std::cout << "Введите мощность множества B: ";
            std::cin >> power;
            TSet ts(power);
            std::cout << "Задать поле: ";
            std::cin >> ts;
            B = ts;
            std::cout << A;
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            TSet ts(A + B);
            std::cout << ts;
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            TSet ts(A * (~B));
            std::cout << ts;
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            TSet ts(A * B);
            std::cout << ts;
            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            std::cout << "Дополнение множества А: " << ~A;
            std::cout << "Дополнение множества B: " << ~B;
            system("pause");
            system("cls");
            break;
        }
        case 7:
        {
            int n;
            std::cout << "Введите N: ";
            std::cin >> n;
            eratosthenes_alghoritm(n);
            system("pause");
            system("cls");
            break;
        }
        case 8:
        {
            flag = 0;
        }
        }
    }
}

