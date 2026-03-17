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
        void operator+=(const char*);
        ingredients();
        explicit ingredients(float);
        ingredients(const ingredients& obj);
        ingredients& operator=(const ingredients& obj);

        //ingredients(float, float);
        ~ingredients();

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

        std::ostream& afisare(std::ostream& out) const;
};
std::ostream& operator<<(std::ostream& out, const ingredients& i) {
    i.afisare(out);
    return out;
}
std::ostream& ingredients::afisare(std::ostream& out) const
{
    out<< "Ingredients in the list: "<<ingr_number<<"total cost: "<<cost;
    return out;
}
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

    return *this;
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
ingredients::ingredients(float b) : initial_budg(b)
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


class client
{
    private:
        char* name;
        int age;
        //double bonus;
        static int no_clients;
        ingredients chart;

    public:
        explicit client( const char* name="Not known", int v=0);

        client(const client& obj);
        ~client();
        client& operator=(const client& obj);

        const char* getname() const 
        {
            return name;
        }
        int getage() const
        {
            return age;
        }
        void setage(int v)
        {
            age=v;
        }
        void setname(const char* n)
        {
            if(this->name)
                {
                    delete[] name;
                }
            this->name=new char[strlen(n)+1];
            strcpy(this->name, n);
        }
        ingredients& getchart()
        {
            return chart;
        }

        std::ostream& afisare_client(std::ostream& out) const;
        //std::istream& citire_client(std::istream& in, client& obj);
};

class shop
{
    private:
        char* address;
        long turnover;
        int staff_no;
        bool open;

    public:
        shop():turnover(5000), staff_no(5), open(true)
        {
            address = new char[strlen("Main street no,1 ") +1];
            strcpy(address, "Main street no,1 ");
        } 
        explicit shop(const char* address, long turn, int staff, bool open):turnover(turn), staff_no(staff), open(open)
        {
            this->address=new char[strlen(address) +1];
            strcpy(this->address, address);
        }
        ~shop()
        {
            delete[] address;

        }
        shop(const shop& obj)
        {
            this->address=new char[strlen(obj.address)+1];
            strcpy(this->address, obj.address);

            this->turnover=obj.turnover;
            this->staff_no=obj.staff_no;
            this->open=obj.open;


        }

        shop& operator=(const shop& obj)
        {
            if(this == &obj)
                return *this;
            else 
            {
                delete[] address;
                this->address=new char[strlen(obj.address)+1];
            strcpy(this->address, obj.address);

            this->turnover=obj.turnover;
            this->staff_no=obj.staff_no;
            this->open=obj.open;
            }

        }
        std::ostream& shop_afis(std::ostream& out) const {
        out << "Shop Address: " << address << "\n Turnover: " << turnover << " \n Open: " << (open ? "Is open" : "Nope");
        return out;}

        

};
std::ostream& operator<<(std::ostream& out, const shop& s)
{
    return s.shop_afis(out);
}



int client::no_clients=0;
std::ostream& client::afisare_client(std::ostream& out) const{
    out<<"client name: "<<name<<"----age: "<<age;
    return out;
}
std::ostream& operator<<(std::ostream& out, const client& obj)
{
    return obj.afisare_client(out);
}
std::istream& operator>>(std::istream& in, client& obj)
{
    char buff[256]; int v;
    in.get();
    std::cout<<"your name:";
    in.getline(buff, 256);
    std::cout<<"your age:";
    in >>v;
    in.ignore(256, '\n');
    obj.setage(v);
    obj.setname(buff);
    return in;
}
client& client::operator=(const client & obj)
{
    if (this!= &obj)
    {
        delete[] name;
        this->name=new char[strlen(obj.name)+1];
        this->age=obj.age;
        strcpy(this->name, name);

    }
    return *this;
}
client::~client()
{
    delete[] name;
}
client::client(const client& obj)
{
    this->name= new char[strlen(obj.name) +1];
    this->age=obj.age;
    strcpy(this->name, name);

}
client::client(const char* name, int v): age(v)
{
    this->name= new char[strlen(name)+1];
    strcpy(this->name, name);
    no_clients++;
}

class receipt
{
    private:
    char* receipt_no;
    float paid_amount;
    
    static int total_receipts;

    public:
    receipt(const char* id, float amount):paid_amount(amount)
    {
        receipt_no = new char[strlen(id)+1];
        strcpy(this->receipt_no, id);
        total_receipts++;
    }
    ~receipt()
    {
        delete[] receipt_no;
    }
    
};

int main()
{
    int option;
    float budget;
    std::cout<<"set you initial budgt: ";
    std::cin>>budget;
    //ingredients my_ingredients(budget);

    shop stores[3] = {
        shop("street nr. 5", 120000, 4, true),
        shop("street no. 4", 300000, 10, true),
        shop("street no. 3", 80000, 2, false)
    };
    shop * actual_shop=nullptr;

    client utilizator;
    do
    {
        std::cout<<"\n KEBAB SIMULATOR \n";
        if(actual_shop != nullptr) 
        {
            std::cout<<"Location: "<< *actual_shop<<"\n";

        }
        else{
            std::cout<<"Choose first a location\n";
        }
    std::cout<<"\n== choose from the following ==\n";
    std::cout<<"1. add ingredient\n";
    std::cout<<"2. show ingredients\n";
    std::cout<<"3. introduce yourself\n";
    std::cout<<"4. select/switch shop\n";
    std::cout<<"0. exit\n";

    std::cin>>option;
    switch(option)
    {
        case 1:
            utilizator.getchart().open_menu();
            break;
        case 2:
            utilizator.getchart().show_ingr();
            break;
        case 3:
            //std::cout<<"introduce yourself: ";
            std::cin>>utilizator;
            break;
        case 4:
            int shop_choice;
            std::cout<<"\n available shops: \n";
            for (int i=0;i<=2; i++)
            {
                std::cout<<i+1<<" "; std::cout<<stores[i]<<std::endl;
            }
            std::cin>>shop_choice;
            if(shop_choice>=1 && shop_choice<=3)
            {
                actual_shop=&stores[shop_choice-1];
                std::cout<<"Welcome!!";

            }
            else std::cout<<"Invalid number!!";
            break;
    }
    }while(option!=0);
}