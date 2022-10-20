#ifndef USERSPACE
#define USERSPACE

typedef union {
    uint32_t raw;
    struct {
        bool is_windows : 1;
    };
} user_config_t;

enum combos { OEU_ARROWS, COMDOT_DQT, COMDOT_GRV, ACOM_BSPC, RL_SLSH, RS_MINS,
NZ_EQL, RP_CEQL };

enum custom_keycodes {
    DVORAK = SAFE_RANGE,
    QWERTY,
    LOWER,
    RAISE,
    ADJUST,
    ARROWS,
    COL_EQL,
    AUTOFIL,
    SRCHPWD,
    SWPL,
    SWPR,
    ALT_L,
    ALT_R,
    DSP_OFF,
    CHNGOS,
    MT_AT,
    MT_POUND,
    MT_DLR,
    MT_AMP,
    MT_STAR,
    MT_LPAREN,
    CMBSRT,
    PLOVER,
    EXT_PLV,
    GAME,
    EXT_GME,
};

enum layers {
    _DVORAK = 0,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARROWS,
    _PLOVER,
    _GAME,
};

// app specific macros
//#define AUTOFIL  LCMD(KC_BSLS) // autofill forms in firefox(1pwd)
#define AFWIN LCTL(KC_BSLS)  // autofill forms in firefox(1pwd windows)
#define SRCHPWD LCMD(LALT(KC_BSLS))  // open 1pwd extension in firefox
#define SPWIN LCTL(LALT(KC_BSLS))  // open 1pwd extension in firefox on windows
#define CHKESC HYPR(KC_C)  // chunkwm leader key
#define TMUXPRF LCTL(KC_A)  // tmux leader key
#define VIMWIND LCTL(KC_W)  // vim windows leader key
#define CTL_U LCTL(KC_U)  // vim page up
#define CTL_D LCTL(KC_D)  // vim page down
#define SCRNLYR LM(_ARROWS, MOD_LCTL | MOD_LSFT)  // BetterTouchTools move screen arrow layer modifier
#define LSCRN LCTL(LSFT(KC_LEFT)) // BetterTouchTools move cursor left monitor
#define USCRN LCTL(LSFT(KC_UP)) // BetterTouchTools move cursor up monitor
#define DSCRN LCTL(LSFT(KC_DOWN)) // BetterTouchTools move cursor down monitor
#define RSCRN LCTL(LSFT(KC_RIGHT)) // BetterTouchTools move cursor right monitor

#define SPCN HYPR(KC_N)
#define SPCP HYPR(KC_P)

// hybrid keys & shorthand
#define SFT_ENT SFT_T(KC_ENT)  // Enter when tapped, shift when held
#define CTL_ESC CTL_T(KC_ESC)  // Esc when tapped, ctrl when held
#define CTL_SFT LCTL(KC_LSFT)  // Ctrl + Shift
#define GUI_ESC GUI_T(KC_ESC)  // Esc when tapped, gui when held
#define TAP_SFT OSM(MOD_LSFT)  // tap shift
#define TAP_CTL OSM(MOD_LCTL)  // tap ctrl
#define TAP_GUI OSM(MOD_LGUI)  // tap gui
#define TAP_ALT OSM(MOD_LALT)  // tap alt
#define TAP_RSE OSL(_RAISE)    // tap to raise
#define TABU_N LCTL(S(KC_TAB))
#define TABD_N LCTL(KC_TAB)
#define OSLOW OSL(_LOWER)
#define MO_LOW MO(_LOWER)
#define TABU LCTL(S(KC_TAB))
#define TABD LCTL(KC_TAB)
#define RSE_TAB  LT(_RAISE, KC_TAB)

// home row mods
#define ALT_HL ALT_T(KC_O)
#define GUI_HL GUI_T(KC_E)
#define CTL_HL CTL_T(KC_U)
#define ALT_HR RALT_T(KC_N)
#define GUI_HR RGUI_T(KC_T)
#define CTL_HR RCTL_T(KC_H)
#define ALT_HL2 ALT_T(MT_AT)
#define GUI_HL2 GUI_T(MT_POUND)
#define CTL_HL2 CTL_T(MT_DLR)
#define ALT_HR2 RALT_T(MT_LPAREN)
#define GUI_HR2 RGUI_T(MT_STAR)
#define CTL_HR2 RCTL_T(MT_AMP)

#endif

bool num_mod(keyrecord_t *record, uint16_t key);
bool mod_tap_override(uint16_t mod, uint16_t key1, uint16_t key2);
