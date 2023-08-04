#include "dvd.h"

DVD::DVD(string tit, string des, int dis, int annopub, int dur, string reg,
         double vot)
    : Disco(tit, des, dis, annopub, dur), regista(reg), voto(vot) {}

DVD::~DVD() = default;

string DVD::getRegista() const { return regista; }
double DVD::getVoto() const { return voto; }
