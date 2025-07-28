#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool evaluate(string op, int a, int b) {
    if (op == "AND") return a & b;
    else if (op == "OR") return a | b;
    else if (op == "XOR") return a ^ b;
    else if (op == "NAND") return !(a & b);
    else if (op == "NOR") return !(a | b);
    else return false;
}

void generateTruthTable(string gate) {
    transform(gate.begin(), gate.end(), gate.begin(), ::toupper);
    cout << "\nTruth Table for " << gate << ":\n";
    cout << "A | B | Output\n";
    cout << "-------------\n";

    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            cout << a << " | " << b << " |   " << evaluate(gate, a, b) << "\n";
        }
    }
}

int main() {
    string gate;
    cout << "Enter logic gate (AND / OR / XOR / NAND / NOR): ";
    cin >> gate;
    generateTruthTable(gate);
    return 0;
}
