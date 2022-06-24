#include <vector>

#ifndef Personaje_h
#define Personaje_h

class Personaje{
    private:
        string figure;
        vector<Item> Bag;
        int vida;
        int dano;
        string nombre;
        int coord_x, coord_y;
    public:
        Personaje();
        Personaje(string, int, int, string, int, int);
        void show_bag();
        void add_item(Item);
        void set_figure(string);
        string get_figure();
        int get_coord_x();
        void set_coord_x(int);
        int get_coord_y();
        void set_coord_y(int);
        vector<Item> get_bagV();
};

Personaje::Personaje(){
    figure = 'n';
    vida = 0;
    dano = 0;
    nombre = "N/A";
    coord_x = 0;
    coord_y = 0;
}

Personaje::Personaje(string f, int v, int d, string n, int x, int y){
    figure = f;
    vida = v;
    dano = d;
    nombre = n;
    coord_x = x;
    coord_y = y;
}

vector<Item> Personaje::get_bagV(){
    return Bag;
}

string Personaje::get_figure(){
    return figure;
}

void Personaje::set_figure(string f){
    figure = f;
}

int Personaje::get_coord_x(){
    return coord_x;
}

void Personaje::set_coord_x(int x){
    coord_x = x;
}

int Personaje::get_coord_y(){
    return coord_y;
}

void Personaje::set_coord_y(int y){
    coord_y = y;
}

void Personaje::add_item(Item it1){
    Bag.push_back(it1);
}

void Personaje::show_bag(){
    for(int i = 0;i < Bag.size(); i++){
        Bag[0].show_item();
    }
}


#endif