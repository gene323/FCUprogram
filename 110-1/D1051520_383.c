bool canConstruct(char * ransomNote, char * magazine){
    
    int flag = 1;//judge whether the answer is true or false 
    int a[26] = {0};//counting the number of letter of ransomNote
    int b[26] = {0};//counting the number of letter of magazine
    for(int i=0; i<strlen(ransomNote); i++)
        a[ransomNote[i]-'a']++;
    
    for(int i=0; i<strlen(magazine); i++)
        b[magazine[i]-'a']++;
    
    for(int i=0; i<26; i++)
    {
        if(a[i] > b[i])
        {
            flag = 0;
            break;
        }
    }
    
    if(flag == 1)
        return true;
    else
        return false;
}