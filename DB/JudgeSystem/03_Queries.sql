USE JudgeSystemDB;
GO

-- Simple Querries
-- 1. Get tests by problem
SELECT *
FROM Tests
WHERE ProblemId = 1;

-- 2. Get upcomming contests
SELECT *
FROM Contests
WHERE StartTime > GETDATE();

-- 3. Get contests in date range
SELECT *
FROM Contests
WHERE GETDATE() BETWEEN StartTime AND EndTime;

-- 4. Get contests by lesson
SELECT *
FROM Contests
WHERE LessonId = 1;

-- 5. Get all the courses
SELECT * 
FROM Courses;

-- 6. Get all the lessons by course
SELECT Id, Name 
FROM Lessons
WHERE CourseId = 3;


-- 2 or more table(union, intersect)

-- 7. Get all the submissions by user
SELECT Users.UserName, Submissions.Id, Submissions.ActualPoints -- 1
FROM Submissions, Users
WHERE Submissions.UserId = Users.Id and Users.UserName = 'Presiyan01'

-- 8. Get tests execution result by problem id
SELECT Problems.Name as [Problem Name], Tests.Id as [Test ID], ExecutedTests.Output, Tests.ExpectedOutput, CASE -- 2
	WHEN ExecutedTests.Output = Tests.ExpectedOutput
		THEN 'Yes'
		ELSE 'No'
	END as [Correct Output] 
FROM Tests, ExecutedTests, Problems
WHERE Tests.Id = ExecutedTests.TestId AND Tests.ProblemId = Problems.Id AND Problems.Id = 1

-- 9. Get tests and problem info by problem
SELECT Problems.Name, Tests.Id, Tests.Input, Tests.ExpectedOutput -- 3
FROM Tests, Problems
WHERE Tests.ProblemId = Problems.Id AND Problems.Id = 1

-- 10. Get information about the contests related to some lesson
SELECT Contests.Id, Contests.Name as [Contest Name], Contests.StartTime, Contests.EndTime,  Lessons.Name as [Lesson Name] -- 4
FROM Contests, Lessons
WHERE Contests.LessonId = Lessons.Id AND Lessons.Name = 'Conditional Statements';


SELECT Courses.Name as [Course Name], Lessons.Name as [Lesson Name] -- 5
FROM Courses, Lessons
WHERE Lessons.CourseId = Courses.Id AND Courses.Name = 'OOP Basics'


-- Nested


-- This querry gives us all the best submissions for all the Problems
SELECT Problems.Id as [Problem ID], Problems.Name, s.Id as [Submission ID], s.[Max Points] -- 1
FROM Problems, (
	SELECT max_s.ProblemId, Submissions.Id, max_s.[Max Points]
	FROM Submissions, (
		SELECT Submissions.ProblemId, MAX(Submissions.ActualPoints) as [Max Points]
		FROM Submissions
		GROUP BY Submissions.ProblemId) AS max_s
	WHERE Submissions.ProblemId = max_s.ProblemId AND Submissions.ActualPoints = max_s.[Max Points]) AS s
WHERE Problems.Id = s.ProblemId
ORDER BY Problems.Id;


-- This querry gives us all the best submissions for all the problemIds
SELECT max_s.ProblemId, Submissions.Id, max_s.[Max Points] -- 1.1
FROM Submissions, (
	SELECT Submissions.ProblemId, MAX(Submissions.ActualPoints) as [Max Points]
	FROM Submissions
	GROUP BY Submissions.ProblemId) AS max_s
WHERE Submissions.ProblemId = max_s.ProblemId AND Submissions.ActualPoints = max_s.[Max Points];


SELECT t.AllowedIpAddressId, t.[Count] -- 2, GET MOST FREQUENT IP ADDRESS
FROM  (
		SELECT ContestAllowedIpAddresses.AllowedIpAddressId, COUNT(1) AS [Count] 
		FROM ContestAllowedIpAddresses
		GROUP BY ContestAllowedIpAddresses.AllowedIpAddressId
	) AS t
WHERE T.[Count] = (
	SELECT MAX([Count]) as m
	FROM (
		SELECT ContestAllowedIpAddresses.AllowedIpAddressId, COUNT(1) AS [Count] 
		FROM ContestAllowedIpAddresses
		GROUP BY ContestAllowedIpAddresses.AllowedIpAddressId
	) AS t
)


SELECT Contests.Id, Contests.Name, Contests.StartTime -- 3 Get next contest
FROM Contests
WHERE Contests.StartTime = (
	SELECT MIN(C.StartTime) AS [Start Time]
	FROM (
		SELECT *
		FROM Contests
		WHERE Contests.StartTime > GETDATE()
	) AS C
);

