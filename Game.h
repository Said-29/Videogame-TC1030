#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

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
    string name_char, name_mundo, str_input;

    ifstream partida(archivo);
    getline(partida, str_input);

    stringstream ss(str_input);
    getline(ss, name_mundo, ',');
    getline(ss, name_char, ',');

    cout << "Bienvenido de nuevo" << name_char << endl;
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

            partida.open("Partida2.txt");
            getline(partida,str_input);
            partida.close();

            if(str_input == "Nombre_Partida,Nombre_Personaje"){

                run_nueva_partida("Partida2.txt");

            } else {

                partida.open("Partida3.txt");
                getline(partida,str_input);
                partida.close();

                if(str_input == "Nombre_Partida,Nombre_Personaje"){

                    run_nueva_partida("Partida3.txt");

                } else {
                    cout << "No hay espacio para mas partidas!!! Borra una ya creada para tener espacio de nuevo." << endl;
                }
            }
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
        cout << "b) " << mundo2 << endl;
        cout << "c) " << mundo3 << endl;
        cin >> mundo;

        switch (mundo)
        {
        case 'a':
            run_partida("Partida1.txt");
            break;
        case 'b':
            run_partida("Partida2.txt");
            break;
        case 'c':
            run_partida("Partida3.txt");
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
        cout << "b) " << mundo2 << endl;
        cout << "c) " << mundo3 << endl;
        cin >> mundo;

        switch (mundo)
        {
        case 'a':
            borrar_partida("Partida1.txt");
            break;
        case 'b':
            borrar_partida("Partida2.txt");
            break;
        case 'c':
            borrar_partida("Partida3.txt");
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