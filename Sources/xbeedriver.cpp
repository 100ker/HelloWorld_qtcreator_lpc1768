#include <stdio.h>

#include "xbeedriver.h"
#include "messengerinterfacebase.h"
//#include "CApplication.h"
//#include "CRS232.h"


XbeeDriver::XbeeDriver() :
    m_messenger_interface(NULL)
{
}

XbeeDriver::~XbeeDriver()
{
}


void XbeeDriver::setMessengerInterface(MessengerInterfaceBase *messenger_iface)
{
    m_messenger_interface = messenger_iface;
}

// ________________________________________________________________
void XbeeDriver::readyBytes(unsigned char *buff_data, unsigned char buff_size, unsigned short source_id)
{
    //qDebug() << "XbeeDriver: a valid buffer of" << buff_size << "data was received from source" << source_id;
    for (int i=0; i<buff_size; i++) {
        //qDebug("  > 0x%x", buff_data[i]);
    }
    if (m_messenger_interface) m_messenger_interface->decode(buff_data, buff_size, source_id);
}

// ________________________________________________________________
void XbeeDriver::write(unsigned char *buff_data, unsigned char buff_size)
{
    //qDebug() << "XbeeDriver::XBEE ask to write data";
    //m_application->m_RS232_xbee->write((const char*)buff_data, buff_size);
    for (unsigned int i=0; i<buff_size; i++)
    {
       //qDebug() << buff_data[i];
    }
}

// ________________________________________________________________
void XbeeDriver::delay_us(unsigned long delay)
{
    //qDebug() << "XbeeDriver:" << "Xbee driver request a delay of " << delay << "usec";
    //QThread::usleep(delay);
}
