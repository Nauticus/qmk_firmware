# AGENTS.md — Nauticus/qmk_firmware fork notes

Personal fork for building the **ZSA Moonlander** with the custom
`keyboards/zsa/moonlander/keymaps/Nauticus/` keymap.

## Build

- Use the CLI, not raw make with variables:

  ```sh
  qmk compile --keyboard zsa/moonlander --keymap Nauticus
  ```

  WARNING: `make keyboard=... keymap=...` with the current (0.34+) Makefile
  falls into a rule-parsing path that calls `qmk list-keymaps` for **every**
  keyboard in the repo and is extremely slow. Do not use it.

- Output: `.build/zsa_moonlander_Nauticus.hex` (and `.bin`, copied to repo root).
- Flash: `qmk flash --keyboard zsa/moonlander --keymap Nauticus`, or drag the
  hex onto the `ZSA-MOON` MSC drive (key under the moon sticker).

## Updating from upstream

- Remotes: `origin` = this fork, `upstream` = `qmk/qmk_firmware`.
- After `git fetch upstream && git merge upstream/master`:
  - Watch out for the **`lib/chibios` submodule conflict**. Always resolve it
    to upstream's commit (`git checkout upstream/master -- lib/chibios &&
    git add lib/chibios`), then `git submodule update --init --recursive`.
    Recording the fork-side (older) chibios breaks the build with
    `hal.h: error: "obsolete or unknown configuration file"` (config version
    mismatch, e.g. QMK halconf 9.1 vs old chibios 8.4 check).
  - Clean the target build dir if a build failed against the old submodule:
    `rm -rf .build/obj_zsa_moonlander_Nauticus .build/zsa_moonlander_Nauticus.hex`.

## 2026q3 (Aug 2026) upstream changes — audit results

Full changelog: `docs/ChangeLog/20260830.md`.

- **No changes** to `keyboards/zsa/` (Moonlander board code or default keymap).
- Steno rework (`STN_*` → `QK_STENO_*`/`ST_*`): keymap unaffected (no steno keys).
- `EXTRAKEY_ENABLE` System Control HID usage range restricted: unaffected
  (EXTRAKEY not enabled); only relevant if media/system-control keycodes are
  added later (old range can be restored via `SYSTEM_CONTROL_USAGE_MINIMUM`/
  `SYSTEM_CONTROL_USAGE_MAXIMUM` in config.h).
- VIA moving to a community module: deprecation notice only.
- New CLI flags: `-kb`/`-km` removed; use `--keyboard`/`--keymap`.
- Keymap was verified clean against all deprecated/breaking API usages and
  compiles without warnings-as-errors after the update.

## Keymap state

- `Nauticus` keymap: uses KEY_OVERRIDE, CAPS_WORD, oneshot helpers (`oneshot.c`/`oneshot.h`),
  `NO_USB_STARTUP_CHECK`.
- 2026-09-26: added `KC_INS` and `KC_PSCR` to two previously empty keys on the
  right bottom row (next to PgDn/End), home layer.
