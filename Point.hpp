#pragma once

#include <iostream>
#include <cmath>

class Point{
public:
    double x, y;

    Point (double x, double y){
        this->x = x;
        this->y = y;
    }

    Point(){
        x = 0;
        y = 0;
    }

    double Lenght(Point &p) const{
        return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
    }
};



std::ostream &operator<<(std::ostream &out, Point p){
    out << "(" << p.x << ";" << p.y << ")";
    return out;
}

std::istream &operator>>(std::istream &in, Point &p){
    in >> p.x >> p.y;
    return in;
}
