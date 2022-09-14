bool isAnagram(char * s, char * t){
    int a[26] = {0};//counting the number of letter of char s    
    int b[26] = {0};//counting the number of letter of char t
    for(int i=0; i<strlen(s); i++)
    {
        a[s[i]-'a']++;
        
    }
    for(int i=0; i<strlen(t); i++)
    {
        b[t[i]-'a']++;
    }
    
    int flag = 0;//judge whether this input is true or false 
    for(int i=0; i<26; i++)
    {
        if(a[i] != b[i])
        {
            flag = 1;
            break;
        }
    }
    
    if(flag == 0)
        return true;
    else
        return false;
}