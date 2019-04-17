//Brian Chairez
//CPSC 301 Section 2

// Brian Chairez
// 301 Section 2
#include "person.cpp"
#include <vector>

using namespace std;

//Function Prototypes
void readData(vector<Person> &P);
void writeData(vector<Person> &P);

int main()
{
  vector<Person> p;
  readData(p);
  writeData(p);
  return 0;
}

//Reads in a data file and initializes each person's info
void readData(vector<Person> &P)
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

  while (infile)
  {
    infile >> firstname >> lastname >> hours >> pay;
    Person per(firstname, lastname, hours, pay);
    P.emplace_back(per);
  }

  i = P.size();

  infile.close();
}

//Outputs person's name and pay rate to a different text file
void writeData(vector<Person> &P)
{
  ofstream outfile;
  outfile.open("output.txt");
  if (!outfile)
  {
    cout<< "File not found. Exiting."<<endl;
    exit(1);
  }

  for (int i = 0; i<P.size(); i++)
  {
    outfile << P.at(i).fullName() << " " << fixed << setprecision(2) << P.at(i).totalPay()<<endl;

  }

  outfile.close();
}
