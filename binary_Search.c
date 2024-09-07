//Hour-0 
//now its going to be long and crazy we will begin with the absolute basic called the binary search lets get going 
//leetcode 34 find the first and the last position of element in sorted array
//the basic of the question is pretty clear we just need to keep searching until we can find the element whether it may be the first or the last 
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ,target;
    vector<int>ans,nums(n);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>target;
    
    int l=0;
    int r=n-1;
    int first=-1;
    int last=-1;
    while(l<=r){//how to find the first position of the target
        int mid=(l+r)/2;
        if(nums[mid]>=target){
            if(nums[mid]==target){
                first=mid;
            }
            r=mid-1;

        }
        else{
            l=mid+1;
        }

    }
    ans.push_back(first);
    l=0;
    r=n-1;

    while(l<=r){//how to find the last position in the array
        int mid=(l+r)/2;
        if(nums[mid]<=target){
            if(nums[mid]==target){
                last=mid;
            }
            l=mid+1;
        }
        else{
            r=mid-1;
        }

    }
    ans.push_back(last);
    return 0;

}

//leetcode 33 search in rotated sorted array 
//since the array is already sorted but it is being rotated but no worries even the rotated sub parts will turn out to be sorted
// what i mean to say is that there will be pivot position before and  after which the array will definitely sorted now just do the normal binary search

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,target;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int l=0;

    int r=n-1;
    int flag=1;
    while(l<=r && flag==1){
        int mid=(l+r)/2;
        if(nums[mid]==target){//if  the target if found
            cout<<mid<<endl;
            flag=0;
            break;
        }
        else if(nums[low]<=mid){//if the left turn out to be sorted 
            if(nums[low]<=target && target< nums[mid]){
                r=mid-1;

            }
            else{
                l=mid+1;
            }
        }
        else{
            if(nums[mid]<= target && target< nums[r]){//if the right part of the array turn out to be sorted
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }
    if(flag==1){//if the target does not exist
        cout<<-1<<endl
    }
}

//leetcode 540 single element in the sorted array 
//the question can be solved in different ways but for right now just focus on the binary search solution

#include<bits/stdc++.h>
using namsespace std;
int main(){
    int nn;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int l=0;
    int r=n-1;
    int ans=-1;
    //the concept can be confusing if you dont draw two or three array and  try different possible cases to derive the formula
    while(l<=r){
        int mid=(l+r)/2;
        if(mid%2==0 && nums[mid]==nums[mid-1] || (mid%2==1 && nums[mid]==nums[mid+1]) ){//when the current index is even and the current element is eqaul to the previous element 
        //or the current index is odd and is equal to the next elemnt then also the imbalance is being created due to the left part of the array so look there
            r=mid;
        }
        else {//else we have to look on the right side of the array 
            l=mid+1;
        }
    }
    cout<<nums[l];
}

//this question is from geek to geek nth root of a number 
//the question is pretty easy it is a question of binary search on answer  we will be given two integers A and n we have to find the nth root of a example A=81 n=3 then ans =3
//now what we can do is simply linear search from  1 to A and check whether the condition for the nth root is satisfied or not pretty easy but not efficent 
//so lets make it efficent we will create a function check whether when current element eleavated to power n can become >= to A if yes then keep searching on the mid-1 range unstil and unless it tursn out to be false
#include<bits/stdc++.h>
using namespace std;
bool check(int A,int n,int mid){
    int ans=1;
    while(n>=0){
        if(n%2==1){
            ans*=mid;
            n=n-1;
        }
        else{
            mid=mid*mid;
            n=n/2;
        }
    }
    return ans>=A;
}
int solve(int n,int A){
    int l=1;
    int r=A;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(A,n,mid)){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    return ans;

}
int main(){
    int n,A;
    cin>>n>>A;
    cout<<solve(n,A)<<endl;
}

//leetcode 875 koko eating bananas 
// this one of the best and the basic question of the binary search on the answer 
//the  logic is also pretty simple since we are asked a minimum integer k such that with which we can eat bananas in h hour we can search this k 
//just think of it the maximum she can eat is the max of the array cant go further then that and the min is going to be 1 so just search the minimum in this range 

bool check(int mid,vector<int>nums,int h){//check function to check if my speed is sufficient or not
    int count=0;
    for(int i=0;i<num.size();i++){
        if(nums[i]%mid==0){
            ans+=nums[i]/mid;
        }
        else{
            ans+=(nums[i]/mid)+1;
        }

    }
    return ans<=h;
}
int mainfunc(vector<int>nums,int h){
    int maxy=0;
    for(int i=0;i<nums.size();i++){
        maxy=max(nums[i],maxy);
    }
    int l=1;
    int r=maxy;
    int ans=0;
    int flag=1;
    while(l<=r && flag==1){
        int mid=(l+r)/2;
        if(check(mid,nums,h)==1){
            if(check(mid-1,nums,h)==0){
                ans=mid;
                flag=0;
                break;
            }
            else{
                r=mid-1;
            }
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}
//now the hour 1 has started


/*
You are given an array of size “N” ; you are given a capacity of “k” ; 
Each element can be reduced by at most k in 1 move. You are allowed to make maximum “d” moves. Find the minimum possible value of “k” 
*/
//totally similar to the previous question 
bool check(int mid,vector<int>nums,int h){//check function to check if my speed is sufficient or not
    int count=0;
    for(int i=0;i<num.size();i++){
        if(nums[i]%mid==0){
            ans+=nums[i]/mid;
        }
        else{
            ans+=(nums[i]/mid)+1;
        }

    }
    return ans<=h;
}
int mainfunc(vector<int>nums,int h){
    int maxy=0;
    for(int i=0;i<nums.size();i++){
        maxy=max(nums[i],maxy);
    }
    int l=1;
    int r=maxy;
    int ans=0;
    int flag=1;
    while(l<=r && flag==1){
        int mid=(l+r)/2;
        if(check(mid,nums,h)==1){
            if(check(mid-1,nums,h)==0){
                ans=mid;
                flag=0;
                break;
            }
            else{
                r=mid-1;
            }
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

//finding the median in row wise sorted matrix of size n*n
//now the median index can be found simply but what about the element that would be coming there when the matrix is rearranged as an sorted array 
//now if look at the problem we need the median we know how many elments are going to come before it just take mid look whether we have that many elemnet before it or not and keep looking for the best just like life!!!

#include<bits/stdc++.h>
using namespace std;
int find(vector<vector<int>>a){
    int total=a.siz()*a[0].size();
    int median=0
    int l=1;
    int r=1e9;
    while(l<=r){
        int mid=(l+r)/2;
        int lowerb=0;
        for(int row=0;row<a.size();row++){
            int ub=upper_bound(a[row].begin(), a[row].end(),mid)-a[row].begin();//finding the number of element smaller or equal to the mid in every row
            lower+=ub;
        }
        if(ub>total/2){
            median=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return median;
}
int main(){
    int n;
    cin>>n;
    vector<vecotr<int>>a(n,vecotr<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<find(a)<<endl;
    return 0;
}
//leetcode 441 arranging the coins 
int arrangecoins(int n){
    int l=1;
    int r=n;
    int ans=0;
    while(l<=r){
        int mid=(r-l)/2+l;
        int cost=mid*(mid+1)/2;
        if(n>=cost){
            l=mid+1;
            ans=mid;

        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
//leetcode 744 find the smallest letter greater than target
char next(vector<char>alpha,char,target){
    if(alpha[0]>target || target>=alpha[alpha.size()-1]){
        return alpha[0];
    }
    char ans;
    int low=0;
    int high=alpha.size()-1;
    while(low<=high){
        int mid=(high-low)/2+low;
        if(alpha[mid]>target){
            ans=alpha[mid];
            high=mid-1;

        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

//search in a 2d matrix 
//the question is asking us to find the target in a matrix and what we can do is just first check the first element of every row and then when we find the row which satisfy the condition of mat[i][0]<=target we binary search in that row 
//so techniaclly to binary search first one for right row and then for right column

int solve(vector<vecot<int>>mat,int target){
    int s=0;
    int end=a.size()-1;
    int ind=0;
    while(s<=end){
        int mid=s+(end-s)/2;
        if(mat[mid][0]==target){
            return true;
        }
        if(mat[mid][0]<target){
            ind=mid;
            s=mid+1;

        }
        else{
            end=mid-1;

        }
    }
    return binary_search(mat[idx].begin(),mat[idx].end(),target);//complexity log(n)+log(n) =log(n)
}

//geek for geeks counting elements in two arrays 
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;//considering both arrays are sorted 
    vector<int>a,b(n);
    for(int i=0;i<n;i++){
        cind>>a[i]>>b[i]
    }
    vetor<int>ans(n);
    for(int i=0;i<n;i++){
        int ub=upper_bound(a.begin(),a.end(),b[i])-a.begin();
        ub--;
        ans.push_back(ub+0-1)
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}

//leetcode 2560 house robber 4 
//now this question can also be solved in different ways but for now just focus on binary search we need the minimum capabilty of the  robber and he can rob from at least k houses 
//just do  simple binary search on answer to find the minimum capabilty

int minimum(vector<int>nums,int k){
    int l=1;
    int r=1e9;
    int ans=1e9;
    while(l<=r){
        int cnt=0;
        int mid=(l+r)/2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                i++;
                cnt++;
            }
        }
        if(cnt>=k){
            ans=max(ans,mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

//geek for geeks aggressive cows 
//we need to assign stalls to k cows such that minimum distacne between them is maximized hmm what we can do is search for this minimum such that we are able to 
//install k stands  and keep looking for minimum max until the best is found 
#include<bits/stdc++.h>
using namespace std;
bool minimum(int mid,int k,vector<int>nums){
    int prev=nums[0];
    int cnt=0;
    for(int i=1;i<n;i++){
        if(nums[i]-prev<=mid){
            cnt++;
            prev=nums[i];
        }
        if(count>=k){
            return true;
        }
    }
    return false;
}
int solve(vector<int>nums,int k){
    sort(nums.begin(),nums.end());
    int l=0;
    int r=nums[nums.size()-1]-nums[0];
    int ans=r;
    while(l<=r){
        int mid=(l+r)/2;
        if(minimum(mid,k,nums)==true){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    int k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<solve(nums,k)<<endl;
    return 0;
}


//geek for geeks allocate numbe of pages from n books to m students
//there are m students and we need to assign the pages to these students such that the pages are minimum and dont exceed the m students
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>a,int n,int m ,int mid){
    int sum=0;
    int cnt=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid){
            return false;
        }
        sum+=nums[i];
        if(sum>mid){
            cnt++;
            sum=a[i];
        }
        if(cnt>m)return false;
    }
    return true;
}
int solve(vector<int>nums,int n,int m){
    int l=nums[0];
    int r=0;
    int ans=0;
    for(int i=0;i<n;i++){
        r+=nums[i];
        l=min(l,nums[i]);
    }
    while(l<=r){
        int mid=(l+r)/2;
        if(check(nums,n,m,mid)==true){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}
int  main(){
    int n,m;
    cin>>n>>m;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];

    }
    cout<<solve(nums,n,m)<<endl;
    return 0;
}

//leetcode 2616 minimize the maximum differnce of pairs

int minimize(vector<int>num,int k){
    sort(nums.begin(),nums.end());
    int l=0;
    int r=1e9;
    int n=num.size();
    while(l<=r){
        int mid=(l+r)/2;
        for(int i=0;i+1<n;i++){
            if(nums[i+1]-nums[i]<=mid){
                cnt++;
                i++;
            }
        }
        if(cnt>=p){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}//little tired !!!
//now we will do some extremely hard ones 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*We are given “n” type of items ; array b is given which tells us -> b[i] = frequency of item “i” ; 

Our task is to make a group of k distinct items; 

And finally output how many maximum such types of groups can be formed. 
*/

//what can be the smallest number of groups 1 and laregest since we have b items we can take high as the sum of all the items now what we can do is find a valid value
//of groups such that of each of the group has k items each 
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>nums,int k,int mid){
    int tot=mid*k//each group having k items so total items 
    for(int i=0;i<n;i++){
        if(nums[i]>mid){//can contribute to mid groups
            tot=tot-mid;
        }
        else{
            tot=tot-nums[i];//contribute in the gruoups possible
        }
    }
    return (tot<=0);
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n,0);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }
    int l=1;
    int r=sum;
    int flag=0;
    while(l<=r  && flag==0){
        int mid=(l+r)/2;
        if(check(nums,k,mid)==true && check(nums,k,mid+1)==false){
            ans=mid;
            flag=1;
            
        }
        else if(check(nums,k,mid+1)==true){
            l=mid+1;
        }
        else{
            r=mid-1;
            
        }
    }
    cout<<ans<<endl;
    return 0;

}
/* Question is saying to us :- We are given an array and integer k ; 
we have to make maximum k moves on the array such that all elements of array become <=0 ; also -> in each move you can :-> 

Decrease any number of the array by x . 
*/
//what can be the largest x it will be the max element of the array and min will be 1 and then the simple binary search

bool check(vector<int>nums,int k,int mid){
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%mid==0){
            cnt+=nums[i]/mid;
        }
        else{
            cnt+=(nums[i]/mid)+1;
        }
    }
    return cnt<=k;
}
int main(){
    int n,k;
    cin>>n>>k;
    int l=1;
    int r=0;
    vector<int>nums;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        r=max(r,nums[i]);
    }
    int flag=0;
    while(l<=r && flag==0){
        int mid=(l+r)/2;
        if(check(nums,k,mid)==true && check(nums,k,mid-1)==false){
            ans=mid;
            flag=1;
        }
        else if(check(nums,k,mid-1)==true){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
/*
Understanding :-> We are giving you an array of size “M” ; divide the array into at most “N” parts; lets say sum of each part is s1,s2,s3,s4,s5,.......sn 

max(s1,s2,s3,s4…….sn)---> minimum as possible. 
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 
ll b[100005];
ll n,m;


bool check(ll vl){
    
    int i = 1 ; ll c = 0; ll sum = 0 ;
    while(i<=m){
        sum = sum + b[i];
        if(sum<=vl){
            i++;
        }
        else{
            c++;
            sum = 0 ; 
        }
    }
    //cout<<c+1;
    //cout<<'\n';
    if(c+1<=n){
        return true;
    }
    return false;
}


int main() {
    
    ll t;
    cin>>t;
    while(t--){
        
        cin>>n>>m ;
        ll sum = 0 ;
        ll mx=-1e18;
        for(int i=1;i<=m;i++){
            cin>>b[i];
            mx=max(mx,b[i]);
            sum=sum+b[i];
        }
        //cout<<check(37);
        //cout<<mx<<'\n';
        if(check(29)==true){
            cout<<"lol";
        }
        ll low = mx;
        ll high = sum;
        ll k = 0 ; 
        ll v = -1;
        while(low<=high && k==0){
            ll mid = (low + high)/2;
            if(mid==mx && check(mx+1)==true && check(mx)==true){
                v = mid;
                k = 15 ; 
            }
            else if(check(mid)==false && check(mid+1)==false){
                low = mid + 1 ; 
            }
            else if(check(mid)==true && check(mid-1)==false){
                v = mid;
                k = 15 ; 
            }
            else if(check(mid)==false && check(mid+1)==true){
                v = mid+1;
                k = 15 ;
            }
            else if(check(mid)==true && check(mid-1)==true){
                high = mid - 1 ; 
            }
            //cout<<low<<" "<<mid<<" "<<high;
            //cout<<'\n';
            
        }
    
    
        
        cout<<v;
        cout<<'\n';
    }
    
    
    return 0 ;
}
/*Understanding :- Find the length of longest subset such that if the size of that subset is K then :- 

i1*k + a[i1] + …………………………………….. ik*k + a[ik] <= m .
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005; // Maximum value of n

int n, m;
int b[MAXN]; // Assuming b is a global array

bool check(int k, int b[], int m) {
    int g[MAXN];
    for (int i = 1; i <= n; i++) {
        int vl = i * k + b[i];
        g[i] = vl;
    }
    sort(g + 1, g + n + 1);

    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += g[i];
    }

    return sum <= m;
}

int main() {
    // Input
    n = 4;
    int a[] = {4, 3, 2, 1};
    m = 33;
    for (int i = 1; i <= n; i++) {
        b[i] = a[i - 1];
    }

    // Binary search
    int r = 0;
    int low = 1, high = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (!check(mid, b, m)) {
            high = mid - 1;
        } else {
            if (check(mid + 1, b, m)) {
                low = mid + 1;
            } else {
                r = mid;
                break;
            }
        }
    }

    // Handle the case where k = 1 is also not working
    if (r == 0 && !check(1, b, m)) {
        r = 0;
    }

    // Output
    cout << r << endl;

    return 0;
}

/*Understanding :-> You are given an array you can perform this operation any number of times:- 

-> Pick any index “i” ; remove some quantity from it and put inside index i - 1 

-> After doing these operations let's say g is your maximum value in the array 

-> Find minimum possible g 
*/
#include<bits/stdc++.h>
using namespace std;
bool check(int mid,vector<int>nums){
    for(int i=n-1;i>=2;i--){
        if(nums[i]>mid){
            int diff=abs(nums[i]-mid);
            nums[i-1]+=diff
        }
    }
    if(nums[1]<=mid){
        return true ;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int>b(n);
    int maxy=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        maxy=max(maxy,nums[i]);
    }
    int ans=0;
    int l=1;
    int r=maxy;
    int flag=0;
    while(l<=r  && flag==0){
        int mid=(l+r)/2;
        if(check(mid,nums)==true && check(mid-1,nums)==false){
            ans=mid;
            flag=1;
        }
        else if(check(mid-1,nums)==true){
            r=mid-1;
        }
        else {
           l= mid+1;
        }
    }
    cout<<ans;
}
/*Understanding -> We are giving you an array and a number “k” 

We have to add this number “k” to some of the elements of our array 

Do it in such a way such that the maximum number of our array is minimized. 

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canDistribute(vector<int>& arr, int k, int mid) {
    int n = arr.size();
    int required = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < mid) {
            required += (mid - arr[i]);
        }
    }

    return required >= k;
}

int minimizeMaxElement(vector<int>& arr, int k) {
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());  // The minimum possible answer
    int high = low + k;  // The maximum possible answer
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canDistribute(arr, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> arr = {7, 5, 1, 9, 1};
    int k = 25;

    int result = minimizeMaxElement(arr, k);
    cout << "Minimum possible maximum element: " << result << endl;

    return 0;
}

/*You are given an array and an integer k and an array of integers. You must find the length of longest contigous subarray where all integers are equal after removing at most k elements from the array.

 

Example
Input:
[1, -2, 1, 1, 3, 2, 1 ,-2] k = 3
Output: 4

 

Explanation:
Remove index 1 from original Array:
[1, 1, 1, 3, 2, 1, -1]
Remove index 4 from original Array:
[1, 1, 1, 2, 1, -1]
Remove index 5 from original Array:
[1, 1, 1, 1, -1]*/

//the question is to find longest contigous subarray such that all the elements are equal and we can remove k non equal elements between them
//now what i can do is store the the positions of the every element index in an unorderede_map<int,vector<int>> now on this map i can check the k elements

#include<bits/stdc++.h>
using namespace std;
int isP(int m,vector<int>t,int k){
    int x=0;
    for(int i=1;i<m;i++){//adding and checking the current window
        x+=t[i]-t[i-1]-1;
    }
    if(x<=k){
        return 1;
    }
    for(int i=m;i<t.size();i++){
        x+=t[i]-t[i-1]-1;
        x-=t[i-m+1]-t[i-m]-1;
        if(x<=k){
            return 1;
        }
    }
    return 0;
}
void solve(){
    int n=8,k=3;
    vector<int>v={1,-2,1,1,3,2,1,-2};
    map<int,vector<int>>mp;
    int fans=0;
    for(int i=0;i<n;i++){
        mp[v[i]].push_back(i);
    }
    int fans=0;
    for(auto x:mp){
        vector<int>t=x.second;
        int l=0;
        int h=t.size();
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if x=isP(mid,t,k);
            if(x==1){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        fans=max(ans,fans);
    }
    cout<<fans<<endl;
}
/*Q :-> Construct an array of size ‘N’ such that the largest possible number is at the kth index. Also each element should have an absolute difference of 0 or 1 with their adjacent elements. 

Total sum of these elements should be ‘m’

Try to maximize the element of index ‘k’
Each array element >=1
*/

/*now the question is pretty intresting you have to find the k right 
//i can put the k by linear or  binary search  but how will i ensure that this k is best 
//and all the elements maintain Total sum of  elements as ‘m’ and  Each array element >=1

//now what i am thinking is that we can either make the elemnet as largest
 and every other element small or just do the inverse */ 

 #include<bits/stdc++.h>
 using namespace std;
 int check(int mid,int m,int n,int k){
    int b[n+1]={0};
    b[k]=mid;
    int i=k+1;
    //finding the minimum sum
    int l=0;
    while(i<=n){
        b[i]=b[i-1]-1;
        if(b[i]==0){
            b[i]=1;
        }
        l=l+b[i];
    }
    l=l+b[k];
    i=k-1;
    while(i>=1){
        b[i]=b[i+1]-1;
        if(b[i]==0){
            b[i]=1;

        }
        l=l+b[i];
        i--;
    }

    //finding the largest sum 
    int h=0;
    i=k+1;
    while(i<=n){
        b[i]=b[i-1]+1;
        h=h+b[i];
        i++;
    }
    h+=b[i];
    i=k-1;
    
    while(i>=1){
        b[i]=b[i+1]+1;
        h=h+b[i];
        i--;
    }
    //if the sum lies between the largest and minimum then it is valid
    if(l<=m && m<=h){
        return 1;
    }
    if(h<m){
        return 2;
    }
    if(m<l){
        return 3;
    }
    return 0;
 }
 int main(){
    int n;
    int m;
    int k;
    cin>>n>>m>>k;
    int ans=-1;
    int low=1;
    int high=m;
    int flag=0;
    while(low<=high && flag=0){
        int mid=(low+high)/2;
        if(check(mid,k,n,m)==1){
            if(check(mid+1,k,n,m)!=1){
                flag=1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(check(mid,k,n,m)==2){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    cout<<ans;
    return 0;
 }
 /*Understanding :-> We are given “N” points. We have to select k points ; and we have to discuss what is the minimum possible distance b/w any of the k points selected. 
*/
//pretty easy as compared to the last one the difference between 1 hour and 10 minutes 

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ; 
ll n;
bool check(vector <ll> &y,ll k,ll g){
    //check if you can select some points such that all their adjacent difference>=g
    ll p = y[0];
    ll c = 0 ; 
    for(ll i=1;i<=n-1;i++){
        ll diff = abs(p-y[i]);
        if(diff>=g){
            c++;
            p = y[i];
        }
        else{
            
        }
    }
    
    if(c+1>=k){
        return true;
    }
    
    return false;
}

int main() {
    
    
    ll k;
    cin>>n>>k;
    vector <ll> y(n,0);
    for(ll i=0;i<=n-1;i++){
        cin>>y[i];
    }
    sort(y.begin(),y.end());
    ll d = y[n-1] - y[0];
    //cout<<check(y,k,1);
    ll v = 0 ;
    
    
    ll low = 1 ; ll b = 0 ; 
    ll high = d ; 
    while(low<=high && b==0){
        ll mid = (low + high)/2;
        
        if(check(y,k,mid)==true){
            
            if(check(y,k,mid+1)==false){
                v = mid ; 
                b = 1 ; 
            }
            
            else{
                low = mid + 1;
            }
            
            
        }
        
        else{
            high = mid - 1 ;
        }
    }
    
    
    cout<<v;
    
    return 0;
}

/*Understanding :-> Given N chocolates ; 
eat them in min possible days. At first day max 1 chocolate you can eat ; 
in last day also max 1 chocolate you can eat ; and each consecutive 
day you can eat same chocolates as previous or 1 less or 1 more.
*/
//first and the last day are fixed  now we have to distribute  in the remaining array
//now for this we can use a constructive triangle algorithm as triangle approach we will increase till g/2 and the decrease it by 1

//for g days what can be the max amount of choclates if g is even g/2 * g/2+1

//what if g is odd ->g1+g2
//g1=v*(v+1)/2 && g2=y*(y+1)/2

#include <iostream>

using namespace std;

int max_chocolates(int G) {
    if (G % 2 == 0) {
        return (G / 2 * (G / 2 + 1));
    } else {
        int V = G / 2;
        int Y = G / 2 + 1;
        int G1 = V * (V + 1) / 2; // where V = G // 2 (integer division)
        int G2 = Y * (Y + 1) / 2; // where Y = G // 2 + 1 (integer division)
        return (G1 + G2);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int low = 1;
        int high = n;
        int k = 0;
        int answer = 0;

        while (low <= high && k == 0) {
            int mid = (low + high) / 2;
            
            if(max_chocolates(mid)==n){
            	answer = mid ; 
            }
            
            if (max_chocolates(mid) > n) {
                if (max_chocolates(mid - 1) > n) {
                    high = mid - 1;
                } else {
                    k = 1;

                    if (max_chocolates(mid - 1) == n) {
                        answer = mid - 1;
                    } else {
                        answer = mid;
                    }
                }
            } else {
                // mid ---> T
                low = mid + 1;
            }
        }

        cout << answer << endl;
    }

    return 0;
}
/*Understanding :-> You are having an array A of size “N” ;
 create a new array “B” such that maximum number elements
  of array B are larger than array “A” at fixed indices. 
  Array B can only be created by rearranging array “A”.
*/
//find the mid and check if i have enough enlements  to satisfy the condition
#include <bits/stdc++.h>
using namespace std ; 
typedef long long int ll ; 


bool check(ll g,vector <ll> &b){
    
    if(g==0){
        return true;
    }
    
    ll n = b.size();
    ll v = n - 1 ; 
    
    ll i = g - 1 ; 
    
    while(i>=0){
        if(b[v]<=b[i]){
            return false;
        } 
        i--;
        v--;
    }
    return true; 

}

int main() {
    
    ll n ; 
    cin>>n ; vector <ll> b ; 
    ll i = 0 ; 
    while(i<=n-1){
        ll yy ; 
        cin>>yy;
        b.push_back(yy);
        i++;
    }
    
    sort(b.begin(),b.end());
    
    ll answer = 0 ; 
    ll low = 0 ; 
    ll high = n ; 
    ll kk = 0 ; 
    while(low<=high && kk==0){
        ll mid = (low + high)/2;
        if(check(mid,b)==true && check(mid+1,b)==false){
            
            answer = mid;
            kk = 1 ;
            
        } else if(check(mid,b)==true && check(mid+1,b)==true){
            low = mid + 1 ; 
            
        }
        
        else{
            
            high = mid - 1 ;
        }
        
    }
    
    cout<<answer ; 

    return 0 ; 
}

/*Understanding :- We are given 4 arrays of size “N”. We have to solve for 
each index separately and we have to output “N” integers. 
*/
#include<bits/stdc++.h>
using namespace std;
bool check(int mid,int m,int tot,int upd,int sell){
    int left=tot-mid;
    int cost=left*upd;
    int c=mid*sell;
    if(c>=cost){
        return true;
    }
    return false;
}
int solve(int tot,int money,int sell,int upd){
    int low=0;
    int high=tot-1;
    int ans=tot;
    int k=0;
    while(low<=high && k==0){
        int mid=(low+high)/2;
        if(check(mid,money,tot,upd,sell)==true){
            if(mid==0){
                ans=0;
                k=1;
            }
            else{
                if(check(mid-1,money,tot,upd,sell)==false){
                    ans=mid;
                    k=1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main() {
 
    ll n;
    cin>>n;
 
    ll a[n+1],b[n+1],c[n+1],d[n+1];
 
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
 
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
 
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
 
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
 
    for(int i=1;i<=n;i++){
        ll g = solve(a[i],b[i],c[i],d[i]);
        //cout<<g<<" ";
        ll oshi = a[i]-g;
        cout<<oshi<<" ";
    }
 
 
    cout<<'\n';
 
 
 
    return 0;
}


//i dont have the question text because had the image of it but it was an easy one
#include<bits/stdc++.h>
using namespace std;
bool check(int mid, unordered_map<int,int>mp){
    int extra=0;
    for(int i=1;i<n;i++){
        int t=mp[i];
        if(t>mid){//more then the decided load over the server shift to any other server
            extra=extra+abs(t-mid);
            mp[i]=mid;
        }
    }
    for(int i=1;i<=n;i++){
        int t=mp[i];
        int put=abs(mid-t)/2;//shifting to another server over the network
        extra=extra-put;
    }
    if(extra<=0){
        return true;
    }
    return false;
}
int main() {
    n;unordered_map<ll,ll> k;
    cin>>n;ll m;cin>>m;
    ll b[m+1]={0};
    for(ll i=1;i<=m;i++){
        cin>>b[i];
        k[b[i]]++;
    }
    ll answer=0;
    ll low=1;
    ll high=2*m;//when all the m request are assigned to service j and j is not favourite service of any request 
    // for(ll i=1;i<=2*m;i++){
    //     unordered_map<ll,ll> k5 = k;
    //     if(check(i,k5)==true){
    //         answer= i;break;
    //     }
    // }
    while(low<=high){
        ll mid = (low+high)/2;
        unordered_map<ll,ll> k5 = k;
        if(check(mid,k5)==false){
            low = mid + 1;
        }
        else {
            if(mid==1){
                answer = mid;
                break;
            }
            else if(check(mid-1,k5)==false){
                answer = mid;
                break;
            }
            else 
            {
                high = mid-1;
            }
        }
          
    }
    cout<<answer;
}
/*Understanding :-> Given arrays B and C ; and budget D ; 
each element in the array B can be multiplied and increased to a new number ; 
but there is a cost of multiplying which is given by array C

-> Do as many operations as you want but total cost of operations <=D; 

-> Goal -> Minimum value of final array B should be as big as possible!  
*/
#include<bits/stc++.h>
using namespace std;
int b[100001];
int c[100001];
bool check(int mid,int ,int d){
    int tot=0;
    for(int i=1;i<=n;i++){
        if(b[i]>mid){

        }
        else{
            int u=mid/b[i];
            int g=0;
            if(mid%b[i]==0){
                g=mid/b[i];
            }
            else{
                g=mid/b[i]+1;

            }
            tot=tot+(g-1)*c[i];
        }
    }
    if(tot<=d){
        return true;
    }
    return false;

}
 
int main() {
 
    ll n;
    cin>>n;
    ll t = 1e18 ; 
    for(ll i=1;i<=n;i++){
        cin>>b[i];//cout<<b[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>c[i];
    }
    ll d ; cin>>d;
    ll low = 1 ; 
    ll high = d;
    ll ooKK = 0 ; 
    ll k = 0 ; 
    while(low<=high && k==0){
        ll mid = (low + high)/2;
        if(check(mid,n,d)==true){
            if(check(mid+1,n,d)==true){
                low = mid + 1 ; 
            }
            else    {
                ooKK = mid; 
                k = 1 ; 
            }
        }
        else
        {
            high = mid - 1 ; 
        }
    }

    cout<<ooKK;
 
    return 0;
}

            
            