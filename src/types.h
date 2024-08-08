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

typedef struct __attribute__ ((packed, aligned(4))) _RECT {
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
    int16_t sheetYOffset;
    int16_t width;
    int16_t height;
    int16_t totalPixels;
} Sprite;

typedef struct __attribute__ ((packed, aligned(4))) PermObject {
    struct Actor* actor;
    Sprite* spritePtr;
    int16_t spriteIdx;
    int16_t dummy; // Added dummy for proper aligment , Gameblabla
    // 2 bytes padding
    int actorTypeMaybe;
    int actorFrameNo;
    int16_t maybeX;
    int16_t maybeY;
    int16_t unk_0x18;
    int16_t xVelocity;
    int16_t yVelocity;
    int16_t unk_0x1e;
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
    int16_t dummy; // Added dummy for proper aligment , Gameblabla
    
    Sprite* spritePtr;
    int typeMaybe;
    uint32_t frameNo;
    RECT someRect;
    RECT rect;
    int16_t xPosMaybe;
    int16_t yPosMaybe;
    int16_t isInAir;
    int16_t HorizontalVelMaybe;
    int16_t verticalVelocityMaybe;
    int16_t inAirCounter;
    uint32_t flags;
} Actor;

typedef struct __attribute__ ((packed, aligned(4)))
{
    int16_t unk_0;
    int16_t unk_2;
    int16_t unk_4;
    int16_t unk_6;
    int16_t xRelated;
    int16_t unk_a;
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