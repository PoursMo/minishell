static int update_exit_code(int new_code)
{
	static int code;

	if(new_code != -1)
	{
		code = new_code;	
	}
	return (code);
}

int get_exit_code(void)
{
	return (update_exit_code(-1));
}

void set_exit_code(int code)
{
	update_exit_code(code);
}