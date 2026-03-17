#include <zephyr/kernel.h>
#include <zmk/input_processor.h>
#include <zmk/keymap.h>
#include <zmk/behavior.h>
#include <dt-bindings/zmk/keys.h>

static int scroll_to_volume_process(struct input_processor *processor,
                                    struct input_event *event) {

    if (event->code != INPUT_REL_WHEEL) {
        return ZMK_INPUT_PROC_CONTINUE;
    }

    if (event->value > 0) {
        zmk_keymap_invoke_binding(ZMK_KEYMAP_LAYER_DEFAULT, &kp_C_VOL_UP, true, 0);
    } else if (event->value < 0) {
        zmk_keymap_invoke_binding(ZMK_KEYMAP_LAYER_DEFAULT, &kp_C_VOL_DN, true, 0);
    }

    return ZMK_INPUT_PROC_STOP;
}

static const struct input_processor_api scroll_to_volume_api = {
    .process = scroll_to_volume_process,
};

INPUT_PROCESSOR_DEVICE(scroll_to_volume, &scroll_to_volume_api);