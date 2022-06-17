#include "Personaje.h"

class Principal: public Personaje{
    private:
        string figure;
    public:
        Principal();
        Principal(int, int, string, int, int);
        void consume_item();
        void move(Cuadrante);
};

Principal::Principal(): Personaje(){
    figure = "o";
}

Principal::Principal(int v, int d, string n, int x, int y): Personaje("o", v, d, n, x, y){

}

void Principal::move(Cuadrante cuad){
    char ans;
    string figura;
    int x, y;
    cout << "Up [^]" << endl;
    cout << "Down [v]" << endl;
    cout << "Left [<]" << endl;
    cout << "Right [>]" << endl;

    cin >> ans;

    x = get_coord_x();
    y = get_coord_y();
    figura = get_figure();
    
    switch (ans)
    {
    case '^':
        if(cuad.get_char(x, y-1) == " "){
            cuad.errase_in_coords(x, y);
            cuad.draw_in_coords(x, y-1, figura);
            cout << x << " " << y-1 << endl;
            set_coord_y(y-1);
        } else if(cuad.get_char(x, y-1) == "x"){
            cout << "No puedes pasar por aqui" << endl;
        } else if(cuad.get_char(x, y-1) == "^"){
            cuad.errase_in_coords(x,y);
            cuad.open(cuad.get_cuad_arriba());
        }
        cuad.show_cuadrante();
        break;
    case 'v':
        if(cuad.get_char(x, y+1) == " "){
            cuad.errase_in_coords(x, y);
            cuad.draw_in_coords(x, y+1, figura);
            set_coord_y(y+1);
        }
        cuad.show_cuadrante();
        break;
    case '<':
        if(cuad.get_char(x-1, y) == " "){
            cuad.errase_in_coords(x, y);
            cuad.draw_in_coords(x-1, y, figura);
            set_coord_x(x-1);
        }
        cuad.show_cuadrante();
        break;
    case '>':
        if(cuad.get_char(x+1, y) == " "){
            cuad.errase_in_coords(x, y);
            cuad.draw_in_coords(x+1, y, figura);
            set_coord_x(x+1);
        }
        cuad.show_cuadrante();
        break;
    default:
        break;
    }
}