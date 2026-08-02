# Todo List CPP

A simple console-based Todo List manager written in C++, using the STL `std::list` container. Built as a first full C++ project to practice classes, iterators, and basic console I/O.

## Features

- Add a new todo with a text description
- Mark a todo as completed by its ID
- Delete a todo by its ID
- View all todos with their ID, description, and status (Remaining / Completed)
- Feedback message after completing or deleting an ID that foes not exist
- Color-coded menu options and bold header for easier readability
- Aligned, table-like columns for ID / description / status using setw()
- Simple menu-driven console interface
- Cross-platform screen clearing (Windows, macOS, Linux)

## Demo

```
Todo List Manager - v1.4.0
------------------------------------------------------------

   1 | Buy groceries                           | Remaining
   2 | Finish assignment                       | Completed

------------------------------------------------------------

~ [a]dd a TODO          (blue)
~ [d]elete a TODO       (red)
~ [c]omplete a TODO     (green)
~ [q]uit                (yellow)
Select :
```

Note: colors won't render in plain text — running the program in an actual terminal will show the menu options in blue, red, green, and yellow respectively, with the header in bold. The ID column is right-aligned (4 characters wide) and the description column is left-aligned (40 characters wide), so rows stay lined up regardless of value length.

## Requirements

- A C++ compiler with C++11 support or later (e.g. MSVC, g++, clang++)

## Getting Started

### Build with g++

```bash
g++ -std=c++11 -o todo-list-cpp todo-list-cpp.cpp
./todo-list-cpp
```

### Build with Visual Studio

1. Open `todo-list-cpp.cpp` in Visual Studio.
2. Press **Ctrl + F5** (Run Without Debugging) or **F5** (Debug).

## Usage

On launch, you'll see a menu with three options:

| Key | Action | Color |
|-----|--------|-------|
| `a` | Add a new todo (prompts for a description) | Blue |
| `d` | Delete a todo (prompts for its ID) | Red |
| `c` | Mark a todo as completed (prompts for its ID) | Green |
| `q` | Quit the program | Yellow |

Todo IDs are shown in the list on the left-hand column — use that number when completing or deleting a task.IDs are assigned sequentially starting from 1 and are guaranteed unique for the lifetime of a single run. If you enter an ID that doesn't exist for c or d, the app now tells you and waits for you to press Enter before returning to the menu.

## Known Limitations (For current version - v1.0.0)
- **Descriptions longer than 40 characters break alignment.** setw(40) pads short text but does not truncate long text — a description over 40 characters will push the | separator out of line with the rows above and below it.
- **ANSI colors may not render on older Windows terminals.** Legacy cmd.exe requires ENABLE_VIRTUAL_TERMINAL_PROCESSING to be explicitly enabled for ANSI escape codes to display correctly; modern Windows Terminal, PowerShell, macOS Terminal, and most Linux terminals support them by default. On unsupported terminals, the raw escape codes may appear as garbled text instead of color.
- **No persistence** — all todos are lost when the program exits; nothing is saved to disk.
- **No input validation** — non-numeric input for a task ID, or an unrecognized menu option, isn't caught or reported to the user.

## Changelog

**v1.5.0**
- Added <iomanip> and used std::setw() / std::left / std::right to align the ID, description, and status columns into a consistent table layout, instead of relying on raw " | " separators that drifted out of line as values grew.

**v1.4.0**
- Added ANSI color codes for a bold header and color-coded menu options (blue a, red d, green c, yellow q) to improve readability.
- Added an inline comment on the erase() call clarifying that the following break must not be removed without also reassigning the iterator.

**v1.3.0**
- Added a [d]elete option to remove a todo by ID, using std::list::erase.
- Added "not found" feedback messages for both complete and delete when the entered ID doesn't match any task, instead of silently doing nothing.
- Marked the class getters (getID, getDescription, isCompleted) as const, since they don't modify the object.

**v1.2.0**
- Replaced random task IDs (rand() % 100 + 1) with a sequential counter (static int next_id), guaranteeing every ID is unique instead of relying on chance. IDs now start at 1 and increment predictably.

**v1.1.0**
- Replaced the Windows-only system("cls") call with a clearConsole() helper that uses system("clear") on macOS/Linux via #ifdef _WIN32, making the app cross-platform.

**v1.0.0**
- Initial release: add, complete, and list todos in a console menu loop.
