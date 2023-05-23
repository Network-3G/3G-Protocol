#include "mbed.h"
#include "L3_msg.h"
#include "mbed.h"
#include "L3_msg.h"
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

int Msg_checkIfReqCON(uint8_t* msg) // event c
{
    return ((msg[MSG_OFFSET_TYPE] == MSG_TYPE_CON)&&(msg[MSG_OFFSET_RSC] == MSG_RSC_Req)&&(msg[MSG_OFFSET_Acp] == MSG_ACP_ACCEPT));
}

int Msg_checkIfSetCON_Accept_Rcvd(uint8_t* msg) // event c
{
    return ((msg[MSG_OFFSET_TYPE] == MSG_TYPE_CON)&&(msg[MSG_OFFSET_RSC] == MSG_RSC_Set)&&(msg[MSG_OFFSET_Acp] == MSG_ACP_ACCEPT));
}

int Msg_checkIfSetCON_Reject_Rcvd(uint8_t* msg) // event d
{
    return ((msg[MSG_OFFSET_TYPE] == MSG_TYPE_CON)&&(msg[MSG_OFFSET_RSC] == MSG_RSC_Set)&&(msg[MSG_OFFSET_Acp] == MSG_ACP_REJECT));
}

int Msg_checkIfCplCON_Rcvd(uint8_t* msg) // event e
{
    return ((msg[MSG_OFFSET_TYPE] == MSG_TYPE_CON)&&(msg[MSG_OFFSET_RSC] == MSG_RSC_Cpl)&&(msg[MSG_OFFSET_Acp] == MSG_ACP_ACCEPT));
}

int Msg_checkIfSetDIS_Rcvd(uint8_t* msg) // event k
{
    return ((msg[MSG_OFFSET_TYPE] == MSG_TYPE_DIS)&&(msg[MSG_OFFSET_RSC] == MSG_RSC_Set)&&(msg[MSG_OFFSET_Acp] == MSG_ACP_ACCEPT));
}
int Msg_checkIfCplDIS_Rcvd(uint8_t* msg) // event l
{
    return ((msg[MSG_OFFSET_TYPE] == MSG_TYPE_DIS)&&(msg[MSG_OFFSET_RSC] == MSG_RSC_Cpl)&&(msg[MSG_OFFSET_Acp] == MSG_ACP_ACCEPT));
}

uint8_t Msg_encodeCONPDU(uint8_t* msg_CONPDU, int rsc, int acp )  
{
    msg_CONPDU[MSG_OFFSET_TYPE] = MSG_TYPE_CON;
    msg_CONPDU[MSG_OFFSET_RSC] = rsc;

    msg_DISPDU[MSG_MO] = 8;
    msg_DISPDU[MSG_MI] = 10;
    // secp에 따라 송신자 수신자 ID를 추가해야할 수도 있음 event m

}

uint8_t Msg_encodeDISPDU(uint8_t* msg_DISPDU, int rsc, int acp, int , int )
{
    msg_DISPDU[MSG_OFFSET_TYPE] = MSG_TYPE_DIS;
    msg_DISPDU[MSG_OFFSET_RSC] = rsc;
    msg_DISPDU[MSG_OFFSET_Acp] = acp;
    msg_DISPDU[MSG_MO] = 8;
    msg_DISPDU[MSG_MI] = 10;


}

uint8_t Msg_encodeCHAT(uint8_t* msg_data, uint8_t* data, int rsc, int acp, int len)
{
    msg_data[MSG_OFFSET_TYPE] = MSG_TYPE_CHAT;
    msg_data[MSG_OFFSET_RSC] = rsc;
    msg_data[MSG_OFFSET_Acp] = acp;
   
    memcpy(&msg_data[ARQMSG_OFFSET_DATA], data, len * sizeof(uint8_t));

    return len + ARQMSG_OFFSET_DATA;    
}


uint8_t* arqMsg_getWord(uint8_t* msg)
{
    return &msg[ARQMSG_OFFSET_DATA];
}