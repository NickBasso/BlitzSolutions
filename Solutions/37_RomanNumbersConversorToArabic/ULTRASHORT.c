#include<stdio.h> 
void main(){freopen("input.txt","r",stdin);char s[10]={0};int a['Z' + 1],i=0,ans=0,len;a['I']=1;a['V']=5;a['X']=10;a['L']=50;a['C']=100;a['D']=500;a['M']=1000;scanf("%s",s);while(s[i])i++;len=i;ans+=a[s[0]];i=1;while(i<len){ans+=a[s[i-1]]<a[s[i]]?-2*a[s[i-1]]+a[s[i]]:a[s[i]];i++;}printf("%d",ans);}
