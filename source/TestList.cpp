#include <iostream>
#include <vector>
#include <list>
#include "stdio.h"
#include "List.hpp"
#include "circle.hpp"

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>


TEST_CASE("show first element with front", "[modifiers]"){
    List<int> list;

    list.push_front(42);
    REQUIRE(42 == list.front());
    list.push_front(-11); 
    REQUIRE(-11 == list.front());
    list.push_front(0);   
    REQUIRE(0 == list.front());
}

TEST_CASE("add element with push_front", "[modifiers]"){
    List<int> list;

    list.push_front(42);
    REQUIRE(42 == list.front());
    list.push_front(-11); 
    REQUIRE(-11 == list.front());
    list.push_front(0);   
    REQUIRE(0 == list.front());
}

TEST_CASE("show last element with back", "[modifiers]"){
    List<int> list;
    
    list.push_back(42);
    REQUIRE(42 == list.back());
    list.push_back(-11); 
    REQUIRE(-11 == list.back());
    list.push_back(0);   
    REQUIRE(0 == list.back());
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

TEST_CASE("should be empty after clearing", "[modifiers]"){
    List<int> list;
    
    list.push_back(1);
    list.push_back(2); 
    list.push_back(3);   
    list.push_back(4);   
    list.push_back(5);   
    list.clear();
    REQUIRE(list.size() == 0);
}

TEST_CASE("iterators*", "[iterators]"){
    List<int> list;
    list.push_back(1);
    list.push_back(2); 
    list.push_back(3);   
    list.push_back(4);   
    list.push_back(5);   
    auto iterator = list.begin();
    auto value = *(list.begin());
    REQUIRE(value == 1);
    REQUIRE(*(iterator++) == 1);
    REQUIRE(*(++iterator) == 3);
}
TEST_CASE("iterators == !=", "[iterators]"){
    List<int> list;
    list.push_back(1);
    list.push_back(2); 
    list.push_back(3);   
    list.push_back(4);   
    list.push_back(5);   
    auto iterator1 = list.begin();
    auto iterator2 = list.begin();
    auto iterator3 = list.end();
    REQUIRE( iterator1 == iterator2);
    REQUIRE( iterator1 != iterator3);

}

TEST_CASE("ListIterator", "[circle]"){
    List<Circle> circle_list; 
    Circle c = Circle{450.0f,Vec2{200.0f,400.0f},Color{1.0f,0.0f,0.0f},"Circle1"};
    circle_list.push_back(c);

    auto c_it = circle_list.begin(); 
    std::cout <<"Der Radius des 1.Circles in der Liste ist: "
              << c_it->get_radius() <<std::endl; 

}


TEST_CASE ( " should be an empty range after default construction " ," [ iterators ] " )
{ //aufgabe 6
    List <int> list ;
    auto b = list.begin();
    auto e = list.end();
    REQUIRE ( b == e );
}

TEST_CASE ( " provide access to the first element with begin " , " [ iterators ] " ){
    List <int> list;
    list.push_front(42);
    REQUIRE (42 == *list.begin());
}

TEST_CASE("list == !=", "[list]"){
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2); 
    list1.push_back(3);   
    list1.push_back(4);   
    list1.push_back(5);   
    List<int> list2;
    list2.push_back(1);
    list2.push_back(2); 
    list2.push_back(3);   
    list2.push_back(4);   
    list2.push_back(5); 
    REQUIRE( list1 == list2);

    list1.pop_back();
    List<int> list3;
    list3.push_back(1);
    list3.push_back(2); 
    list3.push_back(3);   
    list3.push_back(4);   
    list3.push_back(4); 
    REQUIRE(!(list3 == list2));

    REQUIRE(list3 != list2);
    REQUIRE(list1 != list2);
}

TEST_CASE("copy constructor", "[constructor]"){
    List<int> list; 
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    List<int> list2{list};

    REQUIRE(list == list2);
}

TEST_CASE("insert", "[insert]"){
    List<int> list; 
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    ListIterator <int> it = list.begin();
    it++;

    REQUIRE(*(list.insert(it, 13)) == 13);
}

/*TEST_CASE("reverse", "[reverse]"){    {
        List<int> list;
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        list.push_front(4);
        list.reverse();
        REQUIRE(1 == list.front());    
}*/


 int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}