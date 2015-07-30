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
#include "GestureHandler.h"

#define _USE_MATH_DEFINES // has to be defined to activate definition of M_PI
#include <math.h>

GestureHandler::GestureHandler(SDP_rectangle *rect)
{
	m_arguments = 0;
	m_rect = rect;
	m_draw_count = 0;
	m_inv_count = 0;
}

GestureHandler::~GestureHandler(void)
{
}

LRESULT GestureHandler::WndProc(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	bool gestureHandled = 0;
    GESTUREINFO  gi;
    ZeroMemory(&gi, sizeof(GESTUREINFO));
    gi.cbSize = sizeof(GESTUREINFO);
	BOOL result = GetGestureInfo((HGESTUREINFO)lParam, &gi);

	if(result)
	{
		switch(gi.dwID)
		{
			case GID_BEGIN:
			case GID_END:
				gestureHandled = 1;
				break;
			case GID_ZOOM:
				handleZoom(hWnd, gi);
				gestureHandled = 1;
				break;
			case GID_PAN:
				handlePan(hWnd, gi);
				gestureHandled = 1;
				break;
			case GID_ROTATE:
				handleRotate(hWnd, gi);
				gestureHandled = 1;
				break;
			case GID_TWOFINGERTAP:
				handle2FingerTap(hWnd, gi);
				gestureHandled = 1;
				break;
			case GID_PRESSANDTAP:
				handlePNT(hWnd, gi);
				gestureHandled = 1;
				break;
			default:
				gestureHandled = 0;
				break;
		}
	}
	else
	{
		//failed to get gesture info
	}

	if (gestureHandled)
    {
        CloseGestureInfoHandle((HGESTUREINFO)lParam);
    }
	else
    {
        DefWindowProc(hWnd, WM_GESTURE, wParam, lParam);
    }

	return (GID_END | GID_ZOOM | GID_PAN | GID_ROTATE | GID_TWOFINGERTAP | GID_PRESSANDTAP) << 1;
}

void GestureHandler::handleZoom(HWND hWnd, GESTUREINFO gi)
{
	//Capture the first location of the two fingers
	if (gi.dwFlags & GF_BEGIN)
	{
		m_arguments = gi.ullArguments;
		m_first.x = gi.ptsLocation.x;
		m_first.y = gi.ptsLocation.y;
		return;
	}
	//Capture the end of the gesture
	else if (gi.dwFlags & GF_END)
	{
		int height = 0;
		int length = 0;

		height = int (gi.ullArguments - m_arguments);
		length = int (gi.ullArguments - m_arguments);
		
		m_rect->changeSize(length, height);

		//InvalidateRect(hWnd, NULL, TRUE);
		invalidate(hWnd, TRUE);

		m_arguments = 0;
	}
	//It's a midpoint between the beginning and end of the gesture
	else
	{
		//to see the object update as you perform the gesture,
		//calculate the coordinates and redraw it here.
		int height = 0;
		int length = 0;

		height = int (gi.ullArguments - m_arguments);
		length = int (gi.ullArguments - m_arguments);
		
		m_rect->changeSize(length, height);

		//InvalidateRect(hWnd, NULL, TRUE);
		invalidate(hWnd, FALSE);

		m_arguments = gi.ullArguments;
	}
}
void GestureHandler::handlePan(HWND hWnd, GESTUREINFO gi)
{
	if (gi.dwFlags & GF_BEGIN)
	{
		m_arguments = gi.ullArguments;
		m_first.x = gi.ptsLocation.x;
		m_first.y = gi.ptsLocation.y;
		return;
	}
	else
	{
		int x = 0;
		int y = 0;

		x = int (gi.ptsLocation.x - m_first.x);
		y = int (gi.ptsLocation.y - m_first.y);

		m_rect->move(x, y);
		//InvalidateRect(hWnd, NULL, TRUE);
		invalidate(hWnd, FALSE);

		m_first.x = gi.ptsLocation.x;
		m_first.y = gi.ptsLocation.y;
	}
}
void GestureHandler::handleRotate(HWND hWnd, GESTUREINFO gi)
{
	double radians = 0;
	double radian_change = 0;
	double degree_change = 0;
	
	if (gi.dwFlags & GF_BEGIN)
	{
		m_arguments = gi.ullArguments;
		radians =  GID_ROTATE_ANGLE_FROM_ARGUMENT(m_arguments);
		m_initial_degrees = radians * (180 / M_PI);
		if (m_initial_degrees < 0)
			m_initial_degrees = 360 + m_initial_degrees;
		
		m_rect->changeColor(m_initial_degrees, 0);
		//InvalidateRect(hWnd, NULL, TRUE);
		invalidate(hWnd, TRUE);
	}
	else
	{
		int temp_total = 0;
		radian_change = GID_ROTATE_ANGLE_FROM_ARGUMENT(gi.ullArguments);
		degree_change = radian_change * (180 / M_PI);
		
		temp_total = (int) (m_initial_degrees + degree_change);
		if (temp_total < 0)
			temp_total = 360 + temp_total;
		temp_total = temp_total % 360;

		m_rect->changeColor(temp_total, degree_change);
		//InvalidateRect(hWnd, NULL, TRUE);
		invalidate(hWnd, FALSE);
	}


}
void GestureHandler::handle2FingerTap(HWND hWnd, GESTUREINFO gi)
{
	m_rect->changeRect();

	//InvalidateRect(hWnd, NULL, TRUE);
	invalidate(hWnd, TRUE);
}
void GestureHandler::handlePNT(HWND hWnd, GESTUREINFO gi)
{
	m_rect->changeBordercolor();

	//InvalidateRect(hWnd, NULL, TRUE);
	invalidate(hWnd, TRUE);
}

void GestureHandler::invalidate(HWND hWnd, int force)
{
	if (force)
	{
		InvalidateRect(hWnd, NULL, TRUE);
		m_inv_count = 0;
		return;
	}
	else
	{
		if (m_inv_count == 0)
		{
			InvalidateRect(hWnd, NULL, TRUE);
		}
		m_inv_count = (m_inv_count + 1) % 10;
	}
}