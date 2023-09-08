#include "listaarticoli.h"

//COSTRUTTORI
ListaArticoli::ListaArticoli(QWidget* parent) : QListWidget(parent) {
    model = new Lista<Articolo>();
    //widgetarticoli;
}
ListaArticoli::ListaArticoli(Lista<Articolo>* lis, QWidget* parent): QListWidget(parent), model(lis){
    refreshLista();
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
}

void ListaArticoli::eliminaArticolo(Articolo* art) {
    model->rimuovi(*art);

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

    // Aggiorna la vista
    update();
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
