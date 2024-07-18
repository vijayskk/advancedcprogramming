int lengthOfString(char * str){
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}
int countChars(char * str,char target){
    int count = 0;
    int length = lengthOfString(str);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == target)
        {
            count++;
        }
        
    }
    return count;
}

int clearNonAlpha(char * str,char * destination){
    int count = 0;
    int length = lengthOfString(str);
    for (int i = 0; i < length; i++)
    {
        if (str[i]>=65 && str[i]<=122)
        {
            destination[count] = str[i];
            count++;
        }
    }
    return length - count;
}

int strConCat(char * str1,char * str2,char * destination){
    int len1 = lengthOfString(str1);
    int len2 = lengthOfString(str2);

    int count = 0;
    for (int i = 0; i < len1; i++)
    {
        destination[count] = str1[i];
        count++;
    }
    for (int j = 0; j < len1; j++)
    {
        destination[count] = str1[j];
        count++;
    }
    return count;
}

int strCopy(char * str,char * destination){
    int len = lengthOfString(str);
    for (int i = 0; i < len; i++)
    {
        destination[i] = str[i];
    }
    return len;
}

int extractFromString(char * str,int from,int to,char * destination){
    int index = 0;
    for (int i = from; i <= to; i++)
    {
        destination[index] = str[i];
    }
    return index;
}
