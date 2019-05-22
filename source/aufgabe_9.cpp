# include <cstdlib> // std:rand()
# include <vector> // std::vector<>
# include <list> //std::list<>
# include <iostream> //std::cout
# include <iterator> //std::ostream_iterator
# include <algorithm> //std::reverse, std::generate




int main ()
{
    std::vector <int> v_0(10);
    for (auto& v: v_0){
        v = std::rand(); // vektor wird mit 10 zufälligen zahlen gefüllt 
    }
    std::copy(std::cbegin(v_0), std::cend(v_0), std::ostream_iterator <int>(std::cout, " (1) \n" )); // alle elemente aus vektor v_0 werden ausgegeben (10 elemente)
    std::cout << "\n";
    std::list <int> l_0(std::cbegin( v_0 ), std::cend(v_0)); // kopiert alle elemente aus v_0 in liste l_0
    std::list <int> l_1(std::cbegin(l_0), std::cend( l_0 )); // kopiert alle elemente aus l_0 in liste l_1
    std::reverse(std::begin(l_1), std::end(l_1)); //liste l_1 wird umgekehrt (1. element ist nun letztes)
    std::copy(std::cbegin(l_1), std::cend(l_1) , std::ostream_iterator < int >( std::cout, " (2) \n" )); // liste l_1 wird ausgegeben (ist genau umgekehrt von v_0)
    std::cout<<"\n";
    l_1.sort(); //l_1 wir sortiert
    std::copy ( l_1.cbegin() , l_1.cend(), std::ostream_iterator < int >( std::cout, " (3) \n" )); // aufsteigend sortierte liste l_1 wird ausgegeben
    std::cout<<"\n";
                //   first              last               generator function that is called
    std::generate ( std::begin(v_0) , std::end(v_0) , std::rand); // füllt v_0 mit random zahlen
    std::copy ( v_0.crbegin() , v_0.crend() , std::ostream_iterator < int >( std::cout, " (4) \n" ));
    return 0;
}