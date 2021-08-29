#ifndef KEYS_H
#define KEYS_H

namespace ChernoEngine
{
  enum CE_KeyAction
  {
    CE_KEY_PRESSED,
    CE_KEY_RELEASED
  };

  //Taken from SDL_KEYcode.h
  enum CE_KeyCode
  {
    CE_KEYCODE_UNKNOWN = 0,

    CE_KEYCODE_A = 4,
    CE_KEYCODE_B = 5,
    CE_KEYCODE_C = 6,
    CE_KEYCODE_D = 7,
    CE_KEYCODE_E = 8,
    CE_KEYCODE_F = 9,
    CE_KEYCODE_G = 10,
    CE_KEYCODE_H = 11,
    CE_KEYCODE_I = 12,
    CE_KEYCODE_J = 13,
    CE_KEYCODE_K = 14,
    CE_KEYCODE_L = 15,
    CE_KEYCODE_M = 16,
    CE_KEYCODE_N = 17,
    CE_KEYCODE_O = 18,
    CE_KEYCODE_P = 19,
    CE_KEYCODE_Q = 20,
    CE_KEYCODE_R = 21,
    CE_KEYCODE_S = 22,
    CE_KEYCODE_T = 23,
    CE_KEYCODE_U = 24,
    CE_KEYCODE_V = 25,
    CE_KEYCODE_W = 26,
    CE_KEYCODE_X = 27,
    CE_KEYCODE_Y = 28,
    CE_KEYCODE_Z = 29,

    CE_KEYCODE_1 = 30,
    CE_KEYCODE_2 = 31,
    CE_KEYCODE_3 = 32,
    CE_KEYCODE_4 = 33,
    CE_KEYCODE_5 = 34,
    CE_KEYCODE_6 = 35,
    CE_KEYCODE_7 = 36,
    CE_KEYCODE_8 = 37,
    CE_KEYCODE_9 = 38,
    CE_KEYCODE_0 = 39,

    CE_KEYCODE_RETURN = 40,
    CE_KEYCODE_ESCAPE = 41,
    CE_KEYCODE_BACKSPACE = 42,
    CE_KEYCODE_TAB = 43,
    CE_KEYCODE_SPACE = 44,

    CE_KEYCODE_MINUS = 45,
    CE_KEYCODE_EQUALS = 46,
    CE_KEYCODE_LEFTBRACKET = 47,
    CE_KEYCODE_RIGHTBRACKET = 48,
    CE_KEYCODE_BACKSLASH = 49, /**< Located at the lower left of the return
                                  *   key on ISO keyboards and at the right end
                                  *   of the QWERTY row on ANSI keyboards.
                                  *   Produces REVERSE SOLIDUS (backslash) and
                                  *   VERTICAL LINE in a US layout, REVERSE
                                  *   SOLIDUS and VERTICAL LINE in a UK Mac
                                  *   layout, NUMBER SIGN and TILDE in a UK
                                  *   Windows layout, DOLLAR SIGN and POUND SIGN
                                  *   in a Swiss German layout, NUMBER SIGN and
                                  *   APOSTROPHE in a German layout, GRAVE
                                  *   ACCENT and POUND SIGN in a French Mac
                                  *   layout, and ASTERISK and MICRO SIGN in a
                                  *   French Windows layout.
                                  */
    CE_KEYCODE_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                  *   instead of 49 for the same key, but all
                                  *   OSes I've seen treat the two codes
                                  *   identically. So, as an implementor, unless
                                  *   your keyboard generates both of those
                                  *   codes and your OS treats them differently,
                                  *   you should generate CE_KEYCODE_BACKSLASH
                                  *   instead of this code. As a user, you
                                  *   should not rely on this code because SDL
                                  *   will never generate it with most (all?)
                                  *   keyboards.
                                  */
    CE_KEYCODE_SEMICOLON = 51,
    CE_KEYCODE_APOSTROPHE = 52,
    CE_KEYCODE_GRAVE = 53, /**< Located in the top left corner (on both ANSI
                              *   and ISO keyboards). Produces GRAVE ACCENT and
                              *   TILDE in a US Windows layout and in US and UK
                              *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                              *   and NOT SIGN in a UK Windows layout, SECTION
                              *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                              *   layouts on ISO keyboards, SECTION SIGN and
                              *   DEGREE SIGN in a Swiss German layout (Mac:
                              *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                              *   DEGREE SIGN in a German layout (Mac: only on
                              *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                              *   French Windows layout, COMMERCIAL AT and
                              *   NUMBER SIGN in a French Mac layout on ISO
                              *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                              *   SIGN in a Swiss German, German, or French Mac
                              *   layout on ANSI keyboards.
                              */
    CE_KEYCODE_COMMA = 54,
    CE_KEYCODE_PERIOD = 55,
    CE_KEYCODE_SLASH = 56,

