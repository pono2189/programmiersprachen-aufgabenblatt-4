#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"
//#include "window.hpp"
//#include "mat2.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>


class Circle{  
    
    public:
        Circle();
        Circle(float radius_, Vec2 const& center_, Color const& col_, std::string const& name_);
        float const circumference();
        //void const draw(Window const& w);
        //void const draw(Window const& w, float thickness);
        bool const is_inside_(const Vec2& point);
        std::ostream& print(std::ostream & outstream) const;
        //std::string Circle::print()const;
        float get_radius() const;
        std::string get_name() const;
        
    private:
        float radius_;
        Vec2 center_;
        Color col_; 
        std::string name_;
};
std::ostream& operator<<(std::ostream& outstream,const Circle &c_1);
bool operator< (Circle const& c_1, Circle const& c_2);
bool operator> (Circle const& c_1, Circle const& c_2);
bool operator== (Circle const& c_1, Circle const& c_2);
#endif


