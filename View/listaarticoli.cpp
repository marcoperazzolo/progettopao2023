#include "listaarticoli.h"

//COSTRUTTORI
ListaArticoli::ListaArticoli(QWidget* parent) : QListWidget(parent) {
    model = new Lista<Articolo>();
}
void ListaArticoli::aggiornaListadaLista(Lista<Articolo>* lis) {
    model = lis;
    for(unsigned int i = 0; i < lis->getDim(); i++){
        WidgetArticolo* widget = new WidgetArticolo (lis->cercadaPos(i));
        QListWidgetItem* listItem = new QListWidgetItem(this);
        setItemWidget(listItem, widget);
        listItem->setSizeHint(QSize(0, 120));
        addItem(listItem);
    }

    refreshLista();
    update();
}
ListaArticoli::~ListaArticoli(){
    delete model;
}


//OPERAZIONI SU ARTICOLI (MODEL E VISTA)
void ListaArticoli::aggiungiArticolo(Articolo* art){
    //Model
    model->inserisci(art);
    //View
    WidgetArticolo* widget = new WidgetArticolo (art);
    aggiungiWidgetArticolo(widget);
}

void ListaArticoli::aggiungiWidgetArticolo(WidgetArticolo* widget) {
    QListWidgetItem* listItem = new QListWidgetItem(this);
    setItemWidget(listItem, widget);
    listItem->setSizeHint(QSize(0, 120));
    addItem(listItem);

    update();
    refreshLista();
}

void ListaArticoli::eliminaArticolo(Articolo* art) {
    for (int i = 0; i < count(); ++i) {
        QListWidgetItem* item = this->item(i);
        WidgetArticolo* widgetArticolo = dynamic_cast<WidgetArticolo*>(itemWidget(item));

        if (widgetArticolo && widgetArticolo->getArticolo() == art) {
            takeItem(i);
            delete widgetArticolo;
        }
    }
    model->rimuovi(*art);

    // Aggiorna la vista
    update();
}

void ListaArticoli::clear() {
    Lista<Articolo>::Nodo* nodo = model->getFirst();
    while(nodo){
        Lista<Articolo>::Nodo* prossimo = nodo->getNext();
        eliminaArticolo(nodo->getInfo());
        nodo = prossimo;
    }
}

//REFRESH
void ListaArticoli::refreshLista() {
    Lista<Articolo>::Nodo* nodo = model->getFirst();
        while (nodo) {
            Articolo* art = nodo->getInfo();

            for (int i = 0; i < count(); ++i) {
                QListWidgetItem* item = this->item(i);
                WidgetArticolo* widgetArticolo = dynamic_cast<WidgetArticolo*>(itemWidget(item));

                if (widgetArticolo && widgetArticolo->getArticolo() == art) {
                    widgetArticolo->refreshWidget();
                    break;
                }
            }
            nodo = nodo->getNext();
        }
    update();
}

void ListaArticoli::refreshLista(Lista<Articolo>* lis) {
    Lista<Articolo>::Nodo* nodo = lis->getFirst();
        while (nodo) {
            Articolo* art = nodo->getInfo();

            for (int i = 0; i < count(); ++i) {
                QListWidgetItem* item = this->item(i);
                WidgetArticolo* widgetArticolo = dynamic_cast<WidgetArticolo*>(itemWidget(item));

                if (widgetArticolo && widgetArticolo->getArticolo() == art) {
                    widgetArticolo->refreshWidget();
                    break;
                }
            }
            nodo = nodo->getNext();
        }
    update();
}

Lista<Articolo>* ListaArticoli::getLista() const{
    return model;
}
