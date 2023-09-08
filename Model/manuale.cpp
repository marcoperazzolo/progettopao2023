#include "manuale.h"

Manuale::Manuale(string tit, string des, int dis, string aut,
                 string edi, int pag, string arg): Libro(tit, des, dis, aut, edi, pag), argomento(arg) {}
    
Manuale::~Manuale()=default;

string Manuale::getArgomento() const{
    return argomento;
}

void Manuale::setArgomento(const string& newArgomento){
    argomento=newArgomento;
}

void Manuale::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita,
        const string& newAutore, const string& newEditore, int newPagine, const string& newGenereRomanzo, int newNumero, const string& newArgomento, 
        int newDurata, const string& newRegista, double newVoto, const string& newArtista, const string& newGenereCD, int newNumeroBrani){
    setTitolo(newTitolo);
    setDescrizione(newDescrizione);
    setDisponibilita(newDisponibilita);
    setAutore(newAutore);
    setEditore(newEditore);
    setPagine(newPagine);
    /*setGenereRomanzo(newGenereRomanzo);
    setNumero(newNumero);*/
    setArgomento(newArgomento);
    /*setDurata(newDurata);
    setRegista(newRegista);
    setVoto(newVoto);
    setArtista(newArtista);
    setGenereCD(newGenereCD);
    setNumeroBrani(newNumeroBrani);*/
}
void Manuale::modifica2(){
  string newTitolo; 
  string newDescrizione; 
  int newDisponibilita;
  string newAutore;
  string newEditore;
  int newPagine;
  string newArgomento;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newAutore;
  cin>>newEditore;
  cin>>newPagine;
  cin>>newArgomento;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setAutore(newAutore);
  setEditore(newEditore);
  setPagine(newPagine);
  setArgomento(newArgomento);
}

void Manuale::mostraDettagli() const{
    std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()
    <<", Autore: "<<getAutore()<<", Editore: "<<getEditore()<<", Numero di pagine: "<<getPagine()<<", Argomento: "<<getArgomento()<<std::endl;
}