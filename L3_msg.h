#include "mbed.h"

#define MSG_MO   3
#define MSG_MI   4	

#define MSG_TYPE_CHAT   0
#define MSG_TYPE_CON    1		//type header
#define MSG_TYPE_DIS    2

#define MSG_RSC_Req		0		//RSC header
#define MSG_RSC_Set		1
#define MSG_RSC_Cpl		2

#define MSG_ACP_ACCEPT  1		//Accept header
#define MSG_ACP_REJECT  0

#define MSG_OFFSET_TYPE  0		//PDU�迭 �� Ÿ���� ��ġ
#define MSG_OFFSET_RSC   1
#define MSG_OFFSET_Acp   2

//������� ����

//#define ARQMSG_ACKSIZE      3

#define ARQMSG_MAXDATASIZE  26
#define ARQMSSG_MAX_SEQNUM  1024


int arqMsg_checkIfData(uint8_t* msg);
int arqMsg_checkIfAck(uint8_t* msg);
uint8_t arqMsg_encodeAck(uint8_t* msg_ack, uint8_t seq);
uint8_t arqMsg_encodeData(uint8_t* msg_data, uint8_t* data, int seq, int len);
uint8_t arqMsg_getSeq(uint8_t* msg);
uint8_t* arqMsg_getWord(uint8_t* msg);