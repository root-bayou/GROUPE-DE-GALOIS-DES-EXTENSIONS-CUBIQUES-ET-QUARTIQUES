#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "lesFonctions.h"
using namespace std;
int main()
{
    string choix, cofp, cofq, cofr, cofs, degchoix, reponse;
    int iDegChoix;
    int disc1(0), disc2(0);
    bool reductible = false;
    int p(0), q(0), r(0), s(0), g, f;
    int pR(0), qR(0), rR(0), racine(0);
    int i = 0, t, y = 2;
    int car;
    bool alter = false;
    char rep;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                          *Ce programme détermine les groupes de Galois associés aux polynômes de degré 3 ou 4*                                                     |" << endl;
    cout << "|                                        - Etape 1 il faut choisir le degré du polynome tapez (3) pour le degré 3 tapez (4) pour le degré 4                                          |" << endl;
    cout << "|                                        - Etape 2 il faut choisir la caractéristique du corps 0 pour Q un nombre premier > 3 pour un corps fini                                     |" << endl;
    cout << "|                                        - Etape 3 il faut choisir les coefficients; Notons que ces coefficients doivent étre dans Z                                                 |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                                                         Choisir le degré du polynôme                                                                               |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout<<"-> ";
    cin >> degchoix;
    while (1)
    {
        int a = (int)degchoix[0];
        if (degchoix.length() >= 2)
        {
            cout << "Valeur inccorecte tapez 3 ou 4 : "<<endl;
            cout<<"-> ";
            cin >> degchoix;
        }
        else if (a == 51 || a == 52)
        {
            iDegChoix = a - 48;
            break;
        }
        else
        {
            cout << "Valeur inccorecte tapez 3 ou 4 : "<<endl;
            cout <<"-> ";
            cin >> degchoix;
        }
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                                                     Choisir la caractéristique du corps                                                                            |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-> ";
    cin >> choix;
    int leChoix = verChoix(choix);
    do
    {

        if (leChoix == 1)
        {
            cout << "veuillez saisir un autre nombre, soit 0 soit un nombre premier > 3 : " << endl;
            cout <<"-> ";
            cin >> choix;
            leChoix = verChoix(choix);
        }
        else
        {
            car = leChoix;
            break;
        }

    } while (1);

    if (iDegChoix == 3)
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "                                                 Polynome de degré 3 p(X) = X³ + pX² + qX + r sur un corps de caractéristique  " << car << "                                         " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Donnez p, q, r dans l'ordre :" << endl;
        cout << "-> p = ";
        cin >> cofp;
        cout << "-> q = ";
        cin >> cofq;
        cout << "-> r = ";
        cin >> cofr;
        do
        {
            if (verCof(cofp, p) && verCof(cofq, q) && verCof(cofr, r))
            {
                break;
            }
            else
            {
                cout << "Valeurs inccorects veuillez introduire d'autres valeurs :" << endl;
                cout << "-> p = ";
                cin >> cofp;
                cout << "-> q = ";
                cin >> cofq;
                cout << "-> r = ";
                cin >> cofr;
                p = 0;
                q = 0;
                r = 0;
                continue;
            }

        } while (1);

        if (car != 0)
        {
            p = ((p % car) + car) % car;
            q = ((q % car) + car) % car;
            r = ((r % car) + car) % car;
        }
        cout << endl;
        cout << "----> p(X) = X³ + "
             << " (" << p << ")"
             << "X² + "
             << " (" << q << ")"
             << "X + " << r << " **" << endl;
        cout << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                                                               Test d'irréductibilité                                                                              |" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        do
        {
            if (polyRed(p, q, r, car, iDegChoix))
            {
                if (car != 0)
                {
                    p = ((p % car) + car) % car;
                    q = ((q % car) + car) % car;
                    r = ((r % car) + car) % car;
                }
                cout << "----> p(X) = X³ + "
                     << " (" << p << ")"
                     << "X² + "
                     << " (" << q << ")"
                     << "X + " << r << " est irréductible                                        " << endl;
                break;
            }
            else
            {
                continue;
            }

        } while (1);
        cout << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                                                               Calcule du discriminant (∆)                                                                         |" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        long int det(0);
        if (reductible == false)
        {

            det = calDet(p, q, r, car);
            cout << endl;
            cout << "----> ∆ de "
                 << " X³ + "
                 << " (" << p << ")"
                 << "X² + "
                 << " (" << q << ")"
                 << "X + " << r << " = " << det << endl;
            if (carre(det, car) && car == 0)
            {
                cout << "----> ∆ est un carré (" << sqrt(det) << ")² = " << det << endl;
                cout << endl;
            }
            else if (carre(det, car) == false && car == 0)
            {
                
                cout << "----> ∆ n'est pas un carré" << endl;
                cout << endl;
            }
            else if (carre(det, car) && car != 0)
            {
                g = 0;
                f;
                while (g < car)
                {
                    f = pow(g, 2);
                    if (f % car == det)
                    {
                        break;
                    }
                    g++;
                }

                cout << "----> ∆ est un carré " << g << "² ≡ " << det << "[" << car<<"]" << endl;
               
                cout << endl;
            }
            else if (carre(det, car) == false && car != 0)
            {
                
                cout << "----> ∆ n'est pas un carré" << endl;
                cout << endl;
            }
            cout << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "|                                                                          Detérmination du groupe de Galois associé                                                                |" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            alter = carre(det, car);
            if (alter)
            {
                cout << "******************************************************************************" << endl;
                cout << "*Le groupe de Galois associé est isomorphe au groupe altérné d'ordre 3 ( A3 )*" << endl;
                cout << "******************************************************************************" << endl;
            }
            else
            {
                cout << "*********************************************************************************" << endl;
                cout << "*Le groupe de Galois associé est isomorphe au groupe symétrique d'ordre 3 ( S3 )*" << endl;
                cout << "*********************************************************************************" << endl;
            }
        }
    }
    else
    {
        bool redDegQ;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "                                             Polynome de degré 4 f(X) = X⁴ + pX³ + qX² + rX + s sur un corps de caractéristique  " << car << "          " << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Donnez p, q, r, s dans l'ordre :" << endl;
        cout << "-> p = ";
        cin >> cofp;
        cout << "-> q = ";
        cin >> cofq;
        cout << "-> r = ";
        cin >> cofr;
        cout << "-> s = ";
        cin >> cofs;
        do
        {
            if (verCof(cofp, p) && verCof(cofq, q) && verCof(cofr, r) && verCof(cofs, s))
            {
                break;
            }
            else
            {
                cout << "Valeurs inccorects veuillez introduire d'autres valeurs :" << endl;
                cout << "-> p = ";
                cin >> cofp;
                cout << "-> q = ";
                cin >> cofq;
                cout << "-> r = ";
                cin >> cofr;
                cout << "-> s = ";
                cin >> cofs;
                p = 0;
                q = 0;
                r = 0;
                s = 0;
                continue;
            }

        } while (1);

        if (car != 0)
        {
            p = ((p % car) + car) % car;
            q = ((q % car) + car) % car;
            r = ((r % car) + car) % car;
            s = ((s % car) + car) % car;
        }
        cout << endl;
        cout << "----> f(X) = X⁴ + "
             << " (" << p << ")"
             << "X³ + "
             << " (" << q << ")"
             << "X² + "
             << "(" << r << ")X + " << s << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                                                             Résolvente cubique associée φ(X)                                                                       |" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        pR = -q;
        qR = (p * r) - (4 * s);
        rR = ((pow(p, 2) * s) + (pow(r, 2)) - (4 * q * s)) * (-1);

        if (car != 0)
        {
            pR = ((pR % car) + car) % car;
            qR = ((qR % car) + car) % car;
            rR = ((rR % car) + car) % car;
        }

        cout << "----> φ(X) = X³ + "
             << " (" << pR << ")"
             << "X² + "
             << " (" << qR << ")"
             << "X + (" << rR << ")" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                                                               Test d'irréductibilité de φ(X)                                                                       |" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;

        if (polyRed(pR, qR, rR, car, iDegChoix))
        {

            cout << "----> φ(X)= X³ + "
                 << " (" << pR << ")"
                 << "X² + "
                 << " (" << qR << ")"
                 << "X + (" << rR << ") est irréductible                                        " << endl;
            redDegQ = false;
        }
        else
        {

            cout << "----> φ(X) = X³ + "
                 << " (" << pR << ")"
                 << "X² + "
                 << " (" << qR << ")"
                 << "X + (" << rR << ") est réductible                                        " << endl;
            redDegQ = true;
        }

        cout << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                                                              Calcule du discriminant (∆) de φ(X)                                                                   |" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        long int det(0);
        if (reductible == false)
        {

            det = calDet(pR, qR, rR, car);
            cout << endl;
            cout << "----> ∆ de "
                 << " X³ + "
                 << " (" << pR << ")"
                 << "X² + "
                 << " (" << qR << ")"
                 << "X + (" << rR << ") = " << det
                 << endl;
            cout << endl;
            if (carre(det, car) && car == 0)
            {

                cout << "----> ∆ est un carré (" << sqrt(det) << ")² = " << det << endl;
                cout << endl;
            }
            else if (carre(det, car) == false && car == 0)
            {

                cout << "----> ∆ n'est pas un carré" << endl;
                cout << endl;
            }
            else if (carre(det, car) && car != 0)
            {
                g = 0;
                f;
                while (g < car)
                {
                    f = pow(g, 2);
                    if (f % car == det)
                    {
                        break;
                    }
                    g++;
                }

                cout << "----> ∆ est un carré " << g << "² ≡ " << det << "[" << car<<"]" << endl;
                cout << endl;
            }
            else if (carre(det, car) == false && car != 0)
            {

                cout << "----> ∆ n'est pas un carré" << endl;
                cout << endl;
            }
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                                                           Detérmination du groupe de Galois associé                                                                |" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        if (carre(det, car))
        {
            if (redDegQ)
            {
                cout << "******************************************************************************" << endl;
                cout << "*Le groupe de Galois associé est isomorphe au groupe de Klein d'ordre 4 ( V )*" << endl;
                cout << "******************************************************************************" << endl;
            }
            else
            {
                cout << "******************************************************************************" << endl;
                cout << "*Le groupe de Galois associé est isomorphe au groupe altérné d'ordre 4 ( A4 )*" << endl;
                cout << "******************************************************************************" << endl;
            }
        }
        else
        {
            if (redDegQ == false)
            {
                cout << "*********************************************************************************" << endl;
                cout << "*Le groupe de Galois associé est isomorphe au groupe symétrique d'ordre 4 ( S4 )*" << endl;
                cout << "*********************************************************************************" << endl;
            }
            else
            {
                if (det < 0)
                {

                    cout << "*********************************************************************************" << endl;
                    cout << "*Le groupe de Galois associé est isomorphe au groupe Diédral d'ordre 8 ( D4 )   *" << endl;
                    cout << "*********************************************************************************" << endl;
                }
                else
                {
                    cout << endl;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "|                                                                          Recherche a l'aide de la mhétode de Kappe, Warren                                                         |" << endl;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << endl;
                    int j(0);
                    bool racineTrouve = false;

                    if (car == 0)
                    {
                        while (racineTrouve == false)
                        {
                            if ((pow(j, 3) + pR * (pow(j, 2)) + qR * (j) + rR) == 0)
                            {
                                racine = j;
                                racineTrouve = true;
                            }
                            else if ((pow(j * (-1), 3) + pR * (pow(j * (-1), 2)) + qR * (j * (-1)) + rR) == 0)
                            {
                                racine = j * (-1);
                                racineTrouve = true;
                            }

                            j++;
                        }
                    }
                    else if (car != 0)
                    {
                        while (racineTrouve == false && j < car)
                        {
                            int b = (pow(j, 3) + (pR * (pow(j, 2))) + (qR * (j)) + rR);
                            b = b % car;
                            if (b == 0)
                            {
                                racine = j;
                                racineTrouve = true;
                            }
                            j++;
                        }
                    }
                    cout << endl;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "|                                                       Recherche de la racine (β) de la résolvante cubique sur le corps de base                                                     |" << endl;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << endl;

                    cout << "----> (β) = " << racine<< endl;

                    cout << endl;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "|                                                                                Polynômes associés                                                                                  |" << endl;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << endl;
                    disc1 = (pow(p, 2) - 4 * (q - racine)) * det;
                    disc2 = (pow(racine, 2) - (4 * s)) * det;
                    if (car != 0)
                    {
                        disc1 = ((disc1 % car) + car) % car;
                        disc2 = ((disc2 % car) + car) % car;
                        
                    }
                    
                    float cardisc1 = sqrt(disc1);
                    float cardisc2 = sqrt(disc2);
                    if (car == 0 && disc1 > 0 && disc2 > 0)
                    {

                        cout << "----> X² + (" << p << ")X + (" << q << ")-(" << racine << "), ∆1 x ∆  = " << disc1 << " = (" << cardisc1 << ")²" << endl;
                        cout << "----> X² - (" << racine << ")X + (" << s << "), ∆2 x ∆ = " << disc2 << " = (" << cardisc2 << ")²" << endl;
                        cout << endl;
                    }
                    else if (car == 0 && (disc1 < 0 || disc2 < 0))
                    {

                        cout << "----> X² + (" << p << ")X + (" << q << ")-(" << racine << "), ∆1 x ∆ = " << disc1 << endl;
                        cout << "----> X² - (" << racine << ")X + (" << s << "), ∆2 x ∆ = " << disc2 << endl;
                        cout << endl;
                    }
                    else if (car != 0)
                    {

                        cout << "----> X² + (" << p % car << ")X + (" << q % car << ")-(" << racine % car << "), ∆1 x ∆ = " << disc1 % car << endl;
                        cout << "----> X² - (" << racine % car << ")X + (" << s % car << "), ∆2 x ∆ = " << disc2 % car << endl;
                        cout << endl;
                    }
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    bool v1 = carre(disc1, car);
                    bool v2 = carre(disc2, car);
                    if (car == 0)
                    {
                        if (v1)
                        {

                            cout << "----> ∆1 est un carré (" << sqrt(disc1) << ")² = " << disc1 << endl;
                            cout << endl;
                        }
                        else
                        {

                            cout << "----> ∆1 n'est pas un carré" << endl;
                            cout << endl;
                        }
                        if (v2)
                        {

                            cout << "----> ∆2 est un carré (" << sqrt(disc2) << ")² = " << disc2 << endl;
                            cout << endl;
                        }
                        else
                        {

                            cout << "----> ∆2 n'est pas un carré" << endl;
                            cout << endl;
                        }
                    }
                    else
                    {
                        if (v1)
                        {
                            g = 1;
                            f;
                            while (g < car)
                            {
                                f = pow(g, 2);
                                if (f % car == disc1)
                                {
                                    break;
                                }
                                g++;
                            }

                            cout << "----> ∆1 est un carré " << g << "² ≡ " << disc1 << " [" << car<<"]" << endl;
                            cout << endl;
                        }
                        else
                        {

                            cout << "----> ∆1 n'est pas un carré " << endl;
                            cout << endl;
                        }
                        if (v2)
                        {
                            g = 1;
                            f;
                            while (g < car)
                            {
                                f = pow(g, 2);
                                if (f % car == disc2)
                                {
                                    break;
                                }
                                g++;
                            }

                            cout << "----> ∆2 est un carré " << g << "² ≡ " << disc2 << "[" << car<<"]" << endl;

                            cout << endl;
                        }
                        else
                        {

                            cout << "----> ∆2 n'est pas un carré " << endl;
                            cout << endl;
                        }
                    }

                    if (v1 == true && v2 == true)
                    {
                        cout << "*********************************************************************************" << endl;
                        cout << "*Le groupe de Galois associé est isomorphe au groupe additif d'ordre 4 ( Z/4Z ) *" << endl;
                        cout << "*********************************************************************************" << endl;
                    }
                    else if (v1 == false || v2 == false)
                    {

                        cout << "*********************************************************************************" << endl;
                        cout << "*Le groupe de Galois associé est isomorphe au groupe Diédral d'ordre 8 ( D4 )   *" << endl;
                        cout << "*********************************************************************************" << endl;
                    }
                }
            }
        }
    }

    return 0;
}
