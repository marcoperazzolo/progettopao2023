#ifndef LISTAARTICOLI_H
#define LISTAARTICOLI_H

#include <QListWidget>
#include "../Model/lista.h"

//?
#include "widgetarticolo.h"

class ListaArticoli : public QListWidget {
    Q_OBJECT
private:
    Lista<Articolo>* lista;
    std::vector<WidgetArticolo*> widgetarticoli;
public:
    ListaArticoli(QWidget* parent = nullptr);
    ListaArticoli(Lista* lis, QWidget* parent = nullptr);

    ~ListaArticoli() { };
    void eliminaArticolo(WidgetArticolo* wa);
    void aggiungiArticolo(Articolo* articolo);

    void aggiungiWidgetArticolo(Articolo* articolo);
    void aggiungiWidgetArticolo(WidgetArticolo* widgetArticolo);
    void aggiungiWidgetArticolo(Articolo* articolo, WidgetArticolo* widgetArticolo);
    void aggiungiArticolo(std::string tit="ATTENZIONE: Titolo non inserito", std::string desc="ATTENZIONE: Descrizione non inserita", int disp=-1);
    void aggiornaArticolo(int index, const std::string& titolo, const std::string& descrizione, int disponibilita);
};

#endif // LISTAARTICOLI_H
