
#include "mat2.hpp"
#include "cmath"


// Aufgabe 2.5
Mat2& Mat2::operator *=( Mat2 const& m ){
    Mat2 const temp{*this};
    e_00 = temp.e_00*m.e_00 + temp.e_01*m.e_10;
    e_01 = temp.e_00*m.e_01 + temp.e_01*m.e_11;
    e_10 = temp.e_10*m.e_00 + temp.e_11*m.e_10;
    e_11 = temp.e_10*m.e_01 + temp.e_11*m.e_11;
    return *this;
};

Mat2 operator *(Mat2 const& m1 , Mat2 const& m2 ){
    Mat2 m0 = m1;
    m0 *= m2;
    return m0;
};


// Aufgabe 2.6
Mat2 inverse (Mat2 const& m){
    Mat2 m_inv;
    float det;
    det = m.e_00*m.e_11 - m.e_01*m.e_10;
    m_inv.e_00 = m.e_11 * (1/det);
    m_inv.e_01 = -m.e_01 * (1/det);
    m_inv.e_10 = -m.e_10 * (1/det);
    m_inv.e_11 = m.e_00 * (1/det);
    return m_inv;
};

Mat2 transpose (Mat2 const& m){
    Mat2 m_trans; 
    m_trans.e_00 = m.e_00;
    m_trans.e_01 = m.e_10;
    m_trans.e_10 = m.e_01;
    m_trans.e_11 = m.e_11;
    return m_trans;
};

Mat2 make_rotation_mat2 (float phi){
    Mat2 rotation;
    rotation.e_00 = cos(phi) ;
    rotation.e_01 = -sin(phi);
    rotation.e_10 = sin(phi);
    rotation.e_11 = cos(phi);
    return rotation;
};

float Mat2:: det() const{
    float determinante; 
    determinante = (e_00*e_11) - (e_01*e_10);
    return determinante;
};


