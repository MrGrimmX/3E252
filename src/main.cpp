#include <SerieNavidad.hpp>
#include <Foco.hpp>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    SerieNavidad miSeriesNavidad;
    miSeriesNavidad.Encender();
    miSeriesNavidad.ImprimirSerie();
    miSeriesNavidad.Apagar();
    miSeriesNavidad.ImprimirSerie();

    Foco foco;
    foco.Apagar(); 
    foco.Encender(); 

    cout<<"Foco: "
    <<foco.MostrarEstado()
    <<endl;

    return 0;
}