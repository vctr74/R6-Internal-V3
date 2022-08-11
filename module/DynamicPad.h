// DynamicPad.h
#pragma once

#define STR_MERGE_IMPL(a, b) a##b
#define STR_MERGE(a, b) STR_MERGE_IMPL(a, b)
#define MAKE_PAD(size) STR_MERGE(_pad, __COUNTER__)[size]
#define MEMBER(type, name, offset) struct {unsigned char MAKE_PAD(offset); type name;}
 