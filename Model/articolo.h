#ifndef ARTICOLO_H
#define ARTICOLO_H

#include <iostream>
#include <string>
using std::string;
using std::cin;
//c++ Model/articolo.cpp main.cpp -o main

class Articolo {
private:
  string titolo;
  string descrizione;
  int disponibilita;
  int annoPubblicazione;
public:
  //costruttori
  Articolo(string tit = "Titolo non definito", string des="Descrizione non definita", int dis=0, int annopub=0);
  Articolo(const Articolo& a);
  virtual ~Articolo();

  bool operator==(const Articolo& a) const;

  //getter
  virtual string getTitolo() const;
  virtual string getDescrizione() const;
  virtual int getDisponibilita() const;
  virtual int getAnnoPubblicazione() const;
  //extra
  virtual string getAutore() const;
  virtual string getEditore() const;
  virtual int getPagine() const;
  virtual string getGenereRomanzo() const;
  virtual int getNumero() const;
  virtual string getArgomento() const;
  
  virtual int getDurata() const;
  virtual string getArtista() const;
  virtual string getGenereCD() const;
  virtual int getNumeroBrani() const;
  virtual string getRegista() const;
  virtual double getVoto() const;

  //setter
  virtual void setTitolo(const string& newTitolo);
  virtual void setDescrizione(const string& newDescrizione);
  virtual void setDisponibilita(int newDisponibilita);
  virtual void setAnnoPubblicazione(int newAnnoPubblicazione);
  //extra
  virtual void setAutore(const string& newAutore);
  virtual void setEditore(const string& newEditore);
  virtual void setPagine(int newPagine);
  virtual void setGenereRomanzo(const string& newGenere);
  virtual void setNumero(int newNumero);
  virtual void setArgomento(const string& newArgomento);

  virtual void setDurata(int newDurata);
  virtual void setRegista(const string& newRegista);
  virtual void setVoto(double newVoto);
  virtual void setArtista(const string& newArtista);
  virtual void setGenereCD(const string& newGenere);
  virtual void setNumeroBrani(int newNumeroBrani);

  //metodi
  //aggiunger modifica dettagli, ha argomenti di default, vedere se cambiare
  virtual void modificaDettagli(const string& newTitolo="", const string& newDescrizione="", int newDisponibilita=0, int newAnnoPubblicazione=0, 
    const string& newAutore="", const string& newEditore="", int newPagine=0, const string& newGenereRomanzo="", int newNumero=0, const string& newArgomento="", 
    int newDurata=0, const string& newRegista="", double newVoto=0, const string& newArtista="", const string& newGenereCD="", int newNumeroBrani=0);
  virtual void modifica2();//opzione alternativa che usa dei cin
  virtual void mostraDettagli() const;
};

#endif // ARTICOLO_H