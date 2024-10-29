// Fill out your copyright notice in the Description page of Project Settings.

#include "gridLayout.h"

gridLayout::gridLayout()
{
    empty = true;
    width = 0;
    length = 0;
    Occupied = nullptr;
}

void gridLayout::setup(int Width, int Length)
{
    this->width = Width;
    this->length = Length;

    Occupied = new bool*[length];
    for(int i = 0 ; i < length; i++)
    {
        Occupied[i] = new bool[width];
        for(int j = 0 ; j < width; j++)
            Occupied[i][j] = false;
    }
}

bool gridLayout::checkForSpace(int x, int y, int Width, int Length)
{
    return false;
}

void gridLayout::occupy(int x, int y, int Width, int Length)
{
    return;
}

gridLayout::~gridLayout()
{
    for(int i = 0 ; i < length; i++)
        delete[] Occupied[i];
    delete[] Occupied;
}
