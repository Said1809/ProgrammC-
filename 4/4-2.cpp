#include <iostream>
#include <cstring>
#include <vector>

// Базовый класс СТРОКА
class String {
protected:
    char* data;
    int length;

public:
    // Конструктор без параметров
    String() : data(nullptr), length(0) {}

    // Конструктор, принимающий C-строку
    String(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Конструктор, принимающий символ
    String(char c) {
        length = 1;
        data = new char[2];
        data[0] = c;
        data[1] = '\0';
    }

    // Конструктор копирования
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Получение длины строки
    int getLength() const {
        return length;
    }

    // Очистка строки
    void clear() {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    // Деструктор
    virtual ~String() {
        delete[] data;
    }
};

// Производный класс БИТОВАЯ_СТРОКА
class BitString : public String {
public:
    // Конструктор без параметров
    BitString() : String() {}

    // Конструктор, принимающий C-строку
    BitString(const char* str) : String() {
        bool isValid = true;
        for (size_t i = 0; str[i] != '\0'; ++i) {
            if (str[i] != '0' && str[i] != '1') {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        }
    }

    // Конструктор копирования
    BitString(const BitString& other) : String(other) {}

    // Деструктор
    ~BitString() {}

    // Изменение знака на противоположный
    void negate() {
        // Реализация перевода числа в дополнительный код
    }

    // Переопределение оператора присваивания
    BitString& operator=(const BitString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    // Переопределение оператора сложения
    BitString operator+(const BitString& other) const {
        // Реализация арифметической суммы строк
    }

    // Переопределение оператора равенства
    bool operator==(const BitString& other) const {
        return std::strcmp(data, other.data) == 0;
    }
};

// Тестовая программа
int main() {
    // Создание и тестирование объектов
    // ...

    return 0;
}
