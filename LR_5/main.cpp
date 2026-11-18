#include <iostream>  // Подключение библиотеки для ввода и вывода данных (cin, cout)
#include <windows.h> // Подключение Windows API для настройки кодировки консоли
#include <iomanip>   // Подключение манипуляторов форматирования вывода (setw, setprecision, fixed)
#include <cmath>     // Подключение математических функций (sqrt, log, abs)

int main() {
    // Установка кодировки UTF-8 для корректного отображения кириллицы в консоли Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Настройка вывода вещественных чисел: фиксированный формат и 4 знака после запятой
    std::cout << std::fixed << std::setprecision(4);

    int program; // Переменная для выбора режима работы программы
    int fn;      // Переменная для выбора функции в 3-м режиме

    double a, b, h; // Границы интервала [a, b] и шаг табуляции h
    double xFirst;  // Начальное значение x (равное левой границе a)
    double yFirst;  // Значение функции в первой точке xFirst
    double minY;    // Минимальное значение функции на интервале
    double maxY;    // Максимальное значение функции на интервале

    int count = 0;    // Счетчик отрицательных значений функции (для 2-го режима)
    double sum = 0.0; // Накопитель суммы значений функции (для 3-го режима)
    bool flag = false; // Флаг для отслеживания повторного ввода границ интервала

    // Вывод главного меню программы
    std::cout << "Список программ:" << std::endl;
    std::cout << "1. Табуляция простой функции на интервале [a, b] с шагом h." << std::endl;
    std::cout << "2. Табуляция + найти количество отрицательных значений." << std::endl;
    std::cout << "3. Табуляция + накопление суммы ряда." << std::endl;
    std::cout << "0. Выйти из программы." << std::endl;
    std::cout << "Выберите программу: ";

    std::cin >> program;

    // Проверка корректности ввода пункта меню (целое число от 0 до 3 без лишних символов)
    while (std::cin.fail() || program < 0 || program > 3 || std::cin.get() != '\n') {
        std::cin.clear();            // Сброс флага ошибки потока ввода
        std::cin.ignore(10000, '\n'); // Очистка буфера клавиатуры до символа новой строки
        std::cout << "Ошибка ввода программы!" << std::endl;
        std::cout << "Выберите программу: ";
        std::cin >> program;
    }

    // Досрочный выход из программы при выборе пункта 0
    if (program == 0) {
        return 0;
    }

    // Цикл ввода границ отрезка [a, b] и шага h с проверкой их корректности (a <= b и h > 0)
    do {
        if (flag) {
            std::cout << "Ошибка ввода чисел!" << std::endl;
            std::cout << "Подсказка: a < b, h > 0!" << std::endl;
        }

        // Ввод и проверка левой границы a
        std::cout << "Введите число a:";
        std::cin >> a;
        while (std::cin.fail() || std::cin.get() != '\n') {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода числа!" << std::endl;
            std::cout << "Введите число a:";
            std::cin >> a;
        }

        // Ввод и проверка правой границы b
        std::cout << "Введите число b:";
        std::cin >> b;
        while (std::cin.fail() || std::cin.get() != '\n') {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода числа!" << std::endl;
            std::cout << "Введите число b:";
            std::cin >> b;
        }

        // Ввод и проверка шага табуляции h
        std::cout << "Введите число h:";
        std::cin >> h;
        while (std::cin.fail() || std::cin.get() != '\n') {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода числа!" << std::endl;
            std::cout << "Введите число h:";
            std::cin >> h;
        }

        flag = true; // Устанавливаем флаг, чтобы при следующей итерации вывести подсказку об ошибке
    } while (a > b || h <= 0);

    // Выбор алгоритма в зависимости от выбранного режима программы
    switch (program) {
        // Режим 1: Табуляция функции y = √x
        case 1: {
            std::cout << std::endl;
            std::cout << "==========================================" << std::endl;
            std::cout << "  x      |       y=√x" << std::endl;
            std::cout << "==========================================" << std::endl;
            // Проход по отрезку [a, b] с шагом h (1e-9 добавлено для компенсации погрешности double)
            for (double x = a; x <= b + 1e-9; x += h) {
                // Проверка области определения функции (x >= 0) с учетом погрешности вычислений
                if (x >= -1e-9) {
                    if (x < 0) x = 0.0; // Обнуление микроскопической отрицательной погрешности в нуле
                    double y = std::sqrt(x);
                    std::cout << std::setw(8) << x << " | " << std::setw(12) << y << std::endl;
                }
            }
            std::cout << "==========================================" << std::endl;
            break;
        }

        // Режим 2: Табуляция функции y = ln(x) и подсчет количества отрицательных значений
        case 2: {
            std::cout << std::endl;
            std::cout << "==========================================" << std::endl;
            std::cout << "  x      |       y=ln(x)" << std::endl;
            std::cout << "==========================================" << std::endl;
            for (double x = a; x <= b + 1e-9; x += h) {
                // Проверка области определения натурального логарифма (x > 0)
                if (x > 1e-9) {
                    double y = std::log(x);
                    if (std::abs(y) < 1e-9) y = 0.0; // Устранение машинного нуля (-0.0000)
                    std::cout << std::setw(8) << x << " | " << std::setw(12) << y << std::endl;
                    // Если значение функции строго отрицательное, увеличиваем счетчик
                    if (y <= -1e-9) {
                        count++;
                    }
                }
            }
            std::cout << "==========================================" << std::endl;
            std::cout << "Количество отрицательных значений: " << count << std::endl;
            break;
        }

        // Режим 3: Меню выбора одной из 5 функций, табуляция и поиск min, max и суммы
        case 3: {
            std::cout << "Список функций:" << std::endl;
            std::cout << "1. y=2x-1" << std::endl;
            std::cout << "2. y=x²" << std::endl;
            std::cout << "3. y=x³" << std::endl;
            std::cout << "4. y=|x|" << std::endl;
            std::cout << "5. y=3" << std::endl;
            std::cout << "Выберите функцию: ";

            std::cin >> fn;

            // Проверка корректности выбора функции (целое число от 1 до 5)
            while (std::cin.fail() || fn < 1 || fn > 5 || std::cin.get() != '\n') {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка ввода функции!" << std::endl;
                std::cout << "Выберите функцию: ";
                std::cin >> fn;
            }

            // Выполнение табуляции и анализа для выбранной функции
            switch (fn) {
                // Функция 1: y = 2x - 1
                case 1: {
                    // Инициализация начальных значений minY и maxY по первой точке отрезка
                    xFirst = a;
                    yFirst = 2 * xFirst - 1;
                    if (std::abs(yFirst) < 1e-9) yFirst = 0.0;
                    minY = yFirst;
                    maxY = yFirst;

                    std::cout << std::endl;
                    std::cout << "==========================================" << std::endl;
                    std::cout << "  x      |       y=2x-1" << std::endl;
                    std::cout << "==========================================" << std::endl;
                    for (double x = a; x <= b + 1e-9; x += h) {
                        if (std::abs(x) < 1e-9) x = 0.0;
                        double y = 2 * x - 1;
                        if (std::abs(y) < 1e-9) y = 0.0;
                        std::cout << std::setw(8) << x << " | " << std::setw(12) << y << std::endl;
                        // Обновление минимума, максимума и накопление суммы
                        if (y < minY) minY = y;
                        if (y > maxY) maxY = y;
                        sum += y;
                    }
                    std::cout << "==========================================" << std::endl;
                    std::cout << "Минимум: " << minY << std::endl;
                    std::cout << "Максимум: " << maxY << std::endl;
                    std::cout << "Сумма: "<< sum << std::endl;
                    break;
                }

                // Функция 2: y = x²
                case 2: {
                    xFirst = a;
                    yFirst = xFirst * xFirst;
                    if (std::abs(yFirst) < 1e-9) yFirst = 0.0;
                    minY = yFirst;
                    maxY = yFirst;

                    std::cout << std::endl;
                    std::cout << "==========================================" << std::endl;
                    std::cout << "  x      |       y=x²" << std::endl;
                    std::cout << "==========================================" << std::endl;
                    for (double x = a; x <= b + 1e-9; x += h) {
                        if (std::abs(x) < 1e-9) x = 0.0;
                        double y = x * x;
                        if (std::abs(y) < 1e-9) y = 0.0;
                        std::cout << std::setw(8) << x << " | " << std::setw(12) << y << std::endl;
                        if (y < minY) minY = y;
                        if (y > maxY) maxY = y;
                        sum += y;
                    }
                    std::cout << "==========================================" << std::endl;
                    std::cout << "Минимум: " << minY << std::endl;
                    std::cout << "Максимум: " << maxY << std::endl;
                    std::cout << "Сумма: "<< sum << std::endl;
                    break;
                }

                // Функция 3: y = x³
                case 3: {
                    xFirst = a;
                    yFirst = xFirst * xFirst * xFirst;
                    if (std::abs(yFirst) < 1e-9) yFirst = 0.0;
                    minY = yFirst;
                    maxY = yFirst;

                    std::cout << std::endl;
                    std::cout << "==========================================" << std::endl;
                    std::cout << "  x      |       y=x³" << std::endl;
                    std::cout << "==========================================" << std::endl;
                    for (double x = a; x <= b + 1e-9; x += h) {
                        if (std::abs(x) < 1e-9) x = 0.0;
                        double y = x * x * x;
                        if (std::abs(y) < 1e-9) y = 0.0;
                        std::cout << std::setw(8) << x << " | " << std::setw(12) << y << std::endl;
                        if (y < minY) minY = y;
                        if (y > maxY) maxY = y;
                        sum += y;
                    }
                    std::cout << "==========================================" << std::endl;
                    std::cout << "Минимум: " << minY << std::endl;
                    std::cout << "Максимум: " << maxY << std::endl;
                    std::cout << "Сумма: "<< sum << std::endl;
                    break;
                }

                // Функция 4: y = |x|
                case 4: {
                    xFirst = a;
                    yFirst = std::abs(xFirst);
                    if (std::abs(yFirst) < 1e-9) yFirst = 0.0;
                    minY = yFirst;
                    maxY = yFirst;

                    std::cout << std::endl;
                    std::cout << "==========================================" << std::endl;
                    std::cout << "  x      |       y=|x|" << std::endl;
                    std::cout << "==========================================" << std::endl;
                    for (double x = a; x <= b + 1e-9; x += h) {
                        if (std::abs(x) < 1e-9) x = 0.0;
                        double y = std::abs(x);
                        if (std::abs(y) < 1e-9) y = 0.0;
                        std::cout << std::setw(8) << x << " | " << std::setw(12) << y << std::endl;
                        if (y < minY) minY = y;
                        if (y > maxY) maxY = y;
                        sum += y;
                    }
                    std::cout << "==========================================" << std::endl;
                    std::cout << "Минимум: " << minY << std::endl;
                    std::cout << "Максимум: " << maxY << std::endl;
                    std::cout << "Сумма: "<< sum << std::endl;
                    break;
                }

                // Функция 5: y = 3 (константная функция)
                case 5: {
                    xFirst = a;
                    yFirst = 3;
                    if (std::abs(yFirst) < 1e-9) yFirst = 0.0;
                    minY = yFirst;
                    maxY = yFirst;

                    std::cout << std::endl;
                    std::cout << "==========================================" << std::endl;
                    std::cout << "  x      |       y=3" << std::endl;
                    std::cout << "==========================================" << std::endl;
                    for (double x = a; x <= b + 1e-9; x += h) {
                        if (std::abs(x) < 1e-9) x = 0.0;
                        double y = 3;
                        if (std::abs(y) < 1e-9) y = 0.0;
                        std::cout << std::setw(8) << x << " | " << std::setw(12) << y << std::endl;
                        if (y < minY) minY = y;
                        if (y > maxY) maxY = y;
                        sum += y;
                    }
                    std::cout << "==========================================" << std::endl;
                    std::cout << "Минимум: " << minY << std::endl;
                    std::cout << "Максимум: " << maxY << std::endl;
                    std::cout << "Сумма: "<< sum << std::endl;
                    break;
                }
            }
            break;
        }
    }

    return 0; // Успешное завершение работы программы
}