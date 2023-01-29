#ifndef CLASS_FUNCTION_H_INCLUDED
#define CLASS_FUNCTION_H_INCLUDED
#include <iostream>
#include <fstream>
#include "class.h"
using namespace std;
Root::Root()
{
}

ofstream& operator << (ofstream& ofstr, Root root)
{
ofstr<<root.Username;
return ofstr;
}

int Root::check_option()
{
    int option;
    int br=0;
    do
    {
        cin>>option;
        if((option>=0)&&(option<=4))
            return option;
        else
        {
            cout<<"Wrong option! this option not exist! Please insert againg"<<endl;
            br++;
        }
        if(option==4)
            return 0;
        if(br==3)
        {
            return 0;
        }
    }
    while(option);
}

void Root::set_Username(string username)
{
    Username=username;
}

void Root::set_Password(string password)
{
    Password=password;
}

void Root::set_Right(int reigth)
{
    Reight=reigth;
}

string Root::get_Username()
{
    return Username;
}

string Root::get_Password()
{
    return Password;
}

int Root::get_Reight()
{
    return Reight;
}

int Root::numder_file_row(std::string file_name)
{
    ifstream file(file_name);
    string line;
    int br=0;
    if(file.is_open())
    {
        while(getline(file,line))
        {
            br++;
        }
        file.close();
    }
    else
        cout<<"File not exsitS"<<endl;
    return br;
}

int Root::read_file(string file_name)
{
    file_name=file_name;
    ifstream file(file_name);
    string line;
    int br=0;
    if(file.is_open())
    {
        while(getline(file,line))
        {
            cout<<line<<endl;
        }
        file.close();
    }
    else
        cout<<"File not exsitS"<<endl;
}


void Root::get_username(Users users[], int br)
{
    string file_name="access.txt";
    string name;
    br=numder_file_row(file_name);
    string password, username;
    fstream file(file_name);
    if(file.is_open())
    {
        for(int i=0; i<br/3; i++)
        {
            file>>users[i].username;
            file>>users[i].password;
            file>>users[i].reight;
        }
        file.close();
    }
}




int Root::check_access(Users users[], int br, string username, string password)
{
    int i=0;
    do
    {
        if(i==br)
        {
            system("clear");
            cout<<"*********************************\n";
            cout<<"Password or username are not correct!"<<"\n"<<"Please try again"<<endl;
            cout<<"*********************************\n";

            i=0;
            cout<<"Inser your username"<<endl;
            cin>>username;
            cout<<"Inser your password"<<endl;
            cin>>password;
        }
        if(username==users[i].username&& password==users[i].password)
        {
            system("clear");
            return i;
            break;
        }
        i++;
    }
    while(1);
}


int Root::get_number_product()
{
    int br=numder_file_row("access.txt");
    Users user[br/3];
    get_username(user, br);
    int br_product=0;
    for(int i=0; i<br/3; i++)
    {
        if(user[i].reight==2)
        {
            string file_name=user[i].username+"_product.txt";
            ifstream file(file_name);
            if(file.is_open())
            {
                int br_line=numder_file_row(file_name);
                for(int j=0; j<br_line/6; j++)
                {
                    br_product++;
                }
                file.close();
            }
        }

    }
    return br_product;
}


int Root::check_reight()
{
    string file_name="access.txt";
    int br=0;
    br=numder_file_row(file_name);
    Users users[br];
    get_username(users, br);
    string username, password;
    system("clear");
    cout<<"Optical Shop"<<endl;
    cout<<"**********************************"<<endl;
    cout<<"Inser your username"<<endl;
    cin>>username;
    cout<<"Inser your password"<<endl;
    cin>>password;
    int show_right=check_access(users, br, username, password);
    set_Username(users[show_right].username);
    set_Password(users[show_right].password);
    set_Right(users[show_right].reight);

    return get_Reight();
}

Client::Client()
{

}

void Client::show_supllier(string name)
{
    //int br=get_number_product();
    string file_name;
    Supllier supllier;
    file_name=name+".txt";
    ifstream file(file_name);
    if(file.is_open())
    {
        file>>supllier.id;
        cout<<"Id of suplier: "<<supllier.id<<endl;
        file>>supllier.username;
        cout<<"Name of supllier: "<<supllier.username<<endl;
        file>>supllier.bulstat;
        cout<<"Bulstat :"<<supllier.bulstat<<endl;
        file>>supllier.location;
        cout<<"Location: "<<supllier.location<<endl;
        file>>supllier.tel_number;
        cout<<"Telephone of supllier: "<<supllier.tel_number<<endl;
        file.close();
    }
}



