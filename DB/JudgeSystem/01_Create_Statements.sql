USE [master]
GO

-- 1. Create database
CREATE DATABASE [JudgeSystemDB]
GO

-- 2. Switch to the our database
USE [JudgeSystemDB]
GO

CREATE TABLE Roles (
	Id INT PRIMARY KEY IDENTITY,
	[Name] NVARCHAR(256) NOT NULL UNIQUE
)
GO

CREATE TABLE Users (
	Id INT PRIMARY KEY IDENTITY NOT NULL,
	UserName NVARCHAR(256) NOT NULL UNIQUE,
	Email NVARCHAR(256) NOT NULL UNIQUE,
	EmailConfirmed BIT NOT NULL,
	PasswordHash NVARCHAR(500) NOT NULL,
	PhoneNumber NVARCHAR(20) NULL,
	CreatedOn DATETIME2(7) NOT NULL,
	ModifiedOn DATETIME2(7) NULL,
	FirstName NVARCHAR(100) NULL,
	LastName NVARCHAR(100) NULL,
)
GO

ALTER TABLE Users ADD DEFAULT GETDATE() FOR CreatedOn
GO

CREATE TABLE UserRoles (
	UserId INT FOREIGN KEY REFERENCES Users(Id) NOT NULL,
	RoleId INT FOREIGN KEY REFERENCES Roles(Id) NOT NULL
)
GO

ALTER TABLE UserRoles ADD CONSTRAINT PK_UserId_RolesId_UserRoles PRIMARY KEY (UserId, RoleId)
GO

CREATE TABLE Courses (
	Id INT PRIMARY KEY IDENTITY NOT NULL,
	[Name] NVARCHAR(100) NOT NULL,
	OrderBy INT NOT NULL
)
GO

CREATE TABLE Lessons (
	Id INT PRIMARY KEY IDENTITY NOT NULL,
	[Name] NVARCHAR(100) NOT NULL,
	CourseId INT FOREIGN KEY REFERENCES Courses(Id) NOT NULL,
	OrderBy INT NOT NULL,
)
GO

CREATE TABLE Problems (
	Id INT PRIMARY KEY IDENTITY NOT NULL,
	Name NVARCHAR(100) NOT NULL,
	IsExtraTask BIT NOT NULL,
	MaxPoints INT NOT NULL,
	LessonId INT FOREIGN KEY REFERENCES Lessons(Id) NOT NULL,
	AllowedMemoryInMegaBytes FLOAT NOT NULL,
	AllowedTimeInMilliseconds INT NOT NULL,
	TimeIntervalBetweenSubmissionInSeconds INT NOT NULL,
	OrderBy INT NOT NULL
)
GO

CREATE TABLE Resources (
	Id INT PRIMARY KEY IDENTITY NOT NULL,
	[Name] NVARCHAR(100) NOT NULL,
	FilePath NVARCHAR(256) NOT NULL,
	LessonId INT FOREIGN KEY REFERENCES Lessons(Id) NOT NULL,
	CreatedOn DATETIME2(7) NOT NULL,
	OrderBy INT NOT NULL,
)
GO

ALTER TABLE Resources ADD DEFAULT GETDATE() FOR CreatedOn
GO

CREATE TABLE Submissions (
	Id INT PRIMARY KEY IDENTITY NOT NULL,
	[Code] VARBINARY(MAX) NOT NULL,
	ProblemId INT FOREIGN KEY REFERENCES Problems(Id) NOT NULL,
	SubmisionDate DATETIME2(7) NOT NULL,
	UserId INT FOREIGN KEY REFERENCES Users(Id) NULL,
	CompilationErrors VARBINARY(MAX) NULL,
	ActualPoints INT NOT NULL
)
GO

CREATE TABLE DeletedSubmissions (
	Id INT PRIMARY KEY NOT NULL,
	[Code] VARBINARY(MAX) NOT NULL,
	ProblemId INT FOREIGN KEY REFERENCES Problems(Id) NOT NULL,
	SubmisionDate DATETIME2(7) NOT NULL,
	UserId INT FOREIGN KEY REFERENCES Users(Id) NULL,
	CompilationErrors VARBINARY(MAX) NULL,
	ActualPoints INT NOT NULL
)
GO

CREATE TRIGGER tr_DeleteSubmission ON Submissions 
FOR DELETE
AS
	INSERT INTO DeletedSubmissions(Id, [Code], ProblemId, SubmisionDate, UserId, CompilationErrors, ActualPoints)
	SELECT Id, [Code], ProblemId, SubmisionDate, UserId, CompilationErrors, ActualPoints FROM deleted 
GO


