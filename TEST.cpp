/*
 * TEST.cpp
 *
 *  Created on: 14 апр. 2017 г.
 *      Author: diman-pro
 */
#define __DEBUG
#ifdef __DEBUG

#include <iostream>

#include "MasterGen.h"
#include "Gens/Exception.h"
#include "Sys.h"
#include <ostream>
#include <sstream>

#define MaxValue 2000

//#define LINUX

#ifdef LINUX
#include "../ProcessManager/ProcessManager.h"
#include "../SaveResult/SaveResult.h"
#include <cstdlib>
#include <fstream>


#include "../ConsoleFunction.h"
#endif


using std::ostream;
using std::istringstream;
using System::Rand;
using std::cin;

template<typename T=ostream>
class Out{
	private:
		int Num=0;
		T& out;
	public:
		Out(T& os):out(os){}
		int operator++(int){
			out<<"№"<<Num<<": success\n";
			return Num++;
		}
		int operator--(int){
			out<<"№"<<Num<<": fail\n";
			throw Generator::Collection::FailGenerator();
			return Num++;
		}
		template<typename O>
		friend Out& operator<<(Out& os,const O& o){
			os.out<<o;
			return os;
		}
};

Generator::Collection::Constant cons;
istringstream stream;
Out<ostream> out{std::cout};


inline void TestConstant();

inline void TestDivide();

inline void TestMinus();

inline void TestMultiple();

inline void TestSum();

inline void TestOptimisation();

void GenTest(){

	out<<"Test start\n";
	TestConstant();
	TestDivide();
	TestMinus();
	TestMultiple();
	TestSum();
	TestOptimisation();

	out<<"\n Test finish\n";

}

int main0(){
	Generator::Collection::Master master;
	out<<"help - подсказка\n";
	while (true){
		string str;
		cin>>str;
		if (str=="exit"){
			break;
		}
		if (str=="gen"){
			int b;
			cin>>b;
			out<<master(b)<<"\n";
			continue;
		}
		if (str=="var"){
			int b;
			cin>>str>>b;
			master.SetValue(str,b);
			out<<"\n";
			continue;
		}
		if (str=="test"){
			GenTest();
			out<<"\n";
			continue;
		}
		if (str=="unknow"){
			cin>>str;
			master.SetValue(str);
			out<<"\n";
			continue;
		}
		if (str=="help"){
			out<<"help - вывод справки\n"
					"gen N - генерировать выражение для N\n"
					"test - запустить тестирование\n"
					"exit - завершить работу\n"
					"var Name Value - добавить генератору переменную Name со значением Value\n"
					"unknow Name - добавить генератору неинициализированную переменную Name\n"
					;
			continue;
		}
		out<<"Comand is not found. Use 'help'\n";
	}
}
#ifdef LINUX
template<typename T,typename Y>
class Pair{
	public:
		T first;
		Y second;
		Pair(const T&first,const Y&second):first(first),second(second){}
};

#endif

inline void TestOptimisation(){
#ifdef LINUX
	Generator::Collection::Master mast;
	mast.SetValue("i",64);
	mast.SetValue("j",58);
	mast.SetValue("isFail");
	mast.SetValue("Not");
	auto max=100;
	size_t countTest=40;
	auto gen=SaveResultThread::getSave(mng,[&mast,&max](){
		int b=Rand(max)+70;
		return Pair<int,string>(b,mast(b));
	},countTest);

	gen.run();
	out<<"Wait...\n";
	gen.weit();
	auto result=gen.Result();
	int CountFailTest=0;
	for (int i=0;i<result.size();i++){
		string proga="#include <iostream>\n"
				"using std::cout;\n"
				"int main(){\n"
				"\tint i=64;\n"
				"\tint Not=-1111;\n"
				"\tint j=58;\n"
				"\tint isFail=20;\n"
				"int out="+result[i].second+";\n"
						"\tcout<<out;\n"
						"}";
		{
			std::ofstream f;
			f.open("klfdhvhkdvcklsdhvdfk.cpp");
			f<<proga;
			f.close();
		}
		string g="g++ -S -o ojfghkjfdngjkfdg.s klfdhvhkdvcklsdhvdfk.cpp";
		system(g.c_str());
		{
			std::ifstream f;
			f.open("ojfghkjfdngjkfdg.s");
			string genResult="$"+System::ToString(result[i].first)+",";
			while (!f.eof()){
				string lit;
				f>>lit;
				if (genResult.compare(lit)==0){
					out<<genResult<<" "<<lit<<"\n";
					CountFailTest++;
					f.close();
					continue;
				}

			}
			f.close();
		}
	}
	out<<"Fail Gen: "<<CountFailTest<<" ("<<(CountFailTest/(double)result.size())<<"%)\n";
	out<<"Fail Run: "<<countTest-result.size()<<"\n";
	out<<"All :"<<countTest<<"\n";


#endif
}