void Client::show_all_product(Product product[])
{
    int br=numder_file_row("access.txt");
    Users user[br/3];
    get_username(user, br);
    int br_product=get_number_product();
    br_product=0;
    for(int i=0; i<br/3; i++)
    {

        if(user[i].reight==2)
        {
            show_supllier(user[i].username);
            int id=random()%100;
            string file_name;
            file_name=user[i].username+"_product.txt";
            ifstream file(file_name);
            cout<<endl;
            cout<<endl;
            if(file.is_open())
            {
                int br_line=numder_file_row(file_name);
                for(int j=0; j<br_line/6; j++)
                {
                    file>>product[br_product].id;
                    cout<<"Id product:  "<<product[br_product].id<<endl;
                    file>>product[br_product].name_product;
                    cout<<"Name of product:  "<<product[br_product].name_product<<endl;
                    file>>product[br_product].type;
                    cout<<"Type of product:  "<<product[br_product].type<<endl;
                    file>>product[br_product].name_maretrials;
                    cout<<"Material of product:  "<<product[br_product].name_maretrials<<endl;
                    file>>product[br_product].diopter;
                    cout<<"Diopter: "<<product[br_product].diopter<<endl;
                    file>>product[br_product].thickness;
                    cout<<"Thinckness of product: "<<product[br_product].thickness<<endl;
                    file>>product[br_product].price;
                    cout<<"Price:  "<<product[br_product].price<<endl;
                    cout<<"\n\n";
                    br_product++;
                }
                file.close();
            }
        }
    }
}

void Client::inser_stoller(string name,Product product, int count_product)
{
    fstream file(name, ios::app);
    if(file.is_open())
    {
        file<<"Id of product"<<product.id<<endl;
        file<<"Name of product: "<<product.name_product<<endl;
        file<<"Type of product: "<<product.type<<endl;
        file<<"Materials of product: "<<product.name_maretrials<<endl;
        file<<"Diopter of product: "<<product.diopter<<endl;
        file<<"Thickness of product: "<<product.thickness<<endl;
        file<<"Price of product: "<<product.price<<endl;
        file<<endl;
        file<<"Count of product: "<<count_product<<endl;
        file<<endl;
        file.close();
    }
}

void Client::cheak_true_supllier(Product product[])
{
    string name_supllier;
    int id_suplier, flag=1;
    cout<<"Insert Name of supllier!"<<endl;
    cin>>name_supllier;
    cout<<"Insert id of suplier!"<<endl;
    cin>>id_suplier;
    while(flag)
    {
        string file_suplier=name_supllier+".txt";
        fstream file(file_suplier);
        string username;
        int id;
        if(file.is_open())
        {
        file>>id;
        file>>username;
        file.close();
        }
        if((id==id_suplier)&&(username==name_supllier))
        {
        system("clear");
        flag=0;
        show_supllier(username);
        cout<<"***********************************"<<endl;
        cout<<"Product of suplier"<<endl;
        show_suplier_product(product, username);
        break;
        }
        else
        {
        cout<<"Worng username or id of suplier!"<<endl;
        cout<<"Please insert again!"<<endl;
        cout<<"Insert Name of supllier!"<<endl;
        cin>>name_supllier;
        cout<<"Insert id of suplier!"<<endl;
        cin>>id_suplier;
        flag==1;
        }
    }
}

void Client::show_suplier_product(Product product[], string supllier_name)
{
string filename=supllier_name+"_product.txt";
fstream file(filename);
int br_product=get_number_product();
    br_product=0;
if(file.is_open())
    {
        int br_line=numder_file_row(filename);
                for(int j=0; j<br_line/6; j++)
                {
                    file>>product[br_product].id;
                    cout<<"Id product:  "<<product[br_product].id<<endl;
                    file>>product[br_product].name_product;
                    cout<<"Name of product:  "<<product[br_product].name_product<<endl;
                    file>>product[br_product].type;
                    cout<<"Type of product:  "<<product[br_product].type<<endl;
                    file>>product[br_product].name_maretrials;
                    cout<<"Material of product:  "<<product[br_product].name_maretrials<<endl;
                    file>>product[br_product].diopter;
                    cout<<"Diopter: "<<product[br_product].diopter<<endl;
                    file>>product[br_product].thickness;
                    cout<<"Thinckness of product: "<<product[br_product].thickness<<endl;
                    file>>product[br_product].price;
                    cout<<"Price:  "<<product[br_product].price<<endl;
                    cout<<"\n\n";
                    br_product++;
                }
                file.close();
    }
}

