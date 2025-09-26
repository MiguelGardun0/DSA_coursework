/*
    Miguel Angel Garduño Manrique A01668481
    Course: Programming of Basic Data Structures and Algorithms

    Queue implementation from scratch in C++
    This code correctly implements the functionality of a queue using a dynamic array (vector).
    However, it might not be the most efficient solution in terms of Space Complexity


*/

#include <iostream>
#include <vector>

using namespace std;

class Queue{
    public:

        vector<int> values;
        int first = 0;
        int last = 0;
        int dequeue_value;

        Queue(){

        }

        Queue(vector<int> vectorcito) {
            this->values = vectorcito;
        }

        void enqueue(int value){
            values.resize(last+1);
            values[last] = value;
            last +=1;
        }

        int dequeue(){
            dequeue_value = values[first];
            first += 1;
            return dequeue_value;
        }

        int peek(){
            return values[first];
        }
        
        bool empty(){
            return first >= last;
        }

};


int main(){

    Queue my_queue = Queue();

    bool stop = false;
    int choice;
    int number;

    while (!stop){
        cout<<"Enter the number for your desired function"<<endl
            <<"1.Enqueue"<<endl
            <<"2.Dequeue"<<endl
            <<"3.Peek"<<endl
            <<"4.Exit"<<endl;
        cin>>choice;
        
        if (choice == 1){
            cout<<"Enter the number: ";
            cin>>number;
            my_queue.enqueue(number);
            continue;

        }

         if (choice == 2){
            if (!my_queue.empty()){
                cout<<my_queue.dequeue()<<endl;
                continue;
            }
            else{
                cout<<"You have ran out of data";
                break;
            }
                
            
        }

         if (choice == 3){
            cout<<my_queue.peek()<<endl;
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