class Solution {
public:
    int helper(vector<int>& arr, int l, int h, int key) { 
        if (l > h) return -1; 

        int mid = (l+h)/2; 
        if (arr[mid] == key) 
            return mid; 
        
        if (arr[l] <= arr[mid]) { 
            if (key >= arr[l] && key <= arr[mid]) 
                return helper(arr, l, mid-1, key); 
            return helper(arr, mid+1, h, key); 
        } 

        if (key >= arr[mid] && key <= arr[h]) 
            return helper(arr, mid+1, h, key); 
        return helper(arr, l, mid-1, key); 
    } 
    
    int search(vector<int>& arr, int tg) {
        return helper(arr, 0, arr.size()-1, tg); 
    }
};