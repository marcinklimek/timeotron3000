# timeotron3000

timeotron3000 is an Arduino sketch that measures the time of a speed-climbing run and shows it on a MAX72XX LED matrix panel, with buttons read through EasyButton. The owner uses it on the physical board; the repo has no automated check, so a change is done when the owner has run it there.

## Profile

Values the kit rules refer to. Keep each line short and true. Delete a line that does not apply.

| Key | Value |
|---|---|
| owner language | Polish (full diacritics) |
| start folder | the repository root (Claude Code loads `.claude/` and `.mcp.json` only from the start folder) |
| stack | C++ Arduino sketch (`src/timeotron3000/timeotron3000.ino` and `.h`); vendored libraries in `libraries/`: MD_MAX72XX 3.0.1, MD_MAXPanel 1.2.3, EasyButton 1.0.1 |
| checks | none in the repo (no build script, no tests). ASSUMPTION: owner compiles the sketch in the Arduino IDE |
| check pass means | ASSUMPTION: the sketch compiles with no errors and the owner has run it on the board |
| risky paths | `src/timeotron3000/sys_*.h` (included by the sketch); `libraries/` (vendored, do not edit) |
| owner approval | changes to the vendored libraries under `libraries/`; timing or display changes the owner has not run on the board |
| push targets | see `.claude/kit.json` `guard.pushAllow` |
| board | GitHub project created by `kit.py board setup`, config `.claude/board/board.json` |
| glossary | default `docs/CONTEXT.md` (skill `domain-modeling`) |
| decisions | ADR folder, default `docs/decisions/` (skill `domain-modeling`) |
| libraries to re-check | MD_MAX72XX, MD_MAXPanel, EasyButton (vendored; check upstream docs before changing how they are used) |

## Invariants

Testable statements that every change keeps. Review checks each one the change can touch.

- INVARIANT: none yet; the repo has no automated check. Check: owner adds one.

## Overrides

Deviations from kit rules. Everything not listed follows the kit. One entry per deviation:

- Overrides kit `<rule>.md` (<what the kit says>): <what this project does>. Reason: <why>.

## Project rules

Project-specific rules that are short go here. Longer ones go to `.claude/rules/<name>.md`
(project-owned files next to the kit links in `.claude/rules/kit/`).

<!-- kit:begin (managed by kit.py sync; do not edit) -->
## Kit

This project uses claude-workflow-kit as Claude Code plugins (marketplace `claude-workflow-kit`): `kit-core`, `kit-board`.
Kit rules arrive as SessionStart context from the plugins. Setup and update steps: the kit `SETUP.md`.
Kit rules apply; project files narrow them. A deviation from a kit rule is valid only as an entry in `## Overrides` of this file.
<!-- kit:end -->
