#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int i, j, testcase, N, count=1, min_cout, max, main_cout=0;
    cout<<"enter the number of testcases";
	cin>>testcase;
	for(int i=0; i<testcase; i++){
        cout<<"how many entegers?: ";
	    cin>>N;
        int num[N];
	    for(int i=0; i<N; i++){
            cout<<"enter the number: ";
	        cin>>num[i];
	    }
	    for(i=0; i<N; i++){
            min_cout=1;
	        for(j=i+1; j<N;j++){
	            if(num[i]==num[j])
	                min_cout += 1;
	        }
	        if(min_cout>=count){
	            count = min_cout;
	            max = i;
	        }
	    }
        for(i=0; i<N; i++){
            if(num[i] != num[max]){
                num[i] = num[max];
                main_cout += 1;
            }
        }
        cout<<main_cout<<endl;
	}
	return 0;
}