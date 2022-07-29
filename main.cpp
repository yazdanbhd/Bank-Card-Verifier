#include <iostream>


using namespace std;

int main()
{

    int separator[16],j=0,sumOfNumbers=0,sumOfEvenNumbers=0,temp=0,bankNumber[4];
    while(true)
    {
        for(int i=0;i<4;i++){
            cin>>bankNumber[i];
            for(int t=0;t<4;t++){

                separator[0+j]=bankNumber[i]%10;
                j++;
                bankNumber[i]=bankNumber[i]/10;
            }
        }

        for(int i=0;i<16;i+=4){
            for(int p=i,j=i+4;p<j;p++,j--){
                temp=separator[p];
                separator[p]=separator[j-1];
                separator[j-1]=temp;
            }
        }

        for(int i=0;i<16;i++){
            if(i%2==0)
            {
                separator[i]*=2;
                if(separator[i]>9)
                    separator[i]-=9;

                sumOfNumbers+=separator[i];
            }
            if(i%2!=0)
                sumOfEvenNumbers+=separator[i];
        }
        if(((sumOfEvenNumbers)+(sumOfNumbers))%10!=0)
            cout<<"No"<<endl;

        else if(((sumOfEvenNumbers)+(sumOfNumbers))%10==0)
            if((sumOfEvenNumbers+sumOfNumbers)==0)
                break;
            else
                cout<<"Yes"<<endl;

        j=0; sumOfNumbers=0; sumOfEvenNumbers=0; temp=0;
    }
}



