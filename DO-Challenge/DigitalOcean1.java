
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class DigitalOcean1 {
static int A[];
static int B[];

	public static void main(String args[]) throws NumberFormatException, IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int T=Integer.parseInt(br.readLine());

		while(T-->0)
		{
			String str[]=br.readLine().split(" ");
			int length1=Integer.parseInt(str[0]);

			A =new int[length1];

			for(int i=1;i<length1+1;i++)
				A[i-1]=Integer.parseInt(str[i]);


			str=br.readLine().split(" ");
			int length2=Integer.parseInt(str[0]);

			B=new int[length2];

			for(int i=1; i<length2+1; i++)
				B[i-1]=Integer.parseInt(str[i]);
			
			System.out.println(findMin(length1,length2));
		}
	}

	public static long findMin(int length1,int length2)
	{
		
		if(length1<0 && length2<0)
			return 0;
		
		int i=length1-1;
		int j=length2-1;
		long sum1=0;
		long sum2=0;

		while(i>=0 || j>=0)
		{
			
			if(i>=0 && j>=0 && A[i]>B[j] )
			{
				sum1+=A[i];
				i--;
				
			}
			else
				if(i>=0 && j>=0 && A[i]<B[j] )
				{
					sum2+=B[j];
					j--;
					
				}
				else if(i>=0 && j>=0 && A[i]==B[j] )
					{
						sum1+=A[i];
						sum2+=B[j];
						
						if(i==0 && j==0)
							return Math.min(sum1, sum2);
						

					
					long minValue=findMin(i,j);
					
						return Math.min(sum1+minValue,sum2+minValue);
						
					}
			
					else if(i>j)
					{
						sum1+=A[i];
						i--;
						
					}
					else 
					{
						sum2+=B[j];
						j--;
					}
		}
		return Math.min(sum1,sum2);

	}


}