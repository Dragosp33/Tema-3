#include <iostream>
#include <assert.h>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
class Animal {
protected:
    std::string m_name;
public:
    Animal() {}
    Animal (std::string name): m_name {name} {}
    virtual void set_name(std::string name) {m_name = name;}
    virtual std::string get_name () {return m_name;}
    virtual std::string regn()  const { return "???"; }

    virtual ~Animal(){
    cout << "Destructor animal"<<'\n';}
  friend istream& operator >> (istream &in,  Animal* k){
    in>> k->m_name;


   return in;}
   friend std::ostream& operator<<(std::ostream &out, Animal *a){
    return a->print(out, a);}
    virtual std::ostream& print(std::ostream& out, Animal * a) const
	{
		out << "Animal\t";
		out << a->get_name();
		return out;}
    virtual Animal* operator=(Animal* rhs){
    this->set_name(rhs->get_name());}
};
class Nevertebrate : public Animal{
public:
    virtual std::string regn() const { return "nevertebrate";}
    virtual ~Nevertebrate();
};
class Vertebrate: public Animal {
protected:

    Vertebrate() : Animal () {}
        Vertebrate (std::string name)
            : Animal {name} {}
public:


//operatorul << prin functie membru;
 //  friend std::ostream& operator<<(std::ostream &out, Vertebrate *a){
 //   return a->print(out, a);}
    virtual std::ostream& print(std::ostream& out, Animal * a) const override
	{
		out << "Vertebrate";
		out << a->get_name() << "REGN"<<a->regn();
		return out;}
    virtual Animal* operator=(Animal* rhs) override{
    this->set_name(rhs->get_name());
    cout << "Vertebrate =  ";}
    virtual std::string regn() const { return "vertebrate";}
    virtual ~Vertebrate(){
    cout<<"Destructor vertebrate"<<'\n';};
};


class Pasare: public Vertebrate {
public:
    virtual std::ostream& print(std::ostream& out, Animal * a) const override
	{
		out << "Pasari\t";
		out << a->get_name()<<"\t" << "REGN\t"<<a->regn()<<'\n';
		return out;}
    virtual Animal* operator=(Animal* rhs) override{
    this->set_name(rhs->get_name());
    cout << " = pasari =  ";}
    Pasare() : Vertebrate(){}
    Pasare(std::string name)
        : Vertebrate{ name }{}
    void set_name (std::string nume){
    m_name = nume;}

    std::string get_name(){
    return m_name;}

    std::string regn()  const override {return "pasare";}
     ~Pasare (){
    cout << "destructor pasare"<<'\n';}

 };
class Mamifere: public Vertebrate {
public:
     virtual std::ostream& print(std::ostream& out, Animal * a) const override
	{
		out << "Mamifere\t";
		out << a->get_name() << "REGN\t"<<a->regn()<<'\n';
		return out;}
    Mamifere(): Vertebrate(){}
    Mamifere(std::string name) : Vertebrate { name } {}
    void set_name (std::string nume){
    m_name = nume;}

    std::string get_name(){
    return m_name;}

    std::string regn()  const override {return "mamifere";}
     ~Mamifere (){
    cout << "destructor mamifere"<<'\n';}};

class Peste: public Vertebrate {
protected:
    bool rapitor;
    float lungime;
public:
     virtual std::ostream& print(std::ostream& out, Animal * a) const override
	{
		out << "Pestele:\t";
		out << a->get_name() << "tipul pestelui\t"<<a->regn()  <<'\n';
		return out;}
    Peste(): Vertebrate(){}
    Peste(std::string name, float l) : Vertebrate { name } { lungime = l;}
    void set_name (std::string nume){
    m_name = nume;}
    void set_rapitor(bool x){rapitor = x;}
    bool get_rapitor() {return rapitor;}
    std::string get_name(){
    return m_name;}
    void set_lungime (float x){lungime = x;}
    float get_lungime (){return lungime;}

    std::string regn()  const override { if(rapitor == false) return "peste";
                                          else return "PESTE RAPITOR";}
     ~Peste (){
    cout << "destructor peste"<<'\n';}
};

template <class T>
class Atlas2;

