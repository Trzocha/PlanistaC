#include <iostream>
#include "funkcje.h"
using namespace std;
 
bool flagaPm1=0;
bool flagaP0=0;
bool flagaP1=0;
int ilElOpriorP1=0;
int ilElOpriorP0=0;
int ilElOpriorPm1=0;
 
struct Proces
{
int id;                   //liczba
int priorytet;            //waga
Proces *next;
Proces *poprzed;
Proces(){next = NULL; poprzed = NULL;}
};
 
void dodaj_elNaPocz(Proces *&KListy,Proces *&PListy,Proces *&korzen,int id,int prior)      //przy dodawaniu nowych procesow musze wiedziec ile jest
{                                                        //procesow o danym priorytecie
        zmianaFlagi(prior);
 
        if(prior == 1 && ilElOpriorP1>2 && korzen->next != NULL) dodajZaElWsk(korzen,id,1);
        else if(prior == 0 && ilElOpriorP0>2 && korzen->next != NULL) dodajZaElWsk(korzen,id,0);
        else if(prior == -1 && ilElOpriorPm1>2 && korzen->next != NULL) dodajZaElWsk(korzen,id,-1);
 
        else if(prior == 1){dodajElDoListy(KListy,PListy,korzen,id,1,ilElOpriorP1);}
        else if(prior == 0){dodajElDoListy(KListy,PListy,korzen,id,0,ilElOpriorP0);}
        else if(prior == -1){dodajElDoListy(KListy,PListy,korzen,id,-1,ilElOpriorPm1);}
 
}
 
void dodaj_elNaKon(Proces *&KListy,Proces *&PListy,Proces *&korzen,int id,int prior)
{
 
        if(prior == 1)dodaj_elNaPocz(KListy,PListy,korzen,id,1);
 
        if(prior == 0)dodaj_elNaPocz(KListy,PListy,korzen,id,0);
 
        if(prior == -1) dodaj_elNaPocz(KListy,PListy,korzen,id,-1);
}
void dodajZaElWsk(Proces *&korzen, int id,int prior)
{
Proces *nowy = new Proces;
Proces *pom;
 
        nowy->id = id;
        nowy->priorytet = prior;
 
        pom = korzen->next;
        pom->poprzed = nowy;
 
        korzen->next = nowy;
 
        nowy->next = pom;
        nowy->poprzed = korzen;
}
void NaKoniec(Proces *&KListy,int id,int prior)
{
Proces *nowy = new Proces;
Proces *pom;
 
        nowy->id = id;
        nowy->priorytet = prior;
 
        pom = KListy;
        KListy->next = nowy;
        nowy->poprzed = pom;
 
        KListy = nowy;
}
void dodajElDoListy(Proces *&KListy,Proces *&PListy,Proces *&korzen,int id,int prior,int ilosc_el)
{
Proces *nowy = new Proces;
Proces *pom_next=NULL;
                                       //komentarz
                nowy->id = id;
                nowy->priorytet = prior;
 
        if(ilosc_el == 1)
                {
             pom_next = PListy;
             PListy = nowy;
             KListy = nowy;
             korzen = nowy;
             nowy->next = pom_next ;
                }else{
                        pom_next = PListy;
                        PListy = nowy;
                        pom_next->poprzed = PListy;
                        nowy->next = pom_next ;
                }
 
}
//-------------------------------------------------------------------------------------------------------------------------------
void wypiszOdPocz(Proces *&PListy)
{
Proces *ide=NULL;
 
        ide = PListy;
        while(ide != NULL)
        {
                cout<<ide->id<<" <- "<<&ide->id<<"\n";
                ide = ide->next;
        }
}
void wypiszOdKon(Proces *&KListy)
{
Proces *ide=NULL;
 
        ide = KListy;
        while(ide != NULL)
                {
                                cout<<ide->id<<"\n";
                                ide = ide->poprzed;
                }
}
void wypiszListe(Proces *&KListy,Proces *&korzen)
{
 
        cout<<korzen->id<<"\n";
        if(korzen->poprzed == NULL) korzen = KListy;
        else korzen = korzen->poprzed;
 
}
void wypisz_el(Proces *&korzen,Proces *&KListy,int prior)
{
        if(prior == 1) wypiszWgPrior(korzen,KListy,ilElOpriorP1);
        if(prior == 0) wypiszWgPrior(korzen,KListy,ilElOpriorP0);
        if(prior == -1) wypiszWgPrior(korzen,KListy,ilElOpriorPm1);
}
void wypiszWgPrior(Proces *&korzen,Proces *&KListy,int ilosc_el)
{
Proces *ide=NULL;                       //od konca ide
        ide = korzen;
 
        for(int i=1;i<=ilosc_el;i++)
        {
                cout<<ide->id<<" ";
                if(ide->poprzed == NULL) ide = KListy;
                else ide = ide->poprzed;
        }
 
}
//-----------------------------------------------------------------------------------------------------------------------------
void IdzPojedOdKon(Proces *&korzenP1,Proces *&KListyP1,Proces *&korzenP0,Proces *&KListyP0,Proces *&korzenPm1,Proces *&KListyPm1)
{
 
   if(flagaP1 == 1){wypiszListe(KListyP1,korzenP1); }
   else if(flagaP0 == 1){wypiszListe(KListyP0,korzenP0); }
   else if(flagaPm1 == 1){wypiszListe(KListyPm1,korzenPm1);}
 
}
//---------------------------------------------------------------------------------------------------------------------------------
 
