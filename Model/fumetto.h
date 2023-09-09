#ifndef FUMETTO_H
#define FUMETTO_H
#include "libro.h"

class Fumetto : public Libro {
private:
  int numero;
public:
  // costruttori
  Fumetto(string tit = "Titolo non definito",
          string des = "Descrizione non definita", int dis = 0,
          string aut = "Autore non definito",
          string edi = "Editore non definito", int pag = 0, int num = 0);

  virtual ~Fumetto();

  // getter
  int getNumero() const;

  //setter
  void setNumero(int newNumero);

  // metodi
  virtual void modifica2();

  QJsonObject toJson() const;
  void fromJson(const QJsonObject& jsonObj);
};

#endif // FUMETTO_H
