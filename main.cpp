#include <iostream>
#include <cmath>
using namespace std;

// Завдання 1 (Варіант 13): Визначити кількість точок всередині кола
void task1() {
    int n;
    cout << "Введіть кількість точок: ";
    cin >> n;

    int count = 0;
    double x, y;
    double r = 5; // Розмір радіусу кола, можна змінити

    for (int i = 0; i < n; i++) {
        cout << "Введіть координати точки " << i+1 << " (x y): ";
        cin >> x >> y;

        // Перевірка, чи точка знаходиться всередині кола
        if (pow(x, 2) + pow(y, 2) <= pow(r, 2)) {
            count++;
        }
    }

    cout << "Кількість точок всередині кола: " << count << endl;
}

// Завдання 2 (Варіант 14): Обчислити суму ряду та вивести непарні елементи
void task2() {
    double x;
    cout << "Введіть значення x: ";
    cin >> x;

    double sum = x;  // Початкове значення суми
    double xs = x;
    
    cout << "Ряд: ";
    for (int j = 1; j <= 10; j++) {  // Пример для 10 елементів
        xs = xs / x;  // Обчислення елементу ряду
        sum += xs;
        
        // Виведення непарних елементів
        if (j % 2 != 0) {
            cout << xs << " ";
        }
    }
    cout << endl;
    cout << "Сума ряду: " << sum << endl;
}

// Завдання 3 (Варіант 13): Дослідження збіжності ряду
void task3() {
    double x, u, sum;
    double epsilon = 1e-5; // Мала величина для перевірки збіжності

    cout << "Введіть значення x: ";
    cin >> x;

    u = 1 / x;  // Перше значення елементу ряду
    sum = u;

    while (fabs(u) > epsilon) {
        u = u / x;  // Обчислюємо новий елемент
        sum += u;   // Додаємо до суми
    }

    cout << "Сума ряду: " << sum << endl;
}

int main() {
    int menu;
    do 
    { // початок циклу
        cin >> menu; // Вибрати номер завдання
        switch (menu) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case -1: cout << "Вихід з програми." << endl; break;
            default: cout << "Невірний вибір!" << endl; break;
        }
    } while (menu != -1);

    return 0;
}
