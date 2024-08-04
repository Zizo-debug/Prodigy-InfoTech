#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Contact {
private:
	string name;
	string phone;
	string email;
public:
	Contact()
	{
		name = " ";
		phone = " ";
		email = " ";
	}
	Contact(string Name, string ph, string Email)
	{
		this->name = Name;
		this->email = Email;
		this->phone = ph;
	}
	void viewContact()
	{
		cout << "Name: " << this->name << endl;
		cout << "Email: " << this->email << endl;
		cout << "Phone: " << this->phone << endl<<endl;
	}
	string getName()
	{
		return this->name;
	}
	string getPhone()
	{
		return this->phone;
	}
	string getEmail()
	{
		return this->email;
	}
	void setName(string Name)
	{
		this->name = Name;
	}
	
	void setEmail(string Email)
	{
		this->email = Email;
	}
	void setPhone(string Ph)
	{
		this->phone = Ph;
	}
	~Contact()
	{}
};

class User {
private:
	Contact* list;
	int numOfContacts;
public:
	int getNumContacts()
	{
		return this->numOfContacts;
	}
	User()
	{
		list = nullptr;
		numOfContacts = 0;
	}
	void setValues(Contact* phonebook, int num)
	{
		list = phonebook;
		numOfContacts = num;
	}
	//works 
	void viewContactList()
	{
		fstream fs;
		fs.open("C:/Users/Dell/source/repos/Project1/Project1/test.txt");
		string text;
		int i = 1;
		int sequence_index = 1;
		fs.seekg(0);
		while (getline(fs, text)) {
			if (sequence_index == 1) {
				list[(i - 1) / 3].setName(text); 

			}
			else if (sequence_index == 2) {

				list[(i - 2) / 3].setEmail(text); 
			}
			else if (sequence_index == 3) {
			
				 list[(i - 3) / 3].setPhone(text); 
			}

			sequence_index = (sequence_index % 3) + 1;

			i++;
		}
			
		fs.close();
		for (int i = 0; i < numOfContacts; i++)
		{
			cout <<endl<< "Name: " << list[i].getName() << endl << "Phone: " << list[i].getPhone() << endl << "Email: " << list[i].getEmail() << endl;
		}
	}
	
	//check file handling
	void editExistingContact(int index)
	{
		string temp;
		cout << "Enter name: " << endl;
		cin.ignore();
		getline(cin, temp);
		list[index].setName(temp);
		//delete this
		cout << "Name : " << list[index].getName()<<endl;
		cout << "Enter email: " << endl;
		getline(cin, temp);
		bool isFound = false;
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '@')
			{
				isFound = true;
				break;
			}
		}
			if (isFound)
			{
				list[index].setEmail(temp);	
			}
			else
			{
				while (isFound == false )
				{
					cout << "Enter correct email: " << endl;
					cin.ignore();
					getline(cin, temp);
					for (int i = 0; i < temp.length(); i++)
					{
						if (temp[i] == '@')
						{
							isFound = true;
							if (isFound)
							{
								list[index].setEmail(temp);
						
								
							}
							break;
						}
					}
				}
			}
		cout << "Enter phone: " << endl;
		getline(cin, temp);
		int i = 0;
		while(isdigit(temp[i])== false && i < temp.length())
		{
				cout << "Enter correct phone: " << endl;
				getline(cin, temp);
		}
		
		list[index].setPhone(temp);
		fstream fs1;
		fs1.open("C:/Users/Dell/source/repos/Project1/Project1/test.txt");
		fs1.seekg(0);
		for (int i = 0; i < numOfContacts; i++)
		{
			if (i == numOfContacts - 1)
			{
				fs1 << list[i].getName() << "\n";
				fs1 << list[i].getEmail() << "\n";
				fs1 << list[i].getPhone();
			}
			else
			{
				fs1 << list[i].getName() << "\n";
				fs1 << list[i].getEmail() << "\n";
				fs1 << list[i].getPhone() << "\n";
			}
		}
		fs1.close();
	}

	void addNewContact()
	{
		this->numOfContacts++;
		if (list == nullptr)
		{
			list = new Contact[numOfContacts];
			this->editExistingContact(0);
		}
		else
		{

			Contact* oldList = list;
			list = new Contact[numOfContacts];
			for (int i = 0; i < numOfContacts - 1; i++)
			{
				list[i] = oldList[i];
			}
			this->editExistingContact(numOfContacts - 1);
			for (int i = 0; i < numOfContacts; i++)
			{
				list[i].viewContact();
			}
			delete[] oldList;
		}
	}

	//test filehandling
	void deleteContact(int index)
	{
		///fix this    
		Contact* oldList = list;
		fstream fs1;
		
		for (int i = index; i < numOfContacts-1; i++)
		{
			oldList[i] = oldList[i + 1];
		}

		numOfContacts--;
		list = new Contact[numOfContacts];

		for (int i = 0; i < numOfContacts; i++)
		{
			list[i] = oldList[i];
		}

		for (int i = 0; i < numOfContacts; i++)
		{
			list[i].viewContact();
		}
		fs1.open("C:/Users/Dell/source/repos/Project1/Project1/test.txt");
		fs1.seekg(0);
		for (int i = 0; i < numOfContacts; i++)
		{
			if (i == numOfContacts - 1)
			{
				fs1 << list[i].getName() << "\n";
				fs1 << list[i].getEmail() << "\n";
				fs1 << list[i].getPhone();
			}
			else
			{
				fs1 << list[i].getName() << "\n";
				fs1 << list[i].getEmail() << "\n";
				fs1 << list[i].getPhone() << "\n";
			}
		}
		fs1.close();
		delete[] oldList;
	}
	~User(){}
	
};
//make sure to clear the file after running again

int main()
{
	int choice = 0;
	int index;
	User u1;
	cout << "Your contact list is empty" << endl;
	cout << "Add a new contact: ";
	u1.addNewContact();
	while(choice != 5)
	{ 
		cout << "1. Add More Contacts \t 2. Show Contact List \n 3. Edit Existing Contact \t 4. Delete Contact\n 5.Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			u1.addNewContact();
			break;
		case 2:
			u1.viewContactList();
			break;
		case 3:
			cout << "Which contact? Write the index " << endl;
			cin >> index;
			while (index<0 || index>u1.getNumContacts())
			{
				cout << " Error!, Index doesnt exist, Which contact? Write the index " << endl;
				cin >> index;
			}
			u1.editExistingContact(index);
			break;
		case 4:
			cout << "Which contact? Write the index " << endl;
			cin >> index;
			while (index<0 || index>u1.getNumContacts())
			{
				cout << " Error!, Index doesnt exist, Which contact? Write the index " << endl;
				cin >> index;
			}
			u1.deleteContact(index);
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "Error!"<<endl;
			break;
		}
	}
}