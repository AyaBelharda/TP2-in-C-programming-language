  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#ifndef _CONIO2_H_
#define _CONIO2_H_

#include <conio.h>
#ifdef UNICODE
#include <windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
#endif /* _CONIO2_H_ */
/**
 * Colors which you can use in your application.
 */
typedef enum
{
    BLACK,          /**< black color */
    BLUE,           /**< blue color */
    GREEN,          /**< green color */
    CYAN,           /**< cyan color */
    RED,            /**< red color */
    MAGENTA,        /**< magenta color */
    BROWN,          /**< brown color */
    LIGHTGRAY,      /**< light gray color */
    DARKGRAY,       /**< dark gray color */
    LIGHTBLUE,      /**< light blue color */
    LIGHTGREEN,     /**< light green color */
    LIGHTCYAN,      /**< light cyan color */
    LIGHTRED,       /**< light red color */
    LIGHTMAGENTA,   /**< light magenta color */
    YELLOW,         /**< yellow color */
    WHITE           /**< white color */
} COLORS;


/**
 * This defines enables you to use all MinGW conio.h functions without
 * underscore.
 */
#define cgets   _cgets
#define cprintf _cprintf
#define cputs   _cputs
#define cscanf  _cscanf

#ifdef UNICODE
    #define cgetws   _cgetws
    #define getwch   _getwch
    #define getwche  _getwche
    #define putwch   _putwch
    #define ungetwch _ungetwch
    #define cputws   _cputws
    #define cwprintf _cwprintf
    #define cwscanf  _cwscanf
#endif
/*@}*/


#ifndef _CONIO_NO_GETTEXT_
  #define gettext _conio_gettext
#endif

#define ScreenClear clrscr

/**
 * @anchor cursortypes
 * @name Cursor types
 * Predefined cursor types. */
/*@{*/
#define _NOCURSOR 0         /**< no cursor */
#define _SOLIDCURSOR 100    /**< cursor filling whole cell */
#define _NORMALCURSOR 20    /**< cursor filling 20 percent of cell height */
/*@}*/

/**
 * Structure holding information about screen.
 * @see gettextinfo
 * @see inittextinfo
 */
struct text_info {
    unsigned char curx;          /**< cursor coordinate x */
    unsigned char cury;          /**< cursor coordinate y */
    unsigned short attribute;    /**< current text attribute */
    unsigned short normattr;     /**< original value of text attribute after
                                      start of the application. If you don't
                                      called the <TT>inittextinfo</TT> on the
                                      beginning of the application, this always
                                      will be black background and light gray
                                      foreground */
    unsigned char screenwidth;   /**< screen width */
    unsigned char screenheight;  /**< screen height */
};

/**
 * Structure used by gettext/puttext.
 * @see _conio_gettext
 * @see puttext
 */
struct char_info {
#ifdef UNICODE
    wchar_t letter;        /**< character value */
#else
    char letter;           /**< character value */
#endif
    unsigned short attr;   /**< attribute value */
};

/**
 * Returns information of the screen.
 * @see text_info
 */
void gettextinfo (struct text_info * info);

/**
 * Call this if you need real value of normattr attribute in the text_info
 * structure.
 * @see text_info
 */
void inittextinfo (void);

/**
 * Clears rest of the line from cursor position to the end of line without
 * moving the cursor.
 */
void clreol (void);

/**
 * Clears whole screen.
 */
void clrscr (void);

/**
 * Delete the current line (line on which is cursor) and then moves all lines
 * below one line up. Lines below the line are moved one line up.
 */
void delline (void);

/**
 * Insert blank line at the cursor position.
 * Original content of the line and content of lines below moves one line down.
 * The last line is deleted.
 */
void insline (void);

/**
 * Gets text from the screen. If you haven't defined <TT>_CONIO_NO_GETTEXT_</TT>
 * prior to including <TT>conio2.h</TT> you can use this function also under
 * the <TT>gettext</TT> name.
 * @see char_info
 * @see puttext
 * @param left Left coordinate of the rectangle, inclusive, starting from 1.
 * @param top Top coordinate of the rectangle, inclusive, starting from 1.
 * @param right Right coordinate of the rectangle, inclusive, starting from 1.
 * @param bottom Bottom coordinate of the rectangle, inclusive, starting from 1.
 * @param buf You have to pass buffer of size
 * <TT>(right - left + 1) * (bottom - top + 1) * sizeof(char_info)</TT>.
 */
void _conio_gettext (int left, int top, int right, int bottom,
                     struct char_info * buf);

/**
 * Puts text back to the screen.
 * @see char_info
 * @see _conio_gettext
 * @param left Left coordinate of the rectangle, inclusive, starting from 1.
 * @param top Top coordinate of the rectangle, inclusive, starting from 1.
 * @param right Right coordinate of the rectangle, inclusive, starting from 1.
 * @param bottom Bottom coordinate of the rectangle, inclusive, starting from 1.
 * @param buf You have to pass buffer of size
 * <TT>(right - left + 1) * (bottom - top + 1) * sizeof(char_info)</TT>.
 */
void puttext (int left, int top, int right, int bottom, struct char_info * buf);

/**
 * Copies text.
 * @param left Left coordinate of the rectangle, inclusive, starting from 1.
 * @param top Top coordinate of the rectangle, inclusive, starting from 1.
 * @param right Right coordinate of the rectangle, inclusive, starting from 1.
 * @param bottom Bottom coordinate of the rectangle, inclusive, starting from 1.
 * @param destleft Left coordinate of the destination rectangle.
 * @param desttop Top coordinate of the destination rectangle.
 */
void movetext (int left, int top, int right, int bottom, int destleft,
              int desttop);

/**
 * Moves cursor to the specified position.
 * @param x horizontal position
 * @param y vertical position
 */
void gotoxy(int x, int y);

/**
 * Puts string at the specified position.
 * @param x horizontal position
 * @param y vertical position
 * @param str string
 */
void cputsxy (int x, int y, char * str);

/**
 * Puts char at the specified position.
 * @param x horizontal position
 * @param y vertical position
 * @param ch char
 */
void putchxy (int x, int y, char ch);

/**
 * Sets the cursor type.
 * @see @ref cursortypes
 * @param type cursor type, under Win32 it is height of the cursor in percents
 */
void _setcursortype (int type);

/**
 * Sets attribute of text.
 * @param _attr new text attribute
 */
void textattr (int _attr);

/**
 * Sets text attribute back to value it had after program start.
 * It uses text_info's normattr value.
 * @see text_info
 */
void normvideo (void);

/**
 * Sets text background color.
 * @see COLORS
 * @param color new background color
 */
void textbackground (int color);

/**
 * Sets text foreground color.
 * @see COLORS
 * @param color new foreground color
 */
void textcolor (int color);

/**
 * Reads the cursor X position.
 * @returns cursor X position
 */
int wherex (void);

/**
 * Reads the cursor Y position.
 * @returns cursor Y position
 */
int wherey (void);

/**
 * Reads password. This function behaves like cgets.
 *
 * @see cgets
 * @param prompt prompt which will be displayed to user
 * @param str string for the password. <TT>str[0]</TT> have to contain
 * length of the <TT>str</TT> - 3
 * @returns <TT>&str[2]</TT>, the password will be stored in <TT>str</TT>
 * beginning at <TT>str[2]</TT>, in <TT>str[1]</TT> will be length of the
 * string without <TT>\\0</TT>, at <TT>str[2 + str[1]]</TT> will be \\0.
 */
char * getpass (const char * prompt, char * str);

/**
 * Makes foreground colors light.
 * If the current foreground color is less than <TT>DARKGRAY</TT> adds
 * 8 to the its value making dark colors light.
 * @see COLORS
 * @see lowvideo
 */
void highvideo (void);

/**
 * Makes foreground colors dark.
 * If the current foreground color is higher than <TT>LIGHTGRAY</TT> substracts
 * 8 from its value making light colors dark.
 * @see COLORS
 * @see highvideo
 */
void lowvideo (void);

/*@{*/
/*
 * You may need to link with libmsvcr70.a or libmsvcr70d.a or libmsvcr71.a
 *  or libmsvcr71d.a if you want any of these functions.
 */
#ifdef UNICODE
_CRTIMP wchar_t * __cdecl         _cgetws(wchar_t *);
_CRTIMP unsigned short __cdecl    _getwch(void);
_CRTIMP unsigned short __cdecl    _getwche(void);
_CRTIMP unsigned short __cdecl    _putwch(wchar_t);
_CRTIMP unsigned short __cdecl    _ungetwch(unsigned short);
_CRTIMP int __cdecl               _cputws(const wchar_t *);
_CRTIMP int __cdecl               _cwprintf(const wchar_t *, ...);
_CRTIMP int __cdecl               _cwscanf(const wchar_t *, ...);
#endif
/*@}*/

/**
 * Pauses program execution for a given time.
 * @see switchbackground
 * @param ms miliseconds
 */
void delay (int ms);

/**
 * Replaces background color in the whole window. The text however
 * is left intact. Does not modify textbackground().
 * @see flashbackground
 * @param color background color
 */
void switchbackground (int color);

/**
 * Changes background color for a given time and then it restores it back.
 * You can use it for visual bell. Does not modify textbackground().
 * @see switchbackground
 * @see delay
 * @param color background color
 * @param ms miliseconds
 */
void flashbackground (int color, int ms);

/**
 * Clears the keyboard buffer.
 * To see it in effect run <TT>conio_test</TT> and try to press a key during
 * the 'Flashing...' phase.
 */
void clearkeybuf (void);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;
static struct text_info __text_info = {
    1, 1,
    LIGHTGRAY + (BLACK << 4),
    LIGHTGRAY + (BLACK << 4),
    80, 25
};
static int __CONIO_TOP = 0;
static int __CONIO_LEFT = 0;

static void
__fill_text_info (void)
{
    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    __CONIO_LEFT = info.srWindow.Left;
    __CONIO_TOP = info.srWindow.Top;
    __text_info.curx = info.dwCursorPosition.X - __CONIO_LEFT + 1;
    __text_info.cury = info.dwCursorPosition.Y - __CONIO_TOP  + 1;
    __text_info.attribute = info.wAttributes;
    __text_info.screenwidth  = info.srWindow.Right - info.srWindow.Left + 1;
    __text_info.screenheight = info.srWindow.Bottom - info.srWindow.Top + 1;
}

void
gettextinfo (struct text_info * info)
{
    __fill_text_info();
    *info = __text_info;
}

void
inittextinfo (void)
{
    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &info);
    __text_info.normattr = info.wAttributes;
}

void
clrscr (void)
{
    DWORD written;
    int i;

    __fill_text_info();
    for (i = __CONIO_TOP; i < __CONIO_TOP + __text_info.screenheight; i++) {
      FillConsoleOutputAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
        __FOREGROUND + (__BACKGROUND << 4), __text_info.screenwidth,
        (COORD) {__CONIO_LEFT, i},
        &written);
      FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
        __text_info.screenwidth,
        (COORD) {__CONIO_LEFT, i},
        &written);
    }
    gotoxy (1, 1);
}


void
clreol (void)
{
    COORD coord;
    DWORD written;

    __fill_text_info();
    coord.X = __CONIO_LEFT + __text_info.curx - 1;
    coord.Y = __CONIO_TOP  + __text_info.cury - 1;

    FillConsoleOutputAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      __FOREGROUND + (__BACKGROUND << 4),
      __text_info.screenwidth - __text_info.curx + 1, coord, &written);
    FillConsoleOutputCharacter (GetStdHandle (STD_OUTPUT_HANDLE),
      ' ', __text_info.screenwidth - __text_info.curx + 1, coord, &written);
    gotoxy (__text_info.curx, __text_info.cury);
}


void
delline (void)
{
    COORD coord;
    SMALL_RECT rect;
    CHAR_INFO fillchar;

    __fill_text_info();
    coord.X = __CONIO_LEFT;
    coord.Y = __CONIO_TOP + __text_info.cury - 1;
    rect.Left = __CONIO_LEFT;
    rect.Top = __CONIO_TOP + __text_info.cury;
    rect.Right = __CONIO_LEFT + __text_info.screenwidth - 1;
    rect.Bottom = __CONIO_TOP + __text_info.screenheight - 1;
    fillchar.Attributes = __FOREGROUND + (__BACKGROUND << 4);
#ifdef UNICODE
    fillchar.Char.UnicodeChar = L' ';
    ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#else
    fillchar.Char.AsciiChar = ' ';
    ScrollConsoleScreenBufferA (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#endif


    gotoxy (__text_info.curx, __text_info.cury);
}

void
insline (void)
{
    COORD coord;
    SMALL_RECT rect;
    CHAR_INFO fillchar;

    __fill_text_info();
    coord.X = __CONIO_LEFT;
    coord.Y = __CONIO_TOP + __text_info.cury;
    rect.Left = __CONIO_LEFT;
    rect.Top = __CONIO_TOP + __text_info.cury - 1;
    rect.Right = __CONIO_LEFT + __text_info.screenwidth - 1;
    rect.Bottom = __CONIO_TOP + __text_info.screenheight - 2;
    fillchar.Attributes = __FOREGROUND + (__BACKGROUND << 4);
#ifdef UNICODE
    fillchar.Char.UnicodeChar = L' ';
    ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#else
    fillchar.Char.AsciiChar = ' ';
    ScrollConsoleScreenBufferA (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#endif

    gotoxy (__text_info.curx, __text_info.cury);
}

void
movetext (int left, int top, int right, int bottom, int destleft, int desttop)
{
    struct char_info * buffer;

    buffer = malloc ((right - left + 1) * (bottom - top + 1) * sizeof(struct char_info));
    gettext (left, top, right, bottom, buffer);
    puttext (destleft, desttop, destleft + right - left, desttop + bottom - top, buffer);
    free(buffer);
}

void
_conio_gettext (int left, int top, int right, int bottom,
  struct char_info * buf)
{
    int i;
    SMALL_RECT r;
    CHAR_INFO* buffer;
    COORD size;

    __fill_text_info();
    r = (SMALL_RECT) {__CONIO_LEFT + left - 1, __CONIO_TOP + top - 1,
      __CONIO_LEFT + right - 1, __CONIO_TOP + bottom - 1};
    size.X = right - left + 1;
    size.Y = bottom - top + 1;
    buffer = malloc (size.X * size.Y * sizeof(CHAR_INFO));

    ReadConsoleOutput (GetStdHandle (STD_OUTPUT_HANDLE),
      (PCHAR_INFO) buffer, size, (COORD) {0, 0}, &r);

    for (i = 0; i < size.X * size.Y; i++)
    {
#ifdef UNICODE
        buf[i].letter = buffer[i].Char.UnicodeChar;
#else
        buf[i].letter = buffer[i].Char.AsciiChar;
#endif
        buf[i].attr = buffer[i].Attributes;
    }
    free (buffer);
}

void
puttext (int left, int top, int right, int bottom, struct char_info * buf)
{
    int i;
    SMALL_RECT r;
    CHAR_INFO* buffer;
    COORD size;

    __fill_text_info();
    r = (SMALL_RECT) {__CONIO_LEFT + left - 1, __CONIO_TOP + top - 1,
      __CONIO_LEFT + right - 1, __CONIO_TOP + bottom - 1};
    size.X = right - left + 1;
    size.Y = bottom - top + 1;
    buffer = malloc (size.X * size.Y * sizeof(CHAR_INFO));

    for (i = 0; i < size.X * size.Y; i++)
    {
#ifdef UNICODE
        buffer[i].Char.UnicodeChar = buf[i].letter;
#else
        buffer[i].Char.AsciiChar = buf[i].letter;
#endif
        buffer[i].Attributes = buf[i].attr;
    }

    WriteConsoleOutput (GetStdHandle (STD_OUTPUT_HANDLE),
      buffer, size, (COORD) {0, 0}, &r);
    free (buffer);
}

void
gotoxy(int x, int y)
{
  COORD c;

  c.X = __CONIO_LEFT + x - 1;
  c.Y = __CONIO_TOP  + y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void
cputsxy (int x, int y, char * str)
{
    gotoxy (x, y);
    cputs (str);
}

void
putchxy (int x, int y, char ch)
{
    gotoxy (x, y);
    putch (ch);
}

void
_setcursortype (int type)
{
    CONSOLE_CURSOR_INFO Info;

    if (type == 0) {
        Info.bVisible = FALSE;
    } else {
      Info.dwSize = type;
      Info.bVisible = TRUE;
    }
    SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE),
      &Info);
}


void
textattr (int _attr)
{
    __FOREGROUND = _attr & 0xF;
    __BACKGROUND = _attr >> 4;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), _attr);
}

void
normvideo (void)
{
    textattr (__text_info.normattr);
}

void
textbackground (int color)
{
    __BACKGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      __FOREGROUND + (color << 4));
}


void
textcolor (int color)
{
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      color + (__BACKGROUND << 4));
}


int
wherex (void)
{
    __fill_text_info();
    return __text_info.curx;
}


int
wherey (void)
{
    __fill_text_info();
    return __text_info.cury;
}

char *
getpass (const char * prompt, char * str)
{
    int maxlength = str[0];
    int length = 0;
    int ch = 0;
    int x, y;

    cputs(prompt);
    __fill_text_info();
    x = __text_info.curx;
    y = __text_info.cury;

    while (ch != '\r') {
        ch = getch();
        switch (ch) {
            case '\r' : /* enter */
                break;
            case '\b' : /* backspace */
                if (length > 0) putchxy (x + --length, y, ' ');
                gotoxy (x + length, y);
                break;
            default:
                if (length < maxlength) {
                    putchxy (x + length, y, '*');
                    str[2 + length++] = ch;
                }
        }
    }

    str[1] = length;
    str[2 + length] = '\0';
    return &str[2];
}

void
highvideo (void)
{
    if (__FOREGROUND < DARKGRAY) textcolor(__FOREGROUND + 8);
}

void
lowvideo (void)
{
    if (__FOREGROUND > LIGHTGRAY) textcolor(__FOREGROUND - 8);
}

void
delay (int ms)
{
    Sleep(ms);
}

void
switchbackground (int color)
{
    struct char_info* buffer;
    int i;

    buffer = malloc(__text_info.screenwidth * __text_info.screenheight *
      sizeof(struct char_info));
    _conio_gettext(1, 1, __text_info.screenwidth, __text_info.screenheight,
      buffer);
    for (i = 0; i < __text_info.screenwidth * __text_info.screenheight; i++) {
        unsigned short attr = buffer[i].attr & 0xF;
        buffer[i].attr = (color << 4) | attr;
    }
    puttext(1, 1, __text_info.screenwidth, __text_info.screenheight, buffer);
    free(buffer);
}

void
flashbackground (int color, int ms)
{
    struct char_info* buffer;

    buffer = malloc(__text_info.screenwidth * __text_info.screenheight *
      sizeof(struct char_info));
    _conio_gettext(1, 1, __text_info.screenwidth, __text_info.screenheight,
      buffer);
    switchbackground(color);
    delay(ms);
    puttext(1, 1, __text_info.screenwidth, __text_info.screenheight, buffer);
    free(buffer);
}

void
clearkeybuf (void)
{
    while (kbhit()) {
        getch();
    }
}

#ifdef __cplusplus
}
#endif

