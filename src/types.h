//
// Created by Eric on 22/10/2022.
//

#ifndef SKIFREE_DECOMP_TYPES_H
#define SKIFREE_DECOMP_TYPES_H

#include <SDL.h>

typedef int BOOL;
typedef void* HDC;
typedef void* HWND;
typedef void* HGDIOBJ;
typedef unsigned long DWORD;
typedef char* LPCSTR;

#define TRUE 1
#define FALSE 0

typedef struct _RECT {
    long left;
    long top;
    long right;
    long bottom;
} RECT, *PRECT;

typedef struct
{
    HDC sheetDC;
    HDC sheetDC_1bpp;
    SDL_Surface* sheet;
    short sheetYOffset;
    short width;
    short height;
    short totalPixels;
} Sprite;

typedef struct PermObject {
    struct Actor* actor;
    Sprite* spritePtr;
    short spriteIdx;
    // 2 bytes padding
    int actorTypeMaybe;
    int actorFrameNo;
    short maybeX;
    short maybeY;
    short unk_0x18;
    short xVelocity;
    short yVelocity;
    short unk_0x1e;
    int unk_0x20;
} PermObject;

typedef struct PermObjectList {
    struct PermObject* startingObject;
    struct PermObject* nextObject;
    struct PermObject* currentObj;
} PermObjectList;

typedef struct Actor {
    struct Actor* next;
    struct Actor* linkedActor;
    struct Actor* actorPtr;
    struct PermObject* permObject;
    uint16_t spriteIdx2;
    // 2 byte padding TODO check alignment of struct
    Sprite* spritePtr;
    int typeMaybe;
    uint32_t frameNo;
    RECT someRect;
    RECT rect;
    short xPosMaybe;
    short yPosMaybe;
    short isInAir;
    short HorizontalVelMaybe;
    short verticalVelocityMaybe;
    short inAirCounter;
    uint32_t flags;
} Actor;

typedef struct
{
    short unk_0;
    short unk_2;
    short unk_4;
    short unk_6;
    short xRelated;
    short unk_a;
    uint32_t frameNo;
} ActorVelStruct;

typedef struct
{
    /*HGLOBAL*/ void* soundResource;
    void* soundData;
} Sound;

typedef struct
{
    int leftFrameNo;
    int rightFrameNo;
} PlayerTurnFrameNoLookupTbl;

#endif // SKIFREE_DECOMP_TYPES_H
