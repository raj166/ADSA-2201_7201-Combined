//====================================
// Algorithm & Data Structure Analysis
// Student: Raj Pravin Patel
// Student ID: a1809073
// Semester: 2
// Year: 2022
// Assignment: 1
//=====================================

//Importing libraries.
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <functional>

using namespace std;


//Adding two Numbers represented as string
//Function name: School_Addition
//Parameter: String I1,I2 and int B
//Return: String 
string School_Addition(string I1, string I2 , int B){
    int carry = 0, temp_add, size_difference;
    string Addition_result;

    //Equal the size of the string by appending 0 at the front of I2
    if(I1.size() > I2.size()){
        size_difference = I1.size() - I2.size();
		//append the I2 to string of zeros the number of zeros is the diffrence of length in I1,I2
        I2 = string(size_difference , '0').append(I2);
    }

    //Equal the size of the string by appending 0 at the front of I1
    if(I1.size() < I2.size()){
        size_difference = I2.size() - I1.size();
		//append the I1 to string of zeros the number of zeros is the diffrence of length in I1,I2
        I1 = string(size_difference , '0').append(I1);
    }

	//perform addition element be element 
    for(int i = I1.size()-1; i >-1; i--){
        int temp_bit_add;
        temp_bit_add = (I1[i] - '0') + (I2[i] - '0') + carry;
        
		//if the sum is creater than Base value set carry 
        if(temp_bit_add >=B){
            temp_add = temp_bit_add%B;
            carry = temp_bit_add/B;
            Addition_result = Addition_result + to_string(temp_add);
        }
		//if the sum of 2 elemets of I1 and I2 is small than base then addd the s1 to the result string
        else{
            Addition_result = Addition_result + to_string(temp_bit_add);
            carry = 0;
        }

    }

    if(carry!=0){
        Addition_result = Addition_result + to_string(carry);
    }
    
    reverse(Addition_result.begin(),Addition_result.end());
    
    return Addition_result;

}

//Subtraction of two Numbers represented as string
//Function name: School_Subtraction
//Parameter: String I1,I2 and int B
//Return: String 
string School_Subtraction(string I1, string I2 , int B){
    int carry = 0, temp_sub, size_difference;
    string Subtraction_result;

    //Equal the size of the string by appending 0 at the front of I2
    if(I1.size() > I2.size()){
        size_difference = I1.size() - I2.size();
		//append the I2 to string of zeros the number of zeros is the diffrence of length in I1,I2
        I2 = string(size_difference , '0').append(I2);
    }

    //Equal the size of the string by appending 0 at the front of I1
    if(I1.size() < I2.size()){
        size_difference = I2.size() - I1.size();
		//append the I1 to string of zeros the number of zeros is the diffrence of length in I1,I2
        I1 = string(size_difference , '0').append(I1);
    }

	//perform Subtraction element be element 
    for(int i = I1.size()-1; i >-1; i--){
        int temp_bit_I1, temp_bit_I2 ;

        temp_bit_I1 = (I1[i] - '0') - carry;
        temp_bit_I2 = (I2[i] - '0');

		//if I2 is grater then I1-c then set carry to 1
        if(temp_bit_I2 > temp_bit_I1){
            temp_sub = temp_bit_I1 + B - temp_bit_I2;
            carry = 1;
            Subtraction_result = Subtraction_result + to_string(temp_sub);
        }
		//if I1-c is grater then I2 then set carry to zero
        else{
            temp_sub = temp_bit_I1 - temp_bit_I2;
            carry = 0;
            Subtraction_result = Subtraction_result + to_string(temp_sub);
        }

    }

    reverse(Subtraction_result.begin(),Subtraction_result.end());
    
    return Subtraction_result;

}

