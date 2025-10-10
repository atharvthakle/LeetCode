# Problem

## SQL Schema

    Create table If Not Exists Employee (empId int, name varchar(255), supervisor int, salary int)
    Create table If Not Exists Bonus (empId int, bonus int)
    Truncate table Employee
    insert into Employee (empId, name, supervisor, salary) values ('3', 'Brad', NULL, '4000')
    insert into Employee (empId, name, supervisor, salary) values ('1', 'John', '3', '1000')
    insert into Employee (empId, name, supervisor, salary) values ('2', 'Dan', '3', '2000')
    insert into Employee (empId, name, supervisor, salary) values ('4', 'Thomas', '3', '4000')
    Truncate table Bonus
    insert into Bonus (empId, bonus) values ('2', '500')
    insert into Bonus (empId, bonus) values ('4', '2000')

## Pandas Schema

    data = [[3, 'Brad', None, 4000], [1, 'John', 3, 1000], [2, 'Dan', 3, 2000], [4, 'Thomas', 3, 4000]]
    employee = pd.DataFrame(data, columns=['empId', 'name', 'supervisor', 'salary']).astype({'empId':'Int64', 'name':'object', 'supervisor':'Int64', 'salary':'Int64'})
    data = [[2, 500], [4, 2000]]
    bonus = pd.DataFrame(data, columns=['empId', 'bonus']).astype({'empId':'Int64', 'bonus':'Int64'})

Table: Employee

    +-------------+---------+
    | Column Name | Type    |
    +-------------+---------+
    | empId       | int     |
    | name        | varchar |
    | supervisor  | int     |
    | salary      | int     |
    +-------------+---------+

empId is the column with unique values for this table.

Each row of this table indicates the name and the ID of an employee in addition to their salary and the id of their manager.

Table: Bonus

Input: 

Employee table:

    +-------+--------+------------+--------+
    | empId | name   | supervisor | salary |
    +-------+--------+------------+--------+
    | 3     | Brad   | null       | 4000   |
    | 1     | John   | 3          | 1000   |
    | 2     | Dan    | 3          | 2000   |
    | 4     | Thomas | 3          | 4000   |
    +-------+--------+------------+--------+

Bonus table:

    +-------+-------+
    | empId | bonus |
    +-------+-------+
    | 2     | 500   |
    | 4     | 2000  |
    +-------+-------+

Output: 

    +------+-------+
    | name | bonus |
    +------+-------+
    | Brad | null  |
    | John | null  |
    | Dan  | 500   |
    +------+-------+

addressId = 1 contains information about the address of personId = 2.
