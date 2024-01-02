#include <iostream>

class Vector {
private:
    double x;
    double y;

public:
    //automatically set the vector 0/0 as default
    Vector() : x(0), y(0) {}

//setter and getter
    void setX(double X) {
        x = X;
    }

    int getX() const {
        return x;
    }

    void setY(double Y) {
        y = Y;
    }

    int getY() const {
        return y;
    }

    void display() const {
        std::cout << "(" << x << "; " << y << ")" << std::endl;
    }

    void display2(double x){
        std::cout << x << std::endl;
    }

    //overloaded operators
    Vector operator+(const Vector& other) const {
        Vector result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }

    Vector operator-(const Vector& other) const {
        Vector result;
        result.x = x - other.x;
        result.y = y - other.y;
        return result;
    }

    double operator*(const Vector& other) const {
        double result;
        result = x * other.x +y * other.y;
        return result;
    }

    Vector operator*(const double& other) const {
        Vector result;
        result.x = x * other;
        result.y = y * other;
        return result;
    }
};

int main() {
    Vector vector1, vector2;
    double x1, y1, x2, y2, k;

    std::cout << "Enter x1: ";
    std::cin >> x1;
    vector1.setX(x1);

    std::cout << "Enter y1: ";
    std::cin >> y1;
    vector1.setY(y1);

    std::cout << "Enter x2: ";
    std::cin >> x2;
    vector2.setX(x2);

    std::cout << "Enter y2: ";
    std::cin >> y2;
    vector2.setY(y2);

    std::cout << "Enter k: ";
    std::cin >> k;

    std::cout << "First vector: ";
    vector1.display();

    std::cout << "Second vector: ";
    vector2.display();

    Vector sum = vector1 + vector2;
    Vector difference = vector1 - vector2;
    double product1 = vector1 * vector2;
    Vector product2 = vector1 * k;

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    difference.display();

    std::cout << "Product1: ";
    std::cout << product1 << std::endl;

    std::cout << "Product2: ";
    product2.display();

    return 0;
}