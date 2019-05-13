#include "led.h"
#include "delay.h"
#include "sys.h"
#include "cJSON.h"
#include "usart.h"
#include "ADC.h"

//cjson��ֲ��ַ:http://blog.csdn.net/yannanxiu/article/details/52712078

int main(void)
{
    u8 t;
    u8 len;
    //u16 times=0;
    u16 Adcx;
    float temp;

    SystemInit();//ϵͳʱ�ӵȳ�ʼ��
    delay_init(72);	     //��ʱ��ʼ��
    NVIC_Configuration();//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
    uart_init(9600);//���ڳ�ʼ��Ϊ960
    Adc_Init();
    LED_Init();
    printf("\n�����͵���ϢΪ:\n");

    while(1) {
        printf("Version: %s\n", cJSON_Version());
        if(USART_RX_STA&0x80) {
            len=USART_RX_STA&0x3f;//�õ��˴ν��յ������ݳ���
            printf("\n�����͵���ϢΪ:\n");
            for(t=0; t<len; t++) {
                USART1->DR=USART_RX_BUF[t];
                while((USART1->SR&0X40)==0);//�ȴ����ͽ���
            }
            printf("\n\n");//���뻻��
            USART_RX_STA=0;
        } else {

            Adcx = Get_Adc(ADC_Channel_0);
            temp=(100.0-(float)Adcx*(100.0/4096));
            printf("\n\n");
            printf("%.1f%%\n\n",temp);
            printf("\n\n");
            delay_ms(500);
        }
    }

}

