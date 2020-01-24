/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 11:11:06 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 14:42:39 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "stm32f30x_it.h"
#include "stm32f30x.h"
#include "stm32f30x_conf.h"
#include "drone.h"
#include <stdio.h>

int _write(int32_t file, char* ptr, int32_t len)
{
	(void)file;
	int i=0;
	for(i=0 ; i<len ; i++)
		ITM_SendChar((*ptr++));
	return len;

	return -1;
}

int main(void)
{
	TIM6_enable();
	RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
	GPIOE_enable();
	GPIOE_full_init();
	ITM_init();

	_write(0, "bonjour\n", 8);
	_write(0, "Hello World!\n", 13);

	while (1)
	{
		GPIOE->BSRR = (1 << 15);
		delay(10000);
		GPIOE->BSRR = (1 << 14);
		GPIOE->BSRR = (1 << (15 + 16));
		delay(10000);
		GPIOE->BSRR = (1 << 13);
		GPIOE->BSRR = (1 << (14 + 16));
		delay(10000);
		GPIOE->BSRR = (1 << 12);
		GPIOE->BSRR = (1 << (13 + 16));
		delay(10000);
		GPIOE->BSRR = (1 << 11);
		GPIOE->BSRR = (1 << (12 + 16));
		delay(10000);
		GPIOE->BSRR = (1 << 10);
		GPIOE->BSRR = (1 << (11 + 16));
		delay(10000);
		GPIOE->BSRR = (1 << 9);
		GPIOE->BSRR = (1 << (10 + 16));
		delay(10000);
		GPIOE->BSRR = (1 << 8);
		GPIOE->BSRR = (1 << (9 + 16));
		delay(10000);
		GPIOE->BSRR = (1 << (8 + 16));
	}
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{ 
	(void)file;
	(void)line;
	/* User can add his own implementation to report the file name and line number,
ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif