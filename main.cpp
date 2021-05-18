#include <iostream>
#include <assert.h>
#include <list>
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
    virtual std::string regn() const { return "vertebrate";}
    virtual ~Vertebrate(){
    cout<<"Destructor vertebrate"<<'\n';};
};


class Pasare: public Vertebrate {
public:

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
    int lungime;
public:
    Peste(): Vertebrate(){}
    Peste(std::string name, int l) : Vertebrate { name } { lungime = l;}
    void set_name (std::string nume){
    m_name = nume;}

    std::string get_name(){
    return m_name;}

    std::string regn()  const override {return "peste";}
     ~Peste (){
    cout << "destructor peste"<<'\n';}
};
class PesteRapitor: public Peste {
public:
    PesteRapitor (): Peste(){}
    PesteRapitor (std::string name, int l) : Peste{name, l} {};
    void set_name (std::string nume){
    m_name = nume;}

    std::string get_name(){
    return m_name;}

    std::string regn()  const override {return "pesteRapitor";}
    ~PesteRapitor() {  cout << "Destructor pesteRapitor"<<'\n';}
};

/*template <class T>
class Atlas
{
private:

    int m_length{};
    T* m_data{};


public:
  //  std::list<T> lista;
  //  void Adauga(T data, int j);
    void SetLungime(int j);
    Atlas(int length)
    {
        assert(length > 0);
        m_data = new T[length]{};
        m_length = length;

    }

    Atlas(const Atlas&) ;//= delete;
    Atlas& operator=(const Atlas&);// = delete;

    ~Atlas()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    int getLength() const;
};
template <class T>
int Atlas<T>::getLength() const
{
  return m_length;
}
template <class T>
void Atlas<T>::SetLungime(int j){m_length = j;
m_data = new T[j];
}
/*template <class T>
void Atlas<T>::Adauga(T data, int j){
lista.push_back(data);
m_length = j;
m_data = new T[j];}

template <class T> class Nod
{
     //pointer to the next node element

public:
    T data; //the object information
    Nod* next;
    Nod () {
    next = NULL;}
    Nod (T info){
    data = info;
    next = NULL;}
    Nod(const Nod &nod){
    data = nod.data;
    next = nod.next;}
    ~Nod () {}
    Nod operator= (Nod nod){
    data = nod.data;
    delete next;
    next = nod.next;
    return *this;}
    T get_data(){return data;}
    Nod *get_next(){return next;}

*/

/*template<class T>
class LinkedList
{
public:
	Nod<T>* first;
	Nod<T>* last;
	LinkedList<T>() {
		first = NULL;
		last = NULL;
	}

	void add(T data) {
		if(!first) {
			// The list is empty
			first = new Nod<T>;
			first->data = data;
			first->next = NULL;
			last = first;
		} else {
			// The list isn't empty
			if(last == first) {
				// The list has one element
				last = new Nod<T>;
				last->data = data;
				last->next = NULL;
				first->next = last;
			} else {
				// The list has more than one element
				Nod<T>* insdata = new Nod<T>;
				insdata->data = data;
				insdata->next = NULL;
				last->next = insdata;
				last = insdata;
			}
		}
	}

	T get(int index) {
		if(index == 0) {
			// Get the first element
			return this->first->data;
		} else {
			// Get the index'th element
			Nod<T>* curr = this->first;
			for(int i = 0; i < index; ++i) {
				curr = curr->next;
			}
			return curr->data;
		}
	}

	T operator[](int index) {
		return get(index);
	}

};*/

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
   Atlas2 operator += (const T& data){
   this->m_length++;
   this->pagini.push_back(data);
   return *this;}
   };
 /*   friend istream& operator>> (istream &in,const Atlas2<T> &rhs){
    int n;
    in >> n;
    m_length = n;
    for(int i=1; i<=m_length; i++)
    in >> rhs;};
};*/
/*template <class T>
istream& operator >> (istream &in,const Atlas2<T>& rhs){
in >> m_length;
for(int i=1; i<=m_length; i++)
    in >> rhs;
    Atlas2.pagini.push_back(rhs);
return in;
}*/


template <class T>
void Atlas2<T>::adauga(T data){m_length = m_length+1;
pagini.push_back(data);}
template <>
void Atlas2<PesteRapitor*>::adauga(PesteRapitor * data) {
nr_pesti = nr_pesti + 1;
m_length = m_length+1;
pagini.push_back(data);}
int main()
{



Pasare *p = new Pasare{"EAGLE"};
Peste *b = new Peste{"Biban", 1};
PesteRapitor *s = new PesteRapitor{"Stiuca", 1};
Atlas2<Animal *> ATLASU2;
ATLASU2.adauga(p);
ATLASU2.adauga(b);
ATLASU2.adauga(s);
Pasare *c = new Pasare{"vulture"};
cout << ATLASU2.m_length;
for (Animal *x : ATLASU2.pagini) {cout << x->get_name() << " " << x->regn();}
ATLASU2 += c;
for (Animal *x : ATLASU2.pagini) {cout << x->get_name() << " " << x->regn();}
cout << ATLASU2.m_length<<" ";
cout << ATLASU2.nr_pesti;
    return 0;
}
