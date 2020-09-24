#pragma once
#include <iostream>
#include <vector>
using namespace std;
class OperacionMatematica 
{
  protected:
    float totalOperacion;
    vector<float>numeros;
  public:
    virtual float ejecutarOperacion(vector<float>numerosSuma,bool primeraOperacion)=0;
    virtual string mostrarOperacion()=0;
};
