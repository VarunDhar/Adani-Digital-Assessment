#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fun1(int numberOfRows ,int numberOfColumns){
    vector<vector<int>> ans(numberOfRows,vector<int>(numberOfColumns));
    for(int i=0;i<numberOfRows;i++){
        for(int j=0;j<numberOfColumns;j++){
            ans[i][j]= (rand())%101; //101 is used to pick values from 0 to 100
        }
    }
    return ans;
}

void fun2(vector<vector<int>> &arr, int columnIndex){
    vector<pair<int,int>> temp;
    for(int i=0;i<arr.size();i++){
        temp.push_back({arr[i][columnIndex],i});
    }
    //arr was called using reference, so returned the same array after making changes
    sort(temp.begin(),temp.end());
    vector<vector<int>> newarr(arr.size(),vector<int>(arr[0].size()));
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<arr[0].size();j++){
            newarr[i][j] = arr[temp[i].second][j];
        }
    }
    arr = newarr;
    return ;
}

int main()
{
    //fun1 is function for first question
    //fun2 is function for second question
    vector<vector<int>> temp = fun1(5,5); // function1 call
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<temp[i][j]<<"   ";
        }
        cout<<"\n";
    }
    cout<<"---"<<endl;
    fun2(temp,2); //function2 call
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<temp[i][j]<<"   ";
        }
        cout<<"\n";
    }
    return 0;
}
