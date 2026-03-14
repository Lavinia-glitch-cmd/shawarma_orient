#include <iostream>
#include <cstring>


class ingredients
{
    private:
        char* chosen_ingr[20]; 
        int ingr_number;
        double price[20], cost;

    public:
        void open_menu();
        void add_ingr_in_list(const char*);
        void show_ingr();

        ingredients();
        ingredients(double);
        ~ingredients();
};
ingredients::ingredients(double budget)
{
    cost=budget;
    ingr_number=0;
    for(int i=0; i< 20;i++)
        chosen_ingr[i]=nullptr;
}
ingredients::~ingredients()
{
    for (int i=0; i<ingr_number; i++)
        delete[] chosen_ingr[i];
}
ingredients::ingredients()
{
    ingr_number=0;
    for (int i=0;i<20;++i)
        chosen_ingr[i]=nullptr;
}
void ingredients::add_ingr_in_list(const char *name)
{
    if(ingr_number>20)
        std::cout<<"too many ingredients";
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
    if(ingr_number==0) 
        std::cout<<"you did not chose any ingredient\n";
    else 
    {
        std::cout<<"\n---your ingredients:\n";
        for(int i=0;i<ingr_number;i++)
            std::cout<<"---"<<chosen_ingr[i]<<"\n";
    }
}
void ingredients::open_menu()
{
    int suboption=-1;
    while(suboption!=0)
    {
        std::cout<<"\n==Choose ingredient==\n";
        std::cout<<"1. meat\n";
        std::cout<<"2. sauce\n";
        std::cout<<"3. tomaotes\n";
        std::cout<<"4. french fries\n";
        std::cout<<"0. exit\n";
        std::cin>>suboption;
        
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
    std::cout<<"\n== choose from the following ==\n";
    std::cout<<"1. add ingredient\n";
    std::cout<<"2. show ingredients\n";
    std::cout<<"0. exit\n";

    std::cin>>option;
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
