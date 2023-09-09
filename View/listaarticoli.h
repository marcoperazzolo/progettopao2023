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
    void aggiornaListadaLista(Lista<Articolo>* lis);
    ~ListaArticoli();
    Lista<Articolo>* getLista() const;
public slots:
    //OPERAZIONI SUGLI ARTICOLI
    void aggiungiArticolo(Articolo* articolo);
    //void aggiungiWidgetArticolo(Articolo* articolo);
    void aggiungiWidgetArticolo(WidgetArticolo* widgetArticolo);
    void eliminaArticolo(Articolo* art);

    //REFRESH
    void refreshLista();
    void refreshLista(Lista<Articolo>* lis);
    //void setModel();
    void clear();
    //void cercaDaBarra(string titolo, MainWindow* parent = nullptr);
    //Lista<Articolo>* creaListaRisultati(string titolo);

};

#endif // LISTAARTICOLI_H
