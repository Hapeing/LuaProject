#include <crtdbg.h>
#include <string>

#include <iostream>
#include "lua.hpp"

int main(int argc, char ** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	//int error = luaL_loadstring(L, "print('hello world')") || lua_pcall(L, 0, 0, 0);
	
	//int error = luaL_loadfile(L, "main.lua") || lua_pcall(L, 0, 0, 0);
	int error = luaL_loadfile(L, "fibbonacci.lua") || lua_pcall(L, 0, 0, 0);

	for (int i = 0; i < 1; i++)//call nrOfTimes
	{
		lua_getglobal(L, "fibb");
		error = lua_pcall(L, 0, 1, 0);

		if (error)
		{
			std::cerr << "Unable to run:" << lua_tostring(L, -1);
			lua_pop(L, 1);
			system("pause");
		}
		else
		{
			lua_pushnil(L);  /* first key */
			while (lua_next(L, -2) != 0) {
				/* uses 'key' (at index -2) and 'value' (at index -1) */
				printf("%i - %i\n",
					lua_tointeger(L, -2),
					lua_tointeger(L, -1));
				/* removes 'value'; keeps 'key' for next iteration */
				lua_pop(L, 1);
			}
			//std::cout << lua_tostring(L, -1) << std::endl;
			/*lua_getglobal(L, "bajs");
			std::string str = lua_tostring(L, -1);
			std::cout << str << std::endl;

			std::cout << lua_tostring(L, -2) << std::endl;
			std::cout << lua_tostring(L, -1) << std::endl;
			lua_pop(L, 2);*/
		}
	}
	
	system("pause");
	lua_close(L);
}