# ft_printf

A custom implementation of the standard C `printf` function, handling conversions for `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

## Project Structure

```
.
├── include/
│   └── ft_printf.h          # Public header file
├── src/
│   ├── ft_printf.c          # Core printf implementation
│   ├── utils.c              # Output utilities (char, str, nbr)
│   └── utilsbis.c           # Hex and pointer address formatting
├── Makefile                 # Build configuration
└── .github/
    └── workflows/           # CI/CD automation (build & release)
```

## Compilation

The library can be compiled from source using `make`:

- `make` or `make all`: Compiles the library and generates `libftprintf.a`.
- `make bonus`: Compiles the library with bonus support into `libftprintf.a`.
- `make clean`: Removes object files (`.obj/`) and dependency files (`.dep/`).
- `make fclean`: Removes object files, dependency files, and `libftprintf.a`.
- `make re`: Rebuilds the library from scratch (`fclean` + `all`).

## Continuous Integration & Distribution Bundles

A GitHub Actions workflow automatically builds and packages the library on every pull request targeting `main` and on push to `main`. It generates pre-compiled distribution bundles for both Linux (`x86_64`) and macOS (`ARM64`).

Each release contains:
- `libftprintf.tar.gz`: Default distribution archive containing:
  ```
  libftprintf/
  ├── include/
  │   └── ft_printf.h
  └── lib/
      └── libftprintf.a
  ```
- `libftprintf-Linux-X64.tar.gz`: Linux x86_64 precompiled bundle.
- `libftprintf-macOS-ARM64.tar.gz`: macOS Apple Silicon precompiled bundle.
- `ft_printf.h`: Direct header file.
- `libftprintf.a`: Direct Linux static library.

## Using Precompiled ft_printf in Downstream Projects

To use the precompiled library in other repositories without having to compile ft_printf from source, add a download rule to your project's `Makefile`:

```makefile
PRINTF_DIR = ./libs/ft_printf
PRINTF_URL = https://github.com/tristan-gscn/simply-invent-ft_printf/releases/latest/download/libftprintf.tar.gz

$(PRINTF_DIR):
	@mkdir -p $(PRINTF_DIR)
	curl -sL $(PRINTF_URL) | tar -xz -C $(PRINTF_DIR)

# Compilation flags
CFLAGS  += -I$(PRINTF_DIR)/include
LDFLAGS += -L$(PRINTF_DIR)/lib -lftprintf
```
