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


multimap<int, string> nums = {
  { 1, "адзін" },
  { 1, "один" },
  { 1, "one" },
  { 2, "два" },
  { 2, "two" },
  { 3, "тры" },
  { 3, "три" },
  { 3, "three" },
  { 4, "чатыры" },
  { 4, "четыре" },
  { 4, "four" } };

//it - встроенный в multimap итератор
multimap<int, string>::iterator it, it1;
int key;
cout << "Enter key";
cin >> key;
it = nums.lower_bound(key);//ищет первое вхождение ключа и возвращает итератор
it1 = nums.upper_bound(key);//ищет последнее вхождение ключа и возвращает итератор
//если первое вхождение ключа не найдено - выходим
if (it == nums.end())
{
	cout << "No such key\n";
	return 0;
}
std::copy(it, it1, std::ostream_iterator<std::pair<int, string>>(cout, " "));
 }
 break;
