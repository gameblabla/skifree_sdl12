#define IDS_TITLE 1
#define IDB_BITMAP1 1
#define IDC_MYICON 2
#define IDS_PAUSED 2
#define IDB_BITMAP2 2
#define IDS_TIME 3
#define IDB_BITMAP3 3
#define IDS_DIST 4
#define IDB_BITMAP4 4
#define IDS_SPEED 5
#define IDS_STYLE 6
#define IDS_TIME_BLANK 7
#define IDS_DIST_BLANK 8
#define IDS_SPEED_BLANK 9
#define IDS_STYLE_BLANK 10
#define IDS_TIME_FORMAT 11
#define IDS_DIST_FORMAT 12
#define IDS_SPEED_FORMAT 13
#define IDS_STYLE_FORMAT 14
#define IDS_HIGH_SCORES 15
#define IDS_THATS_YOU 16
#define IDS_TRY_AGAIN 17
#define IDD_SKI32_DECOMP_DIALOG 102
#define IDD_ABOUTBOX 103
#define IDS_APP_TITLE 103
#define IDM_ABOUT 104
#define IDM_EXIT 105
#define IDS_HELLO 106
#define IDI_SKI32_DECOMP 107
#define IDI_SMALL 108
#define IDC_SKI32_DECOMP 109
#define IDR_MAINFRAME 128
#define iconSki 134
#define others_res 135
#define IDC_STATIC -1

// https://twitter.com/Foone/status/877023720111353857
#define SND01 Ouch
#define SND02 Whee
#define SND03 Woof
#define SND04 Oof
#define SND05 Dude
#define SND06 Myhair
#define SND07 Gobble
#define SND08 Piddle
#define SND09 Argh
#define SND10 Pop
#define SND11 Ding

// Originally defined in skifree_decomp.rc
char* STRINGTABLE[] = {
    "SkiFree",
    "Ski Paused ... Press F3 to continue",
    "Time:",
    "Dist:",
    "Speed:",
    "Style:",
    "00:00:00.00",
    " 0000m",
    " 0000m/s",
    "0000000",
    "%2u:%2.2u:%2.2u.%2.2u",
    "%5.2dm",
    "%5.2dm/s",
    "%7d", /* originally "%7ld", */
    "High Scores",
    " <-- that's you",
    " <-- try again!"
};