void Client::shop(string name)
{
    name=name+"_stoller.txt";
    int br=numder_file_row("access.txt");
    Users user[br/3];
    get_username(user, br);
    int br_product=get_number_product();
    Product product[br_product];
    show_all_product(product);
    float sum=0;
    int id_product;
    string confirm;
    cheak_true_supllier(product);
    cout<<"Inser id of product"<<endl;
    cin>>id_product;
    do
    {
    int wrong_id=0;
        for(int i=0; i<br_product; i++)
        {
            if(product[i].id==id_product)
            {
                float count_product;
                cout<<"Pleace insert count of product"<<endl;
                cin>>count_product;
                inser_stoller(name,product[i], count_product);
                float price=product[i].price;
                count_product=count_product*price;
                sum=sum+count_product;
                cout<<"If this is the end and you want to confirm yours order please insert yes/no"<<endl;
                cin>>confirm;
                int flag=1;
                while(flag)
                    if(confirm=="yes")
                    {
                        cout<<"This is our order"<<endl;
                        cout<<"************************************************"<<endl;
                        read_file(name);
                        cout<<"***********************************************"<<endl;
                        cout<<"This is the whole price"<<endl;
                        cout<<sum;
                        cout<<endl;
                        cout<<"Please confurm your order insert yes/no!"<<endl;
                        cin>>confirm;
                        if(confirm=="yes")
                        {
                            ofstream file(name, ios::app);
                            if(file.is_open())
                            {
                                int id=random()%1000;
                                file<<"The entire amount for the order is : "<<sum<<endl;
                                file<<"**************************************"<<endl;
                                file<<"Id of order is:  "<<id<<endl;
                                file<<"***************************************"<<endl;
                                file.close();
                            }
                            id_product=0;
                            flag=0;
                            break;
                        }
                    }
                    else
                        if(confirm=="no")
                        {
                            i=0;
                            system("clear");
                            show_all_product(product);
                            cheak_true_supllier(product);
                            cout<<"Inser id of product"<<endl;
                            cout<<"If you don't want to buy enithin please insert 0"<<endl;
                            cin>>id_product;
                            flag=0;
                        }
                        else
                        {
                        cout<<"Wrong value pleace insert only yes/no!"<<endl;
                        cin>>confirm;
                        }
            }
            else
            {
            wrong_id++;
            }
        }
        if(wrong_id==br_product)
        {
        cout<<"Wrong_id"<<endl;
        cout<<"Inser id of product"<<endl;
        cin>>id_product;
        }
    }
    while(id_product!=0);
}

void Client::buy_product()
{
    system("clear");
    string name=get_Username();
    shop(name);
}

void Client::show_Product()
{
    system("clear");
    int br_product=get_number_product();
    Product product[br_product];
    show_all_product(product);
}


supllier::supllier()
{
}


void supllier::set_bulsat(string bulstat)
{
    Bulstat=bulstat;
}

void supllier::set_location(string location)
{
    Location=location;
}

void supllier::set_Phone_number(int phone_number)
{
    Phone_number=phone_number;
}


string supllier::get_Bulstat()
{
    return Bulstat;
}

string supllier::get_Location()
{
    return Location;
}

int supllier::get_Phone_number()
{
    return Phone_number;
}

void supllier::create_product(string file_name)
{
    Product product;
    ofstream file(file_name,ios::app);
    if(file.is_open())
    {
        product.id=get_number_product();
        file<<product.id<<endl;
        cout<<"Insert name of product: "<<endl;
        cin>>product.name_product;
        file<<product.name_product<<endl;
        cout<<"Insert type of product"<<endl;
        cin>>product.type;
        file<<product.type<<endl;
        cout<<"Insert name of meterisal"<<endl;
        cin>>product.name_maretrials;
        file<<product.name_maretrials<<endl;
        cout<<"Insert diopter: "<<endl;
        cin>>product.diopter;
        file<<product.diopter<<endl;
        cout<<"Insert thickness"<<endl;
        cin>>product.thickness;
        file<<product.thickness<<endl;
        cout<<"Insert price"<<endl;
        cin>>product.price;
        file<<product.price<<endl;
        file<<endl;
        file.close();
    }
}

