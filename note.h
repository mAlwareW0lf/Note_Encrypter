#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int size = 0x2f;
int Mthd[15] = { 0x4d, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x01, 0x00, 0x04, 0x01, 0xe0, 1488 };
int Mtrk_h1[16] = { 0x4d, 0x54, 0x72, 0x6b, 0x00, 0x00, 0x00, 0x0b, 0x00, 0xff, 0x51, 0x03, 0x07, 0xa1, 0x20, 1488 };
int Mtrk_h2[9] = { 0x4d, 0x54, 0x72, 0x6b, 0x00, 0x00, 0x00, 0x2f, 1488 };
int TrkName[6] = { 0x00, 0xff, 0x03, 0x01, 0x47, 1488 };
int Inst[4] = { 0x00, 0xc0, 0x24, 1488 };
int ToneN[9] = { 0x00, 0xff, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 1488 };
int Note_On[5] = { 0x00, 0x90, 0x4f, 0x60, 1488 };
int Idk_wtf[19] = { 0x00, 0xff, 0x59, 0x02, 0x00, 0x00, 0x00, 0xb0, 0x65, 0x00, 0x00, 0xb0, 0x64, 0x00, 0x00, 0xb0, 0x06, 0x06, 1488 };
int Note_Off[6] = { 0x81, 0x70, 0x80, 0x60, 0x40, 1488 };
int end[5] = { 0x00, 0xff, 0x2f, 0x00, 1488 };


int tone_Am(int dd, int dg)
{
    if (dg == dd + 0) { return 0x28; }
    if (dg == dd + 1) { return 0x29; }
    if (dg == dd + 2) { return 0x2b; }
    if (dg == dd + 3) { return 0x2d; }
    if (dg == dd + 4) { return 0x2f; }
    if (dg == dd + 5) { return 0x30; }
    if (dg == dd + 6) { return 0x32; }
    if (dg == dd + 7) { return 0x34; }
    if (dg == dd + 8) { return 0x35; }
    if (dg == dd + 9) { return 0x37; }
    if (dg == dd + 10) { return 0x39; }
    if (dg == dd + 11) { return 0x3b; }
    if (dg == dd + 12) { return 0x3c; }
    if (dg == dd + 13) { return 0x3e; }
    if (dg == dd + 14) { return 0x40; }
    if (dg == dd + 15) { return 0x41; }
    if (dg == dd + 16) { return 0x43; }
    if (dg == dd + 17) { return 0x45; }
    if (dg == dd + 18) { return 0x47; }
    if (dg == dd + 19) { return 0x48; }
    if (dg == dd + 20) { return 0x4a; }
    if (dg == dd + 21) { return 0x4c; }
    if (dg == dd + 22) { return 0x4d; }
    if (dg == dd + 23) { return 0x4f; }
    if (dg == dd + 24) { return 0x51; }
    if (dg == dd + 25) { return 0x53; }
}

int putcMthd(FILE* fp)
{
    int i = 0;
    while (Mthd[i] != 1488)
    {
        // printf("Mthd\n");
        putc(Mthd[i], fp);
        i++;
    }
}

int putcMtrk_h1(FILE* fp)
{
    int i = 0;
    while (Mtrk_h1[i] != 1488)
    {
        putc(Mtrk_h1[i], fp);
        i++;
    }
}

int putcMtrk_h2(FILE* fp)
{
    int i = 0;
    while (Mtrk_h2[i] != 1488)
    {
        putc(Mtrk_h2[i], fp);
        i++;
    }
}

int putcTrkN(FILE* fp)
{
    int i = 0;
    while (TrkName[i] != 1488)
    {
        putc(TrkName[i], fp);
        i++;
    }
}

int putcInst(FILE* fp)
{
    int i = 0;
    while (Inst[i] != 1488)
    {
        putc(Inst[i], fp);
        i++;
    }
}

int putcToneN(FILE* fp)
{
    int i = 0;
    while (ToneN[i] != 1488)
    {
        putc(ToneN[i], fp);
        i++;
    }
}

int putcNote_On(FILE* fp)
{
    int i = 0;
    while (Note_On[i] != 1488)
    {
        putc(Note_On[i], fp);
        i++;
    }
}

int putcNote_Off(FILE* fp)
{
    int i = 0;
    while (Note_Off[i] != 1488)
    {
        putc(Note_Off[i], fp);
        i++;
    }
}

int putcIdk(FILE* fp)
{
    int i = 0;
    while (Idk_wtf[i] != 1488)
    {
        putc(Idk_wtf[i], fp);
        i++;
    }
}

int putcEnd(FILE* fp)
{
    int i = 0;
    while (end[i] != 1488)
    {
        putc(end[i], fp);
        i++;
    }
}