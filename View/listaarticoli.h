#ifndef LISTAARTICOLI_H
#define LISTAARTICOLI_H

#include <QListWidget>
#include "../Model/lista.h"
#include "widgetarticolo.h"

class ListaArticoli : public QListWidget {
    Q_OBJECT
private:
    Lista<Articolo>* model;

public:
    //COSTRUTTORI
    ListaArticoli(QWidget* parent = nullptr);
    ~ListaArticoli();

    void aggiornaListadaLista(Lista<Articolo>* lis);
    Lista<Articolo>* getLista() const;

public slots:
    //OPERAZIONI SUGLI ARTICOLI
    void aggiungiArticolo(Articolo* articolo);
    void aggiungiWidgetArticolo(WidgetArticolo* widgetArticolo);
    void eliminaArticolo(Articolo* art);

    //REFRESH
    void refreshLista();
    void refreshLista(Lista<Articolo>* lis);
    void clear();

};

#endif // LISTAARTICOLI_H
