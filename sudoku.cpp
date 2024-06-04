#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define debug cout << "debug\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int ok = 1;
int c = 0;
int s[9][9]  =   {{0,0,0,0,0,0,0,0,0},
			      {0,0,0,0,0,0,0,0,0},
			      {0,0,0,0,0,0,0,0,0},
		 	      {0,0,0,0,0,0,0,0,0},
			      {0,0,0,0,0,0,0,0,0},
			      {0,0,0,0,0,0,0,0,0},
			      {0,0,0,0,0,0,0,0,0},
			      {0,0,0,0,0,0,0,0,0},
		  	      {0,0,0,0,0,0,0,0,0},};

bool valido(int z, int r, int c){
	bool ans = true;
	for(int i = 0; i <9;i++){
		if(s[r][i]==z){
			ans = false;
			break;
		}
		else{
			continue;
		}
	}
	
	for(int j = 0; j <9;j++){
		if(s[j][c]==z){
			ans = false;
			break;
		}
		else{
			continue;
		}
	}


	int startRow = (r/ 3) * 3;
	int startCol = (c / 3) * 3;

	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			if(z==s[startRow + r][startCol + c]){
				ans=false;
				break;
			}
		}
	}
	return ans;
}

void solve(int x, int y){
	if((x==9)&&(ok)){
		
		for(int x =0; x < 9;x++){
			for(int y = 0; y <9;y++){
				cout << s[x][y] << " ";
			}
		cout << "\n";
		}
		cout << "\n";
		ok = 0;
	}
	if(x==9){
		c++;
	}
	else if(y==9){
		return solve(x+1,0);
	}
	else if(s[x][y]!=0){
		return solve(x,y+1);
	}
	for(int n = 0; n<=9;n++){
		if(!valido(n,x,y)){
			continue;
		}
		s[x][y] = n;
		solve(x,y+1);
		s[x][y] = 0;
	}

}


int main(){
	cout << "Introduce el sudoku a resolver: \n";
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9;j++){
			cin >> s[i][j];
		}
	}
	 
	solve(0,0);
	cout << "\n La cantidad total de formas de completar el sudoku es de: " << c;
	return 0;
}
