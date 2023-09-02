#include "cd.h"

CD::CD(string tit, string des, int dis, int annopub, int dur, string art, string gen, int numBr): Disco(tit, des, dis, annopub, dur), artista(art), genere(gen), numBrani(numBr) {}
    
CD::~CD()=default;

string CD::getArtista() const{
    return artista;
}
string CD::getGenere() const{
    return genere;
}
int CD::getNumeroBrani() const{
    return numBrani;
}


void CD::setArtista(const string& newArtista){
    artista=newArtista;
}
void CD::setGenere(const string& newGenere){
    genere=newGenere;
}
void CD::setNumeroBrani(int newNumeroBrani){
    numBrani=newNumeroBrani;
}