
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
	cin>>t;
	while(t-->0){
	    float a,b,c,d,e,f,g,h;
	    cin>>a>>b>>c>>d>>e>>f>>g>>h;

	    float midx = (a+c+e+g)/4;
	    float midy = (b+d+f+h)/4;

	    float d1 = sqrt(abs((midx-a)*(midx-a))+abs((midy-b)*(midy-b)));
	    float d2 = sqrt(abs((midx-c)*(midx-c))+abs((midy-d)*(midy-d)));
	    float d3 = sqrt(abs((midx-e)*(midx-e))+abs((midy-f)*(midy-f)));
	    float d4 = sqrt(abs((midx-g)*(midx-g))+abs((midy-h)*(midy-h)));

	    if(d1 == d2 && d2 == d3 && d3 == d4 && d4 == d1){
	    	cout<<"1"<<endl;
	    }
	    else{
	    	cout<<"0"<<endl;
	    }


	    /*double x = sqrt((c-a)*(c-a)+(d-b)*(d-b));
	    double y = sqrt((g-a)*(g-a)+(h-b)*(h-b));
	    double z = sqrt((e-a)*(e-a)+(f-b)*(f-b));
	    
		if((x>y && x> z && y==z && x == y*sqrt(2)) || (y>x && y> z && x==z && y == x*sqrt(2)) || (z>y && z> x && x==y && z == y*sqrt(2) ) ){
	        cout<<"1"<<endl;   
	    }
	    else
	        cout<<"0"<<endl; */
	}
	return 0;
}


/*
#include <iostream>
#include <math.h>
using namespace std;
int main() 
{
int t;
cin>>t;
for(int i=0;i<t;i++) {
float x1,y1,x2,y2,x3,y3,x4,y4,cx,cy;
cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
cx=(x1+x2+x3+x4)/4;
cy=(x1+y2+y3+y4)/4;

float d1,d2,d3,d4;
d1= sqrt(pow(fabs(cy-y1),2)+pow(fabs(cx-x1),2));
d2= sqrt(pow(fabs(cy-y2),2)+pow(fabs(cx-x2),2));
d3= sqrt(pow(fabs(cy-y3),2)+pow(fabs(cx-x3),2));
d4= sqrt(pow(fabs(cy-y4),2)+pow(fabs(cx-x4),2));

if(d1==d2 && d2==d3 && d3==d4 && d4==d1)
cout<<"1"<<endl; 
else
cout<<"0"<<endl;
    
}
return 0;
    
}

*/