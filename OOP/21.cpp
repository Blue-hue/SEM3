#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    int size;
    double* element;
    double magnitude;

    void updatemagnitude() {
        for (int i = 0; i < size; i++) {
            magnitude += element[i] * element[i];
        }
        magnitude = sqrt(magnitude);
    }

public:
    Vector(const int &s, bool empty = false) : size(s) {
        element = new double[size];
        if (!empty) {
            cout << " vector : ";
            for (int i = 0; i < size; i++) {
                cin >> *(element + i);
            }
        } else {
            for (int i = 0; i < size; i++) {
                *(element + i) = 0;
            }
        }
        updatemagnitude();
    }

    Vector(const Vector& target) : size(target.size) {
        element = new double[size];
        for (int i = 0; i < size; i++) {
            *(element + i) = *(target.element + i);
        }
        magnitude = target.magnitude;
    }

    ~Vector() {
        delete[] element;
    }

    Vector add(const Vector& other) const {
        if (size == other.size) {
            Vector result(size, true);
            for (int i = 0; i < size; i++) {
                result.element[i] = element[i] + other.element[i];
            }
            result.updatemagnitude();
            return result;
        } else {
            return Vector(0);
        }
    }

    Vector subtract(const Vector& other) const {
        if (size == other.size) {
            Vector result(size, true);
            for (int i = 0; i < size; i++) {
                result.element[i] = element[i] - other.element[i];
            }
            result.updatemagnitude();
            return result;
        } else {
            return Vector(0);
        }
    }

    bool isEqual(const Vector& other) const {
        if (size == other.size) {
            for (int i = 0; i < size; i++) {
                if (element[i] != other.element[i]) {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool isGreater(const Vector& other) const {
        return magnitude > other.magnitude;
    }

    bool isLess(const Vector& other) const {
        return magnitude < other.magnitude;
    }

    void print_Vector() {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << element[i] << " ";
        }
        cout << "]\n";
    }
};

int main() {
    int n;
    cout << "Enter dimension of vector : ";
    cin >> n;
    cout << "First";
    Vector a(n);
    cout << "Second";
    Vector b(n);

    Vector sum = a.add(b);
    Vector diff = a.subtract(b);

    cout << "sum : ";
    sum.print_Vector();
    cout << "diff: ";
    diff.print_Vector();

    cout << "a equal to b ? " << a.isEqual(b);
    cout << "\na greater than b ? " << a.isGreater(b);
    cout << "\na less than b ? " << a.isLess(b);

    return 0;
}