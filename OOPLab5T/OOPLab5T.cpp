#include <iostream>

using namespace std;

class Quadrilateral {
protected:
    double side1, side2; // сторони чотирикутника

public:
    // Конструктор
    Quadrilateral(double s1, double s2) : side1(s1), side2(s2) {}

    // Віртуальний деструктор
    virtual ~Quadrilateral() {}

    // Чисто віртуальні функції для обчислення площі та периметра
    virtual double getArea() const = 0;

    virtual double getPerimeter() const = 0;

    // Віртуальна функція для виведення інформації про чотирикутник
    virtual void print() const {
        cout << "Quadrilateral with sides: " << side1 << ", " << side2 << endl;
    }
};

class Rectangle : public Quadrilateral {
public:
    // Конструктор прямокутника
    Rectangle(double width, double height) : Quadrilateral(width, height) {}

    // Деструктор
    ~Rectangle() {}

    // Обчислення площі прямокутника
    double getArea() const override {
        return side1 * side2;
    }

    // Обчислення периметра прямокутника
    double getPerimeter() const override {
        return 2 * (side1 + side2);
    }

    // Функція для виведення інформації про прямокутник
    void print() const override {
        cout << "Rectangle with width " << side1 << " and height " << side2 << endl;
    }
};

class Square : public Rectangle {
public:
    // Конструктор квадрата
    Square(double side) : Rectangle(side, side) {}

    // Деструктор
    ~Square() {}

    // Функція для виведення інформації про квадрат
    void print() const override {
        cout << "Square with side " << side1 << endl;
    }
};

int main() {
    // Створення об'єктів різних типів чотирикутників
    Quadrilateral* quad1 = new Rectangle(4, 5);
    Quadrilateral* quad2 = new Square(3);

    // Виведення інформації про перший чотирикутник
    cout << "Quadrilateral 1" << endl;
    quad1->print();
    cout << "Area: " << quad1->getArea() << ", Perimeter: " << quad1->getPerimeter() << endl;

    // Виведення інформації про другий чотирикутник
    cout << "Quadrilateral 2" << endl;
    quad2->print();
    cout << "Area: " << quad2->getArea() << ", Perimeter: " << quad2->getPerimeter() << endl;

    delete quad1;
    delete quad2;

    return 0;
}
