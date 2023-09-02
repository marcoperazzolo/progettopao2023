#include "libro.h"

Libro::Libro(string tit, string des, int dis, int annopub, string aut, string edi, int pag): Articolo(tit, des, dis, annopub), autore(aut), editore(edi), pagine(pag) {}
    
Libro::~Libro()=default;

string Libro::getAutore() const{
    return autore;
}
string Libro::getEditore() const{
    return editore;
}
int Libro::getPagine() const{
    return pagine;
}

void Libro::setAutore(const string& newAutore){
    autore=newAutore;
}
void Libro::setEditore(const string& newEditore){
    editore=newEditore;
}
void Libro::setPagine(int newPagine){
    pagine=newPagine;
}

void Libro::mostraDettagli() const{
    std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()<<", Anno di pubblicazione: "<<getAnnoPubblicazione()
    <<", Autore: "<<getAutore()<<", Editore: "<<getEditore()<<", Numero di pagine: "<<getPagine()<<std::endl;
}