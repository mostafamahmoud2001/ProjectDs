#include "Admin.h"
Admin::Admin(string name, string pass, string email)
{
    this->name =  name;
    this->password = pass;
    this->email = email;
}
string Admin::getname()
{
    return name;
}
string Admin::getpassword()
{
    return password;
}
string Admin::getEmail()
{
    return email;
}
void Admin::pushToWaited(Product p)
{
    WaitedProduct.push(p);
}
void Admin::viewWaitedProduct(vector<Product>& productes)
{
    int x;
    if (!WaitedProduct.empty())
    {
        cout << "                                        *_______ Waiting list of products _______*" << endl;
        for (int i = 1; !WaitedProduct.empty(); i++)
        {
            Product temp = WaitedProduct.front();
            WaitedProduct.pop();
            cout << "Product (" << i << ")" << endl;
            cout << "Name : " << temp.getname() << endl;
            cout << "ID : " << temp.getid() << endl;
            cout << "Category : " << temp.getcategory() << endl;
            cout << "Quantity : " << temp.getquantity() << endl;
            cout << "Price : " << temp.getprice() << endl;
            cout << "___________________________________________" << endl;
            cout << "Do you want to accept this product ?" << endl;
            cout << "1- Yes" << endl << "2- No" << endl;
            cout << "Your choice : ";
            while (1)
            {
                cin >> x;
                if (x == 1 || x == 0)
                    break;
                cout << "invaild choice! " << endl;
            }
            if (x == 1)
            {
                productes.push_back(temp);
                cout << "Product has added successfully" << endl;
            }
            else if (x == 2)
            {
                cout << "Product has ignored" << endl;
            }
            cout << "___________________________________________" << endl;
        }
    cout << "________________________________________________________________________________________________________________________" << endl;
    AdminMainMenu();
    }
    else
    {
        cout << "The waiting list is empty !" << endl;
        cout << "________________________________________________________________________________________________________________________" << endl;
        AdminMainMenu();
    }
}
int Admin::AdminMainMenu()
{
    int s;
    cout << "1- Show the waiting list of products "<<endl;
    cout << "2- Logout " << endl;
    cout << "Your choice : ";
    while (1)
    {
        cin >> s;
        if ((s == 1 || s == 2))
        {
            cout << "________________________________________________________________________________________________________________________" << endl;
            return s;
        }
        cout << "Enter valid choice : ";
    }
}