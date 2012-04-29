@set javadir="C:\Program Files\Java\jdk1.6.0_02"
@set mem=1G
@%javadir%\bin\java -Xmx%mem% -server -jar sunflow.jar %*
@if %errorlevel% neq 0 pause
