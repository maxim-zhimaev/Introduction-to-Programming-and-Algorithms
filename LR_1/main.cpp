#include <iostream>
#include <windows.h>
int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int program;
    std::cout << "Список программ:" << std::endl;
    std::cout << "0. Выйти из программы" << std::endl;
    std::cout << "1. Стоимость покупки" << std::endl;
    std::cout << "2. Вычисление длины окружности и площади круга" << std::endl;
    std::cout << "3. Вычисление площади треугольника" << std::endl;
    std::cout << "Выберите программу:";
    std::cin >> program;
    if (std::cin.fail() or program < 0 or program > 3) {
        std::cout << "Ошибка ввода программы!" << std::endl;
        return 0;
    }

    if (program == 1) {
        double price;
        unsigned int amount;
        double sum;
        std::cout << "Введите цену товара:";
        std::cin >> price;
        if (std::cin.fail() or price <= 0.0) {
            std::cout << "Ошибка ввода цены!" << std::endl;
            return 0;
        }
        std::cout << "Введите кол-во товаров:";
        std::cin >> amount;
        if (std::cin.fail() or amount <= 0.0) {
            std::cout << "Ошибка ввода кол-ва товаров!" << std::endl;
            return 0;
        }
        sum = price * amount;
        std::cout << "Итоговая цена: " << sum;
    }

    if (program == 2) {
        double radius;
        double length;
        double square;
        std::cout << "Введите радиус круга:";
        std::cin >> radius;
        if (std::cin.fail() or radius <= 0.0) {
            std::cout << "Ошибка ввода радиуса!" << std::endl;
            return 0;
        }
        length = 2.0 * std::numbers::pi * radius;
        square = std::numbers::pi * (radius * radius);
        std::cout << "Длина окружности: " << length << ", Площадь круга: " << square;
    }

    if (program == 3) {
        double base;
        double height;
        double square;
        std::cout << "Введите основание треугольника:";
        std::cin >> base;
        if (std::cin.fail() or base <= 0.0) {
            std::cout << "Ошибка ввода основания!" << std::endl;
            return 0;
        }
        std::cout << "Введите высоту треугольника:";
        std::cin >> height;
        if (std::cin.fail() or height <= 0.0) {
            std::cout << "Ошибка ввода высоты!" << std::endl;
            return 0;
        }
        square = (base * height) / 2.0;
        std::cout << "Площадь треугольника: " << square;
    }

    return 0;
}