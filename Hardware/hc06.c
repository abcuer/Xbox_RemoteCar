#include "headfile.h"

void HC06Init(void)
{
	NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
	NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
}

void UART_0_INST_IRQHandler(void)
{
    if(DL_UART_getPendingInterrupt(UART_0_INST) == DL_UART_IIDX_RX)
    {
        uint8_t rx_data = DL_UART_Main_receiveData(UART_0_INST);
		switch(rx_data)
		{
			case 0x00: 		CarStop(); 			break;
			/* 前 */
			case 0x01:		CarForward();		break;
			/* 后 */
			case 0x05:		CarBackward();		break;
			/* 右 */
			case 0x03:		CarTurnRight();	 	break;
			/* 左 */	
			case 0x07:		CarTurnLeft();		break;
			/* 左前方 */
			case 0x08:		CarLeftForward();	break;
			/* 右前方 */
			case 0x02:		CarRightForward();	break;
			/* 左后方 */
			case 0x06:		CarLeftBackward();	break;
			/* 右后方 */
			case 0x04:		CarRightBackward();	break;
			/* 其他 */
			default:		CarStop();			break;
		}
    }
}

