#include<bits/stdc++.h>

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;
    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

void shopping::menu()
{
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t__________________________\n";
    cout << "\t\t\t\t                           \n";
    cout << "\t\t\t\t   Supermarket Main Menu   \n";
    cout << "\t\t\t\t                           \n";
    cout << "\t\t\t\t__________________________\n";
    cout << "\t\t\t\t                           \n";

    cout << "\t\t\t\ |     1) Administrator        |\n";
    cout << "\t\t\t |                              \n";
    cout << "\t\t\t\ |     2) Buyer                |\n";
    cout << "\t\t\t |                              \n";
    cout << "\t\t\t\ |     3) Exit                 |\n";
    cout << "\t\t\t |                              \n";
    cout << "\n\t\t\t Please select: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Please Login \n ";
        cout << "Enter Email : ";
        cin >> email;
        cout << "Enter Password : ";
        cin >> password;

        if (email == "ank688.ak@gmail.com" && password == "ank688.ak@")
        {
            administrator();
        }
        else
        {
            cout << "Invalid email/Password !!!";
        }
        break;
    case 2:
        buyer();
        break;
    case 3:
        exit(0);
        break; // Optional, as the program will exit anyway.
    default:
        cout << "Please select from the given options";
        break;
    }
    goto m;
}


void shopping :: administrator()
{
    m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator menu";
    cout << "\n\t\t\t|______1) Add the product_________|";
    cout << "\n\t\t\t|                                 |";
    cout << "\n\t\t\t|______2) Modify the product______|";
    cout << "\n\t\t\t|                                 |";
    cout << "\n\t\t\t|______3) Delete the product______|";
    cout << "\n\t\t\t|                                 |";
    cout << "\n\t\t\t|_____4) Back to the main menu____|";
    cout << "\n\t\t\t|                                 |";
    cout << "\n\t\t Please enter your choice";
    cin >> choice;

    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout << "Invalid choice!";
    }
    goto m;
}

void shopping:: buyer()
{
    m:
    int choice;
    cout << "\t\t\t Buyer \n";
    cout << "               \n";
    cout << "\t\t\t 1)Buy product \n";
    cout << "               \n";
    cout << "\t\t\t 2) Go back \n";
    cout << "\t\t\t Enter your choice : \n";

    cin >> choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout << "Invalid choice";
    }
    goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\n\t\t\t Product code of the product";
    cout << "\n\n\n\t\t\t Add new Product (Insert Product Code) : ";
    cin>>pcode;
    cout << "\n\n\n\t\t\t Name of the Product : ";
    cin >> pname;
    cout << "\n\n\n\t\t\t Price of the Product : ";
    cin >> price;
    cout << "\n\n\n\t\t\t Discount on product : ";
    cin >> dis;

    data.open("database.txt",ios::in);    //open it in reading mode
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);    //out is for writing  //app is for append if data is already there
        data << " "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data >> c >> n >> p >> d;    //initializing the index

        while(!data.eof())     //eof : end of file hai
        {
            if(c == pcode)   //c stands for code, ye hum same item ko likhenge to +1 kardenge token ko
            {
                token++;
            }
            data >> c >> n >>p >>d;
        }
        data.close();
    }

    if(token==1)
        goto m;
    else{
        data.open("database.txt",ios::app|ios::out);    //out is for writing  //app is for append if data is already there
        data << " "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    cout << "\n\n\t\t Record Inserted !";
}

void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code :";
    cin >> pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout << "\n\n File doesn't exist !";
    }
    else
    {
        data1.open("database1.txt",ios::app | ios::out);    //temporary ye file banaya hai, isme edit karna hai fir isko rename to database.txt

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout << "\n\t\t Product new code : ";
                cin >> c;
                cout << "\n\t\t Name of the Product : ";
                cin >> n;
                cout << "\n\t\t Price : ";
                cin >>p;
                cout <<"\n\t\t Discount : ";
                cin >>d;
                data1 << " "<<c <<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout << "\n\n\t\t Record edited";
                token++;
            }
            else
            {
                data1 << " "<<pcode <<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data >>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout << "\n\n Record not found !";
        }
    }
}

void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout << "\n\n\t Delete Product";
    cout << "\n\n\t Product code :";
    cin >>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data1.open("database1.txt",ios::app | ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout <<  "\n\n\t Product deleted Successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data >>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout << "\n\n Record not found";
        }
    }
}

void shopping:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout << "\n\n|_______________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n|_______________________________________\n";
    data>> pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout << pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;
    int arrc[100];  //array of codes
    int arrq[100];  //storing multiple quantity
    char choice;
    int c = 0;
    float total = 0;

    // Create data structures to hold product information
    int productCodes[100];
    string productNames[100];
    float productPrices[100];
    float productDiscounts[100];
    int numProducts = 0;

    // Read product information into memory
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        while (data >> pcode >> pname >> price >> dis)
        {
            productCodes[numProducts] = pcode;
            productNames[numProducts] = pname;
            productPrices[numProducts] = price;
            productDiscounts[numProducts] = dis;
            numProducts++;
        }
        data.close();

        list();
        cout << "\n_________________________________\n";
        cout << "\n|                                \n";
        cout << "\n      Please place the order    \n";
        cout << "\n|                                \n";
        cout << "\n_________________________________\n";
        do
        {
            m:
            cout << "\n\nEnter Product code : ";
            cin >> arrc[c];
            cout << "\n\nEnter the Product quantity : ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate Product code, Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another Product? if yes then press y else n for no  ";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t\t_________________RECEIPT___________________\n";
        cout << "\nProduct No\t Product Name\t Product quantity \tPrice \tAmount\tAmount with discount\n";

        for (int i = 0; i < c; i++)
        {
            bool productFound = false;
            for (int j = 0; j < numProducts; j++)
            {
                if (productCodes[j] == arrc[i])
                {
                    float amount = productPrices[j] * arrq[i];
                    float discountAmount = amount - (amount * productDiscounts[j] / 100);
                    total += discountAmount;
                    cout << "\n" << productCodes[j] << "\t\t" << productNames[j] << "\t\t\t" << arrq[i] << "\t\t" << productPrices[j] << "\t" << amount << "\t\t" << discountAmount;
                    productFound = true;
                    break;  // Exit the inner loop since the product was found
                }
            }
            if (!productFound)
            {
                cout << "\nProduct with code " << arrc[i] << " not found.";
            }
        }
    }
    cout << "\n\n__________________________________________";
    cout << "\n Total Amount : " << total;
}


int main()
{
    shopping s;
    s.menu();
}

