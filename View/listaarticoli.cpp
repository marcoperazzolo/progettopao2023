#include "listaarticoli.h"

ListaArticoli::ListaArticoli(QWidget* parent) : QListWidget(parent) { }


void ListaArticoli::aggiungiArticolo(std::string tit, std::string desc, int disp){
    WidgetArticolo* temp = new WidgetArticolo (tit, desc, disp);
    QListWidgetItem* tempItem = new QListWidgetItem(this);
    //tempItem->setSizeHint(temp->sizeHint());
    tempItem->setSizeHint(QSize(0, 120));
    setItemWidget(tempItem, temp);
}

void ListaArticoli::aggiornaArticolo(int index, const std::string& titolo, const std::string& descrizione, int disponibilita) {
    if (index >= 0 && index < count()) {
        QListWidgetItem* item = this->item(index);
        WidgetArticolo* widgetArticolo = dynamic_cast<WidgetArticolo*>(itemWidget(item));
        if (widgetArticolo) {
            widgetArticolo->setTitolo(titolo);
            widgetArticolo->setDescrizione(descrizione);
            widgetArticolo->setDisponibilita(disponibilita);

            // Aggiorna la visualizzazione dell'articolo nella lista
            itemWidget(item)->update();
        }
    }
}




