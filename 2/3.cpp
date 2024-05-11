#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
    ifstream inputFile("numbers.txt"); // открываем файл для чтения
    ofstream outputFile("output.txt"); // открываем файл для записи
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening files" << endl;
        return 1;
    }
    double num;
    while (inputFile >> num) {
        if (num > 0) {
            outputFile << sqrt(num) << " "; // заменяем положительные числа квадратными корнями
        } else {
            outputFile << pow(num, 2) << " "; // заменяем отрицательные числа их квадратами
        }
    }
    inputFile.close();
    outputFile.close();
    cout << "Numbers processed and saved to output.txt" << endl;
    return 0;
}
