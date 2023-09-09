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

    WidgetArticolo* widgetItem;
    WidgetArticolo* wasource;
    WidgetArticolo* wadettaglio;

    //FINESTRE E WIDGET CENTRALE
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
    QAction* actionAggiungiArticolo;

    //LAYOUT RICERCA E BOTTONI
    QTextEdit* barraRicerca;
    QPushButton* cercaButton;
    QPushButton* aggiungiArticoloButton;

    //Ricerca
    ListaArticoli* listarisultati;
    string titolocercato;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void refresh();
    void mostraDettagliArticolo(QListWidgetItem* item);
    void apriFinestraAggiunta();
    void aggiungiArticolo(Articolo* art);
    void eliminaArticolo(Articolo* art);

    void cercaButtonPremuto();

    void apriFile();
    void salvaFile();
};

#endif // MAINWINDOW_H
