#include<iostream>
#include<vector>
#include<fstream>
#include "Suma.cpp"
#include "Resta.cpp"
#include "Division.cpp"
#include "Multiplicacion.cpp"
using namespace std;
class Calculadora
{
  private:
    vector<string> historialOperaciones;
  public:
    void mostrarMenu(string opcionMenu);
    vector<float> introducirValores();
    void ejecutarCalculadora();
    float ejecutarOperacion(int numeroOperacion,vector<float>numeros,bool primeraOperacion);
    vector<float>introducirValoresContinuando(vector<float>numeros);
    void mostrarHistorial();
};

void Calculadora::mostrarMenu(string opcionMenu)
{
  string lineaArchivo;
  string nombreArchivo="MenuInicial";
  if(opcionMenu!="MenuInicial")
    nombreArchivo="Menu";
  fstream archivo(nombreArchivo+".txt");
  if(archivo.fail())
  {
    cout<<"El archivo no existe"<<endl;
  }
  else
  {
    while(!archivo.eof())
    {
      getline(archivo,lineaArchivo); 
      cout<<lineaArchivo<<endl;
    }
  }
}
vector<float> Calculadora::introducirValores()
{
  int cantidadValores, valor;
  vector<float>valoresIngresados;
  cout<<"Cuantos valores desea introducir: ";
  cin>>cantidadValores;
  for(int i=0;i<cantidadValores;i++)
  {
    cout<<"Ingrese el valor "<<i+1<<": ";
    cin>>valor;
    valoresIngresados.push_back(valor);
  }
  cout<<endl;
  return valoresIngresados;
}
vector<float> Calculadora::introducirValoresContinuando(vector<float>numeros)
{
  int cantidadValores, valor;
  cout<<"Ingrese el valor: ";
  cin>>valor;
  numeros.push_back(valor);
  cout<<endl;
  return numeros;
}
float Calculadora::ejecutarOperacion(int numeroOperacion,vector<float>numeros, bool primeraOperacion)
{
  Suma suma;
  Resta resta;
  Division division;
  Multiplicacion multiplicacion;
  float resultado;
  switch(numeroOperacion)
    {
    case 1:
      resultado=suma.ejecutarOperacion(numeros,primeraOperacion);
      historialOperaciones.push_back(suma.mostrarOperacion());
      break;
    case 2:
      resultado=resta.ejecutarOperacion(numeros,primeraOperacion);
      historialOperaciones.push_back(resta.mostrarOperacion());
      break;
    case 3:
      resultado=division.ejecutarOperacion(numeros,primeraOperacion);
      historialOperaciones.push_back(division.mostrarOperacion());
      break;
    case 4:
      resultado=multiplicacion.ejecutarOperacion(numeros,primeraOperacion);
      historialOperaciones.push_back(multiplicacion.mostrarOperacion());
      break;
    case 6:
      ejecutarCalculadora();
      break;
    case 7:
      system("pause");
      mostrarHistorial();

      break;
    default:
      cout<<"Seleccione una opcion valida"<<endl;
      break;
    }
    return resultado;
}
void Calculadora::ejecutarCalculadora()
{
  int numeroOperacion,contador=0;
  vector<float>numeros;
  float ultimoResultado=0;
  mostrarMenu("MenuInicial");
  cout<<"Elige la operacion: ";
  cin>>numeroOperacion;
  while(numeroOperacion!=5)
  {
    if(contador==0)
    {
      ultimoResultado=ejecutarOperacion(numeroOperacion,introducirValores(),true);
      contador++;
      historialOperaciones.clear();
    }
    else
    {
      mostrarMenu("Menu");
      cout<<"Elige la operacion: ";
      cin>>numeroOperacion;
      if(numeroOperacion==6)
        ejecutarCalculadora();
      else
      {
        numeros.push_back(ultimoResultado);
        ultimoResultado=ejecutarOperacion(numeroOperacion,introducirValoresContinuando(numeros),false);
        numeros.clear();  
      }
      
    }
  }
}
void Calculadora::mostrarHistorial()
{
  if(historialOperaciones.size()==0)
    cout<<"No existen operaciones realizadas aun"<<endl;
    else
    { 
      cout<<"------Historial de operaciones--------"<<endl;
      for(int i=0;i<historialOperaciones.size();i++)
      {
        cout<<i+1<<"."<<historialOperaciones[i]<<endl;
      }
    }
    
}
