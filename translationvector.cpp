#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main()
{
	int gd=DETECT,gm;
	int i,j,k,obj[3][3],img[3][3],T[3][3];
	
	//input translation vector and object matrix
	printf("Enter the translation matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++){
			printf("Enter the element [%d][%d] : ",i,j);
			scanf("%d",&T[i][j]);}
	}
	printf("Enter the object matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter the element [%d][%d] : ",i,j);
			scanf("%d",&obj[i][j]);
		}
	}
	//matrix multiplication to find img
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			img[i][j] = 0;
			for(k=0;k<3;k++)
				img[i][j] += T[i][k] * obj[k][j];
		}
	}
	printf("\nThe product of the matrix is: \n");
	for(i=0;i<3;i++){
	 for(j=0;j<3;j++){
	  printf("%d\t",img[i][j]);
	 }
	 printf("\n");
	}
	
	
	int ax1,ay1,ax2,ay2,ax3,ay3;
	int bx1,by1,bx2,by2,bx3,by3;
	ax1 = obj[0][0];
	ay1 = obj[1][0];
	ax2 = obj[0][1];
	ay2 = obj[1][1];
	ax3 = obj[0][2];
	ay3 = obj[1][2];
	bx1 = img[0][0];
	by1 = img[1][0];
	bx2 = img[0][1];
	by2 = img[1][1];
	bx3 = img[0][2];
	by3 = img[1][2];
	
	//draw triangles
	initgraph(&gd, &gm,"");
	line(ax1,ay1,ax2,ay2);
	line(ax2,ay2,ax3,ay3);
	line(ax3,ay3,ax1,ay1);
	//drawing transformed triangle
	line(bx1,by1,bx2,by2);
	line(bx2,by2,bx3,by3);
	line(bx3,by3,bx1,by1);
	getch();
}
//output
//Enter the translation matrix
//1 0 2
//0 1 3
//0 0 1
//Enter the object matrix
//200 500 400 or 50 100 80
//200 200 400 or 50 50 100
//1 1 1 
