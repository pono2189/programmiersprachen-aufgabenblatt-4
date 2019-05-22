
#include <iostream>
#include "vec2.hpp"
//#include "mat2.hpp"

Vec2& Vec2::operator +=( Vec2 const& v){
    x += v.x;
    y += v.y;
    return *this;
};

Vec2& Vec2::operator -=( Vec2 const& v){
    x -= v.x;
    y -= v.y;
    return *this;
};


Vec2& Vec2::operator *=( float s){
    x *= s;
    y *= s;
    return *this;
};

Vec2& Vec2::operator /=(float s){
    if (s != 0.0f) {
         x /= s;
        y /= s;
        return *this;
    }
    else {
        std::cout << "Error \n";

        return  *this;
    }
};

// 2.4
 Vec2 operator+ (Vec2 const& u , Vec2 const& v){
    Vec2 z = u; //neuer vektor da konstanten!

    z += v;

    return z;
};



Vec2 operator-( Vec2 const& u , Vec2 const& v ){
    Vec2 z;
    z.x = u.x;
    z.y = u.y;
    z.x -= v.x;
    z.y -= v.y;

    return z;
};

Vec2 operator*( Vec2 const& v , float s ){
    Vec2 z;
    z.x = v.x; 
    z.y = v.y;
    z.x *= s;
    z.y *= s;
   

    return z;
};

Vec2 operator /( Vec2 const& v , float s ){
    if (s == 0.0f){
  
        return v;
    }
    else {  
        Vec2 z;  
        z.x = v.x;
        z.x /= s;
        z.y = v.y;
        z.y /= s; 
        return z;
    }
};

Vec2 operator *( float s , Vec2 const& v ){
    Vec2 z;
    z.x = v.x * s;
    z.y = v.y * s;
    return z;
};





