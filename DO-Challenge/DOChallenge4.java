
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class DOChallenge4 {

	public static void main(String args[]) throws NumberFormatException, IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());

		while(T-->0)
		{
			String str[]=br.readLine().split(" ");
			int length1=Integer.parseInt(str[0]);

			int nos1[]=new int[length1];

			for(int i=1;i<length1+1;i++)
				nos1[i-1]=Integer.parseInt(str[i]);


			str=br.readLine().split(" ");
			int length2=Integer.parseInt(str[0]);

			int nos2[]=new int[length2];

			for(int i=1;i<length2+1;i++)
				nos2[i-1]=Integer.parseInt(str[i]);

			System.out.println(findMin(nos1,length1,nos2,length2));
		}
	}

	public static int findMin(int A[],int length1,int B[],int length2)
	{


		int i=0;
		int j=0;
		int sum1=0;
		int sum2=0;
		int minSum=0;

		while(i<=length1-1 || j<=length2-1)
		{
           if(i<=length1-1 && j<=length2-1 && A[i]<B[j])
           {
        	   sum1+=A[i++];
        	   
           }
           else if(i<=length1-1 && j<=length2-1 && A[i]>B[j])
           {
        	   sum2+=B[j++];
           }
           else if(i<=length1-1 && j<=length2-1 && A[i]==B[j])
           {
        	   sum1+=A[i++];
        	   sum2+=B[j++];
        	   minSum+=Math.min(sum1,sum2);
        	   sum1=0;
        	   sum2=0;
        	   
           }
          
           else if(j<length2)
           {
        	   sum2+=B[j++];
           }
           else if(i<length1)
           {
        	   sum1+=A[i++];
           }
            
		}
            minSum+=Math.min(sum2, sum1);
            return minSum;
	}
}