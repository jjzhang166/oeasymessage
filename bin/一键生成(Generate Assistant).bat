@echo off
set windeployqt="D:\qt\Qt5.8.0\5.8\mingw53_32\bin\\windeployqt.exe"

set myissue="OEasyMessage-Qt5-MinGW-release.exe"


echo ��ǰwindeployqt·����: %windeployqt%


echo --------------------------------------
echo --------------------------------------
echo ������ȷ: 
echo �رյ�ǰ�ű������޸����е�Qt·����
echo --------------------------------------
echo ��·����ȷ:
pause
echo --------------------------------------
echo --------------------------------------

%windeployqt% %myissue%

pause