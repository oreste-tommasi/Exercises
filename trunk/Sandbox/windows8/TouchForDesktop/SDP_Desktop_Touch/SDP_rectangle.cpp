/*
Copyright (c) <2012>, Intel Corporation All Rights Reserved.

The source code, information and material ("Material") contained herein is 
owned by Intel Corporation or its suppliers or licensors, and title to such 
Material remains with Intel Corporation or its suppliers or licensors. The 
Material contains proprietary information of Intel or its suppliers and 
licensors. The Material is protected by worldwide copyright laws and treaty 
provisions. No part of the Material may be used, copied, reproduced, 
modified, published, uploaded, posted, transmitted, distributed or 
disclosed in any way without Intel's prior express written permission. No 
license under any patent, copyright or other intellectual property rights 
in the Material is granted to or conferred upon you, either expressly, by 
implication, inducement, estoppel or otherwise. Any license under such 
intellectual property rights must be express and approved by Intel in 
writing.

Copyright (c) Microsoft Corporation. All rights reserved

Unless otherwise agreed by Intel in writing, you may not remove or alter 
this notice or any other notice embedded in Materials by Intel or Intel’s 
suppliers or licensors in any way.
*/


#include "StdAfx.h"
#include "SDP_rectangle.h"

const COLORREF SDP_rectangle::m_colors[] = 
{
    RGB(13,13,13),     // black
    RGB(255,139,23), // yellow   
    RGB(146,208,80),   // green
    RGB(149,179,215)    // blue
};

SDP_rectangle::SDP_rectangle(void)
{
	m_init = 1;
	m_color_index = 0;
	m_point_index = 0;
	m_curColor = m_colors[m_color_index];
	m_borderColor = m_colors[m_color_index];
	m_buff_len = wsprintf(m_buff, (LPCWSTR)"");
	m_buff_len2 = wsprintf(m_buff2, (LPCWSTR)"");
}


SDP_rectangle::~SDP_rectangle(void)
{
}

void SDP_rectangle::initialize(HWND hWnd, HDC hdc)
{
	int temp_ulx;
	int temp_uly;
	int temp_brx;
	int temp_bry;
	int incr = 25;

	RECT r;

    GetClientRect(
        hWnd,
        &r
    );
	
	temp_ulx = r.left + 200;
	temp_uly = r.top + 200;
	temp_brx = r.right - 200;
	temp_bry = r.bottom - 200;
	
	for (int i=0; i<NUM_PRESETS; i++)
	{
		m_ul_presets[i].x = (temp_ulx += incr);
		m_ul_presets[i].y = (temp_uly += incr);
		m_br_presets[i].x = (temp_brx -= incr);
		m_br_presets[i].y = (temp_bry -= incr);
	}

	m_ul_point.x = r.left + 300;
	m_ul_point.y = r.top + 300;
	m_br_point.x = r.right - 300;
	m_br_point.y = r.bottom - 300;

	m_init = 0;
	m_point_index = 0;
}

void SDP_rectangle::draw2(HWND hWnd, HDC hdc)
{
    // Copied the code from MSDN on double buffering: http://msdn.microsoft.com/en-us/library/ms969905.aspx 
    RECT rc;
    HDC hdcMem;
    HBITMAP hbmMem;
    HGDIOBJ hbmOld;
    HBRUSH hbrBkGnd;
    HFONT hfntOld;

    HGDIOBJ lastpen;
	HPEN mypen;
	int ret;

    // Run init function as needed
    if (m_init)
	{
		initialize(hWnd, hdc);
	}

    // Set up back buffer
    GetClientRect(hWnd, &rc);
    hdcMem = CreateCompatibleDC(hdc);
    hbmMem = CreateCompatibleBitmap(hdc, rc.right-rc.left, rc.bottom-rc.top);

    // Set up to render to the back buffer
    hbmOld = SelectObject(hdcMem, hbmMem);

    // Erase the background.
    hbrBkGnd = CreateSolidBrush(GetSysColor(COLOR_WINDOW));
    FillRect(hdcMem, &rc, hbrBkGnd);
    DeleteObject(hbrBkGnd);

    // Draw text
    TextOut(hdcMem, 0, 0, m_buff, m_buff_len);
	TextOut(hdcMem, 0, 100, m_buff2, m_buff_len2);
    
    // Draw rectangle
	mypen = CreatePen(PS_SOLID, 10, m_borderColor);
	lastpen = SelectObject(hdcMem, mypen);

	ret = Rectangle(hdcMem, m_ul_point.x, m_ul_point.y, m_br_point.x, m_br_point.y);
	if (ret)
	{
		HBRUSH brush = CreateSolidBrush(m_curColor);
		if(brush)
		{
			RECT myrect;
			myrect.top = m_ul_point.y;
			myrect.left = m_ul_point.x;
			myrect.bottom = m_br_point.y;
			myrect.right = m_br_point.x;
			FillRect(hdcMem, &myrect, brush);
			DeleteObject(brush);
		}
	}

	DeleteObject(mypen);
	SelectObject(hdcMem, lastpen);


    // Flip back buffer to the front
    BitBlt(hdc, rc.left, rc.top, rc.right-rc.left, rc.bottom-rc.top, hdcMem, 0, 0, SRCCOPY);

    // Disable back buffer
    SelectObject(hdcMem, hbmOld);
    DeleteObject(hbmMem);
    DeleteDC(hdcMem);
}


