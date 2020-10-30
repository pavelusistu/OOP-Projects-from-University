#include <iostream>
using namespace std;

class elevi
{
    string nume;
    char sex;
    int varsta;
public:
    void citire();
    void afisare();
};
void elevi::citire()

{
    cout<<"Nume: ";
    cin>>nume;
    cout<<"Sex: ";
    cin>>sex;
    cout<<"Varsta: ";
    cin>>varsta;
}

void elevi::afisare()

{
    cout<<nume<<" "<<sex<<" "<<varsta<<endl;
}

class clasa
{
    int numar;
    char litera;
    string specializare;
    int sala;
    elevi *c;
public:
    void citire();
    void afisare();
    clasa();
    clasa(int,char,string,int);
    clasa(clasa&);
    ~clasa();
    clasa& operator=(const clasa&);
    void afisare(ostream &out);
    friend ostream& operator<<(ostream &out, clasa& x);
};

clasa::clasa()
{
    this->c=new elevi;
    c=NULL;
}
clasa::clasa(int numar,char litera, string specializare, int sala)
{
    this->numar=numar;
    this->litera=litera;
    this->specializare=specializare;
    this->sala=sala;
}
clasa::clasa(clasa &x)
{
    this->numar=x.numar;
    this->litera=x.litera;
    this->specializare=x.specializare;
    this->sala=x.sala;

}
clasa::~clasa()

{
    delete[] c;
}


void clasa::citire()

{
    cout<<"Nr. clasei: ";
    cin>>numar;
    cout<<"Litera: ";
    cin>>litera;
    cout<<"Specializarea: ";
    cin>>specializare;
    cout<<"Sala: ";
    cin>>sala;
}

void clasa::afisare()
{
    cout<<numar<<" "<<litera<<" "<<specializare<<" "<<sala<<endl;
}
clasa& clasa::operator=(const clasa &x)
{

    numar=x.numar;
    litera=x.litera;
    specializare=x.specializare;
    sala=x.sala;
}

void clasa::afisare(ostream &out)
{
    out<<numar<<" "<<litera<<" "<<specializare<<" "<<sala<<"\n";
}
ostream& operator<<(ostream& out, clasa& x)
{
    x.afisare(out);
    return out;
}

int main()
{
    clasa p;
    const int n=5;
    cout<<"Cititi clasa: "<<endl;
    p.citire();
    p.afisare();
    cout<<"Numarul elevilor din clasa este: "<<n<<endl;
    elevi e[30];
    cout<<"Cititi datele elevilor: "<<endl;
    for(int i=0; i<5; i++)
        e[i].citire();
    for(int i=0; i<5; i++)
        e[i].afisare();
    return 0;
}

