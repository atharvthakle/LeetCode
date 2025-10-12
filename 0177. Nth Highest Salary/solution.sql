CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    SELECT Salary
    FROM (
      SELECT DISTINCT Salary
      FROM Employee
    ) AS uniq
    WHERE (
      SELECT COUNT(DISTINCT Salary)
      FROM Employee AS e2
      WHERE e2.Salary > uniq.Salary
    ) = N - 1
    LIMIT 1
  );
END
