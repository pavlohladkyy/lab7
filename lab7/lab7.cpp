#include <iostream>
#include <set>
#include <cstdlib> 
#include <ctime>   
#include<Windows.h>
using namespace std;

class RandomMultiset {
private:
    multiset<int> myMultiset;

public:
    // Конструктор класу, який заповнює множину випадковими числами
    RandomMultiset(int size) {
        srand(static_cast<unsigned int>(time(0)));  
        generateRandomNumbers(size);
    }

    // Метод для генерації та заповнення випадковими числами
    void generateRandomNumbers(int size) {
        for (int i = 0; i < size; ++i) {
            myMultiset.insert(rand() % 21);
        }
    }

    // Метод для виведення елементів множини за допомогою ітераторів
    void printSetElements() const {
        for (auto i = myMultiset.begin(); i != myMultiset.end(); ++i) {
            cout << *i << endl;
        }
    }

    // Метод для виведення кількості повторень кожного елемента множини за допомогою ітераторів
    void printOccurrences() const {
        for (auto i = myMultiset.begin(); i != myMultiset.end(); ++i) {
            int count = myMultiset.count(*i);
            cout << "Елемент " << *i << " повторюється " << count << " разів" << endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "введіть кількість елементів:";
    cin >> n;
    RandomMultiset randomMultiset(n);

    // Виводимо елементи множини за допомогою ітераторів
    cout << "Елементи множини:" << endl;
    randomMultiset.printSetElements();

    // Виводимо кількість повторень кожного елемента множини за допомогою ітераторів
    cout << "\nКількість повторень кожного елемента:" << endl;
    randomMultiset.printOccurrences();

    return 0;
}
