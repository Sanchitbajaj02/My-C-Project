//Source Code

#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<process.h>

fstream fout;   // ofstream writing
fstream fin;    // ifstream reading

//TRAVEL BY AIRWAYS
class travel
{
int mem;  		           //input the members
char name[20];     		//take input name
char id[30];       		//take email id
char tra;          		//take mode of travel
unsigned int price;     	//price of travelling
char dest[30];          	//travel destination
public:
travel()
{ mem=0;
  tra='a';
  price=0;
}
char ret_tra()       //return mode of travel
{ return tra;  }
char* ret_name()     //return name
{ return name; }
char* ret_id()       //return email id
{ return id;   }
void input();
void travelling(char,int);
void output();
}t;
//Airway class object = t
void travel::travelling(char choice,int mem)
{
int xx;
if(choice=='n'||choice=='N')
 { cout<<"\n 1.Flight-> Delhi to Jaipur";
   cout<<"\n 2.Flight-> Delhi to Mumbai";
   cout<<"\n 3.Flight-> Delhi to Chennai";
   cout<<"\n 4.Flight-> Delhi to Kolkata";
   cout<<"\n Enter your choice : ";
   cin>>xx;
   cout<<"\n Booking confirmed";
   cout<<"\n Price generted\n";
   if(xx==1)
   { price=(mem*2500);
     strcpy(dest,"Delhi to Jaipur");
   }
   if(xx==2)
   { price=(mem*3500);
     strcpy(dest,"Delhi to Mumbai");
   }
   if(xx==3)
   { price=(mem*4000);
     strcpy(dest,"Delhi to Chennai");
   }
   if(xx==4)
   { price=(mem*3200);
     strcpy(dest,"Delhi to Kolkata");
   }
 }
if(choice=='i'||choice=='I')
 { cout<<"\n 1.Flight-> Delhi to USA";
   cout<<"\n 2.Flight-> Delhi to Australia";
   cout<<"\n 3.Flight-> Delhi to France";
   cout<<"\n 4.Flight-> Delhi to Switzerland";
   cout<<"\n Enter your choice : ";
   cin>>xx;
   cout<<"\n Booking confirmed";
   cout<<"\n Price generted\n";
   if(xx==1)
   { price=(mem*7000);
     strcpy(dest,"Delhi to USA");
   }
   if(xx==2)
   { price=(mem*4500);
     strcpy(dest,"Delhi to Australia");
   }
   if(xx==3)
   { price=(mem*5000);
     strcpy(dest,"Delhi to France");
   }
   if(xx==4)
   { price=(mem*8000);
     strcpy(dest,"Delhi to Switzerland");
   }
 }
}
void travel::input()
{
  cout<<"\n Enter your name : ";
  gets(name);
  cout<<"\n Enter e-mail id : ";
  gets(id);
  cout<<"\n Enter the no. of passengers you are travel with : ";
  cin>>mem;
  if(mem>=1 && mem<=10)
  { cout<<"\n Where you want to travel (National = N & Internationl = I) : ";
    cin>>tra;
  }
  travelling(tra,mem);
}
void travel::output()
{ cout<<"\n NAME : "<<name;
  cout<<"\n E-MAIL : "<<id;
  cout<<"\n PASSENGERS : "<<mem;
  cout<<"\n TRAVELLING  NATIONAL/INTERNATIONAL : "<<tra;
  cout<<"\n DESTINATION : "<<dest;
  cout<<"\n TRAVELLING PRICE : "<<price;
}
void entry()              //take the entry
{  char ch='y';
   fout.open("fly.dat",ios::app|ios::binary);
   while(ch=='y'||ch=='Y')
   { system("cls");
     t.input();
     fout.write((char*)&t,sizeof(t));
     cout<<"\n More Record (Y/N) : ";
     cin>>ch;
   }
   fout.close();
}
void display()             //display the entry
{  fin.open("fly.dat",ios::in|ios::binary);
   fin.seekg(0);
   fin.read((char*)&t,sizeof(t));
   while(!fin.eof())
   { t.output();
     cout<<endl;
     fin.read((char*)&t,sizeof(t));
   }
   fin.close();
}
void search()            //search the entry
{ fin.open("fly.dat",ios::in|ios::app|ios::binary);
  char n[20];
  cout<<"\nSearch Your Booking by name : ";
  gets(n);
  while(fin.read((char*)&t,sizeof(t)))
  {  if(strcmpi(n,t.ret_name())==0)
     { t.output();
       fin.read((char*)&t,sizeof(t));
     }
  }
  fin.close();
}
void delete_booking(char* id)        //delete the entry
{ fin.open("fly.dat",ios::in|ios::binary);
  fout.open("second.dat",ios::out|ios::binary);
  char found='n';
  while(fin.read((char*)&t,sizeof(t)))
  { if(strcmpi(id,t.ret_id())!=0)
     {  fout.write((char*)&t,sizeof(travel));   }
    else
     {	found='y';   }
  }
  if(found=='n')
  cout<<"\n record not found";
fin.close();
fout.close();
cout<<"\n Account deleted\n";
remove("fly.dat");
rename("second.dat","fly.dat");
}
void flight()
{ int x; char ans; char id1[30];
  do{   clrscr();
    cout<<"\n....WELCOME TO AIRWAY SERVICES....";
    cout<<"\n 1.Booking for flight";
    cout<<"\n 2.Display bookings";
    cout<<"\n 3.Search your booking";
    cout<<"\n 4.Delete booking";
    cout<<"\n enter your choice : ";
    cin>>x;
    switch(x)
      { case 1: entry();
	break;
	case 2: display();
	break;
	case 3: search();
	break;
	case 4:
	cout<<"\n Enter the id to be deleted : ";
	gets(id1);
	delete_booking(id1);
	break;
	default:
	cout<<"\n Try Again\n";
      }
      cout<<"\n GO BACK TO AIRWAY SERVICES : ";
      cin>>ans;
    }while(ans=='y'||ans=='Y');
}
//==============================================
//TRAVEL BY RAILWAYS
class rail
{
int mem;			//take the input of members
char name[20];		//take input name
char id[30];			//take email id			
unsigned int price;		//take the travelling price
char dest[30];		//take the input of destination
public:
rail()
{ mem=0;
  price=0;
}
char* ret_name()
{ return name; }
char* ret_id()
{ return id;   }
void input();
void travelling(int);
void output();
}r;
//Railway class object = r
void rail::travelling(int mem)
{
int xx;
   cout<<"\n 1.Train-> Delhi to Bhopal";
   cout<<"\n 2.Train-> Delhi to Patna";
   cout<<"\n 3.Train-> Delhi to Varanasi";
   cout<<"\n 4.Train-> Delhi to Punjab";
   cout<<"\n 5.Train-> Delhi to Lucknow";
   cout<<"\n Enter your choice : ";
   cin>>xx;
   cout<<"\n Booking confirmed";
   cout<<"\n Price generted\n";
   if(xx==1)
   { price=(mem*1000);
     strcpy(dest,"Delhi to Bhopal");
   }
   if(xx==2)
   { price=(mem*800);
     strcpy(dest,"Delhi to Patna");
   }
   if(xx==3)
   { price=(mem*500);
     strcpy(dest,"Delhi to Varanasi");
   }
   if(xx==4)
   { price=(mem*450);
     strcpy(dest,"Delhi to Punjab");
   }
   if(xx==5)
   { price=(mem*600);
     strcpy(dest,"Delhi to Lucknow");
   }
}
void rail::input()
{
  cout<<"\n Enter your name : ";
  gets(name);
  cout<<"\n Enter e-mail id : ";
  gets(id);
  cout<<"\n Enter the no. of passengers you are travel with : ";
  cin>>mem;
  if(mem>=1 && mem<=8)
  { travelling(mem);
  }
}
void rail::output()
{ cout<<"\n NAME : "<<name;
  cout<<"\n E-MAIL : "<<id;
  cout<<"\n PASSENGERS : "<<mem;
  cout<<"\n DESTINATION : "<<dest;
  cout<<"\n TRAVELLING PRICE : "<<price;
}
void entry1()              //take the entry
{
   fout.open("rail.dat",ios::app|ios::binary);
   while(1)
   { system("cls");
     r.input();
     fout.write((char*)&r,sizeof(r));
     break;
   }
   fout.close();
}
void display1()             //display the entry
{  fin.open("rail.dat",ios::in|ios::binary);
   fin.seekg(0);
   fin.read((char*)&r,sizeof(r));
   while(!fin.eof())
   { r.output();
     cout<<endl;
     fin.read((char*)&r,sizeof(r));
   }
   fin.close();
}
void search1()            //search the entry
{ fin.open("rail.dat",ios::in|ios::app|ios::binary);
  char n[20];
  cout<<"\nSearch Your Booking by name : ";
  gets(n);
  while(fin.read((char*)&r,sizeof(r)))
  {  if(strcmpi(n,r.ret_name())==0)
     { r.output();
       fin.read((char*)&r,sizeof(r));
     }
  }
  fin.close();
}
void delete_booking1(char* id)        //delete the entry
{ fin.open("rail.dat",ios::in|ios::binary);
  fout.open("new.dat",ios::out|ios::binary);
  char found='n';
  while(fin.read((char*)&r,sizeof(r)))
  { if(strcmpi(id,r.ret_id())!=0)
     {  fout.write((char*)&r,sizeof(rail));   }
    else
     {	found='y';   }
  }
  if(found=='n')
  cout<<"\n record not found";
fin.close();
fout.close();
cout<<"\n Account deleted\n";
remove("rail.dat");
rename("new.dat","rail.dat");
}
void train()
{ int x; char ans; char id1[30];
  do{   clrscr();
    cout<<"\n....WELCOME TO RAILWAY SERVICES....";
    cout<<"\n 1.Booking for train";
    cout<<"\n 2.Display bookings";
    cout<<"\n 3.Search your booking";
    cout<<"\n 4.Delete booking";
    cout<<"\n enter your choice : ";
    cin>>x;
    switch(x)
      { case 1: entry1();
	break;
	case 2: display1();
	break;
	case 3: search1();
	break;
	case 4:
	cout<<"\n Enter the id to be deleted : ";
	gets(id1);
	delete_booking1(id1);
	break;
      }
      cout<<"\n GO BACK TO RAILWAY SERVICES : ";
      cin>>ans;
    }while(ans=='y'||ans=='Y');
}
//=========================================================
//TAVEL BY TAXI
class taxi
{
int mem;			//take the input of members
char name[20];		//take input name
char id[30];			//take email id			
unsigned int price;		//take the travelling price
char dest[30];		//take the input of destination
int base;			//base fare = 50
int pkm;			//price per kilometer = 8
int distance;			//take the value of distance
public:
taxi()
{ mem=0;
price=0;
  pkm=8;
  base=50;	//base fare of taxi
}
char* ret_name()
{ return name; }
char* ret_id()
{ return id;   }
void input();
void travelling(char []);
void output();
}ti;
//Roadway class object = ti
void taxi::travelling(char dest[])
{ if(strcmpi(dest,"Market")==0)
  {  distance=15;
  }
  if(strcmpi(dest,"Hospital")==0)
  {  distance=20;
  }
  if(strcmpi(dest,"Police Station")==0)
  {  distance=10;
  }
  if(strcmpi(dest,"School")==0)
  {  distance=8;
  }
  if(strcmpi(dest,"Mall")==0)
  {  distance=12;
  }
  price=base+(pkm*distance);
}
void taxi::input()
{
  cout<<"\n Enter your name : ";
  gets(name);
  cout<<"\n Enter e-mail id : ";
  gets(id);
  cout<<"\n Enter the no. of passengers you are travel with : ";
  cin>>mem;
  if(mem>=1 && mem<=6)
  { cout<<"\n Enter the destination : ";
    gets(dest);
    travelling(dest);
  }
  else exit(1);
}
void taxi::output()
{ cout<<"\n NAME : "<<name;
  cout<<"\n E-MAIL : "<<id;
  cout<<"\n PASSENGERS : "<<mem;
  cout<<"\n DESTINATION : "<<dest;
  cout<<"\n DISTANCE : "<<distance;
  cout<<"\n TRAVELLING PRICE : "<<price;
}
void entry2()              //take the entry
{
   fout.open("taxi.dat",ios::app|ios::binary);
   while(1)
   { system("cls");
     ti.input();
     fout.write((char*)&ti,sizeof(ti));
     break;
   }
   fout.close();
}
void display2()             //display the entry
{  fin.open("taxi.dat",ios::in|ios::binary);
   fin.seekg(0);
   fin.read((char*)&ti,sizeof(ti));
   while(!fin.eof())
   { ti.output();
     cout<<endl;
     fin.read((char*)&ti,sizeof(ti));
   }
   fin.close();
}
void search2()            //search the entry
{ fin.open("taxi.dat",ios::in|ios::app|ios::binary);
  char n[20];
  cout<<"\nSearch Your Booking by name : ";
  gets(n);
  while(fin.read((char*)&ti,sizeof(ti)))
  {  if(strcmpi(n,ti.ret_name())==0)
     { ti.output();
       fin.read((char*)&ti,sizeof(ti));
     }
  }
  fin.close();
}
void delete_booking2(char* id)        //delete the entry
{ fin.open("taxi.dat",ios::in|ios::binary);
  fout.open("data.dat",ios::out|ios::binary);
  char found='n';
  while(fin.read((char*)&ti,sizeof(ti)))
  { if(strcmpi(id,ti.ret_id())!=0)
     {  fout.write((char*)&ti,sizeof(taxi));    }
    else
     {	found='y';    }
  }
  if(found=='n')
  cout<<"\n record not found";
fin.close();
fout.close();
cout<<"\n Account deleted\n";
remove("taxi.dat");
rename("data.dat","taxi.dat");
}
void road()
{ int x; char ans; char id1[30];
  do{   clrscr();
    cout<<"\n....WELCOME TO ROADWAY SERVICES....";
    cout<<"\n 1.Booking for taxi";
    cout<<"\n 2.Display bookings";
    cout<<"\n 3.Search your booking";
    cout<<"\n 4.Delete booking";
    cout<<"\n enter your choice : ";
    cin>>x;
    switch(x)
      { case 1: entry2();
	 cout<<"\n Booking confirmed";
	 cout<<"\n Price generted\n";
	break;
	case 2: display2();
	break;
	case 3: search2();
	break;
	case 4:
	cout<<"\n Enter the id to be deleted : ";
	gets(id1);
	delete_booking2(id1);
	break;
      }
      cout<<"\n GO BACK TO TAXI SERVICES : ";
      cin>>ans;
    }while(ans=='y'||ans=='Y');
}

void main()
{ clrscr();
  int ch;   char ans='y';
  do{        clrscr();
  cout<<"\n\t       __  ___              ___              ";
  cout<<"\n\t |\\/| |__|  |  |\\ |   |\\/| |__  |\\ | |   |  ";
  cout<<"\n\t |  | |  | _|_ | \\|   |  | |___ | \\| |___|  "<<endl;
  cout<<"\n 1.Airplane booking...";
  cout<<"\n 2.Railway booking...";
  cout<<"\n 3.Taxi booking...";
  cout<<"\n Enter your choice : ";
  cin>>ch;
  switch(ch)
   { case 1:
     flight();
      break;
     case 2:
     train();
      break;
     case 3:
     road();
      break;
     default:
	cout<<"\n Don't waste our time\n";
   }
   cout<<"\n DO YOU WANT TO GOBACK TO MAIN MENU ('Y' OR 'y') : ";
   cin>>ans;
  }while(ans=='y'||ans=='Y');
  getch();
}
