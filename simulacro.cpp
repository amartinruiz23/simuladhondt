#include <iostream>

using namespace std;

class Partido{

  char nombre[50];
  long int votos;
  int escanios;

public:

  Partido(char nomb[], long int voto){

    for(int i = 0; i < 50; i++)
      nombre[i] = nomb[i];
    votos = voto;
    escanios = 0;

  }

  Partido(){
    votos=0;
    escanios=0;
  }

  long double Fraccion(){
    return votos/(escanios+1);
  }

  void Imprime(){
    cout << nombre << " - Votos: " << votos << " Escaños: " << escanios << "\n";
  }

  void SumaEscanio(){
    escanios++;
  }

};

int main(){

  int numero_partidos;
  int escanios_a_repartir;
  char nombre_partido[50];
  long int num_votos;

  cout << "Introduzca el número de escaños a repartir: ";
  cin >> escanios_a_repartir;

  cout << "\n¿Cuántos partidos participan en la circunscripción? ";
  cin >> numero_partidos;

  Partido partidos[numero_partidos];

  for (int i = 0; i < numero_partidos; i++){
    cout << "\nIntroduzca el nombre del partido número " << i+1 << ":";
    cin >> nombre_partido;
    cout << "\nIntroduzca el número de votos recibido por el partido: ";
    cin >> num_votos;

    partidos[i] = Partido(nombre_partido, num_votos);
  }

  for (int i = 0; i < escanios_a_repartir; i++){

    int partidolider = 0;
    for (int j = 0; j < numero_partidos; j++){
      if (partidos[j].Fraccion() > partidos[partidolider].Fraccion())
        partidolider = j;
    }
    partidos[partidolider].SumaEscanio();
  }

  for (int i = 0; i < numero_partidos; i++){
    partidos[i].Imprime();
  }

}
