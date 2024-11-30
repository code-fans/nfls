#include <iostream>
using namespace std;
class base
{
public:
    base()
    {
        cout << "base constructor" << endl;
    }

    ~base()
    {
        cout << "base destructor" << endl;
    }
};

class derived : public base
{
public:
    derived()
    {
        cout << "derived constructor" << endl;
    }

    ~derived()
    {
        cout << "derived destructor" << endl;
    }
};

int main(){
    derived * d;
    d = new derived();

    delete d;
    return 0; 
}