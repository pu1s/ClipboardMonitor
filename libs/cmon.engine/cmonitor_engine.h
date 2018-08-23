/*
MIT License

Copyright(c) 2018 pu1s(pu1s@outlook.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <Windows.h>

typedef enum c_monitor_state
{
	unknown = 0,	 // nd
	stopped = 1,	 // остановлен
	running = 2		 // работает
}C_MONITOR_STATE;

class c_monitor
{
public:
	c_monitor();
	~c_monitor();

	C_MONITOR_STATE get_c_monitor_state(void) const;
	C_MONITOR_STATE run(void);
	C_MONITOR_STATE stop(void);

private:

	C_MONITOR_STATE m_c_monitor_state = C_MONITOR_STATE::unknown;
	HWND p_next_clipboard_wiever = nullptr;
	
};


