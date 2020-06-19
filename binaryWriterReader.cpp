#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

using namespace std;

    string fileName;
    int rows;
    int cols;
    
  

int random_generator() {
    


    ofstream outFile;
    


    cout << "Please enter a file name to write : ";
    getline(cin, fileName);
    fileName += ".bin";
    
    outFile.open(fileName.c_str(), ios::binary); // note: ios::binary tells C++ to open the file as binary file mode

        cout << "Enter number of rows: " << endl;
        cin >> rows;
        cout << "Enter number of columns: " << endl;
        cin >> cols;
    
    if (outFile) {

        long double arr[rows][cols];
        
        srand (static_cast <unsigned> (time(0)));
        

        
        
        for (int i=0;i<rows;i++){
            
            for (int j=0;j<cols;j++){
                
                long double r = static_cast <long double> (rand()) / static_cast <long double> (RAND_MAX);
                arr[i][j] = r;
                
            }
        
    }

        // output the values is done with the write function, the write
        // function requires only the address of the data we want to write,
        // and how many bytes in size of the data ( we have to cast the
        // address returned by the address operator as a (char *) or byte 
        // pointer.
        
        outFile.write((char *) &arr, sizeof (arr));

        outFile.close();
        cout << "File: " << fileName.c_str() << " successfully written.\n";
    } else {
        cout << "Could not open" << fileName.c_str() << " for output\n";
        return 1;
    }
    
    ifstream inFile;
     
    cout << "Enter file name: ";
    cin >> fileName;
    
    inFile.open(fileName.c_str(), ios::binary); // note: ios::binary tells C++ to open the file as binary file mode
    

    
    if (inFile) {
       
        long double arr[rows][cols];
        
        // read the values is done with the read function, the read
        // function requires only the address of where we want to store
        // the read data into memory, and how many bytes in size of the data 
        // to read ( we have to cast the address returned by the address 
        // operator as a (char *) or byte pointer.
        
        inFile.read((char *) &arr, sizeof (arr));

        inFile.close();
        cout << "File: " << fileName << " successfully read.\n";
        cout << "Here are the values:\n";
        
        cout << "Rows: " << rows << endl;
        cout << "Cols: " << cols << endl;
        
        for (int i = 0; i < rows; i++){
            
            for (int j = 0; j<cols;j++){
                
                cout << arr[i][j] << " ";
                
            }
            cout << endl;
        }
    } else {
        cout << "Could not open data.bin for reading\n";
        return 1;
    }
    
    
    return 0;

}
    
   
   
    

int read_binary_file_demo()
{
    // demo function that reads binary data from a file named data.bin in the following format:
    // {unsigned short int}
    // {short int}
    // {unsigned int}
    // {int}
    // {unsigned long long}
    // {long long}
    // {float}
    // {double}
    
    ifstream inFile;
    
    cout << "Enter file name: ";
    cin >> fileName;
    
    inFile.open(fileName.c_str(), ios::binary); // note: ios::binary tells C++ to open the file as binary file mode
    
    if (inFile)
    { long double arr[rows][cols];
        
        
        // read the values is done with the read function, the read
        // function requires only the address of where we want to store
        // the read data into memory, and how many bytes in size of the data 
        // to read ( we have to cast the address returned by the address 
        // operator as a (char *) or byte pointer.
        inFile.read((char *) &arr, sizeof (arr));
        
        
        cout << "FileRead";
        
        for (int i = 0; i < rows; i++){
            
            for (int j = 0; j<cols;j++){
                
                cout << arr[i][j] << " ";
                
            }
            cout << endl;
        }
        
        
        inFile.close();
        cout << "File: " << fileName << " successfully read.\n";
        cout << "Here are the values:\n";
        for (int i = 0; i < rows; i++){
            
            for (int j = 0; j<cols;j++){
                
                cout << arr[i][j] << " ";
                
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Could not open data.bin for reading\n";
        return 1;
    }    
    return 0;
}


int main() {
    

    
    random_generator();
    
 
    
    
    
}


