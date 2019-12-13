void reverse(char *pointerCharArray, int length){
	int i;
	for(i = 0; i < (length + 1) / 2; i++){	
		char temp = pointerCharArray[i];
		pointerCharArray[i] = pointerCharArray[length - 1 - i];
		pointerCharArray[length - 1 - i] = temp;	
	}		
}

void moveCharArrToInt(char *pointerCharArray, int *pointerIntArray, int length){
	int i;
	for(i = 0; i < length; i++){
		*(pointerIntArray + i) = *(pointerCharArray + i) - (int)('0');
	}
}