inline void TestSumSys(){
	out<<"\tSysTest\n";
	Generator::Collection::Sum d;
	//Из-за особенности реализации возможны только автоматические тесты
	//Извините за доставленные неудобства
	bool fail;
	char c;
	out<<"Automatic Test\n";
	for (int i=0;i<10;i++){
		int r=Rand()%MaxValue;
		stream.str(d(r,fail,cons));
		int a,b;
		stream>>a>>c>>b;
		if ((a+b)!=r)
			out--;
		else
			out++;
		stream.clear();
	}
}

inline void TestSumLeft(){
	out<<"\tLeft Sum\n";
	Generator::Collection::Sum d;
	bool fail;
	int b=2;
	stream.str(d.left(b,6,fail,cons));
	int a;
	stream>>a;
	if ((a+b)!=6)
		out--;
	else
		out++;
	stream.clear();
	b=9;
	stream.str(d.left(b,72,fail,cons));
	stream>>a;
	if ((a+b)!=72)
		out--;
	else
		out++;
	stream.clear();
	b=7;
	stream.str(d.left(b,147,fail,cons));
	stream>>a;
	if ((a+b)!=147)
		out--;
	else
		out++;
	stream.clear();
	b=7;
	stream.str(d.left(b,63,fail,cons));
	stream>>a;
	if ((a+b)!=63)
		out--;
	else
		out++;
	stream.clear();
	int Max=MaxValue;
	out<<"Automatic Test\n";
	for (int i=0;i<10;i++){
		b=Rand()%Max;
		a=Rand()%Max;
		int res=a+b;
		stream.str(d.left(b,res,fail,cons));
		stream>>a;
		if ((a+b)!=res)
			out--;
		else
			out++;
		stream.clear();
	}
}

inline void TestSumRight(){
	out<<"\tRight Sum\n";
	Generator::Collection::Sum d;
	bool fail;
	int a=125;
	stream.str(d.right(a,625,fail,cons));
	int b;
	char c;
	stream>>c>>b;
	if ((a+b)!=625)
		out--;
	else
		out++;
	stream.clear();
	a=3;
	stream.str(d.right(a,549,fail,cons));
	stream>>c>>b;
	if ((a+b)!=549)
		out--;
	else
		out++;
	stream.clear();
	a=11;
	stream.str(d.right(a,121,fail,cons));
	stream>>c>>b;
	if ((a+b)!=121)
		out--;
	else
		out++;
	stream.clear();
	a=64;
	stream.str(d.right(a,256,fail,cons));
	stream>>c>>b;
	if ((a+b)!=256)
		out--;
	else
		out++;
	stream.clear();
	out<<"Automatic Test\n";
	int Max=MaxValue;
	for (int i=0;i<10;i++){
		b=Rand()%Max;
		a=Rand()%Max;
		int res=a+b;
		stream.str(d.right(a,res,fail,cons));
		stream>>c>>b;
		//console<<a<<c<<b<<" = "<<res<<"\n";
		if ((a+b)!=res)
			out--;
		else
			out++;
		stream.clear();
	}
}




inline void TestSum(){
	out<<"\t\tSum\n";
	TestSumSys();
	TestSumLeft();
	TestSumRight();
}

inline void TestMultipleSys(){
	out<<"\tSysTest\n";
	Generator::Collection::Multiple d;
	//Из-за особенности реализации возможны только автоматические тесты
	//Извините за доставленные неудобства
	bool fail;
	char c;
	out<<"Automatic Test\n";
	for (int i=0;i<10;i++){
		int r=Rand()%MaxValue;
		try{
			stream.str(d(r,fail,cons));
		}catch(Generator::Collection::FailGenerator&){
			i--;
			continue;
		}
		int a,b;
		stream>>a>>c>>b;
		if ((a*b)!=r)
			out--;
		else
			out++;
		stream.clear();
	}
}

