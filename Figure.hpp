#pragma once
#include "Point.hpp"

class Figure{
public:
    Figure(){}

    virtual ~Figure(){}

    virtual double Area() = 0;
    virtual Point Center() = 0;
    virtual std::ostream &Print(std::ostream &out) = 0;
    virtual std::istream &Read(std::istream &in) = 0;
};



std::ostream &operator<<(std::ostream &out, Figure &f){
    return f.Print(out);
}

std::istream &operator>>(std::istream &in, Figure &f){
    return f.Read(in);
}

