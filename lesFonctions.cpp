#include "lesFonctions.h"
#include <string>
#include <iostream>
#include <cmath>
int verChoix(std::string choix)
{

    bool nombrePremier = true;
    bool toutEstOk = true;
    int car = 0, i = 0, t = 0, y;

    while (i < choix.length())
    {
        t = (int)choix[i];
        if (t > 47 && t < 58)
        {
            t = t - 48;
            car = car + t;
        }
        else
        {
            toutEstOk = false;
            break;
        }

        if (i != choix.length() - 1)
        {
            car = car * 10;
        }
        i++;
    }
    y = 2;
    while (y < car && nombrePremier == true)
    {
        if (car % y == 0)
        {

            nombrePremier = false;
        }
        else
        {

            nombrePremier = true;
        }
        y++;
    }
    if (nombrePremier && toutEstOk && car != 2 && car != 3)
    {
        return car;
    }
    else
    {
        return 1;
    }
}
bool verCof(std::string cof, int &cofe)
{
    bool cofOk = true, valeurNegatif = false;
    int i = 0, t = 0;
    while (i < cof.length())
    {
        t = (int)cof[i];
        if (i == 0 && t == 45)
        {
            valeurNegatif = true;
            i++;
        }
        t = (int)cof[i];
        if (t > 47 && t < 58)
        {
            t = t - 48;
            cofe = cofe + t;
        }
        else
        {
            cofOk = false;
            break;
        }

        if (i != cof.length() - 1)
        {
            cofe = cofe * 10;
        }
        i++;
    }
    if (cofOk)
    {
        if (valeurNegatif)
        {
            cofe = cofe * (-1);
        }

        return true;
    }
    else
    {
        return false;
    }
}
bool polyRed(int &p, int &q, int &r, int car , int iDegchoix)
{
    int i = 1;
    std::string cofp, cofq, cofr;
    bool reductible = false;
    if (car == 0 && r != 0)
    {
        while (i <= abs(r) && reductible == false)
        {
            if (abs(r) % i == 0)
            {

                if ((pow(i, 3) + p * (pow(i, 2)) + q * (i) + r) == 0 || (pow(i * (-1), 3) + p * (pow(i * (-1), 2)) + q * (i * (-1)) + r) == 0)
                {
                    reductible = true;
                }
            }
            i++;
        }
    }
    else if (car != 0 && r != 0)
    {
        i = 0;
        while (i < car && reductible == false)

        {
            int b = (pow(i, 3) + p * (pow(i, 2)) + q * (i) + r);
            b = b % car;
            if (b == 0)
            {
                reductible = true;
            }
            i++;
        }
    }
    if (r == 0)
    {
        reductible = true;
    }

    if (reductible && iDegchoix == 3)
    {

        std::cout << "le polynome est reductible, veuillez saisir d'autres valeurs : " << std::endl;
        do
        {
            std::cout << "-> p = ";
            std::cin >> cofp;
            std::cout << "-> q = ";
            std::cin >> cofq;
            std::cout << "-> r = ";
            std::cin >> cofr;

            p = 0;
            q = 0;
            r = 0;

            if (verCof(cofp, p) && verCof(cofq, q) && verCof(cofr, r))
            {
                break;
            }
            else
            {
                continue;
            }

        } while (1);
    }

    if (reductible == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int calDet(int p, int q, int r, int car)
{
    long long int det;
    det = (18 * p * q * r) - (4 * (pow(p, 3)) * r) + (pow(p, 2) * pow(q, 2)) - (4 * (pow(q, 3))) - (27 * (pow(r, 2)));
    if (car != 0)
    {
        if (det < 0)
        {
            det = ((det % car) + car) % car;
        }
        else
        {
            det = det % car;
        }
    }
    return det;
}
bool carre(int dete, int car)
{   
    int i ; 
    bool eCarre = true ;
    if (dete < 0 && car == 0)
    {
        eCarre = false;
    }
    else if (dete > 0 && car == 0)
    {
        std::string disc = std::to_string(sqrt(dete));
        i = 0;
        while (i < disc.length())
        {
            if (char l = (int)disc[i] == 46)
            {   
               break;
               
            } 
            else{
                i++;
            }
        }
        int j = i + 1 ;
        while (j < disc.length() && eCarre == true)
        {
            
                   if (disc[j] == 48)
                   {    
                       eCarre = true ;
                       j++; 
                   }
                   else{
                       eCarre = false ;
                   }
        }
        
    }
    if (car != 0)
    {
        i = 0;
        int j;
        while (i < car )
        {   
            j = pow(i,2);
            if (j % car == dete)
            {   
                eCarre = true;
                break;
            }
            else
            {
                eCarre = false;
            }
            i++;
        }
    }

    return eCarre ; 
}
