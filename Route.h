#pragma once
#include <vector>
using std::vector;
#include<fstream>
#include<iostream>
using std::cout;
using std::cin;
#include<string>
using std::string;
#include<sstream>
#include<iterator>
#include<algorithm>
#include <map> 
#include <set> 
class Route
{
public:
	Route();
	~Route();
	std::string GetDriver() { return driver; }
	Route& operator=(const std::string& s) { driver = s; return*this; }
	size_t GetNumberOfRoute()const { return numberOfRoute; }
	friend vector<Route> Collect(vector<vector<string>> Bus);
	Route(std::pair<size_t, string> Bus_, string driver_, size_t numberOfRoute_) : Bus(Bus_), driver(driver_), numberOfRoute(numberOfRoute_) {};
	friend std::ostream& operator<<(std::ostream& out, const Route& r);
private:
	std::pair<size_t, string> Bus;
	string driver;
	size_t numberOfRoute;

};

Route::Route()
{
}

Route::~Route()
{
}

vector<vector<string>> BusRoutes;
void ReadData(string filename)
{
	std::ifstream in(filename);
	string str;
	while (std::getline(in, str))
	{
		std::istringstream ss(str);
	
	vector<string> temp;
	while (ss>>str)
	{
		temp.push_back(str);
	}

	BusRoutes.push_back(temp);
    }
}

vector<Route> Collect(vector<vector<string>> Bus)
{
	vector<Route> result(Bus.size());
	std::transform(Bus.begin(), Bus.end(), result.begin(),
		[](vector<string> obj)
	{
		return Route(std::make_pair(stoi(obj[2]), obj[3]), obj[1], stoi(obj[0]));
	});
	return result;
}

std::ostream& operator<<(std::ostream& out, const Route& r)
{
	out << r.Bus.first << " " << r.Bus.second << " " << r.driver << " " << r.numberOfRoute << " \n";
	return out;
}
 std::multimap<size_t, Route>CreateMap( std::vector<Route>&vector)
{
	std::multimap<size_t, Route>result;
	std::transform(vector.begin(), vector.end(), std::inserter(result,result.begin())  , [](Route& obj)
	{
		return std::make_pair(obj.GetNumberOfRoute(), obj);
	}
	);



	return result;

}
std::set<size_t>ListOfRouts( std::vector<Route>&vector)
{
	std::set<size_t>result;
	std::transform(vector.begin(), vector.end(), 
		std::inserter(result, result.begin()), [](Route& obj)
	{
		return obj.GetNumberOfRoute();
	}
	);
	return result;
}

void ListOfBusesByRout(std::multimap<size_t, Route> container, int rout)
{
	std::multimap<size_t, Route>::iterator it, it1;
	
	
	it = container.lower_bound(rout);//ищет первое вхождение ключа и возвращает итератор
	it1 = container.upper_bound(rout);//ищет последнее вхождение ключа и возвращает итератор
	//если первое вхождение ключа не найдено - выходим
	if (it == container.end())
	{
		cout << "No such key\n";
		return;
	}
	std::copy(it, it1, std::ostream_iterator<std::pair<size_t, Route>>(cout, " "));


}
void DeleteByRout(std::multimap<size_t, Route> &container,const int rout)
{
	container.erase(rout);
}
void ReplaceDriverOnTheRoute(std::vector<Route>&v, size_t route, std::string driver, const std::string &newdriver)
{
	std::replace_if(v.begin(), v.end(), [route, driver](Route& obj) {if (obj.GetNumberOfRoute() == route && obj.GetDriver() == driver) { return 1; }}, newdriver);
}
size_t MaxBusesOnRoute(std::vector<Route>r)
{
	std::sort(r.begin(), r.end(), [](Route& obj1,Route& obj2) 
	{return obj1.GetNumberOfRoute() <= obj2.GetNumberOfRoute(); });
	std::multimap<size_t, size_t>map;
	int count=0,number;
	std::transform(r.begin(), r.end(),
		std::inserter(map, map.begin()), [ &count  ](Route& obj)
	    {
		number = obj.GetNumberOfRoute();
		if ()
		{

		}
	    }
	);
}