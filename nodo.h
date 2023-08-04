#ifndef NODO_H
#define NODO_H


#include "articolo.h"

class Nodo {
  private:
    Articolo* articolo;
    Nodo* next;

  public:
    //costruttori
    Nodo(const Articolo& art){
        articolo = art;
        next = nullptr;
    }

    virtual ~Nodo();


};

#endif // NODO_H
