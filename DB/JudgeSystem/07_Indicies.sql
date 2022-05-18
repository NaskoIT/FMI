CREATE NONCLUSTERED INDEX IX_Users_UserName ON Users(UserName ASC)
GO

CREATE NONCLUSTERED INDEX IX_Lessons_CourseId ON Lessons(CourseId ASC)
GO

CREATE NONCLUSTERED INDEX IX_Problems_LessonId ON Problems(LessonId ASC)
GO

CREATE NONCLUSTERED INDEX IX_Resources_LessonId ON Resources(LessonId ASC)
GO

CREATE NONCLUSTERED INDEX IX_Submissions_ProblemId ON Submissions(ProblemId ASC)
GO

CREATE NONCLUSTERED INDEX IX_Submissions_UserId ON Submissions(UserId ASC)
GO

CREATE NONCLUSTERED INDEX IX_Tests_ProblemId ON Tests(ProblemId ASC)
GO

CREATE NONCLUSTERED INDEX IX_ExecutedTests_SubmissionId ON ExecutedTests(SubmissionId ASC)
GO

CREATE NONCLUSTERED INDEX IX_Contests_LessonId ON Contests(LessonId ASC)
GO

CREATE NONCLUSTERED INDEX IX_UserContests_UserId ON UserContests(UserId ASC)
GO

CREATE NONCLUSTERED INDEX IX_UserContests_ContestId ON UserContests(ContestId ASC)
GO

CREATE NONCLUSTERED INDEX IX_UserRoles_UserId ON UserRoles(UserId ASC)
GO

CREATE NONCLUSTERED INDEX IX_ContestAllowedIpAddresses_ContestId ON ContestAllowedIpAddresses(ContestId ASC)
GO
