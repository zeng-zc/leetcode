// https://leetcode.com/problems/first-unique-character-in-a-string/
// 直观的解法
int firstUniqChar(char* s) {
    int len = strlen(s);
    int i, j, flags[26]={0};  // flags标记字母是否已经出现过
    for (i=0; i<len; ++i){
        if(flags[s[i]-'a'])
            continue;
        for(j=i+1; j<len; ++j){
            if(s[j]==s[i]){
                flags[s[i]-'a']=1;
                break;
            }
        }
        if (j==len)
            break;
    }
    if(i==len)
        return -1;
    else
        return i;
}
// beats 75%

// 解法2：两个数组，一个标记是否重复了，一个记录首次出现位置
int firstUniqChar(char* s) {
    int i, duplicated[26]={0}, first_idx[26];
    for(i=0; i<26; ++i)
        first_idx[i]=-1;
    char *t=s;
    for(; *t; ++t) {
        if(first_idx[*t-'a']<0)
            first_idx[*t-'a'] = t-s;
        else
            duplicated[*t-'a']=1;
    }
    int res=INT_MAX;
    for(i=0; i<26; ++i) {
        if(first_idx[i]<0 || duplicated[i]==1)
            continue;
        if(first_idx[i]<res)
            res=first_idx[i];
    }
    if(res==INT_MAX)
        return -1;
    else
        return res;
}
