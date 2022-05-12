USE JudgeSystemDB;
GO

-- Roles
INSERT INTO Roles([Name]) VALUES ('User');
INSERT INTO Roles([Name]) VALUES ('Lecturer');
INSERT INTO Roles([Name]) VALUES ('Administrator');

-- Users
INSERT INTO Users(UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Presiyan01', 'Presiyan01@email.com', 0, 'a26903271e6e70b358e1265c6a604529cca8a5da4e57692dd5437b39947761c2', '0878434131', NULL, 'Presiyan', 'Todorov');

INSERT INTO Users(UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Ivan', 'Ivan@email.com', 1, 'fc7378392c1765db5a73d6bdef1484683770ef3197f9e8a1bd7181014e7bf25c', '0878687121', NULL, 'Ivan', 'Ivanov');

INSERT INTO Users(UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Marto', 'Marto@email.com', 0, 'a26903271e6e70b358e1265c6a604529cca8a5da4e57692dd5437b39947761c2', '0878421531', NULL, 'Martin', 'Minchev');

INSERT INTO Users(UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Boyan', 'Boyan@email.com', 0, '2224fd494c8b3b59ecc4c2a46dbca801fd627842fd011e0493f0cc7522754cb7', '0878132131', NULL, 'Boyan', 'Vasilev');

INSERT INTO Users(UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Bobo', 'Bobo@email.com', 0, 'd823e02f720fed7fb2423add75be1567364d18cd5f73bbbb83c2cd95c1e12578', '0878433152', NULL, 'Boris', 'Gerenski');

INSERT INTO Users(USerName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Vesko', 'Vesko@email.com', 1, '86b8a0580b5f9669adc35f4cf3ee49b1dfb2b09a0638a806b99a6fd5b724e2bb', '0878454762', NULL, 'Veselin', 'Shterev');

INSERT INTO Users(UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Staskata', 'Staskata@email.com', 1, '672255ba6159d5bf3e108263d3765f8a246a09f1103ac27bfa585c286e2faa19', '0878454671', NULL, 'Stanislav', 'Raykov');

INSERT INTO Users(UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Kris', 'Kris@email.com', 0, '1be8d00ab3467f2162800c5980e2cac2c485299d05310ed0be4678b330e6c5e3', '0878467211', NULL, 'Kristiyan', 'Velikov');

INSERT INTO Users(UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Vankata', 'Vankata@email.com', 1, 'bdeea01e93f3372f765ab2d4e6277c033866de52869c7c1c79fabc39a7ef82e8', '0878539671', NULL, 'Ivan', 'Gerov');

INSERT INTO Users(UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Rado', 'Rado@email.com', 0, '5011c12ae372fa1b89c06aaf9b0543fbb359fdf26c72699889296c63f5357198', '0878030191', NULL, 'Radomir', 'Geshev');

INSERT INTO Users(UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Valio00', 'Valio00@email.com', 1, '6d4b43cbf0d212657e52f3355dd0c8e300f66a7e90a02ffc1b2d20a15bcd0843', '0878035108', NULL, 'Valentin', 'Todorov');

INSERT INTO Users(UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) 
VALUES ('Nasko.IT', 'nasko01vasilev@gmail.com', 1, '6d4b43cbf0d212657e52f3355dd0c8e300f66a7e90a02ffc1b2d20a15bcd0843', '0876359189', NULL, 'Atanas', 'Vasilev');

-- User Roles
INSERT INTO UserRoles(UserId, RoleId) values (1, 1);
INSERT INTO UserRoles(UserId, RoleId) values (2, 3);
INSERT INTO UserRoles(UserId, RoleId) values (2, 1);
INSERT INTO UserRoles(UserId, RoleId) values (3, 1);
INSERT INTO UserRoles(UserId, RoleId) values (4, 2);
INSERT INTO UserRoles(UserId, RoleId) values (5, 2);
INSERT INTO UserRoles(UserId, RoleId) values (6, 3);
INSERT INTO UserRoles(UserId, RoleId) values (6, 1);
INSERT INTO UserRoles(UserId, RoleId) values (7, 1);
INSERT INTO UserRoles(UserId, RoleId) values (8, 1);
INSERT INTO UserRoles(UserId, RoleId) values (9, 3);
INSERT INTO UserRoles(UserId, RoleId) values (9, 1);
INSERT INTO UserRoles(UserId, RoleId) values (10, 2);
INSERT INTO UserRoles(UserId, RoleId) values (10, 1);
INSERT INTO UserRoles(UserId, RoleId) values (11, 3);
INSERT INTO UserRoles(UserId, RoleId) values (12, 1);

-- Alloweed IP addresses
INSERT INTO AllowedIpAddresses(Value, DisplayName) values ('213.45.6.56', 'FMI Wi-Fi')
INSERT INTO AllowedIpAddresses(Value, DisplayName) values ('188.5.87.31', 'SMG Wi-Fi')
INSERT INTO AllowedIpAddresses(Value, DisplayName) values ('193.25.23.56', 'PMG Sofia Wi-Fi')
INSERT INTO AllowedIpAddresses(Value, DisplayName) values ('199.4.12.42', 'MG Varna Wi-Fi')
INSERT INTO AllowedIpAddresses(Value, DisplayName) values ('221.41.4.5', 'MG Baba Tonka Wi-Fi')

-- Courses
INSERT INTO Courses([Name], OrderBy) VALUES ('Introduction to Programming', 0);
INSERT INTO Courses([Name], OrderBy) VALUES ('Programming Fundamentals', 10);
INSERT INTO Courses([Name], OrderBy) VALUES ('OOP Basics', 20);;
INSERT INTO Courses([Name], OrderBy) VALUES ('Data Structures', 40);
INSERT INTO Courses([Name], OrderBy) VALUES ('Algorithms', 50);

-- Lessons
-- Introduction to programming
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Data Types and Varaibles', 1, 0);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Conditional Statements', 1, 10);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Loops', 1, 20);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Nested Loops', 1, 30);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Exam Preperation', 1, 40);

-- Programming Fundamentals
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Arrays', 2, 0);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Methods', 2, 10);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('List', 2, 20);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Software Development Concepts', 2, 30);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Bitwise Operations', 2, 40);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Text Processing', 2, 50);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Associative Arrays', 2, 60);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Regular Exrepssions', 2, 70);

-- OOP Basics
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Classes and Objects', 3, 0);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Encapsulation', 3, 10);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Inheritance', 3, 20);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Interfaces and Abstraction', 3, 30);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Polymorphism', 3, 40);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Exception Handling', 3, 50);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Debugging Techniques', 3, 60);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('SOLID', 3, 70);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Unit Testing', 3, 80);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Design Patterns', 3, 90);

-- Data Structures
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Linear Data Structures', 4, 0);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Stack and Queue', 4, 10);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Binary Search Tree', 4, 20);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Balanced Search Trees', 4, 30);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Hash Tables', 4, 40);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Graphs', 4, 50);

