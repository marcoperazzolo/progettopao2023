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
    QHBoxLayout* riga;
    QVBoxLayout* testi;

    QLabel* immagineLabel;
    QPixmap immagine;

    QLabel* titoloLabel;
    QLabel* descrizioneLabel;
    QLabel* disponibilitaLabel;

    QString qTitolo;
    QString qDescrizione;
    QFont fontTitolo;

    //Disco
    QLabel* durataLabel;
    //CD
    QLabel* artistaLabel;
    QLabel* genereMusicaleLabel;
    QLabel* numbraniLabel;
    //DVD
    QLabel* registaLabel;
    QLabel* votoLabel;

    //Libro
    QLabel* autoreLabel;
    QLabel* pagineLabel;
    QLabel* editoreLabel;
    //Romanzo
    QLabel* genereLabel;
    //Manuale
    QLabel* argomentoLabel;
    //Fumetto
    QLabel* numeroLabel;

public:
    //WidgetArticolo(const std::string& titolo="ATTENZIONE: Titolo non inserito", const std::string& descrizione="ATTENZIONE: Descrizione non inserita", int disponibilita=-1, QWidget* parent=nullptr);
    WidgetArticolo(Articolo* art=nullptr, QWidget* parent=nullptr);

    ~WidgetArticolo() { };

    //WidgetArticolo(const WidgetArticolo& wa);
    WidgetArticolo* clone();

    void setTitolo(const std::string& titolo);
    void setDescrizione(const std::string& descrizione);
    void setDisponibilita(const int& disponibilita);


    /*void setqTitolo(const std::string& titolo="ATTENZIONE: Titolo non inserito");
    void setqDescrizione(const std::string& descrizione="ATTENZIONE: Descrizione non inserita");
    void setqDisponibilita(const int& disponibilita);
    void setTitoloLabel();
    void setDescrizioneLabel();
    void setDisponibilitaLabel();*/
    void setCDLabels(int durata, std::string artista, std::string genereMusicale, int numeroBrani);
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
    void setNumFumetto(int numero);


    Articolo* getArticolo() const;
    QString getqTitolo() const;
    QString getqDescrizione() const;
    QLabel* getTitoloLabel() const;
    QLabel* getDescrizioneLabel() const;
    QLabel* getDisponibilitaLabel() const;
    QPixmap getImmagine();

    //Disco
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
    QLabel* getNumeroLabel() const;

    void refreshWidget(Articolo* articolo);
    void refresh();

};

#endif // WIDGETARTICOLO_H

