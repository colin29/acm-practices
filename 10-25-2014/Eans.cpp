#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
 
using namespace std;
 
struct P {
    int x, y, z;
    P(int lx, int ly, int lz) { x = lx; y = ly; z = lz; }
};
 
struct cmpPZ {
    bool operator() (const P &p1, const P &p2) const {
        return p1.z < p2.z || (p1.z == p2.z && (p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x)));
    }
};
 
 
int main() {
    int nc; cin >> nc;
    for (int cs = 1; cs <= nc; cs++) {
        int n; cin >> n;
        vector<P> pts;
        for (int i = 0; i < n; i++) {
            int x, y, z; cin >> x >> y >> z;
            pts.push_back(P(x, y, z));
        }
        sort(pts.begin(), pts.end(), cmpPZ());
        map<int, int> rects;
        int count = 1;
        rects[pts[0].x] = pts[0].y;
        //cerr << pts[0].x << " " << pts[0].y << " " << rects[pts[0].x] << endl;
        for (int i = 1; i < n; i++) {
            if (pts[i].x < rects.begin()->first) { //compare their keys (x values)
                count++;
                rects[pts[i].x] = pts[i].y;
                    for (map<int, int>::iterator it = ++rects.lower_bound(pts[i].x); it != rects.end(); ) {
                        int yy = it->second;
                        map<int, int>::iterator iii = it;
                        ++it;
                        if (yy > pts[i].y) {
                            rects.erase(iii);
                        } else {
                            break;
                        }
                    }
            } else {
                map<int, int>::iterator i1 = --rects.lower_bound(pts[i].x);
                //cerr << i << " " << pts[i].y << " " << i1->first << " " << i1->second << endl;
                if (pts[i].y < i1->second) {
                    count++;
                    rects[pts[i].x] = pts[i].y;
                    for (map<int, int>::iterator it = ++rects.lower_bound(pts[i].x); it != rects.end(); ) {
                        int yy = it->second;
                        map<int, int>::iterator iii = it;
                        ++it;
                        if (yy > pts[i].y) {
                            rects.erase(iii);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        cout << count << endl;
    }
}