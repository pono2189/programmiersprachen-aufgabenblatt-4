#include <iostream>
#include <vector>
#include <list>
#include "stdio.h"
#include <set>
#include <map>
#include <iterator>
#include "circle.hpp"
#include <string>
#include "vec2.hpp"
#include "color.hpp"
#include <algorithm>
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>


//Aufgabe 3.6
TEST_CASE ("aufgabe6","[aufgabe6]") {
    std::string name; 
    Circle c1 = Circle{450.0f,Vec2{200.0f,400.0f},Color{1.0f,0.0f,0.0f},"Circle1"};
    Circle c2 = Circle{100.0f,Vec2{600.0f,400.0f},Color{0.0f,1.0f,0.0f},"Circle2"};
    Circle c3 = Circle{30.0f,Vec2{200.0f,400.0f},Color{0.0f,0.0f,1.0f},"Circle3"};
    Circle c4 = Circle{450.0f,Vec2{200.0f,300.0f},Color{1.0f,1.0f,0.0f},"Circle1"};

    std::vector<Circle> sorted_circles;
    sorted_circles.push_back(c1); 
    sorted_circles.push_back(c2); 
    sorted_circles.push_back(c3); 

    std::sort(sorted_circles.begin(), sorted_circles.end());

    REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}
    TEST_CASE ("aufgabe7","[aufgabe7]") {
        std::vector<Circle> circles_7;

        Circle c1 = Circle{450.0f,Vec2{200.0f,400.0f},Color{1.0f,0.0f,0.0f},"Circle1"};
        Circle c2 = Circle{100.0f,Vec2{600.0f,400.0f},Color{0.0f,1.0f,0.0f},"Circle2"};
        Circle c3 = Circle{30.0f,Vec2{200.0f,400.0f},Color{0.0f,0.0f,1.0f},"Circle3"};
        Circle c4 = Circle{450.0f,Vec2{200.0f,300.0f},Color{1.0f,1.0f,0.0f},"Circle1"};

        
        circles_7.push_back(c1); 
        circles_7.push_back(c2); 
        circles_7.push_back(c3); 
        
        std::sort(circles_7.begin(), circles_7.end(), [] (Circle c1, Circle c2)-> bool {return c1 < c2;});

        REQUIRE(std::is_sorted(circles_7.begin(), circles_7.end()));
    }

   int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}