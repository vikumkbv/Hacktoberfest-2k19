#!/bin/bash
UP=$(uptime -p | xargs echo "The System has been" )
#UP=$(uptime | awk '{print $2,$3,$4}')
echo "------------------------------------------------------"
echo $UP
echo "-----------------------------------------------------"
echo -n "The Current time is "
TIME=$(uptime| awk '{print $1}')
echo $TIME
echo "--------------------------------------------------"
echo -n "The Numbers of users currently logged in are "
USER=$(uptime| cut -d "," -f 2)
echo $USER
echo "-------------------------------------------------------------"
echo -n "Load Average in the past 1,5,15 minutes prespectively are "
LOAD=$(uptime | cut -d "," -f 3,4,5|cut -d ":" -f 2,3)
echo $LOAD
echo "----------------------------------------
The Free disk space, Total Disk space is"
echo
df -h|awk '{print $1,$3,$4}'
echo "--------------------------------------------"
#echo $DISK
echo "The Total memory and Free memory is "
echo
cat /proc/meminfo| head -n 2
echo "--------------------------------------------"
echo "The Top 3 most expensive processes are: "
ps -eo pid,comm,%cpu --sort=%cpu|head -n 4
echo "----------------------------------------------"
echo "The list of all open TCP PORTS"
echo 
netstat -ltn
echo "--------------------------------------------"
echo "All the active connections to the server are: "
netstat  -na
