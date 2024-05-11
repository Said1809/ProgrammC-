#include <iostream>
#include <queue>
#include <string>

// Структура для хранения информации о процессоре
struct Processor {
    std::string name;
    double clockSpeed;
    int numCores;
};

int main() {
    std::queue<Processor> processorQueue;

    // Добавляем информацию о нескольких процессорах в очередь
    processorQueue.push({"Intel i7", 3.4, 8});
    processorQueue.push({"AMD Ryzen 5", 3.2, 6});
    processorQueue.push({"Intel Core 2 Duo", 2.2, 2});

    // Добавляем информацию о новом процессоре в очередь
    Processor newProcessor = {"AMD Ryzen 7", 3.6, 8};
    processorQueue.push(newProcessor);

    // Просмотр данных в очереди и их печать
    while (!processorQueue.empty()) {
        Processor currentProcessor = processorQueue.front();
        std::cout << "Процессор: " << currentProcessor.name << ", Частота: " << currentProcessor.clockSpeed << " GHz, Ядра: " << currentProcessor.numCores << std::endl;
        processorQueue.pop();
    }

    return 0;
}
