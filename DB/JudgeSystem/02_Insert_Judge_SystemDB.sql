USE JudgeSystemDB;
GO

-- Roles
SET IDENTITY_INSERT Roles ON
INSERT INTO Roles(Id, [Name]) VALUES (1, 'User');
INSERT INTO Roles(Id, [Name]) VALUES (2, 'Lecturer');
INSERT INTO Roles(Id, [Name]) VALUES (3, 'Administrator');
SET IDENTITY_INSERT JudgeSystemDB.dbo.Users ON;

INSERT INTO Users(Id, UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) values (
				1, 'Presiyan01', 'Presiyan01@email.com', 0, 'a26903271e6e70b358e1265c6a604529cca8a5da4e57692dd5437b39947761c2', '0878434131', NULL, 'Presiyan', 'Todorov');

INSERT INTO Users(Id, UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) values (
				2, 'Ivan', 'Ivan@email.com', 1, 'fc7378392c1765db5a73d6bdef1484683770ef3197f9e8a1bd7181014e7bf25c', '0878687121', NULL, 'Ivan', 'Ivanov');

INSERT INTO Users(Id, UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) values (
				3, 'Marto', 'Marto@email.com', 0, 'a26903271e6e70b358e1265c6a604529cca8a5da4e57692dd5437b39947761c2', '0878421531', NULL, 'Martin', 'Minchev');

INSERT INTO Users(Id, UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) values (
				4, 'Boyan', 'Boyan@email.com', 0, '2224fd494c8b3b59ecc4c2a46dbca801fd627842fd011e0493f0cc7522754cb7', '0878132131', NULL, 'Boyan', 'Vasilev');

INSERT INTO Users(Id, UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) values (
				5, 'Bobo', 'Bobo@email.com', 0, 'd823e02f720fed7fb2423add75be1567364d18cd5f73bbbb83c2cd95c1e12578', '0878433152', NULL, 'Boris', 'Gerenski');

INSERT INTO Users(Id, USerName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) values (
				6, 'Vesko', 'Vesko@email.com', 1, '86b8a0580b5f9669adc35f4cf3ee49b1dfb2b09a0638a806b99a6fd5b724e2bb', '0878454762', NULL, 'Veselin', 'Shterev');

INSERT INTO Users(Id, UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) values (
				7, 'Staskata', 'Staskata@email.com', 1, '672255ba6159d5bf3e108263d3765f8a246a09f1103ac27bfa585c286e2faa19', '0878454671', NULL, 'Stanislav', 'Raykov');

INSERT INTO Users(Id, UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) values (
				8, 'Kris', 'Kris@email.com', 0, '1be8d00ab3467f2162800c5980e2cac2c485299d05310ed0be4678b330e6c5e3', '0878467211', NULL, 'Kristiyan', 'Velikov');

INSERT INTO Users(Id, UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) values (
				9, 'Vankata', 'Vankata@email.com', 1, 'bdeea01e93f3372f765ab2d4e6277c033866de52869c7c1c79fabc39a7ef82e8', '0878539671', NULL, 'Ivan', 'Gerov');

INSERT INTO Users(Id, UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) values (
				10, 'Rado', 'Rado@email.com', 0, '5011c12ae372fa1b89c06aaf9b0543fbb359fdf26c72699889296c63f5357198', '0878030191', NULL, 'Radomir', 'Geshev');

INSERT INTO Users(Id, UserName, Email, EmailConfirmed, PasswordHash, PhoneNumber, ModifiedOn, FirstName, LastName) values (
				11, 'Valio00', 'Valio00@email.com', 1, '6d4b43cbf0d212657e52f3355dd0c8e300f66a7e90a02ffc1b2d20a15bcd0843', '0878035108', NULL, 'Valentin', 'Todorov');

SET IDENTITY_INSERT Roles ON;

INSERT INTO Roles(Id, [Name]) VALUES (1, 'User');
INSERT INTO Roles(Id, [Name]) VALUES (2, 'Lecturer');
INSERT INTO Roles(Id, [Name]) VALUES (3, 'Administrator');

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

SET IDENTITY_INSERT AllowedIpAddresses ON;

