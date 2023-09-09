#ifndef ARTICOLO_H
#define ARTICOLO_H

#include <iostream>
#include <string>
using std::string;
using std::cin;
//c++ Model/articolo.cpp main.cpp -o main



#include <QJsonObject>


class Articolo {
private:
  string titolo;
  string descrizione;
  int disponibilita;
public:
  //costruttori
  Articolo(string tit = "Titolo non definito", string des="Descrizione non definita", int dis=0);
  Articolo(const Articolo& a);
  virtual ~Articolo();

  bool operator==(const Articolo& a) const;

  //getter
  virtual string getTitolo() const;
  virtual string getDescrizione() const;
  virtual int getDisponibilita() const;
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

  virtual void modifica2();

  virtual QJsonObject toJson() const = 0;
  virtual void fromJson(const QJsonObject& jsonObj) = 0;
};

#endif // ARTICOLO_H
