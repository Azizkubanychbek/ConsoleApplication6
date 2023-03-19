
#include <iostream>
class bad_length:std::exception{
public://const char* what() const override { return "Ошибка создания фигуры"; }
	  bad_length(const std::string& error_message) : error_message_(error_message) {}

	  const char* what() const noexcept override {
		  return error_message_.c_str();
	  }

private:
	std::string error_message_;
};
void thr(std::string g) {

		throw bad_length(g);
}
class Figure {
public:
	Figure() {}
	virtual void print_info() const {
		std::cout << "Name : Figure\n";
		if (check() == true) {
			std::cout << "Sides : a = " << a << " b = " << b << " c = " << c << std::endl;
			std::cout << "Corners : A = " << A << " B = " << C << " C = " << C << std::endl;
			std::cout << "\n";
		}
		else {
			thr("Error: Неправиьная фигура");
		}
	}
	bool check() const {

		return true;

		
	}
protected:

	int a, b, c;
	int A, B, C;
};
class Triangle :public Figure {
public:
	Triangle() {}
	Triangle(int a, int b, int c, int A, int B, int C) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;

	}
	void print_info() const override {
		std::cout << "Name : Triangle\n";
		if (check() == true) {
			std::cout << "Правильный трегуольник";
			std::cout << "Sides : a = " << a << " b = " << b << " c = " << c << std::endl;
			std::cout << "Corners : A = " << A << " B = " << B << " C = " << C << std::endl;
			std::cout << "\n";
		}
		else {
			thr("Error: Сумма  углов не равна 180");
		}
	}
	bool check() const {
		if (A + B + C == 180) {
			return true;
		}
		else {
		
			return false;
		}
	}

};
class Quadrate :public Figure {
public:
	Quadrate() {}
	Quadrate(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->d = d;


	}
	void print_info() const override {
		std::cout << "Name : Quadrate\n";
		if (check() == true) {
			std::cout << "Правильный quadrate";
			std::cout << "Sides : a = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
			std::cout << "Corners : A = " << A << " A = " << B << " C = " << C << " D = " << D << std::endl;
			std::cout << "\n";
		}
		else {
			thr("Error: Heправильный четырехугол cумма не равна 360\n");
		}
		
	}
	bool check() const {
			if (A + B + C + D == 360) {

				return true;
			}
			else {
				return false;
			}
		//catch (const bad_length& ex) { std::cout << ex.what() <<  << std::endl; }
		

	}

protected:
	int d;
	int D;

};
class Prtr :public Triangle {
public:

	Prtr(int a, int b, int c, int A, int B) :Triangle(a, b, c, A, B, C = 90)
	{

	}
	void print_info() const override {

		std::cout << "Name : Prtr\n";
		if (check() == true) {
			std::cout << "Sides : a = " << a << " b = " << b << " c = " << c << std::endl;
			std::cout << "Corners : A = " << A << " A = " << B << " C = " << C << std::endl;
			std::cout << "\n";
		}
		else {
			thr("Error: Сумма  углов не равна 180");
		}
	}

};
class Rbtr :public Triangle {
public:


	Rbtr(int a, int b, int A, int B) :Triangle(a, b, c = a, A, B, C = A)
	{

	}
	void print_info() const override {
		std::cout << "Name : Rbtr\n";
		if(check()==true){
		std::cout << "Sides : a = " << a << " b = " << b << " c = " << c << std::endl;
		std::cout << "Corners : A = " << A << " A = " << B << " C = " << C << std::endl;
		std::cout << "\n";
		}
		else {
			thr("Error: Сумма  углов не равна 180");
		}
	}

};
class Rtr :public Triangle {
public:


