Installation von Pathcompare

1.) Installiere ROS Diamondback, siehe dazu:
http://www.ros.org/wiki/diamondback/Installation/Ubuntu


2.) Extrahiere das package pathcompare in das Verzeichnis: 
/opt/ros/diamondback/stacks/


3.) Wechsle in das Verzeichnis 
cd /opt/ros/diamondback/stacks/pathcompare


4.) führe cmake aus:
cmake CMakeLists.txt

5.) starte Buildvorgang
make


Starten von Pathcompare
1.) starte ROS master
roscore

2.) öffne terminal fenster starte pathcompare
rosrun pathcompare pathcompare

