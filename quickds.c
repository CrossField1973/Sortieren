#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MENGE 50000
#define REICHWEITE 20


/*------------------typedef-------------*/
typedef struct 
{
	int randNumbers[MENGE];
} T_Feld;
/*--------------------------------------*/

int m=1;



/*-------------Funktionen---------------*/
void printFirstPart				(T_Feld* p_feld);
void bestueckeMitNummern		(T_Feld* p_feld);
void quickSortieren				(T_Feld* p_feld, int links, int rechts);
/*--------------------------------------*/


int main()
{
	T_Feld feld;
	T_Feld *p_feld = &feld;
	
	bestueckeMitNummern(p_feld);
	
	printf("Vor der Sortierung\n\n");
	printFirstPart(p_feld);
	printf("\n\n\n");
	
	quickSortieren(p_feld, 0, MENGE - 1);
	
	printf("Nach der Sortierung\n\n");
	printFirstPart(p_feld);
	
	
	return 0;
}


/*-------Zeig die ersten Zahlen---------*/
void printFirstPart(T_Feld* p_feld)
{
	int j;
	
	
	printf("\n");
	
	for(j = 1;	 j <= 32; j++)
	{
		printf("%10d", p_feld->randNumbers[j]);
		
		if((j % 8) == 0)
		{
			printf("\n");
		}
	}

}
/*--------------------------------------*/



/*-----------feld bestücken---------------*/
void bestueckeMitNummern(T_Feld* p_feld)
{
	int i;
	
	for(i = 0; i < MENGE; i++)
	{
		p_feld->randNumbers[i] = rand();// % (REICHWEITE + 1);
	}
}
/*----------------------------------------*/




/*----------------Quick Sort--------------*/
void quickSortieren(T_Feld* p_feld, int links, int rechts)
{
	int iLi, iRe, med;
	int tmp;
	
	iLi = links;
	iRe = rechts;

	med = (links + rechts) / 2;
	
	while(iLi < iRe)
	{
		while(p_feld->randNumbers[iLi] < p_feld->randNumbers[med])	iLi++;
		while(p_feld->randNumbers[iRe] > p_feld->randNumbers[med])	iRe--;
		
		//Tausche (feld[iLi], feld[iRe])
		tmp 						= p_feld->randNumbers[iLi];
		p_feld->randNumbers[iLi] 	= p_feld->randNumbers[iRe];
		p_feld->randNumbers[iRe] 	= tmp;
		
		if		(iLi == med)	med = iRe;
		else if	(iRe == med)	med = iLi;
		
		
		if(iLi < med)		iLi++;
		if(iRe > med)		iRe--;
		
	}
	
	if(links < med - 1)
	{
		quickSortieren(p_feld, links, med - 1);
	}
	
	if(rechts > med + 1)
	{
		quickSortieren(p_feld, med + 1, rechts);
	}
//	printf("erl.%5d ",m++);
}
/*----------------------------------------*/
