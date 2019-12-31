#pragma once
#include <stdint.h>//uint16_t
#include <string>//std::string
#include <iostream>//cout
#include <memory.h>//memset memcpy
class HMessage
{
    int m_iCurPos;//0
   unsigned char m_szBuffer[1000];//[10][00] [01] [00]  [04][00] [dubo]
    int m_iCount;

   public:
    int m_iClient;
    HMessage()
    {
       m_iCurPos = 0;
       m_iCount = 0;
       memset(m_szBuffer,0,1000);
    }
static int GetMsgLen(unsigned char * szBuffer,int iLen)
{
    if(iLen<2 )
        return 0;
     uint16_t wResult=0;

     wResult = *(szBuffer)  <<8;

     wResult = wResult| ( *(szBuffer +1) & 0xff);

    return wResult;
}


static int GetMsgMainProtcol(unsigned char * szBuffer,int iLen)
{
    if(iLen<2 )
        return 0;
     uint16_t wResult=0;

     wResult = *(szBuffer+2)  <<8;

     wResult = wResult| ( *(szBuffer +3) & 0xff);


    return wResult;
}
static int GetMsgSubProtcol(unsigned char * szBuffer,int iLen)
{
    if(iLen<2 )
        return 0;
     uint16_t wResult=0;

     wResult = *(szBuffer+4)  <<8;

     wResult = wResult| ( *(szBuffer +5) & 0xff);


    return wResult;
}


unsigned char * GetBuffer()
{
   //*( (uint16_t *)  m_szBuffer ) = m_iCurPos;
    m_iCount = m_iCurPos;
    m_iCurPos = 0;

    PutUShort(m_iCount);

    m_iCurPos = m_iCount;
    return m_szBuffer;
}

void Init(unsigned char *pBuffer,int iSize)
{
   memcpy( m_szBuffer,pBuffer,iSize);
    m_iCount = iSize;
    m_iCurPos = 0;
}


   int GetSize()
   {
       m_iCount = m_iCurPos;
       return m_iCount;
   }

void AddData(int iSize)
{
    m_iCurPos += iSize;
  //  m_iCount  += iSize;
}
//#define uint8_t unsigned char
//#define int8_t  char
//#define int64_t  long   //long long
void putChar(uint8_t cData)
{
      *(m_szBuffer+m_iCurPos)   = cData ;
       AddData(sizeof(uint8_t));
}

//习惯int 转　大端　string 转　utf-8
   void PutUShort(uint16_t wData)
    {
     * (m_szBuffer+m_iCurPos)   = wData>>8 & 0xff ;
     * (m_szBuffer+m_iCurPos+1) = wData & 0xff;
     AddData(sizeof(uint16_t));
    }

   void PutUInt(uint32_t wData)
   {
       * (m_szBuffer+m_iCurPos)   = wData>>24 & 0xff ;
       * (m_szBuffer+m_iCurPos+1)   = wData>>16  & 0xff ;
       * (m_szBuffer+m_iCurPos+2)   = wData>>8 & 0xff ;
       * (m_szBuffer+m_iCurPos+3) = wData & 0xff;
       AddData(sizeof(uint32_t));
   }
      void PutString(std::string strData)
      {
         PutUShort(strData.length());

         memcpy( m_szBuffer+m_iCurPos,strData.c_str(),strData.length() );


         AddData(strData.length());


      }
    bool CheckHaveEnoughData(int iSize)
    {
        if(m_iCurPos+iSize <= m_iCount)
            return true;
        return false;
    }
    bool GetChar(uint8_t & wData)
    {
       if(false== CheckHaveEnoughData(1) )
           return false;
        uint16_t wResult=0;

        wData = *(m_szBuffer+m_iCurPos) ;
        m_iCurPos+=sizeof(uint8_t);
        return true;
    }
    bool GetUShort(uint16_t & wData)
    {
       if(false== CheckHaveEnoughData(2) )
           return false;
        uint16_t wResult=0;

        wResult = *(m_szBuffer+m_iCurPos)  <<8;

        wResult = wResult| ( *(m_szBuffer+m_iCurPos +1) & 0xff);
     //  *((unsigned char *)&wResult  + 0) =(m_szBuffer+m_iCurPos));
//        *( (unsigned char *)&wResult  + 1) =(m_szBuffer+m_iCurPos));
        m_iCurPos+=sizeof(uint16_t);
        wData = wResult;
        return true;
    }
    bool GetUInt(uint32_t & wData)
    {
       if(false== CheckHaveEnoughData(sizeof(uint32_t)) )
           return false;
        uint32_t wResult=0;

         wResult |= *(m_szBuffer+m_iCurPos)  <<24;
          wResult |= *(m_szBuffer+m_iCurPos+1)  <<16;
        wResult |= *(m_szBuffer+m_iCurPos+2)  <<8;

        wResult = wResult| ( *(m_szBuffer+m_iCurPos +3) & 0xff);
     //  *((unsigned char *)&wResult  + 0) =(m_szBuffer+m_iCurPos));
//        *( (unsigned char *)&wResult  + 1) =(m_szBuffer+m_iCurPos));
        m_iCurPos+=sizeof(uint32_t);
        wData = wResult;
        return true;
    }
   bool  GetString(std::string & strData)
    {
       if(false== CheckHaveEnoughData(2) )
           return false;

       uint16_t wLen = 0;

      bool bCheck = GetUShort(wLen);

      if(false == bCheck )
          return false;

      if(false== CheckHaveEnoughData(wLen) )
           return false;

       char szBuffer[1000]={};
       memcpy(szBuffer,m_szBuffer+m_iCurPos,wLen);
       szBuffer[wLen]=0;
       strData=szBuffer;


       m_iCurPos+=wLen;

       return true;
    }

};