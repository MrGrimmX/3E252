#pragma once
#include <string>
#include <list>
using namespace std;

#include <ftxui/screen/screen.hpp>
using namespace ftxui;

class Dibujo
{
private:
    list<string> dibujo;
    int x = 0;
    int y = 0;

    public:
        Dibujo(list<string> dibujo) {
            this->dibujo = dibujo;
        }
        ~Dibujo() {}
        void Imprimir(Screen& pantalla){
            int fila = 0;
            for (auto &&linea : dibujo)
            {
                int columna = 0;
                for (auto &&letra : linea)
                {
                    Pixel &pixel = pantalla.PixelAt(
                        x + columna, 
                        y + fila
                    );
                    pixel.character = letra;
                    pixel.background_color = Color::Blue;
                    pixel.foreground_color = Color::Red;
                    columna ++;
                }
                fila++;
            };
        }

        void MoverDerecha(){
            x++;
        }

        void MoverIzquierda(){
            x--;
        }

        void MoverArriba(){
            y--;
        }

        void MoverAbajo(){
            y++;
        }

    };