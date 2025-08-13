## Qt ClientUI Application

### Prerequisites
- Qt 6.9.0
- Microsoft Visual Studio 2022 with MSVC toolchain
- Qt Creator IDE (recommended)
- C++17 compatible compiler
- Windows SDK (version matching your Qt installation)

### Building the Application

#### Using Qt Creator
1. Open Qt Creator
2. File → Open File or Project...
3. Select `ClientUI.pro` from the project directory
4. Select MSVC 2022 64-bit kit when prompted
5. Configure build settings (Debug/Release) in the Projects panel
6. Build → Build Project "ClientUI"
7. Run → Run to start the application

#### Command Line Build
```bash
cd GUI
qmake -spec win32-msvc "CONFIG+=debug" ClientUI.pro
nmake
```

### Project Structure
```
GUI/
├── ClientUI.pro        # Main project file
├── ClientUI.cpp        # Main application window
├── ClientUI.h          # Main window header
├── ClientUI.ui         # Main window UI design
├── LoginWidget.*       # Authentication UI components
├── GroupNameWidget.*   # Group selection components 
├── UserItemWidget.*    # User list item components
├── DES_c.*             # DES encryption implementation
└── main.cpp            # Application entry point
```

### Dependencies
- Qt Core
- Qt GUI
- Qt Widgets
- Qt Network
- Qt Concurrent

### Configuration Notes
- Ensure Qt is configured with MSVC 2022 64-bit compiler
- Debug builds require Qt debug libraries
- Project uses Qt's meta-object compiler (moc) for signals/slots
- UI files are compiled using Qt's User Interface Compiler (uic)

### Troubleshooting
**Common Build Issues:**
- **Missing Qt Modules**: Verify installed components in Qt Maintenance Tool
- **Compiler Mismatch**: Ensure Qt kit matches MSVC 2022 64-bit
- **Debug Library Errors**: Install debug information files for Qt
- **qmake Path Issues**: Add Qt bin directory to system PATH

**Runtime Issues:**
- **DLL Not Found**: Copy required Qt DLLs to executable directory
- **UI Rendering Issues**: Rebuild project after modifying .ui files

### Cleaning the Build
```bash
nmake clean
