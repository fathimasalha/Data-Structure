    #include<stdio.h>
    #include<stdlib.h>
    struct node
    {
    int data;
    struct node *lchild,*rchild;
    };
    //function to insert a data in BST
    struct node *insert(struct node *root,int data)
    {
    struct node *t1,*t2,*t;
    t1=root;
    t2=(struct node *)0;
     
     
    //finding node to insert
    while(t1!=(struct node *)0 && t1->data!=data)
    {
    t2=t1;
    if(data<t1->data)
    t1=t1->lchild;
    else
    t1=t1->rchild;
    }
    if(t1!=(struct node *)0)
    //data already exist
    printf("Duplicate. \n");
    else
    {
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->lchild=t->rchild=(struct node *)0;
    if(root==(struct node *)0)
    root=t;
    else
    {
    if(data<t2->data)
    t2->lchild=t;
    else
    t2->rchild=t;
    }
    }
    return root;
    }
   //function to display 
    void inorder(struct node*root)
    {
    if(root!=(struct node*)0)
    {
    inorder(root->lchild);
    printf("%d\t",root->data);
    inorder(root->rchild);
    }
    }
    //function to search an item
    struct node *search(struct node *root,int item)
    {
    struct node *t=root;
    while(t!=(struct node *)0 && t->data!=item)
    if(item<t->data)
    t=t->lchild;
    else
    t=t->rchild;
    return t;
    }
     
     
    //function to delete an item in BST
    struct node *delete(struct node *root,int item)
    {
    struct node *t1,*t,*par,*supar,*suc;
    t1=root;
    par=(struct node *)0;
    while(t1!=(struct node *)0 && t->data!=item)
    {
    par=t;
    if(item<t->data)
    t=t->lchild;
    else
    t=t->rchild;
    }
    if(t==(struct node *)0)
    printf("%d not found \n",item);
    else
    {
    if(t->lchild==(struct node *)0 && t->rchild==(struct node *)0)
    //case of zero child
    {
    if(par==(struct node *)0)
    //return  root
    root==(struct node *)0;
    else
    if(t->data>par->data)
    par->rchild==(struct node *)0;
    else
    par->lchild=(struct node *)0;
    }
    else if(t->lchild==(struct node *)0 || t->rchild==(struct node *)0)
    //case of one child
    {
    if(par==(struct node *)0)
    root=root->lchild==(struct node *)0 ? root->rchild:root->lchild;
    else if(t->data>par->data)
    par->rchild=t->lchild==(struct node *)0 ? t->rchild:t->lchild;
    else
    par->lchild=t->lchild==(struct node *)0 ? t->rchild:t->rchild;
    }
    else
    //case of 2 children
    {
    supar=t;
    suc=t->rchild;
    //find inorder successor of t
    while(suc->lchild!=0)
    supar=suc;
    suc=suc->lchild;
    }
    //copy inorder successor data to t
    t->data=suc->data;
    //delete inorder suc
    if(suc->data<supar->data)
    supar->lchild=suc->rchild;
    else
    supar->rchild=suc->rchild;
    t=suc;
    }
    free(t);
    return root;
    }
     
     
    int main()
    {
    struct node *t=(struct node *)0;
    int opt,t1,data;
    do
    {
    printf("\n 1.insert \n");
    printf("\n 2.display\n");
    printf("\n 3.search \n");
    printf("\n 4.delete \n");
    printf("\n 5.exit \n");
    printf("\n option:");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:
          printf("data:");
          scanf("%d",&data);
          t=insert(t,data);
          break;
    case 2:inorder(t);
          break;
    case 3:printf("item to search:");
        scanf("%d",&data);
        t=search(t,data);
        if(t==(struct node *)0)
        printf("not found");
        else
        printf("found");
        break;
    case 4:printf("item to delete:");
        scanf("%d",&data);
        t=search(t,data);
        if(t!=(struct node *)0){
        t=delete(t,data);
        printf("item deleted %d",data);}
        else  
        printf("not exist\n");       
        break;
    case 5:exit(0);
    }
    }
    while(1);
    }

    
