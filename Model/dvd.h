#ifndef DVD_H
#define DVD_H
#include "disco.h"

class DVD : public Disco {
private:
    string regista;
    double voto;

public:
    //costruttori
    DVD(string tit = "Titolo non definito", string des="Descrizione non definita", int dis=0, int dur=0, string reg="Regista non definito", double vot=0.0);
    
    virtual ~DVD();

    //getter
    string getRegista() const;
    double getVoto() const;

    //setter
    void setRegista(const string& newRegista);
    void setVoto(double newVoto);

    //metodi
    virtual void modifica2();

    QJsonObject toJson() const;
    void fromJson(const QJsonObject& jsonObj);
};

#endif // DVD_H
