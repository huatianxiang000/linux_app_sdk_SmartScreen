#ifndef _FONT_CONF_H_
#define _FONT_CONF_H_

#include "res_conf.h"
#include "font_utils.h"

typedef enum
{
	FONT_TYPE_CN = 0,
	FONT_TYPE_CN_LIGHT,
	FONT_TYPE_LETTER,
	FONT_TYPE_NUMBER,
}FONT_TYPE;

#define FONT_TYPE_CN_PATH FONT_PATH "SOURCEHANSANSCN_REGULAR.OTF" //中文常规字体
#define FONT_TYPE_CN_LIGHT_PATH FONT_PATH "SOURCEHANSANSCN_LIGHT.OTF"//中文细瘦字体
#define FONT_TYPE_LETTER_PATH FONT_PATH "tianxingti.ttf"//中文个性字体
#define FONT_TYPE_NUMBER_PATH FONT_PATH "Library-3-am-3.otf"

#define FONT_INIT() \
    do { \
        add_font(FONT_TYPE_CN,FONT_TYPE_CN_PATH); \
        add_font(FONT_TYPE_CN_LIGHT,FONT_TYPE_CN_LIGHT_PATH); \
        add_font(FONT_TYPE_LETTER,FONT_TYPE_LETTER_PATH); \
        add_font(FONT_TYPE_NUMBER,FONT_TYPE_NUMBER_PATH); \
    } while (0)  

#endif