INSERT INTO AllowedIpAddresses(Id, Value, DisplayName) values (1, '213.45.6.56', 'FMI Wi-Fi')
INSERT INTO AllowedIpAddresses(Id, Value, DisplayName) values (2, '188.5.87.31', 'SMG Wi-Fi')
INSERT INTO AllowedIpAddresses(Id, Value, DisplayName) values (3, '193.25.23.56', 'PMG Sofia Wi-Fi')
INSERT INTO AllowedIpAddresses(Id, Value, DisplayName) values (4, '199.4.12.42', 'MG Varna Wi-Fi')
INSERT INTO AllowedIpAddresses(Id, Value, DisplayName) values (5, '221.41.4.5', 'MG Baba Tonka Wi-Fi')


-- Courses
SET IDENTITY_INSERT Courses ON
INSERT INTO Courses(Id, [Name], OrderBy) VALUES (1, 'Introduction to Programming', 0);
INSERT INTO Courses(Id, [Name], OrderBy) VALUES (2, 'Programming Fundamentals', 10);
INSERT INTO Courses(Id, [Name], OrderBy) VALUES (3, 'OOP Basics', 20);;
INSERT INTO Courses(Id, [Name], OrderBy) VALUES (5, 'Data Structures', 40);
INSERT INTO Courses(Id, [Name], OrderBy) VALUES (6, 'Algorithms', 50);

-- Lessons
SET IDENTITY_INSERT Lessons ON
-- Introduction to programming
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(1, 'Data Types and Varaibles', 1, 0);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(2, 'Conditional Statements', 1, 10);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(3, 'Loops', 1, 20);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(4, 'Nested Loops', 1, 30);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(5, 'Exam Preperation', 1, 40);

-- Programming Fundamentals
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(6, 'Arrays', 2, 0);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(7, 'Methods', 2, 10);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(8, 'List', 2, 20);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(9, 'Software Development Concepts', 2, 30);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(10, 'Bitwise Operations', 2, 40);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(11, 'Text Processing', 2, 50);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(12, 'Associative Arrays', 2, 60);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(13, 'Regular Exrepssions', 2, 70);

-- OOP Basics
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(14, 'Classes and Objects', 3, 0);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(15, 'Encapsulation', 3, 10);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(16, 'Inheritance', 3, 20);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(17, 'Interfaces and Abstraction', 3, 30);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(18, 'Polymorphism', 3, 40);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(19, 'Exception Handling', 3, 50);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(20, 'Debugging Techniques', 3, 60);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(21, 'SOLID', 3, 70);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(22, 'Unit Testing', 3, 80);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(23, 'Design Patterns', 3, 90);

-- Data Structures
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(24, 'Linear Data Structures', 4, 0);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(25, 'Stack and Queue', 4, 10);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(26, 'Binary Search Tree', 4, 20);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(27, 'Balanced Search Trees', 4, 30);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(28, 'Hash Tables', 4, 40);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(29, 'Graphs', 4, 50);

-- Algorithms
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(25, 'Recursion and Backtracking', 5, 0);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(26, 'Combinatorial Problems', 5, 10);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(27, 'Searching, Sorting and Greedy Algorithms', 5, 20);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(28, 'Graph Theory, Traversal and Shortest Paths', 5, 30);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(29, 'Dynamic Programming', 5, 40);
INSERT INTO Lessons (Id, [Name], CourseId, OrderBy) VALUES(30, 'Graphs Topologica Sorting, MST', 5, 0);

-- Problems
SET IDENTITY_INSERT Lessons ON
-- Data types and variables
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(1, 'Sum Two Numbers', 0, 100, 1, 5, 300, 10, 10);
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(2, 'Caluclator', 1, 100, 1, 7, 500, 10, 20);

-- Conditional statements
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(3, 'Max Number', 0, 100, 2, 5, 300, 10, 0);
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(4, 'Min Number', 0, 100, 2, 5, 300, 10, 10);

-- Loops
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(6, 'Sum numbers', 0, 100, 3, 10, 500, 20, 0);
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(7, 'Average number', 0, 100, 3, 10, 500, 20, 10);
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(8, 'Min and Max Number', 0, 100, 3, 10, 500, 20, 20);

-- Nested loops
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(9, 'Write Matrix', 0, 100, 4, 12, 600, 30, 0);
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(10, 'Labyrinth', 0, 100, 4, 10, 500, 20, 10);

