#ifndef LISTAARTICOLI_H
#define LISTAARTICOLI_H

#include <QListWidget>

//?
#include "widgetarticolo.h"

class ListaArticoli : public QListWidget {
    Q_OBJECT
public:
    ListaArticoli(QWidget* parent = nullptr);
    ~ListaArticoli() { };

    //void aggiungiArticolo(Articolo* a);
    void aggiungiArticolo(std::string tit="ATTENZIONE: Titolo non inserito", std::string desc="ATTENZIONE: Descrizione non inserita", int disp=-1);
    void aggiornaArticolo(int index, const std::string& titolo, const std::string& descrizione, int disponibilita);
};

#endif // LISTAARTICOLI_H
