

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();
void prpLuhn(char[],int);
void Luhn(char[],int);

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=12;
    char crdCard[SIZE];
    char tstCrd[] = "5800580710\0";
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    
    
    Luhn(crdCard,SIZE-2);
    //cout<<"The random number with Luhn Encoding, Output Here!"<<endl;
    //cout<<crdCard<<endl;
    
   
    
    
    //Exit Stage Right
    return 0;
}

void Luhn(char crdCard[],int SIZE){
    
    int nwCard[SIZE];
    
    int wat[] = {1,2,3,4,5};
    
    int a;
    int b;
    
    for(int i=0;i<SIZE;i++){
        nwCard[i] = crdCard[i] - 48;
        
        //a = crdCard[i] - 48;
        //cout << "Test a : " << a << endl;
        //b = crdCard[i];
        
        
        //nwCard[i]=nwCard[i]-'0';
    }
    
    
    //cout << "Test 1 chrArr: " << crdCard << endl;
    cout << "Account Number: ";
    
    
    for (int i=0;i<SIZE;i++){
        cout << nwCard[i];
    
    }
    
    cout << "\n";
    
    int newArr[SIZE];
    
    int count = 0;
    
    for (int i=0;i<SIZE;i++){
        
        
        
        //cout<<"Temp = " << temp << endl;
            
        
        if (i%2==1){
            
            
            //cout<<i;
            int temp = nwCard[i]*2;
            newArr[i] = nwCard[i]*2;
            
                
            //cout << "Ele # " << i << " == " << temp << endl;
                if (temp>=10){

                    //cout<< "Element: " << i << " " << temp <<" --> ";
                    newArr[i] = temp%10+(temp/10);
                    //cout<<" newArr = " << newArr[i] << endl;
                }
        }
        else{
            newArr[i]=nwCard[i];
            
            
            }
        //i++;
        
    }
    
    cout<<"\n";
    
    
    int totalSum = 0;
    
    for(int i = 0;i<SIZE;i++){
        totalSum = totalSum + newArr[i];
    }
    
   cout<<"Double every other: ";
    
    for (int i=0;i<SIZE;i++){
        cout << newArr[i];
    
    }
    
     cout << "\n";
     
     cout << "Total: " << totalSum;
     
     cout << "\n";
     
     int checkDigit = 0;
     
     checkDigit = (totalSum*9)%10;
     
     
     int f = (totalSum+checkDigit)%10;
     
     cout << "Check Digit: " << checkDigit << endl;
     
     if ((totalSum+checkDigit)%10==0){
         
         cout<<"Card is VALID."<<endl;
     }
     else{
         cout<<"Card is INVALID"<<endl;
     }
     
     
     
    
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+48;
}