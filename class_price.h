#include <string>
using namespace std;

class Price {
private:
	string name;
	string shop_name;
	int cost;
public:
	int get_cost();
	string get_name();
	string get_shop_name();

	void set_cost(int cost);
	void set_name(string name);
	void set_shop_name(string shop_name);

	void print();
};