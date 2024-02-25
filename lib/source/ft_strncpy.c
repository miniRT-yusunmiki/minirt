void	ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = 0;
}
