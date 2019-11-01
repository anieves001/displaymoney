#include<iostream>
#include<string>
#include "hands.h"

using  namespace std;

string displaymoney(double money);

int main(){

	double amount;
	cout<<"Enter amount: ";
	cin>>amount;
	string hand=displaymoney(amount);
	cout<<hand;
	return 0;
}

string displaymoney(double money){
	
	/*	
			Each if statement addresses the placement of commas in 1,000 10,000 and 100,000 respectively.
			Larger values are simply extensions with the same comma placements as the former.
			Since a double that is converted to a string produces a decimal with six 0's appended to it,
			the modulus of the number size with values 11, 12 and 13 produce values that are divisible by 3 for
			1,000 10,000 and 100,000 respectively.
			11,14,17  		12,15,18  		13,16,19		  
			1000.000000      	10000.000000   		100000.000000   	 	
			1000000.000000		10000000.000000		100000000.000000
			1000000000.000000	10000000000.000000	100000000000.000000
			We also make sure we dont place any commas after the decimal.


		*/	
	string dollars=to_string(money);
	string accum;
	char test;
	int j=0;

	for(int i =0;i<dollars.size()-4;i++){
		accum+=dollars[i];
		test=dollars[i+1];
		
		if(((dollars.size()%11)%3==0)&&!(test=='.')&&(i<dollars.size()-7)){
			//condition value is in the 1,000's 1,000,000's 1,000,000,000's...etc.	
			if(i==0||j==3){	
				accum+=",";
				j=0;
			}
			j++;			
		}
		else if(((dollars.size()%12)%3==0)&&!(test=='.')&&(i<dollars.size()-7)){
			//condition value is in the 10,000's 10,000,000's 10,000,000,000's...etc.
			if(i==1||j==3){
				accum+=",";
				j=0;
			}
			j++;
		}
		else if(((dollars.size()%13)%3==0)&&!(test=='.')&&(i<dollars.size()-7)){
			//condition value is in the 100,000's 100,000,000's 100,000,000,000's...etc
			if(i==2||j==3){
				accum+=",";
				j=0;
			}
			j++;
		}
				
	}
	return accum;
}

