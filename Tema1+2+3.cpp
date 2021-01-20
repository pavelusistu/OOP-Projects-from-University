#include <iostream>
#include <algorithm>
#include <vector>
#include "rlutil.h"
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
    int get_varsta()
    {
        return varsta;
    }

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

    cout<<"Sex(F/M):  ";
    int ok;
    do
    {
        try
        {
            in>>sex;
            if(!(sex=='M'|| sex=='F'))
            {
                throw 1;
                ok=0;
            }
            else
                ok=1;
        }
        catch(int i)
        {
            cout<<"Introduceti un caracter valid pentru sex. Alegeti M sau F: ";
            ok=0;
        }
    }
    while(ok==0);

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
    out<<"Profesorul: ";
    persoana::afisare(out);
    out<<"Materia predata este: ";
    out<<materie<<endl;
}


profesor& profesor::operator=(const profesor &p)

{
    if (this!=&p)
    {
        persoana::operator=(p);
        materie=p.materie;
    }
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
    int ok;
    do
    {
        try
        {
            in>>medie;
            if(!(medie>=1 && medie<=10))
            {
                throw 1;
                ok=0;
            }
            else
                ok=1;
        }
        catch(int i)
        {
            cout<<"Introduceti un numar valid pentru medie. Acesta trebuie sa fie intre 1 si 10: ";
            ok=0;
        }
    }
    while(ok==0);
}

void elev::afisare(ostream &out)

{
    out<<"Elevul: ";
    persoana::afisare(out);
    out<<"Media generala a elevului este: ";
    out<<medie<<endl;
}



elev& elev::operator=(const elev &e)

{
    if (this!=&e)
    {
        persoana::operator=(e);
        medie=e.medie;
    }

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
    vector <profesor*> p;
    vector <elev*> c;
public:
    clasa(int,int,int,int,char,string);
    clasa(const clasa&);
    ~clasa();
    clasa& operator=(const clasa&);
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, clasa &x);
    friend ostream& operator<<(ostream &out, clasa &x);
};


clasa::clasa(int numar=0, int sala=0, int n=0, int nr_profi=0, char litera=' ', string specializare=" ")

{
    this->nr_profi=nr_profi;
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
    for(unsigned int i=0; i<x.c.size(); i++)
        this->c.push_back(x.c[i]);
    for(unsigned int i=0; i<x.p.size(); i++)
        this->p.push_back(x.p[i]);

}

clasa::~clasa()

{
    n=0;
    numar=0;
    litera=' ';
    specializare=" ";
    sala=0;
    for(unsigned int i=0; i<c.size(); i++)
        delete c[i];
    c.clear();
    for(unsigned int i=0; i<p.size(); i++)
        delete p[i];
    p.clear();
}


void clasa::citire(istream &in)

