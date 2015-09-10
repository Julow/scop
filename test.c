#include "libft.h"
#include <limits.h>
#include <unistd.h>

#define MAX_PATH_LEN	(PATH_MAX - 1)

typedef struct	s_path
{
	char			str[MAX_PATH_LEN + 1];
	int				length;
}				t_path;

#define PATHC(s)	((t_path){(s), sizeof(s)})

/*
** Return the number of byte that are equals in s1 and s2
*/
t_uint			ft_memstart(const void *s1, const void *s2, t_uint n)
{
	t_uint const	length = n;

	while (n > sizeof(MEM_TYPE))
	{
		if (*((MEM_TYPE*)s1) != *((MEM_TYPE*)s2))
			break ;
		s1 += sizeof(MEM_TYPE);
		s2 += sizeof(MEM_TYPE);
		n -= sizeof(MEM_TYPE);
	}
	while (n-- > 0)
	{
		if (*((t_byte*)s1) != *((t_byte*)s2))
			return (length - n);
		s1++;
		s2++;
	}
	return (n);
}

void			ft_path_init(t_path *path, t_sub str)
{
	if (str.length > MAX_PATH_LEN)
		str.length = MAX_PATH_LEN;
	ft_memcpy(path->str, str.str, str.length);
	path->length = str.length;
	path->str[str.length] = '\0';
}

t_sub			ft_path_basename(t_sub path)
{
	int				len;

	len = path.length;
	while (--len >= 0)
		if (path.str[len] == '/'
			&& (len <= 0 || path.str[len - 1] != '\\'))
			return (SUB(path.str + len + 1, path.length - len));
	return (path);
}

t_sub			ft_path_dirname(t_sub path)
{
	int				len;

	len = path.length;
	while (--len >= 0)
		if (path.str[len] == '/'
			&& (len <= 0 || path.str[len - 1] != '\\'))
			return (SUB(path.str, len));
	return (SUB(path.str, 0));
}

void			ft_path_clean(t_path *path)
{
}

t_bool			ft_path_current(t_path *dst)
{
	if (getcwd(dst->str, MAX_PATH_LEN) == NULL)
		return (false);
	dst->length = ft_strlen(dst->str);
	return (true);
}

void			ft_path_copy(t_path *dst, t_path const *src)
{
	ft_memcpy(dst->str, src->str, src->length + 1);
	dst->length = src->length;
}

t_bool			ft_path_append(t_path *path, t_sub add)
{
	if ((add.length + path->length + 1) > MAX_PATH_LEN)
		return (false);
	if (path->length <= 0)
		path->str[path->length++] = '.';
	path->str[path->length++] = '/';
	ft_memcpy(path->str + path->length, add.str, add.length);
	path->length += add.length;
	path->str[path->length] = '\0';
	return (true);
}

t_bool			ft_path_absolute(t_path *path)
{
	t_path			tmp;

	ft_path_copy(&tmp, path);
	if (!ft_path_current(path))
		return (false);
	return (ft_path_append(path, SUB(tmp.str, tmp.length)));
}

t_bool			ft_path_relative(t_path *path)
{
	t_path			tmp;
	t_path			absolute;
	int				length;

	ft_path_copy(&tmp, path);
	if (!ft_path_current(&absolute))
		return (false);
	ft_path_copy(path, &absolute);
	if (!ft_path_append(path, SUB(tmp.str, tmp.length)))
		return (false);
	length = ft_memstart(tmp.str, path->str, tmp.length);
	return (true);
}

static void		debug_path(t_path const *path)
{
	t_sub			tmp;

	ft_printf("\tpath: %s (%.*s)\n", path->str, path->length, path->str);
	tmp = ft_path_basename(SUB(path->str, path->length));
	ft_printf("\tbasename: %.*s\n", tmp.length, tmp.str);
	tmp = ft_path_dirname(SUB(path->str, path->length));
	ft_printf("\tdirname: %.*s\n", tmp.length, tmp.str);
}

int				main(int argc, char **argv)
{
	t_path			path;

	if (argc > 1)
	{
		ft_path_init(&path, ft_sub(argv[1], 0, -1));
		ft_printf("argv[1]:\n");
		ft_path_init(&path, ft_sub(argv[1], 0, -1));
		debug_path(&path);
		ft_printf("absolute:\n");
		ft_path_absolute(&path);
		debug_path(&path);
		// ft_printf("relative:\n");
		// ft_path_relative(&path);
		// debug_path(&path);
	}
	if (argc > 2)
	{
		ft_path_init(&path, ft_sub(argv[1], 0, -1));
		ft_printf("argv[1] + argv[2]:\n");
		if (!ft_path_append(&path, ft_sub(argv[2], 0, -1)))
			return (ft_printf("FAIL\n"), 1);
		debug_path(&path);
		ft_printf("absolute:\n");
		ft_path_absolute(&path);
		debug_path(&path);
		// ft_printf("relative:\n");
		// ft_path_relative(&path);
		// debug_path(&path);
	}
	return (0);
}
