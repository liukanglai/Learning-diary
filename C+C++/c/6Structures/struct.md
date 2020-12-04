#

sizeof(tmie);
array 内定义的变量无法返回
(int)(pi*10)%10)
强转是一种截断，舍去。


> attention: when you use the loop to p = p->next, must judge whethe the p is NULL!!!!!!!!!!!!!!!!!!!

# define a struct:
1. 

struct name
{
    int a;
    char b;
    int c[9];
};

struct name time;

2. 

struct name(name can ommit, if you use it only once)
{
    ....
}time;

3. 

typedef struct name NAME;

typedef struct (name)
{
    ...
}NAME;



# call

赋值time={};

.and->运算优先级高


time.data=;

*head->data=;
(*head).data
赋初值使若无，则为0
内存对齐-提高内寻址效率 添加补位或前后统一
支持 time1=time2; // be different from array!!!


# 结构体指针

struct name *pt=&time;
const struct name *head;-----------------------不会改变。

嵌套定义不合法


## 作用 

结构体简化函数接口
# enumeration-枚举

> 有限个int型数据

enum weeks {sun,mon,tue....};  sun=0,mon=1....by default 
若赋值，则后递增1
enum weeks time;

time=sun;  // 赋值！
time1=(enum weeks) (time +1); //为数字需强转

是整型常量，不是字符串


## 作用

增加程序的可读性----定义bool类型，用来定义标志变量

# 共用体
## define
union name
{
    /* data */
};
##
共用同一内存空间，(首地址）只有最后一个起作用。
基本同struct
## 作用
- 节省存储空间
- 构造混合类型


# Linked list:

struct node
{
    int data;
    struct node *next;  // must use struct node * to define, can't use typedef...
};

struct node *head;
struct node *end;
end->next=NULL;


struct node *pt,*prept;    ------pre is the most important.

## 动态内存分配形式

1. 
void *malloc(unsigned int size);
void *calloc(unsigned int num,unsigned size); // 能将初始值为0
(int*)malloc(10*sizeof(int));
void *realloc(void *p,unsigned int size); 
void free(void *p);

返回首地址
