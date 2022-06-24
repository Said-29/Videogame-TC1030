#include "Personaje.h"

#pragma once

class Principal: public Personaje{
    private:
        string figure;
        int room;
        string room_txt;
    public:
        Principal();
        Principal(int, int, string, int, int, int, string);
        void consume_item();
        void move(Cuadrante);
        int get_room_p();
        void set_room_p(int);
        string get_bag();
};

Principal::Principal(): Personaje(){
    figure = "o";
    room = 0;
    room_txt = "N/A";
}

Principal::Principal(int v, int d, string n, int x, int y, int r, string rt): Personaje("o", v, d, n, x, y){
    room = r;
    room_txt = rt;
}

string Principal::get_bag(){
    string bag;
    vector<Item> mochila = get_bagV();
    for(int i = 0; i < mochila.size(); i++){
        bag += mochila[i].get_nombre() + ",";
    }

    return bag;
}

void Principal::move(Cuadrante cuad){
    char ans;
    string figura;
    string arch1, str_input;
    ifstream partida;
    ofstream partida1;
    int x, y, size_x, size_y;
    int i =0;
    arch1 = "";

    x = get_coord_x();
    y = get_coord_y();
    figura = get_figure();

    cout << "Cuarto: " << room << endl;

    cuad.set_cuadrante(room_txt);

    cout << "Up [^]" << endl;
    cout << "Down [v]" << endl;
    cout << "Left [<]" << endl;
    cout << "Right [>]" << endl;
    cout << "Ver inventario [I]" << endl;

    cin >> ans;
    switch (ans){
    case '^':
        if(cuad.get_char(x, y-1) == " "){
            cuad.errase_in_coords(x, y);
            cuad.draw_in_coords(x, y-1, figura);
            set_coord_y(y-1);
        } else if(cuad.get_char(x, y-1) == "x"){
            cout << "No puedes pasar por aqui" << endl;
        } else if(cuad.get_char(x, y-1) == "^"){
            cuad.errase_in_coords(x,y);

            room_txt = cuad.get_cuad_arriba();

            cuad.set_cuadrante(room_txt);

            cuad.set_height();
            cuad.set_length();

            size_x = cuad.get_length();
            size_y = cuad.get_height();

            set_coord_x(size_x / 2);
            set_coord_y(size_y - 2);

            room = cuad.get_room();
            cuad.draw_in_coords(get_coord_x(), get_coord_y(), figura);

            if(room_txt == "mapa/cuadrante22.txt"){
                cout << "Has entrado al laberinto, no podras escapar hasta llegar al corazon de cthulu!!!" << endl << endl;
            }

        } else if (cuad.get_char(x, y-1) == "E") {

            cuad.errase_in_coords(x, y);
            Item espada(50, 5, "Espada Excalibur");
            cuad.draw_in_coords(x, y-1, figura);
            set_coord_y(y-1);
            add_item(espada);
            cout << "Has encontrado la Espada Excalibur!! Estas cada vez mas cerca de tu meta." << endl << endl;

        } else if (cuad.get_char(x, y-1) == "C") {

            cuad.errase_in_coords(x, y);
            Item pocion(10, 1, "Pocion de curacion");
            cuad.draw_in_coords(x, y-1, figura);
            set_coord_y(y-1);
            add_item(pocion);
            cout << "Has encontrado una pocion de curacion, ahora tu vida ha aumentado en 10." << endl << endl;

        } else if (cuad.get_char(x, y-1) == "D") {

            cuad.errase_in_coords(x, y);
            Item escudo(30, 5, "Escudo de Doran");
            cuad.draw_in_coords(x, y-1, figura);
            set_coord_y(y-1);
            add_item(escudo);
            cout << "Posees en tus manos el Escudo de Doran, si tienes la Espada Excalibur sientete con la libertad de entrar al laberinto." << endl << endl;

        } else if (cuad.get_char(x, y-1) == "A") {
            cuad.errase_in_coords(x, y);
            Item anillo(30, 1, "Anillo de Doran");
            cuad.draw_in_coords(x, y-1, figura);
            set_coord_y(y-1);
            add_item(anillo);
            cout << "Has encontrado el anillo de Doran, sientes como la magia fluye en ti." << endl << endl;

        } else if (cuad.get_char(x, y-1) == "*"){
            cout << "Felicidades!!!! Has completado el Juego y derrotado a Cthulu.\nAhora eres libre y podras regresar al mundo de los vivos\n"; 
            cout << "Pero no te confies, recuerda que siempre tienes un ojo detras de ti." << endl;
            cout << "Saliendo...";
            exit(1);
        } else {
            cout << "No se puede pasar por aqui" << endl;
        }

        system("cls");

        cuad.show_cuadrante(room);
        break;
    case 'v':
        if(cuad.get_char(x, y+1) == " "){
            cuad.errase_in_coords(x, y);
            cuad.draw_in_coords(x, y+1, figura);
            set_coord_y(y+1);
        } if(cuad.get_char(x, y+1) == "v"){
            cuad.errase_in_coords(x,y);

            room_txt = cuad.get_cuad_abajo();

            cuad.set_cuadrante(room_txt);

            cuad.set_height();
            cuad.set_length();

            size_x = cuad.get_length();
            size_y = cuad.get_height();

            set_coord_x(size_x / 2);
            set_coord_y(1);

            room = cuad.get_room();
            cuad.draw_in_coords(get_coord_x(), get_coord_y(), figura);

        } else if (cuad.get_char(x, y+1) == "E") {

            cuad.errase_in_coords(x, y);
            Item espada(50, 5, "Espada Excalibur");
            cuad.draw_in_coords(x, y+1, figura);
            set_coord_y(y+1);
            add_item(espada);
            cout << "Has encontrado la Espada Excalibur!! Estas cada vez mas cerca de tu meta." << endl << endl;

        } else if (cuad.get_char(x, y+1) == "C") {

            cuad.errase_in_coords(x, y);
            Item pocion(10, 1, "Pocion de curacion");
            cuad.draw_in_coords(x, y+1, figura);
            set_coord_y(y+1);
            add_item(pocion);
            cout << "Has encontrado una pocion de curacion, ahora tu vida ha aumentado en 10." << endl << endl;

        } else if (cuad.get_char(x, y+1) == "D") {

            cuad.errase_in_coords(x, y);
            Item escudo(30, 5, "Escudo de Doran");
            cuad.draw_in_coords(x, y+1, figura);
            set_coord_y(y-1);
            add_item(escudo);
            cout << "Posees en tus manos el Escudo de Doran, si tienes la Espada Excalibur sientete con la libertad de entrar al laberinto." << endl << endl;

        } else if (cuad.get_char(x, y+1) == "A") {
            cuad.errase_in_coords(x, y);
            Item anillo(30, 1, "Anillo de Doran");
            cuad.draw_in_coords(x, y+1, figura);
            set_coord_y(y+1);
            add_item(anillo);
            cout << "Has encontrado el anillo de Doran, sientes como la magia fluye en ti." << endl << endl;

        } else if (cuad.get_char(x, y+1) == "*"){
            cout << "Felicidades!!!! Has completado el Juego y derrotado a Cthulu.\nAhora eres libre y podras regresar al mundo de los vivos\n"; 
            cout << "Pero no te confies, recuerda que siempre tienes un ojo detras de ti." << endl;
            cout << "Saliendo...";
            system("cls");
            exit(1);
        } else {
            cout << "No se puede pasar por aqui" << endl;
        }

        system("cls");

        cuad.show_cuadrante(room);
        break;
    case '<':
        if(cuad.get_char(x-1, y) == " "){
            cuad.errase_in_coords(x, y);
            cuad.draw_in_coords(x-1, y, figura);
            set_coord_x(x-1); 
        } else if(cuad.get_char(x-1, y) == "<"){
            cuad.errase_in_coords(x,y);

            room_txt = cuad.get_cuad_izquierda();

            cuad.set_cuadrante(room_txt);

            cuad.set_height();
            cuad.set_length();

            size_x = cuad.get_length();
            size_y = cuad.get_height();

            set_coord_x(size_x - 3);
            set_coord_y(size_y / 2);

            room = cuad.get_room();
            cuad.draw_in_coords(get_coord_x(), get_coord_y(), figura);
        } else if (cuad.get_char(x-1, y) == "E") {

            cuad.errase_in_coords(x, y);
            Item espada(50, 5, "Espada Excalibur");
            cuad.draw_in_coords(x-1, y, figura);
            set_coord_x(x-1);
            add_item(espada);
            cout << "Has encontrado la Espada Excalibur!! Estas cada vez mas cerca de tu meta." << endl << endl;

        } else if (cuad.get_char(x-1, y) == "C") {

            cuad.errase_in_coords(x, y);
            Item pocion(10, 1, "Pocion de curacion");
            cuad.draw_in_coords(x-1, y, figura);
            set_coord_x(x-1);
            add_item(pocion);
            cout << "Has encontrado una pocion de curacion, ahora tu vida ha aumentado en 10." << endl << endl;

        } else if (cuad.get_char(x-1, y) == "D") {

            cuad.errase_in_coords(x, y);
            Item escudo(30, 5, "Escudo de Doran");
            cuad.draw_in_coords(x, x-1, figura);
            set_coord_x(x-1);
            add_item(escudo);
            cout << "Posees en tus manos el Escudo de Doran, si tienes la Espada Excalibur sientete con la libertad de entrar al laberinto." << endl << endl;

        } else if (cuad.get_char(x-1, y) == "A") {
            cuad.errase_in_coords(x, y);
            Item anillo(30, 1, "Anillo de Doran");
            cuad.draw_in_coords(x-1, y, figura);
            set_coord_x(x-1);
            add_item(anillo);
            cout << "Has encontrado el anillo de Doran, sientes como la magia fluye en ti." << endl << endl;

        } else if (cuad.get_char(x-1, y) == "*"){
            cout << "Felicidades!!!! Has completado el Juego y derrotado a Cthulu.\nAhora eres libre y podras regresar al mundo de los vivos\n"; 
            cout << "Pero no te confies, recuerda que siempre tienes un ojo detras de ti." << endl;
            cout << "Saliendo...";
            system("cls");
            exit(1);
        } else {
            cout << "No se puede pasar por aqui" << endl;
        }

        system("cls");

        cuad.show_cuadrante(room);
        break;
    case '>':
        if(cuad.get_char(x+1, y) == " "){
            cuad.errase_in_coords(x, y);
            cuad.draw_in_coords(x+1, y, figura);
            set_coord_x(x+1);
        } else if (cuad.get_char(x+1, y) == ">"){
            cuad.errase_in_coords(x,y);

            room_txt = cuad.get_cuad_derecha();

            cuad.set_cuadrante(room_txt);

            cuad.set_height();
            cuad.set_length();

            size_x = cuad.get_length();
            size_y = cuad.get_height();

            set_coord_x(1);
            set_coord_y(size_y / 2);

            room = cuad.get_room();
            cuad.draw_in_coords(get_coord_x(), get_coord_y(), figura);
        } else if (cuad.get_char(x+1, y) == "E") {

            cuad.errase_in_coords(x, y);
            Item espada(50, 5, "Espada Excalibur");
            cuad.draw_in_coords(x+1, y, figura);
            set_coord_x(x+1);
            add_item(espada);

        } else if (cuad.get_char(x+1, y) == "C") {

            cuad.errase_in_coords(x, y);
            Item pocion(10, 1, "Pocion de curacion");
            cuad.draw_in_coords(x+1, y, figura);
            set_coord_x(x+1);
            add_item(pocion);

        } else if (cuad.get_char(x+1, y) == "D") {

            cuad.errase_in_coords(x, y);
            Item escudo(30, 5, "Escudo de Doran");
            cuad.draw_in_coords(x+1, y, figura);
            set_coord_x(x+1);
            add_item(escudo);

        } else if (cuad.get_char(x+1, y) == "A") {
            cuad.errase_in_coords(x, y);
            Item anillo(30, 1, "Anillo de Doran");
            cuad.draw_in_coords(x+1, y, figura);
            set_coord_x(x+1);
            add_item(anillo);
        }
        system("cls");
        cuad.show_cuadrante(room);
        break;
    case 'I':
        show_bag();
    default:
        break;
    }
}

int Principal::get_room_p(){
    return room;
}

void Principal::set_room_p(int r){
    room = r;
}