#include <iostream>
#include <string>
#include <ctime>
class Book {
private:
    std::string title; // Название книги
    std::string author; // Автор
    int yearPublished; // Год издания
public:
    // Конструктор по умолчанию
    Book() : title("Неизвестно"), author("Неизвестно"), yearPublished(0) {}
    // Конструктор с параметрами
    Book(std::string t, std::string a, int y) : title(t), author(a), yearPublished(y) {}
    // Деструктор
    ~Book() {
        std::cout << "Книга \"" << title << "\" уничтожена." << std::endl;
    }
    // Функция для вычисления, сколько лет книге
    int calculateAge() const {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        return currentYear - yearPublished;
    }

    // Функция для вычисления количества дней, прошедших после года издания книги
    int calculateDaysSincePublished() const {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        int days = (currentYear - yearPublished) * 365; // Примерное количество дней
        return days;
    }

    // Функция формирования строки информации об объекте
    std::string getInfo() const {
        return "Книга: " + title + ", Автор: " + author + ", Год издания: " + std::to_string(yearPublished);
    }
};

int main() {
    // Создание объекта с константными значениями
    Book book1("Война и мир", "Лев Толстой", 1869);

    // Вывод информации о книге и результатов обработки данных
    std::cout << book1.getInfo() << std::endl;
    std::cout << "Книге лет: " << book1.calculateAge() << std::endl;
    std::cout << "Дней после года издания: " << book1.calculateDaysSincePublished() << std::endl;

    // Создание объекта с введенными пользователем значениями
    std::string titleInput;
    std::string authorInput;
    int yearInput;

    std::cout << "Введите название книги: ";
    std::getline(std::cin, titleInput);
    std::cout << "Введите автора книги: ";
    std::getline(std::cin, authorInput);
    std::cout << "Введите год издания книги: ";
    std::cin >> yearInput;
    Book book2(titleInput, authorInput, yearInput);
    // Вывод информации о книге и результатов обработки данных
    std::cout << book2.getInfo() << std::endl;
    std::cout << "Книге лет: " << book2.calculateAge() << std::endl;
    std::cout << "Дней после года издания: " << book2.calculateDaysSincePublished() << std::endl;
    return 0;
}
