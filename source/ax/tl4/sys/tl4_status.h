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
      TL4_CON_PRE_IP_RESOLV, // задание о поиске ip поставлено
      TL4_CON_IP_RESOLV,  // нужно узнать ip, потому что задание было по имени
      TL4_CON_PRECONNECTING, // задание о соединении поставленно в очередь
      TL4_CON_CONNECTING, // клиент пытается соедениться
      TL4_CON_RECONNECTING, // клиент обломался, пытается еще раз

      TL4_CON_CONNECTED, // как только установилось соединение
      TL4_CON_IDLE, // соединение простаивает
      TL4_CON_TRANSFER, // при последнем сеансе передачи буфера остались заполненными

      TL4_CON_CLOSING, // задание о закрытии принято, нельзя делать другие действия
      TL4_CON_DISCONNECTED, // как только прервалось соединение
      TL4_CON_TRANSFERERROR, // если обнаружились ошибки при передаче
      TL4_CON_DENIED, // нижний уровень не дал права на операцию
      TL4_CON_CANTRESOLVE, // не смогли вычислить ip
      TL4_CON_TIMEOUT, // хост слишком долго не отвечал
      TL4_CON_REFUSED, // хост отклонил соединение или системная ошибка

      TL4_CON_CLOSED, // соединение закрыто, ожидается освобождение ресурсов
      TL4_CON_FREE // ячейка памяти свободна
    };
    enum STAT_PORT
    {
      TL4_PORT_PREOPENNING, // задание о открытии порта поставленно в очередь
      TL4_PORT_OPENNING, // сервер пытается открыть порт

      TL4_PORT_OPENED, // как только открылся
      TL4_PORT_IDLE, // все еще открыт

      TL4_PORT_CLOSING,
      TL4_PORT_CANTBIND, // уже занят
      TL4_PORT_CANTLISTEN, // хз)
      TL4_PORT_CLOSED, // порт закрыт, ожидается освобождение ресурсов
      TL4_PORT_FREE
    };
  };
};

#endif