inline void TestMultipleLeft(){
	out<<"\tLeft Multiple\n";
	Generator::Collection::Multiple d;
	bool fail;
	int b=2;
	stream.str(d.left(b,6,fail,cons));
	int a;
	stream>>a;
	if ((a*b)!=6)
		out--;
	else
		out++;
	stream.clear();
	b=9;
	stream.str(d.left(b,72,fail,cons));
	stream>>a;
	if ((a*b)!=72)
		out--;
	else
		out++;
	stream.clear();
	b=7;
	stream.str(d.left(b,147,fail,cons));
	stream>>a;
	if ((a*b)!=147)
		out--;
	else
		out++;
	stream.clear();
	b=7;
	stream.str(d.left(b,63,fail,cons));
	stream>>a;
	if ((a*b)!=63)
		out--;
	else
		out++;
	stream.clear();
	int Max=MaxValue;
	out<<"Automatic Test\n";
	for (int i=0;i<10;i++){
		b=Rand()%Max;
		a=Rand()%Max+b;
		int res=a*b;
		stream.str(d.left(b,res,fail,cons));
		stream>>a;
		if ((a*b)!=res)
			out--;
		else
			out++;
		stream.clear();
	}
}

inline void TestMultipleRight(){
	out<<"\tRight Multiple\n";
	Generator::Collection::Multiple d;
	bool fail;
	int a=125;
	stream.str(d.right(a,625,fail,cons));
	int b;
	char c;
	stream>>c>>b;
	if ((a*b)!=625)
		out--;
	else
		out++;
	stream.clear();
	a=3;
	stream.str(d.right(a,549,fail,cons));
	stream>>c>>b;
	if ((a*b)!=549)
		out--;
	else
		out++;
	stream.clear();
	a=11;
	stream.str(d.right(a,121,fail,cons));
	stream>>c>>b;
	if ((a*b)!=121)
		out--;
	else
		out++;
	stream.clear();
	a=64;
	stream.str(d.right(a,256,fail,cons));
	stream>>c>>b;
	if ((a*b)!=256)
		out--;
	else
		out++;
	stream.clear();
	out<<"Automatic Test\n";
	int Max=MaxValue;
	for (int i=0;i<10;i++){
		b=Rand()%Max;
		a=Rand()%Max;
		int res=a*b;
		stream.str(d.right(a,res,fail,cons));
		stream>>c>>b;
		//console<<a<<c<<b<<" = "<<res<<"\n";
		if ((a*b)!=res)
			out--;
		else
			out++;
		stream.clear();
	}
}

inline void TestMultiple(){
	out<<"\t\tMultiple\n";
	TestMultipleSys();
	TestMultipleLeft();
	TestMultipleRight();
}

inline void TestMinusSys(){
	out<<"\tSysTest\n";
	Generator::Collection::Minus d;
	//Из-за особенности реализации возможны только автоматические тесты
	//Извините за доставленные неудобства
	bool fail;
	char c;
	out<<"Automatic Test\n";
	for (int i=0;i<10;i++){
		int r=Rand()%MaxValue;
		stream.str(d(r,fail,cons));
		int a,b;
		stream>>a>>c>>b;
		if ((a-b)!=r)
			out--;
		else
			out++;
		stream.clear();
	}
}

inline void TestMinusLeft(){
	out<<"\tLeft Minus\n";
	Generator::Collection::Minus d;
	bool fail;
	int b=2;
	stream.str(d.left(b,6,fail,cons));
	int a;
	stream>>a;
	if ((a-b)!=6)
		out--;
	else
		out++;
	stream.clear();
	b=9;
	stream.str(d.left(b,72,fail,cons));
	stream>>a;
	if ((a-b)!=72)
		out--;
	else
		out++;
	stream.clear();
	b=7;
	stream.str(d.left(b,125,fail,cons));
	stream>>a;
	if ((a-b)!=125)
		out--;
	else
		out++;
	stream.clear();
	b=7;
	stream.str(d.left(b,63,fail,cons));
	stream>>a;
	if ((a-b)!=63)
		out--;
	else
		out++;
	stream.clear();
	int Max=MaxValue;
	out<<"Automatic Test\n";
	for (int i=0;i<10;i++){
		b=Rand()%Max;
		a=Rand()%Max+b;
		int res=a-b;
		stream.str(d.left(b,res,fail,cons));
		stream>>a;
		if ((a-b)!=res)
			out--;
		else
			out++;
		stream.clear();
	}
}

