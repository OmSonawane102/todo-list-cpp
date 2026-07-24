# todo-list-cpp
# Todo List CPP

A simple console-based Todo List manager written in C++, using the STL `std::list` container. Built as a first full C++ project to practice classes, iterators, and basic console I/O.

## Features

- Add a new todo with a text description
- Mark a todo as completed by its ID
- View all todos with their ID, description, and status (Remaining / Completed)
- Randomly generated task IDs
- Simple menu-driven console interface

## Demo

```
Todo List Manager - v1.0.0
----------------------------------------------

42 | Buy groceries | Remaining
17 | Finish assignment | Completed

----------------------------------------------

~ [a]dd a TODO
~ [c]omplete a TODO
~ [q]uit
Select :
```

## Requirements

- A C++ compiler with C++11 support or later (e.g. MSVC, g++, clang++)
- Windows (uses `system("cls")` to clear the screen — see [Known Limitations](#known-limitations))

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
| `c` | Mark a todo as completed (prompts for its ID) |
| `q` | Quit the program |

Todo IDs are shown in the list on the left-hand column — use that number when completing a task.

## Known Limitations (For current version - v1.0.0)

- **Windows only** — the screen-clearing call (`system("cls")`) doesn't work on macOS/Linux.
- **No persistence** — all todos are lost when the program exits; nothing is saved to disk.
- **No delete option** — todos can be added and completed, but not removed.
- **IDs are random, not guaranteed unique** — collisions are possible with `rand() % 100 + 1`.
