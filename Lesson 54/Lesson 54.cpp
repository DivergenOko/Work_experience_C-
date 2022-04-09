// В С++ Структуры - это вид класса. Обращение к полям структуры свободное. 
// В классах С нет свободного обращения. Поле - одно из составляющих структуры  
// (перемннная какого-то типа) данные структуры. 
// А методы - это функции, которые работают с полями.  
// Структура хранит побайтовую разметку памяти на каждый тип данных. 
// Структуры чаще всего используются для хранения данных (не метод). 

#include <iostream> 
using namespace std;

struct Point { // Point - это тип данных которыq мы хотим описать. 
	float x;
	float y;
	float z;
};

void cin_point(Point& p) { // чтение структуры с помощью функции 
	cin >> p.x >> p.y >> p.z;
}

void cout_point(Point p) {
	cout << p.x << "\t" << p.y << "\t" << p.z << "\t" << "\n";
}

ostream& operator <<(ostream& cout, Point p) { // оператор - это функция которая имеет специфическое имя 
	cout << p.x << " " << p.y << " " << p.z;
	return cout;
}

istream& operator >>(istream& cout, Point& p) { // оператор - это функция которая имеет специфическое имя 
	cin >> p.x >> p.y >> p.z;
	return cin;
}

Point operator +(Point p1, Point p2) { // операция сложения точек 
	Point p;
	p.x = p1.x + p2.x;
	p.y = p1.y + p2.y;
	p.z = p1.z + p2.z;
	return p;
};

Point avg(Point p1, Point p2) { // операция вычисления среднего значения точку 
	Point p;
	p.x = (p1.x + p2.x) / 2;
	p.y = (p1.y + p2.y) / 2;
	p.z = (p1.z + p2.z) / 2;
	return p;
}

int main()
{
	Point p;
	Point p1;
	Point p2;
	cin >> p1 >> p2;

	Point p3 = avg(p1, p2);
	Point p4 = p1 + p2;
	cout << p4;
	/*cin_point(p1);
	//cin_point(p2);
	//cin_point(p3);

	//cout_point(p1);
	//cout_point(p2);
	//cout_point(p3);*/
}