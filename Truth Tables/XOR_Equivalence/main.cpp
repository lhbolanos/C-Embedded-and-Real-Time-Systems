

#include <cstdlib>
#include <iostream>



using namespace std;


int main(int argc, char** argv) {
    //Initialize Random Number Seed
    
    //Declare Variables
    
    //Initialize Variables
    
    //Process The Inputs -> Outputs
    //cout<<"p  q  ~p  ~q  p&&q  p||q  p^q  p^q^q  p^q^p  !(p&&q) !p||!q !(p||q) !p^!q"<<endl;
    cout<<"p q (p&&q) (p||q) (p^q) (p&&q)||~(p||q) (p||q)&&~(p&&q)"<<endl;
    for(int p=1;p>=0;p--){
        for(int q=1;q>=0;q--){
            cout
                <<(p?'T':'F')<<" "
                <<(q?'T':'F')<<"   "
                <<((p&&q)?'T':'F')<<"      "
                <<((p||q)?'T':'F')<<"      "
                <<((p^q)?'T':'F')<<"           "
                <<((p&&q)||!(p||q)?'T':'F')<<"               "
                <<(((p||q)&&!(p&&q))?'T':'F')<<"          "
                    <<endl;
        }
    }
    
    cout<<"\n(p&&q)||~(p||q) != p^q and (p||q)&&~(p&&q)= p^q"<<endl;
    
    //Display Results, Verify Inputs
    
    //Clean up and exit
    
    
    return 0;
}

