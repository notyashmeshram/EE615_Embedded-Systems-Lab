#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"

int main(void)
{
    SYSCTL_RCGC2_R |= 0x00000020;       /* enable clock to GPIOF */
    GPIO_PORTF_LOCK_R = 0x4C4F434B;     /* unlock commit register */
    GPIO_PORTF_CR_R = 0x1F;             /* make PORTF0 configurable */
    GPIO_PORTF_DEN_R = 0x1E;            /* set PORTF pins 4 pin */
    GPIO_PORTF_DIR_R = 0x0E;            /* set PORTF4 pin as input user switch pin */
    GPIO_PORTF_PUR_R = 0x10;            /* PORTF4 is pulled up */

    register long int x = 0;
        while(1)
        {
            GPIO_PORTF_DATA_R = 0x12;
            x = 0;
            while(x<900000)
            {
                x++;
            }
            GPIO_PORTF_DATA_R = 0x1A;
            x = 0;
            while(x<900000)
            {
                x++;
            }
            GPIO_PORTF_DATA_R = 0x18;
            x = 0;
            while(x<900000)
            {
                x++;
            }
            GPIO_PORTF_DATA_R = 0x14;
            x = 0;
            while(x<900000)
            {
                x++;
            }
            GPIO_PORTF_DATA_R = 0x16;
            x = 0;
            while(x<900000)
            {
                x++;
            }
        }

}
