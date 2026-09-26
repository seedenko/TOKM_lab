@echo off
chcp 65001 > nul
title Командная строка - tetgen.exe -fenv stars_sidenko.node
mode con: cols=95 lines=32
cls
echo d:\ForWorkStudy\Projects\bsu\sidenko\выполнение\lab3\data^> tetgen.exe -fenv stars_sidenko.node
tetgen.exe -fenv stars_sidenko.node
echo.
echo d:\ForWorkStudy\Projects\bsu\sidenko\выполнение\lab3\data^> _
pause > nul
