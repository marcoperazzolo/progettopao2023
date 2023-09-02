#include "dvd.h"

DVD::DVD(string tit, string des, int dis, int annopub, int dur, string reg, double vot): Disco(tit, des, dis, annopub, dur), regista(reg), voto(vot) {}
    
DVD::~DVD()=default;

string DVD::getRegista() const{
    return regista;
}
double DVD::getVoto() const{
    return voto;
}

void DVD::setRegista(const string& newRegista){
    regista=newRegista;
}
void DVD::setVoto(double newVoto){
    voto=newVoto;
}