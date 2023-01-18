    #include<stdio.h>
    #include<stdlib.h>
    typedef struct
    {
    int value;
    struct rep *repptr;
    struct node *next;
    }node;
    typedef struct
    {
    node *head;
    node *tail;
    }rep;
    typedef struct
    {
    int key;
    node *obj_node_ptr;
    struct nodaddr *next;
    }nodaddr;
    nodaddr *ndr=0;
    void makeset(int a)
    {
    nodaddr *t=(nodaddr*)malloc(sizeof(nodaddr));
    rep *newset=(rep*)malloc(sizeof(node));
    node *n=(node *)malloc(sizeof(node));
    n->value=a;
    n->repptr=newset;
    n->next=0;
    newset->head=newset->tail=n;
    t->obj_node_ptr=n;
    t->key=a;
    t->next=ndr;
    ndr=t;
    }
    rep *find(int x)
    {
    nodaddr *t=ndr;
    while(t->key!=x && t!=0)
    t=t->next;
    return t->obj_node_ptr->repptr;
    }
    void unionset(int key1,int key2)
    {
    rep *set1,*set2;
    node *t1;
    set1=find(key1);
    set2=find(key2);
    if(set1==set2)
    printf("\n %d and %d belongs to same set \n",key1,key2);
    else
    {
    t1=set2->head;
    while(t1!=0)
    {
    t1->repptr=set1;
    t1=t1->next;
    }
    set1->tail->next=set2->head;
    set1->tail=set2->tail;//set the tail of set1 to tail of set2
    t1=set1->head;
    free(set2);
    }
    }
    void display_set(int a)
    {
    int i=0;
    rep *r;
    node *t;
    r=find(a);
    t=r->head;
    printf("set members containing %d :",a);
    while(t!=0)
    {
    printf("%d ",t->value);
    t=t->next;
    }
    }
    void main()
    {
    int opt,data,data1,data2;
    do
    {
    printf("\n 1.insert \n");
    printf("\n 2.find set \n");
    printf("\n 3.union set \n");
    printf("\n 4.display set \n");
    printf("\n 5.exit \n");
    printf("enter your option :");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:
    printf("Enter the data :");
    scanf("%d",&data);
    makeset(data);
    break;
    case 2:
    printf("Enter set value :");
    scanf("%d",&data);
    printf("Reference of set containing %d is %X",data,find(data));
    break;
    case 3:
    printf("enter the data :");
    scanf("%d%d",&data1,&data2);
    unionset(data1,data2);
    break;
    case 4:
    printf("enter the data :");
    scanf("%d",&data);
    display_set(data);
    break;
    case 5:
    exit(0);
    }
    }
    while(1);
    }






              