template<typename T>
std::istream& operator>>(std::istream& in,const Atlas2<T>& A);
template<typename T>
std::ostream& operator<< (std::ostream& out, const Atlas2<T> & A);
// Test varianta 3:
template<class T>
class Atlas2{
public:
int nr_pesti;
   int  m_length;
    std::list<T> pagini;
    Atlas2(){m_length = 0; nr_pesti = 0;}
    ~Atlas2(){}
    void adauga(T data);
    void adauga(Peste* data);
   Atlas2 operator += (const T& data){
   this->m_length++;
   this->pagini.push_back(data);
   return *this;}
    friend std::istream& operator>> <> (std::istream& in, const Atlas2<T>& A);
    friend std::ostream& operator<< <> (std::ostream& out, const Atlas2<T> &A);
   };

// Functie pentru verificarea si evitarea unei greseli atunci cand introducem in citire numarul de pagini.
int Get_length(){ while (true){
    int x;
    cin >> x;
    if (std::cin.fail()) // insertia a esuat
{
    std::cin.clear(); // elimina eroarea
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // sterge inputul gresit
    std::cout << "Hopa hopa, trebuie sa introduci un NUMAR INTREG care semnifica numarul de pagini din atlas.\n";

}
    else // altfel, insertia a reusit
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            return x; //returneaza valoarea lui x
        }

}}
//functie pentru optimizarea stringului citit de la tastatura ce semnifica tipul de animal citit, exemplu: abnPasare => Pasare;
int FindString(std::string s1, std::string s2 ){
int i = 0;
  for (i=0; i<s1.size(); i++){
    std::string s = s1.substr(i, s2.size());
    if( s == s2)
        return 1;

}
return 0;
}


template <class T>
std::istream& operator>> (istream &in, Atlas2<T> &A)
{   if(A.m_length != 0){A.m_length = 0;
    A.pagini.clear();}  // Daca incercam sa citim un obiect atlas deja initializat, se vor sterge automat datele din el.
    A.m_length = Get_length();
    for (int i=1; i<=A.m_length; i++){
        std::string tip;
        in >> tip;
        std::for_each(tip.begin(), tip.end(), [](char & c) {
        c = ::tolower(c);  // toate elementele din string vor lua lower pentru a se putea introduce un animal de tipul PasArE;
    });
        try { if (tip == "vertebrate")
                throw "Nu se pot adauga vertebrate, trebuie specificat tipul";
                if(FindString(tip, "animal")==0 && FindString(tip, "pasare")==0
                   && FindString(tip, "peste")==0 && FindString(tip, "mamifer"))
                    throw -1;
                }
        catch (std::string){
        std::cout << "S-a detectat eroarea: Ai incercat sa adaugi vertebrate, fara sa specifici tipul"<<'\n';
        in >> tip;
        std::for_each(tip.begin(), tip.end(), [](char & c) {
        c = ::tolower(c);
    });
        }
        catch (int){std::cout<<"Tipul introdus este incompatibil, introdu unul valid (ex: 'pasare', 'animal')\n";
        in >> tip;
        std::for_each(tip.begin(), tip.end(), [](char & c) {
        c = ::tolower(c);
    });}

        if (FindString(tip, "animal")==1){
        T data = new Animal;
        std::string nume;
        in >> nume;
        data->set_name(nume);
        A.pagini.push_back(data);}
        else if(FindString(tip,"pasare") ==1){
        T data = new Pasare;
        std::string nume;
        in >> nume;
        data->set_name(nume);
        A.pagini.push_back(data);}
        else if(FindString(tip, "mamifer")==1){
        T data = new Mamifere;
        std::string nume;
        in >> nume;
        data->set_name(nume);
        A.pagini.push_back(data);}
        else if(tip == "peste"){
            T data = new Peste;

            std::cout << "Peste rapitor?\t";

            std::string raspuns;
            cin >> raspuns;
            std::for_each(raspuns.begin(), raspuns.end(), [](char & c) {
            c = ::tolower(c);});

            if(raspuns == "da"){
                std::cout << "Introdu lungimea:\t";
                dynamic_cast <Peste *>(data)->set_rapitor(true);

                int n = Get_length();
                dynamic_cast <Peste *>(data)->set_lungime(n);
            }
            else {dynamic_cast <Peste *>(data)->set_rapitor(false);}
            std::string nume;
            in >> nume;
            data->set_name(nume);
            A.pagini.push_back(data);
        }}
    return in;
}
template <class T>
std::ostream& operator<< (ostream &out, Atlas2<T> &A){
  out <<"Numarul de pagini este:"<< A.m_length <<'\n';
  out <<"Animalele aflate in atlas sunt :\n";
  for (T x : A.pagini){
                    out << x->get_name();
                    std::cout <<" - ";
                    out << x->regn();
                    std::cout<<",\t";}
    return out;
  }

