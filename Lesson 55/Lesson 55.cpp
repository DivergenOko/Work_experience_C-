//Lesson 55. Центр тяжести среди в фигуре

#include <iostream> 
#include <fstream> 
using namespace std;

struct Point { // Point - это тип данных которые мы хотим описать. 
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

ostream& operator <<(ostream& cout, Point p) {
	// оператор - это функция которая имеет специфическое имя 
	cout << "( " << p.x << "; " << p.y << "; " << p.z << " )";
	return cout;
}

fstream& operator >>(fstream& in, Point& p) { // разные потоки данных  
	in >> p.x >> p.y >> p.z;
	return in;
}

Point operator +(Point p1, Point p2) { // операция сложения точек 
	Point p;
	p.x = p1.x + p2.x;
	p.y = p1.y + p2.y;
	p.z = p1.z + p2.z;
	return p;
};

int main()
{
	int n;
	Point* points = 0;
	fstream point = fstream("point.txt", ios::in);

	if (point.good()) {
		point >> n;
		points = new Point[n];
		for (int i = 0; i < n; i++) {
			point >> points[i];
		}
		point.close();
	}

	if (points != 0) {
		for (int i = 0; i < n; i++) {
			cout << points[i] << "\t" << "\n";
		}

		Point centr;
		centr.x = 0;
		centr.y = 0;
		centr.z = 0;
		for (int i = 0; i < n; i++) {
			centr = centr + points[i];
		}
		centr.x /= n;
		centr.y /= n;
		centr.z /= n;
		cout << "c: " << centr;

		fstream out = fstream("out.txt", ios::out | ios::binary);
		if (out.good()) {
			out.write((char*)&n, sizeof(n));
			out.write((char*)points, sizeof(points) * n);
			out.close();
		}
		delete[] points;
	}
}