#include "Figure.hpp"

class Rectangle : public Figure{
public:
    Rectangle(){
        vertex.resize(4);
        name = "Rectangle";
        std::cout << "Rectangle created\n";
    }

    ~Rectangle(){
        std::cout << "Rectangle deleted\n";
    }

    double Area(){
        double A = vertex[0].Lenght(vertex[1]);
        double B = vertex[0].Lenght(vertex[2]);
        double C = vertex[1].Lenght(vertex[2]);

        double P = (A + B + C)/2;

        return 2 * sqrt(P * (P-A) * (P-B) * (P-C));
    }
};
