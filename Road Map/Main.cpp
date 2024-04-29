#include<iostream>
#include "CountryGraph.h"
using namespace std;
void MainMenu()
{
	cout << "\t\t\t--------------------- Main Menu ------------------- :" << endl;
	cout << "Enter 1 to Add new city" << endl;
	cout << "Enter 2 to Add new Edge" << endl;
	cout << "Enter 3 to Find City" << endl;
	cout << "Enter 4 to Find Edge " << endl;
	cout << "Enter 5 to Delete City " << endl;
	cout << "Enter 6 to Delete Edge " << endl;
	cout << "Enter 7 to Delete all Graph " << endl;
	cout << "Enter 8 to Display all Graph " << endl;
	cout << "Enter 0 to End program " << endl;
}
void operation_switch(int operation_number, CountryGraph& Country)
{
	switch (operation_number)
	{
	case 1:
	{
		string city;
		cout << "Enter added city name :";
		cin >> city;
		Country.AddCity(city);
		cout << "City " << city << " Added successfully" << endl;
		break;
	}
	case 2:
	{
		string city_1;
		string city_2;
		int cost;
		cout << "Enter name of first destination city :";
		cin >> city_1;
		cout << "Enter name of second destination city :";
		cin >> city_2;
		cout << "Enter cost of the road :";
		cin >> cost;
		Country.AddEdge(city_1, city_2, cost);
		cout << "Edge between City " << city_1 << "and City " << city_2 << " with cost " << cost << " Added successfully" << endl;
		break;
	}
	case 3:
	{
		string city;
		cout << "Enter city name to search :";
		cin >> city;
		if (Country.FindCity(city))
		{
			cout << "City Founded " << endl;
		}
		else
		{
			int choosenumber;
			cout << "City not Founded" << endl;
			cout << "Enter 1 to add city to Graph and any other number to back to Main menu : ";
			cin >> choosenumber;
			if (choosenumber == 1)
			{
				Country.AddCity(city);
			}
		}

	}
	case 4:
	{
		string city_1;
		string city_2;
		int cost;
		cout << "Enter name of first destination city :";
		cin >> city_1;
		cout << "Enter name of second destination city :";
		cin >> city_2;
		cout << "Enter cost of the road :";
		cin >> cost;
		if (Country.FindEdge(city_1, city_2))
		{
			cout << "Edge between City" << city_1 << "and City " << city_2 << " Founded successfully" << endl;
		}
		else
		{
			int choosenumber;
			cout << "Edge not Founded" << endl;
			cout << "Enter 1 to add Edge between city " << city_1 << "and city 2" << city_2 << " to Graph and any other number to back to Main menu : ";
			cin >> choosenumber;
			if (choosenumber == 1)
			{
				Country.AddEdge(city_1, city_2, cost);
			}
		}
		break;
	}
	case 5:
	{
		string deletecity;
		cout << "Enter name of Deleted city : ";
		cin >> deletecity;
		if (Country.FindCity(deletecity))
		{
			Country.DeleteCity(deletecity);
			cout << "City " << deletecity << " Deleted  successfully" << endl;
		}
		else
		{
			cout << "City not Founded you cant delete it " << endl;
		}
		break;
	}
	case 6:
	{
		string city_1;
		string city_2;
		int cost;
		cout << "Enter name of first destination city at deleted edge :";
		cin >> city_1;
		cout << "Enter name of second destination city at deleted edge :";
		cin >> city_2;
		cout << "Enter cost of deleted edge :";
		cin >> cost;
		if (Country.FindEdge(city_1, city_2))
		{
			Country.DeleteEdge(city_1, city_2);
			cout << "Edge between City " << city_1 << "and City " << city_2 << " with cost " << cost << " deleted successfully" << endl;
		}
		else
		{
			cout << "Edge not Founded you cant delete it " << endl;
		}
		break;
	}
	case 7:
	{
		Country.Delete_AllGraph();
		cout << "All Graph Deleted successfully ";
		break;
	}
	case 8:
	{
		cout << "Display Graph :" << endl;
		Country.DisplayGraph();
		cout << "All Graph Displayed ";
		break;
	}
	default:
	{
		cout << "invalid operation number";
		break;
	}
	}
}
void ReadFormFiles(CountryGraph& Country)
{
	Country.Read_Cities_FromFiles();
	Country.Read_Edges_FromFiles();
}
void WriteInFiles(CountryGraph& Country)
{
	Country.Write_Cities_InFiles();
	Country.Write_Edges_InFiles();
}
int main()
{

	cout << "\t\t\t--------------------- HI you are in ROAD MAP PROJECT -------------------" << endl;
	CountryGraph Country;
	ReadFormFiles(Country);
	int operation_number;
	while (true)
	{
		MainMenu();
		cout << "Enter your operation number : ";
		cin >> operation_number;
		if (operation_number)
			operation_switch(operation_number, Country);
		else
			break;
	}
	WriteInFiles(Country);
	cout << "\t\t\t--------------------- ROAD MAP program End bye bye user -------------------<<endl";
}
