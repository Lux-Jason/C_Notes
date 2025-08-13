/*
=============================================
 Name: L7T1T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 4
typedef struct stack_info
{
	int    Data[SIZE];
	int    top;
	int    bottom;
	int    size;
	int    count;
}stack_t;

void push(stack_t* stack, int data)
{
	if (stack->count == SIZE)
	{
		printf("Unsuccessful push operation: Stack is full\n");
		return ;
	}
	else
	{
		stack->Data[stack->top] = data;
		stack->top++;
		stack->count++;
	}
	return ;
}
int pop(stack_t* stack)
{
	int data;
	if (stack->count == 0)
	{
		return -1;
	}
	else
	{
		data = stack->Data[--(stack->top)];
		stack->count--;
		return data;
	}
}
int main()
{
	stack_t stack;
	int i = 0;
	int n = 0;
	memset(&stack, 0, sizeof(stack));
	printf("Please choose action(1: Push 2: Pop  0: Exit):");
	scanf("%d", &n);
	while (n)
	{
		if (1==n)
		{
			int m = 0;
			printf("Enter an integer to push: ");
			scanf("%d", &m);
			push(&stack, m);
			printf("\n----------------------\n");
			printf("| Stack:");
			for (int i = 0; i < stack.count; i++)
			{
				printf("%d ", stack.Data[i]);
			}
			printf("\n----------------------\n");
			printf("Please choose action(1: Push 2: Pop  0: Exit):");
			scanf("%d", &n);
		}
		else if (2 == n)
		{
			if (0!=stack.count)
			{
				printf("Popped: %d\n", pop(&stack));
			}
			else
			{
				printf("Unsuccessful pop operation: Stack is empty\n");
			}
			printf("\n----------------------\n");
			printf("| Stack: ");
			for (int i = 0; i < stack.count; i++)
			{
					printf("%d ", stack.Data[i]);
			}
			printf("\n----------------------\n");
			printf("Please choose action(1: Push 2: Pop  0: Exit):");
			scanf("%d", &n);
		}
	}
	printf("Exiting the program\n");
	return 0;
}
