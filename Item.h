class Item{
    private:
        int valor;
        int tamano;
        string nombre;
    public:
        int get_valor();
        void set_valor(int);
        int get_tamano();
        void set_tamano(int);
        string get_nombre();
        void set_nombre(string);
        void show_item();
};

int Item::get_valor(){
    return valor;
}

void Item::set_valor(int v){
    valor = v;
}

int Item::get_tamano(){
    return tamano;
}

void Item::set_tamano(int t){
    tamano = t;
}

string Item::get_nombre(){
    return nombre;
}

void Item::set_nombre(string n){
    nombre = n;
}

void Item::show_item(){
    cout << "Item: " << nombre << endl; 
    cout << "Valor: " << valor << endl;
    cout << "Tamano: " << tamano << endl;
}