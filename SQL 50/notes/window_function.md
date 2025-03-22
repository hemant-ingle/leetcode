# Window Function

## Create Table (sales):
```sql
CREATE TABLE sales (id SERIAL PRIMARY KEY, sales_date DATE, sales_amount DECIMAL, employee_id INT, region VARCHAR(50));
```

## Insert Data:
```sql
INSERT INTO sales (sales_date, sales_amount, employee_id, region) VALUES 
('2024-01-01', 100, 1, 'North'), 
('2024-01-05', 150, 2, 'South'),
('2024-02-01', 200, 1, 'North'),
('2024-02-10', 250, 3, 'West'),
('2024-03-01', 300, 2, 'South'),
('2024-03-10', 350, 3, 'West'),
('2024-04-01', 400, 1, 'North'),
('2024-04-05', 450, 2, 'South'),
('2024-05-01', 500, 3, 'West');
```

## Table Data (select * from sales):
| id <br> [PK] integer | sales_date <br> date | sales_amount <br> numeric | employee_id <br> integer | region <br> character varying (50) |
| -------------------- | -------------------- | ------------------------- | ------------------------ | ---------------------------------- |
| 1 | 2024-01-01 | 100 | 1 | North |
| 2 | 2024-01-05 | 150 | 2 | South |
| 3 | 2024-02-01 | 200 | 1 | North |
| 4 | 2024-02-10 | 250 | 3 | West |
| 5 | 2024-03-01 | 300 | 2 | South |
| 6 | 2024-03-10 | 350 | 3 | West |
| 7 | 2024-04-01 | 400 | 1 | North |
| 8 | 2024-04-05 | 450 | 2 | South |
| 9 | 2024-05-01 | 500 | 3 | West |

## Different scenarios of window function:

### Scenario 1:
```sql
select *, sum(sales_amount) over (partition by extract(month from sales_date) order by extract(day from sales_date) asc) 
from sales data;
```
| id <br> [PK] integer | sales_date <br> date | sales_amount <br> numeric | employee_id <br> integer | region <br> character varying (50) | sum <br> numeric |
| -------------------- | -------------------- | ------------------------- | ------------------------ | ---------------------------------- | ---------------- |
| 1 | 2024-01-01 | 100 | 1 | North | 100 |
| 2 | 2024-01-05 | 150 | 2 | South | 250 |
| 3 | 2024-02-01 | 200 | 1 | North | 200 |
| 4 | 2024-02-10 | 250 | 3 | West | 450 |
| 5 | 2024-03-01 | 300 | 2 | South | 300 |
| 6 | 2024-03-10 | 350 | 3 | West | 650 |
| 7 | 2024-04-01 | 400 | 1 | North | 400 |
| 8 | 2024-04-05 | 450 | 2 | South | 850 |
| 9 | 2024-05-01 | 500 | 3 | West | 500 |

### Scenario 2:
```sql
select *, sum(sales_amount) over (partition by extract(month from sales_date) order by extract(day from sales_date) desc) 
from sales data;
```
| id <br> [PK] integer | sales_date <br> date | sales_amount <br> numeric | employee_id <br> integer | region <br> character varying (50) | sum <br> numeric |
| -------------------- | -------------------- | ------------------------- | ------------------------ | ---------------------------------- | ---------------- |
| 2 | 2024-01-05 | 150 | 2 | South | 150 |
| 1 | 2024-01-01 | 100 | 1 | North | 250 |
| 4 | 2024-02-10 | 250 | 3 | West | 250 |
| 3 | 2024-02-01 | 200 | 1 | North | 450 |
| 6 | 2024-03-10 | 350 | 3 | West | 350 |
| 5 | 2024-03-01 | 300 | 2 | South | 650 |
| 8 | 2024-04-05 | 450 | 2 | South | 450 |
| 7 | 2024-04-01 | 400 | 1 | North | 850 |
| 9 | 2024-05-01 | 500 | 3 | West | 500 |

