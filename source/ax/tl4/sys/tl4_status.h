/* This file protected by faith_base_00 license
 * No part of this file could be copyed or changed without Develop Project agreement
 * No part of this file could be used or viewed without Develop Project agreement
 */

#ifndef _AX_TL4_STATUS_H_
#define _AX_TL4_STATUS_H_

namespace ax
{
  namespace tl4
  {
    enum STAT_CON
    {
      TL4_CON_PRE_IP_RESOLV, // ������� � ������ ip ����������
      TL4_CON_IP_RESOLV,  // ����� ������ ip, ������ ��� ������� ���� �� �����
      TL4_CON_PRECONNECTING, // ������� � ���������� ����������� � �������
      TL4_CON_CONNECTING, // ������ �������� �����������
      TL4_CON_RECONNECTING, // ������ ���������, �������� ��� ���

      TL4_CON_CONNECTED, // ��� ������ ������������ ����������
      TL4_CON_IDLE, // ���������� �����������
      TL4_CON_TRANSFER, // ��� ��������� ������ �������� ������ �������� ������������

      TL4_CON_CLOSING, // ������� � �������� �������, ������ ������ ������ ��������
      TL4_CON_DISCONNECTED, // ��� ������ ���������� ����������
      TL4_CON_TRANSFERERROR, // ���� ������������ ������ ��� ��������
      TL4_CON_DENIED, // ������ ������� �� ��� ����� �� ��������
      TL4_CON_CANTRESOLVE, // �� ������ ��������� ip
      TL4_CON_TIMEOUT, // ���� ������� ����� �� �������
      TL4_CON_REFUSED, // ���� �������� ���������� ��� ��������� ������

      TL4_CON_CLOSED, // ���������� �������, ��������� ������������ ��������
      TL4_CON_FREE // ������ ������ ��������
    };
    enum STAT_PORT
    {
      TL4_PORT_PREOPENNING, // ������� � �������� ����� ����������� � �������
      TL4_PORT_OPENNING, // ������ �������� ������� ����

      TL4_PORT_OPENED, // ��� ������ ��������
      TL4_PORT_IDLE, // ��� ��� ������

      TL4_PORT_CLOSING,
      TL4_PORT_CANTBIND, // ��� �����
      TL4_PORT_CANTLISTEN, // ��)
      TL4_PORT_CLOSED, // ���� ������, ��������� ������������ ��������
      TL4_PORT_FREE
    };
  };
};

#endif