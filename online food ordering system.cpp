#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<conio.h>

using namespace std;

class login
{
    string username, password;
    fstream file;

public:
    void new_user(string fname)
    {
        file.open(fname, ios::app);
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Enter new username\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>username;
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Enter new password\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>password;

        file<<username<<"\t\t\t\t";
        file<<password<<endl;
        file.close();
    }

    bool check_authority(string fname)
    {
        q:
        string name, pass;
        fstream file;
        file.open(fname, ios::in);
        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Enter your username\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>name;
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Enter your password\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>pass;
        system("cls");
        while(file)
        {
            file>>username;
            file>>password;


            if(username == name)
            {
                if(pass == password)
                    return true;
            }
        }
        file.close();
        cout<<"\t\t\t\t\t\t\t";
         cout<<"Username or password incorrect\n";
         cout<<"\n\n\n\n";
         int y;
         cout<<"\t\t\t\t\t\t\t";
         cout<<"Do you want to enter details again(0/1): \n";
         cin>>y;
         if(y)
            goto q;

        else
            exit(0);



    }
};



class provider : public login
{
    string food_item, name;
    float price;
    fstream file;
    fstream foodfile;
public:

        void add_hotel(void)
        {
        new_user("provider.txt");
        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Enter your hotel file name(it is as : hotel_name.txt)\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>name;
        file.open(name, ios::out);
        file.close();
        }

    void update_menu(void)
    {

        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Enter your hotel file name(it is as : hotel_name.txt)\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>name;
        label :
        file.open(name, ios::app);
        foodfile.open("food_items.txt", ios::app);
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Enter the food name\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>food_item;
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Enter the price\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>price;

        file<<food_item<<"\t\t\t"<<price<<endl;
        foodfile<<food_item<<"\t\t\t"<<price<<endl;

        file.close();
        foodfile.close();
        int a;
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Do you want to enter again(0/1) : ";
        cout<<"\t\t\t\t\t\t\t";
        cin>>a;
        if(a)
            goto label;
    }
    void see_menu(void)
    {
        label:
          cout<<"\n\n\n\n";
          cout<<"\t\t\t\t\t\t\t";
          cout<<"Enter your hotel file name(it is as : hotel_name.txt)\n";
          cout<<"\t\t\t\t\t\t\t";
          cin>>name;

          file.open(name, ios::in);
          cout<<"\t\t\t\t\t\t\t";
          cout<<setw(20)<<"name of food"<<setw(20)<<"cost of food\n";

          while(file)
          {
              file>>food_item;
              file>>price;
              cout<<"\t\t\t\t\t\t\t";
              cout<<setw(20)<<food_item<<setw(20)<<price<<endl;
          }
          file.close();
          int a;
          cout<<"\t\t\t\t\t\t\t";
          cout<<"Do you want to continue again(0|1)\n";
          cout<<"\t\t\t\t\t\t\t";
          cin>>a;
          if(a)
            goto label;
    }
};


class user : public login//, public provider
{
    string food[20];
    int number[20], i = 0;
    float bill = 0, total[20];
public:
    user()
    {
        system("cls");
        int a;
        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Choose your suitable option\n";
        cout<<"\t\t\t\t\t\t\t";
        cout<<"1.Do you have an account\n";
        cout<<"\t\t\t\t\t\t\t";
        cout<<"2.Do you want to create a new account\n";
        cout<<"\t\t\t\t\t\t\t";
        cout<<"3.Do you want to exit the system\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>a;
        bool check;
        switch(a)
        {
        case 1:
            {
                check_authority("Customer.txt");
                break;
            }
        case 2:
            {
                new_user("Customer.txt");
                break;
            }
        case 3:
            {
                exit(0);
                break;
            }
        default :
            {
                cout<<"\t\t\t\t\t\t\t";
                cout<<"Please choose the correct option\n";
                break;
            }
        }


            string food_item;
            float price;

            fstream file;
            cout<<"\n\n\n\n\n\t\t\t\t\t\t\t";
            file.open("food_items.txt", ios::in);

            cout<<setw(20)<<"food items"<<setw(20)<<"price"<<"\n\n\n";
            while(file)
          {
              file>>food_item;
              file>>price;
              cout<<"\t\t\t\t\t\t\t";
              cout<<setw(20)<<food_item<<setw(20)<<price<<endl;
          }
          file.close();


    }

    void order(void);
    void make_bill(void);
    void payment(void);
};


