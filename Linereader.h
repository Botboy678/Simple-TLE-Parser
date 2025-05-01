#ifndef LINEREADER_H
#define LINEREADER_H
#include <algorithm>
#include <string> 
#include <cstdlib> 




struct LineOneData{
    //Feels like there's a better way to do this
    string LineNum, SatNumber, classification; 
    string LaunchYear, LaunchNum, Epoch, Epoch_year, FTD, BSTAR; 
    string STD, EphemType, ElemNum, CheckSum; 
    string PieceofLaunch;
    }; 

struct LineTwoData{
    string LineNum, SatNumber, inclination, RightAscension, Eccentricity; 
    string Perigee, MeanAnomaly, MeanMotion, RevolutionNum, CheckSum; 
}; 

//checkSum Validator 
bool checkSum(string line){
    //checks if the last element is a digit
    if(!(isdigit(line[68]))) return false; 

    //converting last element to an integer
    int checkSum = line[68] - '0'; 
    int total = 0; 

    for (int i = 0; i < line.size()-1; i++){
        if(line[i] == '-' ){
            total += 1; 
        }
        else if(isdigit(line[i])){
        char num = line[i];
        /*Okay here's a breakdown of what's going on here
        number is a character yes but it represents an ASCII value and these values 
        are sequential so if say you take a char '5' which is value (53) and minus by '0' (48) then 
        the result is 5 since you can't minus chars it returns the ASCII value instead*/
        total += num - '0'; 
        }
        else{total += 0;}    
    }
    total %= 10; 
    return (total == checkSum);   
}



LineOneData Line1(string Line){
    LineOneData line1; 
    line1.LineNum = Line.substr(0, 1); 
    line1.SatNumber = Line.substr(2, 5); 
    line1.classification = Line.substr(7, 1); 
    line1.LaunchYear = Line.substr(9, 2); 
    line1.LaunchNum = Line.substr(11, 3);  
    line1.PieceofLaunch = Line.substr(14, 3); 
    line1.Epoch = Line.substr(20, 12);
    line1.Epoch_year = Line.substr(18, 2);
    line1.STD = Line.substr(44, 8); 
    line1.FTD = Line.substr(33, 10); 
    line1.BSTAR = Line.substr(53, 8); 
    line1.EphemType = Line.substr(62, 1); 
    line1.ElemNum = Line.substr(64, 5);  
    // Checksum validation
    if (Line.length() >= 69 && checkSum(Line)) {
        line1.CheckSum = Line.substr(68, 1);
    } else {
        line1.CheckSum = "False";
    }
    return line1; 
}

    
    LineTwoData Line2(string Line){
    LineTwoData Line2; 
    Line2.LineNum = Line.substr(0,1); 
    Line2.SatNumber = Line.substr(2,5); 
    Line2.inclination = Line.substr(8,8);
    Line2.RightAscension = Line.substr(17,8); 
    Line2.Eccentricity = Line.substr(26,7); 
    Line2.Perigee = Line.substr(34,8); 
    Line2.MeanAnomaly = Line.substr(43,8); 
    Line2.MeanMotion = Line.substr(52,5);
    Line2.RevolutionNum = Line.substr(63,5);
    // Checksum validation
    if (Line.length() >= 69 && checkSum(Line)) {
        Line2.CheckSum = Line.substr(68, 1);
    } else {
        Line2.CheckSum = "False";
    }
    return Line2; 
    }; 

    


#endif