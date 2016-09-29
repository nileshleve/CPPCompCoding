#include <iostream>
#include <vector>
using namespace std;
void displayPathtoPrincess(int n, vector <vector<char> > grid){
    int locxm, locxp;
    int locym, locyp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            if(grid[i][j] == 'm'){
                locxm = i;
                locym = j;
            }
            if(grid[i][j] == 'p'){
                locxp = i;
                locyp = j;
            }
                
        }
        
    }
    int nx = 0;
    int ny = 0;
    if(locxp < locxm && locyp < locym){// up left
        nx = locxm - locxp;
        ny = locym - locyp;
        for(int i = 0; i < nx; i++){
            cout<<"UP"<<endl;
        }
        for(int i = 0; i < ny; i++){
            cout<<"LEFT"<<endl;
        }
        
            
    }
    else if(locxp < locxm && locyp > locym){// up right
        nx = locxm - locxp;
        ny = locyp - locym;
        for(int i = 0; i < nx; i++){
            cout<<"UP"<<endl;
        }
        for(int i = 0; i < ny; i++){
            cout<<"RIGHT"<<endl;
        }
    }
    else if(locxp > locxm && locyp < locym){ //down left
        nx = locxp - locxm;
        ny = locym - locyp;
        for(int i = 0; i < nx; i++){
            cout<<"DOWN"<<endl;
        }
        for(int i = 0; i < ny; i++){
            cout<<"LEFT"<<endl;
        }
    }
    else{
        nx = locxp - locxm;
        ny = locyp - locym;
        for(int i = 0; i < nx; i++){
            cout<<"DOWN"<<endl;
        }
        for(int i = 0; i < ny; i++){
            cout<<"RIGHT"<<endl;
        }
    }
    
    
    
    //your logic here
}
int main(void) {

    int n;
    vector <vector<char> > grid;
    char str;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        vector<char> s;
        for(int j = 0; j<n; j++){
            cin>>str;
            s.push_back(str);
        }
        grid.push_back(s);
        //string s; cin >> s;
        //grid.push_back(s);
    }

    displayPathtoPrincess(n,grid);

    return 0;
}
