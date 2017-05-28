#include <iostream>
#include <stdio.h>
#include "ListaDwukierunkowaMOJA.h"
 
using namespace std;
 
int main()
{
        wczytaj_dane();
        return 0;
}
void wczytaj_dane()
{
char dane;
 
Proces *ideP1=NULL;
Proces *endP1=NULL;
Proces *beginP1=NULL;
 
Proces *ideP0=NULL;
Proces *endP0=NULL;
Proces *beginP0=NULL;
 
Proces *idePm1=NULL;
Proces *endPm1=NULL;
Proces *beginPm1=NULL;
 
int id,priorytet;
 
        while(cin>>dane)
        {
                switch(dane)
                {
                case 'c':
                        cin>>id>>priorytet;
                        if(priorytet==1)
                                dodaj_elNaPocz(endP1,beginP1,ideP1,id,1);
                        else if(priorytet == 0)
                                dodaj_elNaPocz(endP0,beginP0,ideP0,id,0);
                        else if(priorytet == -1)
                                dodaj_elNaPocz(endPm1,beginPm1,idePm1,id,-1);
                        break;
                case 'n':
                        if(endP1 == NULL && endP0 == NULL && endPm1 == NULL)
                                cout<<"idle \n";
                        else {IdzPojedOdKon(ideP1,endP1,ideP0,endP0,idePm1,endPm1);
                        }
                        break;
                case 't':
                        cin>>id;
                        usunPodanyEl(endP1,beginP1,endP0,beginP0,endPm1,beginPm1,id,ideP1,ideP0,idePm1);
                        break;
                case 'p':
                        cin>>id>>priorytet;
                        usunPodanyEl(endP1,beginP1,endP0,beginP0,endPm1,beginPm1,id,ideP1,ideP0,idePm1);
                        if(priorytet==1)
                                dodaj_elNaKon(endP1,beginP1,ideP1,id,1);
                        else if(priorytet == 0)
                                dodaj_elNaKon(endP0,beginP0,ideP0,id,0);
                        else if(priorytet == -1)
                                dodaj_elNaKon(endPm1,beginPm1,idePm1,id,-1);
                        break;
                case 'l':                            //wypisuje elementy w zaleznosci od wskaznika chodzacego
                        cout<<"1: ";
                        wypisz_el(ideP1,endP1,1);
                        cout<<"\n0: ";
                        wypisz_el(ideP0,endP0,0);
                        cout<<"\n-1: ";
                        wypisz_el(idePm1,endPm1,-1);
                        cout<<"\n";
                        break;
                default:
                        break;
                }
 
        }
}
