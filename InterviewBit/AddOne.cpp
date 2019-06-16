// https://www.interviewbit.com/problems/add-one-to-number/
// Asked in Microsoft and Google

#include <bits/stdc++.h> 
#include <stdio.h>
using namespace std;


vector<int> addOne(vector<int> &A) {
    int i = A.size() - 1;

    while(A[i]==9 && i>=0){
        A[i]=0;
        i--;
    }
    
    if(i==-1){
        A.insert(A.begin(),1);
    }
    
    else{
        A[i]++;
    }

    // clear the number
    while(A[0]==0){
        A.erase(A.begin());
    }
    return A;
}
