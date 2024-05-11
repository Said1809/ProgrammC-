#include <iostream>
#include <cmath> // Для использования функции sqrt()
class NumberPair {
private:
    double number1; // Поле 1
    double number2; // Поле 2
public:
    // Конструктор для инициализации объекта
    NumberPair(double n1, double n2) : number1(n1), number2(n2) {}
    // Функция формирования строки с информацией об объекте
    std::string getInfo() const {
        return "Number 1: " + std::to_string(number1) + ", Number 2: " + std::to_string(number2);
    }
    // Функция обработки значений полей по индивидуальному варианту
    double calculateSqrtOfProduct() const {
        return std::sqrt(number1 * number2);
    }
};
int main() {
    // Создание объекта класса NumberPair
    NumberPair pair(3.0, 4.0);
    // Вывод информации об объекте
    std::cout << pair.getInfo() << std::endl;
    // Вычисление и вывод квадратного корня из произведения чисел
    std::cout << "Квадратный корень из произведения чисел: " << pair.calculateSqrtOfProduct() << std::endl;
    return 0;
}
