# Bookstore

Specification Anaylsis:
First off we decided to make three main modules. Inventory, Cashier, and Reports. With Inventory being the base class
both Cashier and Reports would inherit from Inventory. An instance of Inventory would have all the book's attributes
from ISBN,Title,Author,Publisher,Date Added,Wholesale Value, Retail Value,and Quantity. This would help us when we need
the book information in Cashier and Reports.

For Inventory:
Inventory should contain all common variable, getter and setter every book. It will be inherited by cashier and report module so
its necessary to be full fledged class. It also has to be future-proof in case of any major changes to child class. Counting
duplicated book and quantity of the books is an important factor of this class. Most of the child class will be dealing with
the array created with this class, organizing and book checking has to be quite accurate or it won't be inherited properly.
Exception handling is also implemented to prevent data from being invalid or inaccurate as it will causes quite a few issues
to child class.

For Cashier:
With cashier we wanted to make the user interactivity as simple as possible. So we limited the user to chooses numbers to pick
their book. They are listed the whole inventory with their quantity. The user would choose the number corresponding to it. Once
in cart it will reduce the quantity by one. The user would check out using '~" to exit to checkout. Once in checkout they are 
displayed their books and the prices. After that they are presented their total price. The console diplayes price before and 
after tax. After checkout it would send the user back to the main menu.

For Report Module:
The report module is centered around a menu where there are 7 options.
The user chooses what option and is sent to a function accordingly. Only three of the functions are sorted.
We used the Selection Sort algorithim for all three. They varied since we were comparing dates, quantites, and 
costs. For the list by date it was tricky to compare dates in this format: Month Day, Year. So we made a date class
that would help us compare dates. First we compare the Year.If they are equal then compare months,If they are equal then
compare days. As for the other 3 options they were simple enough. Inventory List function just displayed all information of books.
Inventory Wholesale List function displayed the wholesale value of each book and had a total at the end that was displayed.
Inventory Retail List function displayed the retail value of each book and had a total at the end that was displayed.
Once the user inputs 7 they are sent back to the main menu.



