/* Author: Zhu Gengyu
   Date : 2016/8/12
   Propose: Test simple link-list*/
   
   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>
   #include <stdbool.h>
   
   struct simnode{
   	int data;
   	int key;
   	struct node *next;
   };
   
   struct simnode *head = NULL;
   struct simnode *current = NULL;
   
