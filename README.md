# cpp-game (C++ + raylib + vcpkg)

Mały projekt C++ korzystający z **raylib**.  
Zależności są zarządzane przez **vcpkg** w trybie **manifest** (`vcpkg.json`).

Projekt używa **CMake Presets**, więc budowanie jest uproszczone.

---

## Wymagania

- CMake >= 3.20
- Kompilator obsługujący C++20
- vcpkg (z ustawioną zmienną środowiskową `VCPKG_ROOT`)

---

## 1) Pobranie repo

```bash
git clone https://github.com/Pyushroom/c-game-tutorial.git
cd cpp-game
```

2. Budowanie (CMake Presets)
   Debug
   cmake --preset debug
   cmake --build --preset debug
   Release
   cmake --preset release
   cmake --build --preset release

Foldery build tworzą się automatycznie:

build-debug

build-release

3. Uruchamianie
   Debug
   .\build-debug\cpp_game.exe
   Release
   .\build-release\cpp_game.exe
