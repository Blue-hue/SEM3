#include <iostream>
using namespace std;

class MyClass {
public:
    int a;
    mutable int b; 

    MyClass(const int &val1, const int &val2) : a(val1), b(val2) {};

    void set_a(const int &num){
        a = num;
        }

    void set_b(const int &num){
        b = num;
        }

    void display() const{
        //gives error expression must be a modifiable lvalue
        //a+=10;    this is because the function has a 'const' suffix and unable to modify value
        cout << "a : " << a << "\nb : " << b <<  endl;
    }

};

int main() {
    const MyClass obj(42, 23);
    obj.display();

    //gives error expression must be a modifiable lvalue
    //obj.a = 2; 

    //does not give error
    obj.b = 3;

    obj.display();
    return 0;
}