/*
** errors.h for wolf3d in /home/lombar_e/rendu/Infographie/wolf
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Mon  19 19:53:37 2016 Thomas Lombard
** Last update Wed Jan 04 09:45:45 2017 Thomas Lombard
*/

#ifndef ERRORS_H_
# define ERRORS_H_

extern int	m_errno;

# define FR_ERRORS
# define MALLOC_FAIL "Une erreur inatendue, s'est produite. MALLOC_FAIL"
# define EXIT_ERROR	84

# define N_ERRORS	8
# define ERR_LEN	50

# define E_NOERR	0
# define E_USAGE	1
# define E_OPEN		2
# define E_CLOSE	3
# define E_FILENAME	4
# define E_FILESYNTAX	5
# define E_MALLOC	6
# define E_BAD_COMPILE	7

# define S_NOERR	""
# define S_USAGE	"Usage: \n\t./wolf3d <compiled_file.wf>\n"
# if defined (FR_ERRORS)
#  define S_OPEN	"Impossible d'ouvrir le fichier %s.\n"
#  define S_CLOSE	"Impossible de fermer le fichier %s.\n"
#  define S_FILENAME	"Le format du fichier %s est invalide.\n"
#  define S_FILESYNTAX	"Syntaxe du fichier %s invalide\n"
#  define S_MALLOC	"Plus de memoire (RAM) disponible.\n"
#  define S_BAD_COMPILE	"Mauvaise compilation de ce fichier.\n"
# elif defined (EN_ERRORS)
#  define S_OPEN	"Cannot open %s file.\n"
#  define S_CLOSE	"Cannot close %s file.\n"
#  define S_FILENAME	"Bad file format %s.\n"
#  define S_FILESYNTAX	"Invalid syntax in %s.\n"
#  define S_MALLOC	"No more place in memory.\n"
#  define S_BAD_COMPILE	"Bad compiler for this file.\n"
# endif/* ! FR_ERRORS */

#endif /* ! ERRORS_H_ */