//2 functii de adaugare pe care nu le-am mai folosit
/*template <class T>
void Atlas2<T>::adauga(T data){m_length = m_length+1;
pagini.push_back(data);}
template <class T>
void Atlas2<T>::adauga(Peste* data){m_length = m_length+1;
pagini.push_back(data);}*/

//Specializare pesti;
template <>
class Atlas2<Peste *>{
private:

    int nr_pesti_rapitori;

public:
    int m_length;
    std::list<Peste *> lista_pesti;
    void set_length(int x){m_length = x;}
    void set_nrpesti(int x){nr_pesti_rapitori = x;}
    int get_lungimeAtlas(){return m_length;}
    int get_nrpesti(){return nr_pesti_rapitori;}
  //  void set_lista(std::list<Peste *>l) {lista_pesti = l;}
  //  std::list<Peste *> get_lista() {return lista_pesti;}
    Atlas2(){m_length = 0; nr_pesti_rapitori = 0;}
    ~Atlas2(){m_length= 0;  nr_pesti_rapitori=0;}
    Atlas2 operator += ( Peste* data){

   this->m_length++;
   this->lista_pesti.push_back(data);
   if (data->get_rapitor() == 1 && data->get_lungime() > 1)    {set_nrpesti(get_nrpesti()+1);}
   return *this;}
   friend std::istream& operator>> <> (std::istream& in, const Atlas2<Peste *>& P);
   friend std::ostream& operator<< <> (std::ostream &os, const Atlas2<Peste *>& P);
};
//operator citire - specializare pesti;
template <>
std::istream& operator>> <>(std::istream&in, Atlas2<Peste *>& P){
if(P.get_lungimeAtlas() != 0){P.set_length(0);
    P.lista_pesti.clear();}  // Daca incercam sa citim un obiect atlas deja initializat, se vor sterge automat datele din el.
    P.set_length(Get_length()) ;
    for (int i=1; i<=P.get_lungimeAtlas(); i++){
        Peste *data = new Peste;
        std::string nume;
        in >> nume;
        data->set_name(nume);
        std::cout << "Peste Rapitor?\n";
        std::string raspuns;
            cin >> raspuns;
            std::for_each(raspuns.begin(), raspuns.end(), [](char & c) {
            c = ::tolower(c);});

            if(raspuns == "da"){

                std::cout << "Introdu lungimea:\t";
                float x; std::cin>>x;
                data->set_rapitor(true);
                data->set_lungime(x);
                if(x>1){P.set_nrpesti(P.get_nrpesti()+1);} }
            else {data->set_rapitor(false);}
        P.lista_pesti.push_back(data);

    }
return in;};
//operator afisare pt specializarea pesti;
template <>
std::ostream& operator<< (ostream &out, Atlas2<Peste *> &P){
  out <<"Numarul de pagini este:"<< P.get_lungimeAtlas() <<'\n';
  out <<"Animalele aflate in atlas sunt :\n";
  for (Peste * x : P.lista_pesti){
                    out << x->get_name();
                    std::cout <<" - ";
                    out << x->regn();
                    std::cout<<",\t";}
    out << "Iar numarul de pesti rapitori cu lungimea mai mare de 1m este: \n";
    out << P.get_nrpesti() << "\n";
    return out;
  }

int main()
{

/*Atlas2<Animal *> Atlas3;
cin >> Atlas3;
for (Animal *x : Atlas3.pagini) {cout << x->get_name() << " " << x->regn();}
cout << Atlas3;
cin >> Atlas3;
for (Animal *x : Atlas3.pagini) {cout << x->get_name() << " " << x->regn();}*/
Atlas2<Peste *> Atlas4;
cin >> Atlas4;
cout << Atlas4.get_nrpesti();
Peste *p = new Peste{"Giani", 2 };
p->set_lungime(2);
p->set_rapitor(true);
Atlas4 += p;
cout << Atlas4;
  return 0;

}