SELECT Users.UserName, Users.Email, 'User' as [Role] -- 4 Get all users
FROM Users, UserRoles
WHERE Users.Id = UserRoles.UserId AND UserRoles.RoleId = (SELECT Roles.Id FROM Roles WHERE Roles.Name = 'User');


SELECT t.UserId as [User ID], T.UserName, Submissions.Id as [Submission ID] -- 5 Find Lecturers who have made a submission
FROM Submissions, (
	SELECT *
	FROM Users, UserRoles
	WHERE Users.Id = UserRoles.UserId AND UserRoles.RoleId = (
		SELECT Roles.Id 
		FROM Roles 
		WHERE Roles.Name = 'Lecturer'
	)
) AS t
WHERE Submissions.UserId = t.Id;


-- JOIN

SELECT * 
FROM Courses LEFT JOIN Lessons
ON Lessons.CourseId = Courses.Id
WHERE Courses.Name = 'Algorithms';


SELECT p1.Name, p1.AllowedTimeInMilliseconds, p1.AllowedMemoryInMegaBytes
FROM Problems p1 left join Submissions s1
ON p1.Id=s1.ProblemId
WHERE p1.LessonId = 1;


SELECT e1.Id, e1.MemoryUsed, e1.TimeUsed
FROM ExecutedTests e1 right join Submissions s1
ON e1.SubmissionId=s1.Id
WHERE e1.ExecutionResultType='Correct';


SELECT s1.Id AS [Submission Id], p1.Name AS [Problem Name], s1.ActualPoints
FROM Submissions s1 JOIN problems p1
ON s1.ProblemId=p1.Id AND
      s1.UserId=1
ORDER BY s1.ActualPoints DESC;


SELECT s1.Id AS [Submission Id], p1.Name AS [Problem Name], s1.ActualPoints
FROM Submissions s1 JOIN problems p1
ON s1.ProblemId=p1.Id AND s1.UserId=1
WHERE s1.ActualPoints = (
	SELECT MAX(s1.ActualPoints) as m
	FROM Submissions s1 JOIN problems p1
	ON s1.ProblemId=p1.Id AND s1.UserId=1
);


-- Aggregation and grouping


SELECT Problems.Id, Problems.Name, p.[Average Points] -- 1
FROM Problems, (SELECT Problems.Id, AVG(Submissions.ActualPoints) as [Average Points]
	FROM Submissions, Problems
	WHERE Submissions.ProblemId = Problems.Id
	GROUP BY Problems.Id) AS p
WHERE p.Id = Problems.Id;


SELECT Lessons.Id, Lessons.Name, r.[Resources Count] -- 2
FROM Lessons ,(
	SELECT Resources.LessonId, COUNT(1) AS [Resources Count]
	FROM Resources
	GROUP BY Resources.LessonId) AS r
WHERE Lessons.Id = r.LessonId;


SELECT t.d as [Date], SUM(t.c) as [Submission Count] -- 3
FROM (
	SELECT CONVERT(date, Submissions.SubmisionDate) as d, COUNT(1) AS c
	FROM Submissions
	GROUP BY Submissions.SubmisionDate) AS t
GROUP BY t.d;


SELECT ExecutedTests.TestId, AVG(ExecutedTests.TimeUsed) AS [Average Exection Time (ms)] -- 4
FROM ExecutedTests
GROUP BY ExecutedTests.TestId;


SELECT ExecutedTests.TestId, COUNT(1) AS [Executed Tests Count] -- 5
FROM ExecutedTests
GROUP BY ExecutedTests.TestId;


SELECT ExecutedTests.TestId, ExecutedTests.ExecutionResultType, COUNT(ExecutedTests.ExecutionResultType) as [Count] -- 6
FROM ExecutedTests
GROUP BY ExecutedTests.TestId, ExecutedTests.ExecutionResultType
ORDER BY TestId;


SELECT Users.Id, Users.FirstName, t.[Submissions Count] -- 7
FROM Users, (
	SELECT Submissions.UserId, COUNT(1) AS [Submissions Count]
	FROM Submissions
	GROUP BY Submissions.UserId) AS t
WHERE Users.Id = t.UserId;


SELECT Tests.ProblemId, COUNT(1) AS [Tests Count] -- 8
FROM Tests
GROUP BY Tests.ProblemId
ORDER BY Tests.ProblemId;


SELECT ContestAllowedIpAddresses.ContestId, COUNT(1) AS [Count IP Addresses] -- 9
FROM ContestAllowedIpAddresses
GROUP BY ContestAllowedIpAddresses.ContestId;


SELECT t.ContestId, Contests.Name, t.[Count Users] -- 10
FROM Contests, (
	SELECT UserContests.ContestId, COUNT(1) AS [Count Users] 
	FROM UserContests
	GROUP BY UserContests.ContestId
) AS t
WHERE Contests.Id = t.ContestId
ORDER BY T.[Count Users] DESC;


