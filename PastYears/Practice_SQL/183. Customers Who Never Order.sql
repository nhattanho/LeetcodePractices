select Customers.name as 'Customers'
from Customers
where Customers.id not in
(
    select Orders.customerid from Orders
);


select Customers.name as 'Customers'
from Customers
left join Orders on Customers.id = Orders.customerId
where Orders.customerId is null;
