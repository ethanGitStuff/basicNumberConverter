#include <iostream>
#include <cmath>

using namespace std;

void conversion() {
    string input = "";
    short type = 0;

    int decVar = 0;
    string binVar = "";
    string hexVar = "";

    cout << "Use prefixes - b : d : x" << endl;
    cout << "Choose number to convert: " << endl;
    cin >> input;

    if (input.length() <= 1 || (input[0] != 'b' && input[0] != 'd' && input[0] != 'x')) {
        cout << "Invalid Input" << endl;
        return;
    }

    string operand = input.substr(1, input.length() - 1);

    switch(input[0]) {
        case 'b':
            binVar = operand;
            for (int i = 0; i < operand.length(); ++i) {
                int temp = operand[operand.length() - 1 - i] - '0';
                if (temp != 0) { decVar += pow(2, i * temp); }
            }
            break;
        case 'x':
            for (int i = 0; i < operand.length(); ++i) {
                char currChar = operand[operand.length() - 1 - i];
                switch (currChar) {
                    case 'a':
                }
            }
            break;
        default:
            decVar = stoi(operand);
            break;
    }
    cout << "Decimal: " << dec << decVar << endl;
    cout << "Binary: " << binVar << endl;
    cout << "Hex: " << hex << decVar << endl;
}

int main() {

    short menu = 0;
    while (menu != 4) {
        cout << "Choose Operation: |1) Conversion |2) binVarary Math |4) Exit" << endl;
        cin >> menu;

        switch (menu) {
            case 1: conversion(); break;
            case 4: cout << "Exiting..." << endl; break;
            default: cout << "Invalid Input" << endl;
        }
    }

    return 0;
}