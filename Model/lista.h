#ifndef LISTA_H
#define LISTA_H
//namespace??
#include "articolo.h"

//template <class T>
class Lista{
private:
//public:
    class Nodo{
    public:
        Articolo* info;
        //Nodo* prev;   vedere se rimettere
        Nodo* next;
        Nodo(Articolo* i, Nodo* n = 0): info(i), next(n){}; //Nodo(const T& i, Nodo* p = 0, Nodo* n = 0): info(i), prev(p), next(n){};
        Articolo* getInfo() const{
            return info;
        }
        Nodo& setInfo(Articolo* newInfo){
            this->info=newInfo;
            return *this;
        }
        Nodo *getNext() const{
            return next;
        }
        Nodo& setNext(Nodo* newNext){
            this->next=newNext;
            return *this;
        }
        /*Nodo *getPrev() const{
            return prev;
        }
        Nodo& setPrev(Nodo* newPrev){
            this->prev=newPrev;
            return *this;
        }*/
        /*T& operator*() const{
            return info;
        }*/
        /*
        T* operator->() const {
            return *info;
        }*/
    };
    Nodo* first;
    //Nodo* last;  //vedere se rimettere
public:
    Lista(): first(nullptr) {}
    ~Lista() {
        clear();
    }

    Nodo *getFirst() const{
        return first;
    }
    unsigned int getDim() const{
        unsigned int dim = 0;
        Nodo* n = first;
        while (n != nullptr) {
            n = n->getNext();
            dim++;
        }
        return dim;
    }
    Lista& inserisci(Articolo* t){
        first=new Nodo(t, first);
        return *this;
    }
/*
    bool cerca(Nodo* v, T c){

    }
    void copia(Nodo* fst, Nodo*& n, Nodo* l){

    }

    void distruggi(Nodo* n){

    }*/
    //robe aggiunte diritte
    Lista& rimuovi(Articolo& x){//lavoro in corso
        Nodo* precedente = nullptr;
        Nodo* attuale = first;
        while (attuale != nullptr) {
            if (attuale->getInfo() == &x) {//rivedere x??
                if (precedente != nullptr) {
                    precedente->setNext(attuale->getNext());
                }
                else {
                    first = attuale->getNext();
                }
                delete attuale;
                return *this;
            }
            precedente = attuale;
            attuale = attuale->getNext();
        }
        return *this;
    }
    Lista& clear() {
        while (first != nullptr) {
            Nodo* next = first->getNext();
            delete first;
            first = next;
        }
        return *this;
    }
    
    
};


#endif //LISTA_H