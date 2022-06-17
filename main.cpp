#include <iostream>

using namespace std;

#include "Item.h"
#include "Game.h"
#include "Cuadrante.h"
#include "Principal.h"
#include "Mapa.h"

int main(){
    Game Calabozo_cuthulu;
    Cuadrante cuad1(1);
    Principal granjero(200, 50, "Nicole", 7, 5, 1, "mapa/cuadrante1.txt");

    cuad1.draw_in_coords(7,5,"o");
    cuad1.show_cuadrante(1);

    while(true){
        granjero.move(cuad1);
    }

    //Calabozo_cuthulu.run();

    return 0;
}