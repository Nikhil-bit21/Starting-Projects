#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Item
{
public:
    string name;
    int Quantity;
    double Price;

    Item()
    {
        name = "";
        Quantity = 0;
        Price = 0.0;
    }

    Item(const string &name, int quantity, double price)
    {
        this->name = name;
        this->Quantity = quantity;
        this->Price = price;
    }
};

class Inventory
{
private:
    unordered_map<string, Item> inventory;

public:
    void AddItem(string name, int quantity, double price)
    {
        if (inventory.count(name) > 0)
        {
            inventory[name].Quantity += quantity;
        }
        else
        {
            Item item(name, quantity, price);
            inventory[name] = item;
        }
        cout << quantity << " " << name << "'s added to inventory. *.*" << endl;
    }

    void RemoveItem(string name, int quantity)
    {
        if (inventory.count(name) > 0)
        {
            Item &item = inventory[name];
            if (item.Quantity >= quantity)
            {
                item.Quantity -= quantity;
                cout << quantity << " " << name << "'s removed from inventory. *.*" << endl;
                if (item.Quantity == 0)
                {
                    inventory.erase(name);
                }
            }
            else
            {
                cout << "Insufficient Quantity in inventory. *.*" << endl;
            }
        }
        else
        {
            cout << name << " Does not exist in inventory" << endl;
        }
    }

    void Report()
    {
        cout << "Inventory Report:" << endl;
        for (const auto &pair : inventory)
        {
            const string &name = pair.first;
            const Item &item = pair.second;
            cout << "Name: " << name << ", Quantity: " << item.Quantity << ", Price: " << item.Price << endl;
        }
    }

    void SoldItem(string name, int quantity)
    {
        if (inventory.count(name) > 0)
        {
            Item &item = inventory[name];
            if (item.Quantity >= quantity)
            {
                item.Quantity -= quantity;
                cout << quantity << " " << name << "(s) sold." << endl;
                if (item.Quantity == 0)
                {
                    inventory.erase(name);
                }
            }
            else
            {
                cout << "Insufficient quantity in inventory." << endl;
            }
        }
        else
        {
            cout << name << " does not exist in inventory." << endl;
        }
    }
};

int main()
{
    Inventory inventory;

    while (true)
    {
        cout << endl;
        cout << "Welcome To Titan's Inventory Management System Here is the option menu select what you want to do! *.*" << endl;
        cout << endl;
        cout << "------Inventory Management System------" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Remove Item" << endl;
        cout << "3. Generate Report" << endl;
        cout << "4. Sell Item" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice what you want to do (1-5): " << endl;
        cin >> choice;

        string name;
        int quantity;
        double price;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Item's name: " << endl;
            cin >> name;
            cout << "Enter Item quantity you want to add: " << endl;
            cin >> quantity;
            cout << "Enter the Price: " << endl;
            cin >> price;

            inventory.AddItem(name, quantity, price);

            break;
        }
        case 2:
        {
            cout << "Enter Item's name: " << endl;
            cin >> name;
            cout << "Enter Item quantity you want to remove: " << endl;
            cin >> quantity;

            inventory.RemoveItem(name, quantity);

            break;
        }
        case 3:
        {
            inventory.Report();
            break;
        }
        case 4:
        {
            cout << "Enter Name of Item: " << endl;
            cin >> name;
            cout << "Enter Sold Quantity: " << endl;
            cin >> quantity;

            inventory.SoldItem(name, quantity);

            break;
        }
        case 5:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }
        }
    }

    return 0;
}

// #include <iostream>
// #include <math.h>
// #include <unordered_map>
// #include <fstream>    // used for saving or loading something from memory
// #include <filesystem> // get info about directory and locations

// using namespace std;
// // namespace fs = std::filesystem;

// class Item
// {
// public:
//     string name;
//     int Quantity;
//     double Price;

//     Item(const string &name, int quantity, double price)
//     {
//         this->name = name;
//         this->Quantity = quantity;
//         this->Price = price;
//     }
// };

// class Inventory
// {
// private:
//     unordered_map<string, Item> inventory;

// public:
//     void AddItem(string name, int quantity, double price)
//     {
//         if (inventory.count(name) > 0)
//         {
//             inventory[name].Quantity += quantity;
//         }
//         else
//         {
//             Item item(name, quantity, price);
//             inventory[name] = item;
//         }
//         cout << quantity << " " << name << "'s added to inventory. *.*" << endl;
//     }

//     void RemoveItem(string name, int quantity)
//     {
//         if (inventory.count(name) > 0)
//         {
//             Item &item = inventory[name];
//             if (item.Quantity >= quantity)
//             {
//                 item.Quantity -= quantity;
//                 cout << quantity << " " << name << "'s removed from inventory. *.*" << endl;
//                 if (item.Quantity == 0)
//                 {
//                     inventory.erase(name);
//                 }
//             }
//             else
//             {
//                 cout << "Insufficient Quantity in inventory. *.*" << endl;
//             }
//         }
//         else
//         {
//             cout << name << " Does not exist in inventory" << endl;
//         }
//     }

