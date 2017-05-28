struct Proces;
 
void wczytaj_dane();
void dodaj_elNaPocz(Proces *&KListy,Proces *&PListy,Proces *&korzen,int id,int prior);
bool usunZpocz(Proces *&PListy);
bool usunZkon(Proces *&KListy);
bool usunZsrod(Proces *&List);
bool usunEL(Proces *&KListy,Proces *&PListy,int id,Proces *&korzen);
void usunPodanyEl(Proces *&KListyP1,Proces *&PListyP1,Proces *&KListyP0,Proces *&PListyP0,Proces *&KListyPm1,Proces *&PListyPm1,int id
                ,Proces *&korzenP1,Proces *&korzenP0,Proces *&korzenPm1);
void usunFlagi(int prior,Proces *&KLista,Proces *&PLista,Proces *&korzen);
void usunOstatni(Proces *&Lista);
void wypiszOdPocz(Proces *&PListy);
void wypiszOdKon(Proces *&KListy);
void IdzPojedOdKon(Proces *&korzenP1,Proces *&KListyP1,Proces *&korzenP0,Proces *&KListyP0,Proces *&korzenPm1,Proces *&KListyPm1);
void wypiszWgPrior(Proces *&korzen,Proces *&KListy,int ilosc_el);
void wypisz_el(Proces *&korzen,Proces *&KListy,int prior);
void zmianaFlagi(int prior);
void wypiszListe(Proces *&KListy,Proces *&korzen);
void dodajElDoListy(Proces *&KListy,Proces *&PListy,Proces *&korzen,int id,int prior,int ilosc_el);
void NaKoniec(Proces *&KListy,int id,int prior);
void dodaj_elNaKon(Proces *&KListy,Proces *&PListy,Proces *&korzen,int id,int prior);
void dodajZaElWsk(Proces *&korzen, int id,int prior);
 
void wypiszDane();
