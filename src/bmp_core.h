/*
** lib_bmp.h for wolf3d in /home/lombar_e/rendu/Infographie/wolf3d
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue Jan 03 10:02:50 2017 Thomas Lombard
** Last update Tue Jan 10 15:35:55 2017 Thomas Lombard
*/

#ifndef LIB_BMP_H_
# define LIB_BMP_H_

# if !defined (__LITTLE_ENDIAN__) && !defined (__BIG_ENDIAN__)
#  define __LITTLE_ENDIAN__
# endif /* ! __LITTLE_ENDIAN__ && __BIG_ENDIAN__ */

# ifdef __LITTLE_ENDIAN__
#  define SIGN_SUPPORT 0x4d42
# else
#  define SIGN_SUPPORT 0x424d
# endif /* ! __LITTLE_ENDIAN__ */

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define E_NOERR	0
# define E_USAGE	1
# define E_OPEN		2
# define E_CLOSE	3
# define E_FILENAME	4
# define E_FILESYNTAX	5
# define E_MALLOC	6
# define E_BAD_COMPILE	7

#pragma pack(push, 1)

typedef struct s_fhbmp
{
  uint16_t	signature;
  uint32_t	size;
  uint32_t	reserved;
  uint32_t	bitsOffset;
}		t_fhbmp;

typedef struct s_hbmp
{
  uint32_t	headerSize;
  int32_t	width;
  int32_t	height;
  uint16_t	planes;
  uint16_t	bitCount;
  uint32_t	compression;
  uint32_t	sizeImage;
  int32_t	ppmX;
  int32_t	ppmY;
  uint32_t	clrUsed;
  uint32_t	clrImportant;
  uint32_t	redMask;
  uint32_t	greenMask;
  uint32_t	blueMask;
  uint32_t	alphaMask;
  uint32_t	csType;
  uint32_t	endpoints[9];
  uint32_t	gammaRed;
  uint32_t	gammaGreen;
  uint32_t	gammaBlue;
}		t_hbmp;

typedef struct	s_rgba
{
  uint8_t	r;
  uint8_t	g;
  uint8_t	b;
  uint8_t	a;
}		t_rgba;

typedef struct	s_bgra
{
  uint8_t	b;
  uint8_t	g;
  uint8_t	r;
  uint8_t	a;
}		t_bgra;

typedef struct	s_bitmap
{
  t_rgba	*bitmap;
  int32_t	width;
  int32_t	height;
}		t_bitmap;

#pragma pack(pop)

typedef struct	s_bit_stream
{
  int32_t	len;
  uint8_t	*line;
  uint8_t	*inc;
}		t_bit_stream;

typedef struct	s_bmp
{
  t_fhbmp	hdr_file;
  t_hbmp	hdr_data;
  t_bgra	*table;
  t_bitmap	*bitmap;
  t_bit_stream	stream;
}		t_bmp;

typedef struct	s_size
{
  int32_t	x;
  int32_t	y;
}		t_size;

# define S_UINT		sizeof(uint32_t)
# define S_INT		sizeof(int32_t)
# define S_USHRT	sizeof(uint16_t)
# define S_SHRT		sizeof(int16_t)
# define S_UCHAR	sizeof(uint8_t)
# define S_CHAR		sizeof(int8_t)
# define S_FHBMP	sizeof(t_fhbmp)
# define S_HBMP		sizeof(t_hbmp)
# define S_BRGA		sizeof(t_bgra)
# define S_RGBA		sizeof(t_rgba)

void	*bmp_calloc(uint64_t nmemb, uint64_t nsize);
void	bmp_memset(void *ptr, char reset, int64_t size);

int	parser_init(int fd, t_bmp *process);

t_bitmap	*load_bmp_file(char *filename);

int	parser_bitmap(int fd, t_bmp *process);

int	fill_1_byte(int *index, t_bitmap *bitmap,
		    t_bit_stream *stream, t_bgra *table);
int	fill_4_byte(int *index, t_bitmap *bitmap,
		    t_bit_stream *stream, t_bgra *table);
int	fill_8_byte(int *index, t_bitmap *bitmap,
		    t_bit_stream *stream, t_bgra *table);
int	fill_16_byte(int *index, t_bitmap *bitmap,
		     t_bit_stream *stream);
int	fill_24_byte(int *index, t_bitmap *bitmap,
		     t_bit_stream *stream);
int	fill_32_byte(int *index, t_bitmap *bitmap,
		     t_bit_stream *stream);

#endif /* ! LIB_BMP_H_ */
