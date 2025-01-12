#include <iostream>
#include <string>
using namespace std;

struct ManageItem
{
    int code;
    string name;
    int price;
    int amount;
    ManageItem *left;
    ManageItem *right;
};

void printItemsWithPrice(ManageItem *root, int p)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->price == p)
    {
        cout << "Name: " << root->name << " ,price: " << root->price << endl;
    }
    printItemsWithPrice(root->left, p);
    printItemsWithPrice(root->right, p);
}

int TotalAllItems(ManageItem *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->price * root->amount + TotalAllItems(root->left) + TotalAllItems(root->right);
}

void addItem(ManageItem *&root, int code, string name, int price, int amount)
{
    if (root == nullptr)
    {
        root = new ManageItem{code, name, price, amount, nullptr, nullptr};
    }
    else if (code < root->code)
    {
        addItem(root->left, code, name, price, amount);
    }
    else
    {
        addItem(root->right, code, name, price, amount);
    }
}

int main()
{
    ManageItem *root = nullptr;
    int n;
    while (true)
    {
        cout << "CHUONG TRINH QUAN LY SAN PHAM" << endl;
        cout << "-----------------------------" << endl;
        cout << "1.Nhap them san pham" << endl;
        cout << "2.In ra tat ca san pham" << endl;
        cout << "3.Tinh gia tien cac san pham" << endl;
        cout << "4.Thoat" << endl;
        cout << "Moi chon chuc nang: ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            int code;
            string name;
            int price;
            int amount;
            cout << "Nhap ma san pham: ";
            cin >> code;
            cout << "Nhap ten san pham: ";
            cin >> name;
            cout << "Nhap gia san pham: ";
            cin >> price;
            cout << "Nhap so luong san pham: ";
            cin >> amount;
            addItem(root, code, name, price, amount);
            cout << "Nhap thanh cong!" << endl;
            break;
        }
        case 2:
        {
            int p;
            cout << "Moi nhap gia can tim: ";
            cin >> p;
            cout << "Danh sach san pham co gia " << p << " la: " << endl;
            printItemsWithPrice(root, p);
            break;
        }
        case 3:
        {
            cout << "Tong gia tien cua tat ca san pham la: " << TotalAllItems(root) << endl;
            break;
        }
        case 4:
        {
            cout << "Cam on ban da su dung chuong trinh!" << endl;
            return 0;
        }
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    }
}