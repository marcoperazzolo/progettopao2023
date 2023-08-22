
#include "dvd.h"
#include<iostream>

int main(int argc, char *argv[])
{
    Articolo a("Pane", "pane verde", 3, 2020);
    DVD d("Pane", "pane verde", 3, 2020);
    string x = d.getDescrizione();
    std::cout<< x;

}
