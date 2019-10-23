int main(){

    str a;
	int b[12],i;
	printf("%s ",a);
	scanf("%s ",&a);
	for (i=0;i<strlen(a);i++){
		
		if (a[i]=='A'){
			b[i]=11;
				}
		if (a[i]=='B'){
			b[i]=12;
				}
		if (a[i]=='C'){
			b[i]=13;
				}
		if (a[i]=='D'){
			b[i]=14;
				}
		if (a[i]=='E'){
			b[i]=15;
				}
		if (a[i]=='F'){
			b[i]=16;
				}
		if (((a[i]>,(int)('0'))&&(a[i]<(int)('9'))){
			b[i]=(int)('a[i]')-48;
		}												
}

}
