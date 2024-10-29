// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
*/
class WAREHOUSE_API gridLayout
{
	private:
		bool empty;
		bool** Occupied;
		int width;
		int length;

	public:
		gridLayout();
		void setup(int width, int length);
		bool checkForSpace(int x, int y, int width, int length);
		void occupy(int x, int y, int width, int length);

		~gridLayout();
};
