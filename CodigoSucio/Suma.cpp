#pragma once
#include<iostream>
#include "OperacionMatematica.cpp"
#include<vector>
using namespace std;
class Suma: public OperacionMatematica
{
  public:
    Suma();
    float ejecutarOperacion(vector<float>numerosSuma);
    string mostrarOperacion();
};
Suma::Suma()
{
  totalOperacion=0;
}
float Suma::ejecutarOperacion(vector<float>numerosSuma)
{
  numeros=numerosSuma;
  for(int i=0;i<numeros.size();i++)
  {
    totalOperacion=totalOperacion+numeros[i];
  }
  mostrarOperacion();
  return totalOperacion;
}
string Suma::mostrarOperacion()
{
  string concatenado="";
  for(int i=0;i<numeros.size();i++)
  {
    concatenado=concatenado+to_string(numeros[i])+"+";
  }
  cout<<concatenado<<"="<<totalOperacion;
  cout<<endl;
  return concatenado;
}