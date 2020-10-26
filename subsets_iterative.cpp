// Given a set of {1, 2 .., n} integers,  this code
// works out all the possible subsets of size k.

// ITERATIVE METHOD

// Compile with: g++ subsets_iterative.cpp -o subsets_ix -lm -O
// on Linux or Unix run with command ./subsets_ix


#include <iostream>
#include <cmath>
#include<limits>

using namespace std;

void print_array(unsigned long *A, unsigned long k, unsigned long j);
unsigned long increase_word(unsigned long *A, unsigned long n, unsigned long k);

int main(void)
{
	    unsigned long i=0, g=0, *A, n=0, k=1,j=0;
	    bool cycle =1;                          /*Value of "cycle" decideds whether to continue looping*/
	    while(k>n)
	    {	
		        printf("Enter a value for N: "); 	/*Size of set*/
		        scanf("%ul", &n);
		        printf("Enter a value for K: ");	/*Size of subsets*/
		        scanf("%ul", &k);
	    }
	    printf("The chosen values are: N= %u, K= %u\n\n",n,k);
    	A=new unsigned long [k];               /*A= Array to hold the subsets*/
	    j=1;			                       /*j= Counts the number of subsets computed*/
	    for(i=0;i<k;++i)                       /*A[] is initialised with the trivial subset*/
	        A[i]=i+1;
     print_array(A,k,j);
	    do{
	        g=increase_word(A,n,k);    /*Checks 2C if an entry needs updating in the array*/
	        if(g==0)                   /*g= current value of A[k-1]*/
		            cycle=0;
	        else
	        {
		            for(i=g;i<n+1;++i){
			            A[k-1]=i;print_array(A,k,j);++j;}		
	        }
	    } while (cycle ==1);
	    printf("\n\n%u Choose %u = %u\n",n,k,j);
	    delete A;
	    return(0);
}

void print_array(unsigned long *A,unsigned long k, unsigned long j)
{
	    unsigned long i;
	    printf("{");
	    for(i=0;i<k-1;++i)
		    printf("%u, ", A[i]);
	    printf("%u}  subset number= %u \n",A[i],j);
}

unsigned long increase_word(unsigned long *A, unsigned long n, unsigned long k)
{
	    unsigned long i;
	    for(i=k;i>0;--i) 	/*Starting from A[k-1], entries are tested for increase*/                
		    if(A[i-1]<(n+i-k)){
			    A[i-1]+=1;break;}
	    if(i==0)
		    return(0);
	    else
		    for(i=i;i<k;++i)  /*If an increase was made to A[i]-1 for some i, A[i]->A[k-1] are reset*/
			    A[i]=A[i-1]+1;
	    return(A[k-1]);
}
