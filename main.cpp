#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    ifstream f("date.in");
    int n, nrFin;
    f>>n>>nrFin;
    char x;
    string a[n][n], stariFinale;
    for(int i=0; i<nrFin; i++){
        f>>x;
        stariFinale += x;
    }

    int i, j;


    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j] = "-";
    while(f>>x){
        f>>i>>j;
        if(a[i][j] != "-")
            a[i][j]+=x;
        else a[i][j] = x;
    }

    string cuvant, drum;
    cin>>cuvant;
    cuvant += "";
    drum = "(q0, ";
    drum += cuvant + ")";

    int StareCurenta = 0;
    while(cuvant != ""){
        int ok = 0;
        for(int j=0; j<n; j++)
            if(a[StareCurenta][j].find(cuvant[0]) != string:: npos){
                    StareCurenta = j;
                    cuvant.erase(0, 1);
                    drum += "->(q";
                    drum +=  ('0' + StareCurenta);
                    drum += ", " + cuvant + ")";
                    ok = 1;
                    break;
            }
        if(ok == 0){
            cout<<"Cuvant neacceptat"<<endl;
            break;
        }
    }
    if(cuvant == ""){
        if(stariFinale.find('0' + StareCurenta) != string :: npos){
            cout<<"Cuvant acceptat"<<endl;
            cout<<drum<<endl;
            }
        else cout<<"Cuvant neacceptat"<<endl;
    }
    return 0;
}
