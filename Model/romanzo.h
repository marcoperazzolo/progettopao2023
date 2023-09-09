#ifndef ROMANZO_H
#define ROMANZO_H
#include "libro.h"

class Romanzo : public Libro {
private:
    string genere;
public:
    //costruttori
    Romanzo(string tit = "Titolo non definito",
          string des = "Descrizione non definita", int dis = 0,
          string aut = "Autore non definito",
          string edi = "Editore non definito", int pag = 0, string gen="Genere non definito");
    
    virtual ~Romanzo();

    //getter
    virtual string getGenereRomanzo() const;//cambiato sia questo che quello in cd per conflitto

    //setter
    void setGenereRomanzo(const string& newGenere);

    //metodi

    virtual void modifica2();

    QJsonObject toJson() const;
    void fromJson(const QJsonObject& jsonObj);
};

#endif // ROMANZO_H