CREATE TABLE Tests (
	Id INT PRIMARY KEY IDENTITY NOT NULL,
	ProblemId INT FOREIGN KEY REFERENCES Problems(Id),
	Input NVARCHAR(max) NULL,
	ExpectedOutput NVARCHAR(max) NOT NULL,
	IsTrialTest BIT NOT NULL,
	OrderBy INT NOT NULL,
)
GO

CREATE TABLE TestVersions (
	Id INT PRIMARY KEY IDENTITY NOT NULL,
	TestId INT,
	ProblemId INT FOREIGN KEY REFERENCES Problems(Id),
	Input NVARCHAR(max) NULL,
	ExpectedOutput NVARCHAR(max) NOT NULL,
	IsTrialTest BIT NOT NULL,
	OrderBy INT NOT NULL,
	UpdateOn DATETIME2(7) NOT NULL
)
GO

CREATE TRIGGER TR_TestUpdated ON Tests FOR UPDATE
AS
INSERT INTO TestVersions(TestId, ProblemId, Input, ExpectedOutput, IsTrialTest, OrderBy, UpdateOn)
SELECT p.Id, p.ProblemId, p.Input, p.ExpectedOutput, p.IsTrialTest, p.OrderBy, GETDATE()
FROM deleted as p
GO

CREATE TABLE ExecutedTests (
	Id INT PRIMARY KEY IDENTITY NOT NULL,
	CreatedOn DATETIME2(7) NOT NULL,
	IsCorrect BIT NOT NULL,
	[Output] NVARCHAR(max) NULL,
	TestId INT FOREIGN KEY REFERENCES Tests(Id) NOT NULL,
	SubmissionId INT NOT NULL,
	Error NVARCHAR(max) NULL,
	ExecutionResultType NVARCHAR(50) NOT NULL, -- Correct, Run Time Error, Compilaton Error, Wrong answer, Exceeded Time
	MemoryUsed FLOAT NOT NULL,
	TimeUsed FLOAT NOT NULL,
)
GO

ALTER TABLE ExecutedTests ADD FOREIGN KEY (SubmissionId) REFERENCES Submissions(Id) ON DELETE CASCADE
GO

CREATE TABLE DeletedExecutedTests (
	Id INT PRIMARY KEY NOT NULL,
	CreatedOn DATETIME2(7) NOT NULL,
	IsCorrect BIT NOT NULL,
	[Output] NVARCHAR(max) NULL,
	TestId INT FOREIGN KEY REFERENCES Tests(Id) NOT NULL,
	SubmissionId INT NOT NULL,
	Error NVARCHAR(max) NULL,
	ExecutionResultType NVARCHAR(50) NOT NULL, -- Correct, Run Time Error, Compilaton Error, Wrong answer, Exceeded Time
	MemoryUsed FLOAT NOT NULL,
	TimeUsed FLOAT NOT NULL,
)
GO

CREATE TRIGGER tr_DeleteExecutedTest ON ExecutedTests 
FOR DELETE
AS
	INSERT INTO DeletedExecutedTests(Id, CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed)
	SELECT Id, CreatedOn, IsCorrect, [Output], TestId, SubmissionId, Error, ExecutionResultType, MemoryUsed, TimeUsed FROM deleted
GO

ALTER TABLE ExecutedTests ADD DEFAULT GETDATE() FOR CreatedOn
GO

CREATE TABLE Contests (
	Id INT PRIMARY KEY IDENTITY NOT NULL,
	StartTime DATETIME2(7) NOT NULL,
	EndTime DATETIME2(7) NOT NULL,
	LessonId INT FOREIGN KEY REFERENCES Lessons(Id) NOT NULL,
	[Name] NVARCHAR(50) NOT NULL,
	PasswordHash NVARCHAR(500),
)
GO

CREATE TABLE UserContests (
	UserId INT FOREIGN KEY REFERENCES Users(Id) NOT NULL,
	ContestId INT FOREIGN KEY REFERENCES Contests(Id) NOT NULL,
)
GO

ALTER TABLE UserContests 
ADD CONSTRAINT PK_UserId_ContestId_UserContests PRIMARY KEY(UserId, ContestId)
GO

CREATE TABLE AllowedIpAddresses (
	Id INT PRIMARY KEY IDENTITY NOT NULL,
	[Value] NVARCHAR(500) NOT NULL,
	[DisplayName] NVARCHAR(300) NOT NULL
)
GO

CREATE TABLE ContestAllowedIpAddresses (
	ContestId INT FOREIGN KEY REFERENCES Contests(Id) NOT NULL,
	AllowedIpAddressId INT FOREIGN KEY REFERENCES AllowedIpAddresses(Id) NOT NULL,
)
GO

ALTER TABLE ContestAllowedIpAddresses 
ADD CONSTRAINT PK_AllowedIpAddressId_ContestId_ContestAllowedIpAddresses PRIMARY KEY(AllowedIpAddressId, ContestId)
GO