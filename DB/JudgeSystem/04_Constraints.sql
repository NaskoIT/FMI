-- PRIMARY KEY 
-- FOREIGN KEY
-- IDENTITY

ALTER TABLE Users ADD DEFAULT GETDATE() FOR CreatedOn
GO

ALTER TABLE Users ADD CONSTRAINT UQ_Users_UserName UNIQUE(UserName)
GO

ALTER TABLE ExecutedTests ADD CONSTRAINT Check_Execution_Result_Type CHECK(ExecutionResultType IN ('Correct', 'Run Time Error', 'Compilaton Error', 'Wrong answer', 'Exceeded Time'))
GO
