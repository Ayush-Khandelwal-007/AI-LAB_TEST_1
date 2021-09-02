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

### Explanation

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

### Explanation

Step 1: Start from source (fixed to faculty or 0)

Step 2: Go to person 1 (student 0) to pick gift with cost 2

Step 3: Since the volunteer is carrying 9 worth of weight (with a limit of 12), return to faculty (or 0) with cost 2

Step 4: Go to person 2 (student 1) to pick gift with cost 3

Step 5: Go to person 4 (student 3) to pick gift with cost 9

Step 6: Go to person 3 (student 2) to pick gift with cost 10

Step 7: Since the volunteer is carrying 2+5+4 worth of weight (with a limit of 12), return to faculty (or 0) with cost 4

No more gifts to deliver, terminate
---
Q3. A number of students would like to send gifts to a particular faculty from a set of available faculties. Each student has a gift that is associated with a weight and a faculty to which the gift is to be given. The distance between every person is known. The students. collectively hire a volunteer to collect gifts from the students and send the gifts to the faculties. The volunteer can pick up gifts worth a maximum of W grams. Calculate the total cost of navigation by the volunteer using Uniform Cost Search. The volunteer always starts its journey from the location of the faculty indexed 0.


Input Format: The first line of input is T, the number of test cases. For every test case, the first line is mand in the number of persons (m faculty and n students). The next m+n lines with men integers each contain the cost to navigate between every person. The integer in hline contains the distance between student/faculty and student/faculty. The index of the faculty is from 0 to m-1, while the students have indices m to min-1. The next n lines contain weight of the gift and the index of the faculty in the order of indices of the student. The last line for every test case contains the weight limit W

### Limit : 0<m,n<=15

## Sample Test Case

### Input

1 </br>
2 5</br>
0 6 5 4 2 7 8 </br>
6 0 1 3 5 1 8 </br>
5 1 0 4 4 2 7 </br>
4 3 4 0 5 4 9 </br>
2 5 4 5 0 6 8 </br>
7 1 2 4 6 0 9 </br>
8 8 7 9 8 9 0 </br>
4 1 </br>
10 0 </br>
6 1 </br>
10 0 </br>
4 0 </br>
11

### Output
39

### Explanation

Faculty Index 0 = person index 0

Faculty index 1 person index 1

Student index 0 = person index 2

Student Index 1 = person index 3

Student index 2 person index 4

Student Index 3 = person index 5

Student index 4 = person index 6



Step 1: Start from 0 (fixed)

Step 2: Go to person 3 (student index 1) to collect gift with cost 4

Step 3: Since volunteer is carrying weight 10 (limit 11), return to the faculty 0 to deliver gift with cost 4

Step 4: Go to person 4 (student index 2) to collect gift with cost 2

Step 5: Go to person 2 (student index 0) to collect gift with cost 4

Step 6: Since volunteer is carrying weight 6+4 (limit 11), return to the faculty 1 to deliver gift with cost 1

Step 7: Go to person 5 (student index 3) to collect gift with cost 1

Step 8: Since volunteer is carrying weight 10 (limit 11), return to the faculty 0 to deliver gift with cost 7

Step 9: Go to person (student index 4) to collect gift with cost 8

Step 10. Since volunteer is carrying weight 4 (limit 11), return to the faculty 0 to deliver gift with cost 8

No more gifts, terminate

---
Q4. In question 3 print the tour as a list of vertices visited instead of the cost. In case of a tie print the lexicographically shortest route (taking the path as a string so "10" < "2", "11" < "2", and so on)

Input Format: The first line of input is T, the number of test cases. For every test case, the first line is mand in the number of persons (m faculty and n students). The next m+n lines with men integers each contain the cost to navigate between every person. The integer in hline contains the distance between student/faculty and student/faculty. The index of the faculty is from 0 to m-1, while the students have indices m to min-1. The next n lines contain weight of the gift and the index of the faculty in the order of indices of the student. The last line for every test case contains the weight limit W

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
0 3 0 4 2 1 5 0 6 0

### Explanation


Faculty Index 0 = person index 0

Faculty index 1 person index 1

Student index 0 = person index 2

Student Index 1 = person index 3

Student index 2 person index 4

Student Index 3 = person index 5

Student index 4 = person index 6



Step 1: Start from 0 (fixed)

Step 2: Go to person 3 (student index 1) to collect gift with cost 4

Step 3: Since volunteer is carrying weight 10 (limit 11), return to the faculty 0 to deliver gift with cost 4

Step 4: Go to person 4 (student index 2) to collect gift with cost 2

Step 5: Go to person 2 (student index 0) to collect gift with cost 4

Step 6: Since volunteer is carrying weight 6+4 (limit 11), return to the faculty 1 to deliver gift with cost 1

Step 7: Go to person 5 (student index 3) to collect gift with cost 1

Step 8: Since volunteer is carrying weight 10 (limit 11), return to the faculty 0 to deliver gift with cost 7

Step 9: Go to person (student index 4) to collect gift with cost 8

Step 10. Since volunteer is carrying weight 4 (limit 11), return to the faculty 0 to deliver gift with cost 8

No more gifts, terminate
