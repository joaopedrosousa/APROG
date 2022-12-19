#ifndef winColors

#include <stdio.h>
#include <Windows.h>

void setForegroundColor(int fi,int fr,int fg,int fb)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        int tc = csbi.wAttributes;
        int fc = tc%16;
        int bc = tc/16;
        int nc = bc*16+8*fi+4*fr+2*fg+fb;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), nc);
    }
}

void setBackgroundColor(int bi,int br,int bg,int bb)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        int tc = csbi.wAttributes;
        int fc = tc%16;
        int bc = tc/16;
        int nc = 128*bi+64*br+32*bg+16*bb+fc;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), nc);
    }
}

void setColor(int bi,int br,int bg,int bb,int fi,int fr,int fg,int fb)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        int nc = 128*br+64*bg+32*bb+16*bi+8*fr+4*fg+2*fb+fi;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), nc);
    }
}
void demoColor()
{
    char fore[]="   FOREGROUND   ";
    char back[]="   BACKGROUND   ";
    int br,bg,bb,bi,fr,fg,fb,fi,c,i;
    setBackgroundColor(0,0,0,0);setForegroundColor(1,1,1,1);
    printf("         ");
    for(i=0;i<16;i++) printf("  %c  ",fore[i]);printf("\n");
    printf("    IRGB ");
    for(fr=0;fr<=1;fr++) for(fg=0;fg<=1;fg++) for(fb=0;fb<=1;fb++) for(fi=0;fi<=1;fi++) printf("%d%d%d%d ",fr,fg,fb,fi);
    printf("\n");
    i=0;
    for(br=0;br<=1;br++) for(bg=0;bg<=1;bg++) for(bb=0;bb<=1;bb++) for(bi=0;bi<=1;bi++)
    {
        setBackgroundColor(0,0,0,0);setForegroundColor(1,1,1,1);
        printf(" %c  %d%d%d%d ",back[i],br,bg,bb,bi);i++;
        setBackgroundColor(br,bg,bb,bi);
        for(fr=0;fr<=1;fr++) for(fg=0;fg<=1;fg++) for(fb=0;fb<=1;fb++) for(fi=0;fi<=1;fi++)
        {
           setForegroundColor(fr,fg,fb,fi);
           printf(" XX ");
           setBackgroundColor(0,0,0,0);setForegroundColor(1,1,1,1); printf(" ");setBackgroundColor(br,bg,bb,bi);
        }
        printf("\n");
    }
}

#define winColors
#endif


