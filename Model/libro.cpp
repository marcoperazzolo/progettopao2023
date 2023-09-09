#include "libro.h"

Libro::Libro(string tit, string des, int dis, string aut, string edi, int pag): Articolo(tit, des, dis), autore(aut), editore(edi), pagine(pag) {}
    
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


void Libro::modifica2(){
  string newTitolo; 
  string newDescrizione; 
  int newDisponibilita; 
  string newAutore;
  string newEditore;
  int newPagine;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newAutore;
  cin>>newEditore;
  cin>>newPagine;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setAutore(newAutore);
  setEditore(newEditore);
  setPagine(newPagine);
} 
