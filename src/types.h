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
typedef uint32_t DWORD;
typedef char* LPCSTR;

#define TRUE 1
#define FALSE 0

typedef struct __attribute__ ((packed, aligned(4))) _RECT  {
    int32_t left;
    int32_t top;
    int32_t right;
    int32_t bottom;
} RECT, *PRECT;

typedef struct __attribute__ ((packed, aligned(4)))
{
    HDC sheetDC;
    HDC sheetDC_1bpp;
    SDL_Surface* sheet;
    int32_t sheetYOffset;
    int32_t width;
    int32_t height;
    int32_t totalPixels;
} Sprite;

typedef struct __attribute__ ((packed, aligned(4))) PermObject {
    struct Actor* actor;
    Sprite* spritePtr;
    int32_t spriteIdx;
    // 2 bytes padding
    int actorTypeMaybe;
    int actorFrameNo;
    int32_t maybeX;
    int32_t maybeY;
    int32_t unk_0x18;
    int32_t xVelocity;
    int32_t yVelocity;
    int32_t unk_0x1e;
    int unk_0x20;
} PermObject;

typedef struct __attribute__ ((packed, aligned(4))) PermObjectList {
    struct PermObject* startingObject;
    struct PermObject* nextObject;
    struct PermObject* currentObj;
} PermObjectList;

typedef struct __attribute__ ((packed, aligned(4))) Actor {
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
    int32_t xPosMaybe;
    int32_t yPosMaybe;
    int32_t isInAir;
    int32_t HorizontalVelMaybe;
    int32_t verticalVelocityMaybe;
    int32_t inAirCounter;
    uint32_t flags;
} Actor;

typedef struct __attribute__ ((packed, aligned(4)))
{
    int32_t unk_0;
    int32_t unk_2;
    int32_t unk_4;
    int32_t unk_6;
    int32_t xRelated;
    int32_t unk_a;
    uint32_t frameNo;
} ActorVelStruct;

typedef struct __attribute__ ((packed, aligned(4)))
{
    /*HGLOBAL*/ void* soundResource;
    void* soundData;
} Sound;

typedef struct __attribute__ ((packed, aligned(4)))
{
    int leftFrameNo;
    int rightFrameNo;
} PlayerTurnFrameNoLookupTbl;

#endif // SKIFREE_DECOMP_TYPES_H
