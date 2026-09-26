@echo off
chcp 65001 > nul
title Администратор: Командная строка — tetgen.exe
cd /d "d:\ForWorkStudy\Projects\bsu\sidenko_tokm\lab3\data"
echo Microsoft Windows [Version 10.0.22631.3593]
echo (c) Корпорация Майкрософт (Microsoft Corporation). Все права защищены.
echo.
echo d:\ForWorkStudy\Projects\bsu\sidenko_tokm\lab3\data^> tetgen.exe -fenv stars_sidenko.node
tetgen.exe -fenv stars_sidenko.node
echo.
echo d:\ForWorkStudy\Projects\bsu\sidenko_tokm\lab3\data^>
pause > nul