void user::order(void)
{
    while(1)
    {
        label:
        int check = 0;
        cout<<"\n\n\t\t\t\t\t\t\t";
        cout<<"Enter the name of food you want to order"<<endl;
        cout<<"\t\t\t\t\t\t\t";
        cin>>food[i];
        cout<<"\t\t\t\t\t\t\t";
        cout<<"How many orders you want to place for "<<food[i]<<endl;
        cout<<"\t\t\t\t\t\t\t";
        cin>>number[i];

        string food_item;
        float price;
        fstream file;
        file.open("food_items.txt", ios::in);
        while(file)
          {
              file>>food_item;
              file>>price;
              if(food[i] == food_item)
              {
                  check = 1;
                  total[i] = price * number[i];
                  break;
              }

          }
          file.close();

          if(!check)
          {
              cout<<"\t\t\t\t\t\t\t";
              cout<<"The food you are trying to order is not available\n";
              cout<<"\t\t\t\t\t\t\t";
              cout<<"Please choose among the available food items\n";
              goto label;
          }
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Do you want to order anything else\n";
        int a;
        cout<<"\t\t\t\t\t\t\t";
        cin>>a;
        if(i == 20)
        {
            cout<<"\t\t\t\t\t\t\t";
            cout<<"Sorry you can just order 20 different items in one transaction\n";
            break;
        }
        if(!a)
            break;
        i++;
    }
}

void user::make_bill(void)
{
    if(i == -1)
    {
        cout<<"\t\t\t\t\t\t\t";
        cout<<"Please order something before processing for bill\n";
        return;
    }

    else
    {
        cout<<"\n\n\n";
        cout<<"\t\t\t\t\t\t\t";
        cout<<setw(30)<<"food ordered"<<setw(30)<<"Total item for each"<<setw(30)<<"Total cost for each item"<<endl;
        for(int j = 0; j <= i; j++)
        {
            cout<<"\t\t\t\t\t\t\t";
            cout<<setw(30)<<food[j]<<setw(30)<<number[j]<<setw(30)<<total[j]<<endl;
            bill += total[j];
        }
        cout<<"\n\n\n\t\t\t\t\t\t\t";
        cout<<"Total bill for your order is "<<bill<<"\n\n"<<endl;
    }
}

void user::payment(void)
{
     system("cls");
    int choice;
    label:
    cout<<"\t\t\t\t\t\t\t";
    cout<<"How do you prefer to pay\n\n";
    cout<<"\t\t\t\t\t\t\t";
    cout<<"1.Online payment\n";
    cout<<"\t\t\t\t\t\t\t";
    cout<<"2. Cash on delivery\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
           label1:
            cout<<"\t\t\t\t\t\t\t";
            cout << "How would you like to pay?:\n";
            cout << "\n\t\t\t\t\t\t\t1.Debit Card \n\t\t\t\t\t\t\t2.Credit Card \n\t\t\t\t\t\t\t3.Net Banking\n";
            cout << "\n\n\t\t\t\t\t\t\tEnter your choice\n";
            int choice1;
            cout<<"\t\t\t\t\t\t\t";
            cin >> choice1;
            string card, date, cvv, password, bank, user_id;
            switch(choice1)
            {
                case 1:
                    cout << "\n\t\t\t\t\t\t\tEnter card no:";

                    cin >>card;
                    cout << "\nEnter expiry date:";

                    cin >> date;
                    cout << "\nEnter CVV no.:";

                    cin >> cvv;
                    cout << "\nTransaction Successful\n";
                    break;
                case 2:
                    cout << "\nEnter card no:";
                    cin >> card;
                    cout << "\nEnter expiry date:";
                    cin >> date;
                    cout << "\nEnter password:";
                    cin >> password;
                    cout << "\nTransaction Successful\n";
                    break;
                case 3:
                    cout << "Banks Available:  1.Nabil Bank  2.Standard Chartered Bank 3.Swiss Bank ";
                    cout << "\nSelect your bank:";
                    cin >> bank;
                    cout << "\nYou have selected:" << bank;
                    cout << "\nEnter user id:";
                    cin >> user_id;
                    cout << "\nEnter password:";
                    cin >> password;
                    cout << "\nTransaction Successful\n";
                    break;
                default:
                    cout << "\nWrong input entered.\nTry again\n\n";
                    goto label1;
            }

        }

    case 2:
        {
            cout<<"\t\t\t\t\t\t\t";
            cout<<"You have choosed to pay at delivery\n";
            break;
        }
    default:
        {
            cout<<"\t\t\t\t\t\t\t";
            cout<<"Please choose the valid available option\n";
            goto label;
            break;
        }
    }



    int a;
    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\t\tDo you want us to access your location or you would prefer to manually provide your location : \n";
    cout<<"\t\t\t\t\t\t\t1.Grant permission for accessing location\n";
    cout<<"\t\t\t\t\t\t\t2.Manually provide location\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>a;
    p:
    switch(a)
    {
    case 1:
        {
            cout<<"\t\t\t\t\t\t\tCurrent GPS location saved as delivery location\n";
            cout<<"\t\t\t\t\t\t\tIf this is not the delivery location you can set the delivery location manually\n";
            cout<<"\t\t\t\t\t\t\tPress 'm' if you want to change location else press 'n' for no change\n";
            char q;
            cout<<"\t\t\t\t\t\t\t";
            cin>>q;
            if(q == 'm' || q == 'M')
                a = 2;
            else
                break;
        }
    case 2:
        {
            int loc;
            cout<<"\t\t\t\t\t\t\tEnter your postal code : ";
            cout<<"\t\t\t\t\t\t\t";
            cin>>loc;
            cout<<"\t\t\t\t\t\t\tEnter any nearby popular landmark : ";
            cout<<"\t\t\t\t\t\t\t";
            string lan;
            cin>>lan;
            cout<<"\t\t\t\t\t\t\tAny other thing that can helps us identify your location(If not any write NA) : ";
            string ad;
            cout<<"\t\t\t\t\t\t\t";
            cin>>ad;
            break;
        }
    default:
        {
            cout<<"\t\t\t\t\t\t\tChoose the correct option\n";
            goto p;
        }
    }
    string phoneno;
    cout<<"\t\t\t\t\t\t\tEnter your contact number : \n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>phoneno;
    cout<<"\t\t\t\t\t\t\t";
    cout<<"Your order is placed successfully\n";
}

