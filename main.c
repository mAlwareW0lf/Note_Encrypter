#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "note.h"

#pragma warning(disable : 4996)

int tone_Am(int dd, int dg);
void assemble();
char* name = "smth2.mid";
long long int note[90000];
unsigned long long b = 0;
int p = 0;

int main()
{
    char word[4096];
    int i = 0;
    printf("Enter text-> ");
    scanf("%s", word);
 
    while(i < strlen(word))
    {
        //printf("w = 0x%x\n", word[i]);
        if (word[i] == 0x5f) { note[i] = 0x57; p++; }
        else
        {
            note[i] = tone_Am(97, word[i]);
            
        }

        //printf("n = 0x%x\n", note[i]);

        i++;
        b++;
    }
   
    //wrt();
    assemble();
    printf("\n<Text was crypted>");
    printf("\n<Press any key to exit>");
    getch();
    return 0;
}



void assemble()
{
    FILE* fp = fopen(name, "w");
    int i = 0;
    unsigned long long n =  0x26 + ((b-p) * 9);

    putcMthd(fp);
    putcMtrk_h1(fp);
    putcEnd(fp);

    //kak_zhalj_chto_ja_nie_mogu_bytj_csastliv

    if (n < 0xff)
    {  
        Mtrk_h2[7] = n;
    } 

    if (n > 0xffffffff)
    {
        printf("<!WARNING!>\n");
        printf("<text too big>\n");
        printf("<How you... Are you trying to encrypt War and Peace at ones?>\n");
        return 666;
    }

    if (n > 0xff)
    {
        while (n > 0xff)
        {

            if (n > 0xffff)
            {   

                while (n > 0xffff)
                {

                    if (n > 0xffffff)
                    {   
                        while (n > 0xffffff)
                        {
                            n = n - 256;
                            Mtrk_h2[4]++;
                        }
                    }
                    n = n - 256;
                    Mtrk_h2[5]++;
                }
            }
            n = n - 256;
            Mtrk_h2[6]++;
        }
        Mtrk_h2[7] = n;
    }


    putcMtrk_h2(fp); //8 байт
    putcTrkN(fp);
    putcInst(fp);
    putcToneN(fp);
    
    while (i < b)
    {
        if(note[i+1] != 0x57 && note[i] != 0x57 && i+1 != b)
        {
            Note_On[2] = note[i];
            putcNote_On(fp); // 3 байт
            if (i == 0) { putcIdk(fp); }
            Note_Off[3] = note[i];
            Note_Off[0] = 0x81;
            Note_Off[1] = 0x70;
            putcNote_Off(fp); // 4 байт
        }
        if(note[i+1] == 0x57)
        {
            Note_On[2] = note[i];
            putcNote_On(fp); // 3 байт
            if (i == 0) { putcIdk(fp); }
            Note_Off[3] = note[i];
            Note_Off[0] = 0x83;
            Note_Off[1] = 0x60;
            putcNote_Off(fp); // 4 байт
        }
        if (i + 1 == b)
        {
            Note_On[2] = note[i];
            putcNote_On(fp); // 3 байт
            if (i == 0) { putcIdk(fp); }
            Note_Off[3] = note[i];
            Note_Off[0] = 0x8f;
            Note_Off[1] = 0x00;
            putcNote_Off(fp); // 4 байт
        }

 
        i++;
    }

   
    putcEnd(fp);

    i = 0;
    putcMtrk_h2(fp); //8 байт
    Note_On[1] = 0x92;
    Note_Off[2] = 0x82;
    TrkName[4] = 0x48;
    Inst[1] = 0xc2;
    putcTrkN(fp);
    putcInst(fp);
    putcToneN(fp);

    while (i < b)
    {
        if (note[i + 1] != 0x57 && note[i] != 0x57 && i + 1 != b)
        {
            if (note[i] != 0x29 && note[i] != 0x2f && note[i] != 0x35 && note[i] != 0x3b && note[i] != 0x41 && note[i] != 0x47 && note[i] != 0x4d && note[i] != 0x53)
            {
                Note_On[2] = note[i] - 5;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] - 5;
                Note_Off[0] = 0x81;
                Note_Off[1] = 0x70;
                putcNote_Off(fp); // 4 байт
            }
            else
            {
                Note_On[2] = note[i] - 5;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] - 5;
                Note_Off[0] = 0x81;
                Note_Off[1] = 0x70;
                putcNote_Off(fp); // 4 байт
            }
         
        }
        if (note[i + 1] == 0x57)
        {
            if (note[i] != 0x29 && note[i] != 0x2f && note[i] != 0x35 && note[i] != 0x3b && note[i] != 0x41 && note[i] != 0x47 && note[i] != 0x4d && note[i] != 0x53)
            {
                Note_On[2] = note[i] - 5;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] - 5;
                Note_Off[0] = 0x83;
                Note_Off[1] = 0x60;
                putcNote_Off(fp); // 4 байт
            }
            else
            {
                Note_On[2] = note[i] - 5;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] - 5;
                Note_Off[0] = 0x83;
                Note_Off[1] = 0x60;
                putcNote_Off(fp); // 4 байт
            }

        }
        if (i + 1 == b)
        {
            if (note[i] != 0x29 && note[i] != 0x2f && note[i] != 0x35 && note[i] != 0x3b && note[i] != 0x41 && note[i] != 0x47 && note[i] != 0x4d && note[i] != 0x5)
            {
                Note_On[2] = note[i] - 5;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] - 5;
                Note_Off[0] = 0x8f;
                Note_Off[1] = 0x00;
                putcNote_Off(fp); // 4 байт
            }
            else
            {
                Note_On[2] = note[i] - 5;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] - 5;
                Note_Off[0] = 0x8f;
                Note_Off[1] = 0x00;
                putcNote_Off(fp); // 4 байт
            }

        }


        i++;
    }
    putcEnd(fp);

    i = 0;
    putcMtrk_h2(fp); //8 байт
    Note_On[1] = 0x94;
    Note_Off[2] = 0x84;
    TrkName[4] = 0x49;
    putcTrkN(fp);
    Inst[1] = 0xc4;
    putcInst(fp);
    putcToneN(fp);

    while (i < b)
    {
        if (note[i] >= 0x48)
        {

            if (note[i + 1] != 0x57 && note[i] != 0x57 && i + 1 != b)
            {
                Note_On[2] = note[i] - 12;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] - 12;
                Note_Off[0] = 0x81;
                Note_Off[1] = 0x70;
                putcNote_Off(fp); // 4 байт
            }
            if (note[i + 1] == 0x57)
            {
                Note_On[2] = note[i] - 12;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] - 12;
                Note_Off[0] = 0x83;
                Note_Off[1] = 0x60;
                putcNote_Off(fp); // 4 байт
            }
            if (i + 1 == b)
            {
                Note_On[2] = note[i] - 12;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] - 12;
                Note_Off[0] = 0x8f;
                Note_Off[1] = 0x00;
                putcNote_Off(fp); // 4 байт
            }

        }
        if (note[i] <= 0x3b)
        {
            if (note[i + 1] != 0x57 && note[i] != 0x57 && i + 1 != b)
            {
                Note_On[2] = note[i] + 12;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] + 12;
                Note_Off[0] = 0x81;
                Note_Off[1] = 0x70;
                putcNote_Off(fp); // 4 байт
            }
            if (note[i + 1] == 0x57)
            {
                Note_On[2] = note[i] + 12;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] + 12;
                Note_Off[0] = 0x83;
                Note_Off[1] = 0x60;
                putcNote_Off(fp); // 4 байт
            }
            if (i + 1 == b)
            {
                Note_On[2] = note[i] + 12;
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i] + 12;
                Note_Off[0] = 0x8f;
                Note_Off[1] = 0x00;
                putcNote_Off(fp); // 4 байт
            }
        }
        if(note[i] > 0x3b && note[i] < 0x48)
        {
            if (note[i + 1] != 0x57 && note[i] != 0x57 && i + 1 != b)
            {
                Note_On[2] = note[i];
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i];
                Note_Off[0] = 0x81;
                Note_Off[1] = 0x70;
                putcNote_Off(fp); // 4 байт
            }
            if (note[i + 1] == 0x57)
            {
                Note_On[2] = note[i];
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i];
                Note_Off[0] = 0x83;
                Note_Off[1] = 0x60;
                putcNote_Off(fp); // 4 байт
            }
            if (i + 1 == b)
            {
                Note_On[2] = note[i];
                putcNote_On(fp); // 3 байт
                if (i == 0) { putcIdk(fp); }
                Note_Off[3] = note[i];
                Note_Off[0] = 0x8f;
                Note_Off[1] = 0x00;
                putcNote_Off(fp); // 4 байт
            }
        }
        i++;
    }
    putcEnd(fp);
}
