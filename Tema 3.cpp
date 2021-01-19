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
    in>>medie;
}

void elev::afisare(ostream &out)

{
    out<<"Datele elevului sunt: ";
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
    in>>numar;
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
};

///----clasa CATALOG SINGLETON
class catalog
{
private:
    string numecatalog;
    vector<elev*> elevi;
    vector<profesor*>profesori;
    static catalog* instance;
    catalog(string=" ");
public:
    static catalog* get_instance(string);
    catalog(const catalog& obj);
    ~catalog();
    void add_elevi();
    void add_profesori();
    catalog& operator=(catalog& obj);
    void afis_elevi();
    void afis_profi();
    void menu_output();

};
catalog* catalog::instance = NULL;

catalog::catalog(string numecatalog): numecatalog(numecatalog) {}

catalog* catalog::get_instance(string numecatalog)
{
    if(instance==NULL)
    {
        instance=new catalog(numecatalog);
    }
    return instance;
}
catalog::catalog(const catalog& obj)
{
    this->numecatalog= obj.numecatalog;
    for(unsigned int i=0; i<elevi.size(); i++)
        this->elevi.push_back(obj.elevi[i]);
    for(unsigned int i=0; i<profesori.size(); i++)
        this->profesori.push_back(obj.profesori[i]);
    for(unsigned int i=0; i<profesori.size(); i++)
        this->profesori.push_back(obj.profesori[i]);
}

catalog::~catalog()
{
    numecatalog="";
    for(unsigned int i=0; i<elevi.size(); i++)
        delete elevi[i];
    elevi.clear();
    for(unsigned int i=0; i<profesori.size(); i++)
        delete profesori[i];
    profesori.clear();
}
void catalog::add_elevi()
{

    elev *p =new elev;
    cin>>*p;
    elevi.push_back(p);

}

void catalog::add_profesori()
{

    profesor *p =new profesor;
    cin>>*p;
    profesori.push_back(p);

}
catalog& catalog::operator=(catalog& obj)
{
    if (this != &obj)
    {
        this->numecatalog=obj.numecatalog;
        for(unsigned int i=0; i<elevi.size(); i++)
            this->elevi.push_back(obj.elevi[i]);
        for(unsigned int i=0; i<profesori.size(); i++)
            this->profesori.push_back(obj.profesori[i]);

    }
    return *this;
}
void catalog::afis_elevi()
{

    for(unsigned int i=0; i<elevi.size(); i++)
        cout<<*elevi[i];
}

void catalog::afis_profi()
{
    for(unsigned int i=0; i<profesori.size(); i++)
        cout<<*profesori[i];
}
void catalog::menu_output()
{
    cout<<"\nCATALOG\n";
    cout<<"Catalog: " << this->numecatalog << "\n";
    cout<<"\n\t\tMENIU:";
    cout<<"\n===============================================\n";
    cout<<"1.Citeste elevi\n";
    cout<<"2.Citeste profesori\n";
    cout<<"3.Afiseaza elevi\n";
    cout<<"4.Afiseaza profesori\n";
    cout<<"0.Iesire.\n";

}
void menu_singleton1()
{
    int option;
    option=0;
    catalog *c = c->get_instance("Clasa X");
    do
    {
        c->menu_output();
        cout<<"Introduceti numarul actiunii: ";
        cin>>option;
        if(option==1)
            c->add_elevi();
        if(option==2)
            c->add_profesori();
        if(option==3)
            c->afis_elevi();
        if(option==4)
            c->afis_profi();
        if (option==0)
        {
            cout<<"\nRevenire in meniul anterior!\n";
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
}
class Singleton2
{
    static Singleton2 *instance;
    int data;
    vector<persoana*> p;
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
        persoana *x =new persoana;
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
    do
    {
        cout<<"\nProiect POO - Activitatea unei scoli\n";
        cout<<"-------------------------------------------------------\n";
        cout<<"1.Citirea datelor unei clase\n";
        cout<<"2.Afisarea datelor unei clase\n";
        cout<<"3.Citirea datelor unei scoli (o scoala are mai multe clase) -----TEMPLATE\n";
        cout<<"4.Afisarea datelor unei scoli ----TEMPLATE\n";
        cout<<"5.Catalogul unei clase --- SINGLETON\n";
        cout<<"6.Citirea datelor unei persoane si afisarea unui cod pentru persoana (fiecare persoana citita aici va avea un alt cod) ---SINGLETON\n";
        cout<<"Introduceti numarul actiunii: ";
        cin>>option;
        if(option==1)
        {
            cin>>d;
        }
        if(option==2)
        {
            cout<<d;
        }
        if(option==3)
        {
            cin>>x;
        }
        if(option==4)
        {
            cout<<x;
        }
        if(option==5)
        {
            menu_singleton1();
        }
        if(option==6)
        {
            s->add_pers();
            cout<<s->generare_cod();
        }
        if(option==0)
        {
            cout<<"\nEXIT\n";
        }
        if (option<0 || option>6)
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
