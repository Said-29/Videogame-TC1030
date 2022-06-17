#include "Mapa.h"
#include "Personaje.h"

class Cuadrante: public Mapa{
    private:
        vector<string> cuadrante;
        string name_cuad_txt;
        string last_line;
        string cuad_arriba;
        string cuad_abajo;
        string cuad_derecha;
        string cuad_izquierda;
        int height, length;
        int room;
    public:
        Cuadrante();
        Cuadrante(int r);
        void show_cuadrante(int r);
        void add_personaje(Personaje);
        void set_cuadrante(string);
        void draw_in_coords(int, int, string);
        void errase_in_coords(int, int);
        string get_char(int, int);
        void set_txt(string);
        string get_txt();
        vector<string> get_cuadrante();
        void set_cuad_arriba(string);
        string get_cuad_arriba();
        void set_cuad_abajo(string);
        string get_cuad_abajo();
        void set_cuad_derecha(string);
        string get_cuad_derecha();
        void set_cuad_izquierda(string);
        string get_cuad_izquierda();
        void open(string);
        void set_cuad_anexos();
        void set_room();
        int get_room();
        void set_height();
        int get_height();
        void set_length();
        int get_length();
};

Cuadrante::Cuadrante(){
    name_cuad_txt = "N/A";
}

Cuadrante::Cuadrante(int r){
    room = r;
    switch (r)
    {
    case 1:
        set_cuadrante("mapa/cuadrante1.txt");
        break;
    case 2:
        set_cuadrante("mapa/cuadrante2.txt");
        break;
    case 3:
        set_cuadrante("mapa/cuadrante3.txt");
        break;
    case 4:
        set_cuadrante("mapa/cuadrante4.txt");
        break;
    case 5:
        set_cuadrante("mapa/cuadrante5.txt");
        break;
    case 6:
        set_cuadrante("mapa/cuadrante6.txt");
        break;
    case 7:
        set_cuadrante("mapa/cuadrante7.txt");
        break;
    case 8:
        set_cuadrante("mapa/cuadrante8.txt");
        break;
    case 9:
        set_cuadrante("mapa/cuadrante9.txt");
        break;
    case 10:
        set_cuadrante("mapa/cuadrante10.txt");
        break;
    case 11:
        set_cuadrante("mapa/cuadrante11.txt");
        break;
    case 12:
        set_cuadrante("mapa/cuadrante12.txt");
        break;
    case 13:
        set_cuadrante("mapa/cuadrante13.txt");
        break;
    case 14:
        set_cuadrante("mapa/cuadrante14.txt");
        break;
    case 15:
        set_cuadrante("mapa/cuadrante15.txt");
        break;
    case 16:
        set_cuadrante("mapa/cuadrante16.txt");
        break;
    case 17:
        set_cuadrante("mapa/cuadrante17.txt");
        break;
    case 18:
        set_cuadrante("mapa/cuadrante18.txt");
        break;
    case 19:
        set_cuadrante("mapa/cuadrante19.txt");
        break;
    case 20:
        set_cuadrante("mapa/cuadrante20.txt");
        break;
    case 21:
        set_cuadrante("mapa/cuadrante21.txt");
        break;
    case 22:
        set_cuadrante("mapa/cuadrante22.txt");
        break;
    default:
        break;
    }
}