void zmianaFlagi(int prior)
{
        if(prior==1) {flagaP1 =1; ilElOpriorP1++;}
        if(prior == 0) {flagaP0 =1;ilElOpriorP0++;}
        if(prior == -1){flagaPm1 =1;ilElOpriorPm1++;}
}
 
 
//-------------------------------------------------------------------------------------------------
void usunPodanyEl(Proces *&KListyP1,Proces *&PListyP1,Proces *&KListyP0,Proces *&PListyP0,Proces *&KListyPm1,Proces *&PListyPm1,int id
                ,Proces *&korzenP1,Proces *&korzenP0,Proces *&korzenPm1)
{
        if(flagaP1 == true && ilElOpriorP1>1){if(usunEL(KListyP1,PListyP1,id,korzenP1))ilElOpriorP1--;}
        else if(flagaP1 == true && ilElOpriorP1 == 1 && KListyP1->id == id) {usunOstatni(KListyP1);
                                                                                                                                                ilElOpriorP1--;
                                                                                                                                                usunFlagi(1,KListyP1,PListyP1,korzenP1);}
 
        if(flagaP0 == true && ilElOpriorP0>1){if(usunEL(KListyP0,PListyP0,id,korzenP0))ilElOpriorP0--;}
        else if(flagaP0 == true && ilElOpriorP0 == 1 && KListyP0->id == id) {usunOstatni(KListyP0);
                                                                                                                                                        ilElOpriorP0--;
                                                                                                                                                        usunFlagi(0,KListyP0,PListyP0,korzenP0);}
 
        if(flagaPm1 == true && ilElOpriorPm1>1){if(usunEL(KListyPm1,PListyPm1,id,korzenPm1))ilElOpriorPm1--;}
        else if(flagaPm1 == true && ilElOpriorPm1 == 1 && KListyPm1->id == id) {usunOstatni(KListyPm1);
                                                                                                                                                ilElOpriorPm1--;
                                                                                                                                                usunFlagi(-1,KListyPm1,PListyPm1,korzenPm1);}
 
}
bool usunEL(Proces *&KListy,Proces *&PListy,int id,Proces *&korzen)
{
Proces *ide=NULL;
bool flagaUsuniecia = 0;
 
        ide = PListy;
 
        while(ide !=NULL && flagaUsuniecia == 0)
        {
                if(ide->id == id)
                {
                        if(ide->poprzed == NULL) {if(korzen == ide) korzen = KListy;
                                                                         flagaUsuniecia = usunZpocz(PListy);}
                        else if(ide->next == NULL) {if(korzen == ide) korzen = korzen->poprzed;
                                                                  flagaUsuniecia  = usunZkon(KListy); }
                        else {if(korzen == ide) korzen = korzen->poprzed;
                                 flagaUsuniecia = usunZsrod(ide);}
                }else ide = ide->next;
        }
        if(flagaUsuniecia == 1) return true;
        else if(flagaUsuniecia == 0) return false;
 
return 0;
}
bool usunZpocz(Proces *&PListy)
{
        Proces *pom=NULL;
 
        pom = PListy;
        PListy = PListy->next;
        PListy->poprzed = NULL;
 
delete pom;
 
return true;
}
bool usunZkon(Proces *&KListy)
{
Proces *el_wsk=NULL;
 
        el_wsk = KListy;
        KListy = KListy->poprzed;
        KListy->next = NULL;
 
 
delete el_wsk;
 
return true;
}
 
bool usunZsrod(Proces *&List)
{
Proces *el_pop=NULL;
Proces *el_wsk=NULL;
 
        el_wsk = List;
        el_pop = List->poprzed;
        el_pop->next = List->next;
        List->next->poprzed = el_pop;
 
delete el_wsk;
 
return true;
}
void usunOstatni(Proces *&Lista)
{
Proces *pom=NULL;
        pom = Lista;
delete pom;
}
void usunFlagi(int prior,Proces *&KLista,Proces *&PLista,Proces *&korzen)
{
        if(prior == 1) flagaP1 =0;
        else if(prior == 0) flagaP0 = 0;
        else if(prior == -1) flagaPm1 = 0;
 
        KLista = PLista = korzen = NULL;
 
}
void wypiszDane()
{
cout<<"\nDane: \n";
cout<<"Flagi: "<<flagaP1 <<" "<<flagaP0<<" "<<flagaPm1<<"\n";
cout<<"Ilosci: "<<ilElOpriorP1 <<" "<<ilElOpriorP0<<" "<<ilElOpriorPm1<<"\n";
}
