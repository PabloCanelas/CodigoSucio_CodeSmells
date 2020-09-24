#pragma once
#include<iostream>
#include "OperacionMatematica.cpp"
#include<vector>
class Resta: public OperacionMatematica
{
  public:
    float ejecutarOperacion(vector<float>numerosResta,bool primeraOperacion);
    string mostrarOperacion();
};

float Resta::ejecutarOperacion(vector<float>numerosResta, bool primeraOperacion)
{
  numeros=numerosResta;
  totalOperacion=0;
  for(int i=0;i<numeros.size();i++)
  {
    if(!primeraOperacion)
    {
      totalOperacion=(numeros[i]-numeros[i+1]);
      break;
    }
    else
    {
      totalOperacion=numeros[i]-totalOperacion;
    }
    
  }
  return totalOperacion;    
}
string Resta::mostrarOperacion()
{
  string concatenado="";
  for(int i=0;i<numeros.size();i++)
  {
    concatenado=concatenado+to_string(numeros[i])+"-";
  }
  concatenado=concatenado+"="+to_string(totalOperacion);
  cout<<concatenado<<endl;
  return concatenado;
}