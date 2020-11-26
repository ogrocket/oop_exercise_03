#include <iostream>
#include <vector>

#include "Triangle.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"

void PrintMenu();

int main(){
    std::vector<Figure *> figures;
    int i, variant;

    do {
        PrintMenu();
        std::cin >> variant;
        switch(variant){
            case 1:{
                auto *T = new Triangle;
                std::cout << "Input vertices in format 'x y': ";
                std::cin >> *T;
                std::cout << "Input index : ";
                std::cin >> i;
                if(i > figures.size()){
                    figures.resize(i);
                }
                figures.insert(figures.begin() + i, T);
                break;
            }
            case 2:{
                auto *S = new Square;
                std::cout << "Input vertices in format 'x y': ";
                std::cin >> *S;
                std::cout << "Input index : ";
                std::cin >> i;
                if(i > figures.size()){
                    figures.resize(i);
                }
                figures.insert(figures.begin() + i, S);
                break;
            }
            case 3:{
                auto *R = new Rectangle;
                std::cout << "Input vertices in format 'x y': ";
                std::cin >> *R;
                std::cout << "Input index : ";
                std::cin >> i;
                if(i > figures.size()){
                    figures.resize(i);
                }
                figures.insert(figures.begin() + i, R);
                break;
            }
            case 4:{
                std::cout << "Input index : " ;
                std::cin >> i;
                if (figures.size() < i){
                    std::cout << "There is no element with this index\n";
                    break;
                }
                std::cout << figures[i] -> Center() << "\n";
                break;
            }
            case 5:{
                std::cout << "Input index : " ;
                std::cin >> i;
                if (figures.size() < i){
                    std::cout << "There is no element with this index\n";
                    break;
                }
                std::cout << *figures[i] << "\n";
                break;
            }
            case 6:{
                std::cout << "Input index : " ;
                std::cin >> i;
                if (figures.size() < i){
                    std::cout << "There is no element with this index\n";
                    break;
                }
                std::cout << figures[i] -> Area() << "\n";
                break;
            }
            case 7:{
                double areas = 0;
                for (int i = 0; i < figures.size(); i++) {
                    areas += figures[i] -> Area();
                }
                std::cout << "Summ of all areas = " << areas << "\n";
                break;

            }
            case 8:{
                std::cout << "Input index : " ;
                std::cin >> i;
                if (figures.size() < i){
                    std::cout << "There is no element with this index\n";
                    break;
                }
                figures.erase(figures.begin() + i);
                break;
            }
        }

    }while (variant != 0);
}

void PrintMenu(){
            std::cout<< "What do you want to do?\n";
            std::cout<< "0. Exit\n";
    		std::cout<< "1. Add triangle by index\n";
    		std::cout<< "2. Add square by index\n";
    		std::cout<< "3. Add rectangle by index\n";
    		std::cout<< "4. Print center of figure by index\n";
    		std::cout<< "5. Print points of figure by index\n";
    		std::cout<< "6. Print area of figure by index\n";
    		std::cout<< "7. Sum all areas\n";
    		std::cout<< "8. Delete figure by index\n";
    		std::cout<< "> ";
}
