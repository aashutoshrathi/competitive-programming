#include <bits/stdc++.h> 
#include <windows.h> 
using namespace std; 
  
int main() { 
    char url[100] = "http://google.com/"; 
    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL); 
    return 0; 
} 