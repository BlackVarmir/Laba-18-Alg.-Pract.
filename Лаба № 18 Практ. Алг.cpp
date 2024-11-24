#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cctype>
#include <algorithm>

using namespace std;

// Структура для зберігання інформації про студентів
struct Student {
    string surname;
    int history;
    int math;
    int english;
};

// Функція для завдання 1
void saveSessionInfo() {
    vector<Student> students = {
        {"Ivanov", rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1},
        {"Petrenko", rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1},
        {"Shevchenko", rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1},
        {"Tkachenko", rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1}
    };

    ofstream file("students.txt");
    for (const auto& student : students) {
        file << student.surname << " " << student.history << " " << student.math << " " << student.english << endl;
    }
    file.close();

    cout << "Студенти, які склали хоча б один іспит на 'відмінно':\n";
    for (const auto& student : students) {
        if (student.history == 5 || student.math == 5 || student.english == 5) {
            cout << student.surname << endl;
        }
    }
}

// Функція для завдання 2
void findWordsByLength() {
    ifstream file("words.txt");
    if (!file) {
        cerr << "Помилка відкриття файлу words.txt" << endl;
        return;
    }

    int length;
    cout << "Введіть кількість літер: ";
    cin >> length;

    string word;
    cout << "Слова з " << length << " літерами:\n";
    while (file >> word) {
        if (word.length() == length) {
            cout << word << endl;
        }
    }
    file.close();
}

// Функція для завдання 3
void displayWordsByLetterCount() {
    ifstream file("text.txt");
    if (!file) {
        cerr << "Помилка відкриття файлу text.txt" << endl;
        return;
    }

    vector<string> oneLetterWords, otherWords;
    string word;
    while (file >> word) {
        if (word.length() == 1) {
            oneLetterWords.push_back(word);
        }
        else {
            otherWords.push_back(word);
        }
    }
    file.close();

    cout << "Однолітерні слова:\n";
    for (const auto& w : oneLetterWords) {
        cout << w << " ";
    }
    cout << "\nІнші слова:\n";
    for (const auto& w : otherWords) {
        cout << w << " ";
    }
    cout << endl;
}

// Функція для завдання 4
void countLettersInWords() {
    ifstream file("text.txt");
    if (!file) {
        cerr << "Помилка відкриття файлу text.txt" << endl;
        return;
    }

    vector<string> words;
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    file.close();

    ofstream outFile("text_count.txt");
    for (const auto& w : words) {
        int letterCount = count_if(w.begin(), w.end(), [](char c) { return isalpha(c); });
        outFile << w << "(" << letterCount << ") ";
    }
    outFile.close();

    cout << "Кількість літер у кожному слові додано до файлу під назвою text_count." << endl;
}

// Функція для завдання 5
void extractPunctuation() {
    ifstream file("text.txt");
    if (!file) {
        cerr << "Помилка відкриття файлу text.txt" << endl;
        return;
    }

    ofstream outFile("punctuation.txt");
    char ch;
    while (file.get(ch)) {
        if (ispunct(ch)) {
            outFile << ch;
        }
    }
    file.close();
    outFile.close();

    cout << "Знаки пунктуації збережено у файл punctuation.txt" << endl;
}

int main() {
    // Встановлюємо кодову сторінку UTF-8
    system("chcp 65001");

    srand(static_cast<unsigned int>(time(0)));
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Записати інформацію про складання сесії та вивести студентів з відмінними оцінками\n";
        cout << "2. Вивести слова з певною кількістю літер\n";
        cout << "3. Вивести однолітерні слова та інші слова\n";
        cout << "4. Порахувати кількість літер у кожному слові та записати у файл\n";
        cout << "5. Зберегти всі знаки пунктуації у окремий файл\n";
        cout << "0. Вихід\n";
        cout << "Оберіть завдання: ";
        cin >> choice;

        switch (choice) {
        case 1: saveSessionInfo(); break;
        case 2: findWordsByLength(); break;
        case 3: displayWordsByLetterCount(); break;
        case 4: countLettersInWords(); break;
        case 5: extractPunctuation(); break;
        case 0: cout << "Вихід з програми...\n"; break;
        default: cout << "Неправильний вибір. Спробуйте ще раз.\n"; break;
        }
    } while (choice != 0);

    return 0;
}
