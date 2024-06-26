int main() {
std::queue<int> myQueue;
// Добавляем элементы в очередь
myQueue.push(5);
myQueue.push(10);
myQueue.push(7);
myQueue.push(3);
myQueue.push(15);

// Определяем количество элементов очереди меньших 10
int count = 0;
std::queue<int> tempQueue = myQueue;
while (!tempQueue.empty()) {
    if (tempQueue.front() < 10) {
        count++;
    }
    tempQueue.pop();
}

std::cout << "Количество элементов очереди меньших 10: " << count << std::endl;

// Проход по очереди и вывод данных
while (!myQueue.empty()) {
    std::cout << myQueue.front() << " ";
    myQueue.pop();
}

return 0;
