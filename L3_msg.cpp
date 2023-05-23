#include "mbed.h"
#include "L3_msg.h"

int arqMsg_checkIfCONPDU(uint8_t* msg)
{
    return (msg[ARQMSG_OFFSET_TYPE] == ARQMSG_TYPE_DATA);
}

int arqMsg_checkIfAck(uint8_t* msg)
{
    return (msg[ARQMSG_OFFSET_TYPE] == ARQMSG_TYPE_ACK);
}

uint8_t Msg_encodeCONPDU(uint8_t* msg_CONPDU, int rsc, int acp )  //uint8_t seq)
{
    msg_CONPDU[MSG_OFFSET_TYPE] = MSG_TYPE_CON;
    msg_CONPDU[MSG_OFFSET_RSC] = rsc;
    msg_CONPDU[MSG_OFFSET_Acp] = acp;
    // secp에 따라 송신자 수신자 ID를 추가해야할 수도 있음 event m

    //return ARQMSG_ACKSIZE;
}

uint8_t Msg_encodeDISPDU(uint8_t* msg_DISPDU, int rsc, int acp, int , int )
{
    msg_DISPDU[MSG_OFFSET_TYPE] = MSG_TYPE_DIS;
    msg_DISPDU[MSG_OFFSET_RSC] = rsc;
    msg_DISPDU[MSG_OFFSET_Acp] = acp;
    msg_DISPDU[MSG_MO] = 8;
    msg_DISPDU[MSG_MI] = 8;

    //return ARQMSG_ACKSIZE;
}

//ä�� PDU
uint8_t Msg_encodeChat(uint8_t* msg_data, uint8_t* data, int rsc, int acp, int len)
{
    msg_data[MSG_OFFSET_TYPE] = MSG_TYPE_CHAT;
    msg_data[MSG_OFFSET_RSC] = rsc;
    msg_data[MSG_OFFSET_Acp] = acp;
   
    //�� �ؿ� ��������
    memcpy(&msg_data[ARQMSG_OFFSET_DATA], data, len * sizeof(uint8_t));     //Ű����� �Է¹��� �� �Ű���

    return len + ARQMSG_OFFSET_DATA;    //��Ȳ ���� �ٸ���
}


/*uint8_t arqMsg_getSeq(uint8_t* msg)
{
    return msg[ARQMSG_OFFSET_SEQ];
}
*/

uint8_t* arqMsg_getWord(uint8_t* msg)
{
    return &msg[ARQMSG_OFFSET_DATA];
}