void fun(struct node* start)
{
    if(start == NULL)
        return;
    
    printf("%c",start->data); // considering data is of 'char' type

    if(start->next!=NULL)
        fun(start->next->next);
    printf("%c",start->data);
}