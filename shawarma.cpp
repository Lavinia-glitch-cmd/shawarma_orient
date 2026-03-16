#include <iostream>
#include <cstring>


class ingredients
{
    private:
        char* chosen_ingr[20]; 
        int ingr_number;
        float price[20], cost, budget;
        const float initial_budg;
        static int sold_ingr;

    public:
        void open_menu();
        void add_ingr_in_list(const char*, float);
        void show_ingr();

        ingredients();
        explicit ingredients(float);
        ingredients(const ingredients& obj);
        ingredients& operator=(const ingredients& obj);

        //ingredients(float, float);
        ~ingredients();

        void operator+=(const char*);

        double gettotal() const {
            return cost;
        }
        float getbudget() const 
        {
            return budget;
        }
        void setbudget(float b)
        {
            budget=b;
        }
};
ingredients& ingredients::operator=(const ingredients& obj)
{
    if (this== &obj)
        return *this;
    
        for (int i=0; i<ingr_number;i++)
            delete[] chosen_ingr[i];
        this->cost=obj.cost;
        this->budget=obj.budget;
        this->ingr_number=obj.ingr_number;
        for(int i=0;i<=ingr_number;i++)
        {chosen_ingr[i]=new char[strlen(obj.chosen_ingr[i])+1];
        strcpy(chosen_ingr[i], obj.chosen_ingr[i]);
        price[i] =obj.price[i];}

}
ingredients::ingredients(const ingredients& obj):initial_budg(obj.initial_budg)
{
    this->cost=obj.cost;
    this->budget=obj.budget;
    this->ingr_number=obj.ingr_number;
    for(int i=0;i<=ingr_number;i++)
        {chosen_ingr[i]=new char[strlen(obj.chosen_ingr[i])+1];
        strcpy(chosen_ingr[i], obj.chosen_ingr[i]);
        price[i] =obj.price[i];}

}
void ingredients::operator+=(const char* ingr)
{
    float p=0.0;
    std::string name(ingr);
    if (name == "meat") 
        p=9.99;
    else 
        if (name == "sauce") 
            p = 3.99;
        else 
            if (name == "tomatoes") 
                p = 4.99;
    
            else 
                if (name == "french fries") 
                    p = 5.99;
    add_ingr_in_list(ingr, p);

}

// ingredients::ingredients(float budget, float price)
// {   
//     budget-=price;
    

// }
ingredients::~ingredients()
{
    for (int i=0; i<ingr_number; i++)
        delete[] chosen_ingr[i];
}
ingredients::ingredients() : cost(0), initial_budg(0)
{
    ingr_number=0;
    for (int i=0;i<20;++i)
        chosen_ingr[i]=nullptr;
}
explicit ingredients::ingredients(float b) : initial_budg(b)
{
    cost=0;
    ingr_number=0;
    for(int i = 0; i < 20; ++i)
        chosen_ingr[i] = nullptr;
    budget=b;
}
void ingredients::add_ingr_in_list(const char *name, float price)
{
    if(ingr_number>20)
        std::cout<<"too many ingredients";
    else 
        if (cost+price > initial_budg)
            {
                std::cout<<"over budget!\n";
            std::cout<<"you have "<<budget<<" left";
            }
    else
    {
        chosen_ingr[ingr_number]=new char[strlen(name)+1];
        strcpy(chosen_ingr[ingr_number], name);
        this->price[ingr_number]=price;
        cost+=price;
        budget-=price;
        ingr_number++;

        
    }
}
void ingredients::show_ingr()
{
    if(ingr_number==0) 
        std::cout<<"you did not chose any ingredient \n";
    else 
    {
        std::cout<<"\n---your ingredients:\n";
        for(int i=0;i<ingr_number;i++)
            std::cout<<"---"<<chosen_ingr[i]<<"----"<<price[i]<<"ron"<<"\n";
        
        // std::cout<<"\n-----------------\n";
        // std::cout<<"--- Total items: "<<ingr_number<<"---\n";
        // std::cout<<"--- Grand total: ---"<<cost<<"ron---\n";
        // std::cout<<"--- Remaining budget: ---"<<budget<<"ron---\n";
        
    }
}
void ingredients::open_menu()
{
    int suboption=-1;
    while(suboption!=0)
    {
        std::cout<<"\n==Choose ingredient==\n";
        std::cout<<"1. meat ---------9.99 ron\n";
        std::cout<<"2. sauce---------3.99 ron\n";
        std::cout<<"3. tomaotes------4.99 ron\n";
        std::cout<<"4. french fries--5.99 ron\n";
        std::cout<<"0. exit\n";
        std::cin>>suboption;
        
        switch(suboption)
        {
            case 1:
                this->operator+=("meat");
                break;
            case 2:
                this->operator+=("sauce");
                break;
            case 3:
                this->operator+=("tomatoes");
                break;
            case 4:
                this->operator+=("french fries");
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
    float budget;
    std::cout<<"set you initial budgt: ";
    std::cin>>budget;
    ingredients my_ingredients(budget);
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
