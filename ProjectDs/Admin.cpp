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
    cout << "Product waited : " << endl << endl;
    for (int i = 1; !WaitedProduct.empty(); i++)
    {
        Product temp = WaitedProduct.front();
        WaitedProduct.pop();
        cout << "Product " << i << " is : "<<endl;
        cout << "Name : " << temp.getname()<<endl;
        cout << "ID : " << temp.getid()<<endl;
        cout << "Category : " <<temp.getcategory()<<endl;
        cout << "Quantity : " <<temp.getquantity()<<endl;
        cout << "=================================================================" << endl;
        cout << "Are you want to accept this product ? if you agree press 1 and 2 if not" << endl;
        while (1)
        {
            cin >> x;
            if (x == 1 || x == 0)
                break;
            cout << "invaild choice!" << endl;
        }
        if (x==1)
        {
            productes.push_back(temp);
            cout << "Product add successful" << endl;
        }
        else if (x == 2)
        {
            cout << "product has ignore" << endl;
        }
        
    }
    
}
int Admin::AdminMainMenu()
{
    int s;
    cout << "1 - To show waited list "<<endl;
    cout << "2 - To logout " << endl;
    cout << "Enter number : ";
    while (1)
    {
        cin >> s;
        if ((s ==1 || s == 2 ))
            return s;
        cout << "Enter valid num " << endl;
    }
    
}