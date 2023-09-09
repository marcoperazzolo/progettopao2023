#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QtCore/QVariant> ??
#include <QMainWindow>
#include <QWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include <QTextEdit>
#include <QPushButton>

#include <QListWidget>
#include <QLabel>

#include "widgetarticolo.h"
#include "listaarticoli.h"
#include "finestradettagliarticolo.h"
#include "finestraaggiungiarticolo.h"

#include<QDialog>
#include<QFileDialog>
#include<QDir>


class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    ListaArticoli* listaarticoli;
    FinestraDettagliArticolo* finestradettarticolo;
    //FinestraAggiungiArticolo* finestraaggiunta;

    WidgetArticolo* widgetItem;
    WidgetArticolo* wasource;
    WidgetArticolo* wadettaglio;

    //FINESTRE E WIDGET CENTRALE
    //QMainWindow w;
    QWidget* centralWidget;

    //LAYOUT
    QVBoxLayout* mainLayout;
    QHBoxLayout* searchLayout;

    //BARRA DEL MENU
    // Barra e Menu
    QMenuBar* menuBar;
    QMenu* menuBiblioteca;
    // Actions
    QAction* actionApri;
    QAction* actionSalva;

    //LAYOUT RICERCA E BOTTONI
    QTextEdit* barraRicerca;
    QPushButton* cercaButton;
    QPushButton* aggiungiArticoloButton;

    ListaArticoli* listarisultati;
    string titolocercato;
    //SCROLLBAR E OGGETTI
    //QListWidget* listaOggetti = new QListWidget(centralWidget);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    //void aggiungiArticolo(Articolo* a);
    //void aggiungiArticolo(std::string tit="!Titolo non inizializzato!", std::string desc="!Descrizione non inizializzata", int disp=0);

public slots:
    void refresh(); //serve a refreshare la lista oggetti
    void mostraDettagliArticolo(QListWidgetItem* item);
    void apriFinestraAggiunta();
    void aggiungiArticolo(Articolo* art);
    void eliminaArticolo(Articolo* art);

    void cercaButtonPremuto();

    //void mostraNuovaLista(ListaArticoli* nuovavista);
    //void ripristinaVista();

    void apriFile();
    void salvaFile();
};

#endif // MAINWINDOW_H
