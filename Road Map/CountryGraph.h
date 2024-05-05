#include<unordered_map>
#include<list>
#include<string>
using namespace std;
struct edge
{
	string destination_city;
	int cost;
};
class CountryGraph
{
	unordered_map<string, list<edge>>cities;
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
	int Write_Cities_InFiles();
	int Write_Edges_InFiles();
	int Read_Cities_FromFiles();
	int Read_Edges_FromFiles();
	void DFS(string start_city);
	void BFS(string start);
	pair<CountryGraph, int> Prims();
	void dijkstra_algorithm(string start_city);
};