    CE_KEYCODE_CAPSLOCK = 57,

    CE_KEYCODE_F1 = 58,
    CE_KEYCODE_F2 = 59,
    CE_KEYCODE_F3 = 60,
    CE_KEYCODE_F4 = 61,
    CE_KEYCODE_F5 = 62,
    CE_KEYCODE_F6 = 63,
    CE_KEYCODE_F7 = 64,
    CE_KEYCODE_F8 = 65,
    CE_KEYCODE_F9 = 66,
    CE_KEYCODE_F10 = 67,
    CE_KEYCODE_F11 = 68,
    CE_KEYCODE_F12 = 69,

    CE_KEYCODE_PRINTSCREEN = 70,
    CE_KEYCODE_SCROLLLOCK = 71,
    CE_KEYCODE_PAUSE = 72,
    CE_KEYCODE_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
                                   does send code 73, not 117) */
    CE_KEYCODE_HOME = 74,
    CE_KEYCODE_PAGEUP = 75,
    CE_KEYCODE_DELETE = 76,
    CE_KEYCODE_END = 77,
    CE_KEYCODE_PAGEDOWN = 78,
    CE_KEYCODE_RIGHT = 79,
    CE_KEYCODE_LEFT = 80,
    CE_KEYCODE_DOWN = 81,
    CE_KEYCODE_UP = 82,

    CE_KEYCODE_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
                                     */
    CE_KEYCODE_KP_DIVIDE = 84,
    CE_KEYCODE_KP_MULTIPLY = 85,
    CE_KEYCODE_KP_MINUS = 86,
    CE_KEYCODE_KP_PLUS = 87,
    CE_KEYCODE_KP_ENTER = 88,
    CE_KEYCODE_KP_1 = 89,
    CE_KEYCODE_KP_2 = 90,
    CE_KEYCODE_KP_3 = 91,
    CE_KEYCODE_KP_4 = 92,
    CE_KEYCODE_KP_5 = 93,
    CE_KEYCODE_KP_6 = 94,
    CE_KEYCODE_KP_7 = 95,
    CE_KEYCODE_KP_8 = 96,
    CE_KEYCODE_KP_9 = 97,
    CE_KEYCODE_KP_0 = 98,
    CE_KEYCODE_KP_PERIOD = 99,

    CE_KEYCODE_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                        *   keyboards have over ANSI ones,
                                        *   located between left shift and Y.
                                        *   Produces GRAVE ACCENT and TILDE in a
                                        *   US or UK Mac layout, REVERSE SOLIDUS
                                        *   (backslash) and VERTICAL LINE in a
                                        *   US or UK Windows layout, and
                                        *   LESS-THAN SIGN and GREATER-THAN SIGN
                                        *   in a Swiss German, German, or French
                                        *   layout. */
    CE_KEYCODE_APPLICATION = 101, /**< windows contextual menu, compose */
    CE_KEYCODE_POWER = 102, /**< The USB document says this is a status flag,
                               *   not a physical key - but some Mac keyboards
                               *   do have a power key. */
    CE_KEYCODE_KP_EQUALS = 103,
    CE_KEYCODE_F13 = 104,
    CE_KEYCODE_F14 = 105,
    CE_KEYCODE_F15 = 106,
    CE_KEYCODE_F16 = 107,
    CE_KEYCODE_F17 = 108,
    CE_KEYCODE_F18 = 109,
    CE_KEYCODE_F19 = 110,
    CE_KEYCODE_F20 = 111,
    CE_KEYCODE_F21 = 112,
    CE_KEYCODE_F22 = 113,
    CE_KEYCODE_F23 = 114,
    CE_KEYCODE_F24 = 115,
    CE_KEYCODE_EXECUTE = 116,
    CE_KEYCODE_HELP = 117,
    CE_KEYCODE_MENU = 118,
    CE_KEYCODE_SELECT = 119,
    CE_KEYCODE_STOP = 120,
    CE_KEYCODE_AGAIN = 121,   /**< redo */
    CE_KEYCODE_UNDO = 122,
    CE_KEYCODE_CUT = 123,
    CE_KEYCODE_COPY = 124,
    CE_KEYCODE_PASTE = 125,
    CE_KEYCODE_FIND = 126,
    CE_KEYCODE_MUTE = 127,
    CE_KEYCODE_VOLUMEUP = 128,
    CE_KEYCODE_VOLUMEDOWN = 129,
    /* not sure whether there's a reason to enable these */
    /*     CE_KEYCODE_LOCKINGCAPSLOCK = 130,  */
    /*     CE_KEYCODE_LOCKINGNUMLOCK = 131, */
    /*     CE_KEYCODE_LOCKINGSCROLLLOCK = 132, */
    CE_KEYCODE_KP_COMMA = 133,
    CE_KEYCODE_KP_EQUALSAS400 = 134,

