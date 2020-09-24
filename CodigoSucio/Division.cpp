#pragma once
#include<iostream>
#include "OperacionMatematica.cpp"
#include<vector>
using namespace std;
class Division: public OperacionMatematica
{
  public:
    float ejecutarOperacion(vector<float>numerosSuma,bool primeraOperacion);
    string mostrarOperacion();
};
float Division::ejecutarOperacion(vector<float>numerosDivsion,bool primeraOperacion)
{
  numeros=numerosDivsion;
  totalOperacion=1;
  for(int i=0;i<numeros.size();i++)
  {
    if(primeraOperacion)
      totalOperacion=numeros[i]/totalOperacion;
    else
    {
      totalOperacion=numeros[i]/numeros[i+1];
      break;
    }
  }
  return totalOperacion;
}
string Division::mostrarOperacion()
{
  string concatenado="";
  for(int i=0;i<numeros.size();i++)
  {
    concatenado=concatenado+to_string(numeros[i])+"/";
  }
  concatenado=concatenado+"="+to_string(totalOperacion);
  cout<<concatenado<<endl;
  return concatenado;
}