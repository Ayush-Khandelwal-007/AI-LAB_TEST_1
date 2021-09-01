# AI-LAB_TEST_1
College Lab Test Answers
---
Q1. A number of students would like to send gifts to a particular faculty. Each student has a gift that is associated with a weight. The distance from every student to every faculty and between every student is known. The students collectively hire a volunteer to collect gifts from the students and send the gifts to the faculty. The volunteer can pick up gifts worth a maximum of W grams. Calculate the total cost of navigation by the volunteer using Uniform Cost Search. The volunteer always starts its journey from the location of the faculty.

Input Format: The first line of input is T. the number of test cases. For every test case, the first line is in the number of persons (1 faculty and n-1 students). The next n lines with n integers each contain the cost to navigate between every person. The integer in line contains the distance between student/faculty/ and student/faculty/The index of the faculty is fixed to 0, while the students have indices 1 to n-1. The next line contains n-1 integers that is the weight of the gift with the student in their order of indices. The last line for every test case contains the weight limit W.

### Limit : 0<n<=15
## Sample Test Case
### Input

1 </br>
5 </br>
0 2 3 4 10 </br>
2 0 5 4 8 </br>
3 5 0 7 9 </br>
4 4 7 0 10 </br>
10 8 9 10 0 </br>
9 4 2 5 </br>
12

### Output
30

###Explanation

Step 1: Start from source (fixed to faculty or 0)

Step 2: Go to person 1 (student 0) to pick gift with cost 2

Step 3: Since the volunteer is carrying 9 worth of weight (with a limit of 12), return to faculty (or 0) with cost 2

Step 4: Go to person 2 (student 1) to pick gift with cost 3

Step 5: Go to person 4 (student 3) to pick gift with cost 9

Step 6: Go to person 3 (student 2) to pick gift with cost 10

Step 7: Since the volunteer is carrying 2+5+4 worth of weight (with a limit of 12), return to faculty (or 0) with cost 4

No more gifts to deliver, terminate

---
Q2. In question 1 print the tour as a list of vertices visited instead of the cost. In case of a tie print the lexicographically shortest route (taking the path as a string so "10" < "2", "11" < "2", and so on)

Input Format: The first line of input is T. the number of test cases. For every test case, the first line is in the number of persons (1 faculty and n-1 students). The next n lines with n integers each contain the cost to navigate between every person. The integer in line contains the distance between student/faculty/ and student/faculty/The index of the faculty is fixed to 0, while the students have indices 1 to n-1. The next line contains n-1 integers that is the weight of the gift with the student in their order of indices. The last line for every test case contains the weight limit W.

## Sample Test Case
### Input

1 </br>
5 </br>
0 2 3 4 10 </br>
2 0 5 4 8 </br>
3 5 0 7 9 </br>
4 4 7 0 10 </br>
10 8 9 10 0 </br>
9 4 2 5 </br>
12

### Output
0 1 0 2 4 3 0

###Explanation

Step 1: Start from source (fixed to faculty or 0)

Step 2: Go to person 1 (student 0) to pick gift with cost 2

Step 3: Since the volunteer is carrying 9 worth of weight (with a limit of 12), return to faculty (or 0) with cost 2

Step 4: Go to person 2 (student 1) to pick gift with cost 3

Step 5: Go to person 4 (student 3) to pick gift with cost 9

Step 6: Go to person 3 (student 2) to pick gift with cost 10

Step 7: Since the volunteer is carrying 2+5+4 worth of weight (with a limit of 12), return to faculty (or 0) with cost 4

No more gifts to deliver, terminate