//     void Report()
//     {
//         cout << "Inventory Report:" << endl;
//         for (const auto &pair : inventory)
//         {
//             const string &name = pair.first;
//             const Item &item = pair.second;
//             cout << "Name: " << name << ", Quantity: " << item.Quantity << ", Price: " << item.Price << endl;
//         }
//     }

//     void SoldItem(string name, int quantity)
//     {
//         if (inventory.count(name) > 0)
//         {
//             Item &item = inventory[name];
//             if (item.Quantity >= quantity)
//             {
//                 item.Quantity -= quantity;
//                 cout << quantity << " " << name << "(s) sold." << endl;
//                 if (item.Quantity == 0)
//                 {
//                     inventory.erase(name);
//                 }
//             }
//             else
//             {
//                 cout << "Insufficient quantity in inventory." << endl;
//             }
//         }
//         else
//         {
//             cout << name << " does not exist in inventory." << endl;
//         }
//     }

//     // void SaveInventory(string filename)
//     // {
//     //     fs::path location = fs::current_path();
//     //     string FullPath = (location / (filename + ".csv")).string();
//     //     ofstream file(FullPath);

//     //     if (file.is_open())
//     //     {
//     //         for (const auto &pair : inventory)
//     //         {
//     //             const string &name = pair.first;
//     //             const Item &item = pair.second;
//     //             file << name << "," << item.Quantity << item.Price << endl;
//     //         }
//     //         cout << "Inventory data Saved to " << FullPath << "." << endl;
//     //     }
//     //     else
//     //     {
//     //         cout << "Unable to save File." << endl;
//     //     }
//     //     file.close();
//     // }

//     // void LoadInventory(string filename)
//     // {
//     //     ifstream file(filename);

//     //     if (file.is_open())
//     //     {
//     //         inventory.clear();

//     //         string line;
//     //         while (getline(file, line))
//     //         {
//     //             size_t pos = line.find(",");
//     //             string name = line.substr(0, pos);
//     //             line.erase(0, pos + 1);

//     //             pos = line.find(",");
//     //             int quantity = stoi(line.substr(0, pos));
//     //             line.erase(0, pos + 1);

//     //             double price = stod(line);
//     //             Item item(name, quantity, price);
//     //             inventory[name] = item;
//     //         }
//     //         cout << "Inventory Data Loaded from " << filename << "." << endl;
//     //     }
//     //     else
//     //     {
//     //         cout << "Unable to open File" << endl;
//     //     }
//     //     file.close();
//     // }
// };

// int main()
// {
//     Inventory inventory;

//     while (true)
//     {
//         cout << endl;
//         cout << "Welcome To Titan's Inventory Management System Here is the option menu select what you want to do! *.*" << endl;
//         cout << endl;
//         cout << "------Inventory Management System------" << endl;
//         cout << "1. Add Item" << endl;
//         cout << "2. Remove Item" << endl;
//         cout << "3. Generate Report" << endl;
//         cout << "4. Sell Item" << endl;
//         // cout << "5. Save Inventory to file" << endl;
//         // cout << "6. Load Inventory from file" << endl;
//         cout << "5. Exit" << endl;

//         int choice;
//         cout << "Enter your choice what you want to do (1-7)" << endl;
//         cin >> choice;

//         string name;
//         int quantity;
//         double price;

//         switch (choice)
//         {
//         case1:
//         {
//             cout << "Enter Item's name : " << endl;
//             cin >> name;
//             cout << "Enter Item quantity you want to add : " << endl;
//             cin >> quantity;
//             cout << "Enter the Price : " << endl;
//             cin >> price;

//             inventory.AddItem(name, quantity, price);

//             break;
//         }
//         case2:
//         {
//             cout << "Enter Item's name : " << endl;
//             cin >> name;
//             cout << "Enter Item quantity you want to remove : " << endl;
//             cin >> quantity;

//             inventory.RemoveItem(name, quantity);

//             break;
//         }
//         case3:
//         {
//             inventory.Report();
//             break;
//         }
//         case4:
//         {
//             cout << "Enter Name of Item : " << endl;
//             cin >> name;
//             cout << "Enter Sold Quantity : " << endl;
//             cin >> quantity;

//             inventory.SoldItem(name, quantity);

//             break;
//         }
//         // case5:
//         // {
//         //     cout << "Enter Filename to save" << endl;
//         //     cin >> name;

//         //     inventory.SaveInventory(name);

//         //     break;
//         // }
//         // case6:
//         // {
//         //     cout << "Enter Filename to load" << endl;
//         //     cin >> name;

//         //     inventory.LoadInventory(name);

//         //     break;
//         // }
//         case5:
//         {
//             return 0;
//         }
//         default:
//         {
//             cout << "This is Beta Version & made for testing and feedback purpose. if you want to suggest some features feel free to send us your response. Thank You! *.*" << endl;
//             break;
//         }
//         }
//     }

//     return 0;
// }