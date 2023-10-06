#include <bits/stdc++.h>
#include "utils.hpp"
#define ll long long
using namespace std;

ll gcnt;
void GrahamScan(vector<Point>&);
int main()
{
    cout<<"\n Executing Graham Scan\n";
    
    ifstream in("convexHull.txt");
    if(!in){
        cout << "File not found" << endl;
        return 0;
    }
    ll x,y;
    vector<Point> points;
    while(in >> x >> y){
        if(y < Point::refPoint.y || (y == Point::refPoint.y && x < Point::refPoint.x)){
            Point::refPoint.x = x;
            Point::refPoint.y = y;
        }
        points.push_back(Point(x,y));
    }
    cout<<" Total points: "<<points.size()<<endl;
    points.erase(find(points.begin(), points.end(), Point::refPoint));

    sort(points.begin(), points.end()); gcnt++;
    // cout<<"RefPoint: "<<Point::refPoint.x<<" "<<Point::refPoint.y<<endl;
    in.close();
    
    GrahamScan(points);
    cout << " Graham's Scan Done" << endl;
    cout<<" Steps: "<<gcnt<<" For input size "<<points.size()+1<<endl;
    // this_thread::sleep_for(chrono::milliseconds(2000));
    
    return 0;
}


void GrahamScan(vector<Point>& points){
    myStack<Point> hull;
    hull.push(Point::refPoint);
    hull.push(points[0]);
    hull.push(points[1]);
    gcnt+=3;
    Line l1,l2;
    for(int i=2; i<points.size(); i++){
        l1 = Line(hull.NextToTop(),hull.top());
        l2 = Line(hull.top(),points[i]);
        gcnt+=2;
        while(l1*l2<=0){
            if(hull.NextToTop() == Point::refPoint){
                break;
            }
            hull.pop();
            l1 = Line(hull.NextToTop(),hull.top());
            l2 = Line(hull.top(),points[i]);
            gcnt+=3;
        }
        gcnt++;
        hull.push(points[i]);
    }
    ofstream out("output.txt");
    if(!out){
        cout << "File not found" << endl;
        return;
    }
    out<<Point::refPoint.x<<" "<<Point::refPoint.y<<endl;
    int x = hull.top().x;
    int y = hull.top().y;
    while(!hull.empty()){
        out<<hull.top().x<<" "<<hull.top().y<<"\n";
        hull.pop();
    }
    out<<x<<" "<<y;
}