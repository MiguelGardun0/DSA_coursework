#include <iostream>
#include <vector>

using namespace std;

class Stack{
    public:
    vector<int> values;
    int top=0;
    int bottom=0;
    int pop_value;

    Stack(){

    }
    Stack(vector<int> vectorcito) {
        this->values = vectorcito;
    }

    void push(int value){
        values.resize(top+1);
        values[top] = value;
        top+=1;
    }

    int pop(){
        pop_value = values[top-1];
        values.resize(top-1);
        top-=1;
        return  pop_value;
    }

    void print(){
        for( int i = 0; i < values.size(); i++){
            cout<<values[i]<<endl;
        }
    }
    
    int peek(){
        return values[top-1];
    }
    bool empty(){
        return values.empty();
    }

};


int main(){

    Stack my_stack = Stack();

    bool stop = false;
    int choice;
    int number;

    while (!stop){
        cout<<"Enter the number for your desired function"<<endl
            <<"1.Push"<<endl
            <<"2.Pop"<<endl
            <<"3.Peek"<<endl
            <<"4.Exit"<<endl;
        cin>>choice;
        
        if (choice == 1){
            cout<<"Enter the number: ";
            cin>>number;
            my_stack.push(number);
            continue;

        }

         if (choice == 2){
            if (!my_stack.empty()){
                cout<<my_stack.pop()<<endl;
                continue;
            }
            else{
                cout<<"You have ran out of data";
                break;
            }
                
            
        }

         if (choice == 3){
            cout<<my_stack.peek()<<endl;
            continue;
            
        }

         if (choice == 4){
            stop = true;
            continue;
        }

        else{
            cout<<"Try again, wrong number";
            continue;
        }
        


    }

    return 0;
};