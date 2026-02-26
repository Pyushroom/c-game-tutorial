# cpp-game (C++ + raylib + vcpkg)

Mały projekt C++ korzystający z **raylib**.  
Zależności są zarządzane przez **vcpkg** w trybie **manifest** (`vcpkg.json`).

## Wymagania

- CMake >= 3.20
- Kompilator C++ obsługujący C++20:
  - Windows: MSVC / MinGW / clang
  - Linux/macOS: GCC/Clang
- **vcpkg** (lokalnie na Twojej maszynie)

> Samo `git clone` nie pobiera bibliotek automatycznie.
> Biblioteki (raylib) pobiorą się podczas konfiguracji CMake, jeśli użyjesz toolchaina vcpkg.

---

## 1) Pobranie repo

```bash
git clone <TU_WSTAW_URL_DO_REPO>
cd cpp-game
```
