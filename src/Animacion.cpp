#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <string>
#include <Projecto.hpp>
using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{

    const vector<string> CLOUD_ART = {
        string("      ___(             )__  "),
        string("    ___(                     ) "),
        string("   (                         _)  "),
        string("  (_                     __))   "),
        string("    ((              _____)      "),
        string("      (_________)----'          ")
    };
    
    const vector<string> LIGHTNING_ART = {
        string("      _/  /                   "),
        string("     /  _/                    "),
        string("    _/  /                     "),
        string("   / __/                      "),
        string(" _/ /                         "),
        string(" /__/                         "),
        string(" //                           "),
        string("/'                            ")
    };

    auto pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Full()
    );

    int width = pantalla.dimx();
    int height = pantalla.dimy();

    Dibujo nube(CLOUD_ART, width / 2 - CLOUD_ART[0].size() / 2, 2, Color::GrayDark);
    Dibujo rayo(LIGHTNING_ART, width / 2 - 4, 8, Color::Yellow);

    int rayo_start_y = rayo.GetY();
    int rayo_max_y = height + rayo.GetHeight();

    while (true) {
        
        rayo.Mover(0, 1); 

        if (rayo.GetY() > rayo_max_y) {
            rayo.SetY(rayo_start_y);
        }
        
        pantalla.Clear();
        nube.Imprimir(pantalla);
        rayo.Imprimir(pantalla);

        cout << pantalla.ResetPosition();
        
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    
    return 0;
}