#include <iostream>  // Подключение стандартной библиотеки для потокового ввода (cin) и вывода (cout)
#include <windows.h> // Подключение функций Windows API (нужно для настройки кодировки консоли)
#include <numbers>   // Подключение библиотеки с математическими константами (используется для точного значения Пи)
#include <iomanip>   // Подключение манипуляторов ввода-вывода (нужно для std::fixed и std::setprecision)

int main() {
    // Установка кодировки UTF-8 для корректного вывода русского текста в консоли Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Вынос делителя в константу, чтобы избежать неясных чисел прямо в формуле
    const int TRIANGLE_DIVIDER = 2;

    // Тип int, так как пункты меню задаются целыми числами
    int program;

    // Тип double используется для цен и геометрических параметров,
    // чтобы сохранить точность при работе с дробными значениями
    double price;
    double sum;
    double radius;
    double length;
    double square;
    double base;
    double height;

    // Тип unsigned int, так как количество товаров физически не может быть отрицательным
    unsigned int amount;

    // Вывод главного меню
    std::cout << "Список программ:" << std::endl;
    std::cout << "0. Выйти из программы" << std::endl;
    std::cout << "1. Стоимость покупки" << std::endl;
    std::cout << "2. Вычисление длины окружности и площади круга" << std::endl;
    std::cout << "3. Вычисление площади треугольника" << std::endl;
    std::cout << "Выберите программу: ";
    std::cin >> program;

    // Проверка ввода: если введена буква (cin.fail()) или число вне диапазона меню
    while (std::cin.fail() or program < 0 or program > 3) {
        std::cin.clear(); // Сброс состояния ошибки потока ввода
        std::cin.ignore(10000, '\n'); // Очистка буфера ввода от некорректных символов до Enter
        std::cout << "Ошибка ввода программы!" << std::endl;
        std::cout << "Выберите программу: ";
        std::cin >> program;
    }

    // Установка формата вывода: числа с фиксированной точкой и ровно 2 знаками после запятой
    std::cout << std::fixed << std::setprecision(2);

    // --- ПРОГРАММА 1: Стоимость покупки ---
    if (program == 1) {
        std::cout << "Введите цену товара: ";
        std::cin >> price;
        // Проверка: цена должна быть строго положительной
        while (std::cin.fail() or price <= 0.0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода цены! Введите положительное число: ";
            std::cin >> price;
        }

        std::cout << "Введите кол-во товаров: ";
        std::cin >> amount;
        // Проверка: количество должно быть больше нуля
        while (std::cin.fail() or amount <= 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода кол-ва товаров! Введите число больше нуля: ";
            std::cin >> amount;
        }

        // Вычисление и вывод итоговой суммы
        sum = price * amount;
        std::cout << "Итоговая цена: " << sum << std::endl;
    }

    // --- ПРОГРАММА 2: Окружность и круг ---
    if (program == 2) {
        std::cout << "Введите радиус круга: ";
        std::cin >> radius;
        // Проверка: радиус должен быть строго положительным
        while (std::cin.fail() or radius <= 0.0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода радиуса! Введите положительное число: ";
            std::cin >> radius;
        }

        // Расчет длины и площади с использованием точной константы Пи из стандартной библиотеки
        length = 2.0 * std::numbers::pi * radius;
        square = std::numbers::pi * (radius * radius);

        std::cout << "Длина окружности: " << length << std::endl;
        std::cout << "Площадь круга: " << square << std::endl;
    }

    // --- ПРОГРАММА 3: Площадь треугольника ---
    if (program == 3) {
        std::cout << "Введите основание треугольника: ";
        std::cin >> base;
        // Проверка: основание должно быть больше нуля
        while (std::cin.fail() or base <= 0.0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода основания! Введите положительное число: ";
            std::cin >> base;
        }

        std::cout << "Введите высоту треугольника: ";
        std::cin >> height;
        // Проверка: высота должна быть больше нуля
        while (std::cin.fail() or height <= 0.0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода высоты! Введите положительное число: ";
            std::cin >> height;
        }

        // Явное приведение типов (static_cast) используется для гарантии того,
        // что деление будет выполнено как вещественное, исключая потерю точности.
        square = static_cast<double>(base * height) / TRIANGLE_DIVIDER;

        std::cout << "Площадь треугольника: " << square << std::endl;
    }

    return 0; // Успешное завершение работы программы
}