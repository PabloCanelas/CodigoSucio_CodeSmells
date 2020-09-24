#pragma once
#include<iostream>
#include "OperacionMatematica.cpp"
#include<vector>
using namespace std;
class Suma: public OperacionMatematica
{
  public:
    float ejecutarOperacion(vector<float>numerosSuma,bool primeraOperacion);
    string mostrarOperacion();
};
float Suma::ejecutarOperacion(vector<float>numerosSuma,bool primeraOperacion)
{
  numeros=numerosSuma;
  totalOperacion=0;
  for(int i=0;i<numeros.size();i++)
  {
    totalOperacion=totalOperacion+numeros[i];
  }
  return totalOperacion;
}
string Suma::mostrarOperacion()
{
  string concatenado="";
  for(int i=0;i<numeros.size();i++)
  {
    concatenado=concatenado+to_string(numeros[i])+"+";
  }
  concatenado=concatenado+"="+to_string(totalOperacion);
  cout<<concatenado<<endl;
  return concatenado;
}