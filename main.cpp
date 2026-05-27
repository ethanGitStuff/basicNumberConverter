#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>

using namespace std;

vector<bool> intToBinary(int val) {
    int curr = val;
    int result = val;
    bool remainder = 0;

    vector<bool> bits;

    while (result != 0) {
        remainder = curr % 2;
        result = curr / 2;
        bits.insert(bits.begin(), remainder);
        curr = result;
    }

    while (bits.size() % 4 != 0) {
        bits.insert(bits.begin(), 0);
    }
    return bits;
}

void printResults(int val) {
    vector<bool> bits = intToBinary(val);
    cout << "Binary: ";
    for (bool b : bits) {
        cout << b;
    }
    cout << endl;
    cout << "Decimal: " << dec << val << endl;
    cout << "Hex: " << hex << val << endl;
}

void conversion() {
    string input = "";
    char numberType;
    int decVar;
    int binVar = 0;
    int hexVar = 0;

    cout << "Use prefix \'b\' for binary input and \'x\' for hex." << endl;
    cout << "Input number to convert: " << endl;
    cin >> input;

    numberType = input[0];
    if (isdigit(numberType)) {
        decVar = stoi(input);
        printResults(decVar);
    }
    else if (numberType == 'b') {
        input = input.substr(1, string::npos);
        while (input.length()) {
            if (input[0] != '1' && input[0] != '0') { cout << "Invalid Input - Try Again" << endl; return; }

            binVar += (input[0] - '0') * pow(2, input.length() - 1);
            input = input.substr(1, string::npos);
        }
        printResults(binVar);
    }
    else if (numberType == 'x') {
        input = input.substr(1, string::npos);
        while (input.length()) {
            if (isdigit(input[0])) {
                hexVar += input[0] - '0';
            }
            else if (input[0] >= 97 && input[0] <= 102) {
                hexVar += input[0] - 87;
            }
            else if (input[0] >= 65 && input[0] <= 70) {
                hexVar += input[0] - 55;
            }
            else {
                cout << "Invalid input - Try Again" << endl;
                return;
            }
            input = input.substr(1, string::npos);
        }
    }
    printResults(hexVar);
}

int main() {

    short menu = 0;
    while (menu != 4) {
        cout << "Choose Operation: |1) Conversion |2) Binary Math |4) Exit" << endl;
        cin >> menu;

        switch (menu) {
            case 1: conversion(); break;
            case 4: cout << "Exiting..." << endl; break;
            default: cout << "Invalid Input" << endl;
        }
    }

    return 0;
}
