

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string filename;
    
    cout << "Enter name of file you want to write: ";
    getline(cin, filename, '\n');
    
    ofstream outputFile;
    
    outputFile.open(filename.c_str());
    
    if (outputFile){
        
        float input;
        do {
            
            cout << "Enter a floating point (-999999 to stop): ";
            cin >> input;
            
            if (input == -999999) {
                
                break;
                
            } 
            
            outputFile << setw(8) << input << "\r\n";
            outputFile.flush();
            
        }while (input != -999999);
    }
    else {
        
        cout << "File could not be opened for writing.." << endl;
        return 1;
        
        
    }
    
    outputFile.close();
    cout << "File named: " << filename << " written." << endl;
    
    
	return 0; 
}
