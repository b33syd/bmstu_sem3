#!/bin/bash

#colors for print
RED=`tput setaf 1`
NC=`tput sgr0`
YELLOW=`tput setaf 3`
GREEN=`tput setaf 2`

DATE=`date +%Y-%m-%d-%H-%M-%S`

mkdir tests/$DATE
OUTFOLDER=tests/$DATE
REPORT=$OUTFOLDER/report.txt

#  |tee -a  $REPORT  create file with stdout and print stdout to console


make -i clean
make -i main								|tee -a  $REPORT


echo "	${YELLOW} Start unit testing ${NC}"
make -i moduletest							|tee -a  $REPORT
echo  "	${YELLOW} End unit testing ${NC}"


echo "	${YELLOW} Start functional testing ${NC}"			|tee -a  $REPORT
make -i main                                                            |tee -a  $REPORT
./main 				>$OUTFOLDER/out1
./main tests/does_not_exist 	>$OUTFOLDER/out2
./main tests/empty_file		>$OUTFOLDER/out3
./main tests/first_max		>$OUTFOLDER/out4
./main tests/end_max		>$OUTFOLDER/out5
./main tests/cenrte_pair_max	>$OUTFOLDER/out6
./main tests/cenrte__max	>$OUTFOLDER/out7
./main tests/normal		>$OUTFOLDER/out8

ls $OUTFOLDER | grep '^out' | while read line
do
	diff -q $OUTFOLDER/$line tests/answers/$line  >/dev/null
	if [[ $? == "0" ]]
	then
  		echo "Test with file "$line" ${GREEN}pass ${NC}"  			|tee -a  $REPORT
	else
 		echo "Test with file "$line" ${RED} FAILED ${NC}"	|tee -a  $REPORT
		echo diff $OUTFOLDER/$line tests/answers/$line 		|tee -a  $REPORT
        	diff $OUTFOLDER/$line tests/answers/$line  		|tee -a  $REPORT

	fi
done

echo "  ${YELLOW} End functional testing ${NC}"                       	|tee -a  $REPORT

echo "  ${YELLOW} Start valgrind testing ${NC}"                       	|tee -a  $REPORT
make -i	valgrind							|tee -a  $REPORT
echo "  ${YELLOW} End valgrind testing ${NC}"                       	|tee -a  $REPORT


echo "  ${YELLOW} Start code review ${NC}"                      |tee -a  $REPORT
cd tests/Utils/
wine CodeChecker.exe ../../main.c				|tee -a  ../../$REPORT
wine CodeChecker.exe ../../functions.c				|tee -a  ../../$REPORT
wine CodeChecker.exe ../../moduletest.c				|tee -a  ../../$REPORT
wine CodeChecker.exe ../../functions.h				|tee -a  ../../$REPORT
cd ../../
echo "  ${YELLOW} End code review ${NC}"                      |tee -a  $REPORT

