#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int rank;
    
    Student(string s,int m)
    {
        name = s;
        rank = m;
    }

    bool operator < (const Student &obj)const{
        return this->rank > obj.rank;
    }

};

int main() {
    priority_queue<Student> pq;

    pq.push(Student("aman",2000));
    pq.push(Student("bhumika",1250));
    pq.push(Student("kanishk",500));

    while(!pq.empty())
    {
        cout<<"top is: "<<pq.top().name<<","<<pq.top().rank<<endl;
        pq.pop();
    }

    return 0;
}