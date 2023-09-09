#ifndef CD_H
#define CD_H
#include "disco.h"

class CD : public Disco {
private:
    string artista;
    string genere;
    int numBrani;

public:
    //costruttori
    CD(string tit = "Titolo non definito", string des="Descrizione non definita", int dis=0, int dur=0, string art="Artista non definito", string gen="Genere non definito", int numBr=0);
    
    virtual ~CD();

    //getter
    string getArtista() const;
    string getGenereCD() const;
    int getNumeroBrani() const;

    //setter
    void setArtista(const string& newArtista);
    void setGenereCD(const string& newGenere);
    void setNumeroBrani(int newNumeroBrani);

    //metodi
    virtual void modifica2();

    QJsonObject toJson() const;
    void fromJson(const QJsonObject& jsonObj);
};

#endif // CD_H
