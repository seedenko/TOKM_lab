@echo off
chcp 65001 > nul
title Командная строка — tetgen.exe -fenv stars_sidenko.node
mode con: cols=90 lines=32
cls
cd /d "d:\ForWorkStudy\Projects\bsu\sidenko_tokm\lab3\data"
echo d:\ForWorkStudy\Projects\bsu\sidenko_tokm\lab3\data^> tetgen.exe -fenv stars_sidenko.node
tetgen.exe -fenv stars_sidenko.node
pause > nul
