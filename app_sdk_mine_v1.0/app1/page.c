#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lvgl.h"
#include "page.h"
#include "font_conf.h"
#include "image_conf.h"

static void btn_click_event_cb_func(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SHORT_CLICKED:
        printf("btn short click\n");
        lv_obj_t * ta = lv_event_get_user_data(e);
        lv_event_send(ta, LV_EVENT_READY, NULL);
        break;
    case LV_EVENT_LONG_PRESSED:
        printf("btn long click\n");
        break;    
    default:
        break;
    }
}
static void btn_sw_event_cb_func(lv_event_t * e){
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    switch (code)
    {
    case LV_EVENT_VALUE_CHANGED:
        printf("State: %s\n", lv_obj_has_state(obj, LV_STATE_CHECKED) ? "On" : "Off");
        break; 
    default:
        break;
    }
}
static void ta_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if (code == LV_EVENT_READY) {
        const char * text = lv_textarea_get_text(ta);
        if (text != NULL) {
            printf("current text: %s\n", text);
        } else {
            printf("current text: (empty)\n");
        }
    }
}
static void img_click_event_cb_func(lv_event_t * e)
{
    printf("img_click_event_cb_func click\n");
}
void lv_example_hello_world(void) {
    //"桂林电子科技大学"标语
    lv_font_t * font= get_font(FONT_TYPE_LETTER,64);
    lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_label_set_recolor(label,true);
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN);
    lv_label_set_text(label,"#0000ff 桂林电子科技大学");
    lv_obj_center(label);
    //文本框
    lv_obj_t * ta = lv_textarea_create(lv_scr_act());
    lv_textarea_set_one_line(ta, true);
    lv_obj_align_to(ta,label,LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_set_style_bg_color(ta,lv_color_hex(0xFFFFFF),LV_PART_MAIN);
    lv_textarea_set_placeholder_text(ta, "input your name");
    lv_obj_set_style_border_color(ta,lv_color_hex(0x000000),LV_PART_MAIN);
    lv_obj_set_style_text_color(ta,lv_color_hex(0x000000),LV_PART_MAIN);//设置文字颜色
    lv_obj_set_style_border_color(ta,lv_color_hex(0x00FF00),LV_PART_CURSOR | LV_STATE_FOCUSED);//设置光标颜色
    lv_obj_add_event_cb(ta, ta_event_cb, LV_EVENT_READY, NULL);
    lv_obj_clear_state(ta,LV_STATE_FOCUS_KEY);

    //按钮设置
    lv_obj_t * btn = lv_btn_create(lv_scr_act());
    lv_obj_align_to(btn, label, LV_ALIGN_OUT_TOP_MID, 300, 0);
    lv_obj_set_style_radius(btn,50,LV_PART_MAIN);//做圆角
    lv_obj_set_style_bg_opa(btn,LV_OPA_0,LV_PART_MAIN);//背景透明
    lv_obj_set_style_border_width(btn,2,LV_PART_MAIN);//边框宽度
    lv_obj_set_style_border_color(btn,lv_color_hex(0x0000ff),LV_PART_MAIN);//边框颜色
    lv_obj_clear_state(btn,LV_STATE_FOCUS_KEY);//取消选中状态
    lv_obj_add_event_cb(btn, btn_click_event_cb_func, LV_EVENT_ALL, ta);//按钮事件回调函数

    lv_obj_t * label_1= lv_label_create(btn);
    lv_font_t * font1= get_font(FONT_TYPE_LETTER,64);
    lv_label_set_recolor(label_1,true);
    lv_obj_set_style_text_font(label_1, font1, LV_PART_MAIN);
    lv_label_set_text(label_1,"#ff0000 这不是按钮#");
    lv_obj_center(label_1);

    //开关设置
    lv_obj_t * sw = lv_switch_create(lv_scr_act());
    lv_obj_align_to(sw, label, LV_ALIGN_OUT_TOP_MID, -300, 0);
    lv_obj_set_style_bg_color(sw, lv_color_hex(0x00FF00), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_clear_state(sw,LV_STATE_FOCUS_KEY);
    lv_obj_add_event_cb(sw, btn_sw_event_cb_func, LV_EVENT_ALL, NULL);

    //键盘设置
    lv_obj_t *kb = lv_keyboard_create(lv_scr_act());
    lv_obj_set_size(kb, 375, 150);//设置键盘大小
    lv_obj_set_style_bg_color(kb,lv_color_hex(0xFFFFFF),LV_PART_MAIN);//设置键盘主体背景
    lv_obj_clear_state(kb,LV_STATE_FOCUS_KEY);//清除对象焦点状态
    lv_keyboard_set_textarea(kb, ta); //绑定键盘和输入框
    lv_obj_align(kb,LV_ALIGN_LEFT_MID,0,0);

    //图片设置
    lv_obj_t * img = lv_img_create(lv_scr_act());
    lv_img_set_src(img, GET_IMAGE_PATH("GUET1.png"));
    lv_img_set_zoom(img,128);
    lv_obj_align(img,LV_ALIGN_TOP_MID,0,-50);
    lv_obj_add_flag(img,LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(img,img_click_event_cb_func,LV_EVENT_CLICKED,NULL);


}