#include "Personaje.h"

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

void Principal::move(Cuadrante cuad){
    char ans;
    string figura;
    string arch1, arch2;
    int x, y, size_x, size_y;

    x = get_coord_x();
    y = get_coord_y();
    figura = get_figure();

    cout << "coord_x " << x << endl;
    cout << "coord_y " << y << endl;
    cout << "cuarto " << room << endl;

    cuad.set_cuadrante(room_txt);

    cout << "Up [^]" << endl;
    cout << "Down [v]" << endl;
    cout << "Left [<]" << endl;
    cout << "Right [>]" << endl;

    cin >> ans;
    switch (ans)
    {
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

            set_coord_x(size_x % 2);
            set_coord_y(size_y - 2);

            room = cuad.get_room();
            cuad.draw_in_coords(get_coord_x(), get_coord_y(), figura);
        } else {
            cout << "No se puede pasar por aqui" << endl;
        }
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

            set_coord_x(size_x % 2);
            set_coord_y(1);

            room = cuad.get_room();
            cuad.draw_in_coords(get_coord_x(), get_coord_y(), figura);
        }
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

            set_coord_x(size_x - 2);
            set_coord_y(size_y%2);

            room = cuad.get_room();
            cuad.draw_in_coords(get_coord_x(), get_coord_y(), figura);
        }
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

            set_coord_x(size_x - 2);
            set_coord_y(size_y%2);

            room = cuad.get_room();
            cuad.draw_in_coords(get_coord_x(), get_coord_y(), figura);
        } else {
            cout << "No puedes pasar por aqui" << endl;
        }
        cuad.show_cuadrante(room);
        break;
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