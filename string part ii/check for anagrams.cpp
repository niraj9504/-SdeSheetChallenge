bool areAnagram(string &s1, string &s2){
    if(s1.size()!=s2.size())return false;
    vector<int> v(26);
    for(auto it:s1)v[it-'a']++;
    for(auto it:s2)v[it-'a']--;
    for(auto it:v)if(it!=0)return false;
    return true;
}
