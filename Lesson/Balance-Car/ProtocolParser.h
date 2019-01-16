#ifndef   _PROTOCOLPARSER_H_
#define   _PROTOCOLPARSER_H_
#include "Arduino.h"
#include "Protocol.h"
#include "SmartCar.h"
#include <stdint.h>

#define BUFFER_SIZE 100

class ProtocolParser
{
public:
    ProtocolParser(byte header = PROTOCOL_START_CODE, byte end = PROTOCOL_END_CODE);
    ~ProtocolParser();
    bool RecevData(byte *data, size_t len);
    bool RecevData(void);
    bool ParserPackage(byte *data = NULL);
    E_TYPE GetRobotType(void);
    uint8_t GetRobotAddr(void);
    E_CONTOROL_FUNC GetRobotControlFun(void);
    E_SMARTCAR_CONTROL_MODE GetControlMode(void);
    int GetRobotSpeed(void);
    int GetRobotDegree(void);
    E_SMARTCAR_STATUS GetRobotDirection(void);
    bool SendPackage(ST_PROTOCOL *send_dat,int len);
	  byte * GetPianoSing(void);
    uint8_t GetProtocolDataLength(void);
private:
    byte buffer[BUFFER_SIZE];
    byte m_StartCode, m_EndCode;
    ST_PROTOCOL *recv;
    uint8_t protocol_data_len;
    bool m_recv_flag, m_send_success;   // recevive flag
    byte *m_pHeader;                    // protocol header
    uint8_t m_PackageLength;            // recevie package length
    uint16_t m_CheckSum;
    uint8_t m_RecvDataIndex;            // get recevie data index
    char GetHeader(size_t index);
    uint8_t GetPackageLength(void);
    uint16_t GetCheckSum(void);             // get package check sum
};

#endif // _PROTOCOLPARSER_H_
