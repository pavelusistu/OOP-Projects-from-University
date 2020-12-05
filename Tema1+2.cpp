#include <iostream>
using namespace std;

class persoana

{
protected:
    string nume;
    char sex;
    int varsta;
public:
    persoana(string,char,int);
    persoana(const persoana&);
    virtual ~persoana();
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream &in, persoana &p);
    friend ostream& operator<<(ostream &out, persoana &p);
    persoana& operator=(const persoana&);
};

persoana::persoana(string num=" ", char s=' ', int v=0)

{
    nume=num;
    sex=s;
    varsta=v;
}

persoana::persoana(const persoana& p)

{
    this->nume=p.nume;
    this->sex=p.sex;
    this->varsta=p.varsta;
}

persoana::~persoana()

{

}

void persoana::citire(istream &in)

{
    cout<<"Nume: ";
    in>>nume;
    cout<<"Sex: ";
    in>>sex;
    cout<<"Varsta: ";
    in>>varsta;
}

void persoana::afisare(ostream &out)

{
    out<<nume<<" "<<sex<<" "<<varsta<<" "<<endl;
}

istream& operator>>(istream &in, persoana &p)

{
    p.citire(in);
    return in;
}

ostream& operator<<(ostream &out, persoana &p)

{
    p.afisare(out);
    return out;
}

persoana& persoana::operator=(const persoana &p)

{
    nume=p.nume;
    sex=p.sex;
    varsta=p.varsta;
    return *this;
}

class profesor:public persoana

{
    string materie;
public:
    profesor(string, char, int, string);
    profesor(const profesor&);
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, profesor &p);
    friend ostream& operator<<(ostream &out, profesor &p);
    profesor& operator=(const profesor&);
};

profesor::profesor(string num=" ", char s=' ', int v=0, string mat=" "):persoana(num,s,v)

{
    materie=mat;
}

profesor::profesor(const profesor& p):persoana(p.nume,p.sex,p.varsta)

{
    this->materie=p.materie;
}

void profesor::citire(istream &in)

{
    persoana::citire(in);
    cout<<"Materie: ";
    in>>materie;
}

void profesor::afisare(ostream &out)

{
    out<<"Datele profesorului sunt: ";
    persoana::afisare(out);
    out<<"Materia predata este: ";
    out<<materie<<endl;
}

istream& operator>>(istream &in, profesor &p)

{
    p.citire(in);
    return in;
}

ostream& operator<<(ostream &out, profesor &p)

{
    p.afisare(out);
    return out;
}

profesor& profesor::operator=(const profesor &p)

{
    if (this!=&p)
        materie=p.materie;
    return *this;
}


class elev:public persoana

{
    float medie;
public:
    elev(string, char, int, float);
    elev(const elev&);
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, elev &e);
    friend ostream& operator<<(ostream &out, elev &e);
    elev& operator=(const elev&);
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

elev::elev(string num=" ", char s=' ', int v=0, float m=0):persoana(num,s,v)

{
    medie=m;
}

elev::elev(const elev& e):persoana(e.nume,e.sex,e.varsta)

{
    this->medie=e.medie;
}

void elev::citire(istream &in)

{
    persoana::citire(in);
    cout<<"Medie: ";
    in>>medie;
}

void elev::afisare(ostream &out)

{
    out<<"Datele elevului sunt: ";
    persoana::afisare(out);
    out<<"Media generala a elevului este: ";
    out<<medie<<endl;
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

elev& elev::operator=(const elev &e)

{
    if (this!=&e)
        medie=e.medie;
    return *this;
}


class clasa

{
    int n;
    int nr_profi;
    int numar;
    char litera;
    string specializare;
    int sala;
    profesor *p;
    elev *c;
public:
    clasa();
    clasa(int,int,int,int,char,string,elev*,profesor*);
    clasa(const clasa&);
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
    this->p=NULL;
    this->nr_profi=0;
    this->c=NULL;
    this->n=0;
    this->numar=0;
    this->litera='-';
    this->specializare="-";
    this->sala=0;
}

clasa::clasa(int numar, int sala, int n, int nr_profi, char litera, string specializare, elev *c, profesor *p)

{
    this->nr_profi=nr_profi;
    this->p=p;
    this->c=c;
    this->n=n;
    this->numar=numar;
    this->litera=litera;
    this->specializare=specializare;
    this->sala=sala;
}

clasa::clasa(const clasa &x)

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
    cout<<"Nr. clasei: ";
    in>>numar;
    cout<<"Litera: ";
    in>>litera;
    cout<<"Specializarea: ";
    in>>specializare;
    cout<<"Sala: ";
    in>>sala;
    cout<<"Nr. de profesori care predau la clasa este: ";
    in>>nr_profi;
    p=new profesor[nr_profi];
    for(int i=0; i<nr_profi; i++)
    {
        in>>p[i];
    }
    cout<<"Nr. de elevi al clasei este: ";
    in>>n;
    c=new elev[n];
    for(int i=0; i<n; i++)
    {
        in>>c[i];
    }

}

istream& operator>>(istream &in, clasa &x)

{
    x.citire(in);
    return in;
}

clasa& clasa::operator=(const clasa &x)

{
    c=x.c;
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
    for(int i=0; i<nr_profi; i++)
    {
        out<<p[i];
    }
    for(int i=0; i<n; i++)
    {
        out<<c[i];
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
