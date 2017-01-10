/*
** main.c for github in /home/lombar_e/github/bmp_loader
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue Jan 10 14:48:46 2017 Thomas Lombard
** Last update Tue Jan 10 15:45:16 2017 Thomas Lombard
*/

#include <stdlib.h>
#include "libbmp.h"

int			main(__attribute__((unused)) int ac, char **av)
{
  t_my_framebuffer	*framebuff;

  framebuff = (t_my_framebuffer *)load_bmp_file(av[1]);
  if (framebuff)
    {
      free(framebuff->buff);
      free(framebuff);
    }
  return 0;
}
