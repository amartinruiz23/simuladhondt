#include <iostream>	// Para utilizar las funciones cin-cout
#include <string> 	// Para guardar los nombres en objetos de tipo String

using namespace std;

class Partido{

  string nombre;
  long int votos;
  int escanios;

public:

	/**
	* @brief Constructor de instancias de partidos políticos
	* @param nombre, nombre del partido político a crear 
	* @param voto, cantidad de votos que ha recibido el partido 
	*/
  Partido(string nombre, long int votos){

    this->nombre=nombre;
    this->votos = voto;
    escanios = 0;

  }

	/**
	* @brief Constructor por defecto de instancias de partidos políticos
	*/
  Partido(){
    votos=0;
    escanios=0;
  }

	/**
	* @brief Función que cálcula la fracción de votos que tiene cada partido entre sus escaños +1 (para que el denominador no se anule)
	* @return fracción de votos entre los escaños del partido + 1  
	*/
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
  string nombre_partido;
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
