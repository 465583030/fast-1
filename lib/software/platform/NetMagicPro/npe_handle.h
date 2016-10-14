#ifndef __NPE_WRITE_H__
#define __NPE_WRITE_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <io.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef unsigned char u8;
typedef unsigned long long u64;
struct npe_debug_user_param
{
    int type;
    unsigned long argv1;
    unsigned long argv2;
    unsigned long argv3;
    unsigned long argv4;
    char   filename[100];
};

struct npe_debug_user_result
{
    struct npe_debug_user_param gdp;
    int result;
    int data_len;
    int has_data;
    unsigned char info[200];//��ʾ��Ϣ
    unsigned char data[2048];//�������ݣ��Ϊ16k(16384)
};


/*�豸����ʹ�õ����ݽṹ*/
struct npe_buf_user_param //�����ܴ�С��Ҫ����3000,��Ϊ�ں���ʹ�õ����ռ��С��3000
{
	int cpu;
	int pad;
	struct npe_debug_user_result gdr;
}__attribute__((packed));

void  npe_write(unsigned long long offset,unsigned long long value);
u64 npe_read(unsigned long long offset);

#endif
