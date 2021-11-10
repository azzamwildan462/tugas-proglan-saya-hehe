#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_t
{
    char *nama;
    int x;
    int y;
    // int m;
} data_t;

typedef struct Stack
{
    data_t kota[100];
    int m;
} Stack;

void push(Stack *nama_stack, data_t kota)
{
    nama_stack->m++;
    memcpy(&nama_stack->kota[nama_stack->m], &kota, sizeof nama_stack->kota[nama_stack->m]);
}
void pushV2(Stack *nama_stack, char *nama, int x, int y)
{
    nama_stack->m++;
    // int pos=nama_stack->m;
    nama_stack->kota[nama_stack->m].nama = nama;
    nama_stack->kota[nama_stack->m].x = x;
    nama_stack->kota[nama_stack->m].y = y;
}

void pop(Stack *nama_stack, data_t *kota)
{
    // *kota = nama_stack->kota;
    memcpy(&kota, &nama_stack->kota[nama_stack->m], sizeof kota);
    memset(&nama_stack->kota[nama_stack->m], NULL, sizeof nama_stack->kota[nama_stack->m]);
    // memset(nama_stack->kota[nama_stack->m], NULL, sizeof nama_stack->kota[nama_stack->m]);
    // memset(nama_stack->kota[nama_stack->m].nama, NULL, sizeof nama_stack->kota[nama_stack->m].nama);
    // memset(nama_stack->kota[nama_stack->m].x, NULL, sizeof nama_stack->kota[nama_stack->m].x);
    // memset(nama_stack->kota[nama_stack->m].y, NULL, sizeof nama_stack->kota[nama_stack->m].y);
    nama_stack->m--;
}

void popOri(Stack *nama_stack)
{
    memset(&nama_stack->kota[nama_stack->m], NULL, sizeof nama_stack->kota[nama_stack->m]);
    nama_stack->m--;
}

data_t popV2(Stack *nama_stack)
{
    data_t buff;
    // data_t *buff_null = NULL;

    memcpy(&buff, &nama_stack->kota[nama_stack->m], sizeof buff);
    memset(&nama_stack->kota[nama_stack->m], NULL, sizeof nama_stack->kota[nama_stack->m]);
    // memcpy(&nama_stack->kota[nama_stack->m], buff_null, sizeof nama_stack->kota[nama_stack->m]);
    // buff = *buff_null;
    // memset(nama_stack->kota[nama_stack->m].nama, NULL, sizeof nama_stack->kota[nama_stack->m].nama);
    // (data_t*)malloc(n * sizeof(data_t))
    // free(&nama_stack->kota[nama_stack->m]);
    // memset(&nama_stack->kota[nama_stack->m].x, NULL, sizeof nama_stack->kota[nama_stack->m].x);
    // memset(&nama_stack->kota[nama_stack->m].y, NULL, sizeof nama_stack->kota[nama_stack->m].y);
    // return nama_stack->kota[nama_stack->m + 1];
    nama_stack->m--;
    return buff;
}

void show(Stack nama_stack)
{
    // printf("%s", nama_stack.kota->nama);
    // for (int i = 0; i <= nama_stack.m; i++)
    // {
    //     printf("%s\t%d\t%d", nama_stack.kota[i].nama, nama_stack.kota[i].x, nama_stack.kota[i].y);
    //     printf("\n");
    // }
    for (int i = nama_stack.m; i >= 0; i--)
    {
        printf("%s\t%d\t%d", nama_stack.kota[i].nama, nama_stack.kota[i].x, nama_stack.kota[i].y);
        printf("\n");
    }
}

// void pop(data_t *kota)
// {
// }

void initStack(Stack *stack)
{
    stack->m = -1;
}
// data_t kota[100];

void iface_push()
{
}

void iface_pop()
{
}
void iface_show()
{
}

int main()
{
    int iface_ch;
    data_t kota_lagi;
    Stack tumpukan1;
    initStack(&tumpukan1);
    // push(&tumpukan1, );
    pushV2(&tumpukan1, "sby", 12, 23);
    pushV2(&tumpukan1, "mlg", 123, 234);
    pushV2(&tumpukan1, "jbr", 3421, 432);
    pushV2(&tumpukan1, "jkt", 546, 543);
    show(tumpukan1);
    // pop(&tumpukan1, &kota_lagi);
    kota_lagi = popV2(&tumpukan1);
    printf("setelahnya tak pop\n");
    show(tumpukan1);
    printf("ini hasil pop pop an e\n");
    printf("ini nama: %s\n", kota_lagi.nama);

    kota_lagi = popV2(&tumpukan1);
    printf("setelahnya tak pop 2x\n");
    show(tumpukan1);
    printf("ini hasil pop pop an e\n");
    printf("ini nama: %s\n", kota_lagi.nama);

    kota_lagi = popV2(&tumpukan1);
    printf("setelahnya tak pop 3x\n");
    show(tumpukan1);
    printf("ini hasil pop pop an e\n");
    printf("ini nama: %s\n", kota_lagi.nama);

    kota_lagi = popV2(&tumpukan1);
    printf("setelahnya tak pop 4x\n");
    show(tumpukan1);
    printf("ini hasil pop pop an e\n");
    printf("ini nama: %s\n", kota_lagi.nama);

    // printf("tak isi meneh\n");
    // pushV2(&tumpukan1, "push", 87, 678);
    // printf("hasil show\n");
    // show(tumpukan1);

    // printf("%d\n", tumpukan1.m);

    // while (1)
    // {
    //     printf("0. exit\n1. push\n2. pop\n3. tampil");
    //     scanf("%d", &iface_ch);

    //     if (!iface_ch)
    //         break;
    //     switch (iface_ch)
    //     {
    //     case 1:
    //         iface_push();
    //         break;
    //     case 2:
    //         iface_pop();
    //         break;
    //     case 3:
    //         iface_show();
    //         break;
    //     default:
    //         break;
    //     }
    // }

    return 0;

    // for(auto i: ld){
    //     // printf(i.)
    // }
}