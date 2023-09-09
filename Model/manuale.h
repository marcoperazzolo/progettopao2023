#ifndef MANUALE_H
#define MANUALE_H
#include "libro.h"

class Manuale : public Libro {
private:
    string argomento;
public:
    //costruttori
    Manuale(string tit = "Titolo non definito",
          string des = "Descrizione non definita", int dis = 0,
          string aut = "Autore non definito",
          string edi = "Editore non definito", int pag = 0,string arg="Argomento non definito");
    
    virtual ~Manuale();

    //getter
    string getArgomento() const;

    //setter
    void setArgomento(const string& newArgomento);

    //metodi

    virtual void modifica2();

    QJsonObject toJson() const;
    void fromJson(const QJsonObject& jsonObj);
};

#endif // MANUALE_H
