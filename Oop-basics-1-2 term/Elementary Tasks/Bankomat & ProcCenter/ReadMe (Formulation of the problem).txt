Rus:
Разработать классы Bankomat и ProcCenter.
Класс Bankomat должен имитировать работу банкомата по приему и выдаче наличных денежных средств (в рублях). 
Класс должен поддерживать работу с купюрами в 100, 200, 500, 1000, 2000, 5000 рублей. 
Выдаваемая или принимаемая за одну операцию сумма ограничена 40 купюрами (независимо от их достоинства).
 Купюры каждого достоинства хранятся в отдельной кассете. Емкость каждой кассеты – 2000 тысяч купюр. 
Считать, что начальная загрузка банкомата составляет 80% для каждой кассеты. 
Считать, что клиент банка идентифицируется по номеру пластиковой карты (для упрощения – номер карты от «0001» до «9999»).
База клиентов хранится в классе ProcCenter. Номера выданных клиентам карт могут идти не подряд. 
Считать, что информация о клиенте состоит из номера карты, ФИО владельца, суммы на счету, (для упрощения – без копеек),
 PIN-кода (последовательность из 4-х цифр, каждая от 0 до 9).
Класс Bankomat должен предоставлять следующие операции: 1) принять карту клиента, 2) найти клиента по номеру карты, 
3) проверить PIN-код, 4) распечатать состояние счета клиента, 5) выдать клиенту наличные (списав выданную сумму со счета),
 6) принять от клиента наличные (зачислив полученную сумму на счет), 7) заблокировать карту клиента,
 если до ее возврата клиенту три раза подряд набран неверный PIN-код, 8) вернуть карту клиенту.
Все операции должны сопровождаться необходимыми проверками на указанные выше ограничения.
Класс ProcCenter должен использоваться для поддержки работы класса Bankomat и может быть разработан в минимально-необходимом варианте.
Eng: (Google Translator)
Made Bankomat and ProcCenter classes.
The Bankomat class should imitate the operation of an ATM to receive and issue cash (in rubles).
The class must support work with bills of 100, 200, 500, 1000, 2000, 5000 rubles.
The amount issued or accepted in one operation is limited to 40 bills (regardless of their value).
 Banknotes of each denomination are stored in a separate cassette. The capacity of each cartridge is 2,000 thousand notes.
Assume that the initial loading of the ATM is 80% for each cassette.
Assume that the bank's customer is identified by the number of the plastic card (for simplicity, the card number is from “0001” to “9999”).
The customer base is stored in the ProcCenter class. The numbers of cards issued to customers may not go in a row.
Consider that customer information consists of a card number, name of the owner, amount on the account, (for simplification - without cents),
 PIN code (a sequence of 4 digits, each from 0 to 9).
The Bankomat class must provide the following operations: 1) accept a customer card, 2) find a customer by card number,
3) check the PIN code, 4) print out the status of the client’s account, 5) give out cash to the client (having written off the issued amount from the account),
 6) accept cash from the client (by crediting the amount received to the account), 7) block the client’s card,
 if before returning it to the customer three times in a row the wrong PIN-code is dialed, 8) return the card to the customer.
All operations must be accompanied by the necessary checks for the above restrictions.
The ProcCenter class must be used to support the operation of the Bankomat class and can be developed in the minimum necessary form.