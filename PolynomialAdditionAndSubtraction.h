//结构体以及类的声明
#ifndef POLYNOMIALADDITIONANDSUBTRACTION_H_
#define POLYNOMIALADDITIONANDSUBTRACTION_H_

struct Data 
{
	float coef;//系数 
	int exp;   //指数
	Data* link;//指向下一个节点 
	Data(float c,int e,Data* next=nullptr)
	{ 
		coef=c; exp=e; link=next;
	}
	Data* insert(float c,int e);              //插入新结点 
};

class Polynomal
{
public:
	Polynomal(){first=new Data(0,-1);}
    Data* Gethead() const {return first;}
    Polynomal Execute();                      //执行 
    Polynomal Add(Polynomal&,Polynomal&);     //相加 
	Polynomal Subtract(Polynomal&,Polynomal&);//相减 
	
private:
	Data* first;
};
#endif
