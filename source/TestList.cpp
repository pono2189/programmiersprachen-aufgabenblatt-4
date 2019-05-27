#include <iostream>
#include <vector>
#include <list>
#include "stdio.h"
#include "List.hpp"

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>


TEST_CASE("add element with push_front", "[modifiers]"){
    List<int> list;

    list.push_front(42);
    REQUIRE(42 == list.front());
    list.push_front(-11); 
    REQUIRE(-11 == list.front());
    list.push_front(0);   
    REQUIRE(0 == list.front());
}

TEST_CASE("add element with push_back", "[modifiers]"){
    List<int> list;
    
    list.push_back(42);
    REQUIRE(42 == list.back());
    list.push_back(-11); 
    REQUIRE(-11 == list.back());
    list.push_back(0);   
    REQUIRE(0 == list.back());
}

TEST_CASE("remove last element with pop_back", "[modifiers]"){
    List<int> list;
    
    list.push_back(42);
    list.push_back(-11); 
    list.push_back(0);   
    list.pop_back();
    REQUIRE(2 == list.size());
}

TEST_CASE("remove first element with pop_front", "[modifiers]"){
    List<int> list;
    
    list.push_back(42);
    list.push_back(-11); 
    list.push_back(0);   
    list.pop_front();
    REQUIRE(2 == list.size());
}

 int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}