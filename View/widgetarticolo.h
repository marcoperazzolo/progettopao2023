#ifndef WIDGETARTICOLO_H
#define WIDGETARTICOLO_H

#include "../Model/articolo.h"
#include "../Model/cd.h"
#include "../Model/dvd.h"
#include "../Model/romanzo.h"
#include "../Model/fumetto.h"
#include "../Model/manuale.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <string>

class WidgetArticolo : public QWidget {
    Q_OBJECT
private:
    Articolo* articolo;

    //Layout
    QHBoxLayout* riga;
    QVBoxLayout* testi;

    //Labels
    QLabel* titoloLabel;
    QLabel* descrizioneLabel;
    QLabel* disponibilitaLabel;
    QFont fontTitolo;

    //Immagine
    QLabel* immagineLabel;
    QPixmap immagine;

public:
    //COSTRUTTORI E DISTRUTTORI
    WidgetArticolo(Articolo* art, QWidget* parent=nullptr);
    ~WidgetArticolo() = default;

    //REFRESH
    void refreshWidget(Articolo* art);
    void refreshWidget();

    //GETTERS
    Articolo* getArticolo() const;
    QLabel* getTitoloLabel() const;
    QLabel* getDescrizioneLabel() const;
    QLabel* getDisponibilitaLabel() const;
    QPixmap getImmagine() const;

    //SETTERS
    void setTitoloLabel(const std::string& titolo);
    void setDescrizioneLabel(const std::string& descrizione);
    void setDisponibilitaLabel(const int& disponibilita);
    void setImmagine(const std::string& tipo);
};

#endif // WIDGETARTICOLO_H

