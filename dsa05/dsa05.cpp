

//Miguel Angel Garduño Manrique A01668481

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input_file;
    cout<<"Enter the input file name: ";
    cin>>input_file;
    ifstream inputFile(input_file);
    if (!inputFile) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        if (!line.empty()) lines.push_back(line);
    }

    int x;
    stringstream(lines.back()) >> x;
    string allNumbers;
    for (size_t i = 0; i < lines.size() - 1; ++i) {
        allNumbers += lines[i];
        if (i != lines.size() - 2) allNumbers += " ";
    }

    if (!allNumbers.empty() && allNumbers.front() == '(') allNumbers = allNumbers.substr(1);
    if (!allNumbers.empty() && allNumbers.back() == ')') allNumbers.pop_back();

    stringstream ss(allNumbers);
    int L[10000];
    int i = 0, num;
    char c;
    while (ss >> num) {
        L[i++] = num;
        ss >> c;
    }
    int M = i;
    int left = 0, right = M - 1, result = -1;
    while (left <= right) {
        int middle = (right + left) / 2;
        if (x == L[middle]) {
            result = middle;
            break;
        } else if (x > L[middle]) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    cout << "x is located in index: " << result << endl;
    return 0;
}
