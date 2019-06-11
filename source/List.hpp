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

template <typename T>
struct ListIterator {
    using Self = ListIterator <T>;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = ptrdiff_t ;
    using iterator_category = std::bidirectional_iterator_tag;


/*dereferenziert -> value von element auf das iterator zeigt wird zurück gegeben  */
    T& operator*() const { 
        return node->value;
    }

/* DESCRIPTION operator - >() */
    T* operator->() const {
        return &(node->value);  // gibt referenz auf wert des nodes zurück
    }

/* preincrement*/ 
    ListIterator <T>& operator++() { //iterator wird einen weiter gesetzt und gibt        //( nächsten knotenzurück (temporären knoten))
        *this = this->next();          // pointer wird ein weiter gesetzt
        return *this;                  // pointer auf neues Node wird zurückgegeben
    } // PREINCREMENT

/* postincrement */
    ListIterator <T> operator++(int) { //iterator wird einen weitergesetzt und gibt vorherigen knoten zurück
        auto tmp = *this;              // speichert iterator auf aktuelles Node
        *this = next();                // setzt iterator eins weiter
        return tmp;                    // gibt iterator auf vorheriges Node zurück
    } 

/* will testen ob sie auf den gleichen knoten zeigen */
    bool operator ==(ListIterator<T> const& x) const{ 
        return x.node == node;                        // pointer x und node
    }
    
/* soll testen ob die zwei iteratoren auf den selben knoten zeigen  */
    bool operator !=(ListIterator<T> const& x) const{
        return x.node!= node;
    }

/* soll das element hinter dem auf welches der iterator zeigt zurückgeben */
    ListIterator<T> next() const {
        if (nullptr != node ) {
            return ListIterator {node->next };
        } else { //falls nullptr -> iterator auf nullptr wird zurückgegeben
            return ListIterator {nullptr};
        }
    }

   
    
    ListNode <T>* node = nullptr ;
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



/* Standartkonstruktor initialisiert size mit 0, last und first sind nullpointer */
        List ():
            last_{nullptr},
            first_{nullptr},
            size_{0}
            {}

// Copy - Konstruktor using Deep - Copy semantics ( Aufgabe 4.8)
        List( List<T> const& list1): 
            last_{nullptr}, //erstellt default liste
            first_{nullptr},
            size_{0}{
                ListNode<T>* ptr1 = list1.first_; //pointer zeigt auf first_
                while( ptr1 != nullptr){ // solange ptr1 nicht af nullptr zeigt (zeigt er auf das letzte element so ist last.next ein nullptr)
                    push_back(ptr1->value); // fügt solange alle elemente der zu kopierenden liste der neuen liste hinzu bis zum letzten element 
                    ptr1 = ptr1->next; 
                }
            }
        
	 
// Move konstruktor
/* soll elelmte einer list in eine andere list verschieben elemente "stehlen" (erste liste soll danach leer sein) */
        List(List<T>&& rhs):
            first_{rhs.first_},  // first der neuen liste zeigt auf first der alten liste
            last_{rhs.last_},    // same with last
            size_{rhs.size_}{    // die größe der zweiten liste ist gleich der größe der ertsen liste 
                
                rhs.size_ = 0;   // die alte liste ist nun leer
                rhs.first_ = nullptr; // first und last der liste sind nullpointer da sie leer ist  
                rhs.last_ = nullptr;
        }

// TODO : Move - Konstruktor ( Aufgabe 4.13)// TODO : Initializer - List Konstruktor (4.14)
/* ... */
        List ( std::initializer_list <T> ini_list ) {
// not implemented yet
        }
/* ... */
// TODO : Assignment operator ( Aufgabe 4.12)
    void swap(List<T>& rhs) { // use std::swap for builtins
        std::swap(first_ , rhs.first_);
        std::swap(last_ , rhs.last_);
    }

    List<T>& operator=(List<T> rhs) {  //tiefer zuweisungsoperator für listen etc
        swap(rhs); // vertausche jedes element
        return *this;
        } 

/* ... */


        /* der destruktor soll die liste leeren */
        ~List() {
            //std::cout << "The List with " << size() << " elements is destroyed\n";
            clear();
        }


        /* begin soll den iterator auf das erste element zurück geben  */
        ListIterator <T> begin() {
            if (empty()){
                return ListIterator<T>{nullptr};
            }
            return ListIterator <T>{first_};
        }

        /* end soll den iterator auf das element nach dem letzten element zurück geben also einen nullpointer (last_->next) */
        ListIterator <T> end() { //gibt element "nach letztem element" zurück
            return ListIterator<T>{nullptr}; 
        }
        
        /* meine Methode ignorieren*/
        ListIterator <T> last() { //gibt letztes element zurück 
            assert(! empty());
            return ListIterator<T>{last_}; 
        }

        /* löscht alle elemente aus der liste */
        void clear() {
            while(!empty()){ //solange die liste noch nicht leer ist wird das erste element entfernt
                pop_front();
              }
        }



        /* soll ein neues element an einer frei wählbaren position einfügen*/
        ListIterator <T> insert(ListIterator <T> & it1, T const& val){
            if(it1 == begin()){ //falls am anfang eingefügt werden soll
                push_front(val); 
                ++size_;
                return it1;
            }
            else if (it1 == end()){ //falls am ende eingefügt werden soll
                push_back(val);
                ++size_;
                return it1++;
            }
            else {            
                ListNode <T>* n = new ListNode<T>;    //pointer n                  // wert,  prev,     next
                                                      // n zeigt auf neuen knoten
                n->value = val; 
                n->prev = it1.node;
                n->next = it1.node->next;

                it1.node->next->prev = n;
                it1.node->next = n; 
                ++size_;
                return ++it1;

            }
        }

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


//prüft ob zwei listen komplett identisch sind   
    bool operator== (List <T> const& rhs){ 
        ListNode<T>* ptr1 = first_;
        ListNode<T>* ptr2 = rhs.first_; 
        if(size_!=rhs.size_){
            return false;
        }    
        while( ptr1 != nullptr){
            if (ptr1->value != ptr2->value){
                    return false;
                }
                ptr1 = ptr1->next; 
                ptr2 = ptr2->next;
        }
        
        return true;
    }

//prüft ob zwei listen unterschiedlich sind
    bool operator!=(List<T> const& rhs){
        return !(*this ==rhs);
    }

/* reverse soll die liste "umdrehen", also wird first zu last und andersrum usw.*/
    void reverse(){
        ListNode<T>* ptr1 = first_;
        ListNode<T>* temp = nullptr;
        while( ptr1 != nullptr){
            temp = ptr1->next;
            ptr1->next = ptr1->prev;
            ptr1->prev = temp;

            ptr1 = ptr1->prev;
        }
        std::swap(first_, last_); 

    }
 
 private:
        std::size_t size_ ;
        ListNode <T>* first_ ;
        ListNode <T>* last_ ;

};

/* soll genau wie methode eine liste "umdrehen" */
template <typename T>
List<T> reverse(List <T> const& list){ // list soll reversed werden
        List<T> rev = list; //neue hilfsliste da list const ist
        rev.reverse(); // methode wird auf rev aufgerufen 
        return rev; //rev wird statt list zurückgegeben
    }


// TODO : Freie Funktion operator +(4.14)
# endif // # define BUW_LIST_HPP