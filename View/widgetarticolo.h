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




    /*void setqTitolo(const std::string& titolo="ATTENZIONE: Titolo non inserito");
    void setqDescrizione(const std::string& descrizione="ATTENZIONE: Descrizione non inserita");
    void setqDisponibilita(const int& disponibilita);
    void setTitoloLabel();
    void setDescrizioneLabel();
    void setDisponibilitaLabel();*/
    /* void setCDLabels(int durata, std::string artista, std::string genereMusicale, int numeroBrani);
    void setDVDLabels(int durata, std::string regista, double votoCritica);
    void setManualeLabels(std::string autore, int pagine, std::string editore, std::string argomento);
    void setRomanzoLabels(std::string autore, int pagine, std::string editore, std::string genere);
    void setFumettoLabels(std::string autore, int pagine, std::string editore, int numfumetto);
    void setDurata(int durata);
    void setArtista(std::string artista);
    void setGenereMusicale(std::string genere);
    void setNumeroBrani(int numero);
    void setRegista(std::string regista);
    void setVoto(double voto);
    void setAutore(std::string autore);
    void setPagine(int pagine);
    void setEditore(std::string editore);
    void setGenere(std::string genere);
    void setArgomento(std::string argomento);
    void setNumFumetto(int numero);éarticol */
    /*Disco
    QLabel* getDurataLabel() const;
    //CD
    QLabel* getArtistaLabel() const;
    QLabel* getGenereMusicaleLabel() const;
    QLabel* getNumbraniLabel() const;
    //DVD
    QLabel* getRegistaLabel();
    QLabel* getVotoLabel() const;

    //Libro
    QLabel* getAutoreLabel() const;
    QLabel* getPagineLabel() const;
    QLabel* getEditoreLabel() const;
    //Romanzo
    QLabel* getGenereLabel() const;
    //Manuale
    QLabel* getArgomentoLabel() const;
    //Fumetto
    QLabel* getNumeroLabel() const;*/
};

#endif // WIDGETARTICOLO_H

