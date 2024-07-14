// L138_loop_intr.c
//

#include "L138_LCDK_aic3106_init.h"

interrupt void interrupt4(void)  // interrupt service routine
{
  AIC31_data_type codec_data;

  codec_data.uint = input_sample();
  codec_data.channel[LEFT] = input_right_sample();
  codec_data.channel[RIGHT] = input_left_sample();

  output_sample(codec_data.uint);
  return;
}

int main(void)
{
  L138_initialise_intr(FS_32000_HZ,ADC_GAIN_0DB,DAC_ATTEN_0DB,LCDK_LINE_INPUT);
  while(1);
}
