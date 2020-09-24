#include<iostream>
#include<vector>
#include<fstream>
#include"Suma.cpp"
using namespace std;
class Calculadora
{
  private:
    vector<string> historialOperaciones;
  public:
    void mostrarMenu(string opcionMenu);
    vector<float> introducirValores();
    void ejecutarCalculadora();
    float ejecutarOperacion(int numeroOperacion,vector<float>numeros);
    vector<float>introducirValoresContinuando(vector<float>numeros);
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
  cout<<"Cuantos valores desea añadir a su operacion: ";
  cin>>cantidadValores;
  for(int i=0;i<cantidadValores;i++)
  {
    cout<<"Ingrese el valor "<<i+1<<": ";
    cin>>valor;
    numeros.push_back(valor);
  }
  cout<<endl;
  return numeros;
}
float Calculadora::ejecutarOperacion(int numeroOperacion,vector<float>numeros)
{
  Suma suma;
  float resultado;
  switch(numeroOperacion)
    {
    case 1:
      resultado=suma.ejecutarOperacion(numeros);
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
  float ultimoResultado;
  mostrarMenu("MenuInicial");
  cout<<"Elige la operacion: ";
  cin>>numeroOperacion;
  do{
    if(contador==0)
    {
      ultimoResultado=ejecutarOperacion(numeroOperacion,introducirValores());
      contador++;
    }
    else
    {
      mostrarMenu("Menu");
      cout<<"Elige la operacion: ";
      cin>>numeroOperacion;
      numeros.push_back(ultimoResultado);
      ultimoResultado=ejecutarOperacion(numeroOperacion,introducirValoresContinuando(numeros));
      numeros.clear();
    }
    
  }while(numeroOperacion!=5);
}
