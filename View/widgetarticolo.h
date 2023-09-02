#ifndef WIDGETARTICOLO_H
#define WIDGETARTICOLO_H

//#include "articolo.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <string>

class WidgetArticolo : public QWidget {
    Q_OBJECT
private:
    int disponibilità;

    QHBoxLayout* riga;
    QVBoxLayout* testi;

    QLabel* immagineLabel;
    //QPixmap* immagine;

    QLabel* titoloLabel;
    QLabel* descrizioneLabel;
    QLabel* disponibilitaLabel;

    QString qTitolo;
    QString qDescrizione;
    QFont fontTitolo;

public:
    WidgetArticolo(const std::string& titolo="ATTENZIONE: Titolo non inserito", const std::string& descrizione="ATTENZIONE: Descrizione non inserita", int disponibilita=-1, QWidget* parent=nullptr);
    ~WidgetArticolo() { };

    //WidgetArticolo(const WidgetArticolo& wa);
    WidgetArticolo* clone();

    void setTitolo(const std::string& titolo="ATTENZIONE: Titolo non inserito");
    void setDescrizione(const std::string& descrizione="ATTENZIONE: Descrizione non inserita");
    void setDisponibilita(const int& disponibilita);

    std::string getTitolo() const;
    std::string getDescrizione() const;
    int getDisponibilita() const;
    QPixmap* getImmagine();

};

#endif // WIDGETARTICOLO_H