void Speak(char *discours) { //procédure qui auditionne une chaine de caractères
    char chaine[256];
    sprintf(chaine, "echo m=\"%s\" > file.vbs", discours);
    system(chaine);
    sprintf(chaine, "echo CreateObject(\"SAPI.SpVoice\").Speak m >> file.vbs");
    system(chaine);
    sprintf(chaine, "file.vbs");
    system(chaine);
    remove("file.vbs");
}


  typedef int bool ;
  typedef char * string255 ;

  #define True 1
  #define False 0

  /** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tss Type_Tss  ;
  typedef Type_Tss * Typestr_Tss ;
  typedef string255 Type1_Tss  ;
  typedef string255 Type2_Tss  ;
  struct Tss
    {
      Type1_Tss Champ1 ;
      Type2_Tss Champ2 ;
    };

  Type1_Tss Struct1_Tss ( Typestr_Tss S)
    {
      return  S->Champ1 ;
    }

  Type2_Tss Struct2_Tss ( Typestr_Tss S)
    {
      return  S->Champ2 ;
    }

  void Aff_struct1_Tss ( Typestr_Tss S, Type1_Tss Val )
    {
      strcpy( S->Champ1 , Val );
    }

  void Aff_struct2_Tss ( Typestr_Tss S, Type2_Tss Val )
    {
      strcpy( S->Champ2 , Val );
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tss Typeelem_ATss   ;
  typedef struct Noeud_ATss * Pointeur_ATss ;

  struct Noeud_ATss
    {
      Typeelem_ATss  Val ;
      Pointeur_ATss Fg ;
      Pointeur_ATss Fd ;
      Pointeur_ATss Pere ;
     } ;

  Typeelem_ATss Info_ATss( Pointeur_ATss P )
    { return P->Val;   }

  Pointeur_ATss Fg_ATss( Pointeur_ATss P)
    { return P->Fg ; }

  Pointeur_ATss Fd_ATss( Pointeur_ATss P)
    { return P->Fd ; }

  Pointeur_ATss Pere_ATss( Pointeur_ATss P)
    { return P->Pere ; }

  void Aff_info_ATss ( Pointeur_ATss P, Typeelem_ATss Val)
    {
      Typeelem_ATss _Temp ;
      _Temp = malloc(sizeof(Type_Tss));
      _Temp->Champ1 = malloc(255 * sizeof(char));
      _Temp->Champ2 = malloc(255 * sizeof(char));
      /* Affectation globale de structure */
      strcpy(_Temp->Champ1, Val->Champ1);
      strcpy(_Temp->Champ2, Val->Champ2);
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATss( Pointeur_ATss P, Pointeur_ATss Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATss( Pointeur_ATss P, Pointeur_ATss Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATss( Pointeur_ATss P, Pointeur_ATss Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATss( Pointeur_ATss *P)
    {
      *P = (struct Noeud_ATss *) malloc( sizeof( struct Noeud_ATss))   ;
      (*P)->Val = malloc(sizeof(Type_Tss));
      (*P)->Val->Champ1 = malloc( 255 * sizeof(char));
      (*P)->Val->Champ2 = malloc( 255 * sizeof(char));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATss( Pointeur_ATss P)
    { free( P ) ; }


  /** Implémentation **\: TABLEAU DE CHAINES DE CARACTERES**/

  /** Tableaux **/

  typedef string255 Typeelem_V16s ;
  typedef Typeelem_V16s * Typevect_V16s ;

  Typeelem_V16s Element_V16s ( Typevect_V16s V , int I1  )
    {
      return  *(V +  (I1-1)  ) ;
    }

  void Aff_element_V16s ( Typevect_V16s V  , int I1 ,  Typeelem_V16s Val )
    {
     strcpy( *(V +  (I1-1)  ) , Val );
    }


  /** Implémentation **\: TABLEAU DE CHAINES DE CARACTERES**/

  /** Tableaux **/

  typedef string255 Typeelem_V8_4s ;
  typedef Typeelem_V8_4s * Typevect_V8_4s ;

  Typeelem_V8_4s Element_V8_4s ( Typevect_V8_4s V , int I1 , int I2 )
    {
      return  *(V +  (I1-1)*4 + (I2-1)  ) ;
    }

  void Aff_element_V8_4s ( Typevect_V8_4s V  , int I1 , int I2,  Typeelem_V8_4s Val )
    {
     strcpy( *(V +  (I1-1)*4 + (I2-1)  ) , Val );
    }


  /** Implémentation **\: TABLEAU DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tsi Type_Tsi  ;
  typedef Type_Tsi * Typestr_Tsi ;
  typedef string255 Type1_Tsi  ;
  typedef int Type2_Tsi  ;
  struct Tsi
    {
      Type1_Tsi Champ1 ;
      Type2_Tsi Champ2 ;
    };

  Type1_Tsi Struct1_Tsi ( Typestr_Tsi S)
    {
      return  S->Champ1 ;
    }

  Type2_Tsi Struct2_Tsi ( Typestr_Tsi S)
    {
      return  S->Champ2 ;
    }

  void Aff_struct1_Tsi ( Typestr_Tsi S, Type1_Tsi Val )
    {
      strcpy( S->Champ1 , Val );
    }

  void Aff_struct2_Tsi ( Typestr_Tsi S, Type2_Tsi Val )
    {
       S->Champ2 = Val ;
    }


  /** Tableaux **/

  typedef Typestr_Tsi Typeelem_V4Tsi ;
  typedef Typeelem_V4Tsi * Typevect_V4Tsi ;

  Typeelem_V4Tsi Element_V4Tsi ( Typevect_V4Tsi V , int I1  )
    {
      return  *(V +  (I1-1)  ) ;
    }

  void Aff_element_V4Tsi ( Typevect_V4Tsi V  , int I1 ,  Typeelem_V4Tsi Val )
    {
      Typeelem_V4Tsi _Temp ;
      _Temp = malloc(sizeof(Type_Tsi));
      _Temp->Champ1 = malloc(255 * sizeof(char));
      /* Affectation globale de structure */
      strcpy(_Temp->Champ1, Val->Champ1);
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
      *(V +  (I1-1)  ) = Val ;
    }


  /** Implémentation **\: TABLEAU DE CHAINES DE CARACTERES**/

  /** Tableaux **/

  typedef string255 Typeelem_V8s ;
  typedef Typeelem_V8s * Typevect_V8s ;

  Typeelem_V8s Element_V8s ( Typevect_V8s V , int I1  )
    {
      return  *(V +  (I1-1)  ) ;
    }

  void Aff_element_V8s ( Typevect_V8s V  , int I1 ,  Typeelem_V8s Val )
    {
     strcpy( *(V +  (I1-1)  ) , Val );
    }


  /** Implémentation **\: TABLEAU DE ENTIERS**/

  /** Tableaux **/

  typedef int Typeelem_V4i ;
  typedef Typeelem_V4i * Typevect_V4i ;

  Typeelem_V4i Element_V4i ( Typevect_V4i V , int I1  )
    {
      return  *(V +  (I1-1)  ) ;
    }

  void Aff_element_V4i ( Typevect_V4i V  , int I1 ,  Typeelem_V4i Val )
    {
      *(V +  (I1-1)  ) = Val ;
    }


  /** Implémentation **\: LISTE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tsisi Type_Tsisi  ;
  typedef Type_Tsisi * Typestr_Tsisi ;
  typedef string255 Type1_Tsisi  ;
  typedef int Type2_Tsisi  ;
  typedef string255 Type3_Tsisi  ;
  typedef int Type4_Tsisi  ;
  struct Tsisi
    {
      Type1_Tsisi Champ1 ;
      Type2_Tsisi Champ2 ;
      Type3_Tsisi Champ3 ;
      Type4_Tsisi Champ4 ;
    };

  Type1_Tsisi Struct1_Tsisi ( Typestr_Tsisi S)
    {
      return  S->Champ1 ;
    }

  Type2_Tsisi Struct2_Tsisi ( Typestr_Tsisi S)
    {
      return  S->Champ2 ;
    }

  Type3_Tsisi Struct3_Tsisi ( Typestr_Tsisi S)
    {
      return  S->Champ3 ;
    }

  Type4_Tsisi Struct4_Tsisi ( Typestr_Tsisi S)
    {
      return  S->Champ4 ;
    }

  void Aff_struct1_Tsisi ( Typestr_Tsisi S, Type1_Tsisi Val )
    {
      strcpy( S->Champ1 , Val );
    }

  void Aff_struct2_Tsisi ( Typestr_Tsisi S, Type2_Tsisi Val )
    {
       S->Champ2 = Val ;
    }

  void Aff_struct3_Tsisi ( Typestr_Tsisi S, Type3_Tsisi Val )
    {
      strcpy( S->Champ3 , Val );
    }

  void Aff_struct4_Tsisi ( Typestr_Tsisi S, Type4_Tsisi Val )
    {
       S->Champ4 = Val ;
    }


  /** Listes lin?aires cha?n?es **/

  typedef Typestr_Tsisi Typeelem_LTsisi   ;
  typedef struct Maillon_LTsisi * Pointeur_LTsisi ;

  struct Maillon_LTsisi
    {
      Typeelem_LTsisi  Val ;
      Pointeur_LTsisi Suiv ;
    } ;

  Pointeur_LTsisi Allouer_LTsisi (Pointeur_LTsisi *P)
    {
      *P = (struct Maillon_LTsisi *) malloc( sizeof( struct Maillon_LTsisi)) ;
      (*P)->Val = malloc(sizeof(Type_Tsisi));
      (*P)->Val->Champ1 = malloc( 255 * sizeof(char));
      (*P)->Val->Champ3 = malloc( 255 * sizeof(char));
      (*P)->Suiv = NULL;
    }

  void Aff_val_LTsisi(Pointeur_LTsisi P, Typeelem_LTsisi Val)
    {
      Typeelem_LTsisi _Temp ;
      _Temp = malloc(sizeof(Type_Tsisi));
      _Temp->Champ1 = malloc(255 * sizeof(char));
      _Temp->Champ3 = malloc(255 * sizeof(char));
      /* Affectation globale de structure */
      strcpy(_Temp->Champ1, Val->Champ1);
      _Temp->Champ2 = Val->Champ2;
      strcpy(_Temp->Champ3, Val->Champ3);
      _Temp->Champ4 = Val->Champ4;
      Val = _Temp ;
      P->Val = Val ;
    }

  void Aff_adr_LTsisi( Pointeur_LTsisi P,  Pointeur_LTsisi Q)
    {
      P->Suiv = Q ;
    }

  Pointeur_LTsisi Suivant_LTsisi(  Pointeur_LTsisi P)
    { return( P->Suiv ) ;  }

  Typeelem_LTsisi Valeur_LTsisi( Pointeur_LTsisi P)
    { return( P->Val) ; }

  void Liberer_LTsisi ( Pointeur_LTsisi P)
    { free (P);}

  /** Pour les variables temporaires **/
  typedef Typeelem_V4i Typetab_V4i[4];


  /** Implémentation **\: FILE DE STRUCTURES**/
  /** Files d'attente **/

  typedef Typestr_Tss Typeelem_FTss ;
  typedef  struct Filedattente_FTss * Pointeur_FTss ;
  typedef  struct Maillon_FTss * Ptliste_FTss ;

  struct Maillon_FTss
    {
      Typeelem_FTss Val ;
      Ptliste_FTss Suiv  ;
    };

  struct Filedattente_FTss
    {
      Ptliste_FTss Tete, Queue ;
    };

  void Creerfile_FTss ( Pointeur_FTss *Fil   )
    {
      *Fil = (struct Filedattente_FTss *) malloc( sizeof( struct Filedattente_FTss)) ;
      (*Fil)->Tete = NULL ;
      (*Fil)->Queue = NULL ;
    }

  bool Filevide_FTss (Pointeur_FTss Fil  )
    { return  Fil->Tete == NULL ;}

  void Enfiler_FTss ( Pointeur_FTss Fil , Typeelem_FTss Val   )
    {
      Ptliste_FTss Q;

      Q = (struct Maillon_FTss *) malloc( sizeof( struct Maillon_FTss))   ;
      Q->Val = malloc(sizeof(Type_Tss));
      Q->Val->Champ1 = malloc( 255 * sizeof(char));
      Q->Val->Champ2 = malloc( 255 * sizeof(char));
      Typeelem_FTss _Temp ;
      _Temp = malloc(sizeof(Type_Tss));
      _Temp->Champ1 = malloc(255 * sizeof(char));
      _Temp->Champ2 = malloc(255 * sizeof(char));
      /* Affectation globale de structure */
      strcpy(_Temp->Champ1, Val->Champ1);
      strcpy(_Temp->Champ2, Val->Champ2);
      Val = _Temp ;
      Q->Val = Val ;
      Q->Suiv = NULL;
      if ( ! Filevide_FTss(Fil) )
        Fil->Queue->Suiv = Q ;
      else Fil->Tete = Q;
        Fil->Queue = Q;
    }

  void Defiler_FTss (Pointeur_FTss Fil, Typeelem_FTss *Val )
    {
      if (! Filevide_FTss(Fil) )
        {
          *Val = Fil->Tete->Val ;
          Fil->Tete =  Fil->Tete->Suiv;
        }
      else printf ("%s \n", "File d'attente vide");
    }


  /** Variables du programme principal **/
  int Rep;
  Pointeur_ATss R=NULL;
  Typevect_V16s Tabl;

  /** Fonctions standards **/

  int Mod( int a, int b)
    { return ( a % b ); }

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** Initialisation d'un tableau **/
  void Init_vect_V4i (  Typevect_V4i T , Typetab_V4i Tab , int N)
    {
      int K=-1;
     int I1 ;
     for (I1=0; I1< 4; ++I1)
        {
          K++;
         *(T +  I1  ) = Tab [K] ;
        }
    }


  /** Prototypes des fonctions **/

  void Phase1(); //simulation complète de la phase 1 avec toutes ses options
  void Init32 (Typevect_V8_4s *Tg); //initialiser le tableau des équipes qui participent triées selon le classement de la FIFA 2022
  void Hasard1 (Typevect_V16s *Tm);//affichages des équipes qualifiées dans la phase 1 au hasard
  void Fav_pre1 (Typevect_V16s *Tm);//affichage des équipes qualifiées (favorites) dans la phase 1 selon le classement de la FIFA 2022
  void Fav_pre12 (Pointeur_ATss *R);//affichage des équipes qualifiées (favorites) dans la phase 2 selon le classement de la FIFA 2022
  void Hasard11 (Typevect_V16s *Tm);//affichages des équipes qualifiées dans la phase 2 au hasard
  void Fav();//affichage des résultats selon l'équipe favorite saisie par l'utilisateur (qui se qualifie toujours) dans la phase 1
  void Moins_fav();//affichage des résultats selon l'équipes moins favorite saisie par l'utilisateur (qui se ne se qualifiejamais) dans la phase 1
  void Points (int *A , int *B);//générer les points de toutes les rencontres de la phase 1
  void Fav_grp();//affichage des résultats selon les équipes favorites de chaque groupe toutes saisies par l'utilisateur (qui se qualifient toujours) dans la phase 1
  void Moins_fav_grp();//affichage des résultats selon les équipes moins favorites de chaque groupe toutes saisies par l'utilisateur (qui ne se qualifient jamais) dans la phase 1
  void Aff();//affichage de toutes les rencontres de la phase 1
  void Phase2();//simulation complète de la phase 2 avec toutes ses options
  string255  Gagnant (string255 *E1 , string255 *E2) ;//seléctionner un gagnant parmi deux avec un pourcentage de gain de 50% chacun
  void Hasard12 (Pointeur_ATss *R);//affichages des équipes qualifiées dans la phase 2 au hasard et selon les résultats de la phase 2
  void Fav12 (Pointeur_ATss *R);//affichage des résultats selon l'équipe favorite saisie par l'utilisateur (qui se qualifie toujours) dans la phase 2 et selon les résultats aléatoires de la phase 1
  void Aff1 (Pointeur_ATss *R);//affichage de toutes les rencontres de la phase 2
  void M_fav12 (Pointeur_ATss *R);//affichage des résultats selon les équipes moins favorites de chaque groupe toutes saisies par l'utilisateur (qui ne se qualifient jamais) dans la phase 2 et selon les résultats aléatoires de la phase 1
  void Menu (int *Ans);//la procédure du menu de la phase 1
  void Menu2 (int *Ans);//la procédure du menu de la phase 2
  void Menuglobal (int *N);//la procédure du programme principal


  /*CETTE MATRICE CONTIENT LES 8 GROUPES DE LA COUPE DU MONDE 2022*/

  /*CHAQUE COLONNE CONTIENT LES 4 EQUIPES DE CHAQUE GROUPE*/

  /*LES EQUIPES DE CHAQUE GROUPE SONT TRIEES SELON LE CLASSEMENT MONDIAL DE LA FIFA 2022*/

  void Init32 (Typevect_V8_4s *Tg)
    {

      /** Corps du module **/
     Aff_element_V8_4s ( *Tg , 1 , 1   , "PAYS-BAS " ) ;
     Aff_element_V8_4s ( *Tg , 1 , 2   , "SENEGAL" ) ;
     Aff_element_V8_4s ( *Tg , 1 , 3   , "EQUATEUR" ) ;
     Aff_element_V8_4s ( *Tg , 1 , 4   , "QATAR" ) ;
     Aff_element_V8_4s ( *Tg , 2 , 1   , "ANGLETERRE" ) ;
     Aff_element_V8_4s ( *Tg , 2 , 2   , "ETATS-UNIS" ) ;
     Aff_element_V8_4s ( *Tg , 2 , 3   , "PAYS-DE-GALLE" ) ;
     Aff_element_V8_4s ( *Tg , 2 , 4   , "IRAN" ) ;
     Aff_element_V8_4s ( *Tg , 3 , 1   , "ARGENTINE" ) ;
     Aff_element_V8_4s ( *Tg , 3 , 2   , "MEXIQUE " ) ;
     Aff_element_V8_4s ( *Tg , 3 , 3   , "POLOGNE" ) ;
     Aff_element_V8_4s ( *Tg , 3 , 4   , "ARABIE-SAOUDITE" ) ;
     Aff_element_V8_4s ( *Tg , 4 , 1   , "FRANCE" ) ;
     Aff_element_V8_4s ( *Tg , 4 , 2   , "DANEMARK" ) ;
     Aff_element_V8_4s ( *Tg , 4 , 3   , "TUNISIE" ) ;
     Aff_element_V8_4s ( *Tg , 4 , 4   , "AUSTRALIE" ) ;
     Aff_element_V8_4s ( *Tg , 5 , 1   , "ESPAGNE" ) ;
     Aff_element_V8_4s ( *Tg , 5 , 2   , "ALLEMAGNE" ) ;
     Aff_element_V8_4s ( *Tg , 5 , 3   , "JAPON" ) ;
     Aff_element_V8_4s ( *Tg , 5 , 4   , "NOUVELLE-ZELANDE" ) ;
     Aff_element_V8_4s ( *Tg , 6 , 1   , "BELGIQUE" ) ;
     Aff_element_V8_4s ( *Tg , 6 , 2   , "CROATIE" ) ;
     Aff_element_V8_4s ( *Tg , 6 , 3   , "MAROC" ) ;
     Aff_element_V8_4s ( *Tg , 6 , 4   , "CANADA" ) ;
     Aff_element_V8_4s ( *Tg , 7 , 1   , "BRESIL" ) ;
     Aff_element_V8_4s ( *Tg , 7 , 2   , "SUISSE" ) ;
     Aff_element_V8_4s ( *Tg , 7 , 3   , "SERBIE" ) ;
     Aff_element_V8_4s ( *Tg , 7 , 4   , "CAMEROUN" ) ;
     Aff_element_V8_4s ( *Tg , 8 , 1   , "PORTUGAL" ) ;
     Aff_element_V8_4s ( *Tg , 8 , 2   , "URUGUAY" ) ;
     Aff_element_V8_4s ( *Tg , 8 , 3   , "COREE-DU-SUD" ) ;
     Aff_element_V8_4s ( *Tg , 8 , 4   , "GHANA" ) ;

    }
  void Hasard1 (Typevect_V16s *Tm)
    {
      /** Variables locales **/
      Typevect_V8_4s Tg;
      Typevect_V4Tsi Td;
      Typevect_V8s Te1;
      Typevect_V8s Te2;
      Typevect_V4i Tc;
      Typestr_Tsi S1;
      Typestr_Tsi S2;
      Typestr_Tsi Tmp;
      int Jj;
      int A;
      int B;
      int I;
      int J;
      int M;
      int K;
      int N;
      int U;
      int C;
      Pointeur_LTsisi Tete=NULL;
      Pointeur_LTsisi P=NULL;
      Pointeur_LTsisi Q=NULL;
      Pointeur_LTsisi L=NULL;
      Typestr_Tsisi S;
        Typetab_V4i T_Tc;
      int _Izw;  /** Variable de contrôle **/

      /** Corps du module **/
     Tg = malloc(8*4 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<8*4; ++_Izw2)
       Tg[_Izw2]= malloc(255 * sizeof(char));
     Td = malloc(4 * sizeof(Typestr_Tsi));
     int _Izw3;for (_Izw3=0; _Izw3<4; ++_Izw3)
       Td[_Izw3] = malloc( sizeof(Type_Tsi ));
     int _Izw4;for (_Izw4=0; _Izw4<4; ++_Izw4){
       Td[_Izw4]->Champ1= malloc(255 * sizeof(char));}
     Te1 = malloc(8 * 255  * sizeof(char));
     int _Izw5;for (_Izw5=0; _Izw5<8; ++_Izw5)
       Te1[_Izw5]= malloc(255 * sizeof(char));
     Te2 = malloc(8 * 255  * sizeof(char));
     int _Izw6;for (_Izw6=0; _Izw6<8; ++_Izw6)
       Te2[_Izw6]= malloc(255 * sizeof(char));
     Tc = malloc(4 * sizeof(int));
     S1 = malloc(sizeof(Type_Tsi));
     S1->Champ1 = malloc(255 * sizeof(char));
     S2 = malloc(sizeof(Type_Tsi));
     S2->Champ1 = malloc(255 * sizeof(char));
     Tmp = malloc(sizeof(Type_Tsi));
     Tmp->Champ1 = malloc(255 * sizeof(char));
     S = malloc(sizeof(Type_Tsisi));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ3 = malloc(255 * sizeof(char));
     Jj  =  1 ;
    /*INITIALISATION DU TABLEAU DES EQUIPES*/
     Init32 ( & Tg ) ;
     Aff_struct1_Tsisi ( S  , "PAYS-BAS" ) ;
     Aff_struct3_Tsisi ( S  , "SENEGAL" ) ;
     Aff_struct2_Tsisi ( S  , 1 ) ;
     Aff_struct4_Tsisi ( S  , 2 ) ;
     Allouer_LTsisi (& P ) ;
     Aff_val_LTsisi ( P , S ) ;
     Tete  =  P ;
     Q  =  P ;
     for( M  =  1 ;M <=  8 ; ++M){
       T_Tc [ 0 ] = 0 ;
       T_Tc [ 1 ] = 0 ;
       T_Tc [ 2 ] = 0 ;
       T_Tc [ 3 ] = 0 ;
       Init_vect_V4i ( Tc , T_Tc , 4 )  ;
       for( I  =  1 ;I <=  4 ; ++I){
         for( J  =  I + 1 ;J <=  4 ; ++J){
           Aff_struct1_Tsisi ( S  , Element_V8_4s ( Tg , M , I   ) ) ;
           Aff_struct3_Tsisi ( S  , Element_V8_4s ( Tg , M , J   ) ) ;
           A  =  I ;
           B  =  J ;
           Points ( & A , & B ) ;
          /*GENERATION ALEATOIRE DES POINTS*/
           Aff_struct2_Tsisi ( S  , A ) ;
           Aff_struct4_Tsisi ( S  , B ) ;
           Allouer_LTsisi (& P ) ;
           Aff_val_LTsisi ( P , S ) ;
           Aff_adr_LTsisi ( Q , P ) ;
           Q  =  P ;
           Aff_element_V4i ( Tc , I   , Element_V4i ( Tc , I   ) + Struct2_Tsisi ( S  ) ) ;
           Aff_element_V4i ( Tc , J   , Element_V4i ( Tc , J   ) + Struct4_Tsisi ( S  ) ) ;

         } ;

       } ;
       Aff_adr_LTsisi ( Q , NULL ) ;
       for( K  =  1 ;K <=  4 ; ++K){
         Aff_struct1_Tsi ( S2  , Element_V8_4s ( Tg , M , K   ) ) ;
         Aff_struct2_Tsi ( S2  , Element_V4i ( Tc , K   ) ) ;
         Aff_element_V4Tsi ( Td , K   , S2 ) ;

       } ;
       for( U  =  1 ;U <=  4 ; ++U){
         N  =  1 ;
         while( N < 4)  {
           if( Element_V4i ( Tc , N   ) > Element_V4i ( Tc , N + 1   )) {
             C  =  Element_V4i ( Tc , N   ) ;
             Aff_element_V4i ( Tc , N   , Element_V4i ( Tc , N + 1   ) ) ;
             Aff_element_V4i ( Tc , N + 1   , C ) ;
      /* Affectation globale de structure */
             strcpy(Tmp->Champ1,   Element_V4Tsi ( Td , N   )->Champ1);
             Tmp->Champ2 =   Element_V4Tsi ( Td , N   )->Champ2;
 ;
             Aff_element_V4Tsi ( Td , N   , Element_V4Tsi ( Td , N + 1   ) ) ;
             Aff_element_V4Tsi ( Td , N + 1   , Tmp ) ;

           } ;
           N  =  N + 1 ;

         } ;

       } ;
       Aff_element_V8s ( Te1 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 4   )  ) ) ;
       Aff_element_V8s ( Te2 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 3   )  ) ) ;
       Jj  =  Jj + 1 ;

     } ;
     Aff_element_V16s ( *Tm , 1   , Element_V8s ( Te1 , 1   ) ) ;
     Aff_element_V16s ( *Tm , 2   , Element_V8s ( Te2 , 2   ) ) ;
     Aff_element_V16s ( *Tm , 3   , Element_V8s ( Te1 , 2   ) ) ;
     Aff_element_V16s ( *Tm , 4   , Element_V8s ( Te2 , 1   ) ) ;
     Aff_element_V16s ( *Tm , 5   , Element_V8s ( Te1 , 3   ) ) ;
     Aff_element_V16s ( *Tm , 6   , Element_V8s ( Te2 , 4   ) ) ;
     Aff_element_V16s ( *Tm , 7   , Element_V8s ( Te1 , 4   ) ) ;
     Aff_element_V16s ( *Tm , 8   , Element_V8s ( Te2 , 3   ) ) ;
     Aff_element_V16s ( *Tm , 9   , Element_V8s ( Te1 , 5   ) ) ;
     Aff_element_V16s ( *Tm , 10   , Element_V8s ( Te2 , 6   ) ) ;
     Aff_element_V16s ( *Tm , 11   , Element_V8s ( Te1 , 6   ) ) ;
     Aff_element_V16s ( *Tm , 12   , Element_V8s ( Te2 , 5   ) ) ;
     Aff_element_V16s ( *Tm , 13   , Element_V8s ( Te1 , 7   ) ) ;
     Aff_element_V16s ( *Tm , 14   , Element_V8s ( Te2 , 8   ) ) ;
     Aff_element_V16s ( *Tm , 15   , Element_V8s ( Te1 , 8   ) ) ;
     Aff_element_V16s ( *Tm , 16   , Element_V8s ( Te2 , 7   ) ) ;
     for( Jj  =  1 ;Jj <=  8 ; ++Jj){
       textcolor(6);
       printf ( "%s", "\n\n\t  GROUPE:" );
       printf ( " %d", Jj ) ;
       textcolor(15);
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE1:" );
       printf ( " %s", Element_V8s(Te1,Jj) ) ;
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE2:" );
       printf ( " %s", Element_V8s(Te2,Jj) ) ;

     } ;

    }
  void Fav_pre1 (Typevect_V16s *Tm)
    {
      /** Variables locales **/
      Typevect_V8_4s Tg;
      Typevect_V4Tsi Td;
      Typevect_V8s Te1;
      Typevect_V8s Te2;
      Typevect_V4i Tc;
      Typestr_Tsi S1;
      Typestr_Tsi S2;
      Typestr_Tsi Tmp;
      int Jj;
      int A;
      int B;
      int I;
      int J;
      int X;
      int T;
      int M;
      int K;
      int N;
      int U;
      int C;
      int D;
      Pointeur_LTsisi Tete=NULL;
      Pointeur_LTsisi P=NULL;
      Pointeur_LTsisi Q=NULL;
      Pointeur_LTsisi L=NULL;
      Typestr_Tsisi S;
        Typetab_V4i T_Tc;

      /** Corps du module **/
     Tg = malloc(8*4 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<8*4; ++_Izw2)
       Tg[_Izw2]= malloc(255 * sizeof(char));
     Td = malloc(4 * sizeof(Typestr_Tsi));
     int _Izw3;for (_Izw3=0; _Izw3<4; ++_Izw3)
       Td[_Izw3] = malloc( sizeof(Type_Tsi ));
     int _Izw4;for (_Izw4=0; _Izw4<4; ++_Izw4){
       Td[_Izw4]->Champ1= malloc(255 * sizeof(char));}
     Te1 = malloc(8 * 255  * sizeof(char));
     int _Izw5;for (_Izw5=0; _Izw5<8; ++_Izw5)
       Te1[_Izw5]= malloc(255 * sizeof(char));
     Te2 = malloc(8 * 255  * sizeof(char));
     int _Izw6;for (_Izw6=0; _Izw6<8; ++_Izw6)
       Te2[_Izw6]= malloc(255 * sizeof(char));
     Tc = malloc(4 * sizeof(int));
     S1 = malloc(sizeof(Type_Tsi));
     S1->Champ1 = malloc(255 * sizeof(char));
     S2 = malloc(sizeof(Type_Tsi));
     S2->Champ1 = malloc(255 * sizeof(char));
     Tmp = malloc(sizeof(Type_Tsi));
     Tmp->Champ1 = malloc(255 * sizeof(char));
     S = malloc(sizeof(Type_Tsisi));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ3 = malloc(255 * sizeof(char));
     Jj  =  1 ;
    /*INITIALISATION DU TABLEAU DES EQUIPES*/
     Init32 ( & Tg ) ;
     Aff_struct1_Tsisi ( S  , "PAYS-BAS" ) ;
     Aff_struct3_Tsisi ( S  , "SENEGAL" ) ;
     Aff_struct2_Tsisi ( S  , 1 ) ;
     Aff_struct4_Tsisi ( S  , 2 ) ;
     Allouer_LTsisi (& P ) ;
     Aff_val_LTsisi ( P , S ) ;
     Tete  =  P ;
     Q  =  P ;
     for( M  =  1 ;M <=  8 ; ++M){
       T_Tc [ 0 ] = 0 ;
       T_Tc [ 1 ] = 0 ;
       T_Tc [ 2 ] = 0 ;
       T_Tc [ 3 ] = 0 ;
       Init_vect_V4i ( Tc , T_Tc , 4 )  ;
       for( I  =  1 ;I <=  4 ; ++I){
         for( J  =  I + 1 ;J <=  4 ; ++J){
           Aff_struct1_Tsisi ( S  , Element_V8_4s ( Tg , M , I   ) ) ;
           Aff_struct3_Tsisi ( S  , Element_V8_4s ( Tg , M , J   ) ) ;
           if( ( Mod ( I , 4 ) == 1 ) || ( Mod ( I , 4 ) == 2 )) {
             Aff_struct2_Tsisi ( S  , 4 ) ;
             Aff_struct4_Tsisi ( S  , 0 ) ;
             }
           else
             {
             A  =  I ;
             B  =  J ;
             Points ( & A , & B ) ;
            /*GENERATION ALEATOIRE DES POINTS*/
             Aff_struct2_Tsisi ( S  , A ) ;
             Aff_struct4_Tsisi ( S  , B ) ;

           } ;
           Allouer_LTsisi (& P ) ;
           Aff_val_LTsisi ( P , S ) ;
           Aff_adr_LTsisi ( Q , P ) ;
           Q  =  P ;
           Aff_element_V4i ( Tc , I   , Element_V4i ( Tc , I   ) + Struct2_Tsisi ( S  ) ) ;
           Aff_element_V4i ( Tc , J   , Element_V4i ( Tc , J   ) + Struct4_Tsisi ( S  ) ) ;

         } ;

       } ;
       Aff_adr_LTsisi ( Q , NULL ) ;
       for( K  =  1 ;K <=  4 ; ++K){
         Aff_struct1_Tsi ( S2  , Element_V8_4s ( Tg , M , K   ) ) ;
         Aff_struct2_Tsi ( S2  , Element_V4i ( Tc , K   ) ) ;
         Aff_element_V4Tsi ( Td , K   , S2 ) ;

       } ;
       for( U  =  1 ;U <=  4 ; ++U){
         N  =  1 ;
         while( N < 4)  {
           if( Element_V4i ( Tc , N   ) > Element_V4i ( Tc , N + 1   )) {
             C  =  Element_V4i ( Tc , N   ) ;
             Aff_element_V4i ( Tc , N   , Element_V4i ( Tc , N + 1   ) ) ;
             Aff_element_V4i ( Tc , N + 1   , C ) ;
      /* Affectation globale de structure */
             strcpy(Tmp->Champ1,   Element_V4Tsi ( Td , N   )->Champ1);
             Tmp->Champ2 =   Element_V4Tsi ( Td , N   )->Champ2;
 ;
             Aff_element_V4Tsi ( Td , N   , Element_V4Tsi ( Td , N + 1   ) ) ;
             Aff_element_V4Tsi ( Td , N + 1   , Tmp ) ;

           } ;
           N  =  N + 1 ;

         } ;

       } ;
       Aff_element_V8s ( Te1 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 4   )  ) ) ;
       Aff_element_V8s ( Te2 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 3   )  ) ) ;
       Jj  =  Jj + 1 ;

     } ;
     Aff_element_V16s ( *Tm , 1   , Element_V8s ( Te1 , 1   ) ) ;
     Aff_element_V16s ( *Tm , 2   , Element_V8s ( Te2 , 2   ) ) ;
     Aff_element_V16s ( *Tm , 3   , Element_V8s ( Te1 , 2   ) ) ;
     Aff_element_V16s ( *Tm , 4   , Element_V8s ( Te2 , 1   ) ) ;
     Aff_element_V16s ( *Tm , 5   , Element_V8s ( Te1 , 3   ) ) ;
     Aff_element_V16s ( *Tm , 6   , Element_V8s ( Te2 , 4   ) ) ;
     Aff_element_V16s ( *Tm , 7   , Element_V8s ( Te1 , 4   ) ) ;
     Aff_element_V16s ( *Tm , 8   , Element_V8s ( Te2 , 3   ) ) ;
     Aff_element_V16s ( *Tm , 9   , Element_V8s ( Te1 , 5   ) ) ;
     Aff_element_V16s ( *Tm , 10   , Element_V8s ( Te2 , 6   ) ) ;
     Aff_element_V16s ( *Tm , 11   , Element_V8s ( Te1 , 6   ) ) ;
     Aff_element_V16s ( *Tm , 12   , Element_V8s ( Te2 , 5   ) ) ;
     Aff_element_V16s ( *Tm , 13   , Element_V8s ( Te1 , 7   ) ) ;
     Aff_element_V16s ( *Tm , 14   , Element_V8s ( Te2 , 8   ) ) ;
     Aff_element_V16s ( *Tm , 15   , Element_V8s ( Te1 , 8   ) ) ;
     Aff_element_V16s ( *Tm , 16   , Element_V8s ( Te2 , 7   ) ) ;
     for( Jj  =  1 ;Jj <=  8 ; ++Jj){
       textcolor(6);
       printf ( " %s", "\n\n\t  GROUPE:" );
       printf ( " %d", Jj ) ;
      textcolor(15);
       printf ( " \n%s", "\n\t  EQUIPE QUALIFIEE1:" );
       printf ( " %s", Element_V8s(Te1,Jj) ) ;
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE2:" );
       printf ( " %s", Element_V8s(Te2,Jj) ) ;

     } ;

    }
  void Fav_pre12 (Pointeur_ATss *R)
    {
      /** Variables locales **/
      Pointeur_ATss P=NULL;
      Pointeur_ATss Q=NULL;
      Pointeur_ATss T=NULL;
      Typestr_Tss S;
      Typestr_Tss S1;
      Typestr_Tss S2;
      Typestr_Tss Val;
      Pointeur_FTss Fil=NULL;
      int I;
      int J;
      int K;
      int L;
      int Fav;
      int D;
      string255 Favorite;
      Typevect_V16s Tab;
      Type_Tss _Struct_Temp1;
      Type_Tss _Struct_Temp2;
      Type_Tss _Struct_Temp3;
      Type_Tss _Struct_Temp4;
      Type_Tss _Struct_Temp5;
      Type_Tss _Struct_Temp6;
      Type_Tss _Struct_Temp7;
      Type_Tss _Struct_Temp8;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tss));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ2 = malloc(255 * sizeof(char));
     S1 = malloc(sizeof(Type_Tss));
     S1->Champ1 = malloc(255 * sizeof(char));
     S1->Champ2 = malloc(255 * sizeof(char));
     S2 = malloc(sizeof(Type_Tss));
     S2->Champ1 = malloc(255 * sizeof(char));
     S2->Champ2 = malloc(255 * sizeof(char));
     Val = malloc(sizeof(Type_Tss));
     Val->Champ1 = malloc(255 * sizeof(char));
     Val->Champ2 = malloc(255 * sizeof(char));
     Favorite = malloc(255 * sizeof(char));
     Tab = malloc(16 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<16; ++_Izw2)
       Tab[_Izw2]= malloc(255 * sizeof(char));
     printf ( " %s", "\n LES EQUIPES RETENUES DANS LA PHASE 1 SONT:" ) ;
     Fav_pre1 ( & Tab ) ;
     D  =  1 ;
     K  =  1 ;
      textcolor(6);
     printf ( " %s", "\n\n\tHUITIEME DE FINALE:" );
     textcolor(15);
     printf ( " %s", "\n\t=================\n" ) ;
     for( J  =  1 ;J <=  2 ; ++J){
       for( I  =  1 ;I <=  4 ; ++I){
         Creernoeud_ATss (& P ) ;
         Creernoeud_ATss (& T ) ;
         Aff_struct1_Tss ( S  , Element_V16s ( Tab , K   ) ) ;
         Aff_struct2_Tss ( S  , Element_V16s ( Tab , K + 1   ) ) ;
         Aff_info_ATss ( T , S ) ;
         /** Ecriture d'une structure */
         _Struct_Temp1 = *Info_ATss(T);
         printf ( " \t%s", _Struct_Temp1.Champ1 );
         printf ( " %s", "\n\t VS     \n" ) ;
         printf ( " \t%s", _Struct_Temp1.Champ2 );
         printf ("%s", "\n\t=================\n" ) ;
         Creernoeud_ATss (& T ) ;
         if( Mod ( I , 2 ) == 1) {
           Aff_fg_ATss ( P , T ) ;
           }
         else
           {
           if( I == 2) {
             Aff_fd_ATss ( P , T ) ;
             Aff_struct1_Tss ( S  , Element_V16s ( Tab , D   ) ) ;
             D  =  D + 2 ;
             Aff_struct2_Tss ( S  , Element_V16s ( Tab , D   ) ) ;
             D  =  D + 2 ;
             Aff_info_ATss ( P , S ) ;
             Creernoeud_ATss (& Q ) ;
             Aff_fd_ATss ( Q , P ) ;

           } ;

         } ;
         if( I == 4) {
           Aff_fg_ATss ( Q , P ) ;
           Aff_struct1_Tss ( S  , Element_V16s ( Tab , D   ) ) ;
           D  =  D + 2 ;
           Aff_struct2_Tss ( S  , Element_V16s ( Tab , D   ) ) ;
           D  =  D + 2 ;
           Aff_info_ATss ( P , S ) ;

         } ;
         K  =  K + 2 ;

       } ;
       if( J == 1) {
         Creernoeud_ATss (& *R ) ;
         Aff_fd_ATss ( *R , Q ) ;
         }
       else
         {
         Aff_fg_ATss ( *R , Q ) ;

       } ;

     } ;
     textcolor(6);
     printf ( " %s", "\n\tQUART DE FINALE:" );
     textcolor(15);
     printf ("%s", "\n\t=================\n" ) ;
     /** Ecriture d'une structure */
     _Struct_Temp2 = *Info_ATss(Fd_ATss(Fd_ATss(*R)));
     printf ( " \t%s", _Struct_Temp2.Champ1 );
     printf ( " %s", "\n\t VS\n" ) ;
     printf ( " \t%s", _Struct_Temp2.Champ2 );
     printf ("%s", "\n\t=================\n" ) ;
     /** Ecriture d'une structure */
     _Struct_Temp3 = *Info_ATss(Fg_ATss(Fd_ATss(*R)));
     printf ( " \t%s", _Struct_Temp3.Champ1 );
     printf ( " %s", "\n\t VS\n" ) ;
     printf ( " \t%s", _Struct_Temp3.Champ2 );
     printf ("%s", "\n\t=================\n" ) ;
     /** Ecriture d'une structure */
     _Struct_Temp4 = *Info_ATss(Fd_ATss(Fg_ATss(*R)));
     printf ( " \t%s", _Struct_Temp4.Champ1 );
     printf ( " %s", "\n\t VS\n" ) ;
     printf ( " \t%s", _Struct_Temp4.Champ2 );
     printf ("%s", "\n\t=================\n" ) ;
     /** Ecriture d'une structure */
     _Struct_Temp5 = *Info_ATss(Fg_ATss(Fg_ATss(*R)));
     printf ( " \t%s", _Struct_Temp5.Champ1 );
     printf ( " %s", "\n\t VS\n" ) ;
     printf ( " \t%s", _Struct_Temp5.Champ2 );
     printf ("%s", "\n\t=================\n" ) ;
     printf ( " %s", " " );
     textcolor(6);
     printf ( " %s", "\n\tDEMI FINALE:" );
     textcolor(15);
     printf ("%s", "\n\t=================\n" ) ;
     P  =  Fd_ATss ( Fd_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     Aff_struct1_Tss ( S1  , "ANGLETERRE" ) ;
     P  =  Fg_ATss ( Fd_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     Aff_struct2_Tss ( S1  , "FRANCE" ) ;
     Aff_info_ATss ( Fd_ATss ( *R ) , S1 ) ;
     /** Ecriture d'une structure */
     _Struct_Temp6 = *Info_ATss(Fd_ATss(*R));
     printf ( " \t%s", _Struct_Temp6.Champ1 );
     printf ( " %s", "\n\t VS\n" ) ;
     printf ( " \t%s", _Struct_Temp6.Champ2 );
     printf ("%s", "\n\t=================\n" ) ;
     P  =  Fd_ATss ( Fg_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     Aff_struct1_Tss ( S1  , "BELGIQUE" ) ;
     P  =  Fg_ATss ( Fg_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     Aff_struct2_Tss ( S1  , "BRESIL" ) ;
     Aff_info_ATss ( Fg_ATss ( *R ) , S1 ) ;
     /** Ecriture d'une structure */
     _Struct_Temp7 = *Info_ATss(Fg_ATss(*R));
     printf ( " \t%s", _Struct_Temp7.Champ1 );
     printf ( " %s", "\n\t VS\n" ) ;
     printf ( " \t%s", _Struct_Temp7.Champ2 );
     printf ("%s", "\n\t=================\n" ) ;
     textcolor(6);
     printf ( " %s", "\n\n\tLA FINALE:" );
     textcolor(15);
     printf ("%s", "\n\t=================\n" ) ;
     P  =  Fd_ATss ( *R ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     Aff_struct1_Tss ( S1  , "FRANCE" ) ;
     P  =  Fg_ATss ( *R ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     Aff_struct2_Tss ( S1  , "BRESIL" ) ;
     Aff_info_ATss ( *R , S1 ) ;
     /** Ecriture d'une structure */
     _Struct_Temp8 = *Info_ATss(*R);
     printf ( " \t%s", _Struct_Temp8.Champ1 );
     printf ( " \t%s", "\n\t VS\n" ) ;
     printf ( " \t%s", _Struct_Temp8.Champ2 );
     printf ("%s", "\n\t=================\n" ) ;
     printf ("%s", "\n\n\n\t===================================\n" ) ;
     textcolor(6);
     printf ( " \t%s", " L'EQUIPE GAGNANTE EST :" ) ;
     textcolor(15);
     printf ( " %s", " BRESIL" );
     printf ("%s", "\n\t===================================\n" ) ;

    }
  void Hasard11 (Typevect_V16s *Tm)
    {
      /** Variables locales **/
      Typevect_V8_4s Tg;
      Typevect_V4Tsi Td;
      Typevect_V8s Te1;
      Typevect_V8s Te2;
      Typevect_V4i Tc;
      Typestr_Tsi S1;
      Typestr_Tsi S2;
      Typestr_Tsi Tmp;
      int Jj;
      int A;
      int B;
      int I;
      int J;
      int M;
      int K;
      int N;
      int U;
      int C;
      Pointeur_LTsisi Tete=NULL;
      Pointeur_LTsisi P=NULL;
      Pointeur_LTsisi Q=NULL;
      Pointeur_LTsisi L=NULL;
      Typestr_Tsisi S;
        Typetab_V4i T_Tc;

      /** Corps du module **/
     Tg = malloc(8*4 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<8*4; ++_Izw2)
       Tg[_Izw2]= malloc(255 * sizeof(char));
     Td = malloc(4 * sizeof(Typestr_Tsi));
     int _Izw3;for (_Izw3=0; _Izw3<4; ++_Izw3)
       Td[_Izw3] = malloc( sizeof(Type_Tsi ));
     int _Izw4;for (_Izw4=0; _Izw4<4; ++_Izw4){
       Td[_Izw4]->Champ1= malloc(255 * sizeof(char));}
     Te1 = malloc(8 * 255  * sizeof(char));
     int _Izw5;for (_Izw5=0; _Izw5<8; ++_Izw5)
       Te1[_Izw5]= malloc(255 * sizeof(char));
     Te2 = malloc(8 * 255  * sizeof(char));
     int _Izw6;for (_Izw6=0; _Izw6<8; ++_Izw6)
       Te2[_Izw6]= malloc(255 * sizeof(char));
     Tc = malloc(4 * sizeof(int));
     S1 = malloc(sizeof(Type_Tsi));
     S1->Champ1 = malloc(255 * sizeof(char));
     S2 = malloc(sizeof(Type_Tsi));
     S2->Champ1 = malloc(255 * sizeof(char));
     Tmp = malloc(sizeof(Type_Tsi));
     Tmp->Champ1 = malloc(255 * sizeof(char));
     S = malloc(sizeof(Type_Tsisi));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ3 = malloc(255 * sizeof(char));
     Jj  =  1 ;
    /*INITIALISATION DU TABLEAU DES EQUIPES*/
     Init32 ( & Tg ) ;
     Aff_struct1_Tsisi ( S  , "PAYS-BAS" ) ;
     Aff_struct3_Tsisi ( S  , "SENEGAL" ) ;
     Aff_struct2_Tsisi ( S  , 1 ) ;
     Aff_struct4_Tsisi ( S  , 2 ) ;
     Allouer_LTsisi (& P ) ;
     Aff_val_LTsisi ( P , S ) ;
     Tete  =  P ;
     Q  =  P ;
     for( M  =  1 ;M <=  8 ; ++M){
       T_Tc [ 0 ] = 0 ;
       T_Tc [ 1 ] = 0 ;
       T_Tc [ 2 ] = 0 ;
       T_Tc [ 3 ] = 0 ;
       Init_vect_V4i ( Tc , T_Tc , 4 )  ;
       for( I  =  1 ;I <=  4 ; ++I){
         for( J  =  I + 1 ;J <=  4 ; ++J){
           Aff_struct1_Tsisi ( S  , Element_V8_4s ( Tg , M , I   ) ) ;
           Aff_struct3_Tsisi ( S  , Element_V8_4s ( Tg , M , J   ) ) ;
           A  =  I ;
           B  =  J ;
           Points ( & A , & B ) ;
          /*GENERATION ALEATOIRE DES POINTS*/
           Aff_struct2_Tsisi ( S  , A ) ;
           Aff_struct4_Tsisi ( S  , B ) ;
           Allouer_LTsisi (& P ) ;
           Aff_val_LTsisi ( P , S ) ;
           Aff_adr_LTsisi ( Q , P ) ;
           Q  =  P ;
           Aff_element_V4i ( Tc , I   , Element_V4i ( Tc , I   ) + Struct2_Tsisi ( S  ) ) ;
           Aff_element_V4i ( Tc , J   , Element_V4i ( Tc , J   ) + Struct4_Tsisi ( S  ) ) ;

         } ;

       } ;
       Aff_adr_LTsisi ( Q , NULL ) ;
       for( K  =  1 ;K <=  4 ; ++K){
         Aff_struct1_Tsi ( S2  , Element_V8_4s ( Tg , M , K   ) ) ;
         Aff_struct2_Tsi ( S2  , Element_V4i ( Tc , K   ) ) ;
         Aff_element_V4Tsi ( Td , K   , S2 ) ;

       } ;
       for( U  =  1 ;U <=  4 ; ++U){
         N  =  1 ;
         while( N < 4)  {
           if( Element_V4i ( Tc , N   ) > Element_V4i ( Tc , N + 1   )) {
             C  =  Element_V4i ( Tc , N   ) ;
             Aff_element_V4i ( Tc , N   , Element_V4i ( Tc , N + 1   ) ) ;
             Aff_element_V4i ( Tc , N + 1   , C ) ;
      /* Affectation globale de structure */
             strcpy(Tmp->Champ1,   Element_V4Tsi ( Td , N   )->Champ1);
             Tmp->Champ2 =   Element_V4Tsi ( Td , N   )->Champ2;
 ;
             Aff_element_V4Tsi ( Td , N   , Element_V4Tsi ( Td , N + 1   ) ) ;
             Aff_element_V4Tsi ( Td , N + 1   , Tmp ) ;

           } ;
           N  =  N + 1 ;

         } ;

       } ;
       Aff_element_V8s ( Te1 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 4   )  ) ) ;
       Aff_element_V8s ( Te2 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 3   )  ) ) ;
       Jj  =  Jj + 1 ;

     } ;
     for( Jj  =  1 ;Jj <=  8 ; ++Jj){
       Aff_element_V16s ( *Tm , Jj   , Element_V8s ( Te1 , Jj   ) ) ;
       Aff_element_V16s ( *Tm , Jj + 8   , Element_V8s ( Te2 , Jj   ) ) ;

     } ;
     for( Jj  =  1 ;Jj <=  8 ; ++Jj){
            textcolor(06);
       printf ( " %s", "\n\n\t  GROUPE:" );
       printf ( " %d", Jj ) ;
     textcolor(15);
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE1:" );
       printf ( " %s", Element_V8s(Te1,Jj) ) ;
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE2:" );
       printf ( " %s", Element_V8s(Te2,Jj) ) ;

     } ;

    }
  void Fav()
    {
      /** Variables locales **/
      Typevect_V8_4s Tg;
      Typevect_V4Tsi Td;
      Typevect_V8s Te1;
      Typevect_V8s Te2;
      Typevect_V4i Tc;
      Typestr_Tsi S1;
      Typestr_Tsi S2;
      Typestr_Tsi Tmp;
      int Jj;
      int A;
      int B;
      int I;
      int J;
      int X;
      int T;
      int M;
      int K;
      int N;
      int U;
      int C;
      int D;
      Pointeur_LTsisi Tete=NULL;
      Pointeur_LTsisi P=NULL;
      Pointeur_LTsisi Q=NULL;
      Pointeur_LTsisi L=NULL;
      Typestr_Tsisi S;
      string255 Favorite;
        Typetab_V4i T_Tc;

      /** Corps du module **/
     Tg = malloc(8*4 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<8*4; ++_Izw2)
       Tg[_Izw2]= malloc(255 * sizeof(char));
     Td = malloc(4 * sizeof(Typestr_Tsi));
     int _Izw3;for (_Izw3=0; _Izw3<4; ++_Izw3)
       Td[_Izw3] = malloc( sizeof(Type_Tsi ));
     int _Izw4;for (_Izw4=0; _Izw4<4; ++_Izw4){
       Td[_Izw4]->Champ1= malloc(255 * sizeof(char));}
     Te1 = malloc(8 * 255  * sizeof(char));
     int _Izw5;for (_Izw5=0; _Izw5<8; ++_Izw5)
       Te1[_Izw5]= malloc(255 * sizeof(char));
     Te2 = malloc(8 * 255  * sizeof(char));
     int _Izw6;for (_Izw6=0; _Izw6<8; ++_Izw6)
       Te2[_Izw6]= malloc(255 * sizeof(char));
     Tc = malloc(4 * sizeof(int));
     S1 = malloc(sizeof(Type_Tsi));
     S1->Champ1 = malloc(255 * sizeof(char));
     S2 = malloc(sizeof(Type_Tsi));
     S2->Champ1 = malloc(255 * sizeof(char));
     Tmp = malloc(sizeof(Type_Tsi));
     Tmp->Champ1 = malloc(255 * sizeof(char));
     S = malloc(sizeof(Type_Tsisi));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ3 = malloc(255 * sizeof(char));
     Favorite = malloc(255 * sizeof(char));
     Jj  =  1 ;
    /*INITIALISATION DU TABLEAU DES EQUIPES*/
     Init32 ( & Tg ) ;
     for( I  =  1 ;I <=  31 ; ++I){
       if( Mod ( I , 4 ) == 0) {
           textcolor(6);
           printf ( "\n\t %s","- " ) ;
          textcolor(15);
         printf ( " %s", Element_V8_4s(Tg,(I/4)+1,4) ) ;
         }
       else
         {
           textcolor(6);
           printf ( "\n\t %s","- " ) ;
          textcolor(15);
         printf ( "%s", Element_V8_4s(Tg,((I-Mod(I,4))/4)+1,Mod(I,4)) ) ;

       } ;

     } ;
     textcolor(6);
     printf ( "\n\t %s","- " ) ;
     textcolor(15);
     printf ( "%s", Element_V8_4s(Tg,8,4) ) ;
     printf ( " %s", "\n\n\t VEUILLEZ ENTRER LE NOM DE L'EQUIPE FAVORITE: " ) ;
     scanf ( " %[^\n]", Favorite ) ;
     strcpy(Favorite,strupr(Favorite));
     Aff_struct1_Tsisi ( S  , "PAYS-BAS" ) ;
     Aff_struct3_Tsisi ( S  , "SENEGAL" ) ;
     Aff_struct2_Tsisi ( S  , 1 ) ;
     Aff_struct4_Tsisi ( S  , 2 ) ;
     Allouer_LTsisi (& P ) ;
     Aff_val_LTsisi ( P , S ) ;
     Tete  =  P ;
     Q  =  P ;
     for( M  =  1 ;M <=  8 ; ++M){
       T_Tc [ 0 ] = 0 ;
       T_Tc [ 1 ] = 0 ;
       T_Tc [ 2 ] = 0 ;
       T_Tc [ 3 ] = 0 ;
       Init_vect_V4i ( Tc , T_Tc , 4 )  ;

       for( I  =  1 ;I <=  4 ; ++I){
         for( J  =  I + 1 ;J <=  4 ; ++J){
           Aff_struct1_Tsisi ( S  , Element_V8_4s ( Tg , M , I   ) ) ;
           Aff_struct3_Tsisi ( S  , Element_V8_4s ( Tg , M , J   ) ) ;
           if(strcmp( Element_V8_4s ( Tg , M , I   ), Favorite) == 0 ) {
             Aff_struct2_Tsisi ( S  , 4 ) ;
             Aff_struct4_Tsisi ( S  , 0 ) ;
             }
           else
             {
             if(strcmp( Element_V8_4s ( Tg , M , J   ), Favorite) == 0 ) {
               Aff_struct2_Tsisi ( S  , 0 ) ;
               Aff_struct4_Tsisi ( S  , 4 ) ;
               }
             else
               {
               A  =  I ;
               B  =  J ;
               Points ( & A , & B ) ;
              /*GENERATION ALEATOIRE DES POINTS*/
               Aff_struct2_Tsisi ( S  , A ) ;
               Aff_struct4_Tsisi ( S  , B ) ;

             } ;

           } ;
           Allouer_LTsisi (& P ) ;
           Aff_val_LTsisi ( P , S ) ;
           Aff_adr_LTsisi ( Q , P ) ;
           Q  =  P ;
           Aff_element_V4i ( Tc , I   , Element_V4i ( Tc , I   ) + Struct2_Tsisi ( S  ) ) ;
           Aff_element_V4i ( Tc , J   , Element_V4i ( Tc , J   ) + Struct4_Tsisi ( S  ) ) ;

         } ;

       } ;
       Aff_adr_LTsisi ( Q , NULL ) ;
       for( K  =  1 ;K <=  4 ; ++K){
         Aff_struct1_Tsi ( S2  , Element_V8_4s ( Tg , M , K   ) ) ;
         Aff_struct2_Tsi ( S2  , Element_V4i ( Tc , K   ) ) ;
         Aff_element_V4Tsi ( Td , K   , S2 ) ;

       } ;
       for( U  =  1 ;U <=  4 ; ++U){
         N  =  1 ;
         while( N < 4)  {
           if( Element_V4i ( Tc , N   ) > Element_V4i ( Tc , N + 1   )) {
             C  =  Element_V4i ( Tc , N   ) ;
             Aff_element_V4i ( Tc , N   , Element_V4i ( Tc , N + 1   ) ) ;
             Aff_element_V4i ( Tc , N + 1   , C ) ;
      /* Affectation globale de structure */
             strcpy(Tmp->Champ1,   Element_V4Tsi ( Td , N   )->Champ1);
             Tmp->Champ2 =   Element_V4Tsi ( Td , N   )->Champ2;
 ;
             Aff_element_V4Tsi ( Td , N   , Element_V4Tsi ( Td , N + 1   ) ) ;
             Aff_element_V4Tsi ( Td , N + 1   , Tmp ) ;

           } ;
           N  =  N + 1 ;

         } ;

       } ;
       Aff_element_V8s ( Te1 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 4   )  ) ) ;
       Aff_element_V8s ( Te2 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 3   )  ) ) ;
       Jj  =  Jj + 1 ;

     } ;
     for( Jj  =  1 ;Jj <=  8 ; ++Jj){
       textcolor(6);
       printf ( " %s", "\n\n\t  GROUPE:" );
       printf ( " %d", Jj ) ;
       textcolor(15);
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE1:" );
       printf ( " %s", Element_V8s(Te1,Jj) ) ;
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE2:" );
       printf ( " %s", Element_V8s(Te2,Jj) ) ;

     } ;

    }
  void Moins_fav()
    {
      /** Variables locales **/
      Typevect_V8_4s Tg;
      Typevect_V4Tsi Td;
      Typevect_V8s Te1;
      Typevect_V8s Te2;
      Typevect_V4i Tc;
      Typestr_Tsi S1;
      Typestr_Tsi S2;
      Typestr_Tsi Tmp;
      int Jj;
      int A;
      int B;
      int I;
      int J;
      int X;
      int T;
      int M;
      int K;
      int N;
      int U;
      int C;
      int D;
      Pointeur_LTsisi Tete=NULL;
      Pointeur_LTsisi P=NULL;
      Pointeur_LTsisi Q=NULL;
      Pointeur_LTsisi L=NULL;
      Typestr_Tsisi S;
      string255 M_favorite;
        Typetab_V4i T_Tc;

      /** Corps du module **/
     Tg = malloc(8*4 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<8*4; ++_Izw2)
       Tg[_Izw2]= malloc(255 * sizeof(char));
     Td = malloc(4 * sizeof(Typestr_Tsi));
     int _Izw3;for (_Izw3=0; _Izw3<4; ++_Izw3)
       Td[_Izw3] = malloc( sizeof(Type_Tsi ));
     int _Izw4;for (_Izw4=0; _Izw4<4; ++_Izw4){
       Td[_Izw4]->Champ1= malloc(255 * sizeof(char));}
     Te1 = malloc(8 * 255  * sizeof(char));
     int _Izw5;for (_Izw5=0; _Izw5<8; ++_Izw5)
       Te1[_Izw5]= malloc(255 * sizeof(char));
     Te2 = malloc(8 * 255  * sizeof(char));
     int _Izw6;for (_Izw6=0; _Izw6<8; ++_Izw6)
       Te2[_Izw6]= malloc(255 * sizeof(char));
     Tc = malloc(4 * sizeof(int));
     S1 = malloc(sizeof(Type_Tsi));
     S1->Champ1 = malloc(255 * sizeof(char));
     S2 = malloc(sizeof(Type_Tsi));
     S2->Champ1 = malloc(255 * sizeof(char));
     Tmp = malloc(sizeof(Type_Tsi));
     Tmp->Champ1 = malloc(255 * sizeof(char));
     S = malloc(sizeof(Type_Tsisi));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ3 = malloc(255 * sizeof(char));
     M_favorite = malloc(255 * sizeof(char));
     Jj  =  1 ;
    /*INITIALISATION DU TABLEAU DES EQUIPES*/
    Init32 ( & Tg ) ;
     for( I  =  1 ;I <=  31 ; ++I){
       if( Mod ( I , 4 ) == 0) {
           textcolor(6);
           printf ( "\n\t %s","- " ) ;
          textcolor(15);
         printf ( " %s", Element_V8_4s(Tg,(I/4)+1,4) ) ;
         }
       else
         {
           textcolor(6);
           printf ( "\n\t %s","- " ) ;
          textcolor(15);
         printf ( "%s", Element_V8_4s(Tg,((I-Mod(I,4))/4)+1,Mod(I,4)) ) ;

       } ;

     } ;
     textcolor(6);
     printf ( "\n\t %s","- " ) ;
     textcolor(15);
     printf ( "%s", Element_V8_4s(Tg,8,4) ) ;

     printf ( " %s", "\n\t VEUILLEZ ENTRER LE NOM DE L'EQUIPE PERDANTE " ) ;
     scanf ( " %[^\n]", M_favorite ) ;
     strcpy(M_favorite,strupr(M_favorite));
     Aff_struct1_Tsisi ( S  , "PAYS-BAS" ) ;
     Aff_struct3_Tsisi ( S  , "SENEGAL" ) ;
     Aff_struct2_Tsisi ( S  , 1 ) ;
     Aff_struct4_Tsisi ( S  , 2 ) ;
     Allouer_LTsisi (& P ) ;
     Aff_val_LTsisi ( P , S ) ;
     Tete  =  P ;
     Q  =  P ;
     for( M  =  1 ;M <=  8 ; ++M){
       T_Tc [ 0 ] = 0 ;
       T_Tc [ 1 ] = 0 ;
       T_Tc [ 2 ] = 0 ;
       T_Tc [ 3 ] = 0 ;
       Init_vect_V4i ( Tc , T_Tc , 4 )  ;
       for( I  =  1 ;I <=  4 ; ++I){
         for( J  =  I + 1 ;J <=  4 ; ++J){
           Aff_struct1_Tsisi ( S  , Element_V8_4s ( Tg , M , I   ) ) ;
           Aff_struct3_Tsisi ( S  , Element_V8_4s ( Tg , M , J   ) ) ;
           if(strcmp( Element_V8_4s ( Tg , M , I   ), M_favorite) == 0 ) {
             Aff_struct2_Tsisi ( S  , 0 ) ;
             Aff_struct4_Tsisi ( S  , 4 ) ;
             }
           else
             {
             if(strcmp( Element_V8_4s ( Tg , M , J   ), M_favorite) == 0 ) {
               Aff_struct2_Tsisi ( S  , 4 ) ;
               Aff_struct4_Tsisi ( S  , 0 ) ;
               }
             else
               {
               A  =  I ;
               B  =  J ;
               Points ( & A , & B ) ;
              /*GENERATION ALEATOIRE DES POINTS*/
               Aff_struct2_Tsisi ( S  , A ) ;
               Aff_struct4_Tsisi ( S  , B ) ;

             } ;

           } ;
           Allouer_LTsisi (& P ) ;
           Aff_val_LTsisi ( P , S ) ;
           Aff_adr_LTsisi ( Q , P ) ;
           Q  =  P ;
           Aff_element_V4i ( Tc , I   , Element_V4i ( Tc , I   ) + Struct2_Tsisi ( S  ) ) ;
           Aff_element_V4i ( Tc , J   , Element_V4i ( Tc , J   ) + Struct4_Tsisi ( S  ) ) ;

         } ;

       } ;
       Aff_adr_LTsisi ( Q , NULL ) ;
       for( K  =  1 ;K <=  4 ; ++K){
         Aff_struct1_Tsi ( S2  , Element_V8_4s ( Tg , M , K   ) ) ;
         Aff_struct2_Tsi ( S2  , Element_V4i ( Tc , K   ) ) ;
         Aff_element_V4Tsi ( Td , K   , S2 ) ;

       } ;
       for( U  =  1 ;U <=  4 ; ++U){
         N  =  1 ;
         while( N < 4)  {
           if( Element_V4i ( Tc , N   ) > Element_V4i ( Tc , N + 1   )) {
             C  =  Element_V4i ( Tc , N   ) ;
             Aff_element_V4i ( Tc , N   , Element_V4i ( Tc , N + 1   ) ) ;
             Aff_element_V4i ( Tc , N + 1   , C ) ;
      /* Affectation globale de structure */
             strcpy(Tmp->Champ1,   Element_V4Tsi ( Td , N   )->Champ1);
             Tmp->Champ2 =   Element_V4Tsi ( Td , N   )->Champ2;
 ;
             Aff_element_V4Tsi ( Td , N   , Element_V4Tsi ( Td , N + 1   ) ) ;
             Aff_element_V4Tsi ( Td , N + 1   , Tmp ) ;

           } ;
           N  =  N + 1 ;

         } ;

       } ;
       Aff_element_V8s ( Te1 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 4   )  ) ) ;
       Aff_element_V8s ( Te2 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 3   )  ) ) ;
       Jj  =  Jj + 1 ;

     } ;
     for( Jj  =  1 ;Jj <=  8 ; ++Jj){
       textcolor(6);
       printf ( " %s", "\n\n\t  GROUPE:" );
       printf ( " %d", Jj ) ;
       textcolor(15);
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE1:" );
       printf ( " %s", Element_V8s(Te1,Jj) ) ;
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE2:" );
       printf ( " %s", Element_V8s(Te2,Jj) ) ;
     }}

  void Points (int *A , int *B)
    {
      /** Variables locales **/
      Typevect_V4i T;
      int X;
      int Y;
        Typetab_V4i T_T;

      /** Corps du module **/
     T = malloc(4 * sizeof(int));
     T_T [ 0 ] = 0 ;
     T_T [ 1 ] = 0 ;
     T_T [ 2 ] = 0 ;
     T_T [ 3 ] = 0 ;
     Init_vect_V4i ( T , T_T , 4 )  ;
     X  =  Aleanombre(3 ) ;
     Y  =  Aleanombre(3 ) ;
     if( X > Y) {
       Aff_element_V4i ( T , *A   , 3 ) ;
       }
     else
       {
       if( X < Y) {
         Aff_element_V4i ( T , *B   , 3 ) ;
         }
       else
         {
         Aff_element_V4i ( T , *A   , 1 ) ;
         Aff_element_V4i ( T , *B   , 1 ) ;

       }
     } ;
     *A  =  Element_V4i ( T , *A   ) ;
     *B  =  Element_V4i ( T , *B   ) ;

    }
  void Fav_grp()
    {
      /** Variables locales **/
      Typevect_V8_4s Tg;
      Typevect_V4Tsi Td;
      Typevect_V8s Te1;
      Typevect_V8s Te2;
      Typevect_V4i Tc;
      Typestr_Tsi S1;
      Typestr_Tsi S2;
      Typestr_Tsi Tmp;
      int Jj;
      int A;
      int B;
      int I;
      int J;
      int X;
      int T;
      int M;
      int K;
      int N;
      int U;
      int C;
      int D;
      Pointeur_LTsisi Tete=NULL;
      Pointeur_LTsisi P=NULL;
      Pointeur_LTsisi Q=NULL;
      Pointeur_LTsisi L=NULL;
      Typestr_Tsisi S;
      string255 Favorite;
        Typetab_V4i T_Tc;

      /** Corps du module **/
     Tg = malloc(8*4 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<8*4; ++_Izw2)
       Tg[_Izw2]= malloc(255 * sizeof(char));
     Td = malloc(4 * sizeof(Typestr_Tsi));
     int _Izw3;for (_Izw3=0; _Izw3<4; ++_Izw3)
       Td[_Izw3] = malloc( sizeof(Type_Tsi ));
     int _Izw4;for (_Izw4=0; _Izw4<4; ++_Izw4){
       Td[_Izw4]->Champ1= malloc(255 * sizeof(char));}
     Te1 = malloc(8 * 255  * sizeof(char));
     int _Izw5;for (_Izw5=0; _Izw5<8; ++_Izw5)
       Te1[_Izw5]= malloc(255 * sizeof(char));
     Te2 = malloc(8 * 255  * sizeof(char));
     int _Izw6;for (_Izw6=0; _Izw6<8; ++_Izw6)
       Te2[_Izw6]= malloc(255 * sizeof(char));
     Tc = malloc(4 * sizeof(int));
     S1 = malloc(sizeof(Type_Tsi));
     S1->Champ1 = malloc(255 * sizeof(char));
     S2 = malloc(sizeof(Type_Tsi));
     S2->Champ1 = malloc(255 * sizeof(char));
     Tmp = malloc(sizeof(Type_Tsi));
     Tmp->Champ1 = malloc(255 * sizeof(char));
     S = malloc(sizeof(Type_Tsisi));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ3 = malloc(255 * sizeof(char));
     Favorite = malloc(255 * sizeof(char));
     Jj  =  1 ;
    /*INITIALISATION DU TABLEAU DES EQUIPES*/
     Init32 ( & Tg ) ;
     Aff_struct1_Tsisi ( S  , "PAYS-BAS" ) ;
     Aff_struct3_Tsisi ( S  , "SENEGAL" ) ;
     Aff_struct2_Tsisi ( S  , 1 ) ;
     Aff_struct4_Tsisi ( S  , 2 ) ;
     Allouer_LTsisi (& P ) ;
     Aff_val_LTsisi ( P , S ) ;
     Tete  =  P ;
     Q  =  P ;
     for( M  =  1 ;M <=  8 ; ++M){
       textcolor(6);
       printf ( " %s", "\n\t LES EQUIPES DU GROUPE:" );
       printf ( " %d", M );
       textcolor(15);
       printf ( "\n\t %s",  Element_V8_4s(Tg,M,1) );
       printf ( "\n\t %s",  Element_V8_4s(Tg,M,2) );
       printf ( "\n\t %s",  Element_V8_4s(Tg,M,3) );
       printf ( "\n\t %s",  Element_V8_4s(Tg,M,4) ) ;
       printf ( " %s", "\n\t VEUILLEZ ENTRER LE NOM DE L'EQUIPE FAVORITE DU GROUPE: " ) ;
       scanf ( " %[^\n]", Favorite ) ;
       strcpy(Favorite,strupr(Favorite));
       T_Tc [ 0 ] = 0 ;
       T_Tc [ 1 ] = 0 ;
       T_Tc [ 2 ] = 0 ;
       T_Tc [ 3 ] = 0 ;
       Init_vect_V4i ( Tc , T_Tc , 4 )  ;
       for( I  =  1 ;I <=  4 ; ++I){
         for( J  =  I + 1 ;J <=  4 ; ++J){
           Aff_struct1_Tsisi ( S  , Element_V8_4s ( Tg , M , I   ) ) ;
           Aff_struct3_Tsisi ( S  , Element_V8_4s ( Tg , M , J   ) ) ;
           if(strcmp( Element_V8_4s ( Tg , M , I   ), Favorite) == 0 ) {
             Aff_struct2_Tsisi ( S  , 4 ) ;
             Aff_struct4_Tsisi ( S  , 0 ) ;
             }
           else
             {
             if(strcmp( Element_V8_4s ( Tg , M , J   ), Favorite) == 0 ) {
               Aff_struct2_Tsisi ( S  , 0 ) ;
               Aff_struct4_Tsisi ( S  , 4 ) ;
               }
             else
               {
               A  =  I ;
               B  =  J ;
               Points ( & A , & B ) ;
              /*GENERATION ALEATOIRE DES POINTS*/
               Aff_struct2_Tsisi ( S  , A ) ;
               Aff_struct4_Tsisi ( S  , B ) ;

             } ;

           } ;
           Allouer_LTsisi (& P ) ;
           Aff_val_LTsisi ( P , S ) ;
           Aff_adr_LTsisi ( Q , P ) ;
           Q  =  P ;
           Aff_element_V4i ( Tc , I   , Element_V4i ( Tc , I   ) + Struct2_Tsisi ( S  ) ) ;
           Aff_element_V4i ( Tc , J   , Element_V4i ( Tc , J   ) + Struct4_Tsisi ( S  ) ) ;

         } ;

       } ;
       printf ( " \n\t%s\n", " ===============================" ) ;
       Aff_adr_LTsisi ( Q , NULL ) ;
       for( K  =  1 ;K <=  4 ; ++K){
         Aff_struct1_Tsi ( S2  , Element_V8_4s ( Tg , M , K   ) ) ;
         Aff_struct2_Tsi ( S2  , Element_V4i ( Tc , K   ) ) ;
         Aff_element_V4Tsi ( Td , K   , S2 ) ;

       } ;
       for( U  =  1 ;U <=  4 ; ++U){
         N  =  1 ;
         while( N < 4)  {
           if( Element_V4i ( Tc , N   ) > Element_V4i ( Tc , N + 1   )) {
             C  =  Element_V4i ( Tc , N   ) ;
             Aff_element_V4i ( Tc , N   , Element_V4i ( Tc , N + 1   ) ) ;
             Aff_element_V4i ( Tc , N + 1   , C ) ;
      /* Affectation globale de structure */
             strcpy(Tmp->Champ1,   Element_V4Tsi ( Td , N   )->Champ1);
             Tmp->Champ2 =   Element_V4Tsi ( Td , N   )->Champ2;
 ;
             Aff_element_V4Tsi ( Td , N   , Element_V4Tsi ( Td , N + 1   ) ) ;
             Aff_element_V4Tsi ( Td , N + 1   , Tmp ) ;

           } ;
           N  =  N + 1 ;

         } ;

       } ;
       Aff_element_V8s ( Te1 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 4   )  ) ) ;
       Aff_element_V8s ( Te2 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 3   )  ) ) ;
       Jj  =  Jj + 1 ;

     } ;
     for( Jj  =  1 ;Jj <=  8 ; ++Jj){
       textcolor(6);
       printf ( " %s", "\n\n\t  GROUPE:" );
       printf ( " %d", Jj ) ;
       textcolor(15);
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE1:" );
       printf ( " %s", Element_V8s(Te1,Jj) ) ;
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE2:" );
       printf ( " %s", Element_V8s(Te2,Jj) ) ;
     } ;

    }
  void Moins_fav_grp()
    {
      /** Variables locales **/
      Typevect_V8_4s Tg;
      Typevect_V4Tsi Td;
      Typevect_V8s Te1;
      Typevect_V8s Te2;
      Typevect_V4i Tc;
      Typestr_Tsi S1;
      Typestr_Tsi S2;
      Typestr_Tsi Tmp;
      int Jj;
      int A;
      int B;
      int I;
      int J;
      int X;
      int T;
      int M;
      int K;
      int N;
      int U;
      int C;
      int D;
      Pointeur_LTsisi Tete=NULL;
      Pointeur_LTsisi P=NULL;
      Pointeur_LTsisi Q=NULL;
      Pointeur_LTsisi L=NULL;
      Typestr_Tsisi S;
      string255 Moins_favorite;
        Typetab_V4i T_Tc;

      /** Corps du module **/
     Tg = malloc(8*4 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<8*4; ++_Izw2)
       Tg[_Izw2]= malloc(255 * sizeof(char));
     Td = malloc(4 * sizeof(Typestr_Tsi));
     int _Izw3;for (_Izw3=0; _Izw3<4; ++_Izw3)
       Td[_Izw3] = malloc( sizeof(Type_Tsi ));
     int _Izw4;for (_Izw4=0; _Izw4<4; ++_Izw4){
       Td[_Izw4]->Champ1= malloc(255 * sizeof(char));}
     Te1 = malloc(8 * 255  * sizeof(char));
     int _Izw5;for (_Izw5=0; _Izw5<8; ++_Izw5)
       Te1[_Izw5]= malloc(255 * sizeof(char));
     Te2 = malloc(8 * 255  * sizeof(char));
     int _Izw6;for (_Izw6=0; _Izw6<8; ++_Izw6)
       Te2[_Izw6]= malloc(255 * sizeof(char));
     Tc = malloc(4 * sizeof(int));
     S1 = malloc(sizeof(Type_Tsi));
     S1->Champ1 = malloc(255 * sizeof(char));
     S2 = malloc(sizeof(Type_Tsi));
     S2->Champ1 = malloc(255 * sizeof(char));
     Tmp = malloc(sizeof(Type_Tsi));
     Tmp->Champ1 = malloc(255 * sizeof(char));
     S = malloc(sizeof(Type_Tsisi));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ3 = malloc(255 * sizeof(char));
     Moins_favorite = malloc(255 * sizeof(char));
     Jj  =  1 ;
    /*INITIALISATION DU TABLEAU DES EQUIPES*/
     Init32 ( & Tg ) ;
     Aff_struct1_Tsisi ( S  , "PAYS-BAS" ) ;
     Aff_struct3_Tsisi ( S  , "SENEGAL" ) ;
     Aff_struct2_Tsisi ( S  , 1 ) ;
     Aff_struct4_Tsisi ( S  , 2 ) ;
     Allouer_LTsisi (& P ) ;
     Aff_val_LTsisi ( P , S ) ;
     Tete  =  P ;
     Q  =  P ;
     for( M  =  1 ;M <=  8 ; ++M){
       textcolor(6);
       printf ( " %s", "\n\t LES EQUIPES DU GROUPE:" );
       printf ( " %d", M );
       textcolor(15);
       printf ( "\n\t %s",  Element_V8_4s(Tg,M,1) );
       printf ( "\n\t %s",  Element_V8_4s(Tg,M,2) );
       printf ( "\n\t %s",  Element_V8_4s(Tg,M,3) );
       printf ( "\n\t %s",  Element_V8_4s(Tg,M,4) ) ;
       printf ( " %s", "\n\t VEUILLEZ ENTRER LE NOM DE L'EQUIPE LA MOINS FAVORITE DU GROUPE: " ) ;
       scanf ( " %[^\n]", Moins_favorite ) ;
       strcpy(Moins_favorite,strupr(Moins_favorite));
       T_Tc [ 0 ] = 0 ;
       T_Tc [ 1 ] = 0 ;
       T_Tc [ 2 ] = 0 ;
       T_Tc [ 3 ] = 0 ;
       Init_vect_V4i ( Tc , T_Tc , 4 )  ;
       for( I  =  1 ;I <=  4 ; ++I){
         for( J  =  I + 1 ;J <=  4 ; ++J){
           Aff_struct1_Tsisi ( S  , Element_V8_4s ( Tg , M , I   ) ) ;
           Aff_struct3_Tsisi ( S  , Element_V8_4s ( Tg , M , J   ) ) ;
           if(strcmp( Element_V8_4s ( Tg , M , I   ), Moins_favorite) == 0 ) {
             Aff_struct2_Tsisi ( S  , 0 ) ;
             Aff_struct4_Tsisi ( S  , 4 ) ;
             }
           else
             {
             if(strcmp( Element_V8_4s ( Tg , M , J   ), Moins_favorite) == 0 ) {
               Aff_struct2_Tsisi ( S  , 4 ) ;
               Aff_struct4_Tsisi ( S  , 0 ) ;
               }
             else
               {
               A  =  I ;
               B  =  J ;
               Points ( & A , & B ) ;
              /*GENERATION ALEATOIRE DES POINTS*/
               Aff_struct2_Tsisi ( S  , A ) ;
               Aff_struct4_Tsisi ( S  , B ) ;

             } ;

           } ;
           Allouer_LTsisi (& P ) ;
           Aff_val_LTsisi ( P , S ) ;
           Aff_adr_LTsisi ( Q , P ) ;
           Q  =  P ;
           Aff_element_V4i ( Tc , I   , Element_V4i ( Tc , I   ) + Struct2_Tsisi ( S  ) ) ;
           Aff_element_V4i ( Tc , J   , Element_V4i ( Tc , J   ) + Struct4_Tsisi ( S  ) ) ;

         } ;

       } ;
       Aff_adr_LTsisi ( Q , NULL ) ;
       for( K  =  1 ;K <=  4 ; ++K){
         Aff_struct1_Tsi ( S2  , Element_V8_4s ( Tg , M , K   ) ) ;
         Aff_struct2_Tsi ( S2  , Element_V4i ( Tc , K   ) ) ;
         Aff_element_V4Tsi ( Td , K   , S2 ) ;

       } ;
       for( U  =  1 ;U <=  4 ; ++U){
         N  =  1 ;
         while( N < 4)  {
           if( Element_V4i ( Tc , N   ) > Element_V4i ( Tc , N + 1   )) {
             C  =  Element_V4i ( Tc , N   ) ;
             Aff_element_V4i ( Tc , N   , Element_V4i ( Tc , N + 1   ) ) ;
             Aff_element_V4i ( Tc , N + 1   , C ) ;
      /* Affectation globale de structure */
             strcpy(Tmp->Champ1,   Element_V4Tsi ( Td , N   )->Champ1);
             Tmp->Champ2 =   Element_V4Tsi ( Td , N   )->Champ2;
 ;
             Aff_element_V4Tsi ( Td , N   , Element_V4Tsi ( Td , N + 1   ) ) ;
             Aff_element_V4Tsi ( Td , N + 1   , Tmp ) ;

           } ;
           N  =  N + 1 ;

         } ;

       } ;
       Aff_element_V8s ( Te1 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 4   )  ) ) ;
       Aff_element_V8s ( Te2 , Jj   , Struct1_Tsi ( Element_V4Tsi ( Td , 3   )  ) ) ;
       Jj  =  Jj + 1 ;

     } ;
     for( Jj  =  1 ;Jj <=  8 ; ++Jj){
      textcolor(6);
       printf ( " %s", "\n\n\t  GROUPE:" );
       printf ( " %d", Jj ) ;
       textcolor(15);
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE1:" );
       printf ( " %s", Element_V8s(Te1,Jj) ) ;
       printf ( " %s", "\n\t  EQUIPE QUALIFIEE2:" );
       printf ( " %s", Element_V8s(Te2,Jj) ) ;

     } ;

    }
  void Aff()
    {
      /** Variables locales **/
      Typevect_V8_4s Tg;
      Typevect_V4Tsi Td;
      Typevect_V4i Tc;
      Typestr_Tsi S1;
      Typestr_Tsi S2;
      int A;
      int B;
      int I;
      int J;
      int M;
      int K;
      int C;
      Pointeur_LTsisi Tete=NULL;
      Pointeur_LTsisi P=NULL;
      Pointeur_LTsisi Q=NULL;
      Typestr_Tsisi S;
        Typetab_V4i T_Tc;

      /** Corps du module **/
     Tg = malloc(8*4 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<8*4; ++_Izw2)
       Tg[_Izw2]= malloc(255 * sizeof(char));
     Td = malloc(4 * sizeof(Typestr_Tsi));
     int _Izw3;for (_Izw3=0; _Izw3<4; ++_Izw3)
       Td[_Izw3] = malloc( sizeof(Type_Tsi ));
     int _Izw4;for (_Izw4=0; _Izw4<4; ++_Izw4){
       Td[_Izw4]->Champ1= malloc(255 * sizeof(char));}
     Tc = malloc(4 * sizeof(int));
     S1 = malloc(sizeof(Type_Tsi));
     S1->Champ1 = malloc(255 * sizeof(char));
     S2 = malloc(sizeof(Type_Tsi));
     S2->Champ1 = malloc(255 * sizeof(char));
     S = malloc(sizeof(Type_Tsisi));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ3 = malloc(255 * sizeof(char));
     Init32 ( & Tg ) ;
     Aff_struct1_Tsisi ( S  , "PAYS-BAS" ) ;
     Aff_struct3_Tsisi ( S  , "SENEGAL" ) ;
     Aff_struct2_Tsisi ( S  , 1 ) ;
     Aff_struct4_Tsisi ( S  , 2 ) ;
     Allouer_LTsisi (& P ) ;
     Aff_val_LTsisi ( P , S ) ;
     Tete  =  P ;
     Q  =  P ;
     for( M  =  1 ;M <=  8 ; ++M){
       T_Tc [ 0 ] = 0 ;
       T_Tc [ 1 ] = 0 ;
       T_Tc [ 2 ] = 0 ;
       T_Tc [ 3 ] = 0 ;
       Init_vect_V4i ( Tc , T_Tc , 4 )  ;
       for( I  =  1 ;I <=  4 ; ++I){
         for( J  =  I + 1 ;J <=  4 ; ++J){
           textcolor(6);
           printf ( "\n\t %s", "================" ) ;
           Aff_struct1_Tsisi ( S  , Element_V8_4s ( Tg , M , I   ) ) ;
           Aff_struct3_Tsisi ( S  , Element_V8_4s ( Tg , M , J   ) ) ;
           textcolor(15);
           printf ( "\n\t %s", Struct1_Tsisi(S) ) ;
           textcolor(6);
           printf ( "\n\t %s", "VS" ) ;
           textcolor(15);
           printf ( "\n\t %s", Struct3_Tsisi(S) ) ;
           A  =  I ;
           B  =  J ;
           Points ( & A , & B ) ;
          /*GENERATION ALEATOIRE DES POINTS*/
           Aff_struct2_Tsisi ( S  , A ) ;
           Aff_struct4_Tsisi ( S  , B ) ;
           Allouer_LTsisi (& P ) ;
           Aff_val_LTsisi ( P , S ) ;
           Aff_adr_LTsisi ( Q , P ) ;
           Q  =  P ;
           Aff_element_V4i ( Tc , I   , Element_V4i ( Tc , I   ) + Struct2_Tsisi ( S  ) ) ;
           Aff_element_V4i ( Tc , J   , Element_V4i ( Tc , J   ) + Struct4_Tsisi ( S  ) ) ;

         } ;

       } ;
       textcolor(6);
       printf ( "\n\t %s", "================" ) ;
       textcolor(15);
       Aff_adr_LTsisi ( Q , NULL ) ;
       for( K  =  1 ;K <=  4 ; ++K){
         Aff_struct1_Tsi ( S2  , Element_V8_4s ( Tg , M , K   ) ) ;
         Aff_struct2_Tsi ( S2  , Element_V4i ( Tc , K   ) ) ;
         Aff_element_V4Tsi ( Td , K   , S2 ) ;

       } ;

     } ;

    }

  string255  Gagnant (string255 *E1 , string255 *E2)
    {
      /** Variables locales **/
      string255  Gagnant2 ;
      int M;

      /** Corps du module **/
     Gagnant2 = malloc(255 * sizeof(char));
     M  =  Aleanombre(2 ) ;
     if( M == 1) {
       strcpy (Gagnant2,   *E1) ;
       }
     else
       {
       strcpy (Gagnant2,   *E2) ;

     } ;

     return Gagnant2 ;
    }
  void Hasard12 (Pointeur_ATss *R)
    {
      /** Variables locales **/
      Pointeur_ATss P=NULL;
      Pointeur_ATss Q=NULL;
      Pointeur_ATss T=NULL;
      Typestr_Tss S;
      Typestr_Tss S1;
      int I;
      int J;
      int K;
      int L;
      string255 Val;
      Typevect_V16s Tab;
      Type_Tss _Struct_Temp9;
      string255 _Px1;
      string255 _Px2;
      string255 _Px3;
      string255 _Px4;
      string255 _Px5;
      string255 _Px6;
      string255 _Px7;
      string255 _Px8;
      Type_Tss _Struct_Temp10;
      Type_Tss _Struct_Temp11;
      Type_Tss _Struct_Temp12;
      Type_Tss _Struct_Temp13;
      string255 _Px9;
      string255 _Px10;
      string255 _Px11;
      string255 _Px12;
      Type_Tss _Struct_Temp14;
      string255 _Px13;
      string255 _Px14;
      string255 _Px15;
      string255 _Px16;
      Type_Tss _Struct_Temp15;
      string255 _Px17;
      string255 _Px18;
      string255 _Px19;
      string255 _Px20;
      Type_Tss _Struct_Temp16;
      string255 _Px21;
      string255 _Px22;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tss));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ2 = malloc(255 * sizeof(char));
     S1 = malloc(sizeof(Type_Tss));
     S1->Champ1 = malloc(255 * sizeof(char));
     S1->Champ2 = malloc(255 * sizeof(char));
     Val = malloc(255 * sizeof(char));
     Tab = malloc(16 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<16; ++_Izw2)
       Tab[_Izw2]= malloc(255 * sizeof(char));
     _Px1 = malloc(255 * sizeof(char));
     _Px2 = malloc(255 * sizeof(char));
     _Px3 = malloc(255 * sizeof(char));
     _Px4 = malloc(255 * sizeof(char));
     _Px5 = malloc(255 * sizeof(char));
     _Px6 = malloc(255 * sizeof(char));
     _Px7 = malloc(255 * sizeof(char));
     _Px8 = malloc(255 * sizeof(char));
     _Px9 = malloc(255 * sizeof(char));
     _Px10 = malloc(255 * sizeof(char));
     _Px11 = malloc(255 * sizeof(char));
     _Px12 = malloc(255 * sizeof(char));
     _Px13 = malloc(255 * sizeof(char));
     _Px14 = malloc(255 * sizeof(char));
     _Px15 = malloc(255 * sizeof(char));
     _Px16 = malloc(255 * sizeof(char));
     _Px17 = malloc(255 * sizeof(char));
     _Px18 = malloc(255 * sizeof(char));
     _Px19 = malloc(255 * sizeof(char));
     _Px20 = malloc(255 * sizeof(char));
     _Px21 = malloc(255 * sizeof(char));
     _Px22 = malloc(255 * sizeof(char));
     Hasard11 ( & Tab ) ;
     K  =  1 ;
     textcolor(6);
     printf ( " %s", "\n\n\t  HUITIEME DE FINALE:" );
     printf ( " %s", "\n\t ============" ) ;
     textcolor(15);
     for( J  =  1 ;J <=  2 ; ++J){
       for( I  =  1 ;I <=  4 ; ++I){
         Creernoeud_ATss (& P ) ;
         Creernoeud_ATss (& T ) ;
         Aff_struct1_Tss ( S  , Element_V16s ( Tab , K   ) ) ;
         Aff_struct2_Tss ( S  , Element_V16s ( Tab , K + 1   ) ) ;
         Aff_info_ATss ( T , S ) ;
         /** Ecriture d'une structure */
         _Struct_Temp9 = *Info_ATss(T);
         printf ( "\n\t %s", _Struct_Temp9.Champ1 );
         printf ( "\n\t %s", _Struct_Temp9.Champ2 );
         printf ( " %s", "\n\t ============" ) ;
         Creernoeud_ATss (& T ) ;
         if( Mod ( I , 2 ) == 1) {
           Aff_fg_ATss ( P , T ) ;
           }
         else
           {
           if( I == 2) {
             Aff_fd_ATss ( P , T ) ;
             strcpy(_Px1,  Element_V16s ( Tab , K - 2   ) );
             strcpy(_Px2,  Element_V16s ( Tab , K - 1   ) );
             Aff_struct1_Tss ( S  , Gagnant ( &_Px1, &_Px2) ) ;
             strcpy(_Px3,  Element_V16s ( Tab , K   ) );
             strcpy(_Px4,  Element_V16s ( Tab , K + 1   ) );
             Aff_struct2_Tss ( S  , Gagnant ( &_Px3, &_Px4) ) ;
             Aff_info_ATss ( P , S ) ;
             Creernoeud_ATss (& Q ) ;
             Aff_fd_ATss ( Q , P ) ;

           } ;

         } ;
         if( I == 4) {
           Aff_fg_ATss ( Q , P ) ;
           strcpy(_Px5,  Element_V16s ( Tab , K - 2   ) );
           strcpy(_Px6,  Element_V16s ( Tab , K - 1   ) );
           Aff_struct1_Tss ( S  , Gagnant ( &_Px5, &_Px6) ) ;
           strcpy(_Px7,  Element_V16s ( Tab , K   ) );
           strcpy(_Px8,  Element_V16s ( Tab , K + 1   ) );
           Aff_struct2_Tss ( S  , Gagnant ( &_Px7, &_Px8) ) ;
           Aff_info_ATss ( P , S ) ;

         } ;
         K  =  K + 2 ;

       } ;
       if( J == 1) {
         Creernoeud_ATss (& *R ) ;
         Aff_fd_ATss ( *R , Q ) ;
         }
       else
         {
         Aff_fg_ATss ( *R , Q ) ;

       } ;

     } ;
     textcolor(6);
     printf ( " %s", "\n\n\t  QUART DE FINALE:" );
     textcolor(15);
     printf ( " %s", "\n\t ===============" ) ;
     /** Ecriture d'une structure */
     _Struct_Temp10 = *Info_ATss(Fd_ATss(Fd_ATss(*R)));
     printf ( "\n\t %s", _Struct_Temp10.Champ1 );
     printf ( "\n\t %s", _Struct_Temp10.Champ2 );
     printf ( " %s", "\n\t ===============" ) ;
     /** Ecriture d'une structure */
     _Struct_Temp11 = *Info_ATss(Fg_ATss(Fd_ATss(*R)));
     printf ( "\n\t %s", _Struct_Temp11.Champ1 );
     printf ( "\n\t %s", _Struct_Temp11.Champ2 );
     printf ( " %s", "\n\t ===============" ) ;
     /** Ecriture d'une structure */
     _Struct_Temp12 = *Info_ATss(Fd_ATss(Fg_ATss(*R)));
     printf ( "\n\t %s", _Struct_Temp12.Champ1 );
     printf ( "\n\t %s", _Struct_Temp12.Champ2 );
     printf ( " %s", "\n\t ===============" ) ;
     /** Ecriture d'une structure */
     _Struct_Temp13 = *Info_ATss(Fg_ATss(Fg_ATss(*R)));
     printf ( "\n\t %s", _Struct_Temp13.Champ1 );
     printf ( "\n\t %s", _Struct_Temp13.Champ2 );
     printf ( " %s", "\n\t ===============" ) ;
     textcolor(6);
     printf ( " %s", "\n\n\t DEMI FINALE:" );
     textcolor(15);
     printf ( " %s", "\n\t ===============" ) ;
     P  =  Fd_ATss ( Fd_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px9,  Struct1_Tss ( S  ) );
     strcpy(_Px10,  Struct2_Tss ( S  ) );
     Aff_struct1_Tss ( S1  , Gagnant ( &_Px9, &_Px10) ) ;
     P  =  Fg_ATss ( Fd_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px11,  Struct1_Tss ( S  ) );
     strcpy(_Px12,  Struct2_Tss ( S  ) );
     Aff_struct2_Tss ( S1  , Gagnant ( &_Px11, &_Px12) ) ;
     Aff_info_ATss ( Fd_ATss ( *R ) , S1 ) ;
     /** Ecriture d'une structure */
     _Struct_Temp14 = *Info_ATss(Fd_ATss(*R));
     printf ( "\n\t %s", _Struct_Temp14.Champ1 );
     printf ( "\n\t %s", _Struct_Temp14.Champ2 );
     printf ( " %s", "\n\t ===============" ) ;
     P  =  Fd_ATss ( Fg_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px13,  Struct1_Tss ( S  ) );
     strcpy(_Px14,  Struct2_Tss ( S  ) );
     Aff_struct1_Tss ( S1  , Gagnant ( &_Px13, &_Px14) ) ;
     P  =  Fg_ATss ( Fg_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px15,  Struct1_Tss ( S  ) );
     strcpy(_Px16,  Struct2_Tss ( S  ) );
     Aff_struct2_Tss ( S1  , Gagnant ( &_Px15, &_Px16) ) ;
     Aff_info_ATss ( Fg_ATss ( *R ) , S1 ) ;
     /** Ecriture d'une structure */
     _Struct_Temp15 = *Info_ATss(Fg_ATss(*R));
     printf ( "\n\t %s", _Struct_Temp15.Champ1 );
     printf ( "\n\t %s", _Struct_Temp15.Champ2 );
     printf ( " %s", "\n\t ============" ) ;
     textcolor(6);
     printf ( " %s", "\n\n\t LA FINALE:" );
     textcolor(15);
     P  =  Fd_ATss ( *R ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px17,  Struct1_Tss ( S  ) );
     strcpy(_Px18,  Struct2_Tss ( S  ) );
     Aff_struct1_Tss ( S1  , Gagnant ( &_Px17, &_Px18) ) ;
     P  =  Fg_ATss ( *R ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px19,  Struct1_Tss ( S  ) );
     strcpy(_Px20,  Struct2_Tss ( S  ) );
     Aff_struct2_Tss ( S1  , Gagnant ( &_Px19, &_Px20) ) ;
     Aff_info_ATss ( *R , S1 ) ;
     /** Ecriture d'une structure */
     _Struct_Temp16 = *Info_ATss(*R);
     printf ( "\n\t %s", _Struct_Temp16.Champ1 );
     printf ( "\n\t %s", _Struct_Temp16.Champ2 );
     textcolor(6);
     printf ( " %s", "\n\n\tL'EQUIPE GAGNANTE EST : " ) ;
     textcolor(15);
     strcpy(_Px21,  Struct1_Tss ( S1  ) );
     strcpy(_Px22,  Struct2_Tss ( S1  ) );
     printf ( " %s", Gagnant(&_Px21,&_Px22) );


    }
  void Fav12 (Pointeur_ATss *R)
    {
      /** Variables locales **/
      Pointeur_ATss P=NULL;
      Pointeur_ATss Q=NULL;
      Pointeur_ATss T=NULL;
      Typestr_Tss S;
      Typestr_Tss S1;
      Typestr_Tss S2;
      Typestr_Tss Val;
      Pointeur_FTss Fil=NULL;
      int I;
      int J;
      int K;
      int L;
      int Fav;
      string255 Favorite;
      Typevect_V16s Tab;
      Type_Tss _Struct_Temp17;
      string255 _Px1;
      string255 _Px2;
      string255 _Px3;
      string255 _Px4;
      string255 _Px5;
      string255 _Px6;
      string255 _Px7;
      string255 _Px8;
      string255 _Px9;
      string255 _Px10;
      string255 _Px11;
      string255 _Px12;
      string255 _Px13;
      string255 _Px14;
      string255 _Px15;
      string255 _Px16;
      Type_Tss _Struct_Temp18;
      Type_Tss _Struct_Temp19;
      string255 _Px17;
      string255 _Px18;
      Type_Tss _Struct_Temp20;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tss));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ2 = malloc(255 * sizeof(char));
     S1 = malloc(sizeof(Type_Tss));
     S1->Champ1 = malloc(255 * sizeof(char));
     S1->Champ2 = malloc(255 * sizeof(char));
     S2 = malloc(sizeof(Type_Tss));
     S2->Champ1 = malloc(255 * sizeof(char));
     S2->Champ2 = malloc(255 * sizeof(char));
     Val = malloc(sizeof(Type_Tss));
     Val->Champ1 = malloc(255 * sizeof(char));
     Val->Champ2 = malloc(255 * sizeof(char));
     Favorite = malloc(255 * sizeof(char));
     Tab = malloc(16 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<16; ++_Izw2)
       Tab[_Izw2]= malloc(255 * sizeof(char));
     _Px1 = malloc(255 * sizeof(char));
     _Px2 = malloc(255 * sizeof(char));
     _Px3 = malloc(255 * sizeof(char));
     _Px4 = malloc(255 * sizeof(char));
     _Px5 = malloc(255 * sizeof(char));
     _Px6 = malloc(255 * sizeof(char));
     _Px7 = malloc(255 * sizeof(char));
     _Px8 = malloc(255 * sizeof(char));
     _Px9 = malloc(255 * sizeof(char));
     _Px10 = malloc(255 * sizeof(char));
     _Px11 = malloc(255 * sizeof(char));
     _Px12 = malloc(255 * sizeof(char));
     _Px13 = malloc(255 * sizeof(char));
     _Px14 = malloc(255 * sizeof(char));
     _Px15 = malloc(255 * sizeof(char));
     _Px16 = malloc(255 * sizeof(char));
     _Px17 = malloc(255 * sizeof(char));
     _Px18 = malloc(255 * sizeof(char));
     Hasard11 ( & Tab ) ;
     printf ( " %s", "\n\n\n\t LES EQUIPES RETENUES DANS LA PHASE 1 SONT:" ) ;
     for( I  =  1 ;I <=  16 ; ++I){
       textcolor(6);
       printf ( "\n\t %s", "-" );
       printf ( "%d", I );
     textcolor(15);
       printf ( " %s",  Element_V16s(Tab,I) ) ;

     } ;
     Creerfile_FTss (& Fil ) ;
     printf ( " %s", "\n\t VEUILLEZ ENTRER LE NUMERO DE VOTRE EQUIPE FAVORITE " ) ;
     scanf ( " %d", &Fav ) ;
     strcpy (Favorite,   Element_V16s ( Tab , Fav   )) ;
     K  =  1 ;
     textcolor(6);
     printf ( " %s", "\n\n\t HUITIEME DE FINALE:" );
     textcolor(15);
     printf ( " %s", "\n\t ============" ) ;
     for( J  =  1 ;J <=  2 ; ++J){
       for( I  =  1 ;I <=  4 ; ++I){
         Creernoeud_ATss (& P ) ;
         Creernoeud_ATss (& T ) ;
         Aff_struct1_Tss ( S  , Element_V16s ( Tab , K   ) ) ;
         Aff_struct2_Tss ( S  , Element_V16s ( Tab , K + 1   ) ) ;
         Aff_info_ATss ( T , S ) ;
         /** Ecriture d'une structure */
         _Struct_Temp17 = *Info_ATss(T);
         printf ( "\n\t %s", _Struct_Temp17.Champ1 );
         printf ( "\n\t %s", _Struct_Temp17.Champ2 );
         printf ( " %s", "\n\t ============" ) ;
         Creernoeud_ATss (& T ) ;
         if( Mod ( I , 2 ) == 1) {
           Aff_fg_ATss ( P , T ) ;
           }
         else
           {
           if( I == 2) {
             Aff_fd_ATss ( P , T ) ;
             if( ( Fav == K - 2 ) || ( Fav == K - 1 )) {
               Aff_struct1_Tss ( S  , Favorite ) ;
               }
             else
               {
               strcpy(_Px1,  Element_V16s ( Tab , K - 2   ) );
               strcpy(_Px2,  Element_V16s ( Tab , K - 1   ) );
               Aff_struct1_Tss ( S  , Gagnant ( &_Px1, &_Px2) ) ;

             } ;
             if( ( Fav == K ) || ( Fav == K + 1 )) {
               Aff_struct2_Tss ( S  , Favorite ) ;
               }
             else
               {
               strcpy(_Px3,  Element_V16s ( Tab , K   ) );
               strcpy(_Px4,  Element_V16s ( Tab , K + 1   ) );
               Aff_struct2_Tss ( S  , Gagnant ( &_Px3, &_Px4) ) ;

             } ;
             Aff_info_ATss ( P , S ) ;
             Enfiler_FTss ( Fil , Info_ATss ( P ) ) ;
             Creernoeud_ATss (& Q ) ;
             Aff_fd_ATss ( Q , P ) ;

           } ;

         } ;
         if( I == 4) {
           Aff_fg_ATss ( Q , P ) ;
           if( ( Fav == K - 2 ) || ( Fav == K - 1 )) {
             Aff_struct1_Tss ( S  , Favorite ) ;
             }
           else
             {
             strcpy(_Px5,  Element_V16s ( Tab , K - 2   ) );
             strcpy(_Px6,  Element_V16s ( Tab , K - 1   ) );
             Aff_struct1_Tss ( S  , Gagnant ( &_Px5, &_Px6) ) ;

           } ;
           if( ( Fav == K ) || ( Fav == K + 1 )) {
             Aff_struct2_Tss ( S  , Favorite ) ;
             }
           else
             {
             strcpy(_Px7,  Element_V16s ( Tab , K   ) );
             strcpy(_Px8,  Element_V16s ( Tab , K + 1   ) );
             Aff_struct2_Tss ( S  , Gagnant ( &_Px7, &_Px8) ) ;

           } ;
           Aff_info_ATss ( P , S ) ;
           Enfiler_FTss ( Fil , Info_ATss ( P ) ) ;

         } ;
         K  =  K + 2 ;

       } ;
       if( J == 1) {
         Creernoeud_ATss (& *R ) ;
         Aff_fd_ATss ( *R , Q ) ;
         }
       else
         {
         Aff_fg_ATss ( *R , Q ) ;

       } ;

     } ;
     textcolor(6);
     printf ( " %s", "\n\n\t QUART DE FINALE:" );
     textcolor(15);
     printf ( " %s", "\n\t ============" ) ;
     while( Filevide_FTss ( Fil ) == False) {
       Defiler_FTss ( Fil , &Val ) ;
       /** Ecriture d'une structure */
       printf ( "\n\t %s", Val->Champ1 );
       printf ( "\n\t %s", Val->Champ2 );
       printf ( " %s", "\n\t ============" ) ;

     } ;
     textcolor(6);
     printf ( " %s", "\n\n\t DEMI FINALE:" );
     textcolor(15);
     printf ( " %s", "\n\t ============" ) ;
     P  =  Fd_ATss ( Fd_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px9,  Struct1_Tss ( S  ) );
     strcpy(_Px10,  Struct2_Tss ( S  ) );
     Aff_struct1_Tss ( S1  , Gagnant ( &_Px9, &_Px10) ) ;
     if( (strcmp( Struct1_Tss ( S  ), Favorite) == 0  ) || (strcmp( Struct2_Tss ( S  ), Favorite) == 0  )) {
       Aff_struct1_Tss ( S1  , Favorite ) ;

     } ;
     P  =  Fg_ATss ( Fd_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px11,  Struct1_Tss ( S  ) );
     strcpy(_Px12,  Struct2_Tss ( S  ) );
     Aff_struct2_Tss ( S1  , Gagnant ( &_Px11, &_Px12) ) ;
     if( (strcmp( Struct1_Tss ( S  ), Favorite) == 0  ) || (strcmp( Struct2_Tss ( S  ), Favorite) == 0  )) {
       Aff_struct2_Tss ( S1  , Favorite ) ;

     } ;
     Aff_info_ATss ( Fd_ATss ( *R ) , S1 ) ;
     P  =  Fd_ATss ( Fg_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px13,  Struct1_Tss ( S  ) );
     strcpy(_Px14,  Struct2_Tss ( S  ) );
     Aff_struct1_Tss ( S1  , Gagnant ( &_Px13, &_Px14) ) ;
     if( (strcmp( Struct1_Tss ( S  ), Favorite) == 0  ) || (strcmp( Struct2_Tss ( S  ), Favorite) == 0  )) {
       Aff_struct1_Tss ( S1  , Favorite );
     } ;
     P  =  Fg_ATss ( Fg_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px15,  Struct1_Tss ( S  ) );
     strcpy(_Px16,  Struct2_Tss ( S  ) );
     Aff_struct2_Tss ( S1  , Gagnant ( &_Px15, &_Px16) ) ;
     if( (strcmp( Struct1_Tss ( S  ), Favorite) == 0  ) || (strcmp( Struct2_Tss ( S  ), Favorite) == 0  )) {
       Aff_struct2_Tss ( S1  , Favorite );
     } ;
     Aff_info_ATss ( Fg_ATss ( *R ) , S1 ) ;
     /** Ecriture d'une structure */
     _Struct_Temp18 = *Info_ATss(Fd_ATss(*R));
     printf ( "\n\t %s", _Struct_Temp18.Champ1 );
     printf ( "\n\t %s", _Struct_Temp18.Champ2 );
     printf ( " %s", "\n\t ============" ) ;
     /** Ecriture d'une structure */
     _Struct_Temp19 = *Info_ATss(Fg_ATss(*R));
     printf ( "\n\t %s", _Struct_Temp19.Champ1 );
     printf ( "\n\t %s", _Struct_Temp19.Champ2 );
     printf ( " %s", "\n\t ============" ) ;
     textcolor(6);
     printf ( " %s", "\n\n\t LA FINALE:" );
     textcolor(15);
     printf ( " %s", "\n\t ============" ) ;
     if( Fav < 9) {
      /* Affectation globale de structure */
       strcpy(S2->Champ1,   Info_ATss ( Fg_ATss ( *R ) )->Champ1);
       strcpy(S2->Champ2,   Info_ATss ( Fg_ATss ( *R ) )->Champ2);
 ;
       Aff_struct1_Tss ( S1  , Favorite ) ;
       }
     else
       {
      /* Affectation globale de structure */
       strcpy(S->Champ1,   Info_ATss ( Fd_ATss ( *R ) )->Champ1);
       strcpy(S->Champ2,   Info_ATss ( Fd_ATss ( *R ) )->Champ2);
 ;
       strcpy(_Px17,  Struct1_Tss ( S  ) );
       strcpy(_Px18,  Struct2_Tss ( S  ) );
       Aff_struct1_Tss ( S1  , Gagnant ( &_Px17, &_Px18) ) ;
       Aff_struct2_Tss ( S1  , Favorite ) ;

     } ;
     Aff_info_ATss ( *R , S1 ) ;
     /** Ecriture d'une structure */
     _Struct_Temp20 = *Info_ATss(*R);
     printf ( "\n\t %s", _Struct_Temp20.Champ1 );
     printf ( "\n\t %s", _Struct_Temp20.Champ2 );
     printf ( " %s", "\n\t ============" ) ;
     printf ( " %s", "\n\n\n\t ======================================" );
     textcolor(6);
     printf ( " %s", "\n\t L'EQUIPE GAGNANTE EST : " );
     textcolor(15);
     printf ( " %s", Favorite );
     printf ( " %s", "\n\t ======================================" ) ;

    }
  void Aff1 (Pointeur_ATss *R)
    {
      /** Variables locales **/
      Pointeur_ATss P=NULL;
      Pointeur_ATss Q=NULL;
      Pointeur_ATss T=NULL;
      Typestr_Tss S;
      Typestr_Tss S1;
      int I;
      int J;
      int K;
      int L;
      string255 Val;
      Typevect_V16s Tab;
      Type_Tss _Struct_Temp21;
      string255 _Px1;
      string255 _Px2;
      string255 _Px3;
      string255 _Px4;
      string255 _Px5;
      string255 _Px6;
      string255 _Px7;
      string255 _Px8;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tss));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ2 = malloc(255 * sizeof(char));
     S1 = malloc(sizeof(Type_Tss));
     S1->Champ1 = malloc(255 * sizeof(char));
     S1->Champ2 = malloc(255 * sizeof(char));
     Val = malloc(255 * sizeof(char));
     Tab = malloc(16 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<16; ++_Izw2)
       Tab[_Izw2]= malloc(255 * sizeof(char));
     _Px1 = malloc(255 * sizeof(char));
     _Px2 = malloc(255 * sizeof(char));
     _Px3 = malloc(255 * sizeof(char));
     _Px4 = malloc(255 * sizeof(char));
     _Px5 = malloc(255 * sizeof(char));
     _Px6 = malloc(255 * sizeof(char));
     _Px7 = malloc(255 * sizeof(char));
     _Px8 = malloc(255 * sizeof(char));
     Hasard11 ( & Tab ) ;
     K  =  1 ;
     textcolor(6);
     printf ( " %s", "\n\n\t HUITIEME DE FINALE:" );
     printf ( " %s", "\n\t ============" ) ;
     textcolor(15);
     for( J  =  1 ;J <=  2 ; ++J){
       for( I  =  1 ;I <=  4 ; ++I){
         Creernoeud_ATss (& P ) ;
         Creernoeud_ATss (& T ) ;
         Aff_struct1_Tss ( S  , Element_V16s ( Tab , K   ) ) ;
         Aff_struct2_Tss ( S  , Element_V16s ( Tab , K + 1   ) ) ;
         Aff_info_ATss ( T , S ) ;
         /** Ecriture d'une structure */
         _Struct_Temp21 = *Info_ATss(T);
         printf ( "\n\t %s", _Struct_Temp21.Champ1 );
         printf ( "\n\t %s", _Struct_Temp21.Champ2 );
         textcolor(6);
         printf ( " %s", "\n\t ============" ) ;
         textcolor(15);
         Creernoeud_ATss (& T ) ;
         if( Mod ( I , 2 ) == 1) {
           Aff_fg_ATss ( P , T ) ;
           }
         else
           {
           if( I == 2) {
             Aff_fd_ATss ( P , T ) ;
             strcpy(_Px1,  Element_V16s ( Tab , K - 2   ) );
             strcpy(_Px2,  Element_V16s ( Tab , K - 1   ) );
             Aff_struct1_Tss ( S  , Gagnant ( &_Px1, &_Px2) ) ;
             strcpy(_Px3,  Element_V16s ( Tab , K   ) );
             strcpy(_Px4,  Element_V16s ( Tab , K + 1   ) );
             Aff_struct2_Tss ( S  , Gagnant ( &_Px3, &_Px4) ) ;
             Aff_info_ATss ( P , S ) ;
             Creernoeud_ATss (& Q ) ;
             Aff_fd_ATss ( Q , P ) ;

           } ;

         } ;
         if( I == 4) {
           Aff_fg_ATss ( Q , P ) ;
           strcpy(_Px5,  Element_V16s ( Tab , K - 2   ) );
           strcpy(_Px6,  Element_V16s ( Tab , K - 1   ) );
           Aff_struct1_Tss ( S  , Gagnant ( &_Px5, &_Px6) ) ;
           strcpy(_Px7,  Element_V16s ( Tab , K   ) );
           strcpy(_Px8,  Element_V16s ( Tab , K + 1   ) );
           Aff_struct2_Tss ( S  , Gagnant ( &_Px7, &_Px8) ) ;
           Aff_info_ATss ( P , S ) ;

         } ;
         K  =  K + 2 ;

       } ;
       if( J == 1) {
         Creernoeud_ATss (& *R ) ;
         Aff_fd_ATss ( *R , Q ) ;
         }
       else
         {
         Aff_fg_ATss ( *R , Q ) ;

       } ;

     } ;

    }
  void M_fav12 (Pointeur_ATss *R)
    {
      /** Variables locales **/
      Pointeur_ATss P=NULL;
      Pointeur_ATss Q=NULL;
      Pointeur_ATss T=NULL;
      Typestr_Tss S;
      Typestr_Tss S1;
      Typestr_Tss S2;
      Typestr_Tss Val;
      Pointeur_FTss Fil=NULL;
      int I;
      int J;
      int K;
      int L;
      int Fav;
      string255 M_favorite;
      string255 V;
      Typevect_V16s Tab;
      Type_Tss _Struct_Temp22;
      string255 _Px1;
      string255 _Px2;
      string255 _Px3;
      string255 _Px4;
      string255 _Px5;
      string255 _Px6;
      string255 _Px7;
      string255 _Px8;
      string255 _Px9;
      string255 _Px10;
      string255 _Px11;
      string255 _Px12;
      string255 _Px13;
      string255 _Px14;
      string255 _Px15;
      string255 _Px16;
      Type_Tss _Struct_Temp23;
      Type_Tss _Struct_Temp24;
      string255 _Px17;
      string255 _Px18;
      string255 _Px19;
      string255 _Px20;
      Type_Tss _Struct_Temp25;
      string255 _Px21;
      string255 _Px22;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tss));
     S->Champ1 = malloc(255 * sizeof(char));
     S->Champ2 = malloc(255 * sizeof(char));
     S1 = malloc(sizeof(Type_Tss));
     S1->Champ1 = malloc(255 * sizeof(char));
     S1->Champ2 = malloc(255 * sizeof(char));
     S2 = malloc(sizeof(Type_Tss));
     S2->Champ1 = malloc(255 * sizeof(char));
     S2->Champ2 = malloc(255 * sizeof(char));
     Val = malloc(sizeof(Type_Tss));
     Val->Champ1 = malloc(255 * sizeof(char));
     Val->Champ2 = malloc(255 * sizeof(char));
     M_favorite = malloc(255 * sizeof(char));
     V = malloc(255 * sizeof(char));
     Tab = malloc(16 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<16; ++_Izw2)
       Tab[_Izw2]= malloc(255 * sizeof(char));
     _Px1 = malloc(255 * sizeof(char));
     _Px2 = malloc(255 * sizeof(char));
     _Px3 = malloc(255 * sizeof(char));
     _Px4 = malloc(255 * sizeof(char));
     _Px5 = malloc(255 * sizeof(char));
     _Px6 = malloc(255 * sizeof(char));
     _Px7 = malloc(255 * sizeof(char));
     _Px8 = malloc(255 * sizeof(char));
     _Px9 = malloc(255 * sizeof(char));
     _Px10 = malloc(255 * sizeof(char));
     _Px11 = malloc(255 * sizeof(char));
     _Px12 = malloc(255 * sizeof(char));
     _Px13 = malloc(255 * sizeof(char));
     _Px14 = malloc(255 * sizeof(char));
     _Px15 = malloc(255 * sizeof(char));
     _Px16 = malloc(255 * sizeof(char));
     _Px17 = malloc(255 * sizeof(char));
     _Px18 = malloc(255 * sizeof(char));
     _Px19 = malloc(255 * sizeof(char));
     _Px20 = malloc(255 * sizeof(char));
     _Px21 = malloc(255 * sizeof(char));
     _Px22 = malloc(255 * sizeof(char));
     Hasard11 ( & Tab ) ;
     printf ( "\n\n\t %s\n", " LES EQUIPES RETENUES DANS LA PHASE 1 SONT:" ) ;
     for( I  =  1 ;I <=  16 ; ++I){
        textcolor(6);
       printf ( "\n\t %s","-" );
       printf ( "%d",I );
       textcolor(15);
       printf ( " %s", Element_V16s(Tab,I) ) ;

     } ;
     Creerfile_FTss (& Fil ) ;
     printf ( " %s", "\n\t VEUILLEZ ENTRER LE NUMERO DE VOTRE EQUIPE MOINS FAVORITE: " ) ;
     scanf ( " %d", &Fav ) ;
     strcpy (M_favorite,   Element_V16s ( Tab , Fav   )) ;
     K  =  1 ;
     textcolor(6);
     printf ( " %s", "\n\n\t  HUITIEME DE FINALE" );
     textcolor(15);
     printf ( " %s", "\n\t ============" ) ;
     for( J  =  1 ;J <=  2 ; ++J){
       for( I  =  1 ;I <=  4 ; ++I){
         Creernoeud_ATss (& P ) ;
         Creernoeud_ATss (& T ) ;
         Aff_struct1_Tss ( S  , Element_V16s ( Tab , K   ) ) ;
         Aff_struct2_Tss ( S  , Element_V16s ( Tab , K + 1   ) ) ;
         Aff_info_ATss ( T , S ) ;
         /** Ecriture d'une structure */
         _Struct_Temp22 = *Info_ATss(T);
         printf ( "\n\t %s", _Struct_Temp22.Champ1 );
         printf ( "\n\t %s", _Struct_Temp22.Champ2 );
         printf ( " %s", "\n\t ============" ) ;
         Creernoeud_ATss (& T ) ;
         if( Mod ( I , 2 ) == 1) {
           Aff_fg_ATss ( P , T ) ;
           }
         else
           {
           if( I == 2) {
             Aff_fd_ATss ( P , T ) ;
             Aff_struct1_Tss ( S  , M_favorite ) ;
             while(strcmp( Struct1_Tss ( S  ), M_favorite) == 0 ) {
               strcpy(_Px1,  Element_V16s ( Tab , K - 2   ) );
               strcpy(_Px2,  Element_V16s ( Tab , K - 1   ) );
               Aff_struct1_Tss ( S  , Gagnant ( &_Px1, &_Px2) ) ;

             } ;
             Aff_struct2_Tss ( S  , M_favorite ) ;
             while(strcmp( Struct2_Tss ( S  ), M_favorite) == 0 ) {
               strcpy(_Px3,  Element_V16s ( Tab , K   ) );
               strcpy(_Px4,  Element_V16s ( Tab , K + 1   ) );
               Aff_struct2_Tss ( S  , Gagnant ( &_Px3, &_Px4) ) ;

             } ;
             Aff_info_ATss ( P , S ) ;
             Enfiler_FTss ( Fil , Info_ATss ( P ) ) ;
             Creernoeud_ATss (& Q ) ;
             Aff_fd_ATss ( Q , P ) ;

           } ;

         } ;
         if( I == 4) {
           Aff_fg_ATss ( Q , P ) ;
           Aff_struct1_Tss ( S  , M_favorite ) ;
           while(strcmp( Struct1_Tss ( S  ), M_favorite) == 0 ) {
             strcpy(_Px5,  Element_V16s ( Tab , K - 2   ) );
             strcpy(_Px6,  Element_V16s ( Tab , K - 1   ) );
             Aff_struct1_Tss ( S  , Gagnant ( &_Px5, &_Px6) ) ;

           } ;
           Aff_struct2_Tss ( S  , M_favorite ) ;
           while(strcmp( Struct2_Tss ( S  ), M_favorite) == 0 ) {
             strcpy(_Px7,  Element_V16s ( Tab , K   ) );
             strcpy(_Px8,  Element_V16s ( Tab , K + 1   ) );
             Aff_struct2_Tss ( S  , Gagnant ( &_Px7, &_Px8) ) ;

           } ;
           Aff_info_ATss ( P , S ) ;
           Enfiler_FTss ( Fil , Info_ATss ( P ) ) ;

         } ;
         K  =  K + 2 ;

       } ;
       if( J == 1) {
         Creernoeud_ATss (& *R ) ;
         Aff_fd_ATss ( *R , Q ) ;
         }
       else
         {
         Aff_fg_ATss ( *R , Q ) ;

       } ;

     } ;
     textcolor(6);
     printf ( " %s", "\n\n\t QUART DE FINALE:" );
     textcolor(15);
     printf ( " %s", "\n\t ============" ) ;
     while( Filevide_FTss ( Fil ) == False) {
       Defiler_FTss ( Fil , &Val ) ;
       /** Ecriture d'une structure */
       printf ( "\n\t %s", Val->Champ1 );
       printf ( "\n\t %s", Val->Champ2 );
       printf ( " %s", "\n\t ============" ) ;

     } ;
     textcolor(6);
     printf ( " %s", "\n\n\t DEMI FINALE:" );
     textcolor(15);
     printf ( " %s", "\n\t ============" ) ;
     P  =  Fd_ATss ( Fd_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px9,  Struct1_Tss ( S  ) );
     strcpy(_Px10,  Struct2_Tss ( S  ) );
     Aff_struct1_Tss ( S1  , Gagnant ( &_Px9, &_Px10) ) ;
     P  =  Fg_ATss ( Fd_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px11,  Struct1_Tss ( S  ) );
     strcpy(_Px12,  Struct2_Tss ( S  ) );
     Aff_struct2_Tss ( S1  , Gagnant ( &_Px11, &_Px12) ) ;
     Aff_info_ATss ( Fd_ATss ( *R ) , S1 ) ;
     P  =  Fd_ATss ( Fg_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px13,  Struct1_Tss ( S  ) );
     strcpy(_Px14,  Struct2_Tss ( S  ) );
     Aff_struct1_Tss ( S1  , Gagnant ( &_Px13, &_Px14) ) ;
     P  =  Fg_ATss ( Fg_ATss ( *R ) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( P )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( P )->Champ2);
 ;
     strcpy(_Px15,  Struct1_Tss ( S  ) );
     strcpy(_Px16,  Struct2_Tss ( S  ) );
     Aff_struct2_Tss ( S1  , Gagnant ( &_Px15, &_Px16) ) ;
     Aff_info_ATss ( Fg_ATss ( *R ) , S1 ) ;
     /** Ecriture d'une structure */
     _Struct_Temp23 = *Info_ATss(Fd_ATss(*R));
     printf ( "\n\t %s", _Struct_Temp23.Champ1 );
     printf ( "\n\t %s", _Struct_Temp23.Champ2 );
     printf ( " %s", "\n\t ============" ) ;
     /** Ecriture d'une structure */
     _Struct_Temp24 = *Info_ATss(Fg_ATss(*R));
     printf ( "\n\t %s", _Struct_Temp24.Champ1 );
     printf ( "\n\t %s", _Struct_Temp24.Champ2 );
     printf ( " %s", "\n\t ============" ) ;
     textcolor(6);
     printf ( " %s", "\n\n\t LA FINALE" );
     textcolor(15);
     printf ( " %s", "\n\t ============" ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( Fg_ATss ( *R ) )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( Fg_ATss ( *R ) )->Champ2);
 ;
     strcpy(_Px17,  Struct1_Tss ( S  ) );
     strcpy(_Px18,  Struct2_Tss ( S  ) );
     Aff_struct1_Tss ( S1  , Gagnant ( &_Px17, &_Px18) ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( Fd_ATss ( *R ) )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( Fd_ATss ( *R ) )->Champ2);
 ;
     strcpy(_Px19,  Struct1_Tss ( S  ) );
     strcpy(_Px20,  Struct2_Tss ( S  ) );
     Aff_struct2_Tss ( S1  , Gagnant ( &_Px19, &_Px20) ) ;
     Aff_info_ATss ( *R , S1 ) ;
     /** Ecriture d'une structure */
     _Struct_Temp25 = *Info_ATss(*R);
     printf ( "\n\t %s", _Struct_Temp25.Champ1 );
     printf ( "\n\t %s", _Struct_Temp25.Champ2 );
     printf ( " %s", "\n\t ============" ) ;
      /* Affectation globale de structure */
     strcpy(S->Champ1,   Info_ATss ( *R )->Champ1);
     strcpy(S->Champ2,   Info_ATss ( *R )->Champ2);
 ;
     strcpy(_Px21,  Struct1_Tss ( S  ) );
     strcpy(_Px22,  Struct2_Tss ( S  ) );
     strcpy (V,   Gagnant ( &_Px21, &_Px22)) ;
     printf ( " %s", "\n\n\n\t ===============================" );
     textcolor(6);
     printf ( " %s", "\n\t  L'EQUIPE GAGNANTE EST :" );
     textcolor(15);
     printf ( " %s", V );
     printf ( " %s", "\n\t ===============================" ) ;

    }

    void Menu (int *Ans)
    {

      /** Corps du module **/
      textcolor(6);
     printf ( " %s\n", "\n\n\t LES OPTIONS DISPONIBLES: " ) ;
     printf ( " %s", "\n\t 1-" ) ;
     textcolor(15);
     printf ( " %s", "AFFICHAGE DES RENCONTRES" ) ;
     textcolor(6);
     printf ( " %s", "\n\t 2-" ) ;
     textcolor(15);
     printf ( " %s", "SELECTION DES EQUIPES QUALIFIEES: AU HASARD " ) ;
     textcolor(6);
     printf ( " %s", "\n\t 3-" ) ;
     textcolor(15);
     printf ( " %s", "EQUIPES FAVORITES SELON LE CLASSEMENT MONDIAL DE LA FIFA 2022" ) ;
     textcolor(6);
     printf ( " %s", "\n\t 4-" ) ;
     textcolor(15);
     printf ( " %s", "SELECTION DES EQUIPES QUALIFIEES: EQUIPE FAVORITE ENTREE PAR L'UTILISATEUR" ) ;
     textcolor(6);
     printf ( " %s", "\n\t 5-" ) ;
     textcolor(15);
     printf ( " %s", "SELECTION DE L'EQUIPE GAGNANTE: EQUIPE FAVORITE DE CHAQUE GROUPE ENTREE PAR L''UTILISATEUR" ) ;
     textcolor(6);
     printf ( " %s", "\n\t 6-" ) ;
     textcolor(15);
     printf ( " %s", "SELECTION DE L'EQUIPE PERDANTE: EQUIPE MOINS FAVORITE" ) ;
     textcolor(6);
     printf ( " %s", "\n\t 7-" ) ;
     textcolor(15);
     printf ( " %s", "SELECTION DE L'EQUIPE PERDANTE: EQUIPE MOINS FAVORITE DE CHAQUE GROUPE" ) ;
     textcolor(6);
     printf ( " %s", "\n\t 0-" ) ;
     textcolor(15);
     printf ( " %s", "RETOUR DANS LE MENU PRINCIPAL" ) ;
     printf ( " %s", "\n\n\t L'OPERATION PRECEDENTE VA ETRE REPETEE SI VOUS NE REPONDEZ PAS " ) ;
     printf ( " %s", "\n\n\t ENTREZ VOTRE CHOIX: " ) ;
     scanf ( " %d", &*Ans ) ;
    }

    void Phase1()
    {
      /** Variables locales **/
      int Ans;

      /** Corps du module **/
      system("cls");
     textcolor(6);
     printf ( " %s", "\n\t CECI EST LA SIMULATION DE LA PHASE 1 DES RENCONTRES" ) ;
     textcolor(15);
     Ans  =  1 ;
     Menu ( & Ans ) ;
     while( Ans != 0)  {
       if( Ans == 1) {
         system("cls");
         Aff() ;
         printf ( "\n\n%s", " " ) ;

       } ;
       if( Ans == 2) {
         system("cls");
         Hasard1 ( & Tabl ) ;
          printf ( "\n\n%s", " " ) ;

       } ;
       if( Ans == 3) {
         system("cls");
         Fav_pre1 ( & Tabl ) ;
          printf ( "\n\n%s", " " ) ;

       } ;
       if( Ans == 4) {
         system("cls");
         Fav() ;
          printf ( "\n\n%s", " " ) ;

       } ;
       if( Ans == 5) {
         system("cls");
         Fav_grp() ;
        printf ( "\n\n%s", " " ) ;
       } ;
       if( Ans == 6) {
         system("cls");
         Moins_fav() ;
          printf ( "\n\n%s", " " ) ;

       } ;
       if( Ans == 7) {
        system("cls");
         Moins_fav_grp() ;
          printf ( "\n\n%s", " " ) ;

       } ;

       Menu ( & Ans ) ;

     } ;

    }


    void Phase2()
    {
      /** Variables locales **/
      int Ans;

      /** Corps du module **/
     textcolor(6);
     printf ( " %s", "\n\tLA SIMULATION DE LA PHASE 2 DES RENCONTRES" ) ;
     textcolor(15);
     Ans  =  1 ;
     Menu2 ( & Ans ) ;
     while( Ans != 0)  {
       if( Ans == 1) {
         system("cls");
         Aff1 ( & R ) ;
         printf ( "\n\n%s", " " ) ;

       } ;
       if( Ans == 2) {
         system("cls");
         Hasard12 ( & R ) ;
         printf ( "\n\n%s", " " ) ;

       } ;
       if( Ans == 3) {
         system("cls");
         Fav12 ( & R ) ;
         printf ( "\n\n%s", " " ) ;

       } ;
       if( Ans == 4) {
         system("cls");
         Fav_pre12 ( & R ) ;
         printf ( "\n\n%s", " " ) ;

       } ;
       if( Ans == 5) {
         system("cls");
         M_fav12 ( & R ) ;
          printf ( "\n\n%s", " " ) ;

       } ;
       Menu2 ( & Ans ) ;

     } ;

    }

  void Menu2 (int *Ans)
    {

      /** Corps du module **/
     printf ( "\n\t%s", "LES OPTIONS DISPONIBLES : " ) ;
     textcolor(6);
     printf ( "\n\n\t%s\n", "AFFICHAGES DES RENCONTRES:" ) ;
     printf ( "\n\t%s", "1- " ) ;
     textcolor(15);
     printf ( "%s", "AFFICHAGE DE TOUTES LES RENCONTRES SELON LA PHASE 1" ) ;
     textcolor(6);
     printf ( "\n\n\t%s", "AFFICHAGES DES RESULTATS:" ) ;
     printf ( "\n\n\t%s", "2- " ) ;
     textcolor(15);
     printf ( "%s", "AU HASARD ET SELON LES RENCONTRES DE LA PHASE 1" ) ;
     textcolor(6);
     printf ( "\n\n\t%s", "SELECTION DE L'EQUIPE GAGNANTE:" ) ;
     printf ( "\n\n\t%s", "3- " ) ;
     textcolor(15);
     printf ( "%s", "EQUIPE FAVORITE SELON LES RESULTATS DE LA PHASE 1" ) ;
     textcolor(6);
     printf ( "\n\n\t%s", "4- " ) ;
     textcolor(15);
     printf ( "%s", "EQUIPE FAVORITE SELON LE CLASSEMENT DE LA FIFA 2022" ) ;
     textcolor(6);
     printf ( "\n\n\t%s", "SELECTION DE L'EQUIPE PERDANTE: " ) ;
     printf ( "\n\n\t%s", "5- " ) ;
     textcolor(15);
     printf ( " %s", "EQUIPE PERDANTE SELON LES RESULTATS DE LA PHASE 1" ) ;
     textcolor(6);
     printf ( "\n\n\t%s", "QUITTER" ) ;
     printf ( "\n\n\t%s", "0- " ) ;
     textcolor(15);
     printf ( " %s", "REVENIR AU MENU PRINCIPAL " ) ;
     printf ( " %s", "\n\n\tL'OPERATION PRECEDENTE VA ETRE REPETEE SI VOUS NE REPONDEZ PAS " ) ;
     printf ( " %s", "\n\n\tENTREZ VOTRE CHOIX: " ) ;
     scanf ( " %d", &*Ans ) ;

    }
  void Menuglobal (int *N)
    {

      /** Corps du module **/
     system("cls");
     printf ( "\n\t%s", " LES OPTIONS DISPONIBLES :\n" ) ;
     textcolor(6);
     printf ( "\n\t%s", " 1- " ) ;
     textcolor(15);
     printf ( "%s", "SIMULATION DE LA PHASE1\n" ) ;
     textcolor(6);
     printf ( "\n\t%s", " 2- " ) ;
     textcolor(15);
     printf ( "%s", "SIMULATION DE LA PHASE2\n" ) ;
      textcolor(6);
     printf ( "\n\t%s", " 0- " ) ;
     textcolor(15);
     printf ( "%s", "QUITTER \n\n" ) ;
     printf ( "\n\t%s", "L'OPERATION PRECEDENTE VA ETRE REPETEE SI VOUS NE REPONDEZ PAS \n" ) ;
     printf ( "\n\t%s", "ENTREZ VOTRE CHOIX: " ) ;
     scanf ( " %d", &*N ) ;


    }


    void bienvenu()
    {
     srand(time(0));
     int *nbPic = 1;
     textcolor(6);
     printf("\n\n\n\n");
     printf("\t\t\t\t |||||||||||     |||||||)       ((|||||||//                                \n");
    printf("\t\t\t\t     |||         |||    ))       ((     //                             \n");
    printf("\t\t\t\t     |||         |||   ))         ((   //                            \n");
    printf("\t\t\t\t     |||         |||))))            ((//                                 \n");
    printf("\t\t\t\t     |||         |||                ///                            \n");
    printf("\t\t\t\t     |||         |||               ///                                  \n");
    printf("\t\t\t\t     |||         |||              ///                                       \n");
    printf("\t\t\t\t     |||         |||             //||||||||||                                      \n\n");

     textcolor(6);
     printf("\n\n\n\tLE  TP2 D'ALSDD\n");
     printf("\n\tANNEE SCOLAIRE:   ");
     textcolor(15);
     printf("2021 / 2022\n");
     textcolor(6);
     printf("\n\t\t\t\t\t\tREALISE PAR:\n");
     textcolor(15);
     printf("\n\t\t\t\t\t\tBELHARDA AYA    G03\n");

     printf("\n\t\t\t\t\t\tALISMAIL DYNA HAYEM   G10\n");

     sleep (5);
     system("cls");
      srand(time(0));
 printf("                                                        \n\n\n");
    textcolor(6);
    printf("\n\t\t\t    SIMULATION DES RENCONTRES DE LA COUPE DU MONDE QATAR 2022  \n\n");

    printf("                                                        \n");
    printf("\t\t\t\t                     (())                                 \n");
    printf("\t\t\t\t                   (((())))                                      \n");
    printf("\t\t\t\t                  ((((()))))                                      \n");
    printf("\t\t\t\t                 (((((())))))                                 \n");
    printf("\t\t\t\t                 (((((())))))                               \n");
    printf("\t\t\t\t                  ((((()))))                                 \n");
    printf("\t\t\t\t                   (((())))                                 \n");
    printf("\t\t\t\t                    (||||)                                \n");
    printf("\t\t\t\t                    (||||)                                 \n");
    printf("\t\t\t\t                     ||||                               \n");
    printf("\t\t\t\t                     ||||                               \n");
    printf("\t\t\t\t                    (||||)                          \n");
    printf("\t\t\t\t                   ((||||))                               \n");
    printf("\t\t\t\t                  (((||||)))    ");
    textcolor(15);
    printf("\n\n\n\t\t\t\t          WORLD FOOTBALL CUP QATAR 2022                       \n");
    Speak("BIENVENU A LA COUPE DU MONDE QATAR 2022");
   sleep (3);
     system("cls");

    }
