#include <iostream> 
using namespace std; 
#include <algorithm>
#include <string> 
#include <iomanip> 
/*I defined a seperate header file to read from
and improve readability*/ 
#include "Linereader.h" 
typedef LineOneData L1; 
typedef LineTwoData L2;  

int main(){
    string line1, line2; 
    cout << "Welcome to my Version 1 of my Simple TLE Parser" << endl; 
    cout << "Paste Line 1 of your TLE: "; 
    getline(cin, line1); 
    cout << "Paste Line 2 of your TLE: "; 
    getline(cin, line2);
    L1 line1data = Line1(line1);
    L2 line2data = Line2(line2); 
    
    // NOTE: This parser is for STANDARD TLE format only.
// Non-standard TLEs will throw an error.

// ********************************************************************
// *  STANDARD TLE FORMAT PARSER - NON-STANDARD TLES WILL THROW ERROR  *
// ********************************************************************

{
    // Line 1 Output
    cout << "=================================================" << endl;
    cout << "|              TLE LINE 1 DATA                  |" << endl;
    cout << "|===============================================|" << endl;
    cout << "| Line Number: " << setw(33) << left << line1data.LineNum << "|" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "| Satellite Number: " << setw(28) << left << line1data.SatNumber << "|" << endl;
    cout << "| Classification: " << setw(30) << left << line1data.classification << "|" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|            INTERNATIONAL DESIGNATOR           |" << endl;
    cout << "| Launch Year: " << setw(33) << left << line1data.LaunchYear << "|" << endl;
    cout << "| Launch Number: " << setw(31) << left << line1data.LaunchNum << "|" << endl;
    cout << "| Piece Designation: " << setw(27) << left << line1data.PieceofLaunch << "|" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "| Epoch Year: " << setw(34) << left << line1data.Epoch_year << "|" << endl;
    cout << "| Epoch: " << setw(39) << left << line1data.Epoch << "|" << endl;
    cout << "| 1st Deriv Mean Motion: " << setw(23) << left << line1data.FTD << "|" << endl;
    cout << "| 2nd Deriv Mean Motion: " << setw(23) << left << line1data.STD << "|" << endl;
    cout << "| BSTAR Drag: " << setw(34) << left << line1data.BSTAR << "|" << endl;
    cout << "| Ephemeris Type: " << setw(30) << left << line1data.EphemType << "|" << endl;
    cout << "| Element Set Number: " << setw(26) << left << line1data.ElemNum << "|" << endl;
    cout << "| Checksum: " << setw(36) << left << line1data.CheckSum << "|" << endl;
    cout << "=================================================" << endl << endl;
}

{
    // Line 2 Output
    cout << "=================================================" << endl;
    cout << "|              TLE LINE 2 DATA                  |" << endl;
    cout << "|===============================================|" << endl;
    cout << "| Line Number: " << setw(33) << left << line2data.LineNum << "|" << endl;
    cout << "| Satellite Number: " << setw(28) << left << line2data.SatNumber << "|" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "| Inclination [deg]: " << setw(27) << left << line2data.inclination << "|" << endl;
    cout << "| RAAN [deg]: " << setw(34) << left << line2data.RightAscension << "|" << endl;
    cout << "| Eccentricity: " << setw(32) << left << line2data.Eccentricity << "|" << endl;
    cout << "| Arg of Perigee [deg]: " << setw(24) << left << line2data.Perigee << "|" << endl;
    cout << "| Mean Anomaly [deg]: " << setw(26) << left << line2data.MeanAnomaly << "|" << endl;
    cout << "| Mean Motion [rev/day]: " << setw(23) << left << line2data.MeanMotion << "|" << endl;
    cout << "| Rev Number at Epoch: " << setw(25) << left << line2data.RevolutionNum << "|" << endl;
    cout << "| Checksum: " << setw(36) << left << line2data.CheckSum << "|" << endl;
    cout << "=================================================" << endl;
}
    system("pause"); 
}