    CE_KEYCODE_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    CE_KEYCODE_INTERNATIONAL2 = 136,
    CE_KEYCODE_INTERNATIONAL3 = 137, /**< Yen */
    CE_KEYCODE_INTERNATIONAL4 = 138,
    CE_KEYCODE_INTERNATIONAL5 = 139,
    CE_KEYCODE_INTERNATIONAL6 = 140,
    CE_KEYCODE_INTERNATIONAL7 = 141,
    CE_KEYCODE_INTERNATIONAL8 = 142,
    CE_KEYCODE_INTERNATIONAL9 = 143,
    CE_KEYCODE_LANG1 = 144, /**< Hangul/English toggle */
    CE_KEYCODE_LANG2 = 145, /**< Hanja conversion */
    CE_KEYCODE_LANG3 = 146, /**< Katakana */
    CE_KEYCODE_LANG4 = 147, /**< Hiragana */
    CE_KEYCODE_LANG5 = 148, /**< Zenkaku/Hankaku */
    CE_KEYCODE_LANG6 = 149, /**< reserved */
    CE_KEYCODE_LANG7 = 150, /**< reserved */
    CE_KEYCODE_LANG8 = 151, /**< reserved */
    CE_KEYCODE_LANG9 = 152, /**< reserved */

    CE_KEYCODE_ALTERASE = 153, /**< Erase-Eaze */
    CE_KEYCODE_SYSREQ = 154,
    CE_KEYCODE_CANCEL = 155,
    CE_KEYCODE_CLEAR = 156,
    CE_KEYCODE_PRIOR = 157,
    CE_KEYCODE_RETURN2 = 158,
    CE_KEYCODE_SEPARATOR = 159,
    CE_KEYCODE_OUT = 160,
    CE_KEYCODE_OPER = 161,
    CE_KEYCODE_CLEARAGAIN = 162,
    CE_KEYCODE_CRSEL = 163,
    CE_KEYCODE_EXSEL = 164,

    CE_KEYCODE_KP_00 = 176,
    CE_KEYCODE_KP_000 = 177,
    CE_KEYCODE_THOUSANDSSEPARATOR = 178,
    CE_KEYCODE_DECIMALSEPARATOR = 179,
    CE_KEYCODE_CURRENCYUNIT = 180,
    CE_KEYCODE_CURRENCYSUBUNIT = 181,
    CE_KEYCODE_KP_LEFTPAREN = 182,
    CE_KEYCODE_KP_RIGHTPAREN = 183,
    CE_KEYCODE_KP_LEFTBRACE = 184,
    CE_KEYCODE_KP_RIGHTBRACE = 185,
    CE_KEYCODE_KP_TAB = 186,
    CE_KEYCODE_KP_BACKSPACE = 187,
    CE_KEYCODE_KP_A = 188,
    CE_KEYCODE_KP_B = 189,
    CE_KEYCODE_KP_C = 190,
    CE_KEYCODE_KP_D = 191,
    CE_KEYCODE_KP_E = 192,
    CE_KEYCODE_KP_F = 193,
    CE_KEYCODE_KP_XOR = 194,
    CE_KEYCODE_KP_POWER = 195,
    CE_KEYCODE_KP_PERCENT = 196,
    CE_KEYCODE_KP_LESS = 197,
    CE_KEYCODE_KP_GREATER = 198,
    CE_KEYCODE_KP_AMPERSAND = 199,
    CE_KEYCODE_KP_DBLAMPERSAND = 200,
    CE_KEYCODE_KP_VERTICALBAR = 201,
    CE_KEYCODE_KP_DBLVERTICALBAR = 202,
    CE_KEYCODE_KP_COLON = 203,
    CE_KEYCODE_KP_HASH = 204,
    CE_KEYCODE_KP_SPACE = 205,
    CE_KEYCODE_KP_AT = 206,
    CE_KEYCODE_KP_EXCLAM = 207,
    CE_KEYCODE_KP_MEMSTORE = 208,
    CE_KEYCODE_KP_MEMRECALL = 209,
    CE_KEYCODE_KP_MEMCLEAR = 210,
    CE_KEYCODE_KP_MEMADD = 211,
    CE_KEYCODE_KP_MEMSUBTRACT = 212,
    CE_KEYCODE_KP_MEMMULTIPLY = 213,
    CE_KEYCODE_KP_MEMDIVIDE = 214,
    CE_KEYCODE_KP_PLUSMINUS = 215,
    CE_KEYCODE_KP_CLEAR = 216,
    CE_KEYCODE_KP_CLEARENTRY = 217,
    CE_KEYCODE_KP_BINARY = 218,
    CE_KEYCODE_KP_OCTAL = 219,
    CE_KEYCODE_KP_DECIMAL = 220,
    CE_KEYCODE_KP_HEXADECIMAL = 221,

