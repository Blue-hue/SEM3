#include<iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int *data;

    public:
       Queue(const int sz) { 
       front = rear = -1; 
       size = sz; 
       data = new int[sz]; 
    }
    void add(const int &elem); 
    int remove(); 
    void display() const; 
}; 
   
void Queue::add(const int &elem) 
{ 
    if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))  { 
        cout << "\nQueue is Full";
    } 
    else if (front == -1) {
         front = rear = 0; 
        data[rear] = elem; 
    } 
   else if (rear == size-1 && front != 0) { 
        rear = 0; 
        data[rear] = elem; 
    } 
    else {  
        rear++; 
        data[rear] = elem; 
    }
}

int Queue::remove() 
{ 
    if (front == -1)  { 
        cout << "\nQueue is Empty"; 
        return -1; 
    }
   
    int val = data[front]; 
    data[front] = -1; 
    if (front == rear)  { 
        front = -1; 
        rear = -1; 
    } 
    else if (front == size-1) 
        front = 0; 
    else
        front++; 
   
    return val; 
} 
 
void Queue::display() const{ 
    if (front == -1) { 
        cout << "\nQueue is Empty" << endl;  
    }
    else{
    cout << "\nCircular Queue elements: "; 
    if (rear >= front) { 
        for (int i = front; i <= rear; i++) 
            cout<<data[i]<<" "; 
    } 
    else  { 
        for (int i = front; i < size; i++) 
            cout<<data[i]<<" "; 
   
        for (int i = 0; i <= rear; i++) 
            cout<<data[i]<<" "; 
    } 
}
};

int main(){
	Queue a(10);
	a.add(2);
	a.add(3);
	a.add(4);
	a.add(5);
	a.display();
	cout<<"Removed element 1: "<<a.remove();
	cout<<"Removed element 2: "<<a.remove();
	
	cout<<"\nQueue : ";
	a.display();
}