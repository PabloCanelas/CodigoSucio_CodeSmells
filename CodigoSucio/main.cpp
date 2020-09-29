//
//  main.cpp
//  CodigoSucio
//
//  Created by Pablo Canelas Schlink on 9/13/20.
//  Copyright © 2020 Pablo Canelas Schlink. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Calculadora.cpp"
int main()
{
    Calculadora calculadora;
    calculadora.ejecutarCalculadora();
    return 0;
}

// code smells
// 1. Código Duplicado
// 2. Metodo grande
// 3. Identificadores excesivamente cortos
// 4. Excesivo uso de literales
// https://refactoring.guru/refactoring/smells
// 5. Divergent Change  y este a su ves crea:
// 6. Long Parameter List
// 7. Dead Code (variable "contador" que no hace nada)