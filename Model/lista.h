#ifndef LISTA_H
#define LISTA_H

template<class T>
class Lista{
public:
    class Nodo{
    public:
        T* info;
        Nodo* next;
        Nodo(T* i, Nodo* n = 0): info(i), next(n) {}
        //Nodo(const Nodo& n): info(n.info), next(n.next) {}//fare prove, togliere?
        T* getInfo() const{
            return info;
        }
        Nodo* getNext() const{
            return next;
        }
        Nodo& setInfo(T* newInfo){
            info=newInfo;
            return *this;
        }
        Nodo& setNext(Nodo* newNext){
            next=newNext;
            return *this;
        }
    };
private:
    Nodo* first;
public:
    Lista(): first(nullptr) {}
    Lista(const Lista& l): first(nullptr) {
        copia(l);
    }
    ~Lista() {distruggi();}

    Nodo* getFirst() const{
        return first;
    }
    unsigned int getDim() const{
        Nodo* n=first;
        unsigned int dim=0;
        while (n!=nullptr) {
            n=n->getNext();
            dim++;
        }
        return dim;
    }
    Lista& inserisci(T* t){//versione che inserisce in testa
        first=new Nodo(t, first);
        return *this;
    }
    void inserisci2(T* t){//versione che inserisce in testa
        first=new Nodo(t, first);
    }
    Lista& inserisciInCoda(T* t){//versione che inserisce in coda
        if(getDim()>0){
            Nodo* n=new Nodo(t,nullptr);
            Nodo* attuale=first;
            while(attuale->getNext()!=nullptr){
                attuale=attuale->getNext();
            }
            attuale->setNext(n);
        }else{
            inserisci(t);
        }
        return *this;
    }
    
    //decidere quale usare    void eliminaArticolo(Articolo* art);

    Nodo& cerca(const T* t){//prima tornava un bool
        Nodo* attuale=first;
        while(attuale!=nullptr){
            if(attuale->getInfo()==t){
                return *attuale;
            }
            attuale=attuale->getNext();
        }
        return *attuale;
    }
    bool cercaBool(const T* t){//prima tornava un bool
        Nodo* attuale=first;
        while(attuale!=nullptr){
            if(attuale->getInfo()==t){
                return true;
            }
            attuale=attuale->getNext();
        }
        return false;
    }
    /*Nodo& cerca(const T& t){//aggiungere uno che passa una stringa, prima tornava un bool
        Nodo* attuale=first;
        while(attuale!=nullptr){
            if(attuale->getInfo()->getTitolo()==t.getTitolo()){
                return *attuale;
            }
            attuale=attuale->getNext();
        }
        return *attuale;
    }*/
    
    /*Lista& rimuoviCoda(){
        Nodo* attuale=first;
        Nodo* precedente=nullptr;
        while(attuale->getNext()!=nullptr){
            precedente=attuale;
            attuale=attuale->getNext();
        }
        delete attuale;
        precedente->setNext(nullptr);
        return *this;
    }
    Lista& spostaDaCodaATesta(){
        Nodo* attuale=first;
        Nodo* coda=nullptr;
        unsigned int dim=getDim();
        while(dim>1){
            attuale=attuale->getNext();
            dim--;
            coda=attuale;
        }
        inserisci(attuale->getInfo());
        rimuoviCoda();
        return *this;
    }*/

    Lista& copia(const Lista& l){
        if(this!=&l){
            if(this!=nullptr){
                distruggi();
            }
            Nodo* attuale=l.first;
            while(attuale!=nullptr){
                inserisciInCoda(attuale->getInfo());
                attuale=attuale->getNext();
            }
        }
        return *this;
    }

    //inserire metodo per lettura
    void lettura() const{//vedere come lo hanno fatto, da cambiare
        Nodo* attuale=first;
        while(attuale!=nullptr){
            attuale->getInfo()->mostraDettagli();
            attuale=attuale->getNext();
        }
    }
    Nodo& lettura2(const T* t){//ritorna un nodo che deve essere usato per vedere l'elemento
        Nodo* attuale=first;
        while(attuale!=nullptr){
            if(attuale->getInfo()==t){
                return *attuale;
            }
            attuale=attuale->getNext();
        }
        return *attuale;
    }

    Lista& rimuovi(T& t){
        Nodo* precedente=nullptr;
        Nodo* attuale=first;
        while(attuale!=nullptr){
            if(attuale->getInfo()==&t){
                if(precedente!=nullptr){
                    precedente->setNext(attuale->getNext());
                }
                else{
                    first=attuale->getNext();
                }
                delete attuale;
                return *this;
            }
            precedente=attuale;
            attuale=attuale->getNext();
        }
        return *this;
    }

    Lista& distruggi(){
        while (first!=nullptr) {
            Nodo* next=first->getNext();
            delete first;
            first=next;
        }
        return *this;
    }
};

#endif //LISTA_H
