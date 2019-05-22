#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <iostream>

bool is_even(int n) {return n % 2 == 0; }


template <typename Container, typename Predikat>
Container filter(Container const& c1, Predikat const& p){
    Container c2;
    for (auto& el: c1){
        if(p(el)== true){
            c2.push_back(el);
        }
    }
    return c2;
}

TEST_CASE("Aufgabe13", "[Aufgabe13]"){

    std::vector <int> v{1, 2, 3, 4, 5, 6};
    std::vector <int> all_even = filter(v, is_even);

    REQUIRE(std::all_of(all_even.begin(), all_even.end(), is_even));

}

int main(int argc, char* argv[]){
    return Catch::Session().run(argc, argv);
}