void SDP_rectangle::draw(HWND hWnd, HDC hdc)
{
	HGDIOBJ lastpen;
	HPEN mypen;
	int ret;

	if (m_init)
	{
		initialize(hWnd, hdc);
	}
	
	TextOut(hdc, 0, 0, m_buff, m_buff_len);
	TextOut(hdc, 0, 100, m_buff2, m_buff_len2);

	mypen = CreatePen(PS_SOLID, 10, m_borderColor);
	lastpen = SelectObject(hdc, mypen);

	ret = Rectangle(hdc, m_ul_point.x, m_ul_point.y, m_br_point.x, m_br_point.y);
	if (ret)
	{
		HBRUSH brush = CreateSolidBrush(m_curColor);
		if(brush)
		{
			RECT myrect;
			myrect.top = m_ul_point.y;
			myrect.left = m_ul_point.x;
			myrect.bottom = m_br_point.y;
			myrect.right = m_br_point.x;
			FillRect(hdc, &myrect, brush);
			DeleteObject(brush);
		}
	}

	DeleteObject(mypen);
	SelectObject(hdc, lastpen);
}
void SDP_rectangle::move(int x, int y)
{
	m_ul_point.x = m_ul_point.x + x;
	m_ul_point.y = m_ul_point.y + y;
	m_br_point.x = m_br_point.x + x;
	m_br_point.y = m_br_point.y + y;
}
void SDP_rectangle::changeSize(int length, int height)
{
	int midx = (m_br_point.x + m_ul_point.x) / 2;
	int midy = (m_br_point.y + m_ul_point.y) / 2;

	m_ul_point.x = m_ul_point.x - length/2;
	m_ul_point.y = m_ul_point.y - length/2;
	m_br_point.x = m_br_point.x + length/2;
	m_br_point.y = m_br_point.y + height/2;

	if (m_ul_point.x > midx)
		m_ul_point.x = midx;
	if (m_ul_point.y > midy)
		m_ul_point.y = midy;
	if (m_br_point.x < midx)
		m_br_point.x = midx;
	if (m_br_point.y < midy)
		m_br_point.y = midy;
}
void SDP_rectangle::rotate(int degrees)
{

}
void SDP_rectangle::changeRect()
{
	m_ul_point.x -= 20; //= m_ul_presets[m_point_index].x;
	m_ul_point.y -= 20; //= m_ul_presets[m_point_index].y;
	m_br_point.x += 20; //= m_br_presets[m_point_index].x;
	m_br_point.y += 20; //= m_br_presets[m_point_index].y;

	//m_point_index = (m_point_index + 1) % NUM_PRESETS; 
}

void SDP_rectangle::changeBordercolor()
{
	m_color_index = (m_color_index + 1) % 4;
	m_borderColor = m_colors[m_color_index];
}

void SDP_rectangle::changeColor()
{
	m_color_index = (m_color_index + 1) % 4;
	m_curColor = m_colors[m_color_index];
	m_borderColor = m_colors[m_color_index];
}

void SDP_rectangle::changeColor(double degrees, double change)
{
	int r = 255;
	int g = 0;
	int b = 0;
	
	m_buff_len = wsprintf(m_buff, L"%i", (int)degrees);
	m_buff_len2 = wsprintf(m_buff2, L"%i", (int)change);

	//green up
	if (degrees < 60)
		g = (int) ((degrees/60) * 255);
	//red down
	else if (degrees > 59 && degrees < 120)
	{
		degrees -= 60;
		g=255;
		r = (int) ((1-(degrees/60)) * 255);
	}
	//blue up
	else if (degrees > 119 && degrees < 180)
	{
		degrees -= 120;
		r = 0;
		g = 255;
		b = (int) ((degrees/60) * 255);
	}
	//green down
	else if (degrees > 179 && degrees < 240)
	{
		degrees -= 180;
		r = 0;
		b = 255;
		g = (int) ((1-(degrees /60)) * 255);
	}
	//red up
	else if (degrees > 239 && degrees < 300)
	{
		degrees -= 240;
		b = 255;
		g = 0;
		r = (int) ((degrees/60) * 255);
	}
	//blue down
	else if (degrees > 299 && degrees < 360)
	{
		degrees -= 300;
		r = 255; 
		g = 0;
		b = (int) ((1-(degrees /60)) * 255);
	}
	else 
	{
		r = 255;
		g = 0;
		b = 0;
	}
	m_curColor = RGB(r, g, b);
	m_borderColor = RGB(r, g, b);
}