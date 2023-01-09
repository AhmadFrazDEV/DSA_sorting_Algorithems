#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;

// Functions

void Binary_Search_Tree();
void Load_100_Records();

// Structure for node
struct node
{
    /* data */
    string index;
    string Customer_Id;
    string First_Name;
    string Last_Name;
    string Company;
    string City;
    string Country;
    string Phone_1;
    string Phone_2;
    string Email;
    string Subscription_Date;
    string Website;
    node *left, *right;

    void setleft(node *left) { left = left; }
    void setright(node *right) { right = right; }
    node *getleft() { return left; }
    node *getright() { return right; }

    node()
    {
        // default constructor
    }

    node(int index, string Customer_Id, string First_Name, string Last_Name, string Company, string City, string Country,
         string Phone_1, string Phone_2, string Email, string Subscription_Date, string Website)
    {
        this->index = index;
        this->Customer_Id = Customer_Id;
        this->First_Name = First_Name;
        this->Last_Name = Last_Name;
        this->Company = Company;
        this->City = City;
        this->Country = Country;
        this->Phone_1 = Phone_1;
        this->Phone_2 = Phone_2;
        this->Email = Email;
        this->Subscription_Date = Subscription_Date;
        this->Website = Website;
        setleft(NULL);
        setright(NULL);
    }
};

class Customers
{

 public:
    node *root = NULL;
    node *temp;

    void add(int index, string Customer_Id, string First_Name, string Last_Name, string Company, string City, string Country,
             string Phone_1, string Phone_2, string Email, string Subscription_Date, string Website)
    {
        node *newnNode = new node();
        newNode->index = index;
        newNode->Customer_Id = Customer_Id;
        newNode->First_Name = First_Name;
        newNode->Last_Name = Last_Name;
        newNode->Company = Company;
        newNode->City = City;
        newNode->Country = Country;
        newNode->Phone_1 = Phone_1;
        newNode->Phone_2 = Phone_2;
        newNode->Email = Email;
        newNode->Subscription_Date = Subscription_Date;
        newNode->Website = Website;
        newnNode->setleft(NULL);
        newnNode->setright(NULL);
            
    }
    

    // void add(node *n)
    // {
    //     cout << "Data hass been Added" << endl;

    //     node *prev = root;
    //     node *next = root;
    //     if (root == NULL)
    //     {
    //         root = n;
    //         return;
    //     }
    //     while (next != NULL)
    //     {
    //         prev = next;
    //         if (stoi(n->index) < stoi(prev->index))
    //             next = prev->left;
    //         else
    //             next = prev->right;
    //     }
    //     if (stoi(n->index) >= stoi(prev->index))
    //         prev->right = n;
    //     else
    //         prev->left = n;
    // }

    bool loadData()
    {
        string index;
        string Customer_Id;
        string First_Name;
        string Last_Name;
        string Company;
        string City;
        string Country;
        string Phone_1;
        string Phone_2;
        string Email;
        string Subscription_Date;
        string Website;
        fstream file;

        int counter = 0;
        file.open("customers-100.csv", ios::in);
        int count = 0;
        if (file.is_open())
        {
            while (!file.eof())
            {

                if (count == 0)
                {
                    string temp;
                    getline(file, temp);
                    count = 1;
                    // just for testing
                }
                else
                {
                    
                    getline(file,index);
                    getline(file,Customer_Id);
                    getline(file,First_Name);
                    getline(file,Last_Name);
                    getline(file,Company);
                    getline(file,City);
                    getline(file,Country);
                    getline(file,Phone_1);
                    getline(file,Phone_2);
                    getline(file,Email);
                    getline(file,Subscription_Date);
                    getline(file,Website);
                    add(index, Customer_Id, First_Name, Last_Name, Company, City, Country,
                        Phone_1, Phone_2, Email, Subscription_Date, Website);
                    // add(n);
                }
            }
            file.close();
            return true;
        }
        else
        {
            cout << "No data yet" << endl;
            return false;
        }
        return false;
    }

    void display_data()
    {
        if (root != NULL)
        {
            queue<node *> q;
            q.push(root);

            while (!q.empty())
            {
                cout << "ok" << endl;
                node *temp1 = q.front();
                q.pop();

                cout << temp1->index;
                cout << temp1->Customer_Id;
                cout << temp1->First_Name;
                cout << temp1->Last_Name;
                cout << temp1->Company;
                cout << temp1->City;
                cout << temp1->Country;
                cout << temp1->Phone_1;
                cout << temp1->Phone_2;
                cout << temp1->Email;
                cout << temp1->Subscription_Date;
                cout << temp1->Website;

                if (temp1->getleft() != NULL)
                    q.push(temp1->getleft());
                if (temp1->getright() != NULL)
                    q.push(temp1->getright());
            }
        }
        else
            cout << "No record Yet" << endl;
    }
};

int option_For_1st_menu_Function()
{
    cout << "1. Binary Tree Search" << endl;
    cout << "2. AVL Tree" << endl;
    cout << "3. Exit" << endl;
    int opt;
    cout << "Enter your option :";
    cin >> opt;
    return opt;
}

void systemCLS()
{
    cout << "Press Any Key to continue.....";
    char opt;
    cin >> opt;
    system("CLS");
}

int menu_for_BST_function()
{
    cout << "1. Load 100 Records" << endl;
    cout << "2. Load 1000 Records" << endl;
    cout << "3. Load 10000 Records" << endl;
    cout << "4. Load 100000 Records" << endl;
    cout << "0. Exit" << endl;

    cout << "Enter your option :";
    int opt;
    cin >> opt;
    return opt;
}

int fun_afterLoadData()
{
    cout << "1. Inserts A New Record" << endl;
    cout << "2. Retrive A Record" << endl;
    cout << "3. Updata A Record" << endl;
    cout << "4. Delete A Record" << endl;
    cout << "5. Traverse Binary Tree" << endl;
    cout << "0. Exit" << endl;

    cout << "Enter your option :";
    int opt;
    cin >> opt;
    return opt;
}
int main()
{
    int option_For_1st_menu;
    do
    {
        /* code */
        option_For_1st_menu = option_For_1st_menu_Function();
        if (option_For_1st_menu == 1)
        {
            systemCLS();
            Binary_Search_Tree();
        }
        if (option_For_1st_menu == 2)
        {
            // AVL_Tree();
            // systemCLS();
        }

    } while (option_For_1st_menu != 3);

    return 0;
}

void Binary_Search_Tree()
{
    int menu_for_BST;
    do
    {
        /* code */
        Customers c;
        int var_afterLoadData;
        menu_for_BST = menu_for_BST_function();
        if (menu_for_BST == 1)
        {
            Load_100_Records(); // Load Records
            c.display_data();
            do
            {
                /* code */
                var_afterLoadData = fun_afterLoadData();
                systemCLS();
            } while (var_afterLoadData != 0);
        }
    } while (menu_for_BST != 0);
}

void Load_100_Records()
{
    Customers c;
    c.loadData() ? cout << "Data load Successfully" : cout << "Sorry" << endl;
}
