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
			case 0x00:
				CarStop();
				break;
			case 0x01:	//前
				CarForward();
				break;	
			case 0x05:	//后
				CarBackward();
				break;
			case 0x03:	//右
				CarTurnRight();
				break;
			case 0x07:	//左
				CarTurnLeft();
				break;
			case 0x08:	//左前方
				CarLeftForward();
				break;
			case 0x02:	//右前方
				CarRightForward();
				break;
			case 0x06:	//左后方
				CarLeftBackward();
				break;
			case 0x04:	//右后方
				CarRightBackward();
				break;
			default:
				CarStop();
				break;
		}
    }
}

