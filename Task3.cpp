#include <iostream>
#include <cmath>

//Abstract class
class Figure{
public:
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
    virtual void display(){}
};

//Derived class: triangle
class Triangle:public Figure{
private:
    double s1, s2, s3;

public:
    Triangle(){}  
    Triangle(double S1, double S2, double S3){
        s1 = S1;
        s2 = S2;
        s3 = S3;
    }

//getter and setter
    double getS1(){
        return s1;
    }

    double getS2(){
        return s2;
    }

    double getS3(){
        return s3;
    }

    void setS1(double s1){
        this->s1=s1;
    }

    void setS2(double s2){
        this->s2=s2;
    }

    void setS3(double s3){
        this->s3=s3;
    }

    double Perimeter(){
        return s1+s2+s3;
    }

    double Area(){
        double p = (s1+s2+s3)/2.0;
        return sqrt(p * ( p - s1 ) * ( p - s2 ) * ( p - s3 ));
    }

//Function display
    void display(){
        std:: cout << "Perimeter of triangle: " << Perimeter() << std:: endl;
        std:: cout << "Area of triangle: " << Area() << std:: endl;
    }
};

//Derived class: rectangle
class Rectangle:public Figure{
private:
    double length, width;

public:
    Rectangle(){}
    Rectangle(double length, double width){
        this->length = length;
        this->width = width;
    }

//getter and setter
    double getLength(){
        return length;
    }

    double getWidth(){
        return width;
    }

    void setLength(double Length){
        length = Length;
    }

    void setWidth(double Width){
        width = Width;
    }

    double Perimeter(){
        return (length + width) * 2.0;
    }

    double Area(){
        return length * width;
    }

//Function display
    void display(){
        std:: cout << "Perimeter of rectangle: " << Perimeter() << std:: endl;
        std:: cout << "Area of rectangle: " << Area() << std:: endl;
    }
};

//Derived class: circle
class Circle:public Figure{
private:
    double r;
public:
    Circle(){}
    Circle(double r){
        this->r = r;
    }

//getter and setter
    double getRadius(){
        return r;
    }

    void setRadius(double R){
        r = R;
    }

    double Perimeter(){
        return 3.14 * r * 2.0;
    }

    double Area(){
        return 3.14 * r * r;
    }

//Function display
    void display(){
        std:: cout << "Perimeter of circle: " << Perimeter() << std:: endl;
        std:: cout << "Area of circle: " << Area() << std:: endl;
    }
};

int main(){
    Triangle triangle(3.0, 4.0, 5.0);
    Rectangle rectangle(2.0 , 1.0);
    Circle circle(4.0);

    triangle.display();
    rectangle.display();
    circle.display();
}
