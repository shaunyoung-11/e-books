#include "lab52.h" // 请不要删除本行头文件，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

extern int CurrentCnt; // 请不要删除本行的全局变量声明，否则检查不通过

bool insert_item(GoodsList* L, GoodsInfo goodsInfo, int choice)
{
    GoodsList* temp;
    GoodsList *pre = L, *p = L->next;
    int i;
    if (CurrentCnt >= 100) {
        printf("信息库已满，要插入请先删除一定量的商品数据!\n");
        return false;
    }
    switch (choice) {
    case 0:
        //尾插法插入新商品
        while (p != NULL) {
            pre = p;
            p = p->next;
        }
        temp = (GoodsList*)malloc(sizeof(GoodsList));
        temp->data = goodsInfo;
        pre->next = temp;
        temp->next = NULL;
        printf("Tips:添加商品%s成功\n", goodsInfo.goods_name);
        CurrentCnt++;
        return true;
    case 1:
        //头插法插入新商品
        temp = (GoodsList*)malloc(sizeof(GoodsList));
        temp->data = goodsInfo;
        temp->next = L->next;
        L->next = temp;
        printf("Tips:添加商品%s成功\n", goodsInfo.goods_name);
        CurrentCnt++;
        return true;
    default:
        //中间i号位置插入新商品，例如：输入3，应该在第二个节点后插入新节点
        // CurrentCnt 改为 CurrentCnt+1，因为当 CurrentCnt 为2时，链表中有两个记录，
        // 此时输入3，即 choise为 3，表示在第二条记录后插入数据，新记录成为第3条数据
        if (choice <= CurrentCnt + 1 && choice > 0) {
            for (i = 1; i < choice; i++) {
                pre = p;
                p = p->next;
            }
            temp = (GoodsList*)malloc(sizeof(GoodsList));
            temp->data = goodsInfo;
            pre->next = temp;
            temp->next = p;
            printf("Tips:添加商品%s成功\n", goodsInfo.goods_name);
            CurrentCnt++;
            return true;
        } else {
            printf("输入的位置超出当前商品列表范围\n");
            return false;
        }
    }
}