//Multiplication of two Numbers represented as string
//Function name: School_Multiplication
//Parameter: String I1,I2 and int B
//Return: String 
string School_Multiplication(string I1,string I2 , int B){
    int temp_mul , carry = 0;
    string temp2 ,Addition_adjustment_par_mul , Multiplication_result ;

    for(int i = I2.size()-1; i > -1; i--){
        carry = 0;
        
        //append zeros and adjust the partial multiplication
        for(int l = I2.size() -i - 1; l > 0 ; l--){
            Addition_adjustment_par_mul.append(to_string(0));
        }

        for(int j = I1.size()-1; j >-1; j--){
			// cout << endl<< I1[j] << " Value of I1[i] - 0 " << I1[j]-'0' << " I2[i] " << I2[i] << "Value of I2[i] - 0 " << I2[i]-'0' << endl;
            temp_mul = int((I2[i] - '0')*(I1[j] - '0')) + carry;

            if(temp_mul >=B){
                Addition_adjustment_par_mul.append(to_string(temp_mul%B));
                carry = temp_mul/B;
            }
            else{
                Addition_adjustment_par_mul.append(to_string(temp_mul));
                carry = 0;
            }
        }

        if(carry!=0){
            Addition_adjustment_par_mul.append(to_string(carry));
        }

        reverse(Addition_adjustment_par_mul.begin(),Addition_adjustment_par_mul.end());
        
        //add the partial multiplication to the result
        Multiplication_result = School_Addition(Multiplication_result , Addition_adjustment_par_mul , B);
        
        //clear the string for next partial multiplication
        Addition_adjustment_par_mul.clear();
    }
    return Multiplication_result;

}

//Multiplication of two string using Karatsuba_multiplicationAlgo
//Function name: School_Addition
//Parameter: String I1,I2 and int B
//Return: String
string Karatsuba_Multiplication(string I1,string I2, int B){
    string p0, p1, p2, a0, a1, b0, b1, p1_mul , p1_add, Multiplication_result;
    int max_size, half , size_difference;


    //append zero at front to equal the strings
	if(I1.size()>I2.size()){
		size_difference = I1.size()-I2.size();
		I2 = string(size_difference,'0').append(I2);
	}

	//append zero at front to equal the strings
	if(I2.size()>I1.size()){
		size_difference = I2.size()-I1.size();
		I1 = string(size_difference,'0').append(I1);
	}

    max_size = max(I1.size(), I2.size());

	//if the size is less than 4 digits use the school multiplication
    if(max_size < 4){
        return School_Multiplication(I1,I2,B);
    }

    //calculate half to divide the string in two parts
	half =  I1.size()/2;												
	reverse(I2.begin(),I2.end());									
	reverse(I1.begin(),I1.end());

    //divide the string in two half
	a0 = I1.substr(0, half);
	a1 = I1.substr(half,I1.length()-a0.length());
	b0 = I2.substr(0, half);
	b1 = I2.substr(half, I2.length()-b0.length());
    
    reverse(a0.begin(),a0.end());
	reverse(a1.begin(),a1.end());
	reverse(b0.begin(),b0.end());
	reverse(b1.begin(),b1.end());

	//calculate p0 = a0*b0
	if(a0.size()==1)
		p0 =School_Multiplication(a0, b0,B);
	else
		p0 = Karatsuba_Multiplication(a0, b0,B);
	
	//calculate p2 =  a1*b1
	if(a1.size()==1)
		p2 = School_Multiplication(a1, b1,B);
	else
		p2 = Karatsuba_Multiplication(a1, b1, B);

	//p1_mul = (a1+a0)*(b1+b0)
	p1_mul = Karatsuba_Multiplication(School_Addition(a1,a0,B),School_Addition(b1, b0,B),B);
	
	//p1_add = (a1*b1) + (a0*b0)
	p1_add = School_Addition(p2,p0,B);
	
	//p1 = (a1+a0)*(b1+b0) - ((a1*b1) + (a0*b0))
	p1 = School_Subtraction(p1_mul,p1_add,B);

	
	reverse(p2.begin(),p2.end());
	reverse(p1.begin(),p1.end());
	
	//multiplting p2*B^2n
	p2 = string(2*half,'0').append(p2);
	
	//multiplting p1*B^n
	p1 = string(half,'0').append(p1);
	reverse(p2.begin(),p2.end());
	reverse(p1.begin(),p1.end());
	
	//Multiplication_result = p2+p2+p0
	Multiplication_result = School_Addition(School_Addition(p2, p1,B), p0,B);

	//remove leading zeros
	Multiplication_result.erase(0,Multiplication_result.find_first_not_of('0'));

	//return the results
	return Multiplication_result;

}

//Compare the string I1 and I2 and return which one is the largest
//Function name: compare
//Parameter: String I1,I2
//Return: int
// I1 > I2 return 2;
// I1 < I2 return 1;
// I1 == I2 return 3;
int compare(string I1,string I2){
    int flag=0 , i=0;
    int I1_size = I1.size();
	int I2_size = I2.size();
	
	//compare the size and return 1 if I2 is greater and return 2 is I1 is greater
	if(I1_size<I2_size) 
		flag=1;
	else if(I1_size> I2_size)
		flag=2;

	while(flag==0 && i<=I1_size-1){
        
        //get the single bit and compare 
		int I1_bit = I1[i]-'0', I2_bit = I2[i]-'0';

        //compare individual digit and return 1 or 2 accordingly
		if(I1_bit < I2_bit) 
			flag =1;
		else if(I1_bit > I2_bit ) 
			flag=2;
        
        //enter at the end of string I1 as the i = I1.size both the string are same return 3 
		else if(flag==0 && i== I1_size-1) 
			flag=3;
		i++;
	}
	return flag;
}

