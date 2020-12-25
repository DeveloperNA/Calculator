
A simple Calculator developed for windows platform. It was fully written using Qt C++.

<img src="/output.gif" width="320" alt="output.gif">

###Highlights

* Calculator can be used with your most convenient input device<u>(Keyboard or Mouse)</u>.
* No need to press/click equal all the time to generate the result. 
* It can handle the entire expression without any complication.
<br>

###How to Deploy

####windeployqt
To deploy the application in windows, we are needed to install the latest Qt Framework in https://www.qt.io/download. Make sure the windeployqt is available in bin folder of your installed Qt folder.

```cmd
windeployqt calculator.exe
```
![deploy-folder](/deploy-info.png)

The above command will put dependencies together.

 \- Execute this command in the location where the application needs to be deployed.

####QtInstallerFramework

Download the available latest Qt Installer Framework available in https://download.qt.io/official_releases/qt-installer-framework/.

Following are the folder structure to be followed to generate the installer:-

![Installer-info](/Installer-info.jpg)

Run the command in root folder(CalculatorApp Installer):-
```cmd
C:\Qt\QtIFW-4.0.1\bin\binarycreator.exe -c config/config.xml -p packages CalculatorAppInstaller.exe
```
This will generate the installer for the CalculatorApp