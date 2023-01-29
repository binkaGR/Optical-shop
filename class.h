#include <iostream>
#include <string>
using namespace std;
class Root
{
private:
    string Username;
    string Password;
    int Reight;
    //char out='\n';
protected:
    struct Users
    {
    string username;
    string password;
    int reight;
    };

    struct Product
    {
    int id;
    string name_product;
    string type;
    string name_maretrials;
    float diopter;
    float thickness;
    float price;
    };

    struct Supllier
    {
        int id;
        string username;
        string bulstat;
        string location;
        int tel_number;
    };


    int numder_file_row(string file_name);
    int read_file(string file_name);
    void get_username(Users users[], int br);
    int check_access(Users users[], int br, string username, string password);
    int get_number_product();
public:
    Root();
    friend  ofstream& operator << (ofstream&, Root);
    void set_Username(string username);
    void set_Password(string password);
    void set_Right(int reigth);

    string get_Username();
    string get_Password();
    int get_Reight();

    int check_option();
    int check_reight();
};

class Client : public Root
{
private:
void cheak_true_supllier(Product product[]);
void show_supllier(string name);
void show_all_product(Product product[]);
void inser_stoller(string name,Product product, int count_product);
void shop(string name);
void show_suplier_product(Product product[], string supllier_name);
public:
    Client();

    void buy_product();
    void show_Product();
};

class supllier : public Root
{
private:
    int id;
    string Bulstat;
    string Location;
    int Phone_number;
protected:
    void create_product(string file_name);
protected:

public:
    supllier();

    void set_bulsat(string bulstat);
    void set_location(string location);
    void set_Phone_number(int phone_number);

    string get_Bulstat();
    string get_Location();
    int get_Phone_number();

    void inser_product();
    void see_own_product();

};

class Admin : public Root
{
private:

void create_product(string file_name);
void write_user_file(Users user);
void create_suplier(string file_name, string username);

public:
    Admin();
    void insert_account();
    void insert_product();
};

