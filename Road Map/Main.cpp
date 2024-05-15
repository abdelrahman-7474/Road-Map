#include "CountryGraph.h"
using namespace std;
string  stringformat(string str) {
	string result = "";
	result += toupper(str[0]);
	for (int i = 1; i < str.size(); i++) {
		result += tolower(str[i]);
	}
	return result;
}
int checkcost(int cost)
{
	while (cost < 0)
	{
		cout << "cost must be nonnegative number "<<endl;
		cout << "please Enter postive number for cost :";
		cin >> cost;
	}
	return cost;
		

}
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
	cout << "Enter 9 to Display DFS" << endl;
	cout << "Enter 10 to Display BFS" << endl;
	cout << "Enter 11 to Display MSP" << endl;
	cout << "Enter 12 to Display Dijkstra algorithm" << endl;
	cout << "Enter 13 to Undo" << endl;
	cout << "Enter 14 to Redo" << endl;
	cout << "Enter 15 to display the kruskal MST algorithm" << endl;
	cout << "Enter 16 to FloydWarshall Algorithm" << endl;
	cout << "Enter 17 to check graph connectivity" << endl;
	cout << "Enter 0 to End program " << endl;
}
void operation_switch(int operation_number, UserGraph* user)
{
	CountryGraph Country = user->graph;
	
	switch (operation_number)
	{
	case 0:
	{
		cout << "logout successfully " << endl;
		break;
	}
	case 1:
	{
		string city;
		cout << "Enter added city name :";
		cin >> city;
		Country.AddCity(stringformat(city));
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
		cout << "Enter cost of the road (Hint : cost must be nonnegative):";
		cin >> cost;
		cost = checkcost(cost);
		Country.AddEdge(stringformat(city_1), stringformat(city_2), cost);
		cout << "Edge between City " << city_1 << " and City " << city_2 << " with cost " << cost << " Added successfully" << endl;
		break;
	}
	case 3:
	{
		string city;
		cout << "Enter city name to search :";
		cin >> city;
		if (Country.FindCity(stringformat(city)))
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
				Country.AddCity(stringformat(city));
			}
		}
		break;
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
		if (Country.FindEdge(stringformat(city_1), stringformat(city_2)))
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
				Country.AddEdge(stringformat(city_1), stringformat(city_2), cost);
			}
		}
		break;
	}
	case 5:
	{
		string deletecity;
		cout << "Enter name of Deleted city : ";
		cin >> deletecity;
		if (Country.FindCity(stringformat(deletecity)))
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
		if (Country.FindEdge(stringformat(city_1), stringformat(city_2)))
		{
			Country.DeleteEdge(stringformat(city_1), stringformat(city_2));
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
		cout << "All Graph Deleted successfully "<<endl;
		break;
	}
	case 8:
	{
		if (!Country.is_graphempty()) {
			cout << "Display Graph :" << endl;
			Country.DisplayGraph();
			cout << "All Graph Displayed " << endl;
		}
		else
			cout << "Graph is empty " << endl;
		break;
	}
	case 9:
	{
		string start_city;
		cout << "Enter start city " << endl;
		cin >> start_city;
		if (Country.FindCity(stringformat(start_city))) {
		cout << "Display DFS : " << endl;
		Country.DFS(stringformat(start_city));
		cout << "DFS is display" << endl;
		}
		else
		{
			cout << "Start City not in Graph" << endl;
		}
		break;
	}
	case 10: 
	{
		string start_city;
		cout << "Enter start city " << endl;
		cin >> start_city;
		if (Country.FindCity(stringformat(start_city))) {
			cout << "Display BFS : " << endl;
			Country.BFS(stringformat(start_city));
			cout << "BFS is display" << endl;
		}
		else
		{
			cout << "Start City not in Graph" << endl;
		}
		break;
	}
	case 11:
	{
		if (!Country.is_graphempty()) {
			if (Country.is_connected()) {
				cout << "Display msp :" << endl;
				pair<CountryGraph, int> msp = Country.Prims();
				cout << "total cost: " << msp.second << endl;
				cout << "msp Displayed ";
			}
			else
			{
				cout << "you canot use prims algorithm with unconnected graph you can use kruskal algorithm "<<endl;
			}
		}
		else
			cout << "Graph is empty" << endl;
		break;
	}
	case 12:
	{
		
		cout << "Enter the start city"<<endl;
		string first_city;
		cin >> first_city;
		if (Country.FindCity(stringformat(first_city))) {
			Country.dijkstra_algorithm(stringformat(first_city));
			cout << "Dijkstra’s algorithm displayed successfully" << endl;
		}
		else
		{
			cout << "start city not in graph " << endl;
		}
		break;
	}
	case 13:
	{
		Country.Undo();
		cout << "Operation done successfully";
		break;
	}
	case 14:
	{

		Country.Redo();
		cout << "Operation done successfully";
		break;
	}
	case 15: 
	{
		if (!Country.is_graphempty()) {
			cout << "The Kruskal MST Algorithm display is: " << endl;
			Country.kruskalMST();
		}
		else
		{
			cout << "start city not in graph " << endl;
		}
		break;
	}
	case 16:
	{
		//FloydWarshall Algorithm
		string start_city;
		cout << "Enter the first city: ";
		cin >> start_city;
		string dist_city;
		cout << "Enter the second city: ";
		cin >> dist_city;
		if (Country.FindCity(stringformat(start_city)) && Country.FindCity(stringformat(dist_city)))
		{
			unordered_map<string, unordered_map<string, int>> dist = Country.FloydWarshall();
			int distance = dist[stringformat(start_city)][stringformat(dist_city)];
			cout << endl << "The distance:  " << distance << endl;
		}
		else
		{
			cout << "first city or second city not in graph" << endl;
		}
		break;
	}
	case 17:
	{
		if (!Country.is_graphempty())
		{
			if (Country.is_connected())
				cout << "All Grpah connected" << endl;
			else
				cout << "Graph disconnected" << endl;
			break;
		}
		else
		{
			cout << "Graph is empty"<<endl;
		}
	}
	default:
	{
		cout << "invalid operation number"<<endl;
		break;
	}
	}
	user->graph = Country;
}
void chooseOperation()
{
	cout << "Enter 1 to sign up" << endl;
	cout << "Enter 2 to log in" << endl;
	cout << "Enter 3 to display graphs names " << endl;
	cout << "Enter 4 to delete graph " << endl;
	cout << "enter 0 to exit" << endl;
}
UserGraph* userOperation(UserManager& manager, int operationNum, UserGraph* currentUser)
{
	switch (operationNum)
	{
	case 0:
	{
		cout << "program closed" << endl;
		break;
	}
	case 1:
	{
		manager.signUp();
	}
	case 2:
	{
		currentUser = manager.logIn();
		break;
	}
	case 3:
	{
		manager.display();
		currentUser = nullptr;
		break;
	}
	case 4:
	{
		manager.deleteGraph();
		currentUser = nullptr;
		break;
	}
	default: {
		currentUser = nullptr;
		break;
	}
	}
	return currentUser;
}
int main()
{
	UserManager manager;
	UserGraph* curretnuser = nullptr;
	manager.loadUsers();
	manager.loadAllGraphs();
	int operationNum = -1;
	cout << "\t\t\t--------------------- HI you are in ROAD MAP PROJECT -------------------" << endl;
	while (operationNum)
	{
		chooseOperation();
		cout << "enter operation number: ";
		cin >> operationNum;
		curretnuser = userOperation(manager, operationNum, curretnuser);
		if (curretnuser != nullptr && operationNum != 0) {
			int opNum = -1;
			while (opNum) {
				MainMenu();
				cout << "Enter your operation number : ";
				cin >> opNum;
				operation_switch(opNum, curretnuser);
			}
		}
	}
	cout << "\t\t\t--------------------- ROAD MAP program End bye bye user -------------------" << endl;
	manager.saveAllGraphs();
	manager.saveUsres();

}
