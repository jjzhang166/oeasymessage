@echo off
set windeployqt="D:\qt\Qt5.8.0\5.8\mingw53_32\bin\\windeployqt.exe"

set myissue="OEasyMessage-Qt5-MinGW-release.exe"


echo 当前windeployqt路径是: %windeployqt%


echo --------------------------------------
echo --------------------------------------
echo 若不正确: 
echo 关闭当前脚本，并修改其中的Qt路径。
echo --------------------------------------
echo 若路径正确:
pause
echo --------------------------------------
echo --------------------------------------

%windeployqt% %myissue%

pause