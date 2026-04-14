/**
 * cf02_driver.cpp — CWClockfaceDriver adapter for cw-cf-0x02 (Time in Words)
 * v3 bridge: wraps the v2 CF02::Clockface class in the function-pointer API.
 */

#include "Clockface02.h"        // v2 class, namespace CF02
#include <widgets/clockface/CWClockfaceDriver.h>     // v3 driver API

static CF02::Clockface* s_face = nullptr;

static void cf02_setup(Adafruit_GFX* display, CWDateTime* dateTime) {
    if (!s_face) s_face = new CF02::Clockface(display);
    s_face->setup(dateTime);
}

static void cf02_update() {
    if (s_face) s_face->update();
}

static void cf02_teardown() {
    // Instance kept alive for fast re-activation.
}

CWClockfaceDriver cf_words = {
    .name     = "Time in Words",
    .index    = 1,
    .setup    = cf02_setup,
    .update   = cf02_update,
    .teardown = cf02_teardown,
};
