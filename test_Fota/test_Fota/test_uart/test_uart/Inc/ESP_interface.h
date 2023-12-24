/****************************************************************/
/* Author    : Ahmed Khaled                                      */
/* Date      : 28 SEP 2020                                      */
/* Version   : V01                                              */
/****************************************************************/
#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H

void ESP8266_voidInit (void);
void ESP8266_voidConnectToWiFi ( u8 * SSID , u8 * Password );

void ESP8266_voidConnectToServerTcp ( u8 * Copy_u8Domain , u8 * Copy_u8Port );

u8 ESP8266_u8ReceiveHttpReq (u8 *Copy_u8Server, u8 *Copy_u8FilePath, u8 *Copy_u8Length) ;

void ESP8266_MUSART1CallBackFunction(void);

static u8 voidEspValidateCmd (void);

void ESP8266_voidClearBuffer ( void );

void ESP8266_voidReceiveRecord (void);

#define MAX_LINES	400
#define MAX_CHARS	45

#endif
