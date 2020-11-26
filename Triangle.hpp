#include "Figure.hpp"

class Triangle : public Figure{
public:
    Triangle(){
        vertex.resize(3);
        name = "Triangle";
        std::cout << "Triangle created\n";
    }

    ~Triangle(){
        std::cout << "Triangle deleted\n";
    }

    double Area(){
        double A = vertex[0].Lenght(vertex[1]);
        double B = vertex[0].Lenght(vertex[2]);
        double C = vertex[1].Lenght(vertex[2]);

        double P = (A + B + C)/2;

        return sqrt(P * (P-A) * (P-B) * (P-C));
    }
};
