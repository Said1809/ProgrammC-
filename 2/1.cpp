#include 
int main() {
stdifstream input(a.txt);
stdofstream output(b.txt);
if (!input.is_open()) {
    stdcout  Error opening input file  stdendl;
    return 1;
}
if (!output.is_open()) {
    stdcout  Error opening output file  stdendl;
    return 1;
}
double num;

while (input  num) {
    if (num  0) {
        output  num  stdendl;
    }
}
input.close();
output.close();
return 0;
}
