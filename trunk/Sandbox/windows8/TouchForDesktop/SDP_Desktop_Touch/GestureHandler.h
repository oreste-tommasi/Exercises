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

/* GestureHandler is a class for handling Gesture events sent to the app
by the OS after a user performs a gesture on the touch screen.  In its 
current incarnation, it will send these gesture notifications with their
data to the SDP_rectangle class so that the rectangle on the screen can
be manipulated according to the gestures performed. 
*/

#pragma once
#include <Windows.h>
#include "SDP_rectangle.h"


//This class will handle all gestures and apply them appropriately to the UI
class GestureHandler
{
public:
	GestureHandler(SDP_rectangle *rect);
	~GestureHandler(void);
	
	//To handle the gesture from the main wndproc function
	LRESULT WndProc(HWND hWnd, WPARAM wParam, LPARAM lParam);

	//individual gesture actions
	void handleZoom(HWND hWnd, GESTUREINFO gi);
	void handlePan(HWND hWnd, GESTUREINFO gi);
	void handleRotate(HWND hWnd, GESTUREINFO gi);
	void handle2FingerTap(HWND hWnd, GESTUREINFO gi);
	void handlePNT(HWND hWnd, GESTUREINFO gi);
	void invalidate(HWND hWnd, int force);

private:
	//Put a pointer to your image/object you want to manipulate here

	//multi-point gestue variables
	POINT m_first;
	POINT m_second;
	unsigned long long m_arguments;
	SDP_rectangle *m_rect;
	int m_draw_count;
	double m_initial_degrees;
	int m_inv_count;
};

