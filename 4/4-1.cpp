
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
// Описание класса Book
class Book {
public:
    std::string title;
    std::string author;
    int year;
    Book(std::string t, std::string a, int y) : title(t), author(a), year(y) {}
    // Метод для вывода информации о книге
    void printInfo() const {
        std::cout << "Название: " << title << ", Автор: " << author << ", Год издания: " << year << std::endl;
    }
};
// Описание класса HomeLibrary
class HomeLibrary {
private:
    std::vector<Book> books;
public:
    // Добавление книги в библиотеку
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Удаление книги из библиотеки по названию
    void removeBookByTitle(const std::string& title) {
        books.erase(std::remove_if(books.begin(), books.end(), [&title](const Book& book {
            return book.title == title;
        }), books.end());
    }

    // Поиск книги по автору
    void findBooksByAuthor(const std::string& author) const {
        for (const auto& book : books) {
            if (book.author == author) {
                book.printInfo();
            }
        }
    }
    // Сортировка книг по году издания
    void sortBooksByYear() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b {
            return a.year < b.year;
        });
    }

    // Вывод всех книг в библиотеке
    void printAllBooks() const {
        for (const auto& book : books) {
            book.printInfo();
        }
    }
};
// Функция для демонстрации работы класса HomeLibrary
void demonstrateHomeLibrary() {
    HomeLibrary library;

    // Добавление книг
    library.addBook(Book("Война и мир", "Лев Толстой", 1869));
    library.addBook(Book("Преступление и наказание", "Федор Достоевский", 1866));

    // Вывод всех книг
    std::cout << "Все книги в библиотеке:" << std::endl;
    library.printAllBooks();

    // Поиск книги по автору
    std::cout << "\nПоиск книг Льва Толстого:" << std::endl;
    library.findBooksByAuthor("Лев Толстой");

    // Сортировка книг по году издания
    library.sortBooksByYear();

    // Вывод всех книг после сортировки
    std::cout << "\nВсе книги после сортировки по году издания:" << std::endl;
    library.printAllBooks();

    // Удаление книги
    library.removeBookByTitle("Преступление и наказание");

    // Вывод всех книг после удаления
    std::cout << "\nВсе книги после удаления:" << std::endl;
    library.printAllBooks();
}

int main() {
    demonstrateHomeLibrary();
    return 0;
}
