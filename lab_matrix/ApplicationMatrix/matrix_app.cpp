// Copyright (c) Dudchenko Olesya Victorovna
#include <iostream>
#include <Windows.h>
#include "../TMatrix/Matrix.h"

//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    bool flag = 1;
//    TMatrix A();
//    TMatrix B(1);
//    std::string title = ("---====����====---\n\n");
//    const std::string menu = " 1.;\n 2.������ ��������� B;\n 3.����� ����������� �������� A + B;\n 4.����� �������� ��������� A - B\n 5.����� ����������� �������� A * B\n 6.����� ���������� ���������\n 7.��������� ���������������� ������\n 8.�����\n";
//    const std::string in = " ��� �����: ";
//    while (flag)
//    {
//        std::cout << title;
//        std::cout << menu;
//        std::cout << in;
//        int x;
//        std::cin >> x;
//        system("cls");
//        switch (x)
//        {
//        case 1:
//        {
//            int power;
//            std::cout << "������� �������� ��������� A: ";
//            std::cin >> power;
//            TSet ts(power);
//            std::cout << "������ ����: ";
//            std::cin >> ts;
//            A = ts;
//            std::cout << A;
//            system("pause");
//            system("cls");
//            break;
//        }
//        case 2:
//        {
//            int power;
//            std::cout << "������� �������� ��������� B: ";
//            std::cin >> power;
//            TSet ts(power);
//            std::cout << "������ ����: ";
//            std::cin >> ts;
//            B = ts;
//            std::cout << A;
//            system("pause");
//            system("cls");
//            break;
//        }
//        case 3:
//        {
//            TSet ts(A + B);
//            std::cout << ts;
//            system("pause");
//            system("cls");
//            break;
//        }
//        case 4:
//        {
//            TSet ts(A * (~B));
//            std::cout << ts;
//            system("pause");
//            system("cls");
//            break;
//        }
//        case 5:
//        {
//            TSet ts(A * B);
//            std::cout << ts;
//            system("pause");
//            system("cls");
//            break;
//        }
//        case 6:
//        {
//            std::cout << "���������� ��������� �: " << ~A;
//            std::cout << "���������� ��������� B: " << ~B;
//            system("pause");
//            system("cls");
//            break;
//        }
//        case 7:
//        {
//            int n;
//            std::cout << "������� N: ";
//            std::cin >> n;
//            eratosthenes_alghoritm(n);
//            system("pause");
//            system("cls");
//            break;
//        }
//        case 8:
//        {
//            flag = 0;
//        }
//        }
//    }
//}