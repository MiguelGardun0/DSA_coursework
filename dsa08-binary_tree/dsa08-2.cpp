#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    int value;
    int left;
    int right;
    
    TreeNode(int val) : value(val), left(-1), right(-1) {}
};

class BinaryTree {
private:
    vector<TreeNode> nodes;
    int root;
    
public:
    BinaryTree() : root(-1) {}
    
    void insert(int value) {
        TreeNode newNode(value);
        
        if (root == -1) {
            nodes.push_back(newNode);
            root = 0;
            return;
        }
        
        int current = root;
        while (true) {
            if (value < nodes[current].value) {
                if (nodes[current].left == -1) {
                    nodes.push_back(newNode);
                    nodes[current].left = nodes.size() - 1;
                    return;
                }
                current = nodes[current].left;
            } else {
                if (nodes[current].right == -1) {
                    nodes.push_back(newNode);
                    nodes[current].right = nodes.size() - 1;
                    return;
                }
                current = nodes[current].right;
            }
        }
    }
    
    void printVector() {
        cout << "Binary Search Tree as Vector:" << endl;
        cout << "Index | Value | Left | Right" << endl;
        cout << "------|-------|------|------" << endl;
        
        for (int i = 0; i < nodes.size(); i++) {
            cout << i << "     | " 
                 << nodes[i].value << "   | " 
                 << nodes[i].left << "    | " 
                 << nodes[i].right << endl;
        }
    }
};

vector<int> readFile(string filename) {
    vector<int> numbers;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: No se pudo abrir el archivo" << endl;
        return numbers;
    }
    
    string line;
    getline(file, line);
    
    stringstream ss(line);
    string num;
    
    while (getline(ss, num, ',')) {
        numbers.push_back(stoi(num));
    }
    
    file.close();
    return numbers;
}

int main() {
    vector<int> numbers = readFile("number-list-binary-tree.txt");
    
    if (numbers.empty()) {
        return 1;
    }
    
    BinaryTree tree;
    
    for (int num : numbers) {
        tree.insert(num);
    }
    
    tree.printVector();
    
    return 0;
}