#include <iostream>

using namespace std;

//给教师和学生定义基类
class Human  
{
	private:
	string name;
	string sex;
	public:
	Human(string name, string sex):name(name), sex(sex)
	{

	}
	string getname() {return name;}
	string getsex() {return sex;}
	virtual void getinfo() = 0;  //定义getinfo() 虚函数接口
};

//定义教师类
class Teacher :  public Human
{
	private:
		string title;
		int salary;
	public:
		//构造函数
		Teacher(string name, string sex, string title, int salary):Human(name, sex)
		{	
			this->title = title;
			this->salary = salary;
		}
		//使用基类接口
		void getinfo()  
		{
			cout<< getname()<<" "
				<< getsex() <<" "
				<< salary   <<" "
				<< title  	<<endl;
		}
};

//定义学生类
class Student :  public Human
{
	private:
		string grade;
		int score;
	public:
		Student(string name, string sex,string grade, int score):Human(name, sex)
		{
			this->grade = grade;
			this->score = score;
		}

		void getinfo()
		{
		
			cout<< getname()<<" "
				<< getsex() <<" "
				<< grade    <<" "
				<< score    <<endl;
		}
};

int main()
{
	//使用基类指针访问两个派生类
	Human *T = new Teacher("xiaoli", "proferssional", "female", 200000);
	Human *S = new Student("xiaoming", "class 5", "male", 10);


	T->getinfo();
	S->getinfo();

	delete T;
	delete S;
	return 0;
}
