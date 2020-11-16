#pragma once


struct RedBlackNode {
	void* key;
	void* datum;
	char color;
	RedBlackNode* left;
	RedBlackNode* right;
};

#define RB_RED 0
#define RB_BLACK 1

#define PARENT(node) ((RedBlackNode*)((node)->color & ~RB_BLACK))

#define COLOR(node) ((node)->color &= (~(char)RB_BLACK)

#if defined(__cplusplus) || defined(c_plusplus)
#define BEGIN_DECL extern "C" {
#define END_DECL }
#else
#define BEGIN_DECL
#define END_DECL
#endif

BEGIN_DECL
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
END_DECL