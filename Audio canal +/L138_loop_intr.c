// L138_loop_intr.c
//

#include "L138_LCDK_aic3106_init.h"

interrupt void interrupt4(void)  // interrupt service routine
{
  static int i=0;
  uint16_t negado;
  AIC31_data_type codec_data;

  codec_data.uint = input_sample();
  codec_data.channel[RIGHT] = 0;
  codec_data.channel[LEFT]  = input_left_sample();


  if(i == 1){

      negado = (-1)*input_left_sample();
      codec_data.channel[LEFT]  = negado;
      i = 0;

  }else{

      codec_data.channel[LEFT]  = input_left_sample();
  }

  i++;

  output_sample(codec_data.uint);

  return;
}

int main(void)
{

  L138_initialise_intr(FS_24000_HZ,ADC_GAIN_0DB,DAC_ATTEN_0DB,LCDK_LINE_INPUT);

  while(1);
}
