#include <iostream>
#include <cstring>
class Ingredients
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
        Ingredients();
        explicit Ingredients(float);
        Ingredients(const Ingredients& obj);
        Ingredients& operator=(const Ingredients& obj);

        //ingredients(float, float);
        ~Ingredients();

        double gettotal() const {
            return cost;
        }
        float getbudget() const 
        {
            return budget;
        }
        void setbudget(float b)
        {
            budget=b; std::cout<<"m ia setat bugetul"<<budget;
        }

        std::ostream& afisare(std::ostream& out) const;
};
std::ostream& operator<<(std::ostream& out, const Ingredients& i) {
    i.afisare(out);
    return out;
}
std::ostream& Ingredients::afisare(std::ostream& out) const
{
    out<< "Ingredients in the list: "<<ingr_number<<"total cost: "<<cost;
    return out;
}
Ingredients& Ingredients::operator=(const Ingredients& obj)
{
    if (this== &obj)
        return *this;
    
    for (int i=0; i<ingr_number;i++)
        if (chosen_ingr[i] != nullptr) {
            delete[] chosen_ingr[i];
            chosen_ingr[i] = nullptr;
        }

    this->cost=obj.cost;
    this->budget=obj.budget;
    this->ingr_number=obj.ingr_number;
    for(int i=0;i<obj.ingr_number;i++)
        {
            chosen_ingr[i]=new char[strlen(obj.chosen_ingr[i])+1];
    strcpy(chosen_ingr[i], obj.chosen_ingr[i]);
    this->price[i] =obj.price[i];
        }

    return *this;
}
Ingredients::Ingredients(const Ingredients& obj):initial_budg(obj.initial_budg)
{
    this->cost=obj.cost;
    this->budget=obj.budget;
    this->ingr_number=obj.ingr_number;
    for(int i=0;i<ingr_number;i++)
        {chosen_ingr[i]=new char[strlen(obj.chosen_ingr[i])+1];
        strcpy(chosen_ingr[i], obj.chosen_ingr[i]);
        price[i] =obj.price[i];}

}
void Ingredients::operator+=(const char* ingr)
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
// Ingredients::Ingredients(float budget, float price)
// {   
//     budget-=price;
// }
Ingredients::~Ingredients()
{
    for (int i=0; i<ingr_number; i++)
        delete[] chosen_ingr[i];
}
Ingredients::Ingredients() : cost(0), initial_budg(0)
{
    ingr_number=0;
    for (int i=0;i<20;++i)
        chosen_ingr[i]=nullptr;
}
Ingredients::Ingredients(float b) : initial_budg(b)
{
    cost=0;
    ingr_number=0;
    for(int i = 0; i < 20; ++i)
        chosen_ingr[i] = nullptr;
    budget=b;
}
void Ingredients::add_ingr_in_list(const char *name, float price)
{
    if(ingr_number>20)
        std::cout<<"too many Ingredients";
    else 
        if (cost+price > budget)
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
void Ingredients::show_ingr()
{
    if(ingr_number==0) 
        std::cout<<"you did not chose any ingredient \n";
    else 
    {
        std::cout<<"\n---your Ingredients:\n";
        for(int i=0;i<ingr_number;i++)
            std::cout<<"---"<<chosen_ingr[i]<<"----"<<price[i]<<"ron"<<"\n";
        
        // std::cout<<"\n-----------------\n";
        // std::cout<<"--- Total items: "<<ingr_number<<"---\n";
        // std::cout<<"--- Grand total: ---"<<cost<<"ron---\n";
        // std::cout<<"--- Remaining budget: ---"<<budget<<"ron---\n";
        
    }
}
void Ingredients::open_menu()
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

class Client
{
    private:
        char* name;
        int age;
        //double bonus;
        static int no_Clients;
        Ingredients chart;

    public:
        explicit Client( const char*, int , float);

        Client(const Client& obj);
        ~Client();
        Client& operator=(const Client& obj);

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
        Ingredients& getchart()
        {
            return chart;
        }

        std::ostream& afisare_Client(std::ostream& out) const;
        //std::istream& citire_Client(std::istream& in, Client& obj);
};

class Shop
{
    private:
        char* address;
        long turnover;
        int staff_no;
        bool open;

    public:
        Shop():turnover(5000), staff_no(5), open(true)
        {
            address = new char[strlen("Main street no,1 ") +1];
            strcpy(address, "Main street no,1 ");
        } 
        explicit Shop(const char* address, long turn, int staff, bool open):turnover(turn), staff_no(staff), open(open)
        {
            this->address=new char[strlen(address) +1];
            strcpy(this->address, address);
        }
        ~Shop()
        {
            delete[] address;

        }
        Shop(const Shop& obj)
        {
            this->address=new char[strlen(obj.address)+1];
            strcpy(this->address, obj.address);

            this->turnover=obj.turnover;
            this->staff_no=obj.staff_no;
            this->open=obj.open;


        }

        Shop& operator=(const Shop& obj)
        {
            if(this == &obj)
                return *this;
            
                delete[] address;
                this->address=new char[strlen(obj.address)+1];
            strcpy(this->address, obj.address);

            this->turnover=obj.turnover;
            this->staff_no=obj.staff_no;
            this->open=obj.open;
            return *this;
            
        }
        std::ostream& Shop_afis(std::ostream& out) const {
        out << "Shop Address: " << address << "\n Turnover: " << turnover << " \n Open: " << (open ? "Is open" : "Nope");
        return out;}

        

};
std::ostream& operator<<(std::ostream& out, const Shop& s)
{
    return s.Shop_afis(out);
}

int Client::no_Clients=0;
std::ostream& Client::afisare_Client(std::ostream& out) const{
    out<<"Client name: "<<name<<"----age: "<<age;
    return out;
}
std::ostream& operator<<(std::ostream& out, const Client& obj)
{
    return obj.afisare_Client(out);
}
std::istream& operator>>(std::istream& in, Client& obj)
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
Client& Client::operator=(const Client & obj)
{
    if (this!= &obj)
    {
        delete[] name;
        this->name=new char[strlen(obj.name)+1];
        this->age=obj.age;
        strcpy(this->name, obj.name);

    }
    return *this;
}
Client::~Client()
{
    delete[] name;
}
Client::Client(const Client& obj)
{
    this->age=obj.age;
    (*this).chart=obj.chart;

    if(obj.name != nullptr){
    this->name= new char[strlen(obj.name) +1];
    strcpy(this->name, obj.name);
    }
    else (*this).name= nullptr;

}
Client::Client(const char* name, int v, float b): age(v), chart(b), name(nullptr)
{
    this->name= new char[strlen(name)+1];
    strcpy(this->name, name);
    no_Clients++;
}

class Receipt
{
    private:
    char* Receipt_no;
    float paid_amount;
    
    static int total_Receipts;

    public:
    Receipt(const char* id, float amount):paid_amount(amount)
    {
        Receipt_no = new char[strlen(id)+1];
        strcpy(this->Receipt_no, id);
        total_Receipts++;
    }
    ~Receipt()
    {
        delete[] Receipt_no;
    }
    Receipt(const Receipt& obj)
    {
        this->Receipt_no=new char[strlen(obj.Receipt_no)+1];
        strcpy(this->Receipt_no, obj.Receipt_no);
        this->paid_amount = obj.paid_amount;
    }
    Receipt& operator=(const Receipt& obj)
    {
        if (this != &obj) {

            delete[] Receipt_no;
            Receipt_no = new char[strlen(obj.Receipt_no) + 1];
            strcpy(Receipt_no, obj.Receipt_no);

            paid_amount = obj.paid_amount;
        }
        return *this;
    }
    void print_Receipt(const Client& c, const Shop& s) const {
        std::cout << "         Receipt                    \n";
        std::cout << "ID: " << Receipt_no << "\n";
        std::cout << "Shop: " << s << "\n"; 
        std::cout << "Customer: " << c.getname() << "\n";
        std::cout << "----------------------------------\n";
        std::cout << "TOTAL PAID: " << paid_amount << " RON\n";
        std::cout << "==================================\n";
    }
};
int Receipt::total_Receipts=0;

class Kebabapp {
private:
    float initial_budget;
    Shop stores[3];
    Shop* actual_Shop;
    Client utilizator;

public:
    Kebabapp() : initial_budget(0), actual_Shop(nullptr),  utilizator("Not known", 0, 0) 
    {
        stores[0] = Shop("street nr. 5", 120000, 4, true);
        stores[1] = Shop("street no. 4", 300000, 10, true);
        stores[2] = Shop("street no. 3", 80000, 2, false);}

    void start() {
        std::cout << "Set your initial budget: ";
        std::cin >> initial_budget;
        utilizator.getchart().setbudget(initial_budget);
        
        run_main_loop();
    }

private:
    void run_main_loop() {
        int option;
        display_status();
        do {
            
            display_options();
            std::cin >> option;
            handle_option(option);
        } while (option != 0);
    }

    void display_status() {
        std::cout << "\n KEBAB SIMULATOR \n";
        if (actual_Shop != nullptr) {
            std::cout << "Location: " << *actual_Shop << "\n";
        } else {
            std::cout << "Choose first a location\n";
        }
    }

    void display_options() {
        std::cout << "\n== choose from the following ==\n";
        std::cout << "1. add ingredient\n";
        std::cout << "2. show ingredients\n";
        std::cout << "3. introduce yourself\n";
        std::cout << "4. select/switch Shop\n";
        std::cout << "5. buy\n";
        std::cout << "0. exit\n";
        std::cout << "Option: ";
    }

    void handle_option(int option) {
        switch (option) {
            case 1:
                utilizator.getchart().open_menu();
                break;
            case 2:
                utilizator.getchart().show_ingr();
                break;
            case 3:
                std::cin >> utilizator;
                break;
            case 4:
                choose_Shop();
                break;
            case 5:
                process_purchase();
                break;
        }
    }

    void choose_Shop() {
        int Shop_choice;
        std::cout << "\n Available Shops: \n";
        for (int i=0; i< 3; i++) {
            std::cout <<i+1 <<" " << stores[i] << std::endl;
        }
        std::cin >> Shop_choice;
        if (Shop_choice >= 1 && Shop_choice <= 3) {
            actual_Shop =&stores[Shop_choice- 1];
            std::cout <<"Welcome!!";
        } else {std::cout <<"Invalid number!!";}
    }

    void process_purchase() {
        if (actual_Shop == nullptr) {
            std::cout << "!!! Error: please select a Shop first !!!\n";
        } else if (utilizator.getchart().gettotal() == 0) {
            std::cout << "!!! your cart is empty !!!\n";
        } else {
            Receipt r(utilizator.getname(), (float)utilizator.getchart().gettotal());
            r.print_Receipt(utilizator, *actual_Shop);
        }
    }
};

int main() {
    Kebabapp simulator;
    simulator.start();
    return 0;
}