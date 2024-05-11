#include <iostream>
#include <fstream>
#include <string>
#include <vector>
struct Film {
    std::string title;
    std::string director;
    int year;
    std::string country;
    double cost;
    double revenue;
    double profit;
};
int main() {
    std::vector<Film> films = {
        // Здесь должны быть данные о фильмах
    };
    // Чтение данных из файла
    std::ifstream file("films.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Обработка строки line и заполнение структуры Film
        }
        file.close();
    }

    // Запись данных о фильмах Ежи Гофмана в файл "Кинолента.txt"
    std::ofstream outfile("Кинолента.txt");
    for (const auto& film : films) {
        if (film.director == "Гофман Ежи") {
            outfile << film.title << "; " << film.director << "; " << film.year
                    << "; " << film.country << "; " << film.cost << "; "
                    << film.revenue << "; " << film.profit << std::endl;
        }
    }
    outfile.close();

    return 0;
}
