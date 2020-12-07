#include <iostream>
#include <vector>

#include "Point.hpp"
#include "Triangle.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"

void PrintMenu(){
    std::cout<< "What do you want to do?\n";
    std::cout<< "0. Exit\n";
    std::cout<< "1. Add triangle\n";
    std::cout<< "2. Add square \n";
    std::cout<< "3. Add rectangle\n";
    std::cout<< "4. Print centers of figures \n";
    std::cout<< "5. Print points of figures \n";
    std::cout<< "6. Print area of figures \n";
    std::cout<< "7. Sum all areas\n";
    std::cout<< "8. Delete figure by index\n";
    std::cout<< "> ";
}

int main(){
    std::vector<Figure *> figures;
    int index, variant;
    PrintMenu();
    double Area = 0;

    do{
        std::cin >> variant;
        switch(variant){
            case 1:{
                auto T = new Triangle;
                std::cout << "Input vertices in format 'x y': ";
                std::cin >> *T;
                figures.push_back(T);
                Area += figures.back()->Area();
                break;
            }
            case 2:{
                auto S = new Square;
                std::cout << "Input vertices in format 'x y': ";
                std::cin >> *S;
                figures.push_back(S);
                Area += figures.back()->Area();
                break;
            }

            case 3:{
                auto R = new Rectangle;
                std::cout << "Input vertices in format 'x y': ";
                std::cin >> *R;
                figures.push_back(R);
                Area += figures.back()->Area();
                break;
            }

            case 4:{
                for (int i = 0; i < figures.size(); i++){
                    std::cout << figures[i]->Center() << "\n";
                }
                break;
            }

            case 5:{
                for (int i = 0; i < figures.size(); i++){
                    std::cout << *figures[i] << "\n";
                }
                break;
            }

            case 6:{
                for (int i = 0; i < figures.size(); i++){
                    std::cout << figures[i]->Area() << "\n";
                }
                break;
            }

            case 7:{
                std::cout << Area << "\n";
                break;
            }

            case 8:{
                std::cout << "Input index\n";
                std::cin >> index;
                if (index > figures.size()){
                    std::cout << "Out of range!\n";
                }
                else{
                    Area -= figures[index]->Area();
                    delete figures[index];
                    figures.erase(figures.begin() + index);
                }
                break;

            }
        }

    }while (variant != 0);

    return 0;
}

