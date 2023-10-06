#include <bits/stdc++.h>
#include "utils.hpp"
#define ll long long
using namespace std;

stack<Point>qhull;

int distance(Point p1, Point p2, Point p){
    return abs((p.x-p1.x)*(p2.y-p1.y) - (p.y-p1.y)*(p2.x-p1.x));
}
ll qcnt;
void calcHull(vector<Point>&points, Point left, Point right, int side){
    Point top;
    Line vec(left, right);
    int dist=0; 
    bool topFound = false;
    qcnt+=2;
    for(int i=0;i<points.size();i++){
        Line temp(left, points[i]);
        int tempSide = vec*temp;
        if(tempSide*side < 0) continue;
        int tempDist = distance(left, right, points[i]);
        qcnt+=2;
        if(tempDist == 0) continue;
        qcnt++;
        if(tempDist>dist){
            dist = tempDist;
            top = points[i];
            topFound = true;
            qcnt+=3;
        }
    }
    qcnt++;
    if(!topFound){
        // cout<<"Here\n";
        qhull.push(left);
        qhull.push(right);
        qcnt+=3;
        return;
    }
    // cout<<"Here\n";
    qcnt++;
    calcHull(points, left, top, side);
    qcnt++;
    calcHull(points, top, right, side);

}

void QuickHull(vector<Point>&points){
    Point minp(INT_MAX, INT_MAX),maxp(-INT_MAX, -INT_MAX);
    qcnt++;
    for(auto it: points){
        qcnt++;
        if(it.x < minp.x){
            minp = it;
            qcnt++;
        }
        else if(it.x > maxp.x){
            maxp = it;
            qcnt++;
        }
    }
    // cout<<"Min: "<<minp.x<<" "<<minp.y<<endl;
    // cout<<"Max: "<<maxp.x<<" "<<maxp.y<<endl;
    qcnt++;
    calcHull(points, minp, maxp, -1);
    qcnt++;
    calcHull(points, maxp, minp, -1);
}


int main()
{
    cout<<"\n Executing Quick Hull\n";
    
    ifstream in("convexHull.txt");
    if(!in){
        cout << "File not found" << endl;
        return 0;
    }
    ll x,y;
    vector<Point> points;
    while(in >> x >> y){
        points.push_back(Point(x,y));
    }
    in.close();
    cout<<" Total points: "<<points.size()<<endl;
    QuickHull(points);
    
    ofstream out("output.txt");
    if(!out){
        cout << "File not found" << endl;
        return 0;
    }
    out<<"-1 -1\n";
    x = qhull.top().x;
    y = qhull.top().y;
    while(!qhull.empty()){
        out<<qhull.top().x<<" "<<qhull.top().y<<"\n";
        qhull.pop();
    }
    out<<x<<" "<<y;
    cout << " QuickHull Done" << endl;
    cout<<" Steps: "<<qcnt<<" For input size "<<points.size()<<endl;
    // this_thread::sleep_for(chrono::milliseconds(2000));
    return 0;
}