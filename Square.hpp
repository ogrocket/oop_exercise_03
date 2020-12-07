#include "Figure.hpp"

class Square : public Figure{
private:
    Point A, B, C, D;
    double side;
    std::string name;
public:
    Square(){
        A = B = C = D = {0, 0};
        side = 0;
        name = "Square";
        std::cout << "Square created\n";
    }

    Square(const Point &_A, const Point &_B, const Point &_C, const Point &_D){
        A = _A, B = _B, C = _C, D = _D;
        side = std::min(A.Lenght(B), A.Lenght(C));
        name = "Square";
        std::cout << "Square created\n";
    }

    Point Center() {
        Point center;
        center.x = (A.x + B.x + C.x + D.x)/4;
        center.y = (A.y + B.y + C.y + D.y)/4;
        return center;
    }

    double Area(){
        return side * side;
    }

    std::ostream &Print(std::ostream &out){
        out << name;
        out << ": { " << A << ", " << B << ", " << C <<", " << D << " }\n";
        return out;
    }

    std::istream &Read(std::istream &in){
        in >> A >> B >> C >> D;
        (*this) = Square(A, B, C, D);
        return in;
    }

    ~Square(){
        std::cout << "Square deleted\n";
    }
};

