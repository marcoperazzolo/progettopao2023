#include "articolo.h"
#include "romanzo.h"
#include <iostream>
#include "lista.h"
using namespace std;

int main(int argc, char* argv[]){
    Articolo a("Panetto", "pane verde", 33, 2023);
    //a.mostraDettagli();
    Articolo* d=new Romanzo("Pinono", "pane blu", 3, 2020, "d", "e", 100, "due");
    Libro u("Ricette", "spane blu", 23, 22020, "sd", "se", 1200);
    //d->mostraDettagli();
    Romanzo* e= dynamic_cast<Romanzo*>(d);
    cout<<e->getGenere();
    Lista l;
    l.inserisci(d);
    l.inserisci(&a);
    l.inserisci(&u);
    //l.getFirst()->getNext()->getInfo()->setTitolo("Fiore");
    l.getFirst()->getInfo()->mostraDettagli();
    l.getFirst()->getNext()->getInfo()->mostraDettagli();
    l.getFirst()->getNext()->getNext()->getInfo()->mostraDettagli();
    /*l.rimuovi(a);
    cout<<endl;
    l.getFirst()->getInfo()->mostraDettagli();
    l.getFirst()->getNext()->getInfo()->mostraDettagli();
    //l.getFirst()->getNext()->getNext()->getInfo()->mostraDettagli();
    cout<<endl;
    a.mostraDettagli();*/
    //cout<<l.getFirst()->getInfo().getPagine();
}