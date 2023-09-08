#ifndef LISTAARTICOLI_H
#define LISTAARTICOLI_H

#include <QListWidget>
#include "../Model/lista.h"

//?
#include "widgetarticolo.h"

class ListaArticoli : public QListWidget {
    Q_OBJECT
private:
    Lista<Articolo>* model;

public:
    //COSTRUTTORI
    ListaArticoli(QWidget* parent = nullptr);
    ListaArticoli(Lista<Articolo>* lis, QWidget* parent = nullptr);
    ~ListaArticoli();

public slots:
    //OPERAZIONI SUGLI ARTICOLI
    void aggiungiArticolo(Articolo* articolo);
    //void aggiungiWidgetArticolo(Articolo* articolo);
    void aggiungiWidgetArticolo(WidgetArticolo* widgetArticolo);
    void eliminaArticolo(Articolo* art);

    //REFRESH
    void refreshLista();
};

#endif // LISTAARTICOLI_H
