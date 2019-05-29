# ifndef BUW_LIST_HPP
# define BUW_LIST_HPP
# include <cassert>
# include <cstddef> // ptrdiff_t
# include <iterator> // std::bidirectional_iterator_tag
# include <iostream>
# include <initializer_list>
#include <list>


template <typename T>
class List ;

template <typename T>
struct ListNode {
    T
    value = T();
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
};

template < typename T >
struct ListIterator {
    using Self = ListIterator <T >;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = ptrdiff_t ;
    using iterator_category = std::bidirectional_iterator_tag;


/* DESCRIPTION operator *() */
    T& operator*() const { //dereferenziert -> value wird zurück gegeben
        return node->value;
    }
/* DESCRIPTION operator - >() */
    T* operator->() const {
        return &(node->value); // gibt adresse zurück (pointer)
    }
/* ... */ //evtl ändern
    ListIterator <T>& operator++() { //iterator wird einen weiter gesetzt und gibt
        //node = node-> next;          // nächsten knotenzurück (temporären knoten)
        *this = this->next();
        return *this;
    } // PREINCREMENT

/* ... */
    ListIterator <T> operator++(int) { //iterator wird einen weitergesetzt und gibt
        //ListIterator old(*this);
        //node = node-> next;         // vorherigen knoten zurück
        auto tmp = *this;
        *this = tmp;
        return tmp;
    } // POSTINCREMENT ( signature distinguishes )

/* ... */
    bool operator ==(ListIterator<T> const& x) const{ //will testen ob sie auf den gleichen knoten zeigen
        return x.node == node;                        // pointer x und node
// // not implemented yet
    }/* ... */
    bool operator !=(ListIterator<T> const& x) const{
        return x.node!= node;
// // not implemented yet
    }
/* ... */
    ListIterator<T> next() const {
        if (nullptr != node ) {
            return ListIterator {node->next };
        } else {
            return ListIterator {nullptr};
        }
    }
    
    ListNode <T >* node = nullptr ;
};


template <typename T>
class List {
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = T const*;
        using reference = T&;
        using const_reference = T const&;
        using iterator = ListIterator<T>;



// not implemented yet
// do not forget about the initialiser list !

        /* Standartkonstruktor initialisiet size mit 0, last und first sind nullpointer */
        List ():
            last_{nullptr},
            first_{nullptr},
            size_{0}
            {}

/* ... */
// TODO : Copy - Konstruktor using Deep - Copy semantics ( Aufgabe 4.8)
/* ... */
// TODO : Move - Konstruktor ( Aufgabe 4.13)// TODO : Initializer - List Konstruktor (4.14)
/* ... */
        List ( std::initializer_list <T> ini_list ) {
// not implemented yet
        }
/* ... */
// TODO : Assignment operator ( Aufgabe 4.12)
/* ... */
// TODO : operator == ( Aufgabe 4.7)
/* ... */
// TODO : operator != ( Aufgabe 4.7)
        /* ... */
        ~List() {
            std::cout << "The List with " << size() << " elements is destroyed\n";
            clear();
// TO IMPLEMENT PROPERLY
        }
/* ... */
        ListIterator <T> begin() {
            assert(! empty());
            return ListIterator <T>{first_};
        }

/* ... */
        ListIterator <T> end() { //gibt element "nach letztem element" zurück
            assert(! empty());   //last_->next
            return ListIterator<T>{nullptr}; 
        }

        ListIterator <T> last() { //gibt letztes element zurück 
            assert(! empty());
            return ListIterator<T>{last_}; 
        }

            /* löscht alle elemente aus der liste */
        void clear() {
            while(!empty()){
                pop_front();
              }
        }



// // not implemented yet
        /* ... */
// TODO : member function insert
/* ... */
// TODO : member function reverse

            /* fügt vorne ein element hinzu */
        void push_front(T const& element ){
            ListNode<T>* ptr = new ListNode<T>; 
            ptr->value = element; 

            if(empty()){
                first_ = ptr;
                last_ = ptr;
            }
            else{
                ptr->next = first_;
                first_->prev = ptr;
                first_ = ptr;

            }
            size_++;
        }
             /* soll hinten an der list ein element einfügen  */
        void push_back(T const& element ) {
            ListNode<T>* ptr = new ListNode<T>{element, last_, nullptr};
            
            if(empty()){ //falls die liste leer ist, ist das neue element gleichzeitig das erste und letzte element
                first_ = ptr;
                last_ = ptr;
            }
            else{ //next des letzten elements zeigt nun auf das neue element
                last_->next = ptr;
             }

             last_ = ptr; //ptr ist nun das neue letzte element
             ++size_;
        }
             /* soll vorne an der liste ein element anfügen */
        void pop_front() {
            if (empty()){
                std::cout<<"List is already empty\n";
            }
            assert(!empty()); 
            auto temp = first_; // first node wird zwischengespeichert (pointer temp)
            if(size() == 1){ // falls es nur ein element gibt, sind last und first nullpointer
                first_ = last_ = nullptr; 
            }
            else{
                first_-> next->prev = nullptr; // das element nach first: sein prev-pointer ist nun ein nullpointer( da diese nun das neue erste element ist)
                first_ = first_->next; //der first pointer zeigt nun auf das nächste element
            }
            
            delete temp; //element wir gelöscht
            --size_;
        }

            /* soll das letzte element aus der liste löschen*/
        void pop_back() {
            if (empty()){
                std::cout<<"List is already empty\n";
            }
            assert(!empty());
            auto temp = last_;
            if(size() == 1){
                first_ = last_ = nullptr;
            }
            else{
                last_-> prev->next = nullptr;
                last_ = last_->prev;
            }
            
            delete temp;
            size_--;
        }

            /* gibt den wert des ersten elements aus */
        T& front() {
            assert(!empty());
            return first_->value;
        }

            /* gibt den wert des letzten elements aus */
        T& back() {
            assert(!empty());
                return last_->value;
            }
        
        /* gibt true zurück falls die liste leer ist, ansonsten false */
    bool empty() const{
        if (size_ == 0){
            return true;
        }
        else{
            return false;
        }
    };
        /* gibt die größe der liste zurück */
    std::size_t size() {
        return size_;
    };

    private:
        std::size_t size_ ;
        ListNode <T>* first_ ;
        ListNode <T>* last_ ;
};
/* ... */
// TODO : Freie Funktion reverse
/* ... */
// TODO : Freie Funktion operator +(4.14)
# endif // # define BUW_LIST_HPP