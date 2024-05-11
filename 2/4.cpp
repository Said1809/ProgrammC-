#include 
using namespace std;
int main() {
ifstream input("numbers.txt");
if (!input) {
cerr << "Error opening file." << endl;
return 1;
}
int num, count = 0;
int pos = 1;
while (input >> num) {
    if (pos % 2 == 0 && num == 0) {
        count++;
    }
    pos++;
}
input.close();
cout << "Number of zero elements at even positions: " << count << endl;
return 0;
}
