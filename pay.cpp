#include "person.cpp"

using namespace std;

//Function Prototypes
void readData(Person P[], int &size);
void writeData(Person P[], int &size);

int main()
{
  int size;
  int temp = 20;
  Person p[temp];
  readData(p,size);
  writeData(p,size);
  return 0;
}

//Reads in a data file and initializes each person's info
void readData(Person P[], int &size)
{
  int i =0;
  string firstname;
  string lastname;
  float hours;
  float pay;

  ifstream infile;
  infile.open("input.txt");
  if (!infile)
  {
    cout<< "File not found. Exiting."<<endl;
    exit(1);
  }

  while (!infile.eof())
  {
    infile >> firstname >> lastname >> hours >> pay;
    P[i].setFirstName(firstname);
    P[i].setLastName(lastname);
    P[i].setPayRate(pay);
    P[i].setHoursWorked(hours);
    i++;
    infile>>ws;
  }

  size = i;

  infile.close();
}

//Outputs person's name and pay rate to a different text file
void writeData(Person P[], int &size)
{
  ofstream outfile;
  outfile.open("output.txt");
  if (!outfile)
  {
    cout<< "File not found. Exiting."<<endl;
    exit(1);
  }

  for (int i = 0; i<size; i++)
  {
    outfile << P[i].fullName() << " " << fixed << setprecision(2) << P[i].totalPay()<<endl;

  }

  outfile.close();
}
