#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

class Expense{
	private:
		int date;
		int month;
		int year;
		char payee[50];
		float price;
		float income;
	public:
		Expense(){
			date=0;
			month=0;
			year=0;
			payee[0]={'\0'};
			price=0;
			income=0;
		}
	
	void add_expense();
    bool income_empty();
	void get_details();
	void add_income();
	void check_budget();
	void show_saved_data();
	int save_data();
	void update_income();
	void display_data();
	
		
};

void Expense::update_income(){
	
	float dust_income;
			
						
			ifstream update_income;					/* subtract expense from income*/
			update_income.open("income1.txt");
			update_income>>dust_income;
			update_income.close();
			dust_income=dust_income-price;
			
			ofstream update_income2;				/*write new income in file*/
			update_income2.open("income1.txt");
			update_income2<<dust_income;	
			update_income2.close();
}
int Expense::save_data(){
			
			ofstream save;
			save.open("expense_manager1.txt",ios::app);	/*write date and expense in file*/
			
			save.write((char*)this,sizeof(*this));
			
			/*save<<date<<"\n";
			save<<month<<"\n";
			save<<year<<"\n";
			save<<payee<<"\n";
			save<<price<<"\n";*/
			save.close();
}

bool Expense::income_empty(){
	
	float dust_income,flag;
		
		ifstream flag_income;				/* check if any income is left*/
		flag_income.open("income1.txt");
		flag_income>>flag;
		flag_income.close();
		if(flag==0)
			return(true);
		else
			return(false);
}
void Expense::show_saved_data(){
	
	cout<<endl<<"Data to be saved is:"<<endl;
	cout<<endl<<"day is: \t"<<date<<endl;
	cout<<"month is:\t"<<month<<endl;
	cout<<"year is:\t"<<year<<endl;
			
	cout<<"payee is:\t"<<payee<<endl;
	cout<<"amount is:\t"<<price<<endl;
}

void Expense::get_details(){
	
	
		if(income_empty())
		{
			cout<<"add the income first"<<endl;
			return;
		}
	else{
			time_t t = time(NULL);					/* input date*/
			tm* tPtr = localtime(&t);
			int monthh,date1,year1;
			cout<<"enter the month"<<endl;
			cin>>monthh;
			if(monthh==tPtr->tm_mon+1)
			this->month=monthh;
			else
			{
			cout<<"Enter valid month"<<endl;
			cin>>this->month;
				
			}
			
			cout<<"enter the date"<<endl;
			cin>>date1;
			if(date1<=tPtr->tm_mday)
			this->date=date1;
			else
			{
				cout<<"enter the valid date"<<endl;
				cin>>this->date;
			}
			cout<<"enter the year"<<endl;
			cin>>year1;
			if(year1==tPtr->tm_year+1900)
			this->year=year1;
			else
			{
				cout<<"Enter valid year"<<endl;
				cin>>this->year;
			}					
			
 			
			cout<<"enter the payee"<<"\n";				/* input expense*/
			cin>>this->payee;
	
			cout<<"enter the amount"<<endl;
			cin>>this->price;
	}
						
}
void Expense::check_budget(){
	
	float post_income;
	ifstream show_income;
	show_income.open("income1.txt");
	show_income>>post_income;
	show_income.close();
	cout<<"The remaining budget is:\t"<<post_income<<endl;
}


void Expense::add_income(){
	float pre_income;
	cout<<"Enter the income"<<endl;
	cin>>pre_income;
	income=income+pre_income;
	ofstream update_income;
	update_income.open("income1.txt");
	update_income<<income<<"\n";
	update_income.close();
}

void Expense::display_data(){
	
			ifstream show;
			show.open("expense_manager1.txt",ios::app);	/*read date and expense in file*/
			
			show.read((char*)this,sizeof(*this));
			while(!show.eof())
			{
				show_saved_data();
				show.read((char*)this,sizeof(*this));
			}
			show.close();
			
}
void Expense::add_expense()
{
		
		

			
			
			
			
			
			
		
}
			
int main()
{
	Expense ex;
	int choice;
	char choice2;
	
	do{
		cout<<"Chose anyone from following:\t"<<endl;
		cout<<"1.Add an expense"<<endl;
		cout<<"2.Add income"<<endl;
		cout<<"3.Show remaining budget"<<endl;
		cout<<"4.Show expense on a particular date"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1: ex.income_empty();
					ex.get_details();
					ex.show_saved_data();
					ex.save_data();
					ex.update_income();
					
					break;
			case 2: ex.add_income();
					break;
			case 3: ex.check_budget();
					break;
			case 4: ex.display_data();
					break;
		}
		cout<<"wish to go again"<<endl;
		cin>>choice2;
		
	  }while(choice2=='y');
}
