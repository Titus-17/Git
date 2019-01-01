//SuperPoint.cpp
#include <iostream>
#include <fstream>
// #include "Structs.h"
using namespace std;

struct s2dFloatPoint
{
	float X;
	float Y;
};



///////////////////////////////////////////////////////////////////
struct sPoint
{
	virtual float getFloatX(){ return -1;}
	virtual float getFloatY(){ return -1;}
};


struct sFloatPoint : sPoint
{
	s2dFloatPoint* point;
	float getFloatX(){ return point->X;}
	float getFloatY(){ return point->Y;}
};


struct sTestRecord
{
	sPoint* 	points;
};



int main()
{
	s2dFloatPoint MyPoint_1[1000];
	for (int i = 0; i < 1000; i++)
	{
		MyPoint_1[i].X = i;
		MyPoint_1[i].Y = -i;
	}


	// Запись
	ofstream outfile;
	outfile.open("Test.txt", ios::binary);
	outfile.write(reinterpret_cast<char*>(&MyPoint_1), sizeof(MyPoint_1));
	outfile.close();

	// Чтение
	char* mas = new char[sizeof(MyPoint_1)];
	ifstream is("Test.txt", ios::binary);
	is.read(reinterpret_cast<char*>(mas), sizeof(MyPoint_1));
	is.close();


	sTestRecord record;
	record.points = new sPoint[1000];
	sFloatPoint* A = new sFloatPoint;

	A->point = reinterpret_cast<s2dFloatPoint*>(mas);
	record.points = A;

	for (int i = 0; i < 1000; i++)
	{
		cout << record.points[i].getFloatX() << " - " << record.points[i].getFloatY() << "\n";
	}

	delete[] record.points;
	delete[] mas;
}














// //SuperPoint.cpp
// #include <iostream>
// #include <fstream>
// // #include "Structs.h"
// using namespace std;

// ///////////////////////////////////////////////////////////////////
// #pragma pack (push, 1)
// struct sHeader		// 32 Bytes
// {
// 	long			id;
// 	unsigned long	length;
// 	unsigned long 	metricLenght;
// 	long 			classificationCode;

// 	unsigned short	numberInGroup;
// 	unsigned short	groupNumber;

// 	unsigned short	flag_localization			:4;
// 	unsigned short	flag_frameExit				:4;
// 	unsigned short	flag_insularity				:1;
// 	unsigned short	flag_semantics				:1;
// 	unsigned short	flag_metricSize				:1;
// 	unsigned short	flag_bindingVector			:1;
// 	unsigned short	flag_UNICODE				:1;
// 	unsigned short	flag_reserve				:3;
	
// 	unsigned short	flag_metricFormat			:1;
// 	unsigned short	flag_dimension				:1;
// 	unsigned short	flag_metricType				:1;
// 	unsigned short	flag_metricText				:1;
// 	unsigned short	flag_sign					:1;
// 	unsigned short	flag_scalableGraphics		:1;
// 	unsigned short	flag_metricSpline			:2;

// 	unsigned short	bottomBorder		:4;
// 	unsigned short	topBorder 			:4;

// 	unsigned long 	metricPointsCountBig;
// 	unsigned short 	subobjectNumber;
// 	unsigned short 	metricPointsCount;
// };
// #pragma pack (pop)
// ///////////////////////////////////////////////////////////////////

// struct s2dFloatPoint
// {
// 	float X;
// 	float Y;
// };



///////////////////////////////////////////////////////////////////
// struct sPoint
// {
// 	virtual float getFloatX(){ return -1;}
// 	virtual float getFloatY(){ return -1;}
// };


// struct sFloatPoint : sPoint
// {
// 	s2dFloatPoint* point;
// 	float getFloatX(){ return point->X;}
// 	float getFloatY(){ return point->Y;}
// };


// struct sTestRecord
// {
// 	sHeader* 	header;
// 	sPoint** 	points;
// };



// int main()
// {
// 	sHeader header;
// 	header.id = 100;
// 	header.length = 5000;
// 	header.metricLenght = 4000;



// 	struct floatSTR
// 	{
// 		float X;
// 		float Y;
// 	};
// 	floatSTR MyPoint_1[5];
// 	for (int i = 0; i < 5; i++)
// 	{
// 		MyPoint_1[i].X = i;
// 		MyPoint_1[i].Y = i+5;
// 	}


// 	// Запись
// 	ofstream outfile;
// 	outfile.open("Test.txt", ios::binary);
// 	outfile.write(reinterpret_cast<char*>(&header), sizeof(header));
// 	outfile.write(reinterpret_cast<char*>(&MyPoint_1), sizeof(MyPoint_1));
// 	outfile.close();

// 	// Чтение
// 	char* mas = new char[sizeof(sHeader) + sizeof(MyPoint_1)];
// 	sHeader* ptr_header;
// 	ifstream is("Test.txt", ios::binary);
// 	is.read(reinterpret_cast<char*>(mas), sizeof(sHeader) + sizeof(MyPoint_1));
// 	is.close();


// 	sTestRecord record;
// 	record.points = new sPoint*[5];
// 	sFloatPoint* A = new sFloatPoint[5];

// 	record.points[0] = &A[0];
// 	record.points[1] = &A[1];


// 	A[0].point = reinterpret_cast<s2dFloatPoint*>(mas + sizeof(sHeader));
// 	A[1].point = reinterpret_cast<s2dFloatPoint*>(mas + sizeof(sHeader) + 8);

// 	cout << record.points[0]->getFloatX() << " - " << record.points[0]->getFloatY() << "\n";
// 	cout << record.points[1]->getFloatX() << " - " << record.points[1]->getFloatY() << "\n";

// 	delete[] mas;
// }