void Cuadrante::set_cuad_anexos(){
    switch (room)
    {
    case 1:
        set_cuad_arriba("mapa/cuadrante2.txt");
        set_cuad_abajo("N/A");
        set_cuad_derecha("N/A");
        set_cuad_izquierda("N/A");
        break;
    case 2:
        set_cuad_arriba("mapa/cuadrante22.txt");
        set_cuad_derecha("mapa/cuadrante3.txt");
        set_cuad_izquierda("mapa/cuadrante21.txt");
        set_cuad_abajo("N/A");
        break;
    case 3:
        set_cuad_derecha("mapa/cuadrante4.txt");
        set_cuad_izquierda("mapa/cuadrante2.txt");
        set_cuad_arriba("N/A");
        set_cuad_abajo("N/A");
        break;
    case 4:
        set_cuad_derecha("mapa/cuadrante5.txt");
        set_cuad_izquierda("mapa/cuadrante3.txt");
        set_cuad_abajo("N/A");
        set_cuad_arriba("N/A");
        break;
    case 5:
        set_cuad_arriba("mapa/cuadrante6.txt");
        set_cuad_izquierda("mapa/cuadrante4.txt");
        set_cuad_derecha("N/A");
        set_cuad_abajo("N/A");
        break;
    case 6:
        set_cuad_arriba("mapa/cuadrante7.txt");
        set_cuad_abajo("mapa/cuadrante5.txt");
        set_cuad_derecha("N/A");
        set_cuad_izquierda("N/A");
        break;
    case 7:
        set_cuad_arriba("mapa/cuadrante8.txt");
        set_cuad_abajo("mapa/cuadrante6.txt");
        set_cuad_derecha("N/A");
        set_cuad_izquierda("map/cuadrante22.txt");
        break;
    case 8:
        set_cuad_arriba("mapa/cuadrante9.txt");
        set_cuad_abajo("mapa/cuadrante7.txt");
        set_cuad_izquierda("N/A");
        set_cuad_derecha("N/A");
        break;
    case 9:
        set_cuad_arriba("N/A");
        set_cuad_abajo("mapa/cuadrante8.txt");
        set_cuad_izquierda("mapa/cuadrante10.txt");
        set_cuad_derecha("N/A");
        break;
    case 10:
        set_cuad_arriba("N/A");
        set_cuad_abajo("N/A");
        set_cuad_izquierda("mapa/cuadrante11.txt");
        set_cuad_derecha("mapa/cuadrante9.txt");
        break;
    case 11:
        set_cuad_arriba("N/A");
        set_cuad_abajo("N/A");
        set_cuad_izquierda("mapa/cuadrante12.txt");
        set_cuad_derecha("mapa/cuadrante10.txt");
        break;
    case 12:
        set_cuad_arriba("N/A");
        set_cuad_abajo("mapa/cuadrante22.txt");
        set_cuad_izquierda("mapa/cuadrante13.txt");
        set_cuad_derecha("mapa/cuadrante11.txt");
        break;
    case 13:
        set_cuad_arriba("N/A");
        set_cuad_abajo("N/A");
        set_cuad_izquierda("mapa/cuadrante14.txt");
        set_cuad_derecha("mapa/cuadrante12.txt");
        break;
    case 14:
        set_cuad_arriba("N/A");
        set_cuad_abajo("N/A");
        set_cuad_izquierda("mapa/cuadrante15.txt");
        set_cuad_derecha("mapa/cuadrante13.txt");
        break;
    case 15:
        set_cuad_arriba("N/A");
        set_cuad_abajo("mapa/cuadrante16.txt");
        set_cuad_izquierda("N/A");
        set_cuad_derecha("mapa/cuadrante14.txt");
        break;
    case 16:
        set_cuad_arriba("mapa/cuadrante15.txt");
        set_cuad_abajo("mapa/cuadrante17.txt");
        set_cuad_izquierda("N/A");
        set_cuad_derecha("N/A");
        break;
    case 17:
        set_cuad_arriba("mapa/cuadrante16.txt");
        set_cuad_abajo("mapa/cuadrante18.txt");
        set_cuad_izquierda("N/A");
        set_cuad_derecha("mapa/cuadrante22.txt");
        break;
    case 18:
        set_cuad_arriba("mapa/cuadrante17.txt");
        set_cuad_abajo("mapa/cuadrante19.txt");
        set_cuad_izquierda("N/A");
        set_cuad_derecha("N/A");
        break;
    case 19:
        set_cuad_arriba("mapa/cuadrante18.txt");
        set_cuad_abajo("N/A");
        set_cuad_izquierda("N/A");
        set_cuad_derecha("mapa/cuadrante20.txt");
        break;
    case 20:
        set_cuad_arriba("N/A");
        set_cuad_abajo("N/A");
        set_cuad_izquierda("mapa/cuadrante19.txt");
        set_cuad_derecha("mapa/cuadrante21.txt");
        break;
    case 21:
        set_cuad_arriba("N/A");
        set_cuad_abajo("N/A");
        set_cuad_izquierda("mapa/cuadrante20.txt");
        set_cuad_derecha("mapa/cuadrante2.txt");
        break;
    case 22:
        set_cuad_arriba("mapa/cuadrante12.txt");
        set_cuad_abajo("mapa/cuadrante2.txt");
        set_cuad_izquierda("mapa/cuadrante17.txt");
        set_cuad_derecha("mapa/cuadrante7.txt");
        break;
    default:
        break;
    }
}

