﻿#include <iostream>
using namespace std;

class MyString
{
	char* str;
	static int count;
    int field = 80;
public:
	MyString()
	{
		str = new char[field];
		count++;
	}
	MyString(const char* text)
	{
		str = new char[strlen(text) + 1];
		strcpy_s(str, strlen(text) + 1, text);
		count++;
	}
	/*MyString(const char* size)
	{
		str = new char[strlen(size) + 1];
		strcpy_s(str, strlen(size) + 1, size);
		count++;
	}*/
    MyString(const MyString& other)
    {
        str = new char[strlen(other.str) + 1];
        strcpy_s(str, strlen(other.str) + 1, other.str);
        count++;
    }
	void input()
	{
		char buffer[256];
		cin.getline(buffer, 256);
		str = new char[strlen(buffer) + 1];
		strcpy_s(str, strlen(buffer) + 1, buffer);
	}
	void output() const
	{
		cout << "String: " << str << endl;
	}

	static int getCount()
	{
		return count;
	}
	~MyString()
	{
		delete[] str;
		count--;
	}
};

int MyString::count = 0;

class Contact
{
    char* name;
    char* lastname;
    char* surname;
    char* phoneNumber;
public:
    Contact() : name(nullptr), lastname(nullptr), surname(nullptr), phoneNumber(nullptr) {}

    Contact(const char* Name, const char* LastName, const char* Surname, const char* PhoneNumber)
    {
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
        lastname = new char[(strlen(LastName) + 1)];
        strcpy_s(lastname, strlen(LastName) + 1, LastName);
        surname = new char[(strlen(Surname) + 1)];
        strcpy_s(surname, strlen(Surname) + 1, Surname);
        phoneNumber = new char[(strlen(PhoneNumber) + 1)];
        strcpy_s(phoneNumber, strlen(PhoneNumber) + 1, PhoneNumber);

    }
    Contact(const Contact& other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);
        lastname = new char[strlen(other.lastname) + 1];
        strcpy_s(lastname, strlen(other.lastname) + 1, other.lastname);
        surname = new char[strlen(other.surname) + 1];
        strcpy_s(surname, strlen(other.surname) + 1, other.surname);
        phoneNumber = new char[strlen(other.phoneNumber) + 1];
        strcpy_s(phoneNumber, strlen(other.phoneNumber) + 1, other.phoneNumber);
    }
    void Set()
    {
        char bufferName[30];
        char bufferLastName[30];
        char bufferSurname[30];
        char bufferPhoneNumber[30];

        cout << "Enter the name: ";
        cin >> bufferName;
        cout << "Enter your lastname: ";
        cin >> bufferLastName;
        cout << "Enter your surname: ";
        cin >> bufferSurname;
        cout << "Enter your phonenumber: ";
        cin >> bufferPhoneNumber;

        name = new char[strlen(bufferName) + 1];
        strcpy_s(name, strlen(bufferName) + 1, bufferName);
        lastname = new char[strlen(bufferLastName) + 1];
        strcpy_s(lastname, strlen(bufferLastName) + 1, bufferLastName);
        surname = new char[(strlen(bufferSurname) + 1)];
        strcpy_s(surname, strlen(bufferSurname) + 1, bufferSurname);
        phoneNumber = new char[(strlen(bufferPhoneNumber) + 1)];
        strcpy_s(phoneNumber, strlen(bufferPhoneNumber) + 1, bufferPhoneNumber);

    }
    void Output()
    {
        if (name == nullptr || lastname == nullptr || surname == nullptr || phoneNumber == nullptr)
        {
            cout << "Not full contact." << endl;
            return;
        }
        cout << "Name: " << name << endl;
        cout << "LastName: " << lastname << endl;
        cout << "Surname: " << surname << endl;
        cout << "Phonenumber: " << phoneNumber << endl;
    }
    ~Contact()
    {

    }
};

Contact* addContact(Contact* contact, int& size, const Contact& newStudent)
{
    Contact* newStudents = new Contact[size + 1];
    for (int i = 0; i < size; i++)
    {
        newStudents[i] = contact[i];
    }
    newStudents[size] = newStudent;
    delete[] contact;
    size++;
    return newStudents;
}

Contact* removeStudent(Contact* сontact, int& size, int index)
{
    if (index < 0 || index >= size)
    {

        cout << "Unknown index: " << index << endl;
        return сontact;
    }
    Contact* newStudents = new Contact[size - 1];
    for (int i = 0; i < index; ++i) {
        newStudents[i] = сontact[i];
    }
    for (int i = index + 1; i < size; ++i) {
        newStudents[i - 1] = сontact[i];
    }
    delete[] сontact;
    size--;
    return newStudents;
}


void printContact(Contact* contact, int size)
{
    for (int i = 0; i < size; i++)
    {
        contact[i].Output();
    }
}


int main()
{
    int size = 1;       //Task1
    Contact* сontact = new Contact[size];
    сontact[0] = { "Dima","Juravskiy","Alekseyovich","0683084312" };
    Contact newContact = { "Bogdan","Pirhavko","Oleksandrovich","0916084933" };
    сontact = addContact(сontact, size, newContact);
    printContact(сontact, size);
    сontact = removeStudent(сontact, size, 0);
    printContact(сontact, size);
    delete[] сontact;

    MyString str;       //Task 2
    str.input();
    str.output();
    cout << "Count: " << str.getCount();

}