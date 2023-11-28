// to run it 
// cd /Users/nikhilswami/Downloads/Projects/C++/Inventory\ Management\ System
// g++ -std=c++17 Beta2.cpp -o Beta2

#include <iostream>
#include <math.h>
#include <unordered_map>
#include <fstream>    // used for saving or loading something from memory
#include <filesystem> // get info about directory and locations

namespace fs = std::filesystem;
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
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        if (inventory.count(name) > 0)
        {
            Item &item = inventory[name];
            cout << "There is an entry for " << name << " in the inventory with price $" << item.Price << endl;
            cout << "Do you want to update the price or add the quantity to the existing entry?" << endl;
            cout << "1. Add quantity to the existing entry" << endl;
            cout << "2. Update the Inventory with new price Item" << endl;
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            while (cin.fail() || (choice != 1 && choice != 2))
            {
                cin.clear();
                while (cin.get() != '\n')
                {
                    continue;
                };
                cout << "Invalid choice. Please enter 1 or 2: ";
                cin >> choice;
            }

            if (choice == 1)
            {
                item.Quantity += quantity;
                cout << quantity << " " << name << "'s added to inventory. *.*" << endl;
            }
            else if (choice == 2)
            {
                Item newItem(name, quantity, price);
                inventory[name] = newItem;
                cout << quantity << " " << name << "'s added to inventory. *.*" << endl;
            }
        }
        else
        {
            Item newItem(name, quantity, price);
            inventory[name] = newItem;
            cout << quantity << " " << name << "'s added to inventory. *.*" << endl;
        }
    }

    void RemoveItem(string name)
    {
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        if (inventory.count(name) > 0)
        {
            inventory.erase(name);
            cout << name << " has been completely removed from the inventory." << endl;
        }
        else
        {
            cout << name << " does not exist in inventory." << endl;
        }
    }

    void Report()
    {
        cout << "Inventory Report:" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Item\t\tQuantity\tPrice" << endl;
        cout << "----------------------------------------------" << endl;
        for (const auto &pair : inventory)
        {
            const string &name = pair.first;
            const Item &item = pair.second;
            cout << name << "\t\t" << item.Quantity << "\t\t$" << item.Price << endl;
        }
        cout << "----------------------------------------------" << endl;
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

    void SaveInventory(string filename)
    {
        string currentFolderPath = "/Users/nikhilswami/Downloads/Study/Projects/C++/Inventory Management System";
        fs::path location(currentFolderPath);

        string FullPath = (location / (filename + ".txt")).string();
        ofstream file(FullPath);

        if (file.is_open())
        {
            file << "Item\t\tQuantity\tPrice" << endl;
            file << "----------------------------------------------" << endl;

            for (const auto &pair : inventory)
            {
                const string &name = pair.first;
                const Item &item = pair.second;
                file << name << "\t\t" << item.Quantity << "\t\t$" << item.Price << endl;
            }

            file << "----------------------------------------------" << endl;
            cout << "Inventory data Saved to " << FullPath << "." << endl;
        }
        else
        {
            cout << "Unable to save File." << endl;
        }
        file.close();
    }

    void LoadInventory(string filename)
    {
        string currentFolderPath = "/Users/nikhilswami/Downloads/Study/Projects/C++/Inventory Management System";
        fs::path location(currentFolderPath);
        string FullPath = (location / (filename + ".txt")).string();
        ifstream file(FullPath);

        if (file.is_open())
        {
            inventory.clear();

            string line;
            getline(file, line);

            while (getline(file, line))
            {
                size_t pos1 = line.find("\t\t");
                string name = line.substr(0, pos1);
                line.erase(0, pos1 + 2);

                size_t pos2 = line.find("\t\t");
                int quantity;
                try
                {
                    quantity = stoi(line.substr(0, pos2));
                }
                catch (const invalid_argument &e)
                {
                    continue;
                }
                line.erase(0, pos2 + 2);

                double price;
                try
                {
                    price = stod(line.substr(1));
                }
                catch (const invalid_argument &e)
                {
                    continue;
                }
                Item item(name, quantity, price);
                inventory[name] = item;
            }
            cout << "Inventory Data Loaded from " << filename << "." << endl;
        }
        else
        {
            cout << "Unable to open File" << endl;
        }
        file.close();
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
        cout << "5. Save Inventory to file" << endl;
        cout << "6. Load Inventory from file" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice what you want to do (1-7)" << endl;

        if (!(cin >> choice))
        {
            cout << "Incorrect input. Please enter a valid choice." << endl;
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            };
            continue;
        }

        if (choice < 1 || choice > 7)
        {
            cout << "Incorrect input. Please enter a valid choice." << endl;
            continue;
        }

        string name;
        int quantity;
        double price;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Item's name : " << endl;
            cin >> name;
            cout << "Enter Item quantity you want to add : " << endl;
            cin >> quantity;
            cout << "Enter the Price : " << endl;
            cin >> price;

            inventory.AddItem(name, quantity, price);

            break;
        }
        case 2:
        {
            cout << "Enter Item's name : " << endl;
            cin >> name;
            cout << "Enter Item quantity you want to remove : " << endl;
            cin >> quantity;

            inventory.RemoveItem(name);

            break;
        }
        case 3:
        {
            inventory.Report();
            break;
        }
        case 4:
        {
            cout << "Enter Name of Item : " << endl;
            cin >> name;
            cout << "Enter Sold Quantity : " << endl;
            cin >> quantity;

            inventory.SoldItem(name, quantity);

            break;
        }
        case 5:
        {
            cout << "Enter Filename to save" << endl;
            cin >> name;

            inventory.SaveInventory(name);

            break;
        }
        case 6:
        {
            cout << "Enter Filename to load" << endl;
            cin >> name;

            inventory.LoadInventory(name);

            break;
        }
        case 7:
        {
            return 0;
        }
        default:
        {
            cout << "This is Beta Version & made for testing and feedback purpose. if you want to suggest some features feel free to send us your response. Thank You! *.*" << endl;
            break;
        }
        }
    }

    return 0;
}