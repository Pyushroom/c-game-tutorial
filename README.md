# 🎮 cpp-game

**C++20 + raylib + vcpkg + CMake Presets**  
Cross-platform (Linux 🐧 + Windows 🪟 MinGW)

---

## 📌 Opis

Mały projekt gry w C++ wykorzystujący **raylib**.  
Zależności są zarządzane przez **vcpkg** w trybie **manifest** (`vcpkg.json`).

Projekt używa **CMake Presets**, dzięki czemu budowanie jest proste i spójne na różnych systemach.

---

## ⚙️ Wymagania

- **CMake ≥ 3.20**
- **Ninja**
- Kompilator z obsługą **C++20**
  - Linux → `gcc` lub `clang`
  - Windows → **MinGW (gcc/g++)**
- **vcpkg** z ustawioną zmienną środowiskową `VCPKG_ROOT`

Linux:

```bash
export VCPKG_ROOT=/sciezka/do/vcpkg
```

Windows (PowerShell):

```powershell
setx VCPKG_ROOT "C:\path\to\vcpkg"
```

---

## 📥 Pobranie repo

```bash
git clone https://github.com/Pyushroom/c-game-tutorial.git
cd c-game-tutorial
```

---

# 🐧 Budowanie na Linux

### 🔧 Debug

```bash
cmake --preset linux-debug
cmake --build --preset linux-debug
```

### 🚀 Release

```bash
cmake --preset linux-release
cmake --build --preset linux-release
```

### ▶ Uruchamianie

```bash
./build/linux-debug/cpp_game
```

lub

```bash
./build/linux-release/cpp_game
```

---

# 🪟 Budowanie na Windows (MinGW)

> Uruchamiaj w środowisku, gdzie `gcc`, `g++` i `ninja` są w PATH  
> (np. MSYS2 MinGW64 shell)

### 🔧 Debug

```powershell
cmake --preset mingw-debug
cmake --build --preset mingw-debug
```

### 🚀 Release

```powershell
cmake --preset mingw-release
cmake --build --preset mingw-release
```

### ▶ Uruchamianie

```powershell
.\build\mingw-debug\cpp_game.exe
```

lub

```powershell
.\build\mingw-release\cpp_game.exe
```

---

## 📂 Struktura buildów

Buildy są generowane automatycznie i rozdzielone per system:

```
build/
  linux-debug/
  linux-release/
  mingw-debug/
  mingw-release/
```

---

## 📦 Zależności (vcpkg)

Projekt używa **vcpkg manifest mode**.

Zależności znajdują się w:

```
vcpkg.json
```

Nie commitujemy:

```
build/
vcpkg_installed/
```

---

## 🧠 Konfiguracja platform

| System  | Triplet vcpkg       |
| ------- | ------------------- |
| Linux   | `x64-linux`         |
| Windows | `x64-mingw-dynamic` |

---

## 🚀 Cechy projektu

- C++20
- CMake Presets
- Ninja
- vcpkg (manifest)
- Cross-platform
- Czysta struktura buildów
- Gotowy pod CI

---

Made with ❤️ using C++ and raylib.
