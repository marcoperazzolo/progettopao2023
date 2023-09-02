#include "mainwindow.h"
#include "finestradettagliarticolo.h"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
    //FINESTRA E WIDGET
    w.setWindowTitle("Progetto Biblioteca");
    w.setGeometry(100, 100, 1200, 400);
    centralWidget = new QWidget(&w);
    w.setCentralWidget(centralWidget);

    //LAYOUT
    mainLayout = new QVBoxLayout(centralWidget);
    searchLayout = new QHBoxLayout(centralWidget);

    //BARRA DEL MENU
    menuBar = new QMenuBar();
    menuBiblioteca = new QMenu("Biblioteca...", menuBar);
    //Actions: le aggiungo al menu
    actionApri = new QAction("Apri", menuBiblioteca);
    actionSalva = new QAction("Salva", menuBiblioteca);     //actionAggiungiArticolo = new QAction("Aggiungi Articolo, menuBiblioteca);
    menuBiblioteca->addAction(actionApri);
    menuBiblioteca->addAction(actionSalva);                //menuBiblioteca->addAction(actionAggiungiArticolo);
    //aggiungo Menu alla barra
    menuBar->addMenu(menuBiblioteca);

    //LAYOUT RICERCA E BOTTONI
    barraRicerca = new QTextEdit(centralWidget);
    barraRicerca->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Imposta la politica di ridimensionamento
    barraRicerca->setMaximumHeight(barraRicerca->fontMetrics().height()); // Imposta l'altezza massima
    //barraRicerca->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Rimuovi la barra di scorrimento orizzontale
    barraRicerca->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Rimuovi la barra di scorrimento verticale
    //barraRicerca->setStyleSheet("QTextEdit { padding: 1px 0; }"); // Imposta il padding per evitare i movimenti leggeri durante la scrittura

    cercaButton = new QPushButton("Cerca", centralWidget);
    aggiungiArticoloButton = new QPushButton("Aggiungi Articolo", centralWidget);
    searchLayout->addWidget(barraRicerca);
    searchLayout->addWidget(cercaButton);
    searchLayout->addWidget(aggiungiArticoloButton);

    //LISTA ARTICOLI
    lista = new ListaArticoli(centralWidget);
    lista->aggiungiArticolo("Oppenheimer", "Parla della storia della bomba atomica", 3);
    lista->aggiungiArticolo("Barbie", "Parla di femminismo del cazzo", 6);
    lista->aggiungiArticolo("Titolo", "Descrizione  descrizione descrizione descrizione descrizione descrizione descrizione descrizione descrizione descrizione descrizione descrizione descrizione descrizione", 100);


    //SETTING FINALE LAYOUT
    mainLayout->addWidget(menuBar);
    mainLayout->addLayout(searchLayout);
    //scrollArea->setWidget(listaOggetti);
    mainLayout->addWidget(lista);
    //listaOggetti->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    connect(lista, &ListaArticoli::itemDoubleClicked, this, &MainWindow::mostraDettagliArticolo);

    //SHOW
    w.show();
}

MainWindow::~MainWindow() {};

void MainWindow::mostraDettagliArticolo(QListWidgetItem* item) {
    WidgetArticolo* widgetArticolo = dynamic_cast<WidgetArticolo*>(lista->itemWidget(item));
    if (widgetArticolo) {
       WidgetArticolo* wa = widgetArticolo->clone();
       FinestraDettagliArticolo* dialog = new FinestraDettagliArticolo(wa, this);
       //dialog->apriFinestraModifica(); // Passa l'istanza di ListaArticoli

       dialog->exec();
    }
}


