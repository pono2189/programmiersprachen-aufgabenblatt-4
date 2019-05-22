#include <iostream>
#include <list>
#include "stdio.h"
#include <set>
#include <map>
#include <iterator>
#include "circle.hpp"
#include <string>
#include <vector>
#include "vec2.hpp"
#include "color.hpp"
#include <algorithm>



//Aufgabe 3.4

    std::string name; 
    Circle a = Circle{450.0f,Vec2{200.0f,400.0f},Color{1.0f,0.0f,0.0f},"a"};
    Circle b = Circle{100.0f,Vec2{600.0f,400.0f},Color{0.0f,1.0f,0.0f},"b"};
    Circle c = Circle{30.0f,Vec2{200.0f,400.0f},Color{0.0f,0.0f,1.0f},"c"};
    Circle d = Circle{450.0f,Vec2{200.0f,300.0f},Color{1.0f,1.0f,0.0f},"d"};

    std::set<Circle> circles;
        circles.insert(a);
        circles.insert(b);
        circles.insert(c);
        circles.insert(d);
    
    //std::cout << "Please enter the name of your circle: \n";
    //std::cin >> name ; 
   
    for(auto it1 = circles.begin(); it1 != circles.end(); it1++ ){
        if((*it1).get_name().compare(name)== 0){
            std::cout << *it1;
        }
    }

