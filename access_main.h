#ifndef ACCESS_MAIN_H_INCLUDED
#define ACCESS_MAIN_H_INCLUDED
#include "class_function.h"
using namespace std;

int admin_entrance()
{
    Admin admin;
    int reight=admin.check_reight();
    if(reight!=3)
        {
        cout<<"You are not client please try again"<<endl;
        system("./OpticalShop");
        }
    cout<<"Optical shop"<<endl;
    cout<<"*************************"<<endl;
    cout<<"Please insert one option"<<endl;
    cout<<"1. Insert Product"<<endl;
    cout<<"2. Create acount"<<endl;
int option;
cout<<"If you want to return at the begin of programm please insert 3!"<<endl;
cout<<"If you want to exit the program plese insert:  4"<<endl;
option=admin.check_option();
while(option)
{
    switch(option)
    {
        case 1:
        {
            admin.insert_product();
            break;
        }
        case 2:
        {
            admin.insert_account();
            break;
        }
        case 3:
        {
            system("./OpticalShop");
            break;
        }
        case 4:
        {
            return 0;
            break;
        }
    }
    if(option!=4)
    {
        cout<<"***********************************************************"<<endl;
        cout<<"1. Insert Product"<<endl;
        cout<<"2. Create acount"<<endl;
        cout<<"If you want to return at the begin of programm please insert 3!"<<endl;
        cout<<"If you want to exit the program plese insert:  4"<<endl;
        cout<<"***********************************************************"<<endl;
        option=admin.check_option();
    }

}
return 0;
}

int client_entance()
{
    Client client;
    int reight=client.check_reight();
    if(reight!=1)
        {
        cout<<"You are not client please try again"<<endl;
        system("./OpticalShop");
        }
    cout<<"***********************************************************"<<endl;
    cout<<"Wellcome to Opticshop"<<endl;
    cout<<"We have some opshion for you!"<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<"1. See all product"<<endl;
    cout<<"2. Buy product"<<endl;
    cout<<"If you want to return at the begin of programm please insert 3!"<<endl;
    cout<<"If you want to exit the program plese insert:  4"<<endl;
    cout<<"***********************************************************"<<endl;
    int option;
    option=client.check_option();
    while(option)
    {
        switch(option)
        {
        case 1:
            {
            client.show_Product();
            break;
            }
        case 2:
            {
            client.buy_product();
            break;
            }
        case 3:
            {
            system("./OpticalShop");
            break;
            }
        case 4:
            {
            return 0;
            break;
            }
        }
        if(option!=4)
        {
        cout<<"***********************************************************"<<endl;
        cout<<"1. See all product"<<endl;
        cout<<"2. Buy product"<<endl;
        cout<<"If you want to return at the begin of programm please insert 3!"<<endl;
        cout<<"If you want to exit the program plese insert:  4"<<endl;
        cout<<"***********************************************************"<<endl;
        option=client.check_option();
        }
    }
    return 0;
}

int suplier_entranse()
{
supllier suplier;
int reight=suplier.check_reight();
    if(reight!=2)
        {
        cout<<"You are not client please try again"<<endl;
        system("./OpticalShop");
        }
cout<<"Optical Shop"<<endl;
cout<<"**********************************"<<endl;
cout<<"This is the option which we sugest for supplier!"<<endl;
cout<<"Chose option and insert the numder of option!"<<endl;
cout<<"1. Insert Product"<<endl;
cout<<"2. See your product"<<endl;
int option;
cout<<"If you want to return at the begin of programm please insert 3!"<<endl;
cout<<"If you want to exit the program please insert 4!"<<endl;
option=suplier.check_option();
while(option)
{
    switch(option)
    {
        case 1:
            {
            suplier.inser_product();
            break;
            }
        case 2:
            {
            suplier.see_own_product();
            break;
            }
        case 3:
            {
            system("./OpticalShop");
            break;
            }
        case 4:
            {
            return 0;
            break;
            }

    }
    if(option!=4)
    {
        cout<<"***********************************************************"<<endl;
        cout<<"1. Insert Product"<<endl;
        cout<<"2. See your product"<<endl;
        cout<<"If you want to return at the begin of programm please insert 3!"<<endl;
        cout<<"If you want to exit the program plese insert:  4"<<endl;
        cout<<"***********************************************************"<<endl;
        option=suplier.check_option();
    }
}
return 0;
}

int sistem_entrance()
{
Root root;
int option;
cout<<"Please chose option"<<endl;
cout<<"1. Client entrance"<<endl;
cout<<"2. Supplier entrance"<<endl;
cout<<"3. Admin entarnce"<<endl;
cout<<"4. Exit the program"<<endl;
option=root.check_option();
while(option)
    {
        switch(option)
        {
        case 1:
            {
                    client_entance();
                    break;
            }
        case 2:
            {
                suplier_entranse();
                break;
            }
        case 3:
            {
                admin_entrance();
                break;
            }
        case 4:
            {
                return 0;
                break;
            }
        }
        if(option!=4)
        {
        cout<<"Please chose option"<<endl;
        cout<<"1. Client entrance"<<endl;
        cout<<"2. Supplier entrance"<<endl;
        cout<<"3. Admin entarnce"<<endl;
        cout<<"4. Exit the program"<<endl;
        option=root.check_option();
        }
    }
}


#endif // ACCESS_MAIN_H_INCLUDED
