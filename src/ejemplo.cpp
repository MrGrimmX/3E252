#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <thread>
#include <chrono>
#include <string>
using namespace std;
using namespace ftxui;

#include <Dibujo.hpp>

int main(int argc, char const *argv[])
{
    Screen pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fixed(10)
    );

    Dibujo vaca({
        string("         (__)"),
        string(" `-------(oo)"),
        string("   ||    (__)"),
        string("   ||w--||   ")
    });
    Dibujo nave({
        string("     ___     "),
        string(" ___/   \\___"),
        string("/   '---'   \\"),
        string("'--_______--'")
    });

    while (true){
        nave.MoverDerecha();
        vaca.Imprimir(pantalla);
        nave.Imprimir(pantalla);
        pantalla.Print();
    
        this_thread::sleep_for(chrono::milliseconds(50));

        pantalla.Clear();
        cout << pantalla.ResetPosition();
    }
    return 0;
}