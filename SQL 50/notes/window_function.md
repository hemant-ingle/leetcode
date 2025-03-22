# Window Function

### Create Table (sales):
```sql
CREATE TABLE sales (id SERIAL PRIMARY KEY, sales_date DATE, sales_amount DECIMAL, employee_id INT, region VARCHAR(50));
```

### Insert Data:
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