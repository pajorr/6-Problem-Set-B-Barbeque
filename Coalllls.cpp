#include <iostream>

using namespace std;

class Barbeque{
	string my_Brand;
	string my_Model;
	bool coal, lighted, cooking;
	public :
		Barbeque(string brand, string model );
		void loadCoals();
		void light();
		void cook();
		void reset();
		
		bool hasCoals();
		bool isLit();
		bool isCooking();
};

Barbeque::Barbeque(string brand, string model)
{
	this->my_Brand = brand;
	this->my_Model = model;
}

void Barbeque::loadCoals()
{	
	cout<<"Loading "<<my_Brand<<" "<<my_Model<<" with coals..."<<endl;
}

bool Barbeque::hasCoals()
{
	string coalz;
	cout<<"Does the grill have coal in it?"<<endl;
	cin >> coalz;
	
	if(coalz=="yes")
	{
		coal = true;
		return coal;
	}
	
	else
	{
		cout<<"Fill it with coal 1st"<<endl;
		coal = false;
		return coal;
	}
}

void Barbeque::light()
{
	if (coal)
	cout<<"Lighting the grill!"<<endl;
	else
	cout<<"No coal, fill first. "<<endl;
}

bool Barbeque::isLit()
{	
	string litz;
	cout<<"Is the bbq lit now?"<<endl;
	cin>> litz;
	if(litz=="yes")
	{
		lighted = true;
	return lighted;
	}
	else
	{	
		cout<<"You need to re-light the grill."<<endl;
		lighted = false;
		return lighted;
	}
}

void Barbeque::cook()
{	if(lighted)
	cout<<"Cooking food..."<<endl;
	else
	cout<<"Can't cook in these conditions."<<endl;
}

bool Barbeque::isCooking()
{
	string cookz;
	cout<<"Is the food cooking now?"<<endl;
	cin>>cookz;
	if(cookz=="yes")
	{
		cooking = true;
		return cooking;
	}
	else
	{
		cout<<"You can't cook in this situation !"<<endl;
		return false;
	}
}

void Barbeque::reset()
{
	lighted = false;
	coal = false;
	cooking = false;
}


int main()
{	
	Barbeque bbq = Barbeque("Coleman","Grill 101A");
	bool restart;
	do{
	restart=false;
	bbq.loadCoals();
	if (bbq.hasCoals())
	{
		bbq.light();
		if (bbq.isLit())
		{
			bbq.cook();
		}
		else
		{
			cout << " ERROR in logic."<<endl;
			restart=true;
			bbq.reset();
			cout << "Lets make some errors" << endl;
			bbq.light();
			bbq.cook();
			bbq.loadCoals();
			bbq.cook();		
		}			
	}
	else 
	{
		restart=true;
		bbq.reset();
		cout << "Lets make some errors" << endl;
		bbq.light();
		bbq.cook();
		bbq.loadCoals();
		bbq.cook();
	}
	} while(restart==true);

}
	

