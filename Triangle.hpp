#include "Figure.hpp"
#define EPS 0.001

class Triangle : public Figure{
private:
    Point A, B, C;
    std::string name;
public:
    Triangle(){
        A = B = C = {0, 0};
        name = "Triangle";
        std::cout << "Triangle created\n";
    }

    Triangle(const Point &_A, const Point &_B, const Point &_C){
        A = _A, B = _B, C = _C;
        name = "Triangle";
        std::cout << "Triangle created\n";
    }

    ~Triangle(){
        std::cout << "Triangle deleted\n";
    }

    Point Center() {
        Point center;
        center.x = (A.x + B.x + C.x)/3;
        center.y = (A.y + B.y + C.y)/3;
        return center;
    }

    double Area(){
        double a = A.Lenght(B);
        double b = A.Lenght(C);
        double c = B.Lenght(C);

        double p = (a + b + c) / 2;


        return std::sqrt(p * (p-a) * (p-b) * (p-c));
    }

    std::ostream &Print(std::ostream &out){
        out << name;
        out << ": { " << A << ", " << B << ", " << C << " }\n";
        return out;
    }

    std::istream &Read(std::istream &in){
        in >> A >> B >> C;
        if (( std::fabs(A.Lenght(B) - A.Lenght(C)) < EPS) &&
                                (std::fabs(A.Lenght(B) - C.Lenght(B) < EPS)) &&
                                        (std::fabs(A.Lenght(C) - C.Lenght(B) < EPS))){
            (*this) = Triangle(A, B, C);
        }
        else{
            std::cout << "Not regular\n";
        }
        return in;
    }
};

