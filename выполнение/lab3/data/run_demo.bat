@echo off
chcp 65001 > nul
title TetGen 1.5 CLI - [Sidenko Valeria, gr. 12002531]
color 0A
cd /d "d:\ForWorkStudy\Projects\bsu\sidenko_tokm\lab3\data"
echo ===============================================================================
echo   TetGen 1.5 - Quality Tetrahedral Mesh Generator and 3D Delaunay Triangulator
echo   Лабораторная работа №3. Студентка: Сиденко Валерия (гр. 12002531)
echo ===============================================================================
echo.
echo [COMMAND]: tetgen.exe -fenv stars_sidenko.node
echo.
tetgen.exe -fenv stars_sidenko.node
echo.
echo ===============================================================================
echo   Генерация завершена успешно! Файлы сеток Делоне и Вороного созданы.
echo ===============================================================================
pause
