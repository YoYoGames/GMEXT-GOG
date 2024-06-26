# GMEXT-GOG
Repository for GameMaker's GOG Extension

This repository was created with the intent of presenting users with the latest version available of the extension (even previous to marketplace updates) and also provide a way for the community to contribute with bug fixes and feature implementation.

This extension will work on Windows and macOS.

VISUAL STUDIO SOURCE: `source/GOG_vs/`

XCODE SOURCE: `source/GOG_xcode/`

After compilation the exported dll/dylib file is automatically copied into the extension folder inside the included GameMaker project folder.


---

## Important

Do not download from the **main branch** this branch is a work in place branch and probably has features that might be broken or not working properly, please download from the releases panel (right side instead).

---

## Requirements

In order to compile for Windows/macOS you are required to [download the GOG Galaxy SDK v1.152.10](https://devportal.gog.com/galaxy/components/sdk) and place it inside `source/GOG_sdk/`

---

## Documentation

We provide both a PDF version of the documentation included with the extension and inside the demo project (datafiles) and a fully converted version to the [Github Wiki](https://github.com/YoYoGames/GMEXT-GOG/wiki) format (the latter will be the most up-to-date version, the other will follow shortly after). *If there are any PR requests with new feature implementation please make sure you also provide the documentation for the implemented features.*