### Scenario 3:
```sql
select *, sum(sales_amount) over (partition by extract(month from sales_date)) from sales;
```
| id <br> [PK] integer | sales_date <br> date | sales_amount <br> numeric | employee_id <br> integer | region <br> character varying (50) | sum <br> numeric |
| -------------------- | -------------------- | ------------------------- | ------------------------ | ---------------------------------- | ---------------- |
| 1 | 2024-01-01 | 100 | 1 | North | 250 |
| 2 | 2024-01-05 | 150 | 2 | South | 250 |
| 3 | 2024-02-01 | 200 | 1 | North | 450 |
| 4 | 2024-02-10 | 250 | 3 | West | 450 |
| 5 | 2024-03-01 | 300 | 2 | South | 650 |
| 6 | 2024-03-10 | 350 | 3 | West | 650 |
| 7 | 2024-04-01 | 400 | 1 | North | 850 |
| 8 | 2024-04-05 | 450 | 2 | South | 850 |
| 9 | 2024-05-01 | 500 | 3 | West | 500 |

### Scenario 4:
```sql
select *, sum(sales_amount) over (order by extract(day from sales_date) asc) from sales;
```
| id <br> [PK] integer | sales_date <br> date | sales_amount <br> numeric | employee_id <br> integer | region <br> character varying (50) | sum <br> numeric |
| -------------------- | -------------------- | ------------------------- | ------------------------ | ---------------------------------- | ---------------- |
| 9 | 2024-05-01 | 500 | 3 | West | 1500 |
| 3 | 2024-02-01 | 200 | 1 | North | 1500 |
| 5 | 2024-03-01 | 300 | 2 | South | 1500 |
| 7 | 2024-04-01 | 400 | 1 | North | 1500 |
| 1 | 2024-01-01 | 100 | 1 | North | 1500 |
| 2 | 2024-01-05 | 150 | 2 | South | 2100 |
| 8 | 2024-04-05 | 450 | 2 | South | 2100 |
| 6 | 2024-03-10 | 350 | 3 | West | 2700 |
| 4 | 2024-02-10 | 250 | 3 | West | 2700 |

### Scenario 5:
```sql
select *, sum(sales_amount) over (order by extract(day from sales_date) desc) from sales;
```
| id <br> __[PK] integer__ | sales_date <br> date | sales_amount <br> numeric | employee_id <br> integer | region <br> character varying (50) | sum <br> numeric |
| -------------------- | -------------------- | ------------------------- | ------------------------ | ---------------------------------- | ---------------- |
| 6 | 2024-03-10 | 350 | 3 | West | 600 |
| 4 | 2024-02-10 | 250 | 3 | West | 600 |
| 8 | 2024-04-05 | 450 | 2 | South | 1200 |
| 2 | 2024-01-05 | 150 | 2 | South | 1200 |
| 1 | 2024-01-01 | 100 | 1 | North | 2700 |
| 9 | 2024-05-01 | 500 | 3 | West | 2700 |
| 3 | 2024-02-01 | 200 | 1 | North | 2700 |
| 5 | 2024-03-01 | 300 | 2 | South | 2700 |
| 7 | 2024-04-01 | 400 | 1 | North | 2700 |

### Scenario 6:
```sql
select *, sum(sales_amount) over () from sales;
```
| id <br> [PK] integer | sales_date <br> date | sales_amount <br> numeric | employee_id <br> integer | region <br> character varying (50) | sum <br> numeric |
| -------------------- | -------------------- | ------------------------- | ------------------------ | ---------------------------------- | ---------------- |
| 1 | 2024-01-01 | 100 | 1 | North | 2700 |
| 2 | 2024-01-05 | 150 | 2 | South | 2700 |
| 3 | 2024-02-01 | 200 | 1 | North | 2700 |
| 4 | 2024-02-10 | 250 | 3 | West | 2700 |
| 5 | 2024-03-01 | 300 | 2 | South | 2700 |
| 6 | 2024-03-10 | 350 | 3 | West | 2700 |
| 7 | 2024-04-01 | 400 | 1 | North | 2700 |
| 8 | 2024-04-05 | 450 | 2 | South | 2700 |
| 9 | 2024-05-01 | 500 | 3 | West | 2700 |