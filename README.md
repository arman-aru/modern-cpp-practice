# modern-cpp-practice

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)

A structured, hands-on path through modern C++, from language fundamentals to object-oriented design.
Every exercise is a small, self-contained program that I type by hand, compile, run and then explain in my own words.

The repository grows one topic at a time, and the commit history shows that progression.

## Repository layout

| Folder | Focus | Status |
| --- | --- | --- |
| [`01-fundamentals/`](01-fundamentals) | Variables, types, control flow, functions, pointers & references, classes, memory | ✅ 11 / 11 |
| [`05-oop-university/`](05-oop-university) | OOP course track: inheritance, polymorphism, abstraction, SOLID, design patterns | 🚧 In progress |
| [`06-project/`](06-project) | OOP final project: Vehicle & Sportsbike Dealership System (suppliers, inventory, reservations, factory, templates, file storage) | ✅ Done |

Planned next: `02-stl` (containers, iterators, algorithms), `03-algorithms` (sorting, binary search, two pointers, sliding window, recursion), `04-data-structures` (linked list, stack, queue, hash map, trees, heap). Each folder is added once it has real content.

### OOP track

This track ends with a **Vehicle & Sportsbike Dealership System**: vehicle inventory, user accounts and reservations. It is designed to demonstrate inheritance, polymorphism, encapsulation, abstraction and the SOLID principles.

| # | Topic | Status |
| --- | --- | --- |
| 00a / 01 | Classes, objects, the four pillars of OOP | ✅ |
| 02 | Inheritance, `protected`, constructor chaining | ✅ |
| 03 | Polymorphism, `virtual` / `override`, vtable | 🚧 |
| 04 | Abstraction, pure virtual functions, abstract classes | 🚧 |
| 05–12 | Constructors & destructors, object relationships, exceptions, templates, SOLID, design patterns, serialization, callbacks (`std::function`) | ⏳ |

## Build and run

Each file is a standalone program with its own `main()`.

```bash
# compile and run a single exercise
clang++ -std=c++17 -Wall -Wextra -o /tmp/ex 01-fundamentals/08-functions.cpp && /tmp/ex
```

`g++ -std=c++17` works the same way.

## Conventions

- **Standard:** C++17, with no external dependencies. Every exercise compiles cleanly with `-Wall`.
- **One concept per file.** Each file isolates a single idea so it is easy to review and revisit.
- **Comments are in Banglish** (Bengali written in Latin script), my native language. They are my own explanations of *why* the code behaves the way it does. Identifiers and code stay in English.
- [`NOTES.md`](NOTES.md) and [`05-oop-university/NOTES-OOP.md`](05-oop-university/NOTES-OOP.md) hold concise Q&A notes for each concept. [`PROGRESS.md`](PROGRESS.md) tracks the roadmap.

## Author

**Abu Salek Arman**, [@arman-aru](https://github.com/arman-aru)
