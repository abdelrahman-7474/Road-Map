#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <limits>
using namespace std;
struct edge
{
	string destination_city;
	int cost;
};
class CountryGraph
{
	bool connected;
	unordered_map<string, int> rank;
	unordered_map<string, list<edge>>cities;
    stack<pair<int,pair<string, list<edge>>>> undoStack;
    stack<pair<int, pair<string, list<edge>>>> redoStack;

public:
	void AddCity(string city);
	void AddEdge(string city_1, string city_2, int cost);
	bool FindCity(string city);
	bool FindEdge(string city_1, string city_2);
	void DisplayGraph();
	void DisplayCities();
	void DisplayEdges();
	void DeleteCity(string city);
	void DeleteEdge(string city_1, string city_2);
	void Delete_AllGraph();
	int Write_Cities_InFiles(string);
	int Write_Edges_InFiles(string);
	int Read_Cities_FromFiles(string);
	int Read_Edges_FromFiles(string);
	void DFS(string start_city);
	void BFS(string start);
	pair<CountryGraph, int> Prims();
	void dijkstra_algorithm(string start_city);
    void Undo();
    void Redo();
    void ApplyUChanges(pair<int, pair<string, list<edge>>>&);
	void ApplyRChanges(pair<int, pair<string, list<edge>>>&);
	void ReAddCity(pair<string, list<edge>>&);
	edge GetEdge(string city_1, string city_2);
	bool applychanges;
	void kruskalMST();
	//int findCityIndex(const string& cityName);
	string findParent(unordered_map<string, string>& parent, const string& city);
	void unionCities(unordered_map<string, string>& parent, unordered_map<string, int>& rank, const string& city1, const string& city2);
	unordered_map<string, unordered_map<string, int>> FloydWarshall();
	bool is_connected();
};

class User
{
public:
	string username;
	string password;
	User(string username, string password);
	void createFiles();
	void removeFiles();

};
