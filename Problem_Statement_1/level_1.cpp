// Language: C++17
// Compile: g++ level_1.cpp -o level_1
// Run: ./level_1
// Input: enter values directly in terminal when prompted, or pipe a file: ./level_1 < input.txt


#include<iostream>
#include<string>
#include<array>
using namespace std;

int main() {
    int r, c, generations;
    cout<<"Enter the number of rows(1 to 100): ";
    cin>>r;
    
    if(r<1 || r > 100){
        cout<<endl<<"Please enter a valid number of rows.";
        return 0;
    }
    cout<<endl<<"Enter the number of columns(1 to 100): ";
    cin>>c;
    
    if(c<1 || c > 100){
        cout<<endl<<"Please enter a valid number of columns.";
        return 0;
    }

    cout<<endl<<"Enter the number of generations to simulate(0 to 1000): ";
    cin>>generations;
    cout<<"\n";
    if(generations<0 || generations > 1000){
        cout<<endl<<"Please enter a valid number of generations."<<endl;
        return 0;
    }

    int currentstate[r*c +1];
    currentstate[0] = -1;
    for(int i=1; i<=r; i++){//Taking input of dead and alive cells
        string Ri;
        cin>>Ri;
        for(int j =0; j<c; j++){
            if(Ri[j] == '#'){
                currentstate[(i-1)*c + j+1] = 1;
            }
            else{
                currentstate[(i-1)*c + j+1] = 0;
            }
        }
    }
    int initialalivecells = 0;

    for(int i = 1; i<=(r*c); i++){//Counting initial population 
        if(currentstate[i]==1){
            initialalivecells++;
        }
    }
    
    /*for troubleshooting
    for(int i=1; i <=(r*c); i++){
        cout<<currentstate[i]<<", ";
    }*/

    int peakpopulation = initialalivecells;

    if(generations!=0){
    
    int k =0;
    
    
    do{
        int tempstate[r*c +1];
        for(int i =0; i<=(r*c); i++){
            tempstate[i]=currentstate[i];
        }

        for(int i = 1; i <= r; i++){
            for(int j = 0; j<c; j++){
                int countofalive=0;
                if(i!=1){//top
                    countofalive += tempstate[(i-2)*c + j+1];
                }
                if(i!=1 && j!=0){//top left
                    countofalive += tempstate[(i-2)*c + j];
                }
                if(i!=1 && j!=(c-1)){//top right
                    countofalive += tempstate[(i-2)*c + j+2];
                }
                if(j!=(c-1)){//right
                    countofalive += tempstate[(i-1)*c + j+2];
                }
                if(j!=0){//left
                    countofalive += tempstate[(i-1)*c + j];
                }
                if(i!=r){//bottom
                    countofalive += tempstate[(i)*c + j+1];
                }
                if(i!=r && j!=0){//bottom left
                    countofalive += tempstate[(i)*c + j];
                }
                if(i!=r && j!=(c-1)){//bottom right
                    countofalive += tempstate[(i)*c + j+2];
                }
                if(tempstate[(i-1)*c +j+1]==1){
                    if(countofalive<=1){
                        currentstate[(i-1)*c +j+1]=0;
                    }
                    else if(countofalive==2 || countofalive==3){
                        currentstate[(i-1)*c +j+1]=1;
                    }
                    else if(countofalive>3){
                        currentstate[(i-1)*c +j+1]=0;
                    }
                }
                else if(tempstate[(i-1)*c +j+1]==0){
                    if(countofalive==3){
                    currentstate[(i-1)*c +j+1]=1;
                    }
                }
                
            }

        }

        int currentpopulation = 0;
        for(int i = 1; i<=(r*c); i++){//Counting peak population 
            if(currentstate[i]==1){
                currentpopulation++;
            }
        }

        if(currentpopulation>peakpopulation) peakpopulation=currentpopulation;

        k++;
    } while(k<generations);
}

    int finalpopulation = 0;
    

    for(int i = 1; i<=(r*c); i++){//Counting final population 
        if(currentstate[i]==1){
            finalpopulation++;
        }
    }


    cout<<"Initial population: "<<initialalivecells<<endl;
    cout<<"Final population: "<<finalpopulation<<endl;
    cout<<"Peak population: "<<peakpopulation<<endl;
    cout<<"Final grid:"<<endl;

    for(int i=1; i<=r; i++){//Outputting dead and alive cells
        
        for(int j =0; j<c; j++){
            if(currentstate[(i-1)*c + j+1]==1){
                cout<<'#';
            }
            else if(currentstate[(i-1)*c + j+1]==0){
                cout<<'.';
            }
        }
        cout<<endl;
    }


    return 0;
}