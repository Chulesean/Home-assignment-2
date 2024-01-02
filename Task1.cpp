#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

//find GCD to simplify all fractions
    int GCD(int a, int b) const {
        return b == 0 ? a : GCD(b, a % b);
    }

    void simplify() {
        int gcd = GCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    //automatically set the farction 0/1 as default
    Fraction() : numerator(0), denominator(1) {}

//setter and getter
    void setNumerator(int num) {
        numerator = num;
        simplify();
    }

    int getNumerator() const {
        return numerator;
    }

    void setDenominator(int denom) {
        if (denom == 0) {
            std::cerr << "Error" << std::endl;
            exit(1);
        }

        denominator = denom;
        simplify();
    }

    int getDenominator() const {
        return denominator;
    }

    void display() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

//double
    double toDouble() const {
        return static_cast<double>(numerator) / static_cast<double>(denominator);
    }

    //overloaded operators
    Fraction operator+(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction operator-(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction operator*(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction operator/(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        result.simplify();
        return result;
    }
};

int main() {
    Fraction fraction1, fraction2;

    int num1, denom1, num2, denom2;

    std::cout << "Enter the numerator 1: ";
    std::cin >> num1;
    fraction1.setNumerator(num1);

    std::cout << "Enter the denominator 1: ";
    std::cin >> denom1;
    fraction1.setDenominator(denom1);

    std::cout << "Enter the numerator 2: ";
    std::cin >> num2;
    fraction2.setNumerator(num2);

    std::cout << "Enter the denominator 2: ";
    std::cin >> denom2;
    fraction2.setDenominator(denom2);

    std::cout << "First fraction: ";
    fraction1.display();

    std::cout << "Second fraction: ";
    fraction2.display();

    std::cout << "Fraction 1 as double: " << fraction1.toDouble() << std::endl;

    std::cout << "Fraction 2 as double: " << fraction2.toDouble() << std::endl;

    Fraction sum = fraction1 + fraction2;
    Fraction difference = fraction1 - fraction2;
    Fraction product = fraction1 * fraction2;
    Fraction quotient = fraction1 / fraction2;

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    difference.display();

    std::cout << "Product: ";
    product.display();

    std::cout << "Quotient: ";
    quotient.display();

    return 0;
}