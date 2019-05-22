#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include "stdio.h"

bool is_multiple_of_3(int i){
    if( i % 3 == 0){
        return true;
    }
    else{
        return false;
    }
}

bool is_not_multiple_of_3(int i){
    return !is_multiple_of_3(i);
}

TEST_CASE("filter alle vielfache von drei", "[erase]"){

    std::vector <int> v; 
    for (int i = 0; i < 100; i++){
        v.push_back(rand() % 100);
    } 
   
    v.erase( std::remove_if( v.begin(), v.end(), is_not_multiple_of_3), v.end()); 


    REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3));
}

int main(int argc, char* argv[]){
    return Catch::Session().run(argc, argv);
}