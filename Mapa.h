#ifndef Mapa_h
#define Mapa_h

class Mapa{
    private:
        string mapa;
    public:
        void show_mapa();
        void set_mapa(string);
};

void Mapa::set_mapa(string archivo){
    string str_input;
    ifstream map("mapa/mapa.txt");

    while(true){
        getline(map, str_input);
        mapa = mapa + str_input + "\n";
        if(map.eof()){break;};
    }
}

void Mapa::show_mapa(){
    cout << mapa << endl;
}

#endif
