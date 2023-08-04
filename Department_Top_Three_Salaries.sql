SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM
    Employee e
JOIN
    Department d ON e.departmentId = d.id
WHERE
    (
        SELECT
            COUNT(DISTINCT salary)
        FROM
            Employee e2
        WHERE
            e2.salary >= e.salary AND e2.departmentId = e.departmentId
    ) <= 3
ORDER BY
    d.name, e.salary DESC;
