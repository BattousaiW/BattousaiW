//simple donation and net gross calculator using file handling
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    //variables
    string MovieName;
    double adultTicketPrice,childTicketPrice,donation,grossAmount,amountDonated,netSaleAmount;
    int noAdultTickets,noOfChildTickets;

    const int PERCENT = 100;

    //fstream, ostream
    ifstream inFile;
    ofstream outFile;



    cout << fixed << showpoint <<setprecision(2);
    cout <<"Enter the movie name: " ;
    getline(cin,MovieName);
    cout <<endl;
    inFile.open(MovieName + ".txt");
    outFile.open(MovieName + "Data.out");
    inFile >> MovieName;

    cout <<"Enter the price of an adult ticket: ";
    cin >> adultTicketPrice;
    inFile >> adultTicketPrice;
    cout << endl;

    cout <<"Enter the price of a child ticket: ";
    cin >> childTicketPrice;
    inFile >> childTicketPrice;
    cout << endl;

    cout <<"Enter the number of adult tickets sold: ";
    cin >> noAdultTickets;
    inFile >> noAdultTickets;
    cout << endl;

    cout <<"Enter the number of child tickets sold: ";
    cin >> noOfChildTickets;
    inFile >> noOfChildTickets;
    cout << endl;

    cout <<"Enter the percentage of donation: ";
    cin>> donation;

    inFile >> donation;
    cout << endl << endl;

    grossAmount = adultTicketPrice * noAdultTickets + childTicketPrice * noOfChildTickets;

    amountDonated = grossAmount * donation / PERCENT;

    netSaleAmount = grossAmount - amountDonated;

    outFile << "*___**___**___**___**___**___**___**___**___**___**___**___**___**___**___**___**___*" <<endl;
    outFile <<setfill('.') << left <<setw(35) << "Movie Name: " << right << MovieName << endl;
    outFile <<left <<setw(35) << "Number of tickets sold: " <<right << setw(10) << noAdultTickets + noOfChildTickets << endl;
    outFile << setfill('.') <<left << setw(35) << "Gross amount: " << setfill(' ') << right <<" R" <<setw(8) << grossAmount << endl;
    outFile << setfill('.') << left << setw(35) << "Percentage of Gross Amount Donated: "<< setfill(' ') << right<< setw(9) << donation << '%' << endl;
    outFile << setfill('.') << left << setw(35)<< "Amount Donated: " << setfill(' ') << right << " R"<< setw(8) << amountDonated << endl;
    outFile << setfill('.') << left << setw(35) << "Net Sale: "<< setfill(' ') << right << " R"<< setw(8) << netSaleAmount << endl;
    outFile<< "*___**___**___**___**___**___**___**___**___**___**___**___**___**___**___**___**___*" <<endl;

inFile.close();
outFile.close();

    return 0;
    }
