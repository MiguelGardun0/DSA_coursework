#include <iostream>
using namespace std;

int main(){
    int first_array[] = {1, 3, 5, 7, 8, 28, 32, 2};
    int len = sizeof(first_array) / sizeof(first_array[0]);
    int binary_tree[len];

    binary_tree[0]=first_array[0];
    cout<<binary_tree[1];
    
        
    return 0;
};
