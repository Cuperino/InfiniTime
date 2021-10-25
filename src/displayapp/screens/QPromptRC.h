#pragma once

#include "displayapp/screens/Screen.h"
#include <lvgl/lvgl.h>

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class QPromptRC : public Screen {
      public:
        QPromptRC(DisplayApp* app);
        ~QPromptRC() override;

        void OnObjectEvent(lv_obj_t* obj, lv_event_t event);
      };
      private:
        lv_obj_t* btnDecreaseVelocity;
        lv_obj_t* btnIncreaseVelocity;
        lv_obj_t* btnPlayPause;

        lv_style_t btn_style;

        bool prompting;
        int velocity;
    }
  }
}
