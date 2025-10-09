#include <iostream>


int main() {

    int *pNum = NULL;
    
    sizeof(pNum);

    pNum = new int;

    *pNum = 25;

    std::cout << "direccion: " << pNum << '\n';
    std::cout << "valor: " << pNum << '\n';

    cout << "Tipos de datos: " << endl;
    cout << "Tamaño int : " << sizeof(int) << endl;
    cout << "Tamaño long :" << sizeof(long) << endl;
    cout << "Tamaño float :" << sizeof(float) << endl;
    cout << "Tamaño double :" << sizeof(double) << endl;
    cout << "Tamaño char :" << sizeof(char) << endl;
    cout << "Tamaño bool :" << sizeof(bool) << endl;
    cout << "Tamaño byte :" << sizeof(byte) << endl;

    return 0;
}