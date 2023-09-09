#include "listaarticoli.h"

//COSTRUTTORI
ListaArticoli::ListaArticoli(QWidget* parent) : QListWidget(parent) {
    model = new Lista<Articolo>();
    //widgetarticoli;
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

/*void ListaArticoli::aggiungiWidgetArticolo(Articolo* articolo){
    WidgetArticolo* widgetArticolo = new WidgetArticolo(articolo, this);
    aggiungiWidgetArticolo(widgetArticolo);
*/

void ListaArticoli::aggiungiWidgetArticolo(WidgetArticolo* widget) {
    QListWidgetItem* listItem = new QListWidgetItem(this);
    setItemWidget(listItem, widget);
    listItem->setSizeHint(QSize(0, 120));
    addItem(listItem);

    update();
    refreshLista();
}

void ListaArticoli::eliminaArticolo(Articolo* art) {

    // Cerca il widget corrispondente all'Articolo e rimuovilo dalla QListWidget
    for (int i = 0; i < count(); ++i) {
        QListWidgetItem* item = this->item(i);
        WidgetArticolo* widgetArticolo = dynamic_cast<WidgetArticolo*>(itemWidget(item));

        if (widgetArticolo && widgetArticolo->getArticolo() == art) {
            // Rimuovi il widget dalla QListWidget
            takeItem(i);

            // Elimina l'oggetto WidgetArticolo
            delete widgetArticolo;

            break;
        }
    }
    model->rimuovi(*art);

    // Aggiorna la vista
    update();
}

void ListaArticoli::clear() {
    /*for (int i = 0; i < count(); ++i) {
        QListWidgetItem* item = this->item(i);
        WidgetArticolo* widgetArticolo = dynamic_cast<WidgetArticolo*>(itemWidget(item));
            takeItem(i);
            delete item;
            delete widgetArticolo;
        }*/
    Lista<Articolo>::Nodo* nodo = model->getFirst();
    while(nodo){
        Lista<Articolo>::Nodo* prossimo = nodo->getNext();
        eliminaArticolo(nodo->getInfo());
        nodo = prossimo;
    }
    //model->distruggi();
    //refreshLista();
}

//REFRESH
void ListaArticoli::refreshLista() {
    Lista<Articolo>::Nodo* nodo = model->getFirst();
        while (nodo) {
            // Ottieni l'Articolo dal Nodo
            Articolo* art = nodo->getInfo();

            // Cerca il widget corrispondente all'Articolo
            for (int i = 0; i < count(); ++i) {
                QListWidgetItem* item = this->item(i);
                WidgetArticolo* widgetArticolo = dynamic_cast<WidgetArticolo*>(itemWidget(item));

                if (widgetArticolo && widgetArticolo->getArticolo() == art) {
                    // Aggiorna il widgetArticolo con i dati dell'Articolo
                    widgetArticolo->refreshWidget();
                    break;
                }
            }
            nodo = nodo->getNext();
        }
    update();
}

void ListaArticoli::refreshLista(Lista<Articolo>* lis) {
    //ckup = model;
    Lista<Articolo>::Nodo* nodo = lis->getFirst();
        while (nodo) {
            // Ottieni l'Articolo dal Nodo
            Articolo* art = nodo->getInfo();

            // Cerca il widget corrispondente all'Articolo
            for (int i = 0; i < count(); ++i) {
                QListWidgetItem* item = this->item(i);
                WidgetArticolo* widgetArticolo = dynamic_cast<WidgetArticolo*>(itemWidget(item));

                if (widgetArticolo && widgetArticolo->getArticolo() == art) {
                    // Aggiorna il widgetArticolo con i dati dell'Articolo
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

/*id ListaArticoli::setModel(Lista<Articolo>* lis){
    model=lis;
    refreshLista();
    update();
}*/
