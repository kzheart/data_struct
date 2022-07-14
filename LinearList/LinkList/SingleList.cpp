//
//  SingleList.c
//  linear-table
//
//  Created by kzheart on 2022/7/13.
//

#include "SingleList.h"
#include <stdlib.h>
void InitList(SingleList &list){
    list = (SingleList)malloc(sizeof(SingleList));
}
int Length(SingleList list,bool isExistHeadPoint){
    int init = 0;
    if(isExistHeadPoint){
        init = -1;
    }
    SingleNode *node;
    while(list->next!=NULL){
        
    }
}


