#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include "stdio.h"
//#include <bits/stdc++.h>



TEST_CASE("Aufgabe12", "[Aufgabe12]"){

    std::vector<int> v_1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v_2{9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> v_3(9);


    std::transform(v_1.begin(), v_1.end(), v_2.begin(),v_3.begin(),[](int i, int j) {return i+j;}); //zählt v1 und v2 zusammmen und speichert das ergebnis in v3 

    std::copy(std::begin(v_3), std::end(v_3), std::ostream_iterator<int>(std::cout, "\n")); // gibt v_3 aus
    /*for (std::vector<int>::iterator it1 = v_1.begin() ; it1 != v_1.end(); ++it1){
        for (std::vector<int>::iterator it2 = v_2.begin() ; it2 != v_2.end(); ++it2){
            sum = *it1 + *it2;
            v_3.push_back(sum);
        }
    }*/
    //std::sort(circles_7.begin(), circles_7.end(), [] (Circle c1, Circle c2)-> bool {return c1 < c2;});
    //std::all_of(v_3.begin(), v_3.end(), [](int)-> {return int});
    REQUIRE(std::all_of(v_3.begin(), v_3.end(), [] (int i) -> bool {return i == 10;})); 


}



int main(int argc, char* argv[]){
    return Catch::Session().run(argc, argv);
}