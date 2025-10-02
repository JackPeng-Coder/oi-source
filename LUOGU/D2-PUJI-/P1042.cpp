//P1042 [NOIP 2003 普及组] 乒乓球
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int w=0, l=0;
    int ww=0, ll=0;
    int el[63500][2];
    int elP = 0;
    int tw[63500][2];
    int twP = 0;
    char status;
    cin >> status;
    while(true){
        if(status == 'W'){
            w++;
            ww++;
        }else if (status == 'L'){
            l++;
            ll++;
        }
        if( (l>=11 || w>=11) && abs(w-l)>=2){
            el[elP][0] = w;
            el[elP][1] = l;
            elP++;
            w = 0;
            l = 0;
        }
        if( (ll>=21 || ww>=21) && abs(ww-ll)>=2){
            tw[twP][0] = ww;
            tw[twP][1] = ll;
            twP++;
            ww = 0;
            ll = 0;
        }
        if(status == 'E'){
            el[elP][0] = w;
            el[elP][1] = l;
            elP++;
            w = 0;
            l = 0;
            tw[twP][0] = ww;
            tw[twP][1] = ll;
            twP++;
            ww = 0;
            ll = 0;
            break;
        }
        cin >> status;
    }
    for(int i=0;i<elP;i++) cout << el[i][0] << ":" << el[i][1] << endl;
    cout << endl;
    for(int i=0;i<twP;i++) cout << tw[i][0] << ":" << tw[i][1] << endl;
    return 0;
}