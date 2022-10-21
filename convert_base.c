/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 18:05:44 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/21 18:34:19 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void convert_to_base(char *baseset, int base, int n)
{
    char c;
    unsigned int num;
    
    if (n < 0)
    {
        num = n * -1;
        write(1, "-", 1);
    }
    else
        num = n;
    if (num / base > 0)
        convert_to_base(baseset, base, num / base);
    c = baseset[num % base];
    write(1, &c, 1);
}

int main(void)
{
    convert_to_base("0123456789ABCDEF", 16, -4892);
    write(1, "\n", 1);
    convert_to_base("0123456789", 10, -4892);
    write(1, "\n", 1);
    convert_to_base("01234567", 8, -4892);
    write(1, "\n", 1);
    convert_to_base("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26, -4892);
}