#include <iostream>
using namespace std;

class ingredients
{
    private:

    public:
        void open_menu();
};
void ingredients::open_menu()
{
    cout<<"==Choose ingredient==";
    cout<<"1. meat";
    cout<<"2. sauce";
    cout<<"3. tomaotes";
    cout<<"4. french fries";
}

int main()
{
    int option;
    cout<<"== hello!! choose from the following ==";
    cout<<"1. add ingredient ";
    cout<<"0. Iesire";

    cin>>option;
    switch(option)
    {
        case 1:
            ingredients.open_menu();
    }
}
