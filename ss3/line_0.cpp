#include<iostream>
#include<vector>

// 極簡単な線形探索

using std::cout;
using std::endl;
using std::cin;
using std::vector;


int main(){

    int N,v;
    cin >> N >> v;
    vector<int> a(N);
    for(int i=0; i<N ; i++) 
    {cin >> a[i]; }


    bool exist = false;
    int num_of_loop = 1;

    for(int i=0; i < N ; ++i){

	if(a[i] == v) {

	    exist = true;
	    break;
	}

	++num_of_loop;
    }

    if(exist) cout << "Yes" << endl;
    else      cout << "No"  << endl;

    cout <<"num_of_loop = "<<num_of_loop << endl;
}


