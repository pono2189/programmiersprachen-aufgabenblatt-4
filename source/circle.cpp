#include "circle.hpp"
#include <math.h>
#include <string>
#include "color.hpp"
#include <iostream>

Circle::Circle():
    radius_ {10.0f},
    center_ {1.0f, 1.0f},
    col_ {0.5f, 0.5f, 0.5f},
    name_{"Circle"}
    {};

Circle::Circle(float radius, Vec2 const& center, Color const& col, std::string const& name ):
    radius_ {radius}, 
    center_ {center},
    col_ {col},
    name_ {name}    
    {};

    float Circle::get_radius()const
    {
        return radius_;
    }

    std::string Circle::get_name()const
    {
        return name_;
    }
std::ostream& operator<<(std::ostream & outstream,Circle const& c_1){
    return c_1.print(outstream);
}

std::ostream& Circle::print(std::ostream & outstream)const{
    outstream << "\n Radius: " << radius_ <<"\n Center: " << center_.x << ", " << center_.y << "\n Color: " << col_.r << ", " << col_.b << ", " << col_.b << " \n" ;
    return outstream;
};
//std::string Circle::print()const{
  //  return get_name() << "\n Radius: " << get_radius() <<"\n Center: " << get_center().x << ", " << get_center().y << "\n Color: \n" << get_col().r << ", " << get_col().b << ", " << get_col().b << " \n" ;

//}

//Aufgabe 3.6
bool operator< (Circle const& c_1, Circle const& c_2){
    return c_1.get_radius() < c_2.get_radius();
}
bool operator> (Circle const& c_1, Circle const& c_2){
    return c_1.get_radius() > c_2.get_radius();
}
bool operator== (Circle const& c_1, Circle const& c_2){
    return c_1.get_radius() == c_2.get_radius();
}

float const Circle::circumference(){
    float circum; 
    circum = 2 * radius_ * M_PI; 
    return circum; 
};

/*void const Circle::draw(Window const& w){
    int stepper = 100;
    for (int i = 0; i<= stepper; i++){ 
        Vec2 a = make_rotation_mat2(2*M_PI/stepper*i) * Vec2{radius_, 0.0f} + center_;
        Vec2 b = make_rotation_mat2(2*M_PI/stepper*(i+1)) * Vec2{radius_, 0.0f} + center_;
        w.draw_line (a.x, a.y, b.x, b.y, col_.r, col_.g, col_.b, 1.0f);
    }
}
void const Circle::draw(Window const& w, float thickness){
    int stepper = 100;
    for (int i = 0; i<= stepper; i++){ 
        float a_x = (float) sin((2*M_PI*i)/360) * radius_ + center_.x;
        float a_y = (float)cos((2*M_1_PI*i)/360) * radius_+ center_.y;
        float b_x = (float) sin(2*M_PI*(i+1)/360)*radius_ + center_.x;
        float b_y = (float)cos(2*M_1_PI*(i+1)/360)*radius_+ center_.y;
        Vec2 a = {a_x, a_y} ;
        Vec2 b = {b_x, b_y} ;
        w.draw_line (a.x, a.y, b.x, b.y, col_.r, col_.g, col_.b, thickness);
    }
}

bool const Circle::is_inside_(const Vec2& point){
    Vec2 i = center_ - point;
    float abstand_center_point = sqrt((i.x * i.x) + (i.y * i.y));
    if (abstand_center_point > radius_) {
        return false;
    } 
    else {
        return true;
    }
}*/