inline void TestMinusRight(){
	out<<"\tRight Minus\n";
	Generator::Collection::Minus d;
	bool fail;
	int a=125;
	stream.str(d.right(a,25,fail,cons));
	int b;
	char c;
	stream>>c>>b;
	if ((a-b)!=25)
		out--;
	else
		out++;
	stream.clear();
	a=18;
	stream.str(d.right(a,9,fail,cons));
	stream>>c>>b;
	if ((a-b)!=9)
		out--;
	else
		out++;
	stream.clear();
	a=72;
	stream.str(d.right(a,8,fail,cons));
	stream>>c>>b;
	if ((a-b)!=8)
		out--;
	else
		out++;
	stream.clear();
	a=256;
	stream.str(d.right(a,64,fail,cons));
	stream>>c>>b;
	if ((a-b)!=64)
		out--;
	else
		out++;
	stream.clear();
	out<<"Automatic Test\n";
	int Max=MaxValue;
	for (int i=0;i<10;i++){
		b=Rand()%Max;
		a=Rand()%Max+b;
		int res=a-b;
		stream.str(d.right(res,a,fail,cons));
		stream>>c>>b;
		//console<<a<<c<<b<<" = "<<res<<"\n";
		if ((res-b)!=a)
			out--;
		else
			out++;
		stream.clear();
	}
}

inline void TestMinus(){
	out<<"\t\tMinus\n";
	TestMinusSys();
	TestMinusLeft();
	TestMinusRight();
}

inline void TestDivideSys(){
	out<<"\tSysTest\n";
	Generator::Collection::Divide d;
	//Из-за особенности реализации возможны только автоматические тесты
	//Извините за доставленные неудобства
	bool fail;
	char c;
	out<<"Automatic Test\n";
	for (int i=0;i<10;i++){
		int r=Rand()%MaxValue;
		stream.str(d(r,fail,cons));
		int a,b;
		stream>>a>>c>>b;
		if ((a/b)!=r)
			out--;
		else
			out++;
		stream.clear();
	}
}

inline void TestDivideLeft(){
	out<<"\tLeft Devide\n";
	Generator::Collection::Divide d;
	bool fail;
	int b=2;
	stream.str(d.left(b,8,fail,cons));
	int a;
	stream>>a;
	if (a/b!=8)
		out--;
	else
		out++;
	stream.clear();
	b=9;
	stream.str(d.left(b,72,fail,cons));
	stream>>a;
	if (a/b!=72)
		out--;
	else
		out++;
	stream.clear();
	b=5;
	stream.str(d.left(b,125,fail,cons));
	stream>>a;
	if (a/b!=125)
		out--;
	else
		out++;
	stream.clear();
	b=7;
	stream.str(d.left(b,63,fail,cons));
	stream>>a;
	if (a/b!=63)
		out--;
	else
		out++;
	stream.clear();
	int Max=MaxValue/2;
	out<<"Automatic Test\n";
	for (int i=0;i<10;i++){
		a=Rand()%Max+1;
		b=Rand()%Max+1;
		int res=a*b;
		stream.str(d.left(b,res,fail,cons));
		stream>>a;
		//console<<a<<'/'<<b<<" = "<<res<<"\n";
		if (a/b!=res)
			out--;
		else
			out++;
		stream.clear();
	}
}

inline void TestDivideRight(){
	out<<"\tRight Devide\n";
	Generator::Collection::Divide d;
	bool fail;
	int a=125;
	stream.str(d.right(a,25,fail,cons));
	int b;
	char c;
	stream>>c>>b;
	if (a/b!=25)
		out--;
	else
		out++;
	stream.clear();
	a=18;
	stream.str(d.right(a,9,fail,cons));
	stream>>c>>b;
	if (a/b!=9)
		out--;
	else
		out++;
	stream.clear();
	a=72;
	stream.str(d.right(a,8,fail,cons));
	stream>>c>>b;
	if (a/b!=8)
		out--;
	else
		out++;
	stream.clear();
	a=256;
	stream.str(d.right(a,64,fail,cons));
	stream>>c>>b;
	if (a/b!=64)
		out--;
	else
		out++;
	stream.clear();
	out<<"Automatic Test\n";
	int Max=MaxValue/2;
	for (int i=0;i<10;i++){
		a=Rand()%Max+1;
		b=Rand()%Max+1;
		int res=a*b;
		stream.str(d.right(res,a,fail,cons));
		stream>>c>>b;
		if (res/b!=a)
			out--;
		else
			out++;
		stream.clear();
	}
}

inline void TestDivide(){
	out<<"\t\tDivide\n";
	TestDivideSys();
	TestDivideLeft();
	TestDivideRight();
}


inline void TestConstant(){
	out<<"\t\tConstant\n";
	int A;
	stream.str(cons(50));
	stream>>A;
	if (A!=50)
		out--;
	else
		out++;
	stream.clear();
	stream.str(cons(6434));
	stream>>A;
	if (A!=6434)
		out--;
	else
		out++;
	stream.clear();
	for (int i=0;i<10;i++){
		int b=Rand();
		stream.str(cons(b));
		stream>>A;
		if (A!=b)
			out--;
		else
			out++;
		stream.clear();
	}
}



#endif
