#include<iostream>
using namespace std;

int portstorage;
unsigned int numberofcontainers; 
double weightofcontainer1, weightofcontaineri, totalweight;


int main() {
    cout<<"Enter the maximum port storage capacity: ";
    cin>>portstorage;
    cout<<"Enter the number of containers: ";
    cin>>numberofcontainers;

    //To make sure number of ports isnt 0 or greater than 1000 according to given conditions
    
    if (numberofcontainers <= 0 || numberofcontainers > 1000) {
        cout<<"Please enter a valid number of container. (i.e. between 1 and 1000)";
        return 0;
    }
    
    /*I created a variable which checks everytime in the for loop if the entered number is
    greater or lesser than the numbers entered before them, the first weight is checked 
    separtely to set the varibles to first one in order for there to be something to compare to. */               
    
    /*The total weight is just given by adding all the weights the user entered before the 
    for loop and during the for loop.*/ 
    
    double minval, maxval;
    cout<<"Enter the weight of container no. 1: ";
    cin>>weightofcontainer1;
    totalweight += weightofcontainer1;
    maxval = weightofcontainer1;
    minval = weightofcontainer1;
    
    for (int i=2; i<=numberofcontainers; i ++){
        cout<<"Enter the weight of container no. "<<i<<": ";
        cin>>weightofcontaineri;
        totalweight += weightofcontaineri;
        if (weightofcontaineri> maxval){
            maxval = weightofcontaineri;
        }
        if (weightofcontaineri< minval) {
            minval = weightofcontaineri;
        }
    }

    cout<<"Total Shipment weight: "<<totalweight<<endl;
    cout<<"Average Container weight: "<<totalweight/numberofcontainers<<endl;
    cout<<"Heaviest Container: "<<maxval<<endl;
    cout<<"Lightest Container: "<<minval<<endl;

    if (totalweight>=200){
        cout<<"Classification: Heavy"<<endl;
    }
    else{
        cout<<"Classification: Light"<<endl;
    }

    cout<<"Port Capacity: "<<portstorage<<endl;

    if (totalweight<=portstorage){
        cout<<"Status: Shipment can be unloaded"<<endl;
    }
    else{
        cout<<"Status: Shipment exceeds port capacity"<<endl;
    }

    return 0;
}