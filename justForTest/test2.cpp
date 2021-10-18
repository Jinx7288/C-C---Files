#include <iostream>
 
#include <algorithm>
#include <vector>
using namespace std;
 
bool IsOdd (int i) {
    return ((i%2)==1);
}
 
int main() {
    int myints[] = { 5, 20, 51, 30, 20, 10, 22,50 };
 
    int len= sizeof(myints)/ sizeof(myints[0]);
 
    vector<int> myvector(myints,myints+len);
 
    cout<<myvector.size()<<endl;
 
    vector<int>::iterator  iter;
 
    //find函数查看vector是否包含某元素
    iter=  find(myvector.begin(),myvector.end(),50);
 
    if (iter != myvector.end()) {
        cout << "Element found in myvector: " << *iter << '\n';
    }// 30
    else {
        cout << "Element not found in myvector\n";
    }
 
    vector<int>::iterator it = find_if (myvector.begin(), myvector.end(), IsOdd);
    cout << "The first odd value is " << *it << '\n';
 
 
    vector<int>::iterator iter1 =
            find_if_not (myvector.begin(), myvector.end(), [](int i){return i%2;} );
    cout << "The first even value is " << *iter1 << '\n';
 
    //计数工具  一直接对数组计数
    int mycount = count (myints, myints+8, 10);
    cout << "10 appears " << mycount << " times.\n";
 
    // counting elements in container:
    //对vector计数
    mycount = count (myvector.begin(), myvector.end(), 20);
    cout << "20 appears " << mycount  << " times.\n";
 
    //按照条件计数
     mycount = count_if (myvector.begin(), myvector.end(), IsOdd);
    cout << "myvector contains " << mycount  << " odd values.\n";

    it = search_n (myvector.begin(), myvector.end(), 1, 20);
 
    if (it!=myvector.end())
        cout << "two 30s found at position " << (it-myvector.begin()) << '\n';
    else
        cout << "match not found\n";
}