#pragma once
#include<iostream>
#include "OperacionMatematica.cpp"
#include<vector>
using namespace std;
class Multiplicacion: public OperacionMatematica
{
  public:
    float ejecutarOperacion(vector<float>numerosSuma,bool primeraOperacion);
    string mostrarOperacion();
};
float Multiplicacion::ejecutarOperacion(vector<float>numerosDivsion,bool primeraOperacion)
{
  numeros=numerosDivsion;
  totalOperacion=1;
  for(int i=0;i<numeros.size();i++)
  {
    totalOperacion=numeros[i]*totalOperacion;
  }
  return totalOperacion;
}
string Multiplicacion::mostrarOperacion()
{
  string concatenado="";
  for(int i=0;i<numeros.size();i++)
  {
    concatenado=concatenado+to_string(numeros[i])+"*";
  }
  concatenado=concatenado+"="+to_string(totalOperacion);
  cout<<concatenado<<endl;
  return concatenado;
}