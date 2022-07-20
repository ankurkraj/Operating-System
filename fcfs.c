#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int Process[]={1,2,3,4,5};
	int AT[]={1,1,3,2,4};
	int ATC[]={1,1,3,2,4};
	int BT[]={2,1,8,4,5};
	int BTC[]={2,1,8,4,5};
	int Priority[]={2,1,4,2,3};


void fcfs(){
	int order[5];
	int wt[5];
	int turn[5];
	int st[5];
		int x;
		int l=0;

	for(int i=0;i<5;i++){
		int min=INT_MAX;
		for(int j=0;j<5;j++){
			if(AT[j]<min){
				min=AT[j];
				x=j;
			}

		}
		order[l++]=x;
		AT[x]=INT_MAX;
	}
	// for(int i=0;i<5;i++){
	// 	printf("%d ",order[i]);
	// }
	// for(int i=0;i<5;i++){
	// 	printf("%d ",AT[i]);
	// }
	double avwt=0;
	double avturn=0;
	st[0]=ATC[order[0]];
	//wt[1]=ATC[order[0]]+BT[order[0]];

	for(int i=1;i<5;i++){
		st[i]=st[i-1]+BT[order[i-1]];
	 }
	 for(int i=0;i<5;i++){
	 	wt[i]=st[i]-ATC[order[i]];
	 }
	 for(int i=0;i<5;i++){
	 	turn[i]=wt[i]+BT[order[i]];
	 }

	 printf("Order of Processes:\n");
	 for(int i=0;i<5;i++){
	 	printf("P%d ",order[i]+1);
	 }

	 printf("\n");
	 printf("Wait time of each process:\n");
	 for(int i=0;i<5;i++){
		avwt=avwt+(double)wt[i];
		printf("P%d: %d\n",order[i]+1,wt[i]);
	}

	printf("\n");
	printf("Turnaround time of each process:\n");
	for(int i=0;i<5;i++){
	 	avturn=avturn+(double)turn[i];
	 	printf("P%d: %d\n",order[i]+1,turn[i]);
	 }

	printf("\n");
	avturn=avturn/5;
	avwt=avwt/5;
	printf("Average Wait Time: %lf\n",avwt);
	printf("Average Turnaround Time: %lf\n",avturn);

}



int main(){
	printf("FCFS Algorithm Analysis:\n");
	fcfs();

	return 0;
}