void Cuadrante::set_cuad_arriba(string ca){
    cuad_arriba = ca;
}

string Cuadrante::get_cuad_arriba(){
    return cuad_arriba;
}

void Cuadrante::set_cuad_abajo(string cab){
    cuad_abajo = cab;
}

string Cuadrante::get_cuad_abajo(){
    return cuad_abajo;
}

void Cuadrante::set_cuad_derecha(string cd){
    cuad_derecha = cd;
}

string Cuadrante::get_cuad_derecha(){
    return cuad_derecha;
}

void Cuadrante::set_cuad_izquierda(string ci){
    cuad_izquierda = ci;
}

string Cuadrante::get_cuad_izquierda(){
    return cuad_izquierda;
}

string Cuadrante::get_char(int x, int y){
    string character;
    character = cuadrante[y].at(x);
    return character;
}

void Cuadrante::set_txt(string t){
    name_cuad_txt = t;
}

string Cuadrante::get_txt(){
    return name_cuad_txt;
}

vector<string> Cuadrante::get_cuadrante(){
    return cuadrante;
}

void Cuadrante::set_cuadrante(string archivo){
    string str_input, line;
    int i;
    cuadrante.clear();
    name_cuad_txt = archivo;
    ifstream mapa_cuadrante(archivo);
    while(true){
        getline(mapa_cuadrante, str_input);
        line = str_input + "\n";
        cuadrante.push_back(line);
        i++;
        if(mapa_cuadrante.eof()){
            last_line = str_input;
            break;
        }
    }

    mapa_cuadrante.close();

    set_room();
    set_cuad_anexos();
}

void Cuadrante::show_cuadrante(int r){
    room = r;
    for(int i = 0; i < cuadrante.size(); i++){
        cout << cuadrante[i];
    }
}

void Cuadrante::add_personaje(Personaje person){
    string figura;
    int coord_x, coord_y;
    figura = person.get_figure();

    coord_x = person.get_coord_x();
    coord_y = person.get_coord_y();

    draw_in_coords(coord_x, coord_y, figura);
}

void Cuadrante::draw_in_coords(int x, int y, string figura){
    int max_length, max_height;
    max_length = cuadrante[0].size();
    max_height = cuadrante.size();

    if(x > 0 && x < max_length && y > 0 && y < max_height){
        cuadrante[y].replace(x, 1, figura);
    }

    ofstream cuad(name_cuad_txt);

    for(int i = 0; i < cuadrante.size()-1; i++){
        cuad << cuadrante[i];
    }
    cuad << last_line;
    cuad.close();
}

void Cuadrante::errase_in_coords(int x, int y){
    draw_in_coords(x, y, " ");
}

void Cuadrante::set_room(){
    string first, last, number;
    string::iterator it = cuadrante[0].end();
    first = cuadrante[0].at(0);
    last = *(it - 1);

    if(last != "x" and last != "."){
        number = first + last;
        room = stoi(number);
    } else {
        room = stoi(first);
    }  
}

int Cuadrante::get_room(){
    set_room();
    return room;
}

void Cuadrante::set_height(){
    height = cuadrante.size();
}

int Cuadrante::get_height(){
    return height;
}

void Cuadrante::set_length(){
    length = cuadrante[0].size();
}

int Cuadrante::get_length(){
    return length;
}