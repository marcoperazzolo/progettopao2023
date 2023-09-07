#include "articolo.h"
#include "romanzo.h"
#include <iostream>
#include "lista.h"
#include "manuale.h"
#include "cd.h"
using namespace std;

int main(int argc, char* argv[]){
    Articolo a("Panetto", "pane verde", 33, 2023);
    //a.mostraDettagli();
    Romanzo c("Pinono", "pane blu", 3, 2020, "d", "e", 100, "due");
    Articolo* d=&c;
    Manuale m("Latte", "fresco", 36, 2012, "Mario", "Giorgio", 130, "Cucina");
    Articolo* n=&m;
    Libro u("Ricette", "spane blu", 23, 22020, "sd", "se", 1200);
    Articolo* f=new CD("Tuoni", "musica", 10, 2012, 20, "Matteo", "Metal", 4);
    /*Articolo b=a;
    a.mostraDettagli();
    b.mostraDettagli();
    b.modificaDettagli("pino", "blu", 2, 12);
    a.mostraDettagli();
    b.mostraDettagli();*/
    //d->mostraDettagli();
    /*Romanzo* e= dynamic_cast<Romanzo*>(d);
    cout<<e->getPagine()<<endl;*/
    /*d->mostraDettagli();
    d->modifica2();
    d->mostraDettagli();
    cout<<c.getGenereRomanzo()<<endl;
    d->setGenereRomanzo("gelato");
    d->mostraDettagli();
    c.mostraDettagli();
    cout<<c.getGenereRomanzo()<<endl;*/
    /*Manuale m("Fuffa", "pane rosso", 13, 1020, "di", "ei", 1001, "cinque");
    cout<<m.getArgomento()<<endl;
    m.modificaDettagli("salsa");
    cout<<m.getTitolo();*/
    //n->mostraDettagli();
    Lista<Articolo>* l;
    cout<<"bbb"<<endl;
    l->inserisciInCoda(&a);
    l->inserisciInCoda(d);
    l->inserisciInCoda(&u);
    cout<<"bbb"<<endl;
    /*l.inserisci(&a);
    l.inserisci(d);
    l.inserisci(&u);
    l.inserisci(f);*/
    //l.getFirst()->getNext()->getInfo()->setTitolo("Fiore");
    //l.cerca(d).getInfo()->mostraDettagli();
    //cout<<l.cercaBool(f);
    //l.spostaDaCodaATesta();
    l->lettura();
    //cout<<l.getDim()<<endl;
    cout<<"uuu"<<endl;
    Lista<Articolo> l2;
    l2.inserisci(f);
    l2.lettura();
    cout<<"aaa"<<endl;
    l2.copia(*l);
    l2.lettura();
    //l2.lettura();
    //cout<<"bbb"<<endl;
    /*Lista l2=l;
    l2.getFirst()->getInfo().mostraDettagli();
    l2.getFirst()->getNext()->getInfo().mostraDettagli();
    l2.getFirst()->getNext()->getNext()->getInfo().mostraDettagli();*/
    /*l.rimuovi(a);
    cout<<endl;
    l.getFirst()->getInfo().mostraDettagli();
    l.getFirst()->getNext()->getInfo().mostraDettagli();
    //l.getFirst()->getNext()->getNext()->getInfo()->mostraDettagli();
    cout<<endl;
    a.mostraDettagli();*/
    //cout<<l.getFirst()->getInfo().getPagine();
}