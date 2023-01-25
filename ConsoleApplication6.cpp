#include <iostream>
struct info {
	std::string city;
	std::string street;
	int number;
	int index;
};
void end(std::string cit,std::string stree,int numbe,int inde) {
	std::cout << "city: "<<cit<<"\n";
	std::cout << "street: "<<stree<<"\n";
	std::cout << "number: "<<numbe<<"\n";
	std::cout << "index: "<<inde<<"\n";
}
int main(int argc, char** argv) {
	info pers;
	pers.city = "Bishkek";
	pers.street = "Chuy pr.";
	pers.number = 47;
	pers.index = 735920572;
	end(pers.city,pers.street,pers.number,pers.index);
}