//Division of two numbers represented as string
//Function name: School_Division
//Parameter: String I1,I2 and int B
//Return: String 
string School_Division(string I1,string I2 , int B){
    string quotient, multi;
    int I1_size = I1.size(), I2_size = I2.size();

    //if divisor is greater than divident
    if(I2_size>I1_size)
		quotient="0";
        //if size of the string is equal
    else if (I2_size==I1_size){

        int flag = compare(I1, I2);

    	//I1 < I2 and division can't happen
        if(flag==1) 
            quotient="0";
        
        //I1,I2 are same
        else if(flag == 3) 
            quotient = "1";
        
        // I1 is grater than I2 so we can divide it 
        else if(flag == 2){
            int par_division = (I1[0]-'0')/(I2[0]-'0');
            multi = School_Multiplication(I2, to_string(par_division), B);
            int temp0 = compare(I1, multi);
            if(temp0==1)
                quotient.append(to_string(par_division-1));
            else
                quotient.append(to_string(par_division));
        }
    }
    //if the size is not same
    else{

		int i, j, diff_size, q, flag=0, c=0, temp0=0, temp1 = 0;
		string diff;

		//loop through the I1 size and i increase according to the size of I2
		for(i=0;i<=I1.size()-1;i=i+c){
			temp1=0;
			c=0;
			j=i;
			diff_size = I2.size()-diff.size();
			while(diff_size!=0 && j<I1.size()){
				if(c>0 && i!=0){ 
					// if the numbers in I1 is not divisible by I2 then add zero to the qotient and try adding one more bit to it and divide
					quotient.push_back('0');
				}
				//add digit by digit to see to see if it is divisible by I2 or not
				diff.push_back(I1[j]);
				j++;
				diff_size--;
				c++;	
			}
			//Divisible or not or is it the same number
			flag= compare(diff, I2);
			if(flag==1){
				if(j<I1.size()){
					diff.push_back(I1[j]);
					if(c>0 && i!=0) 
						quotient.push_back('0');
					c++;

					}
				else{
					quotient.append("0");
					temp1 =1;
				}
			}else if(flag==3) {
				quotient.append("1");
				diff="";
			}
			if((flag==2 || c!=0) && flag!=3 && temp1==0){
				q=B;
                int m=1; 
                temp0=0;
				while(temp0==0 || temp0==1){
					q = B-m;
					multi= School_Multiplication(I2, to_string(q), B);
					temp0= compare(diff, multi);
					m++;
				}
				quotient.append(to_string(q));

				//subtract the multi = I2* q from I1 
				diff = School_Subtraction(diff, multi, B);

				//remove the leading zeros
				diff.erase(0,diff.find_first_not_of('0'));
			}
		}
	}
    return quotient;
}

int main(){
    char input[210];
    vector<char*> v;

    //read data from the terminal with max size of 210-> I1(100), I2(100), B(10) and add into char input[220]
    cin.getline(input, 210);

    //split the input data based on " " to get I1,I2,Base
	char* chars_array = strtok(input, " ");

    while(chars_array)
    {
		//input the I1,I2,base into the vector v
        v.push_back(chars_array);
        
		// proceed till ther is no token
		chars_array = strtok(NULL, " ");

    }

    string I1= v[0];
    string I2=v[1];
    string base =v[2];

    int Base = stoi(base);
	
	string sum = School_Addition(I1, I2, Base);
	cout<< sum << " " ;

	string K_multiplication = Karatsuba_Multiplication(I1, I2, Base);
	cout<< K_multiplication << " " ;

   	string Quotient = School_Division(I1,I2,Base);
	cout<< Quotient << " " ;

}

//references
//https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/?ref=rp
//https://www.geeksforgeeks.org/karatsuba-algorithm-for-fast-multiplication-of-large-decimal-numbers-represented-as-strings/?ref=rp
//https://www.geeksforgeeks.org/karatsuba-algorithm-for-fast-multiplication-using-divide-and-conquer-algorithm/?ref=gcse
