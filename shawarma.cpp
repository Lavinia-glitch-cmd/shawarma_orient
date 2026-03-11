#include <iostream>
#include <cstring>
using namespace std;

class ingredients
{
    private:
        char* chosen_ingr[20]; //maximum 20 ingredients 
        int ingr_number;

    public:
        void open_menu();
        void add_ingr_in_list(const char*);
        void show_ingr();

        ingredients();
       // ~ingredients();
};
ingredients::ingredients()
{
    ingr_number=0;
    for (int i=0;i<20;++i)
        chosen_ingr[i]=nullptr;
}
void ingredients::add_ingr_in_list(const char *name)
{
    if(ingr_number>20)
        cout<<"too many ingredients";
    else
    {
        chosen_ingr[ingr_number]=new char[strlen(name)+1];
        strcpy(chosen_ingr[ingr_number], name);
        ingr_number++;
    }
}
void ingredients::show_ingr()
{
    //cout<<"numarul de ingrediente: "<<ingr_number<<"\n";
    if(ingr_number==0) cout<<"you did not chose any ingredient\n";
    else 
    {
        cout<<"\n---your ingredients:\n";
        for(int i=0;i<ingr_number;i++)
            cout<<"---"<<chosen_ingr[i]<<"\n";
    }
}
void ingredients::open_menu()
{
    int suboption=-1;
    while(suboption!=0)
    {
        cout<<"\n==Choose ingredient==\n";
        cout<<"1. meat\n";
        cout<<"2. sauce\n";
        cout<<"3. tomaotes\n";
        cout<<"4. french fries\n";
        cout<<"0. exit\n";
        cin>>suboption;
        
        switch(suboption)
        {
            case 1:
                add_ingr_in_list("meat");
                break;
            case 2:
                add_ingr_in_list("sauce");
                break;
            case 3:
                add_ingr_in_list("tomatoes");
                break;
            case 4:
                add_ingr_in_list("french fries");
                break;
        }
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
    ingredients my_ingredients;
    do
    {
    cout<<"\n== choose from the following ==\n";
    cout<<"1. add ingredient\n";
    cout<<"2. show ingredients\n";
    cout<<"0. exit\n";

    cin>>option;
    switch(option)
    {
        case 1:
            my_ingredients.open_menu();
            break;
        case 2:
            my_ingredients.show_ingr();
            break;
    }
    }while(option!=0);
}
