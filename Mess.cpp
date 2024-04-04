#include <iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;
class Mess	//Base Class
{
	public:
	string name;
	string city;
	int customer_id;
	long number;
	Mess();
    void accept();	
    void allItem();
    void cleardata();
    void putdata();
};
int add(int x,int y)	//Function ADD to ADD two choices
{
	int a=(x+y)*6;
	return a;
}
int add(int x,int y,int z)	//Overloading Function ADD to add extra snacks
{
	int b=(x+y+z)*6;
	return b;
}
Mess::Mess()	//Constructor
{
	name="";
	city="";
	customer_id=0;
	number=0;
}
void Mess::cleardata(){
	name="";
	city="";
	customer_id=0;
	number=0;
}
void Mess::accept()
{
	cout<<"Enter Name :"<<endl;
	cin>>name;
	cout<< "Enter the number : "<<endl;
	cin>>number;	
	
	try
	{
	cout<< "Enter the ID of customer : "<<endl;
	cin>>customer_id;	
	if(customer_id<1 || customer_id>100)
	{
	throw customer_id;
	}
	}
	catch(int a1){
	cout<< "Exception:incorrect ID"<<endl;
	accept();
	  }
	try{
	cout<< "Enter the city : "<<endl;
	cin>>city;
	if(city!="Pune"){
	throw(city);
	}
	}
	catch(string i1){
	cout<< "Exception:incorrect City "<<endl;
	accept();
  	}
	}
void Mess::putdata(){
	cout<<"Name : "<<name<<endl;
	cout<<"Address :"<<city<<endl;
	cout<<"Number :"<<number<<endl;
	cout<<"Customer ID :"<<customer_id<<endl;
}
class Veg:public Mess{
	public:
	void ShowPrice1();
};
void Veg:: ShowPrice1(){
		cout<<"Price For Veg Meal= Rs 57 per day"<<endl;
}
class NonVeg:public Mess{
	public:
	void ShowPrice2();
};
void NonVeg:: ShowPrice2(){
		cout<<"Price For Non Veg Meal= Rs 67 per day "<<endl;
}

class Full:public Mess{
	public:
	void ShowPrice3();
};
void Full:: ShowPrice3(){
		cout<<"Price For Full Meal= Rs 120"<<endl;
}
class Mini:public Mess{
	public:
	void ShowPrice4();
};
void Mini:: ShowPrice4(){
		cout<<"Price For Mini Meal= Rs 90 "<<endl;
	
}
int Extrafood(){  //STL LIBRARY MAPS
	string extra;
        int prc;
        string Extra_snack[]={"Lays","Ice Cream","Coke","ColdCoffee","Tea"};
        int price[]={20,35,20,40,10};
        for(int i=0;i<5;i++){
        	cout<<Extra_snack[i]<<"-"<<price[i]<<endl;
        }
        map<string,int,less<string>>mapExtra;
        map<string,int,less<string>>::iterator iter;
        for(int j=0;j<5;j++){
        	extra=Extra_snack[j];
        	prc=price[j];
        	mapExtra[extra]=prc;
        	
        }
	cout<<"Enter Snack of choice"<<endl;
      	cin>>extra;
      	prc=mapExtra[extra];
      	cout<<"Price"<<prc<<endl;
      	
      	return prc;
}

int main(){
	Mess m1,m2;
	ifstream fin;
	ofstream fout;
	fout.open("details.txt",ios::binary);
	m1.accept();
	fout.write((char*)&m1,sizeof(m1));
        fout.close();
        m1.cleardata();
        
        fin.open("details.txt",ios::in);
        fin.read((char*)&m1,sizeof(m1));
        m1.putdata();
        fin.close();
        fstream file;
        cout<<"Menu Below"<<endl;
	file.open("Menu.txt");
	file.seekg(ios::beg);
	for(int i=0;i<2441;i++){
	char next=file.get();
	cout<<next;
	}
	cout<<endl;
        int s;
        cout<<"Enter Choice For\n 1.Full Veg Meal\n 2.Mini Veg Meal\n 3.Full Non-Veg Meal\n 4.Mini Non-Veg\n 5.Full Veg Meal with extra Snack\n 6.Mini Veg Meal with snack\n 7.Full Non-Veg Meal with snack\n 8.Mini Non-Veg Meal with snacks\n"<<endl;
        cin>>s; 
        Veg v;
        Full f;
        NonVeg n;
        Mini m;
    
        int ch1=add(57,120);
        int ch2=add(57,90);
        int ch3=add(67,120);
        int ch4=add(67,90);
        int ch5,ch6,ch7,ch8;
        /*int ch6=add(57,90,20);
        int ch7=add(67,120,20);
        int ch8=add(67,90,20);*/
        switch(s){
        case 1:
        v.ShowPrice1();
        f.ShowPrice3();
        cout<<"Total Price -"<<ch1<<endl;
        break;
        case 2:
        v.ShowPrice1();
        m.ShowPrice4();
        cout<<"Total Price -"<<ch2<<endl;
        break;
        case 3:
        n.ShowPrice2();
        f.ShowPrice3();
        cout<<"Total Price -"<<ch3<<endl;
        break;
        case 4:
        n.ShowPrice2();
        m.ShowPrice4();
        cout<<"Total Price -"<<ch4<<endl;
      	break;
      	case 5:
      	cout<<"Extra Snack option:-"<<endl;
      	ch5=add(57,120,Extrafood());
      	v.ShowPrice1();
        f.ShowPrice3();
        cout<<"Total Price -"<<ch5<<endl;
      	break;
      	case 6:
      	cout<<"Extra Snack option:-"<<endl;
      	ch6=add(57,90,Extrafood());
      	v.ShowPrice1();
        m.ShowPrice4();
        cout<<"Total Price -"<<ch6<<endl;
      	break;
      	case 7:
      	cout<<"Extra Snack option:-"<<endl;
      	ch7=add(67,120,Extrafood());
      	n.ShowPrice2();
        f.ShowPrice3();
        cout<<"Total Price -"<<ch7<<endl;
      	break;
      	case 8:
      	cout<<"Extra Snack option:-"<<endl;
      	ch8=add(67,90,Extrafood());
	n.ShowPrice2();
        m.ShowPrice4();
        cout<<"Total Price -"<<ch8<<endl;
	break;
      }  
        return 0;
}
