//
//  main.cpp
//  CodigoSucio
//
//  Created by Pablo Canelas Schlink on 9/13/20.
//  Copyright © 2020 Pablo Canelas Schlink. All rights reserved.
//

#include <iostream>
using namespace std;
#include "OperacionMatematica.cpp"
#include "Calculadora.cpp"
#include "Suma.cpp"
float calculadora(float x, float y, int operacion)
{
    cout << "__________________" << endl;
    cout << "Ultima operacion" << endl;

    if (operacion == 1)
    {
        cout << x << "+" << y << "=" << x + y << endl;
        x = x + y;
    }
    if (operacion == 2)
    {
        cout << x << "-" << y << "=" << x - y << endl;
        x = x - y;
    }
    if (operacion == 3)
    {
        cout << x << "/" << y << "=" << x / y << endl;
        x = x / y;
    }
    if (operacion == 4)
    {
        cout << x << "x" << y << "=" << x * y << endl;
        x = x * y;
    }

    return x;
}
int main()
{
    Calculadora calculadora;
    calculadora.ejecutarCalculadora();
    //calculadora.ejecutarCalculadora();
    // int control = 0;
    // float res = 0;
    // int menu = -1;
    // float x, y;


    // if (control == 0)
    // {
    //     cout << "Calculadora " << endl;
    //     cout << "__________________" << endl;

    //     cout << "Operaciones: " << endl;
    //     cout << "1.- Sumar" << endl;
    //     cout << "2.- Restar" << endl;
    //     cout << "3.- Dividir" << endl;
    //     cout << "4.- Multiplicar" << endl;
    //     cout << "__________________" << endl;
    //     cout << "Valor 1?" << endl;
    //     cin >> x;
    //     cout << "Valor 2?" << endl;
    //     cin >> y;
    //     cout << "operacion?" << endl;
    //     cin >> menu;
    //     res = Calculadora(x, y, menu);
    //     control++;
    // }

    // if (control != 0)
    // {
    //     while (menu != 5 && menu != 6)
    //     {
    //         cout << "__________________" << endl;
    //         cout << "Operaciones: " << endl;
    //         cout << "1.- Sumar al valor actual" << endl;
    //         cout << "2.- Restar al valor actual" << endl;
    //         cout << "3.- Dividir al valor actual" << endl;
    //         cout << "4.- Multiplicar al valor actual" << endl;
    //         cout << "5.- Salir de la calculadora " << endl;
    //         cout << "6.- Reiniciar la calculadora " << endl;

    //         cout << "__________________" << endl;
    //         cout << "Valor actual: " << res << endl;
    //         cout << "__________________" << endl;
    //         cout << "operacion?" << endl;

    //         cin >> menu;
    //         if (menu != 5 && menu != 6)
    //         {
    //             cout << "Valor 2?" << endl;
    //             cin >> y;
    //             res = Calculadora(res, y, menu);
    //         }
    //     }
    // }

    // if (menu == 6)
    //     main();

     return 0;
}
