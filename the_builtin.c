#include "shell.h"

/**
 * _myexit - function that exits the shell.
 * @info: Structure containing potential arguments.
 * its used to maintain constant function prototype.
 *
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit".
 */
int _myexit(info_t *info)
{
	int exit_check;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exit_check = _erratoi(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - function that changes the current directory of the process.
 * @info: structure containing potential arguments.
 * used to maintain constant function prototype.
 *
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *g, *direc, buffer[1024];
	int chdir_ret;

	g = getcwd(buffer, 1024);
	if (!g)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		direc = _getenv(info, "HOME=");
		if (!direc)
			chdir_ret = /* TODO: what should this be? */
				chdir((direc = _getenv(info, "PWD=")) ? direc : "/");
		else
			chdir_ret = chdir(direc);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(g);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((direc = _getenv(info, "OLDPWD=")) ? direc : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - function that changes the current directory of the process.
 * @info: structure containing potential arguments.
 * used to maintain constant function prototype.
 *
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
