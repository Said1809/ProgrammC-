#include 
using namespace std;
int main() {
ifstream file1("a1.txt");
ifstream file2("a2.txt");
if (!file1.is_open() || !file2.is_open()) {
    cout << "Error opening files" << endl;
    return 1;
}
double num1, num2;
double product = 1.0;
while (file1 >> num1 && file2 >> num2) {
    if (num1 < 0 && num2 < 0) {
        product *= (num1 * num2);
    }
}
file1.close();
file2.close();
cout << "Product of negative elements in the two files: " << product << endl;
return 0;
}
