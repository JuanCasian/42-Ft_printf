// header

#include "ft_printf.h"

void prepare_percentage(t_info *info)
{
    int len;

    if (!(info->res = ft_strdup("%")))
        print_error();
    if (info->width > (len = ft_strlen(info->res)))
    {
        while (info->flags[Fminus] == 1 && len < info->width)
        {
            info->res = ft_straddsuffix(" ", info->res);
            len++;
        }
        while (info->flags[Fzero] == 1 && len < info->width)
        {
            info->res = ft_straddprefix("0", info->res);
            len++;
        }
        while (len < info->width)
        {
            info->res = ft_straddprefix(" ", info->res);
            len++;
        }
    }
}
