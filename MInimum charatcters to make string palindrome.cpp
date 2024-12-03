//to solve this problem i have used the LPS(Longest Prefix Suffix) concept.

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

int minChar(string& s) {
    // Write your code here
    string rev= s;
    reverse(rev.begin(),rev.end());
    string concat = s + '$' + rev;
    vector<int> lps(concat.length());
    computelps(concat,lps);
    return s.length() - lps.back();
}