    CE_KEYCODE_LCTRL = 224,
    CE_KEYCODE_LSHIFT = 225,
    CE_KEYCODE_LALT = 226, /**< alt, option */
    CE_KEYCODE_LGUI = 227, /**< windows, command (apple), meta */
    CE_KEYCODE_RCTRL = 228,
    CE_KEYCODE_RSHIFT = 229,
    CE_KEYCODE_RALT = 230, /**< alt gr, option */
    CE_KEYCODE_RGUI = 231, /**< windows, command (apple), meta */

    CE_KEYCODE_MODE = 257,    /**< I'm not sure if this is really not covered
                                 *   by any of the above, but since there's a
                                 *   special KMOD_MODE for it I'm adding it here
                                 */

                                 /* @} *//* Usage page 0x07 */

                                 /**
                                  *  \name Usage page 0x0C
                                  *
                                  *  These values are mapped from usage page 0x0C (USB consumer page).
                                  */
                                  /* @{ */

                                  CE_KEYCODE_AUDIONEXT = 258,
                                  CE_KEYCODE_AUDIOPREV = 259,
                                  CE_KEYCODE_AUDIOSTOP = 260,
                                  CE_KEYCODE_AUDIOPLAY = 261,
                                  CE_KEYCODE_AUDIOMUTE = 262,
                                  CE_KEYCODE_MEDIASELECT = 263,
                                  CE_KEYCODE_WWW = 264,
                                  CE_KEYCODE_MAIL = 265,
                                  CE_KEYCODE_CALCULATOR = 266,
                                  CE_KEYCODE_COMPUTER = 267,
                                  CE_KEYCODE_AC_SEARCH = 268,
                                  CE_KEYCODE_AC_HOME = 269,
                                  CE_KEYCODE_AC_BACK = 270,
                                  CE_KEYCODE_AC_FORWARD = 271,
                                  CE_KEYCODE_AC_STOP = 272,
                                  CE_KEYCODE_AC_REFRESH = 273,
                                  CE_KEYCODE_AC_BOOKMARKS = 274,

                                  /* @} *//* Usage page 0x0C */

                                  /**
                                   *  \name Walther keys
                                   *
                                   *  These are values that Christian Walther added (for mac keyboard?).
                                   */
                                   /* @{ */

                                   CE_KEYCODE_BRIGHTNESSDOWN = 275,
                                   CE_KEYCODE_BRIGHTNESSUP = 276,
                                   CE_KEYCODE_DISPLAYSWITCH = 277, /**< display mirroring/dual display
                                                                          switch, video mode switch */
    CE_KEYCODE_KBDILLUMTOGGLE = 278,
    CE_KEYCODE_KBDILLUMDOWN = 279,
    CE_KEYCODE_KBDILLUMUP = 280,
    CE_KEYCODE_EJECT = 281,
    CE_KEYCODE_SLEEP = 282,

    CE_KEYCODE_APP1 = 283,
    CE_KEYCODE_APP2 = 284,

    /* @} *//* Walther keys */

    /* Add any other keys here. */

    CE_NUM_KEYCODES = 512 /**< not a key, just marks the number of KEYcodes
                                 for array bounds */
  };
}

#endif
