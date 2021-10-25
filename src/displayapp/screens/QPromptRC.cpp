#include "QPromptRC.h"
#include "displayapp/DisplayApp.h"

using namespace Pinetime::Applications::Screens;

static void event_handler(lv_obj_t* obj, lv_event_t event) {
  QPromptRC* screen = static_cast<QPromptRC*>(obj->user_data);
  screen->OnObjectEvent(obj, event);
}

QPromptRC::QPromptRC(DisplayApp* app) : Screen(app) {
  lv_obj_t* title = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_text_static(title, "QPrompt RC");
  lv_label_set_align(title, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(title, lv_scr_act(), LV_ALIGN_TOP_MID, 0, 0);

  lv_style_init(&btn_style);
  lv_style_set_radius(&btn_style, LV_STATE_DEFAULT, 20);
  lv_style_set_bg_color(&btn_style, LV_STATE_DEFAULT, LV_COLOR_AQUA);
  lv_style_set_bg_opa(&btn_style, LV_STATE_DEFAULT, LV_OPA_20);

  btnDecreaseVelocity = lv_btn_create(lv_scr_act(), nullptr);
  btnDecreaseVelocity->user_data = this;
  lv_obj_set_event_cb(btnDecreaseVelocity, event_handler);
  lv_obj_set_size(btnDecreaseVelocity, 115, 76);
  lv_obj_align(btnDecreaseVelocity, nullptr, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0);
  lv_obj_add_style(btnDecreaseVelocity, LV_STATE_DEFAULT, &btn_style);
  label = lv_label_create(btnDecreaseVelocity, nullptr);
  lv_label_set_text(label, Symbols::stepBackward);

  btnIncreaseVelocity = lv_btn_create(lv_scr_act(), nullptr);
  btnIncreaseVelocity->user_data = this;
  lv_obj_set_event_cb(btnIncreaseVelocity, event_handler);
  lv_obj_set_size(btnIncreaseVelocity, 115, 76);
  lv_obj_align(btnIncreaseVelocity, nullptr, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
  lv_obj_add_style(btnIncreaseVelocity, LV_STATE_DEFAULT, &btn_style);
  label = lv_label_create(btnIncreaseVelocity, nullptr);
  lv_label_set_text(label, Symbols::stepForward);

  btnPlayPause = lv_btn_create(lv_scr_act(), nullptr);
  btnPlayPause->user_data = this;
  lv_obj_set_event_cb(btnPlayPause, event_handler);
  lv_obj_set_size(btnPlayPause, 76, 76);
  lv_obj_align(btnPlayPause, nullptr, LV_ALIGN_CENTER, 0, 0);
  lv_obj_add_style(btnPlayPause, LV_STATE_DEFAULT, &btn_style);
  txtPlayPause = lv_label_create(btnPlayPause, nullptr);
  lv_label_set_text(txtPlayPause, Symbols::play);

}

void QPromptRC::OnObjectEvent(lv_obj_t* obj, lv_event_t event) {
  if (event == LV_EVENT_CLICKED) {
    switch (obj) {
        case btnDecreaseVelocity:
        case btnIncreaseVelocity:
        case btnPlayPause:
            break;
    }
  }
}

QPromptRC::~QPromptRC() {
  lv_obj_clean(lv_scr_act());
}
