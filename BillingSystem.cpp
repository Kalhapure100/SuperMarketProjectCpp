#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class Bill{
	private:
		string Item;
		int Rate,Quantity;
	public:
		Bill():Item(""),Rate(0),Quantity(0){	}
		
		
		void setItem(string item){//value are assignedusing this function
			Item=item;
		}
		void setRate(int rate){
			Rate=rate;
		}
		void setQuant(int quant){
			Quantity=quant;
		}
		string getItem(){
			return Item;
		}
		int getRate(){
			return Rate;
		}
		int getQuant(){
			return Quantity;
		}
		
};
addItem(Bill b){
bool close=false;
while(!close){
	int choice;
	cout<<"\t1.Add."<<endl;
	cout<<"\t2.Close."<<endl;
	cout<<"\tEnter Choice:";
	cin>>choice;
	
	
if(choice==1){
	system("cls");
	string item;
	int rate,quant;
	cout<<"\tEnter Item Name:"; //value are assigned and input is taken from user
	cin>>item;
	b.setItem(item);
	cout<<"\tEnter Rate of Item:";
	cin>>rate;
	b.setRate(rate);
	cout<<"\tEnter Quantity of Item:";
	cin>>quant;
	b.setQuant(quant);
	
	ofstream out("Bill.txt",ios::app);//to send data in file and replace first item when enter new data
	if(!out){
		cout<<"\tError:File can't open!"<<endl;
		
	}
	else{
		out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuant()<<endl<<endl;//to break line for new item and 2nd endl for gap 
		
	}
	out.close();
	cout<<"\tItem Added Successfully"<<endl;	
	Sleep(3000);//windows.h header file use for this to display data for some time
}
    else if(choice==2){
    	system("cls");
    	close=true;//terminate while loop
    	cout<<"\tBack To Main Menu!"<<endl;
    	Sleep(3000);
	}
}	
}
printBill(){
	system("cls");
	int count=0;
	bool close=false;
	while(!close){
		system("cls");
	int choice;
	cout<<"\t1.Add."<<endl;
	cout<<"\t2.Close."<<endl;
	cout<<"\tEnter Choice:";
	cin>>choice;
	if(choice==1){
		string item;
		int quant;
		cout<<"\tEnter item:";
		cin>>item;
		cout<<"Enter the quantity:";
		cin>>quant;
		ifstream in("Bill.txt");//To read data from file
		ofstream out("Bill Temp.txt");//To write the data into file
		string line;
		bool found=false;
		while(getline(in,line)){
           stringstream ss;
		   ss<<line;
		   string itemName;
		   int itemRate,itemQuant;
		   char delimiter;
		   ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuant;//set the boundary of itemname
		   if(item==itemName){
			found=true;
			if(quant<=itemQuant){
				int amount=itemRate*quant;
				cout<<"\t Item| Rate |Quantity|Amount"<<endl;
				cout<<"\t"<<itemName<<"\t "<<itemRate<<"\t "<<quant<<"\t "<<amount<<endl;
				int newQuant=itemQuant-quant;
				itemQuant=newQuant;
				count+=amount;
				out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl<<endl;


			}else{
				//quant not available or less than
				cout<<"\tSorry, "<<item<<"Ended"<<endl;//quant not available as per user requirement
			}
		   }
		   else{
			//not item found;
			out<<line<<endl;
		   }
		}
		if(!found){
			cout<<"\tItem Not Available!"<<endl;
	}
	out.close();
	in.close();
	remove("Bill.txt");
	rename("Bill Temp.txt","Bill.txt"); //temp file se jo value enter ki hai oo vapas original fileme copy karna
	}
	else if(choice==2){
		close=true;
		cout<<"\tCounting Total Bill"<<endl;
	}
	Sleep(3000);
	}
	system("cls");
	cout<<endl<<endl;
	cout<<"\t Total Bill-------------------:"<<count<<endl<<endl;
	cout<<"\tThanks For Shopping!"<<endl;
	Sleep(5000);


}

int main(){
	Bill b;
	bool exit=false;//exit jab tak true nhi ho jata tab tak while loop chalti rahna
	while(!exit){
		system("cls");//cls:prev output ko hide karna and current output is display
		int val;
		cout<<"\tWelcome To Super Market Billing System"<<endl;
		cout<<"\t**************************************"<<endl;
		cout<<"\t\t1.Add Item."<<endl;
		cout<<"\t\t2.Print Bill"<<endl;
		cout<<"\t\t3.Exit"<<endl;
		cout<<"\t\tEnter choice: ";
		cin>>val;
		
		if(val==1){
			system("cls");
		addItem(b);	
		Sleep(3000);
		}
		else if(val==2){
        printBill();
		}
		else if(val==3){
			system("cls");
			exit=true;
			cout<<"\tGood Luck!"<<endl;
			Sleep(3000);
		}
	}
}
