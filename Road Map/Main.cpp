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
void operation_switch(int operation_number, CountryGraph& Country)
{
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
	case 9:
	{
		string start_city;
		cout << "Enter start city " << endl;
		cin >> start_city;
		cout << "Display DFS : " << endl;
		Country.DFS(stringformat(start_city));
		cout << "DFS is display" << endl;
		break;
	}
	case 10: 
	{
		string start_city;
		cout << "Enter start city " << endl;
		cin >> start_city;
		cout << "Display BFS : " << endl;
		Country.BFS(stringformat(start_city));
		cout << "BFS is display" << endl;
		break;
	}
	case 11:
	{
		
		cout << "Display msp :" << endl;
		pair<CountryGraph, int> msp = Country.Prims();
		cout << "total cost: " << msp.second << endl;
		cout << "msp Displayed ";
		break;
	}
	case 12:
	{
		
		cout << "Enter the start city"<<endl;
		string first_city;
		cin >> first_city;
		Country.dijkstra_algorithm(stringformat(first_city));
		cout << "Dijkstra’s algorithm displayed successfully" << endl;
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
		cout << "The Kruskal MST Algorithm display is: " << endl;
		Country.kruskalMST();
		break;
	}
	case 16:
	{
		//FloydWarshall Algorithm
		string start_city;
		cout << "Enter the start ciry: ";
		cin >> start_city;
		string dist_city;
		cout << "Enter the start ciry: ";
		cin >> dist_city;
		unordered_map<string, unordered_map<string, int>> dist = Country.FloydWarshall();
		int distance = dist[stringformat(start_city)][stringformat(dist_city)];
		cout << endl << "The distance:  " << distance << endl;
		break;
	}
	case 17:
	{
		if (Country.is_connected())
			cout << "All Grpah connected" << endl;
		else
			cout << "Graph disconnected" << endl;
		break;
	}
	default:
	{
		cout << "invalid operation number"<<endl;
		break;
	}
	}
}
void ReadFormFiles(CountryGraph& Country,string user)
{
	Country.Read_Cities_FromFiles(user);
	Country.Read_Edges_FromFiles(user);
}
void WriteInFiles(CountryGraph& Country,string user)
{
	Country.Write_Cities_InFiles(user);
	Country.Write_Edges_InFiles(user);
}
void ReadUsers(vector<User>&users)
{
	string filename = "users.txt";
	ifstream infile(filename);
	if (!infile.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return ;
	}

	string line;
	while (getline(infile, line)) {
		vector<string> data_tokens;
		string token;
		istringstream tokenStream(line);
		while (getline(tokenStream, token, ',')) {
			data_tokens.push_back(token);
		}

		if (data_tokens.size() == 2)
		{
			User user(data_tokens[0], data_tokens[1]);
			users.push_back(user);
		}
	}
	infile.close();
}
void WriteUsers(vector<User>&users)
{
	string filename = "users.txt";
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return ;
	}
	for (int i = 0; i < users.size(); i++)
	{
		outfile << users[i].username << "," << users[i].password << endl;
	}
	outfile.close();
}
void userMenu()
{
	cout << "Enter 1 to create graph\n";
	cout << "Enter 2 to display all graphs\n";
	cout << "Enter 3 to log in into graph\n";
	cout << "Enter 4 to delete graph\n";
	cout << "Enter 0 to close the program\n";
}
int main()
{
	vector<User>users;
	ReadUsers(users);
	int userOperationNumber = -1;
	cout << "\t\t\t--------------------- HI you are in ROAD MAP PROJECT -------------------" << endl;

	while (userOperationNumber)
	{
		userMenu();
		cout << "choose your operation: ";
		cin >> userOperationNumber;
		switch (userOperationNumber)
		{
		case 0:
		{
			cout << "program has closed" << endl;
			break;
		}
		case 1:
		{
			string username;
			string password;
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;
			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].username == stringformat(username))
				{
					cout << "graph already exist" << endl;
					break;
				}
			}
			User user(stringformat(username), password);
			users.push_back(user);
			user.createFiles();
			break;
		}
		case 2:
		{
			for (int i = 0; i < users.size(); i++)
			{
				cout << users[i].username << endl;
			}
			break;
		}
		case 3:
		{
			string username;
			string password;
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;
			bool flage = false;
			for (int i = 0; i < users.size(); i++)
			{
				
				if (users[i].username == stringformat(username) && users[i].password == password)
				{
					flage = true;
					CountryGraph Country;
					Country.applychanges = false;
					ReadFormFiles(Country, stringformat(username));
					Country.applychanges = true;
					int operation_number=-1;
					while (operation_number)
					{
						MainMenu();
						cout << "Enter your operation number : ";
						cin >> operation_number;
						operation_switch(operation_number, Country);
					}
					WriteInFiles(Country, stringformat(username));
					break;
				}
			}
			if(!flage)
			cout << "can not find user, check username or password" << endl;
			break;
		}
		case 4:
		{
			string username;
			string password;
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;
			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].username == stringformat(username) && users[i].password == password)
				{
					users[i].removeFiles();
					users.erase(users.begin() + i);
					break;
				}
			}
			break;
		}
		default:
			cout << "invalid operation" << endl;
			break;
		}
	}
	cout << "\t\t\t--------------------- ROAD MAP program End bye bye user -------------------"<<endl;
	WriteUsers(users);
}
