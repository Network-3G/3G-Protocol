typedef enum L3_event
{
    L3_event_msgRcvd = 2,
    L3_event_dataToSend = 4,
    L3_event_dataSendCnf = 5,
    L3_event_recfgSrcIdCnf = 6,

    L3_event_dataConDone = 7,
    L3_event_dataDisDone = 8,

    // state IDLE
    ReqCON_Rcvd = 15,

    // state CON
    SetCON_Accept_Rcvd = 9,
    SetCON_Reject_Rcvd = 10,
    CplCON_Rcvd = 11,

    // state DIS
    SetDis_Rcvd = 12,
    CplDis_Rcvd = 13,

    //all state
    OTHERPDU = 14

} L3_event_e;

void L3_event_setEventFlag(L3_event_e event);
void L3_event_clearEventFlag(L3_event_e event);
void L3_event_clearAllEventFlag(void);
int L3_event_checkEventFlag(L3_event_e event);