int main(void)
{
    int t = 1;
    while(t){
   system("cls");
   system("color 03");
   cout<<"\n\n\n\n\n\n\n";
   cout<<"\t\t\t\t\t\t\t\t---||---||---||WELCOME TO THE ONLINE FOOD ORDERING SYSTEM---||---||---||\n";
   cout<<"\n\n\t\t\t\t\t\t\t\t---||---||---||WE  PROVIDE THE BEST SERVICE IN OUR AREA---||---||---||\n";
   cout<<"\n\n\t\t\t\t\t\t\t\t\t---||---||---||PRESS 'C' TO CONTINUE---||---||---||\n";
   char a;
   cin>>a;
   if(a == 'c' || a == 'C')
   {
       system("cls");
       //system("color 5F");
       cout<<"\n\n\n\n\n\n\n";
       cout<<"\n\t\t\t\t\t\t\t*/*/*/*/*/*/CHOOSE YOUR ROLE*/*/*/*/*/*/\n\n\n";
       cout<<"\t\t\t\t\t\t\t1.PROVIDER LOGIN\n\n";
       cout<<"\t\t\t\t\t\t\t2.USER\n\n\n\n\n";
       label:
       int choice;
       cin>>choice;
       system("CLS");
       cout<<"\n\n\n\n\n\n\n\n\n\n\n";

       switch(choice)
       {
      case 1:
        {
            provider p;
            z:
            cout<<"\t\t\t\t\t\t\t...||...||...||WELCOME TO THE PROVIDER LOGIN...||...||...||\n\n";
            cout<<"\t\t\t\t\t\t\t...||...||...||SEECT 1 IF YOU WANT NEW REGISTRATION...||...||...||\n\n";
            cout<<"\t\t\t\t\t\t\t...||...||...||SELECT 2 IF YOU ARE EXISTING MEMBER...||...||...||\n\n";
            int y;
            cin>>y;

            if(y == 1)
            {
              p.add_hotel();
              break;
            }
            else if(y == 2)
            {

            p.check_authority("provider.txt");
            cout<<"\n\n\n";
            cout<<"\t\t\t\t\t\t\t...||...||...||CHOOSE THE SUITABLE OPTION FOR YOU...||...||...||\n\n";
            cout<<"\t\t\t\t\t\t\t...||...||...||1.SEE YOUR MENU...||...||...||\n\n";
            cout<<"\t\t\t\t\t\t\t...||...||...||2.UPDATE YOUR MENU...||...||...||\n\n";


            x:
            int opt;
            cin>>opt;

            switch(opt)
            {
            case 1:
                {
                    p.see_menu();
                    break;
                }
            case 2:
                {
                    p.update_menu();
                    break;
                }
           default:
            {
                cout<<"\t\t\t\t\t\t\tPLEASE CHOOSE THE CORRECT OPTION\n";
                goto x;
            }
            }

            break;
        }
        else
        {
            cout<<"\t\t\t\t\t\t\tPLEASE CHOOSE THE CORRECT OPTION\n";
                goto z;
        }
        }
      case 2:
        {
            user u;
            u.order();
            u.make_bill();
            system("PAUSE");
            u.payment();
            break;
        }
       default:
        {
            cout<<"\t\t\t\t\t\t\tPLEASE CHOOSE THE CORRECT OPTION\n";
            goto label;
        }
       }
   }
   p:
   cout<<"Do you want to enter the system again(0/1) : ";
   cin>>t;

    }
}
