int main(){
char str[100],key[26];
int i,j,len,found;
printf("enter text : ");
len = read_text(str,sizeof(str),1);

    do {
        printf("enter key (%d different characters):  " ,26);
        read_text(key,sizeof(key),1);
        found = 0;
        for(i=0;i<26;i++)
        {
            for(j=i+1;j<26;j++)
            {
                if(key[i]==key[j])
                {
                    found = 1;
                    printf("enter characters should be different\n");
                    break;
                }
            }
            if(found == 1)
            {
                break;
            }
        }
    }while(found != 0);
    for(i=0;i<len;i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i] = key[str[i]-'a'];//afaireis ton xarakthra a
            // gia na pareis to gramma ths alfavhtoy
        }
    }
    printf("encrypted text : %s\n" , str);
    for(i=0;i<len;i++)
    {
        for(j=0;j<26;j++)
        {
            if(str[i] == key[j])
            {
                str[i] = 'a'+j;
                break;
            }
        }
    }
    printf("original text : %s\n",str);
    return 0;
    }
