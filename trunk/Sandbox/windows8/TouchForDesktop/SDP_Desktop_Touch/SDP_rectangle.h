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



/* SDP_rectangle is a class for drawing and manipulating a rectangle */

#pragma once

#define NUM_PRESETS 5

/* This class will create and manipulate the rectangle on the screen */
class SDP_rectangle
{
public:
	SDP_rectangle(void);
	~SDP_rectangle(void);
	void draw(HWND hWnd, HDC hdc);
    void draw2(HWND hWnd, HDC hdc);
	void move(int x, int y);
	void changeSize(int length, int height);
	void rotate(int degrees);
	void changeRect();
	void changeColor();
	void changeColor(double degrees, double change);
	void changeBordercolor();

private:
	void initialize(HWND hWnd, HDC hdc);
	//upper left and bottom right points of rectangle
	POINT m_ul_point;
	POINT m_br_point;
	static const COLORREF m_colors[];
	COLORREF m_borderColor;
	COLORREF m_curColor;
	POINT m_ul_presets[NUM_PRESETS];
	POINT m_br_presets[NUM_PRESETS];
	int m_init;
	int m_color_index;
	int m_point_index;
	int m_buff_len;
	int m_buff_len2;
	WCHAR m_buff[40];
	WCHAR m_buff2[40];
};

