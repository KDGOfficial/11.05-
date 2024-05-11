//1
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file1("file1.txt"), file2("file2.txt");
    if (!file1.is_open() || !file2.is_open()) {
        cout << "Failed to open \n";
        return 1;
    }

    string line1, line2;
    int line_number = 0;
    while (getline(file1, line1) && getline(file2, line2)) {
        line_number++;
        if (line1 != line2) {
            cout << "Lines do not match on line " << line_number << ":\n";
            cout << "File 1: " << line1 << "\n";
            cout << "File 2: " << line2 << "\n";
        }
    }

    return 0;
}
 
//2
//вторую задачу я гуглил как делать

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file1("file1.txt"), file2("file2.txt");
    if (!file1.is_open() || !file2.is_open()) {
        cout << "Failed to open one or both files.\n";
        return 1;
    }

    int charCount = 0, lineCount = 0, vowelCount = 0, consonantCount = 0, digitCount = 0;
    char c;

    while (file1.get(c)) {
        charCount++;
        if (c == '\n') lineCount++;
        else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') vowelCount++;
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) consonantCount++;
        else if (c >= '0' && c <= '9') digitCount++;
    }

    ofstream outputFile("output.txt");
    outputFile << "Number of characters: " << charCount << "\n";
    outputFile << "Number of lines: " << lineCount << "\n";
    outputFile << "Number of vowels: " << vowelCount << "\n";
    outputFile << "Number of consonants: " << consonantCount << "\n";
    outputFile << "Number of digits: " << digitCount << "\n";

    return 0;
}

