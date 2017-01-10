/*
** libbmp.h for github in /home/lombar_e/github/bmp_loader/include
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue Jan 10 14:59:39 2017 Thomas Lombard
** Last update Tue Jan 10 15:38:34 2017 Thomas Lombard
*/

#ifndef LIBBMP_H_
# define LIBBMP_H_

#include <stdint.h>
#include <SFML/System.h>

typedef struct	s_rgba
{
  uint8_t	r;
  uint8_t	g;
  uint8_t	b;
  uint8_t	a;
}		t_rgba;

typedef struct	s_bitmap
{
  t_rgba	*bitmap;
  int32_t	width;
  int32_t	height;
}		t_bitmap;

typedef struct	s_my_framebuffer
{
  sfUint8	*buff;
  int		width;
  int		height;
}		t_my_framebuffer;

t_bitmap	*load_bmp_file(char *filename);

#endif /* ! LIBBMP_H_ */
