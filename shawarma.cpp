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
    int suboption=-1;
    while(suboption!=0)
    {
        cout<<"==Choose ingredient==\n";
        cout<<"1. meat\n";
        cout<<"2. sauce\n";
        cout<<"3. tomaotes\n";
        cout<<"4. french fries\n";
        cout<<"0. exit\n";
        cin>>suboption;
    }
    /*switch (suboption)
    {
    case 1:
        cout<<"choose one from the following: ";
        cout<<"1. chicken";
        cout<<"2. beef";
        cout<<"3. lamb";
        break;
    
    default:
        break;
    }*/
}

int main()
{
    int option;
    ingredients ingredients;
    cout<<"== hello!! choose from the following ==\n";
    cout<<"1. add ingredient\n";
    cout<<"0. exit\n";

    cin>>option;
    switch(option)
    {
        case 1:
            ingredients.open_menu();
    }
}
