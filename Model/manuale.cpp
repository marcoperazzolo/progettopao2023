#include "manuale.h"

Manuale::Manuale(string tit, string des, int dis, int annopub, string aut,
                 string edi, int pag, string arg): Libro(tit, des, dis, annopub, aut, edi, pag), argomento(arg) {}
    
Manuale::~Manuale()=default;

string Manuale::getArgomento() const{
    return argomento;
}

void Manuale::setArgomento(const string& newArgomento){
    argomento=newArgomento;
}