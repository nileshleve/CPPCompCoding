#include<stdio.h>


struct student_marks
{
	int subj1;
	int subj2;
	int subj3;
	int total;
};

main()
{
	int i,x,j, subject[3];
	struct student_marks student[3];
	x=0;
	for(i=0;i<3;i++)
	{
		printf("enter marks of student[%d]\n",i+1);
		fflush(stdin);
		scanf("%d %d %d",&student[i].subj1, &student[i].subj2, & student[i].subj3);
		fflush(stdin);	
	}
	//struct student_marks total1 ;
	i = 0;
	for(i=0;i<3;i++)
	{
		student[i].total = student[i].subj1 + student[i].subj2+student[i].subj3 ;
		if(i==0)
		{
			subject[i] = student[i].subj1 + student[i+1].subj1 + student[i+2].subj1;
		}
		 else if (i==1)
		 {
		 	subject[i] = student[i-1].subj2 + student[i].subj2 + student[i+1].subj2;
		 }
		 else
		 subject[i] = student[i].subj3+student[i-1].subj3+student[i-2].subj3; 
	}
	
	for(i=0;i<3;i++)
	{
		printf("\nstudent[%d] = %d",i+1,student[i].total);
	}
	for(i=0;i<3;i++)
	{
		printf("subject[%d] total = %d",i+1, subject[i]);
	}
}