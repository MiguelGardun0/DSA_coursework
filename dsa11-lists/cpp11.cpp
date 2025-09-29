#include <iostream>
#include <vector>
using namespace std;

class List{
    public:
        vector<int> L;
        int size = 0;

        List(){

        };

        List(vector<int>vectorcito){
            this->L = vectorcito;

        };

        void insert(int choice, int number, int index=0){
            if (choice == 1){
                L.resize(size + 1);
                for(int i = size; i > 0; i--) {
                    L[i]=L[i-1];
                };
                L[0] = number;
                size += 1;
            }

            else if (choice == 2){
                L.resize(size + 1);
                L[size]=number;
                size += 1;
            }

            else if (choice == 3){
                L.resize(size + 1);
                for(int i = size; i > index; i--) {
                    L[i]=L[i-1];
                };
                L[index] = number;
                size += 1;
            }
        };

        void delete_item(int index){
                L[index] = 0;
                for(int i = index; i < size-1; i++) {
                    L[i]=L[i+1];
                };
                size -= 1;
                L.resize(size);
        };

        void print(){
            for( int i = 0; i < L.size(); i++){
                cout<<L[i]<<endl;
            }
        }

        bool empty(){
            return L.empty();
        }

    };


int main(){
    List my_list = List();

    bool stop = false;
    int choice;
    int choice2;
    int number;
    int index;

    while (!stop){
        cout<<"Enter the number for your desired function"<<endl
            <<"1.Insert"<<endl
            <<"2.Delete"<<endl
            <<"3.Print"<<endl
            <<"4.Exit"<<endl;
        cin>>choice;
        
        if (choice == 1){
            cout<<"Enter the number: ";
            cin>>number;

            cout<<"Enter the number for your desired function"<<endl
            <<"1.Insert at the beginning"<<endl
            <<"2.Insert at the end"<<endl
            <<"3.Insert at an specific index"<<endl;
            cin>>choice2;
            if (choice2 == 3){
                cout<<"Insert the desired index"<<endl;
                cin>>index;
                my_list.insert(choice2,number,index);
                my_list.print();
            }
         
            else if (choice2 == 1 || choice2 == 2){
                my_list.insert(choice2,number);
                my_list.print();
            }

            else {
                cout<<"Invalid Index"<<endl;
            }
            continue;

        }

         if (choice == 2){
            if (!my_list.empty()){
                cout<<"Index to delete: ";
                cin>>index;
                my_list.delete_item(index);
                continue;
            }
            else{
                cout<<"You have ran out of data";
                break;
            }
                
            
        }

         if (choice == 3){
            my_list.print();
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
}