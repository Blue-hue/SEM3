#include<iostream>
using namespace std;

class IntArray{
    private:
        int size;
        int* element;
    public:
        IntArray(const IntArray &target):size(target.size){
            element = new int[size];
            for(int i=0;i<size;i++){
                element[i] = target.element[i];
            }
        }

        IntArray(int s,bool empty = false):size(s){
            element = new int[size];
            
            if(!empty){
                cout<<"enter array : ";
                for(int i=0;i<size;i++){
                    cin>>element[i];
                }
            }
            else{
                for(int i=0;i<size;i++){
                    element[i] = 0;
                }
            }
        }

        ~IntArray(){
            delete element;
        }

        IntArray add(IntArray &other){
            if(size==other.size){
                IntArray sum(size,true);
                for(int i=0;i<size;i++){
                    sum.element[i] = element[i]+other.element[i];
                }
                return sum;
            }
            else return IntArray(0);
        }
        
        void reverse(){
            int temp;
            for(int i=0;i<size/2;i++){
                temp = element[i];
                element[i] = element[size - 1 - i];
                element[size - 1 - i] = temp;
            }
        }
        
        void sort(bool ascending = true){
            if(ascending){
                int min = element[0],min_index=0;
                for(int i=0;i<size;i++){
                    min = element[i];
                    min_index=i;
                    for(int j=i;j<size;j++){
                        if(min>element[j]){
                            min = element[j];
                            min_index = j;
                        }
                    }
                    element[min_index] = element[i];
                    element[i] = min;
                }
            }
            else{
                this->sort();
                this->reverse();
            }
        }

        void print(){
            for(int i=0;i<size; i++){
                cout<<element[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    IntArray a(3);
    cout<<"a : ";
    a.print();

    IntArray b(a);
    cout<<"Duplicate of a -> b: ";
    b.print();

    
    cout<<"b is reversed\n";
    b.reverse();

    cout << "a : ";
    a.print();
    cout << "b : ";
    b.print();
}