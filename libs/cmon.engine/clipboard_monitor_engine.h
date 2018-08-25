﻿/*
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

namespace std
{
	class clipboard_monitor
	{
	public:
		clipboard_monitor();
		~clipboard_monitor();
		HWND get_next_clipboard_wiever(void) noexcept;
		HWND get_monitor_window(void) noexcept;


	private:
		HWND p_next_clipboard_wiever = nullptr;
		HWND p_monitor_clipboard_wiever = nullptr;
		bool create_monitor_window() noexcept;
		void clipboard_update() noexcept;
	};

	
}


