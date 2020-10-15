#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;


/**************图形类*****************************/
class Graph
{
	string GraphName;
	int Perimeter; //周长
	double Area; //面积
	static int Num; //创建了几个子类
	
	public:
	Graph(string GraphName)
	{
		this->GraphName = GraphName;
		Perimeter = 0;
		Area = 0;
		add();  //每创建一个图形计数
		puts("*********Dividing Line******************");
		cout << GraphName << " is created success!" << endl;
		cout << Num << " graph(s) are created!" << endl;
	}
	static void add()
	{
		Num += 1;
	}
	
	void GetPerimeter(int a)
	{
		Perimeter = a;
		cout << GraphName << ":" << " Perimeter is " << Perimeter << endl;
	}
	void GetArea(double a)
	{
		Area = a;
		cout << GraphName << ":" << " Area is " << Area << endl;
	}
	~Graph()
	{
		Num -= 1;  
	}
};

int Graph::Num = 0;   


/*************等边三角形***************************/
class Triangle : public Graph
{
	int Side;   //边长
	
	public: 
	Triangle(int Side = 10):Side(Side), Graph("Triangle")
	{

	}
	int CalPerimeter()
	{
		return 3*Side;
	}
	double CalArea()
	{
		return sqrt(3)*pow(Side, 2)/4;
	}
};

/*************矩形***************************/
class Square : public Graph
{
	int Length;
	int Width;
	public:
	Square(int Length = 20, int Width = 10): Graph("Square")
	{	
		this->Length = Length;
		this->Width = Width;
	}
	int CalPerimeter()
	{
		return (Length + Width) * 2;
	}
	int CalArea()
	{
		return Length * Width;
	}	
};

int main()
{
	Triangle Tri;
	Graph *p = &Tri;
	p->GetPerimeter(Tri.CalPerimeter());
	p->GetArea(Tri.CalArea());
	Square Rec;
	Rec.GetPerimeter(Rec.CalPerimeter());
	Rec.GetArea(Rec.CalArea());
	
	
	return 0;
}
