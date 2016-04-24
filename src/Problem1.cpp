/*
Given a Binary Tree of N Nodes, which have unique values in the range of 
[0,N](Inclusive)  with one value(Node) missing in that sequence.
Return that missing value .

Example 1 : N=5 
   3
  / \
 4   1
    / \
   5   0
Missing Value is 2 ,Sequence is [0,1,2,3,4,5]

Example 2 : N=8
      2
     / \
    4   5
   / \ / \
  3  1 6  8
 /
0
Missing Value is 7 ,Sequence is [0,1,2,3,4,5,6,7,8]

Constaints : 
-10000<=N<=10000 [N will not be equal to 0]



Input :
Struct node Root Address
Output :
Return Missing Value .
Return -1 for NULL Inputs 

Note:
Dont Create an Extra Array/String ,or else your solution would receive 30% Cut in the Marks you got for this
question .

Difficulty : Easy
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

int get_missing_value(struct node *root, int n){
	int sum = 0, min =9999, max =-9999,no=0;
	struct node *temp = NULL,*temp1=NULL;
	if (root == NULL || n <= 0)
		return -1;
	temp = root;
	temp1 = root;
	no = n;
	while ((temp != NULL || temp1 != NULL) && (no>0))
	{
		if ((temp != NULL))
		{
			if ((temp->data>max))
			max = temp->data;
			if (temp->data<min)
				min = temp->data;
			temp = temp->left;
			no--;
		}
		if ((temp1 != NULL) && (temp1!=root))
		{
			if ((temp1->data>max))
				max = temp1->data;
			if ((temp1->data<min))
				min = temp1->data;
			temp1 = temp1->left;
			no--;
		}
		
	}
	while (max >= min)
	{
		sum += max;
		max--;
	}
	temp = root;
	temp1 = root;
	no = n;
	while ((temp != NULL || temp1 != NULL)&&no>0)
	{
		if ((temp != NULL))
		{
			if (temp->data >= 0)
			sum -= temp->data;
			if (temp->left != NULL)
			temp = temp->left;
			else if (temp->right != NULL)
				temp = temp->right;
			no--;
		}
		if ((temp1 != NULL) && (temp1!=root))
		{
			if (temp1->data>=0)
			sum -= temp1->data;
			if (temp1->right!=NULL)
			temp1 = temp1->left;
			else if (temp1->right != NULL)
				temp1 = temp1->left;
			no--;
		}
	}
	return sum;
}