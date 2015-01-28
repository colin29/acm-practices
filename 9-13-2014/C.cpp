#include <iostream>
#include <algorithm>
#include <cmath> //abs
#include <algorithm> //min, max
#include <string>

const long double EPS = 1e-9;
struct p{
	double x;
	double y;
};

using namespace std;

p h[3];
p u[3];
p r;
int main(){
	while(!cin.eof()){
		r.x=9999; //defend against trailing /n 's
		for (int i = 0; i < 3; ++i)
		{
			cin >> r.x >> r.y;
			//cout<<r.x<<" " << r.y << " ";
			h[i]=r;
		}
		for (int i = 0; i < 3; ++i)
		{
			cin >> r.x >> r.y;
			//cout<<r.x<<" " << r.y << " ";
			u[i]=r;
		}
		if(r.x == 9999)
			return 0;
		string temp;
		getline(cin, temp);
		//find if the happy tri is cclockwise
		int ex, ey, fx, fy; 
		ex=h[1].x - h[0].x;
		ey=h[1].y - h[0].y;
		fx=h[2].x - h[1].x;
		fy=h[2].y - h[1].y;
		bool bcclock = (ex*fy - ey*fx > 0);
		//cout<<"cclockwise: " << bcclock << endl;

		bool canout = true; //applies to both tri's
		for (int i = 0; i < 3; ++i)
		{
			bool canin = true;
			for (int j = 0; j < 3; ++j)
			{
				int lx, ly;
				lx=u[i].x - h[j].x;
				ly=u[i].y - h[j].y;

				int gx, gy;
				gx=h[(j+1)%3].x - h[j].x;
				gy=h[(j+1)%3].y - h[j].y;

				//cout<< "point u " << j << " :" << (bcclock != (gx*ly - gy*lx > 0)) << endl;
				if(bcclock != (gx*ly - gy*lx > 0)){
					canin=false;
				}
			}
			if(canin==true)
				canout=false;
		}

		//find if the unhappy tri is cclockwise
		ex=u[1].x - u[0].x;
		ey=u[1].y - u[0].y;
		fx=u[2].x - u[1].x;
		fy=u[2].y - u[1].y;
		bcclock = (ex*fy - ey*fx > 0);

		//using vars e, f,g
		//l
		for (int i = 0; i < 3; ++i)
		{
			bool canin = true;
			for (int j = 0; j < 3; ++j)
			{
				int lx, ly;
				lx=h[i].x - u[j].x;
				ly=h[i].y - u[j].y;

				int gx, gy;
				gx=u[(j+1)%3].x - u[j].x;
				gy=u[(j+1)%3].y - u[j].y;

				if(bcclock != (gx*ly - gy*lx > 0)){
					canin=false;
				}
			}
			if(canin==true)
				canout=false;
		}

		// cout<< (canout? "A triangle point is not within another" : "Point contained") << endl;
		//using vars a, b, c
		//s, t, w
		for (int i = 0; i < 3; ++i) //iterate over h
		{
			double a, b, c;
			a = h[(i+1)%3].y - h[i].y;
			b = h[i].x - h[(i+1)%3].x; //meant to be rev.
			c = a*h[i].x + b*h[i].y;
			for (int j = 0; j < 3; ++j) //over u
			{
				double s, t, w;
				s = u[(j+1)%3].y - u[j].y;
				t = u[j].x - u[(j+1)%3].x;
				w = s*u[j].x + t*u[j].y;

				double det = a*t - b*s;
				if(abs(det)<=EPS){
					// cout<<"Intersect: " << false << " (parallel lines)"<<endl;
					continue; //lines are parallel
				}
				//using vars x, y
				double x, y;
				x = (t*c - b*w)/det;
				y = (a*w - s*c)/det;




				// cout<< "Intersect: " << ( //bounding box check
				// min(h[i].x, h[(i+1)%3].x)-EPS <= x //operator precendence, works out
				// && max(h[i].x, h[(i+1)%3].x)+EPS >= x
				// && min(h[i].y, h[(i+1)%3].y)-EPS <= y
				// && max(h[i].y, h[(i+1)%3].y)+EPS >= y

				// && min(u[j].x, u[(j+1)%3].x)-EPS <= x 
				// && max(u[j].x, u[(j+1)%3].x)+EPS >= x
				// && min(u[j].y, u[(j+1)%3].y)-EPS <= y
				// && max(u[j].y, u[(j+1)%3].y)+EPS >= y
				// ) << " at " << x << " " << y <<endl;

				if (min(h[i].x, h[(i+1)%3].x)-EPS <= x //operator precendence, works out
				&& max(h[i].x, h[(i+1)%3].x)+EPS >= x
				&& min(h[i].y, h[(i+1)%3].y)-EPS <= y
				&& max(h[i].y, h[(i+1)%3].y)+EPS >= y

				&& min(u[j].x, u[(j+1)%3].x)-EPS <= x 
				&& max(u[j].x, u[(j+1)%3].x)+EPS >= x
				&& min(u[j].y, u[(j+1)%3].y)-EPS <= y
				&& max(u[j].y, u[(j+1)%3].y)+EPS >= y
				){
					//cout<<"Report intersection: "<<endl;
					canout=false; //line intersection
			}
			}
		}

		cout << (canout? "Yes" : "No") << endl;

	}
	return 0;
}