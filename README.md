# Todo List CPP

A simple console-based Todo List manager written in C++, using the STL `std::list` container. Built as a first full C++ project to practice classes, iterators, and basic console I/O.

## Features

- Add a new todo with a text description
- Mark a todo as completed by its ID
- Delete a todo by its ID
- View all todos with their ID, description, and status (Remaining / Completed)
- Feedback message after completing or deleting an ID that foes not exist
- Simple menu-driven console interface
- Cross-platform screen clearing (Windows, macOS, Linux)

## Demo

```
Todo List Manager - v1.3.0
----------------------------------------------

42 | Buy groceries | Remaining
17 | Finish assignment | Completed

----------------------------------------------

~ [a]dd a TODO
~ [d]elete a TODO
~ [c]omplete a TODO
~ [q]uit
Select :
```

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

| Key | Action |
|-----|--------|
| `a` | Add a new todo (prompts for a description) |
| `d` | Delete a todo (prompts for its ID)
| `c` | Mark a todo as completed (prompts for its ID) |
| `q` | Quit the program |

Todo IDs are shown in the list on the left-hand column — use that number when completing or deleting a task.IDs are assigned sequentially starting from 1 and are guaranteed unique for the lifetime of a single run. If you enter an ID that doesn't exist for c or d, the app now tells you and waits for you to press Enter before returning to the menu.

## Known Limitations (For current version - v1.0.0)

- **No persistence** — all todos are lost when the program exits; nothing is saved to disk.
- **No input validation** — non-numeric input for a task ID, or an unrecognized menu option, isn't caught or reported to the user.

## Changelog

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