-- Arrays
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(11, 'Shift Array', 0, 10, 6, 10, 500, 50, 0);
INSERT INTO Problems(Id, [Name], IsExtraTask, MaxPoints, LessonId, AllowedMemoryInMegaBytes, AllowedTimeInMilliseconds, TimeIntervalBetweenSubmissionInSeconds, OrderBy)
VALUES(12, 'Sort', 0, 20, 6, 15, 700, 50, 10);

-- Resources
INSERT INTO Resources(LessonId, [Name], FilePath, OrderBy)
VALUES(1, 'Data Types and Varaibles', 'fileServer/1/1/Data-Types-and-variables.pptx', 0);
INSERT INTO Resources(LessonId, [Name], FilePath, OrderBy)
VALUES(1, 'Sum Two Numbers Solution', 'fileServer/1/1/sum-two-numbers.cpp', 10);
INSERT INTO Resources(LessonId, [Name], FilePath, OrderBy)
VALUES(1, 'Data Types and Varables - Exercise', 'fileServer/1/1/data-types-and-variables-exercise.docx', 20);

-- Submissions
INSERT INTO Submissions(Id, [Code], ProblemId, SubmisionDate, UserId, CompilationErrors, ActualPoints)
VALUES(1, '#include<iostream>; int main() { int a,b; cin >> a >> b; cout << a + b;}', 1, '2022-05-13 00:05:31.327', 1, NULL, 100);
INSERT INTO Submissions([Code], ProblemId, SubmisionDate, UserId, CompilationErrors, ActualPoints)
VALUES(2, '#include<iostream> int main() { int a,b; cin >> a >> b; cout << a + b;}', 1, '2022-05-13 00:01:31.327', 1, 'MIssing ; on the first line', 0);

-- Tests
INSERT INTO Tests(Id, ProblemId, Input, ExpectedOutput, IsTrialTest, OrderBy)
VALUES(1, 1, '5\n5', '10', 1, 0);
INSERT INTO Tests(Id, ProblemId, Input, ExpectedOutput, IsTrialTest, OrderBy)
VALUES(2, 1, '5\n3', '8', 1, 10);
INSERT INTO Tests(Id, ProblemId, Input, ExpectedOutput, IsTrialTest, OrderBy)
VALUES(3, 1, '5\n-3', '2', 0, 20);
INSERT INTO Tests(Id, ProblemId, Input, ExpectedOutput, IsTrialTest, OrderBy)
VALUES(4, 1, '5\n150', '155', 0, 30);
INSERT INTO Tests(Id, ProblemId, Input, ExpectedOutput, IsTrialTest, OrderBy)
VALUES(5, 1, '-5\n-150', '-155', 0, 40);

-- Executed Tests
INSERT INTO ExecutedTests(Id, CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed)
VALUES(1, '2022-05-13 00:05:31.327', 1, '10', 1, 'Correct', 2, 200);
INSERT INTO ExecutedTests(Id, CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed)
VALUES(2, '2022-05-13 00:05:31.358', 1, '8', 2, 'Correct', 2, 200);
INSERT INTO ExecutedTests(Id, CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed)
VALUES(3, '2022-05-13 00:05:32.327', 0, NULL, 3, 'Run Time Error', 3, 500);
INSERT INTO ExecutedTests(Id, CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed)
VALUES(4, '2022-05-13 00:05:32.258', 1, '155', 4, 'Correct', 2, 200);
INSERT INTO ExecutedTests(Id, CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed)
VALUES(5, '2022-05-13 00:05:31.589', 0, NULL, 5, 'Run Time Error', 4, 350);

-- Contests
INSERT INTO Contests(Id, StartTime, EndTime, LessonId, [Name], PasswordHash)
VALUES(1, '2022-05-13 00:00:00.000', '2022-05-18 00:00:00.000', 1, 'Data types and varaibles - Homework', NULL);

-- UserContests
INSERT INTO UserContests(UserId, ContestId) VALUES(1, 1);

-- ContestAllowedIpAddresses
INSERT INTO ContestAllowedIpAddresses(ContestId, AllowedIpAddressId) VALUES(1, 1);