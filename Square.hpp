#include "Figure.hpp"

class Square : public Figure{
public:
    Square(){
        vertex.resize(4);
        name = "Square";
        std::cout << "Square created\n";
    }

    ~Square(){
        std::cout << "Square deleted\n";
    }

    double Area(){
        double A = vertex[0].Lenght(vertex[1]);
        double B = vertex[0].Lenght(vertex[2]);
        if (A >= B){
            return B*B;
        }
        else{
            return A*A;
        }
    }
};
