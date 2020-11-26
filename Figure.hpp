#pragma once
#include "Point.hpp"
#include <iostream>
#include <vector>

class Figure{
protected:
    std::vector<Point> vertex;
    std::string name;

public:
    Figure(){
        std::cout << "Figure created\n";
        name =  "None";
    }

    virtual ~Figure(){
        std::cout << "Figure deleted\n";
    }

    virtual double Area() = 0;

    Point Center(){
        double x_c = 0, y_c = 0;
        for(int i = 0; i < vertex.size(); i++){
            y_c += vertex[i].y;
            x_c += vertex[i].x;
        }
        x_c /= vertex.size();
        y_c /= vertex.size();
        return Point(x_c, y_c);
    }

    void Insert(int i, Point &p){
        vertex[i] = p;
    }

    friend std::ostream &operator<<(std::ostream &out, Figure &f);

    friend std::istream &operator>>(std::istream &in, Figure &f);
};

std::ostream &operator<<(std::ostream &out, Figure &f) {
    out << f.name << " { ";
    for (int i = 0; i < f.vertex.size(); i++){
        out << f.vertex[i] << " ";
    }
    out << "}";
    return out;
}

std::istream &operator>>(std::istream &in, Figure &f) {
    for (int i = 0; i < f.vertex.size(); i++){
        in >> f.vertex[i];
    }
    return in;
}
