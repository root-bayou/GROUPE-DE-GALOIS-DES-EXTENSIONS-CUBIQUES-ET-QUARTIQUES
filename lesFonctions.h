#ifndef LESFONCTIONS_H_INCLUDED
#define LESFONCTIONS_H_INCLUDED
#include <string>
#include<iostream>
int verChoix(std::string choix );
bool verCof(std::string cof, int& cofe);
bool polyRed(int& p , int& q , int& r , int car , int iDegchoix);
int calDet(int p , int q , int r , int car) ;
bool carre(int dete , int car);
#endif