void supllier::inser_product()
{
    string name=get_Username();
    set_Username(name);
    string  file_name, username;
    username=get_Username();
    file_name=username+"_product.txt";
    Product product;
    create_product(file_name);
}

void supllier::see_own_product()
{
    string name=get_Username();
    set_Username(name);
    string  file_name, username;
    username=get_Username();
    file_name=username+"_product.txt";
    ifstream file(file_name);
    string line;
    int br=0;
    if(file.is_open())
    {
        while(getline(file,line))
        {
            cout<<line<<endl;
        }
        file.close();
    }
    else
        cout<<"File not exsitS"<<endl;
}

Admin::Admin()
{
}

void Admin::write_user_file(Users user)
{
    ofstream file("access.txt", ios::app);
    if(file.is_open())
    {
        file<<user.username<<endl;
        file<<user.password<<endl;
        file<<user.password<<endl;
        file.close();
    }
    else
        cout<<"file not exised"<<endl;
}

void Admin::create_suplier(string file_name, string username)
{
    string  bulstat, location;
    int tel_number, id;
    id=random()%100;
    ofstream file(file_name);
    if(file.is_open())
    {
        std::cout<<"Create supllaire:"<<std::endl;
        file<<id<<endl;
        file<<username<<endl;
        cout<<"Inser bulstat"<<endl;
        std::cin>>bulstat;
        file<<bulstat<<endl;
        cout<<"Insert location: "<<endl;
        cin>>location;
        file<<location<<endl;
        std::cout<<"Insert phone number"<<endl;
        std::cin>>tel_number;
        file<<tel_number<<endl;
        file.close();
    }
}


void Admin::insert_account()
{
    string file_name="access.txt";
    Users account;
    cout<<"Please insert new username"<<endl;
    cin>>account.username;
    int br=0;
    br=numder_file_row(file_name);
    Users users[br/3];
    get_username(users, br);
    int flag=1, check=0;
    while(flag)
    {
        check=1;
        for(int i=0; i<br/3; i++)
        {
            if(account.username==users[i].username)
            {
                cout<<users[i].username<<"  "<<check;
                check++;
            }
        }
        if(check==1)
        {
            flag=0;
            break;
        }
        else
        {
            cout<<"It have same username in programm!"<<endl;
            cout<<"Please insert new username"<<endl;
            cin>>account.username;
        }
    }
    cout<<"Please insert new password"<<endl;
    cin>>account.password;
    int right_user;
    cout<<"Plese insert the right of user, and input the corect number"<<endl;
    cout<<"1. admistrator"<<endl;
    cout<<"2. supplier"<<endl;
    cout<<"3. client"<<endl;
    cin>>right_user;
    switch(right_user)
    {
    case 1:
    {
        account.reight=3;
        write_user_file(account);
        break;
    }
    case 2:
    {
        account.reight=2;
        write_user_file(account);
        string file_name=account.username+".txt";
        create_suplier(file_name, account.username);
        break;
    }
    case 3:
    {
        account.reight=1;
        write_user_file(account);
        break;
    }
    }
}

void Admin::create_product(string file_name)
{
    Product product;
    ofstream file(file_name,ios::app);
    if(file.is_open())
    {
        product.id=get_number_product();
        file<<product.id<<endl;
        cout<<"Insert name of product: "<<endl;
        cin>>product.name_product;
        file<<product.name_product<<endl;
        cout<<"Insert type of product"<<endl;
        cin>>product.type;
        file<<product.type<<endl;
        cout<<"Insert name of meterisal"<<endl;
        cin>>product.name_maretrials;
        file<<product.name_maretrials<<endl;
        cout<<"Insert diopter: "<<endl;
        cin>>product.diopter;
        file<<product.diopter<<endl;
        cout<<"Insert thickness"<<endl;
        cin>>product.thickness;
        file<<product.thickness<<endl;
        cout<<"Insert price"<<endl;
        cin>>product.price;
        file<<product.price<<endl;
        file<<endl;
        file.close();
    }
}

void Admin::insert_product()
{
    cout<<"Insert name of suplier"<<endl;
    string name;
    cin>>name;
    string file_name="access.txt";
    int br=0;
    br=numder_file_row(file_name);
    Users users[br/3];
    get_username(users, br);
    for(int i=0; i<br/3; i++)
    {
        if(name==users[i].username&& users[i].reight==2)
        {
            name=name+"_product.txt";
            Product product;
            create_product(name);
            break;
        }
    }
}




#endif // CLASS_FUNCTION_H_INCLUDED
