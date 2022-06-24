#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "Cuadrante.h"
#include "Principal.h"

#ifndef Game_h
#define Game_h

class Game{
    private:
        bool running = false;
        string file_partida;
        string actual_room;
    public:
        void run();
        void initialize();
        void run_nueva_partida(string);
        void run_partida(string);
        void borrar_partida(string);
        void generate_mapa();
        void cargar_partida(string);
};

void Game::run(){
    running = true;
    initialize();
};

void Game::borrar_partida(string archivo){
    ofstream partida(archivo);
    partida << "Nombre_Partida,Nombre_Personaje" << endl;
    partida.close();
}

void Game::run_nueva_partida(string archivo){
    string nombre_partida, nombre_personaje;

    cout << "Nombre del mundo (Una sola palabra): ";
    cin >> nombre_partida;

    cout << "Nombre (Una sola palabra): ";
    cin >> nombre_personaje;

    ofstream partida(archivo);
    partida << nombre_partida << "," << nombre_personaje << endl;
    partida.close();
}

void Game::run_partida(string archivo){
    string name_char, name_mundo, str_input, items, r;

    ifstream partida(archivo);
    getline(partida, str_input);

    stringstream ss(str_input);
    getline(ss, name_mundo, ',');
    getline(ss, name_char, ',');

    cout << "Bienvenido de nuevo " << name_char << endl;

    getline(partida, str_input);
    getline(partida, items);

    partida.close();

    stringstream ssm(str_input);

    getline(ssm, actual_room, ',');
    getline(ssm, r, ',');

    Cuadrante mapa(stoi(r));

    mapa.set_length();
    mapa.set_height();

    Principal granjero(100, 20, name_char, mapa.get_length()/2, mapa.get_height()-2, mapa.get_room(), mapa.get_txt());

    stringstream ssi(items);

    for(int i = 0; i < 2; i++){
        getline(ssi, str_input, ',');
        Item it_aux(50, 5, str_input);
        granjero.add_item(it_aux);
    }
    
    mapa.add_personaje(granjero);
    mapa.show_cuadrante(stoi(r));

    while(true){
        granjero.move(mapa);
    }
}

void Game::initialize(){
    string ans;
    ifstream partida;
    cout << "BIENVENIDO AL CALABOZO DE CUTHULU" << endl << endl;
    cout << "a) Nueva partida" << endl;
    cout << "b) Cargar partida" << endl;
    cout << "c) Borrar partida" << endl;
    cout << "d) Cerrar" << endl;
    cin >> ans;

    if (ans == "a" or ans == "A")
    {
        string str_input;

        partida.open("Partida1.txt");

        getline(partida,str_input);

        partida.close();

        if(str_input == "Nombre_Partida,Nombre_Personaje"){

            run_nueva_partida("Partida1.txt");

        } else{
                    cout << "No hay espacio para mas partidas!!! Borra una ya creada para tener espacio de nuevo." << endl;
                    initialize();
            }
    }else if (ans == "b" or ans =="B")
    {
        string str_input, mundo1, mundo2, mundo3, partida_txt;
        char mundo;

        partida.open("Partida1.txt");
        getline(partida, str_input);
        stringstream ss(str_input);
        getline(ss, mundo1, ',');
        partida.close();

        partida.open("Partida2.txt");
        getline(partida, str_input);
        stringstream ss2(str_input);
        getline(ss2, mundo2, ',');
        partida.close();

        partida.open("Partida3.txt");
        getline(partida, str_input);
        stringstream ss3(str_input);
        getline(ss3, mundo3, ',');
        partida.close();

        cout << "Mundos: " << endl;
        cout << "a) " << mundo1 << endl;

        cin >> mundo;

        switch (mundo)
        {
        case 'a':
            run_partida("Partida1.txt");
            break;
        default:
            break;
        }
    }else if (ans == "c" or ans == "C")
    {
        string str_input, mundo1, mundo2, mundo3, partida_txt;
        char mundo;

        partida.open("Partida1.txt");
        getline(partida, str_input);
        stringstream ss(str_input);
        getline(ss, mundo1, ',');
        partida.close();

        cout << "Mundos: " << endl;
        cout << "a) " << mundo1 << endl;

        cin >> mundo;

        switch (mundo)
        {
        case 'a':
            borrar_partida("Partida1.txt");
            break;
        default:
            break;
        }
    } else if(ans == "d" or ans == "D"){
        cout << "Saliendo..." << endl;
    }
}

void Game::cargar_partida(string archivo){
    string str_input, mundo_txt;
    ifstream partida(archivo);

    while(true){
        getline(partida, str_input);
        mundo_txt = str_input + "\n";
        if(partida.eof()){break;};
    }
}

#endif