void merci()
    {
     srand(time(0));
     int *nbPic = 1;
     textcolor(15);
    printf("\n\n");
    printf("\n\t\t\t\t   ||||  ||||   |||||||||  ||||||||)      (|||||    |||                  ");
    printf("\n\t\t\t\t   ||| \\/ |||   |||        |||    ))     (||        |||          ");
    printf("\n\t\t\t\t   |||    |||   |||        |||   ))     (||         |||               ");
    printf("\n\t\t\t\t   |||    |||   |||||||||  |||||||     (||          |||                      ");
    printf("\n\t\t\t\t   |||    |||   |||        |||  \\\\\\     (||         |||                     ");
    printf("\n\t\t\t\t   |||    |||   |||        |||   \\\\\\     (||        |||                  ");
    printf("\n\t\t\t\t   |||    |||   |||||||||  |||    \\\\\\     (|||||    |||                        ");
    textcolor(6);
    printf("                                                        \n");
    printf("                   (())                                 \n");
    printf("                 (((())))                                      \n");
    printf("                ((((()))))                                      \n");
    printf("               (((((())))))                                 \n");
    printf("               (((((())))))                               \n");
    printf("                ((((()))))                                 \n");
    printf("                 (((())))                                 \n");
    printf("                  (||||)                                \n");
    printf("                  (||||)                                 \n");
    printf("                   ||||                               \n");
    printf("                   ||||                               \n");
    printf("                  (||||)                              \n");
    printf("                 ((||||))                               \n");
    printf("                (((||||)))                                 ");
     textcolor(6);


      srand(time(0));

    printf("              QATAR THANK YOU                       \n");
    Speak("MERCI ET A TRES BIENTOT");
    sleep (3);
     system("cls");
    }



  int main(int argc, char *argv[])
    {
     bienvenu();
     Tabl = malloc(16 * 255  * sizeof(char));
     int _Izw2;for (_Izw2=0; _Izw2<16; ++_Izw2)
       Tabl[_Izw2]= malloc(255 * sizeof(char));
       textcolor(15);
     printf ( " %s", "\n-----------------------------------------------BIENVENU CHER UTILISATEUR-----------------------------------------------\n" ) ;
     textcolor(6);
     printf ( "\n\n\t%s", " SIMULATION DES RENCONTRES DE LA COUPE DU MONDE QATAR 2022\n" ) ;
     Rep  =  1 ;
     textcolor(15);
     Menuglobal ( & Rep ) ;
      system("cls");
     while( Rep != 0)  {
       if( Rep == 1) {
            system("cls");
         Phase1() ;


       } ;
       if( Rep == 2) {
            system("cls");
         Phase2() ;


       } ;
       Menuglobal ( & Rep ) ;

     } ;
    system("cls");
    merci();
      system("PAUSE");
      return 0;
    }