	Rtr(int a) :Triangle(a, a, a, 60, 60, 60)
	{
	}
	void print_info() const override {
		std::cout << "Name : Rtr\n";
		if (check() == true) {
			std::cout << "Sides : a = " << a << " b = " << b << " c = " << c << std::endl;
			std::cout << "Corners : A = " << A << " A = " << B << " C = " << C << std::endl;
			std::cout << "\n";
		}
		else {
			thr("Error: Сумма углов не равна 180");
		}
	}

};
class Prmu :public Quadrate {
public:
	Prmu(int a, int b) :Quadrate(a, b, a, b, 90, 90, 90, 90) {

	}
	void print_info() const override {
		std::cout << "Name : Prmu\n";
		if(check()==true){
		std::cout << "Sides : a = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
		std::cout << "Corners : A = " << A << " A = " << B << " C = " << C << " D = " << D << std::endl;
		std::cout << "\n";}
		else {
			thr("Error: Heправильный четырехугол cумма не равна 360\n");
		}
	}
};
class Kv :public Quadrate {
public:
	Kv(int a) :Quadrate(a, a, a, a, 90, 90, 90, 90) {}
	void print_info() const override {
		std::cout << "Name : Kv\n";
		if(check()==true){
		std::cout << "Sides : a = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
		std::cout << "Corners : A = " << A << " A = " << B << " C = " << C << " D = " << D << std::endl;
		std::cout << "\n";}
		else {
			thr("Error: Heправильный четырехугол cумма не равна 360\n");
		}
	}
};
class Par :public Quadrate {
public:
	Par(int a, int b, int A, int B) :Quadrate(a, b, a, b, A, B, A, B) {}
	void print_info() const override {
		std::cout << "Name : Par\n";
		if(check()==true){
		std::cout << "Sides : a = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
		std::cout << "Corners : A = " << A << " A = " << B << " C = " << C << " D = " << D << std::endl;
		std::cout << "\n";}
		else {
			thr("Error: Heправильный четырехугол cумма не равна 360\n");
		}
	}
};
class Rm :public Quadrate {
public:
	Rm(int a, int A, int B) :Quadrate(a, a, a, a, A, B, A, B) {}
	void print_info() const override {
		std::cout << "Name : Rm\n";
		if(check()==true){
		std::cout << "Sides : a = " << a << " b = " << a << " c = " << c << " a = " << d << std::endl;
		std::cout << "Corners : A = " << A << " A = " << B << " C = " << A << " D = " << B << std::endl;
		std::cout << "\n";}
		else {
			thr("Error: Heправильный четырехугол cумма не равна 360\n");
		}
	}
};
void print_info(const Figure* figure) {
	figure->print_info();
}

int main()
{
	/*Triangle triangle(10, 20, 30, 40, 50, 60);
	Prtr prtr(29, 39, 59, 21, 33);
	//Rbtr rbtr(10, 20, 20, 10);
	Rtr rtr(15);
	Quadrate quadrate(10, 20, 30, 40, 50, 60, 70, 80);
	Prmu prmu(10, 20);
	Kv kv(20);
	Par par(10, 12, 60, 30);*/
	//Rm rm(10, 30, 60);
	//Rm* rm = new Rm(10, 30, 60);
	Rbtr* rbtr = new Rbtr(10, 12, 60, 60);
	//print_info(rbtr);
	//print_info(rm);
	//delete rm;
	Triangle* triangl = new Triangle(10, 20, 30, 40, 50, 60);
	//print_info(triangl);
	Quadrate* quadrat = new Quadrate(10, 20, 30, 40, 50, 60, 70, 80);
	//print_info(quadrat);

	try {
		print_info(rbtr);
	}
	catch (const bad_length& ex) {
		std::cerr << ex.what() << std::endl;
	}

	try {
		print_info(triangl);
	}
	catch (const bad_length& ex) {
		std::cerr << ex.what() << std::endl;
	}

	try {
		print_info(quadrat);
	}
	catch (const bad_length& ex) {
		std::cerr << ex.what() << std::endl;
	}

	delete triangl;
	delete quadrat;
	delete rbtr;

}
