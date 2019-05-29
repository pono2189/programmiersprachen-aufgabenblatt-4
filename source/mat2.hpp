#ifndef MAT2_HPP
#define MAT2_HPP
#include <array>


struct Mat2 {

    float e_00 = 1.0f;
    float e_01 = 0.0f;
    float e_10 = 0.0f;
    float e_11 = 1.0f;

    float det() const;
// Aufgabe 2.5

    Mat2& operator *=( Mat2 const& m );
};

Mat2 operator *(Mat2 const& m1 , Mat2 const& m2 );

// Aufgabe 2.6


Mat2 inverse ( Mat2 const& m );
Mat2 transpose ( Mat2 const& m );
Mat2 make_rotation_mat2 ( float phi );

#endif