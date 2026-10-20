#include <iostream>
#include <windows.h>
#include <string>

int main() {
    // Установка кодировки UTF-8 для корректного вывода русского языка в консоль Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int program;

    // Переменные для различных подпрограмм
    int number;
    int remainder;
    std::string characteristic_1;
    std::string characteristic_2;
    std::string color;
    std::string action;

    // Вывод консольного меню
    std::cout << "Список программ:" << std::endl;
    std::cout << "1. Определить, кратно ли число 5" << std::endl;
    std::cout << "2. Характеристика числа" << std::endl;
    std::cout << "3. Светофор" << std::endl;
    std::cout << "0. Выйти из программы" << std::endl;
    std::cout << "Выберите программу: ";

    std::cin >> program;

    // Защита от некорректного ввода номера программы
    while (std::cin.fail() || program < 0 || program > 3 || std::cin.get() != '\n') {
        std::cin.clear(); // Сброс флага ошибки
        std::cin.ignore(10000, '\n'); // Очистка буфера
        std::cout << "Ошибка ввода программы!" << std::endl;
        std::cout << "Выберите программу: ";
        std::cin >> program;
    }

    // Программа 1: Проверка кратности числа 5 (Базовый уровень)
    if (program == 1) {
        std::cout << "Введите целое число: ";
        std::cin >> number;
        // Защита от некорректного ввода числа
        while (std::cin.fail() || std::cin.get() != '\n') {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода целого числа!" << std::endl;
            std::cout << "Введите целое число: ";
            std::cin >> number;
        }
        // Ветвление: проверка кратности
        if (number % 5 == 0) {
            std::cout << "Число " << number << " кратно 5" << std::endl;
        }
        else {
            remainder = number % 5;
            std::cout << "Число " << number << " не кратно 5, остаток от деления: " << remainder << std::endl;
        }
    }

    // Программа 2: Характеристика числа (Средний уровень)
    if (program == 2) {
        std::cout << "Введите целое число: ";
        std::cin >> number;
        // Защита от некорректного ввода
        while (std::cin.fail() || std::cin.get() != '\n') {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода целого числа!" << std::endl;
            std::cout << "Введите целое число: ";
            std::cin >> number;
        }
        // Ветвление для исключения нуля
        if (number != 0) {
            // Использование тернарного оператора для определения характеристик
            characteristic_1 = (number < 0)?"отрицательное":"положительное";
            characteristic_2 = (number % 2 == 0)?"чётное":"нечётное";
            std::cout << "Характеристика числа: " << characteristic_1 << ", " << characteristic_2 << std::endl;
        } else {
            characteristic_1 = "ноль";
            std::cout << "Характеристика числа: " << characteristic_1 << std::endl;
        }

    }

    // Программа 3: Светофор (Повышенный уровень)
    if (program == 3) {
        // Цикл для повторного запроса при неверном вводе
        while (true) {
            std::cout << "Введите цвет светофора: ";
            std::cin >> color;
            // Множественное ветвление с логическим ИЛИ (||)
            if (color == "Красный" || color == "красный") {
                color = "красный";
                action = "стоять";
                break; // Выход из цикла при успешном вводе
            } if (color == "Желтый" || color == "желтый" || color == "Жёлтый" || color == "жёлтый") {
                color = "жёлтый";
                action = "приготовиться";
                break;
            } if (color == "Зеленый" || color == "зеленый" || color == "Зелёный" || color == "зелёный") {
                color = "зелёный";
                action = "идти";
                break;
            } else {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка ввода цвета светофора!" << std::endl;
            }
        }
        std::cout << "На " << color << " сигнал светофора следут " << action << std::endl;
    }

    return 0;
}