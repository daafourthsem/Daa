#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

int merge(std::vector<int>& v, std::vector<int>& a, std::vector<int>& b) {
    int comps = 0;
    int i=0, j=0, k;
    for(k=0; k<v.size(); k++) {
        if(i == a.size() || j == b.size())
            break;
        
        if(a[i] < b[j])
            v[k] = a[i++];
        else
            v[k] = b[j++];
        
        comps++;
    }
    if(i == a.size()) {
        if(j == b.size())
            return comps;

        while(j != b.size())
            v[k++] = b[j++];
    } 
    else {
        while(i != a.size())
            v[k++] = a[i++];  
    }

    return comps;
}

int sort(std::vector<int>& v) {
    if(v.size() <= 1) {
        return 0;
    }

    std::vector<int> a;
    std::vector<int> b;

    int mid = v.size() / 2;

    for(int i=0; i<mid; i++)
        a.push_back(v[i]);

    for(int i=mid; i<v.size(); i++)
        b.push_back(v[i]);

    int x = sort(a);
    int y = sort(b);

    int z = merge(v, a, b);

    return x+y+z;
}


int main(int argc, char const *argv[]) {
    std::vector<int> v;
    double nlogn;
    int i = 2;
    int comp;
    srand(time(NULL));

    std::cout<<"Size "<<" n*log(n) "<<" Asc. "<<" Ratio\t"<<"Desc. "<<" Ratio "<<" Random "<<" Ratio\n";
    while(i != 32768) {
        nlogn = i*log2(i);
        
        for(int j=0; j<i; j++)
            v.push_back(j);
        comp = sort(v);
        v.clear();
        std::cout<<i<<"\t"<<nlogn<<"\t"<<comp<<"\t"<<nlogn/comp<<"\t";
        
        for(int j=i; j>0; j--)
            v.push_back(j);
        comp = sort(v);
        v.clear();
        std::cout<<comp<<"\t"<<nlogn/comp<<"\t";

        for(int j=0; j<i; j++)
            v.push_back(rand());
        comp = sort(v);
        v.clear();
        std::cout<<comp<<"\t"<<nlogn/comp<<"\n";

        i*=2;
    }
}
