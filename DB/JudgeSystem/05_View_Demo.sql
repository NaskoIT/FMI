CREATE VIEW ActiveUsers AS
SELECT UserName, FirstName, LastName from Users
WHERE Users.EmailConfirmed = 1
GO

SELECT * FROM ActiveUsers
