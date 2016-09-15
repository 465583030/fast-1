#ifndef _AUX_TABLE_H_
#define _AUX_TABLE_H_
//#include"openflow.h"
#include "public.h"
#include <libnet.h>



//#define XTR_DST_MAC "00:0D:29:B9:00:D6"		//���ݺ��������Ӷ˿ڵ�MAC��ַʵ�������д

//#define XTR_SRC_MAC "00:0D:29:B9:8B:D6"		//���ݺ��������Ӷ˿ڵ�MAC��ַʵ�������д


#define EN_LISP_N 0
#define EN_LISP_Y 1

#define DE_LISP_N 0
#define DE_LISP_Y 1

#define RE_MAC_N 0
#define RE_MAC_Y 1

#define FORWARD_N 0
#define FORWARD_Y 1

 
/*��ӱ�Ե���������ı���*/
int add_host_table(struct _host_table host_table[],int port,char* port_ip);

/*�ж��Ƿ�Ϊ��Ե����������*/
int is_host_ip(struct _host_table host_table[],struct libnet_in6_addr dst_ip);


/*
 * ʵ������
 * SUBID-PORT ��
 */
/*���SUBID-PORT����*/
int add_subid_port_table(struct _subid_port_table subid_port_table[],int port,char* eid);

/*��SUBID-PORT��ͨ��Ŀ��SUBID����OUT-PORT*/
int get_port_by_subid(struct _subid_port_table subid_port_table[],struct libnet_in6_addr dst_eid);


/*
 * ʵ������
 * SUBID-RLOC ��
 */

/*���SUBID-RLOC����*/
int add_subid_rloc_table(struct _subid_rloc_table subid_rloc_table[],u64 subid,char* rloc);

/*��SUBID-RLOC��ͨ��Ŀ��SUBID����Ŀ��RLOC*/
u8* get_rloc_by_subid(struct _subid_rloc_table subid_rloc_table[],struct libnet_in6_addr dst_eid);


/*
 * �����
 * RLOC-PORT(PORT-RLOC)�������
 */
int add_rloc_port_table(struct _rloc_port_table rloc_port_table[],int port,struct libnet_in6_addr rloc,int add_rloc_port_table);


/*
 * ���������
 * ͨ��SRC-RLOC����OUT-PORT���
 */

int get_port_by_rloc(struct _rloc_port_table rloc_port_table[],struct libnet_in6_addr rloc);

/*
 * ���������
 * ͨ��IN-PORT����DST-RLOC��װ
 */

u8* get_rloc_by_port(struct _rloc_port_table rloc_port_table[],int port);

/*
 * ��װ������Ϣ
 * MAC�����SRC_MAC
 * ND�����Ŀ��MAC
 */


/*
 * ���mac�����
 * ������������ֱ�Ϊ�Ƿ��·����������·������·������IPv6��ַ��
 */
void add_mac_table(struct _mac_table mac_table[],int port,u8 *mac,int is_router,struct libnet_in6_addr * router_ip);

/*���ND�����*/
void add_nd_table(struct _nd_table nd_table[],struct libnet_in6_addr ip,u8 *dst_mac);


/*��ND����ң�ͨ��IP��ַ����DST_MAC*/
u8 *get_dst_mac_by_ip(struct _nd_table nd_table[],struct libnet_in6_addr *ip);


#endif
