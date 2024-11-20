#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Проверка на наличие определения M_PI
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Функция для проверки корректности ввода
double get_positive_number(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
            cout << "Ошибка: введите положительное число.\n";
        }
        else {
            return value;
        }
    }
}

// Функция для вычисления площади поверхности цилиндра
double calculate_cylinder_surface_area(double radius, double height) {
    return 2 * M_PI * radius * (radius + height);
}

int main() {
    // Устанавливаем локаль для правильного отображения текста
    setlocale(LC_ALL, "Russian");

    cout << "Программа для вычисления площади поверхности цилиндра\n";

    // Запрашиваем у пользователя параметры цилиндра
    double radius = get_positive_number("Введите радиус основания цилиндра: ");
    double height = get_positive_number("Введите высоту цилиндра: ");

    // Вычисляем площадь поверхности цилиндра
    double surface_area = calculate_cylinder_surface_area(radius, height);

    // Выводим результат
    cout << "Площадь поверхности цилиндра: " << surface_area << endl;

    return 0;
}