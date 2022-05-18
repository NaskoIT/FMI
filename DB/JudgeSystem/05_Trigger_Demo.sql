-- Submissio delete trigger
SELECT * 
FROM Submissions;
GO

SELECT *
FROM ExecutedTests
WHERE SubmissionId = 6;
GO

SELECT *
FROM DeletedExecutedTests;
GO

SELECT *
FROM DeletedSubmissions;
GO

DELETE
FROM Submissions
WHERE Id = 6;
GO

-- Update tests demo
SELECT * FROM Tests
GO

UPDATE Tests SET Input = '5\n5' WHERE Id = 1
GO

SELECT * FROM TestVersions
GO
