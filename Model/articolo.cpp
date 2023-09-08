#include "articolo.h"

Articolo::Articolo(string tit, string des, int dis): titolo(tit), descrizione(des), disponibilita(dis) {}
Articolo::Articolo(const Articolo& a): titolo(a.titolo), descrizione(a. descrizione), disponibilita(a.disponibilita) {}
Articolo::~Articolo()=default;

bool Articolo::operator==(const Articolo& a) const{
  if(titolo==a.titolo && descrizione==a.descrizione && disponibilita==a.disponibilita)
    return true;
  return false;
}

string Articolo::getTitolo() const{
  return titolo;
}
string Articolo::getDescrizione() const{
  return descrizione;
}
int Articolo::getDisponibilita() const{
  return disponibilita;
}

string Articolo::getAutore() const{return 0;}//return 0 per evitare warning
string Articolo::getEditore() const{return 0;}
int Articolo::getPagine() const{return 0;}
string Articolo::getGenereRomanzo() const{return 0;}
int Articolo::getNumero() const{return 0;}
string Articolo::getArgomento() const{return 0;}
int Articolo::getDurata() const{return 0;}
string Articolo::getArtista() const{return 0;}
string Articolo::getGenereCD() const{return 0;}
int Articolo::getNumeroBrani() const{return 0;}
string Articolo::getRegista() const{return 0;}
double Articolo::getVoto() const{return 0;}

void Articolo::setTitolo(const string& newTitolo) {
  titolo=newTitolo;
}
void Articolo::setDescrizione(const string& newDescrizione) {
  descrizione=newDescrizione;
}
void Articolo::setDisponibilita(int newDisponibilita) {
  disponibilita=newDisponibilita;
}

void Articolo::setAutore(const string& newAutore){}
void Articolo::setEditore(const string& newEditore){}
void Articolo::setPagine(int newPagine){}
void Articolo::setGenereRomanzo(const string& newGenere){}
void Articolo::setNumero(int newNumero){}
void Articolo::setArgomento(const string& newArgomento){}

void Articolo::setDurata(int newDurata){}
void Articolo::setRegista(const string& newRegista){}
void Articolo::setVoto(double newVoto){}
void Articolo::setArtista(const string& newArtista){}
void Articolo::setGenereCD(const string& newGenere){}
void Articolo::setNumeroBrani(int newNumeroBrani){}

void Articolo::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita, 
  const string& newAutore, const string& newEditore, int newPagine, const string& newGenereRomanzo, int newNumero, const string& newArgomento, 
  int newDurata, const string& newRegista, double newVoto, const string& newArtista, const string& newGenereCD, int newNumeroBrani){
    setTitolo(newTitolo);
    setDescrizione(newDescrizione);
    setDisponibilita(newDisponibilita);
    /*setAutore(newAutore);
    setEditore(newEditore);
    setPagine(newPagine);
    setGenereRomanzo(newGenereRomanzo);
    setNumero(newNumero);
    setArgomento(newArgomento);
    setDurata(newDurata);
    setRegista(newRegista);
    setVoto(newVoto);
    setArtista(newArtista);
    setGenereCD(newGenereCD);
    setNumeroBrani(newNumeroBrani);*/
}
void Articolo::modifica2(){
  string newTitolo;
  string newDescrizione;
  int newDisponibilita;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
}
void Articolo::mostraDettagli() const{
  std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()<<std::endl;
}