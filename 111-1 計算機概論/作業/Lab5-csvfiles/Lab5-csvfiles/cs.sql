-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- 主機： 127.0.0.1
-- 產生時間： 2022 年 11 月 17 日 14:51
-- 伺服器版本： 10.4.19-MariaDB
-- PHP 版本： 8.0.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 資料庫： `cs`
--

-- --------------------------------------------------------

--
-- 資料表結構 `departments`
--

CREATE TABLE `departments` (
  `COL 1` varchar(13) DEFAULT NULL,
  `COL 2` varchar(20) DEFAULT NULL,
  `COL 3` varchar(10) DEFAULT NULL,
  `COL 4` varchar(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 傾印資料表的資料 `departments`
--

INSERT INTO `departments` (`COL 1`, `COL 2`, `COL 3`, `COL 4`) VALUES
('DEPARTMENT_ID', 'DEPARTMENT_NAME', 'MANAGER_ID', 'LOCATION_ID'),
('10', 'Administration', '200', '1700'),
('20', 'Marketing', '201', '1800'),
('30', 'Purchasing', '114', '1700'),
('40', 'Human Resources', '203', '2400'),
('50', 'Shipping', '121', '1500'),
('60', 'IT', '103', '1400'),
('70', 'Public Relations', '204', '2700'),
('80', 'Sales', '145', '2500'),
('90', 'Executive', '100', '1700'),
('100', 'Finance', '108', '1700'),
('110', 'Accounting', '205', '1700'),
('120', 'Treasury', ' - ', '1700'),
('130', 'Corporate Tax', ' - ', '1700'),
('140', 'Control And Credit', ' - ', '1700'),
('150', 'Shareholder Services', ' - ', '1700'),
('160', 'Benefits', ' - ', '1700'),
('170', 'Manufacturing', ' - ', '1700'),
('180', 'Construction', ' - ', '1700'),
('190', 'Contracting', ' - ', '1700'),
('200', 'Operations', ' - ', '1700'),
('210', 'IT Support', ' - ', '1700'),
('220', 'NOC', ' - ', '1700'),
('230', 'IT Helpdesk', ' - ', '1700'),
('240', 'Government Sales', ' - ', '1700'),
('250', 'Retail Sales', ' - ', '1700'),
('260', 'Recruiting', ' - ', '1700'),
('270', 'Payroll', ' - ', '1700');

-- --------------------------------------------------------

--
-- 資料表結構 `employees`
--

CREATE TABLE `employees` (
  `COL 1` varchar(11) DEFAULT NULL,
  `COL 2` varchar(11) DEFAULT NULL,
  `COL 3` varchar(11) DEFAULT NULL,
  `COL 4` varchar(8) DEFAULT NULL,
  `COL 5` varchar(12) DEFAULT NULL,
  `COL 6` varchar(9) DEFAULT NULL,
  `COL 7` varchar(10) DEFAULT NULL,
  `COL 8` varchar(6) DEFAULT NULL,
  `COL 9` varchar(14) DEFAULT NULL,
  `COL 10` varchar(10) DEFAULT NULL,
  `COL 11` varchar(13) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 傾印資料表的資料 `employees`
--

INSERT INTO `employees` (`COL 1`, `COL 2`, `COL 3`, `COL 4`, `COL 5`, `COL 6`, `COL 7`, `COL 8`, `COL 9`, `COL 10`, `COL 11`) VALUES
('EMPLOYEE_ID', 'FIRST_NAME', 'LAST_NAME', 'EMAIL', 'PHONE_NUMBER', 'HIRE_DATE', 'JOB_ID', 'SALARY', 'COMMISSION_PCT', 'MANAGER_ID', 'DEPARTMENT_ID'),
('198', 'Donald', 'OConnell', 'DOCONNEL', '650.507.9833', '21-JUN-07', 'SH_CLERK', '2600', ' - ', '124', '50'),
('199', 'Douglas', 'Grant', 'DGRANT', '650.507.9844', '13-JAN-08', 'SH_CLERK', '2600', ' - ', '124', '50'),
('200', 'Jennifer', 'Whalen', 'JWHALEN', '515.123.4444', '17-SEP-03', 'AD_ASST', '4400', ' - ', '101', '10'),
('201', 'Michael', 'Hartstein', 'MHARTSTE', '515.123.5555', '17-FEB-04', 'MK_MAN', '13000', ' - ', '100', '20'),
('202', 'Pat', 'Fay', 'PFAY', '603.123.6666', '17-AUG-05', 'MK_REP', '6000', ' - ', '201', '20'),
('203', 'Susan', 'Mavris', 'SMAVRIS', '515.123.7777', '07-JUN-02', 'HR_REP', '6500', ' - ', '101', '40'),
('204', 'Hermann', 'Baer', 'HBAER', '515.123.8888', '07-JUN-02', 'PR_REP', '10000', ' - ', '101', '70'),
('205', 'Shelley', 'Higgins', 'SHIGGINS', '515.123.8080', '07-JUN-02', 'AC_MGR', '12008', ' - ', '101', '110'),
('206', 'William', 'Gietz', 'WGIETZ', '515.123.8181', '07-JUN-02', 'AC_ACCOUNT', '8300', ' - ', '205', '110'),
('100', 'Steven', 'King', 'SKING', '515.123.4567', '17-JUN-03', 'AD_PRES', '24000', ' - ', ' - ', '90'),
('101', 'Neena', 'Kochhar', 'NKOCHHAR', '515.123.4568', '21-SEP-05', 'AD_VP', '17000', ' - ', '100', '90'),
('102', 'Lex', 'De Haan', 'LDEHAAN', '515.123.4569', '13-JAN-01', 'AD_VP', '17000', ' - ', '100', '90'),
('103', 'Alexander', 'Hunold', 'AHUNOLD', '590.423.4567', '03-JAN-06', 'IT_PROG', '9000', ' - ', '102', '60'),
('104', 'Bruce', 'Ernst', 'BERNST', '590.423.4568', '21-MAY-07', 'IT_PROG', '6000', ' - ', '103', '60'),
('105', 'David', 'Austin', 'DAUSTIN', '590.423.4569', '25-JUN-05', 'IT_PROG', '4800', ' - ', '103', '60'),
('106', 'Valli', 'Pataballa', 'VPATABAL', '590.423.4560', '05-FEB-06', 'IT_PROG', '4800', ' - ', '103', '60'),
('107', 'Diana', 'Lorentz', 'DLORENTZ', '590.423.5567', '07-FEB-07', 'IT_PROG', '4200', ' - ', '103', '60'),
('108', 'Nancy', 'Greenberg', 'NGREENBE', '515.124.4569', '17-AUG-02', 'FI_MGR', '12008', ' - ', '101', '100'),
('109', 'Daniel', 'Faviet', 'DFAVIET', '515.124.4169', '16-AUG-02', 'FI_ACCOUNT', '9000', ' - ', '108', '100'),
('110', 'John', 'Chen', 'JCHEN', '515.124.4269', '28-SEP-05', 'FI_ACCOUNT', '8200', ' - ', '108', '100'),
('111', 'Ismael', 'Sciarra', 'ISCIARRA', '515.124.4369', '30-SEP-05', 'FI_ACCOUNT', '7700', ' - ', '108', '100'),
('112', 'Jose Manuel', 'Urman', 'JMURMAN', '515.124.4469', '07-MAR-06', 'FI_ACCOUNT', '7800', ' - ', '108', '100'),
('113', 'Luis', 'Popp', 'LPOPP', '515.124.4567', '07-DEC-07', 'FI_ACCOUNT', '6900', ' - ', '108', '100'),
('114', 'Den', 'Raphaely', 'DRAPHEAL', '515.127.4561', '07-DEC-02', 'PU_MAN', '11000', ' - ', '100', '30'),
('115', 'Alexander', 'Khoo', 'AKHOO', '515.127.4562', '18-MAY-03', 'PU_CLERK', '3100', ' - ', '114', '30'),
('116', 'Shelli', 'Baida', 'SBAIDA', '515.127.4563', '24-DEC-05', 'PU_CLERK', '2900', ' - ', '114', '30'),
('117', 'Sigal', 'Tobias', 'STOBIAS', '515.127.4564', '24-JUL-05', 'PU_CLERK', '2800', ' - ', '114', '30'),
('118', 'Guy', 'Himuro', 'GHIMURO', '515.127.4565', '15-NOV-06', 'PU_CLERK', '2600', ' - ', '114', '30'),
('119', 'Karen', 'Colmenares', 'KCOLMENA', '515.127.4566', '10-AUG-07', 'PU_CLERK', '2500', ' - ', '114', '30'),
('120', 'Matthew', 'Weiss', 'MWEISS', '650.123.1234', '18-JUL-04', 'ST_MAN', '8000', ' - ', '100', '50'),
('121', 'Adam', 'Fripp', 'AFRIPP', '650.123.2234', '10-APR-05', 'ST_MAN', '8200', ' - ', '100', '50'),
('122', 'Payam', 'Kaufling', 'PKAUFLIN', '650.123.3234', '01-MAY-03', 'ST_MAN', '7900', ' - ', '100', '50'),
('123', 'Shanta', 'Vollman', 'SVOLLMAN', '650.123.4234', '10-OCT-05', 'ST_MAN', '6500', ' - ', '100', '50'),
('124', 'Kevin', 'Mourgos', 'KMOURGOS', '650.123.5234', '16-NOV-07', 'ST_MAN', '5800', ' - ', '100', '50'),
('125', 'Julia', 'Nayer', 'JNAYER', '650.124.1214', '16-JUL-05', 'ST_CLERK', '3200', ' - ', '120', '50'),
('126', 'Irene', 'Mikkilineni', 'IMIKKILI', '650.124.1224', '28-SEP-06', 'ST_CLERK', '2700', ' - ', '120', '50'),
('127', 'James', 'Landry', 'JLANDRY', '650.124.1334', '14-JAN-07', 'ST_CLERK', '2400', ' - ', '120', '50'),
('128', 'Steven', 'Markle', 'SMARKLE', '650.124.1434', '08-MAR-08', 'ST_CLERK', '2200', ' - ', '120', '50'),
('129', 'Laura', 'Bissot', 'LBISSOT', '650.124.5234', '20-AUG-05', 'ST_CLERK', '3300', ' - ', '121', '50'),
('130', 'Mozhe', 'Atkinson', 'MATKINSO', '650.124.6234', '30-OCT-05', 'ST_CLERK', '2800', ' - ', '121', '50'),
('131', 'James', 'Marlow', 'JAMRLOW', '650.124.7234', '16-FEB-05', 'ST_CLERK', '2500', ' - ', '121', '50'),
('132', 'TJ', 'Olson', 'TJOLSON', '650.124.8234', '10-APR-07', 'ST_CLERK', '2100', ' - ', '121', '50'),
('133', 'Jason', 'Mallin', 'JMALLIN', '650.127.1934', '14-JUN-04', 'ST_CLERK', '3300', ' - ', '122', '50'),
('134', 'Michael', 'Rogers', 'MROGERS', '650.127.1834', '26-AUG-06', 'ST_CLERK', '2900', ' - ', '122', '50'),
('135', 'Ki', 'Gee', 'KGEE', '650.127.1734', '12-DEC-07', 'ST_CLERK', '2400', ' - ', '122', '50'),
('136', 'Hazel', 'Philtanker', 'HPHILTAN', '650.127.1634', '06-FEB-08', 'ST_CLERK', '2200', ' - ', '122', '50'),
('137', 'Renske', 'Ladwig', 'RLADWIG', '650.121.1234', '14-JUL-03', 'ST_CLERK', '3600', ' - ', '123', '50'),
('138', 'Stephen', 'Stiles', 'SSTILES', '650.121.2034', '26-OCT-05', 'ST_CLERK', '3200', ' - ', '123', '50'),
('139', 'John', 'Seo', 'JSEO', '650.121.2019', '12-FEB-06', 'ST_CLERK', '2700', ' - ', '123', '50'),
('140', 'Joshua', 'Patel', 'JPATEL', '650.121.1834', '06-APR-06', 'ST_CLERK', '2500', ' - ', '123', '50');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
