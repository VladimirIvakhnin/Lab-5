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
    int n, variant;
    
    cout << "Введіть значення x: ";
    cin >> x;
    cout << "Введіть кількість елементів n: ";
    cin >> n;
    cout << "Введіть варіант (парний або непарний): ";
    cin >> variant;

    double sum = 0;

    // Обчислення суми
    for (int i = 1; i <= n; ++i) {
        double term = pow(x, 2 * i - 1) / tgamma(i + 3); // (i+2)! = tgamma(i+3)
        sum += term;

        // Виведення кожного 3-го або 4-го елемента залежно від варіанту
        if ((variant % 2 == 0 && i % 3 == 0) || (variant % 2 != 0 && i % 4 == 0)) {
            cout << "Елемент " << i << ": " << term << endl;
        }
    }

    cout << "Загальна сума: " << sum << endl;
}

// Завдання 3 (Варіант 13): Дослідження збіжності ряду
void task3() {
    double sum = 0.0, term;
    double epsilon = 1e-5;  // Мала величина для збіжного ряду
    double g = 1e5;          // Велика величина для розбіжного ряду

    int n = 1;
    double x;

    cout << "Введіть значення x: ";
    cin >> x;

    // Обчислення елементів ряду
    while (true) {
        // Обчислення елементу ряду
        term = (pow(2, 2 * n) * factorial(2 * n - 1)) / sqrt(factorial(n));

        // Перевірка умови збіжності чи розбіжності
        if (fabs(term) < epsilon) {
            break;  // Якщо елемент менший за epsilon, припиняємо для збіжного ряду
        }
        if (fabs(term) > g) {
            cout << "Ряд розбіжний." << endl;
            break;  // Якщо елемент більший за g, припиняємо для розбіжного ряду
        }

        sum += term;
        n++;
    }

    cout << "Загальна сума: " << sum << endl;
}

// Функція для обчислення факторіалу
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    int menu;
    do {
        // Вибір номеру завдання
        cout << "Виберіть завдання (1-3) або -1 для виходу: ";
        cin >> menu;
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
