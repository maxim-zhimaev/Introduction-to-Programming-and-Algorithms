#include <iostream>  // Подключаем библиотеку для ввода/вывода
#include <windows.h> // Для работы с API Windows (здесь нужна для смены кодировки консоли на UTF-8)
#include <iomanip>   // Использование <iomanip> для форматирования
#include <cmath>     // Подключаем для математических функций и для std::round (округление)

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int program;

    // Объявляем переменные типа double.
    // Почему double? Цена и вес могут быть дробными
    double price;
    double weight;
    double cost;
    int number;
    double number_double;
    long square;
    long long cube;

    // ~7 знаков
    // f в конце для float
    float a_f = 1.98765432f;
    float b_f = -3.14159265f;
    float c_f = 5.55555555f;
    float d_f = -0.12345678f;
    float e_f = 42.99999999f;
    float y_f;

    // ~16 знаков
    // double по умолчанию
    double a_d = 1.98765432;
    double b_d = -3.14159265;
    double c_d = 5.55555555;
    double d_d = -0.12345678;
    double e_d = 42.99999999;
    double y_d;
    double error;
    double x;

    // Выводим приглашение для пользователя
    std::cout << "Список программ:" << std::endl;
    std::cout << "0. Выйти из программы" << std::endl;
    std::cout << "1. Вычислить стоимость" << std::endl;
    std::cout << "2. Возведение числа в квадрат и куб" << std::endl;
    std::cout << "3. Вычисление многочлена 4-й степени" << std::endl;
    std::cout << "Выберите программу: ";

    // Считываем значение с клавиатуры
    std::cin >> program;

    // Проверка на ввод некорректных данных (std::cin.fail())
    while (std::cin.fail() or program < 0 or program > 3) {
        // Очистка буфера ввода при ошибке (std::cin.clear(), std::cin.ignore())
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        // Вывод понятного сообщения об ошибке вместо аварийного завершения
        std::cout << "Ошибка ввода программы!" << std::endl;
        std::cout << "Выберите программу: ";
        std::cin >> program;
    }

    if (program == 1) {
        // Использование std::fixed и std::setprecision для точности
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Введите цену товара за килограмм: ";
        std::cin >> price;
        while (std::cin.fail() or price <= 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода цены!" << std::endl;
            std::cout << "Введите цену товара за килограмм: ";
            std::cin >> price;
        }
        std::cout << "Введите вес товара: ";
        std::cin >> weight;
        while (std::cin.fail() or weight <= 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода веса!" << std::endl;
            std::cout << "Введите вес товара: ";
            std::cin >> weight;
        }
        // Оба операнда double -> результат double
        cost = price * weight;
        // Выводим результат
        std::cout << "Стоимость покупки: " << cost << std::endl;

    }

    if (program == 2) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Введите целое число: ";
        std::cin >> number;
        while (std::cin.fail() or std::cin.get() != '\n') {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода числа!" << std::endl;
            std::cout << "Введите целое число: ";
            std::cin >> number;
        }
        // НЕЯВНОЕ приведение: int -> double
        // без потерь
        number_double = number;
        square = number_double * number_double;
        cube = number_double * number_double * number_double;
        std::cout << "Число в квадрате: " << square << std::endl;
        std::cout << "число в кубе: " << cube << std::endl;
    }

    if (program == 3) {
        std::cout << std::fixed << std::setprecision(50);
        std::cout << "Введите x: ";
        std::cin >> x;
        while (std::cin.fail() or std::cin.get() != '\n') {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода значения x!" << std::endl;
            std::cout << "Введите x: ";
            std::cin >> x;
        }
        y_f = a_f * std::pow(x, 4) + b_f * std::pow(x, 3) + c_f * std::pow(x, 2) + d_f * x + e_f;
        y_d = a_d * std::pow(x, 4) + b_d * std::pow(x, 3) + c_d * std::pow(x, 2) + d_d * x + e_d;
        // Демонстрация потери точности между float и double
        error = y_d - y_f;
        std::cout << "Вычисление с float: " << y_f << std::endl;
        std::cout << "Вычисление с double: " << y_d << std::endl;
        std::cout << "Погрешность: " << error << std::endl;
    }

    // Успешное завершение программы
    return 0;
}