SELECT * 
FROM Submissions;

SELECT *
FROM ExecutedTests
WHERE SubmissionId = 6;

SELECT *
FROM DeletedExecutedTests;

SELECT *
FROM DeletedSubmissions;

DELETE
FROM Submissions
WHERE Id = 6;
