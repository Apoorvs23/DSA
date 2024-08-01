#include <iostream>
using namespace std;

// Define a simple structure
struct Point {
    int x;
    int y;
};

int main() {
    // Example 1: Using . to access members directly from an object
    Point p1;
    p1.x = 5;
    p1.y = 10;
    cout << "Using . : Point p1 (" << p1.x << ", " << p1.y << ")" << endl;

    // Example 2: Using -> to access members through a pointer
    Point* ptr = new Point();
    ptr->x = 3;
    ptr->y = 7;
    cout << "Using ->: Point ptr (" << ptr->x << ", " << ptr->y << ")" << endl;
    cout << "Equivalent using * and . : Point ptr (" << (*ptr).x << ", " << (*ptr).y << ")" << endl;
    delete ptr; // Free dynamically allocated memory

    return 0;
}
