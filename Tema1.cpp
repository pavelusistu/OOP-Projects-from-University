#include <iostream>
using namespace std;

class elev
{
    string nume;
    char sex;
    int varsta;
    float medie;
public:
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, elev &e);
    friend ostream& operator<<(ostream &out, elev &e);
    elev(string, char, int, float);
    elev();
    void promovabilitate();
    void performanta();
};

void elev::performanta()

{
    if (medie>9.5 && medie<=10)
        cout<<"Elevului "<<nume<<" i se acorda premiul 1"<<endl;
    if (medie>9 && medie<=9.5)
        cout<<"Elevului "<<nume<<" i se acorda premiul 2"<<endl;
    if (medie>8.5 && medie<=9)
        cout<<"Elevului "<<nume<<" i se acorda premiul 3"<<endl;
    if (medie>8 && medie<=8.5)
        cout<<"Elevului "<<nume<<" i se acorda mentiune"<<endl;


}

void elev::promovabilitate()

{
    if (medie>=5)
        cout<<"Elevul "<<nume<<" a promovat clasa"<<endl;
    else
        cout<<"Elevul "<<nume<<" nu a promovat clasa"<<endl;
}

elev::elev()

{
    this->nume="n/a";
    this->sex='-';
    this->varsta=0;
    this->medie=0;
}

elev::elev(string nume, char sex, int varsta, float medie)

{
    this->nume=nume;
    this->sex=sex;
    this->varsta=varsta;
    this->medie=medie;
}

void elev::citire(istream &in)

{
    cout<<"Nume: ";
    in>>nume;
    cout<<"Sex: ";
    in>>sex;
    cout<<"Varsta: ";
    in>>varsta;
    cout<<"Medie: ";
    in>>medie;
}

void elev::afisare(ostream &out)

{
    out<<nume<<" "<<sex<<" "<<varsta<<" "<<medie<<endl;
}

istream& operator>>(istream &in, elev &e)

{
    e.citire(in);
    return in;
}

ostream& operator<<(ostream &out, elev &e)

{
    e.afisare(out);
    return out;
}

class clasa
{
    int n;
    int numar;
    char litera;
    string specializare;
    int sala;
    elev c[30];
public:
    clasa();
    clasa(int,char,string,int,int);
    clasa(clasa&);
    ~clasa();
    clasa& operator=(const clasa&);
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, clasa &x);
    friend ostream& operator<<(ostream &out, clasa &x);
    void situatie();
};

void clasa::situatie()
{
    for(int i=0; i<n; i++)
    {
        c[i].promovabilitate();
        c[i].performanta();
    }

}

clasa::clasa()

{
    this->n=0;
    this->numar=0;
    this->litera='-';
    this->specializare="-";
    this->sala=0;
}

clasa::clasa(int numar,char litera, string specializare, int sala, int n)

{
    this->n=n;
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

}


void clasa::citire(istream &in)

{
    cout<<"Nr. de elevi al clasei este: ";
    in>>n;
    cout<<"Nr. clasei: ";
    in>>numar;
    cout<<"Litera: ";
    in>>litera;
    cout<<"Specializarea: ";
    in>>specializare;
    cout<<"Sala: ";
    in>>sala;
    for(int i=0; i<n; i++)
    {
        c[i].citire(in);
    }

}

istream& operator>>(istream &in, clasa &x)

{
    x.citire(in);
    return in;
}

clasa& clasa::operator=(const clasa &x)

{
    numar=x.numar;
    litera=x.litera;
    specializare=x.specializare;
    sala=x.sala;
    n=x.n;
    return *this;
}

void clasa::afisare(ostream &out)

{
    out<<"Datele clasei sunt: ";
    out<<numar<<" "<<litera<<" "<<specializare<<" "<<sala<<"\n";
    out<<"Elevii clasei sunt: "<<endl;
    for(int i=0; i<n; i++)
    {
        c[i].afisare(out);
    }
}
ostream& operator<<(ostream& out, clasa& x)
{
    x.afisare(out);
    return out;
}



int main()
{
    clasa p;
    cout<<"Cititi datele clasei"<<endl;
    cin>>p;
    cout<<p;
    p.situatie();
    return 0;
}
