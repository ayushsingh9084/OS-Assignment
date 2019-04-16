/*Ques. 10. Design a scheduler with multilevel queue having two queues which will schedule the processes on the basis  of  pre-emptive shortest remaining processing time first algorithm (SROT) followed by a scheduling in which each process will get 2 units of time to execute. Also note that queue 1 has higher priority than queue 2.  Consider the following set of processes (for reference)with their arrival times and the CPU burst times in milliseconds.
-------------------------------------
Process  Arrival-Time   Burst-Time
-------------------------------------
P1             0      	             5
P2             1             	     3
P3             2                     3
P4             4                     1
-------------------------------------
Calculate the average turnaround time and average waiting time for each process. The input for number of processes  and their arrival time, burst time should be given by the user.
*/

#include<stdio.h> 	//header file for standard input-output
#include<windows.h> //header file for sleep 
int i,tat[20],wt[20],totalwait,totalturn;
int nop=1;
int avgwt,avgtat;
int pr[20],bur[20],prior[20]; 	//initilizing varible process, arrival time, burst time, priority of max size 20
int main()			//main function begins
{
	printf("\t\t....Initializing Scheduling Opeation....");
	Sleep(1000);
	printf("\t\t\t Priority Scheduling\t\t\t");
	printf("\nEnter the no of processes you want to perform scheduling: ");
	scanf("%d",&nop); 	//total no of processes
	
	for(i=0;i<nop;i++)		//oinput for processes
	{
		pr[i]=i;
	}
		
	for(i=0;i<nop;i++) 				//input for burst time
	{
		printf("\nEnter burst time for Process-ID %d:",i);
		scanf("%d",&bur[i]);
	}
	
	for(i=0;i<nop;i++) 				//input for priority
	{
		printf("\nEnter priority for Process-ID %d:",i);
		scanf("%d",&prior[i]);
	}
	printf("\n.......................................................\n");
//...................printing the table...............................	
	
//............applying conditions of preemptive priority sceduling..........
	
	for(i=0;i<nop;i++)
	{
		if(prior[i]>prior[i+1])
		{
			printf("\n.......Process %d Running...... ",pr[i+1]);
			printf("\n.......Process %d Terminated...... ",pr[i]);		
			bur[i+1]--;
		}

		else if(prior[i]<prior[i+1])
		{
			bur[i]=0; 
			printf("\n....Process %d Teriminated...\n",pr[i+1]);
			printf("\n....Process %d Running....\n",pr[i]);
		}
		Sleep(1000);			//initializing sleep
	}
	
	printf("\n\nScheduling Operation Successfully Terminated!!");
//....................calculating avg. waiting time and avg. turnaround time............
	//turnaroundtime= completiontime-arrivaltime
	//waitingtime= turnaroundtime-bursttime
	for (i=0;i<nop;i++)  
        wt[i] =  bur[i-1] + prior[i-1] ;  //waiting time
	
	for (i=0;i<nop;i++)  
    	tat[i] = bur[i] + wt[i];  
    for(i=0;i<nop;i++)
    {
		totalwait = totalwait + wt[i];  
	    totalturn = totalturn + tat[i];  
	}
	avgwt=(float)totalwait / (float)nop; 
    avgtat=(float)totalturn / (float)nop; 
    printf("\nTotal waiting time = %d",totalwait); 
    printf("\nTotal turnaround time = %d",totalturn); 
	printf("\nAverage waiting time = %d",avgwt); 
    printf("\n"); 
    printf("\nAverage turn around time = %d ",avgtat); 
//..................................................................................
	return 0;
} 			//end of main

