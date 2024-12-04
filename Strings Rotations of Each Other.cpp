//This question is about checking if the other string is of rotated string of first one or not.
//I am taking help of computelps from KMP algorithm.
void computelps(string pat, vector<int>& lps)
{
    int length= 0;
    lps[0]=0;
    int i=1;
    while(i<pat.size())
    {
        if(pat[i]==pat[length])
        {
            length++;
            lps[i]=length;
            i++;
        }
        else
        {
            if(length != 0)
            {
                length=lps[length-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
vector<int> search(string& pat, string& txt) {
    // code here
    int m= pat.size();
    int n= txt.size();
    vector<int> lps(m);
    computelps(pat,lps);
    vector<int> ans;
    int i=0;
    int j=0;
    
    while(i<n)
    {
        if(pat[j]== txt[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            ans.push_back(i-j);
            j= lps[j-1];
        }
        else if(i<n && pat[j] != txt[i])
        {
            if(j !=0)
            {
                j= lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return ans;
}
// Function to check if two strings are rotations of each other or not.
bool areRotations(string &s1, string &s2) {
    // Your code here
    string concat = s1+s1;
    vector<int> count=search(s2,concat);
    count.push_back(-1);
    if(count[0] != -1)
    {
        return true;
    }
    return false;
}
