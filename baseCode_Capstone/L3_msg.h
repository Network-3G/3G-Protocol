#include "mbed.h"

#define L3_MSG_TYPE_ACK 0
#define L3_MSG_TYPE_DATA 1
#define L3_MSG_TYPE_DATA_CONT 2

#define L3_MSG_OFFSET_TYPE 0
#define L3_MSG_OFFSET_SEQ 1
#define L3_MSG_OFFSET_DATA 2

#define L3_MSG_ACKSIZE 3

#define L3_MSG_MAXDATASIZE 26
#define L3_MSSG_MAX_SEQNUM 1024

int L3_msg_checkIfData(uint8_t *msg);
int L3_msg_checkIfAck(uint8_t *msg);
int L3_msg_checkIfEndData(uint8_t *msg);
uint8_t L3_msg_encodeAck(uint8_t *msg_ack, uint8_t seq);
uint8_t L3_msg_encodeData(uint8_t *msg_data, uint8_t *data, int seq, int len, uint8_t);
uint8_t L3_msg_getSeq(uint8_t *msg);
uint8_t *L3_msg_getWord(uint8_t *msg);