#include "Figure.hpp"

class Rectangle : public Figure{
private:
    Point A, B, C, D;
    std::string name;
public:
    Rectangle(){
        A = B = C = D = {0, 0};
        name = "Rectangle";
        std::cout << "Rectangle created\n";
    }

    Rectangle(const Point &_A, const Point &_B, const Point &_C, const Point &_D){
        A = _A, B = _B, C = _C, D = _D;
        name = "Rectangle   ";
        std::cout << "Rectangle created\n";
    }

    Point Center() {
        Point center;
        center.x = (A.x + B.x + C.x + D.x)/4;
        center.y = (A.y + B.y + C.y + D.y)/4;
        return center;
    }

    double Area(){
        double a = A.Lenght(B);
        double b = A.Lenght(C);
        double c = A.Lenght(D);

        double p = (a + b + c) / 2;


        return std::sqrt(p * (p-a) * (p-b) * (p-c)) * 2;
    }

    std::ostream &Print(std::ostream &out){
        out << name;
        out << ": { " << A << ", " << B << ", " << C <<", " << D << " }\n";
        return out;
    }

    std::istream &Read(std::istream &in){
        in >> A >> B >> C >> D;
        (*this) = Rectangle(A, B, C, D);
        return in;
    }

    ~Rectangle(){
        std::cout << "Rectangle deleted\n";
    }
};

