/*
** value_setter.c for github in /home/lombar_e/github/bmp_loader/src
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue Jan 10 14:45:33 2017 Thomas Lombard
** Last update Tue Jan 10 14:48:05 2017 Thomas Lombard
*/

#include "bmp_core.h"

int	fill_16_byte(int *index, t_bitmap *bitmap,
		     t_bit_stream *stream)
{
  uint32_t	color;

  color = *((uint8_t *)stream->inc);
  bitmap->bitmap[*index].r = ((color >> 10) & 0x1f) << 3;
  bitmap->bitmap[*index].g = ((color >> 5) & 0x1f) << 3;
  bitmap->bitmap[*index].b = (color & 0x1f) << 3;
  bitmap->bitmap[*index].a = 255;
  ++*index;
  stream->inc += 2;
  return (0);
}

int	fill_24_byte(int *index, t_bitmap *bitmap,
		     t_bit_stream *stream)
{
  uint32_t	color;

  color = *((uint32_t *)stream->inc);
  bitmap->bitmap[*index].r = (color >> 16) & 0xff;
  bitmap->bitmap[*index].g = (color >> 8) & 0xff;
  bitmap->bitmap[*index].b = color & 0xff;
  bitmap->bitmap[*index].a = 255;
  ++*index;
  stream->inc += 3;
  return (0);
}

int	fill_32_byte(int *index, t_bitmap *bitmap,
		     t_bit_stream *stream)
{
  uint32_t	color;

  color = *((uint8_t *)stream->inc);
  bitmap->bitmap[*index].r = (color >> 16) & 0xff;
  bitmap->bitmap[*index].g = (color >> 8) & 0xff;
  bitmap->bitmap[*index].b = color & 0xff;
  bitmap->bitmap[*index].a = color >> 24;
  ++*index;
  stream->inc += 4;
  return (0);
}
