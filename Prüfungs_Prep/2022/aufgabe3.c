

//implemeting vergleich funtion
int cmpLand(const void* p1, const void* p2){

	const tWrg* w1=p1;
	const tWrg* w2=p2;
	
	return strcmp(w1->land,w2->land);
}

int containsLand(const tNode* head, const char* land){

	//address of first node	
	tNode* curr = head;

	while(cur){

	tWrg* w = (twrg*)curr->pData;

	if(strcmp(w->land,land)==0){

		 return 1;
		 curr = curr->pNext;
	}
	
	
}

		return 0;


	}
	
	
	