-- Algorithms
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Recursion and Backtracking', 5, 0);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Combinatorial Problems', 5, 10);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Searching, Sorting and Greedy Algorithms', 5, 20);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Graph Theory, Traversal and Shortest Paths', 5, 30);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Dynamic Programming', 5, 40);
INSERT INTO Lessons ([Name], CourseId, OrderBy) VALUES('Graphs Topologica Sorting, MST', 5, 0);

-- Problems
-- Data types and variables
INSERT INTO Problems([Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES('Sum Two Numbers', 0, 100, 1, 5, 300, 10, 10);
INSERT INTO Problems([Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES('Caluclator', 1, 100, 1, 7, 500, 10, 20);

-- Conditional statements
INSERT INTO Problems([Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES('Max Number', 0, 100, 2, 5, 300, 10, 0);
INSERT INTO Problems([Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES('Min Number', 0, 100, 2, 5, 300, 10, 10);

-- Loops
INSERT INTO Problems([Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES('Sum numbers', 0, 100, 3, 10, 500, 20, 0);
INSERT INTO Problems([Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES('Average number', 0, 100, 3, 10, 500, 20, 10);
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(8, 'Min and Max Number', 0, 100, 3, 10, 500, 20, 20);

-- Nested loops
INSERT INTO Problems([Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES('Write Matrix', 0, 100, 4, 12, 600, 30, 0);
INSERT INTO Problems([Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES('Labyrinth', 0, 100, 4, 10, 500, 20, 10);

-- Arrays
INSERT INTO Problems([Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES('Shift Array', 0, 10, 6, 10, 500, 50, 0);
INSERT INTO Problems([Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES('Sort', 0, 20, 6, 15, 700, 50, 10);

-- Resources
INSERT INTO Resources(LessonId, [Name], FilePath, OrderBy)
VALUES(1, 'Data Types and Varaibles', 'fileServer/1/1/Data-Types-and-variables.pptx', 0);
INSERT INTO Resources(LessonId, [Name], FilePath, OrderBy)
VALUES(1, 'Sum Two Numbers Solution', 'fileServer/1/1/sum-two-numbers.cpp', 10);
INSERT INTO Resources(LessonId, [Name], FilePath, OrderBy)
VALUES(1, 'Data Types and Varables - Exercise', 'fileServer/1/1/data-types-and-variables-exercise.docx', 20);

-- Submissions
INSERT INTO Submissions([Code], ProblemId, SubmisionDate, UserId, CompilationErrors, ActualPoints)
VALUES(
	CONVERT(VARBINARY(MAX),
	'#include<iostream>; int main() { int a,b; cin >> a >> b; cout << a + b;}'),
	1,
	'2022-05-13 00:05:31.327',
	1,
	NULL,
	100);
INSERT INTO Submissions([Code], ProblemId, SubmisionDate, UserId, CompilationErrors, ActualPoints)
VALUES(
	CONVERT(VARBINARY(MAX), '#include<iostream> int main() { int a,b; cin >> a >> b; cout << a + b;}'), 
	1, 
	'2022-05-13 00:01:31.327', 
	1, 
	CONVERT(VARBINARY(MAX), 'Missing ; on the first line'), 
	0);

-- Tests
INSERT INTO Tests(ProblemId, Input, ExpectedOutput, IsTrialTest, OrderBy)
VALUES(1, '5\n5', '10', 1, 0);
INSERT INTO Tests(ProblemId, Input, ExpectedOutput, IsTrialTest, OrderBy)
VALUES(1, '5\n3', '8', 1, 10);
INSERT INTO Tests(ProblemId, Input, ExpectedOutput, IsTrialTest, OrderBy)
VALUES(1, '5\n-3', '2', 0, 20);
INSERT INTO Tests(ProblemId, Input, ExpectedOutput, IsTrialTest, OrderBy)
VALUES(1, '5\n150', '155', 0, 30);
INSERT INTO Tests(ProblemId, Input, ExpectedOutput, IsTrialTest, OrderBy)
VALUES(1, '-5\n-150', '-155', 0, 40);

-- Executed Tests
INSERT INTO ExecutedTests(CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed)
VALUES('2022-05-13 00:05:31.327', 1, '10', 1, 1, NULL, 'Correct', 2, 200);
INSERT INTO ExecutedTests(CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed)
VALUES('2022-05-13 00:05:31.358', 1, '8', 2, 1, NULL, 'Correct', 2, 200);
INSERT INTO ExecutedTests(CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed)
VALUES('2022-05-13 00:05:32.327', 0, NULL, 3, 1, 'Cannot parse negative number', 'Run Time Error', 3, 500);
INSERT INTO ExecutedTests(CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed)
VALUES('2022-05-13 00:05:32.258', 1, '155', 4, 1, NULL, 'Correct', 2, 200);
INSERT INTO ExecutedTests(CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed)
VALUES('2022-05-13 00:05:31.589', 0, NULL, 5, 1, 'Cannot parse negative number', 'Run Time Error', 4, 350);

-- Contests
INSERT INTO Contests(StartTime, EndTime, LessonId, [Name], PasswordHash)
VALUES('2022-05-13 00:00:00.000', '2022-05-18 00:00:00.000', 1, 'Data types and varaibles - Homework', NULL);

-- UserContests
INSERT INTO UserContests(UserId, ContestId) VALUES(1, 1);

-- ContestAllowedIpAddresses
INSERT INTO ContestAllowedIpAddresses(ContestId, AllowedIpAddressId) VALUES(1, 1);