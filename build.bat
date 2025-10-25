@echo off
setlocal enabledelayedexpansion

REM Windows Build Script for LeetCode C++ Project
REM This script provides a Windows equivalent to the Unix build.sh script

REM Default values
set "BUILD_TYPE=Release"
set "BUILD_DIR="
set "INSTALL_PREFIX="
set "CLEAN_BUILD=false"
set "RUN_TESTS=false"
set "VERBOSE=false"
set "BUILD_TESTS=true"
set "TESTS_ONLY=false"
set "BUILD_DOCS=false"
set "OPEN_DOCS=false"
set "JOBS=4"

REM Get number of processors if available
if defined NUMBER_OF_PROCESSORS (
    set "JOBS=%NUMBER_OF_PROCESSORS%"
)

REM Script directory
set "SCRIPT_DIR=%~dp0"
set "SOURCE_DIR=%SCRIPT_DIR%"

REM Colors for output (Windows doesn't support ANSI colors in standard cmd by default)
REM But we'll define them for consistency and future PowerShell support

:parse_args
if "%~1"=="" goto end_parse_args
if "%~1"=="-h" goto show_help
if "%~1"=="--help" goto show_help
if "%~1"=="-c" goto clean_build
if "%~1"=="--clean" goto clean_build
if "%~1"=="-t" (
    set "BUILD_TYPE=%~2"
    shift
    shift
    goto parse_args
)
if "%~1"=="--type" (
    set "BUILD_TYPE=%~2"
    shift
    shift
    goto parse_args
)
if "%~1"=="-d" (
    set "BUILD_DIR=%~2"
    shift
    shift
    goto parse_args
)
if "%~1"=="--build-dir" (
    set "BUILD_DIR=%~2"
    shift
    shift
    goto parse_args
)
if "%~1"=="-r" (
    set "RUN_TESTS=true"
    shift
    goto parse_args
)
if "%~1"=="--run-tests" (
    set "RUN_TESTS=true"
    shift
    goto parse_args
)
if "%~1"=="-i" (
    set "INSTALL_PREFIX=%~2"
    shift
    shift
    goto parse_args
)
if "%~1"=="--install" (
    set "INSTALL_PREFIX=%~2"
    shift
    shift
    goto parse_args
)
if "%~1"=="-v" (
    set "VERBOSE=true"
    shift
    goto parse_args
)
if "%~1"=="--verbose" (
    set "VERBOSE=true"
    shift
    goto parse_args
)
if "%~1"=="--no-tests" (
    set "BUILD_TESTS=false"
    shift
    goto parse_args
)
if "%~1"=="--tests-only" (
    set "TESTS_ONLY=true"
    set "BUILD_TESTS=true"
    set "RUN_TESTS=true"
    shift
    goto parse_args
)
if "%~1"=="--docs" (
    set "BUILD_DOCS=true"
    shift
    goto parse_args
)
if "%~1"=="--open-docs" (
    set "BUILD_DOCS=true"
    set "OPEN_DOCS=true"
    shift
    goto parse_args
)
if "%~1"=="-j" (
    set "JOBS=%~2"
    shift
    shift
    goto parse_args
)
if "%~1"=="--jobs" (
    set "JOBS=%~2"
    shift
    shift
    goto parse_args
)
echo Unknown option: %~1
goto show_help

:clean_build
set "CLEAN_BUILD=true"
shift
goto parse_args

:end_parse_args

REM Validate build type
if "%BUILD_TYPE%"=="Debug" goto valid_build_type
if "%BUILD_TYPE%"=="Release" goto valid_build_type
if "%BUILD_TYPE%"=="RelWithDebInfo" goto valid_build_type
if "%BUILD_TYPE%"=="MinSizeRel" goto valid_build_type
echo [ERROR] Invalid build type: %BUILD_TYPE%
echo [ERROR] Valid types: Debug, Release, RelWithDebInfo, MinSizeRel
exit /b 1

:valid_build_type

REM Set default build and install directories if not specified
if "%BUILD_DIR%"=="" (
    set "BUILD_DIR=%SOURCE_DIR%out\build\%BUILD_TYPE%"
)

if "%INSTALL_PREFIX%"=="" (
    set "INSTALL_PREFIX=%SOURCE_DIR%out\install\%BUILD_TYPE%"
)

echo ========================================
echo   LeetCode C++ Build Script (Windows)
echo ========================================
echo Build Type:       %BUILD_TYPE%
echo Build Directory:  %BUILD_DIR%
echo Install Prefix:   %INSTALL_PREFIX%
echo Parallel Jobs:    %JOBS%
echo Clean Build:      %CLEAN_BUILD%
echo Run Tests:        %RUN_TESTS%
echo Build Tests:      %BUILD_TESTS%
echo Tests Only:       %TESTS_ONLY%
echo Build Docs:       %BUILD_DOCS%
echo Open Docs:        %OPEN_DOCS%
echo ========================================
echo.

REM Check dependencies
echo [INFO] Checking dependencies...

REM Check CMake
cmake --version >nul 2>&1
if errorlevel 1 (
    echo [ERROR] CMake not found. Please install CMake and add it to PATH.
    echo         Download from: https://cmake.org/download/
    exit /b 1
)
for /f "delims=" %%i in ('cmake --version') do (
    echo [SUCCESS] CMake found: %%i
    goto cmake_checked
)
:cmake_checked

REM Check C++ compiler (try MSVC first, then others)
where cl >nul 2>&1
if not errorlevel 1 (
    echo [SUCCESS] MSVC compiler found
    goto compiler_found
)

where g++ >nul 2>&1
if not errorlevel 1 (
    echo [SUCCESS] GCC compiler found
    goto compiler_found
)

where clang++ >nul 2>&1
if not errorlevel 1 (
    echo [SUCCESS] Clang compiler found
    goto compiler_found
)

echo [ERROR] No C++ compiler found. Please install:
echo         - Visual Studio 2022 with C++ tools, or
echo         - MinGW-w64, or
echo         - Clang
exit /b 1

:compiler_found

REM Check for Doxygen (optional)
doxygen --version >nul 2>&1
if not errorlevel 1 (
    for /f "delims=" %%i in ('doxygen --version') do (
        echo [SUCCESS] Doxygen found: %%i
    )
) else (
    echo [WARNING] Doxygen not found. Documentation generation will be skipped.
    echo           Install from: https://www.doxygen.nl/download.html
    if "%BUILD_DOCS%"=="true" (
        echo [ERROR] Cannot build documentation without Doxygen. Please install it first.
        exit /b 1
    )
)

echo.

REM Clean build directory if requested
if "%CLEAN_BUILD%"=="true" (
    echo [INFO] Cleaning build directory: %BUILD_DIR%
    if exist "%BUILD_DIR%" (
        rmdir /s /q "%BUILD_DIR%"
        echo [SUCCESS] Build directory cleaned
    ) else (
        echo [INFO] Build directory doesn't exist, skipping clean
    )
)

REM Configure CMake
echo [INFO] Configuring CMake...

if "%VERBOSE%"=="true" (
    cmake -S "%SOURCE_DIR%" -B "%BUILD_DIR%" -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DCMAKE_INSTALL_PREFIX="%INSTALL_PREFIX%" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DBUILD_SHARED_LIBS=ON
) else (
    cmake -S "%SOURCE_DIR%" -B "%BUILD_DIR%" -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DCMAKE_INSTALL_PREFIX="%INSTALL_PREFIX%" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DBUILD_SHARED_LIBS=ON >nul
)

if errorlevel 1 (
    echo [ERROR] CMake configuration failed
    exit /b 1
)
echo [SUCCESS] CMake configuration complete

REM Build project
if "%TESTS_ONLY%"=="false" (
    echo [INFO] Building project...
    if "%VERBOSE%"=="true" (
        cmake --build "%BUILD_DIR%" --config %BUILD_TYPE% --parallel %JOBS% --verbose
    ) else (
        cmake --build "%BUILD_DIR%" --config %BUILD_TYPE% --parallel %JOBS%
    )
    if errorlevel 1 (
        echo [ERROR] Build failed
        exit /b 1
    )
    echo [SUCCESS] Build complete
)

REM Create symlink for IDE support (Windows) - after any build type
if exist "%BUILD_DIR%\compile_commands.json" (
    echo [INFO] Creating compile_commands.json symlink for IDE support...
    cd "%SOURCE_DIR%"

    REM Create symlink pointing to latest build, fallback to copy
    if exist compile_commands.json del compile_commands.json
    mklink compile_commands.json "out\build\%BUILD_TYPE%\compile_commands.json" >nul 2>&1
    if errorlevel 1 (
        echo [WARNING] Could not create symlink. Copying file instead...
        copy "out\build\%BUILD_TYPE%\compile_commands.json" compile_commands.json >nul
    )

    echo [SUCCESS] IDE compile_commands.json created: compile_commands.json -^> out\build\%BUILD_TYPE%\compile_commands.json
)

REM Build tests if needed
if "%RUN_TESTS%"=="true" (
    if "%BUILD_TESTS%"=="true" (
        if "%TESTS_ONLY%"=="true" (
            echo [INFO] Building tests...
        ) else (
            echo [INFO] Building test targets...
        )

        if "%VERBOSE%"=="true" (
            cmake --build "%BUILD_DIR%" --config %BUILD_TYPE% --parallel %JOBS% --verbose
        ) else (
            cmake --build "%BUILD_DIR%" --config %BUILD_TYPE% --parallel %JOBS%
        )

        if errorlevel 1 (
            echo [ERROR] Test build failed
            exit /b 1
        )
        echo [SUCCESS] Tests built
    )
)

REM Run tests if requested
if "%RUN_TESTS%"=="true" (
    echo [INFO] Running tests...
    ctest --test-dir "%BUILD_DIR%" --output-on-failure --config %BUILD_TYPE%
    if errorlevel 1 (
        echo [ERROR] Tests failed
        exit /b 1
    )
    echo [SUCCESS] All tests passed
)

REM Install if not tests only
if "%TESTS_ONLY%"=="false" (
    echo [INFO] Installing to %INSTALL_PREFIX%...
    cmake --install "%BUILD_DIR%" --config %BUILD_TYPE%
    if errorlevel 1 (
        echo [ERROR] Installation failed
        exit /b 1
    )
    echo [SUCCESS] Installation complete
)

REM Build documentation if requested
if "%BUILD_DOCS%"=="true" (
    echo [INFO] Building documentation...
    if "%VERBOSE%"=="true" (
        cmake --build "%BUILD_DIR%" --config %BUILD_TYPE% --target docs --verbose
    ) else (
        cmake --build "%BUILD_DIR%" --config %BUILD_TYPE% --target docs
    )

    if errorlevel 1 (
        echo [WARNING] Documentation build failed
    ) else (
        echo [SUCCESS] Documentation built successfully
        echo [INFO] Documentation location: %BUILD_DIR%\docs\html\index.html

        if "%OPEN_DOCS%"=="true" (
            set "DOCS_INDEX=%BUILD_DIR%\docs\html\index.html"
            if exist "!DOCS_INDEX!" (
                echo [INFO] Opening documentation in browser...
                start "" "!DOCS_INDEX!"
            ) else (
                echo [ERROR] Documentation index not found at: !DOCS_INDEX!
            )
        )
    )
)

echo.
echo [SUCCESS] ========================================
echo [SUCCESS]   Build completed successfully!
echo [SUCCESS] ========================================
echo [INFO] Build directory: %BUILD_DIR%
if "%TESTS_ONLY%"=="false" (
    echo [INFO] Install prefix:  %INSTALL_PREFIX%
)

goto end

:show_help
echo Usage: build.bat [OPTIONS]
echo.
echo Build script for LeetCode C++ project (Windows).
echo.
echo OPTIONS:
echo   -h, --help              Show this help message
echo   -c, --clean             Clean build (remove build directory first)
echo   -t, --type TYPE         Build type: Debug, Release, RelWithDebInfo, MinSizeRel (default: Release)
echo   -d, --build-dir DIR     Build directory (default: out\build\^<type^>)
echo   -j, --jobs N            Number of parallel jobs (default: %JOBS%)
echo   -r, --run-tests         Run tests after building
echo   -i, --install PREFIX    Install to PREFIX directory (default: out\install\^<type^>)
echo   -v, --verbose           Verbose build output
echo       --no-tests          Don't build tests
echo       --tests-only        Build and run tests only (implies --run-tests)
echo       --docs              Build documentation (requires Doxygen)
echo       --open-docs         Build and open documentation in browser (implies --docs)
echo.
echo EXAMPLES:
echo   build.bat                         # Build Release version
echo   build.bat -c -t Debug             # Clean build in Debug mode
echo   build.bat -t Debug -r             # Build Debug and run tests
echo   build.bat --tests-only            # Build and run tests only
echo   build.bat -i C:\local             # Build and install to C:\local
echo   build.bat --docs                  # Build documentation
echo   build.bat --open-docs             # Build and open documentation in browser
echo.

:end