{
    cout<<"Nr. clasei: ";
    int ok;
    do
    {
        try
        {
            in>>numar;
            if(!(numar>=0 && numar<=12))
            {
                throw 1;
                ok=0;
            }
            else
                ok=1;
        }
        catch(int i)
        {
            cout<<"Introduceti un numar valid pentru clasa. Alegeti un numar de la 0 la 12: ";
            ok=0;
        }
    }
    while(ok==0);

    cout<<"Litera: ";
    in>>litera;
    cout<<"Specializarea: ";
    in>>specializare;
    cout<<"Sala: ";
    in>>sala;
    cout<<"Nr. de profesori care predau la clasa este: ";
    in>>nr_profi;
    for(int i=0; i<nr_profi; i++)
    {
        profesor *x=new profesor;
        in>>*x;
        p.push_back(x);

    }
    cout<<"Nr. de elevi al clasei este: ";
    in>>n;
    for(int i=0; i<n; i++)
    {
        elev *y=new elev;
        in>>*y;
        c.push_back(y);

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
    for(unsigned int i=0; i<x.c.size(); i++)
        this->c.push_back(x.c[i]);
    for(unsigned int i=0; i<x.p.size(); i++)
        this->p.push_back(x.p[i]);
    return *this;
}

void clasa::afisare(ostream &out)

{
    out<<"Datele clasei sunt: ";
    out<<numar<<" "<<litera<<" "<<specializare<<" "<<sala<<"\n";
    for(unsigned int i=0; i<p.size(); i++)
    {
        out<<*p[i];
    }
    for(unsigned int i=0; i<c.size(); i++)
    {
        out<<*c[i];
        c[i]->promovabilitate();
        c[i]->performanta();
    }
}

ostream& operator<<(ostream& out, clasa& x)

{
    x.afisare(out);
    return out;
}

template <class t> class scoala
{
    t *v;
    t *vcpy;
    int n;
public:
    scoala(t *p=NULL, int m=0)
    {
        n=m;
        v=new t[n];
        for(int i=0; i<n; i++)
        {
            v[i]=p[i];
        }
    }
    scoala(const scoala &a)
    {
        n=a.n;
        v=new t[n];
        for(int i=0; i<n; i++)
        {
            v[i]=a.v[i];
        }
    }
    ~scoala()
    {
        delete[] v;
    }
    int get_n()
    {
        return n;
    }
    t get_v(int i)
    {
        return v[i];
    }
    friend istream& operator>>(istream& in, scoala <t> &g)
    {
        cout<<"Numarul de clase din scoala este: ";
        in>>g.n;
        g.v=new t[g.n];
        for(int i=0; i<g.n; i++)
        {
            in>>g.v[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, scoala <t> &g)
    {
        out<<"Numarul de clase din scoala este: ";
        out<<g.n<<endl;
        for(int i=0; i<g.n; i++)
        {
            out<<g.v[i];
        }
        return out;
    }
    scoala <t>& operator=(const scoala <t> & x)
    {
        if(this!=&x)
        {
            n=x.n;
            v=new t[n];
            for(int i=0; i<n; i++)
            {
                v[i]=x.v[i];
            }
        }
        return *this;
    }
    scoala& operator+=(const scoala <t>& a)
    {
        t cls;
        cout<<"\nAdaugarea unei clase in scoala:\n";
        cin>>cls;

        if(n==0)
        {
            this->v=new t[n+1];
            v[n]=cls;
            this->n=n+1;
        }
        else
        {
            this->vcpy=new t[n+1];
            for(int i=0; i<n; i++)
                this->vcpy[i]=this->v[i];
            this->v=new t[n+1];
            for(int i=0; i<n; i++)
                this->v[i]=this->vcpy[i];
            v[n]=cls;
            this->n=n+1;
        }
        return *this;
    }
};

///----clasa CATALOG SINGLETON
class concurs
{
private:
    string numeconcurs;
    vector<elev*> elevi;
    vector<profesor*>profesori;
    vector<clasa*>clase;
    static concurs* instance;
    concurs(string=" ");
public:
    static concurs* get_instance(string);
    concurs(const concurs& obj);
    ~concurs();
    void add_elevi();
    void add_profesori();
    concurs& operator=(concurs& obj);
    void afis_elevi();
    void afis_profi();
};
concurs* concurs::instance = NULL;

concurs::concurs(string numeconcurs): numeconcurs(numeconcurs) {}

concurs* concurs::get_instance(string numeconcurs)
{
    if(instance==NULL)
    {
        instance=new concurs(numeconcurs);
    }
    return instance;
}
concurs::concurs(const concurs& obj)
{
    this->numeconcurs= obj.numeconcurs;
    for(unsigned int i=0; i<elevi.size(); i++)
        this->elevi.push_back(obj.elevi[i]);
    for(unsigned int i=0; i<profesori.size(); i++)
        this->profesori.push_back(obj.profesori[i]);
}

concurs::~concurs()
{
    numeconcurs="";
    for(unsigned int i=0; i<elevi.size(); i++)
        delete elevi[i];
    elevi.clear();
    for(unsigned int i=0; i<profesori.size(); i++)
        delete profesori[i];
    profesori.clear();
}
void concurs::add_elevi()
{

    elev *p =new elev;
    cin>>*p;
    elevi.push_back(p);

}

void concurs::add_profesori()
{

    profesor *p =new profesor;
    cin>>*p;
    profesori.push_back(p);

}
concurs& concurs::operator=(concurs& obj)
{
    if (this != &obj)
    {
        this->numeconcurs=obj.numeconcurs;
        for(unsigned int i=0; i<elevi.size(); i++)
            this->elevi.push_back(obj.elevi[i]);
        for(unsigned int i=0; i<profesori.size(); i++)
            this->profesori.push_back(obj.profesori[i]);

    }
    return *this;
}
void concurs::afis_elevi()
{

    for(unsigned int i=0; i<elevi.size(); i++)
        cout<<*elevi[i];
}

void concurs::afis_profi()
{
    for(unsigned int i=0; i<profesori.size(); i++)
        cout<<*profesori[i];
}

class Singleton2
{
    static Singleton2 *instance;
    int data;
    vector<elev*> p;
    Singleton2()
    {
        data = 0;
    }

public:
    static Singleton2 *get_instance()
    {
        if (!instance)
            instance = new Singleton2;
        return instance;
    }
    void add_pers()
    {
        elev *x =new elev;
        cin>>*x;
        p.push_back(x);
    }
    int generare_cod()
    {

        for(unsigned int i=0; i<p.size(); i++)
            data=i+1000;
        return data;
    }
};
Singleton2 *Singleton2::instance = 0;

int main()

{

    int option;
    option=0;
    clasa d;
    scoala <clasa> x;
    Singleton2 *s = s->get_instance();
    concurs*c = c->get_instance("Concurs X");
    do
    {
        cout<<"\nProiect POO - Activitatea unei scoli\n";
        cout<<"-------------------------------------------------------\n";
        cout<<"1.Citirea datelor unei scoli (o scoala are mai multe clase) -----TEMPLATE\n";
        cout<<"2.Afisarea datelor unei scoli cu optiunea de a adauga o clasa daca se doreste ----TEMPLATE\n";
        cout<<"3.Elevii si profesorii indrumatori care participa la CONCURS --- SINGLETON\n";
        cout<<"4.Citirea datelor unui elev si afisarea unui cod unic de identificare pentru elev ---SINGLETON\n";
        cout<<"Introduceti numarul actiunii: ";

        cin>>option;

        if(option==1)
        {
            cin>>x;
        }
        if(option==2)
        {
            scoala <clasa> z;
            int ok=-1;
            cout<<"Doriti sa adaugati o noua clasa? Daca da, introduceti 1, altfel introduceti 0: ";

            do
            {

                try
                {
                    cin>>ok;
                    if(!(ok==1 || ok==0))
                        throw 10;
                    else if(ok==1)
                    {
                        x+=z;
                        cout<<x;
                    }
                    else if(ok==0)
                    {
                        cout<<x;
                    }

                }

                catch(int i)
                {
                    cout<<"Introduceti 0 sau 1: ";
                    ok=-1;
                }
            }
            while(ok==-1);
        }
        if(option==3)
        {
            int nr;
            cout<<"Numarul elevilor care participa la concurs este: ";
            cin>>nr;
            cout<<"Cititi elevii care participa la concurs:\n";
            for(int i=0; i<nr; i++)
            {
                cout<<"Elevul "<<i+1<<"\n";
                c->add_elevi();
                cout<<"Cititi profesorul indrumator:\n";
                c->add_profesori();
            }

            cout<<"\nElevii care participa la concurs sunt:\n";
            c->afis_elevi();
            cout<<"\nProfesorii indrumatori sunt:\n";
            c->afis_profi();
        }
        if(option==4)
        {
            s->add_pers();
            cout<<"Codul elevului: "<<s->generare_cod();
        }
        if(option==0)
        {
            cout<<"\nEXIT\n";
        }
        if (option<0 || option>4)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        cout<<"Apasati ENTER...\n";
        cin.ignore().get();
        rlutil::cls();
    }
    while(option!=0);

    return 0;
}
