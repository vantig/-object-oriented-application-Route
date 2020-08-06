#include"Route.h"

//std::ostream& operator<<(std::ostream& out, const vector<string> v)
//{
//	std::copy(v.begin(), v.end(), std::ostream_iterator<string>(out, " "));
//	return out;
//}
std::ostream& operator<<(std::ostream& out, const std::pair<size_t, Route>&p)
{
	out<<" first "<<p.first<<" second "<<p.second;
	return out;
}
int main()
{
	setlocale(0, "");
	ReadData("Text.txt");
	vector<Route> Routes;
	Routes = Collect(BusRoutes);
	/*std::multimap<size_t,Route>*/std::multimap<size_t,Route> container = CreateMap(Routes);
	std::copy(container.begin(), container.end(), std::ostream_iterator<std::pair<size_t, Route>>(cout, "\n"));

	DeleteByRout(container, 40);
	std::cout << "-----------------------------------------"<<std::endl;
	std::copy(container.begin(), container.end(), std::ostream_iterator<std::pair<size_t, Route>>(cout,"\n"));

	///*std::copy(BusRoutes.begin(), BusRoutes.end(), std::ostream_iterator <vector<string>>(cout, "\n"));*/
	//for (size_t i = 0; i < BusRoutes.size(); i++)
	//{
	//	cout << BusRoutes[i] << "\n";
	//}

	return 0;
}