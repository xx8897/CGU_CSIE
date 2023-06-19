-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- 主機： 127.0.0.1
-- 產生時間： 2021 年 04 月 19 日 08:16
-- 伺服器版本： 10.4.18-MariaDB
-- PHP 版本： 8.0.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 資料庫： `university_database`
--

-- --------------------------------------------------------

--
-- 資料表結構 `course`
--

CREATE TABLE `course` (
  `CourseNo` char(6) NOT NULL,
  `CrsDesc` varchar(250) NOT NULL,
  `CrsUnits` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- 資料表的關聯 `course`:
--

--
-- 傾印資料表的資料 `course`
--

INSERT INTO `course` (`CourseNo`, `CrsDesc`, `CrsUnits`) VALUES
('FIN300', 'FUNDAMENTALS OF FINANCE', 4),
('FIN450', 'PRINCIPLES OF INVESTMENTS', 4),
('FIN480', 'CORPORATE FINANCE', 4),
('IS320', 'FUNDAMENTALS OF BUSINESS PROGRAMMING', 4),
('IS460', 'SYSTEMS ANALYSIS', 4),
('IS470', 'BUSINESS DATA COMMUNICATIONS', 4),
('IS480', 'FUNDAMENTALS OF DATABASE MANAGEMENT', 4);

-- --------------------------------------------------------

--
-- 資料表結構 `enrollment`
--

CREATE TABLE `enrollment` (
  `OfferNo` int(11) NOT NULL,
  `StdSSN` char(11) NOT NULL,
  `EnrGrade` decimal(3,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- 資料表的關聯 `enrollment`:
--   `OfferNo`
--       `offering` -> `OfferNo`
--   `StdSSN`
--       `student` -> `StdSSN`
--

--
-- 傾印資料表的資料 `enrollment`
--

INSERT INTO `enrollment` (`OfferNo`, `StdSSN`, `EnrGrade`) VALUES
(1234, '123-45-6789', '3.30'),
(1234, '234-56-7890', '3.50'),
(1234, '345-67-8901', '3.20'),
(1234, '456-78-9012', '3.10'),
(1234, '567-89-0123', '3.80'),
(1234, '678-90-1234', '3.40'),
(4321, '123-45-6789', '3.50'),
(4321, '124-56-7890', '3.20'),
(4321, '789-01-2345', '3.50'),
(4321, '876-54-3210', '3.10'),
(4321, '890-12-3456', '3.40'),
(4321, '901-23-4567', '3.10'),
(5555, '123-45-6789', '3.20'),
(5555, '124-56-7890', '2.70'),
(5678, '123-45-6789', '3.20'),
(5678, '234-56-7890', '2.80'),
(5678, '345-67-8901', '3.30'),
(5678, '456-78-9012', '3.40'),
(5678, '567-89-0123', '2.60'),
(5679, '123-45-6789', '2.00'),
(5679, '124-56-7890', '3.70'),
(5679, '678-90-1234', '3.30'),
(5679, '789-01-2345', '3.80'),
(5679, '890-12-3456', '2.90'),
(5679, '901-23-4567', '3.10'),
(6666, '234-56-7890', '3.10'),
(6666, '567-89-0123', '3.60'),
(7777, '876-54-3210', '3.40'),
(7777, '890-12-3456', '3.70'),
(7777, '901-23-4567', '3.40'),
(9876, '124-56-7890', '3.50'),
(9876, '234-56-7890', '3.20'),
(9876, '345-67-8901', '3.20'),
(9876, '456-78-9012', '3.40'),
(9876, '567-89-0123', '2.60'),
(9876, '678-90-1234', '3.30'),
(9876, '901-23-4567', '4.00');

-- --------------------------------------------------------

--
-- 資料表結構 `faculty`
--

CREATE TABLE `faculty` (
  `FacSSN` char(11) NOT NULL,
  `FacFirstName` varchar(50) NOT NULL,
  `FacLastName` varchar(50) NOT NULL,
  `FacCity` varchar(50) NOT NULL,
  `FacState` char(2) NOT NULL,
  `FacZipCode` char(10) NOT NULL,
  `FacHireDate` date DEFAULT NULL,
  `FacDept` char(6) DEFAULT NULL,
  `FacRank` char(4) DEFAULT NULL,
  `FacSalary` decimal(10,2) DEFAULT NULL,
  `FacSupervisor` char(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- 資料表的關聯 `faculty`:
--   `FacSupervisor`
--       `faculty` -> `FacSSN`
--

--
-- 傾印資料表的資料 `faculty`
--

INSERT INTO `faculty` (`FacSSN`, `FacFirstName`, `FacLastName`, `FacCity`, `FacState`, `FacZipCode`, `FacHireDate`, `FacDept`, `FacRank`, `FacSalary`, `FacSupervisor`) VALUES
('098-76-5432', 'LEONARD', 'VINCE', 'SEATTLE', 'WA', '98111-9921', '1995-04-10', 'MS', 'ASST', '35000.00', '654-32-1098'),
('543-21-0987', 'VICTORIA', 'EMMANUEL', 'BOTHELL', 'WA', '98011-2242', '1996-04-15', 'MS', 'PROF', '120000.00', NULL),
('654-32-1098', 'LEONARD', 'FIBON', 'SEATTLE', 'WA', '98121-0094', '1994-05-01', 'MS', 'ASSC', '70000.00', '543-21-0987'),
('765-43-2109', 'NICKI', 'MACON', 'BELLEVUE', 'WA', '98015-9945', '1997-04-11', 'FIN', 'PROF', '65000.00', NULL),
('876-54-3210', 'CRISTOPHER', 'COLAN', 'SEATTLE', 'WA', '98114-1332', '1999-03-01', 'MS', 'ASST', '40000.00', '654-32-1098'),
('987-65-4321', 'JULIA', 'MILLS', 'SEATTLE', 'WA', '98114-9954', '2000-03-15', 'FIN', 'ASSC', '75000.00', '765-43-2109');

-- --------------------------------------------------------

--
-- 資料表結構 `offering`
--

CREATE TABLE `offering` (
  `OfferNo` int(11) NOT NULL,
  `CourseNo` char(6) NOT NULL,
  `OffLocation` varchar(50) NOT NULL,
  `OffDays` char(6) NOT NULL,
  `OffTerm` char(6) NOT NULL,
  `OffYear` int(11) NOT NULL,
  `FacSSN` char(11) DEFAULT NULL,
  `OffTime` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- 資料表的關聯 `offering`:
--   `CourseNo`
--       `course` -> `CourseNo`
--   `FacSSN`
--       `faculty` -> `FacSSN`
--

--
-- 傾印資料表的資料 `offering`
--

INSERT INTO `offering` (`OfferNo`, `CourseNo`, `OffLocation`, `OffDays`, `OffTerm`, `OffYear`, `FacSSN`, `OffTime`) VALUES
(1111, 'IS320', 'BLM302', 'MW', 'SUMMER', 2006, NULL, '10:30:00'),
(1234, 'IS320', 'BLM302', 'MW', 'FALL', 2005, '098-76-5432', '10:30:00'),
(2222, 'IS460', 'BLM412', 'TTH', 'SUMMER', 2005, NULL, '13:30:00'),
(3333, 'IS320', 'BLM214', 'MW', 'SPRING', 2006, '098-76-5432', '08:30:00'),
(4321, 'IS320', 'BLM214', 'TTH', 'FALL', 2005, '098-76-5432', '15:30:00'),
(4444, 'IS320', 'BLM302', 'TTH', 'WINTER', 2006, '543-21-0987', '15:30:00'),
(5555, 'FIN300', 'BLM207', 'MW', 'WINTER', 2006, '765-43-2109', '08:30:00'),
(5678, 'IS480', 'BLM302', 'MW', 'WINTER', 2006, '987-65-4321', '10:30:00'),
(5679, 'IS480', 'BLM412', 'TTH', 'SPRING', 2006, '876-54-3210', '15:30:00'),
(6666, 'FIN450', 'BLM212', 'TTH', 'WINTER', 2006, '987-65-4321', '10:30:00'),
(7777, 'FIN480', 'BLM305', 'MW', 'SPRING', 2006, '765-43-2109', '13:30:00'),
(8888, 'IS320', 'BLM405', 'MW', 'SUMMER', 2006, '654-32-1098', '13:30:00'),
(9876, 'IS460', 'BLM307', 'TTH', 'SPRING', 2006, '654-32-1098', '13:30:00');

-- --------------------------------------------------------

--
-- 資料表結構 `student`
--

CREATE TABLE `student` (
  `StdSSN` char(11) NOT NULL,
  `StdFirstName` varchar(50) NOT NULL,
  `StdLastName` varchar(50) NOT NULL,
  `StdCity` varchar(50) NOT NULL,
  `StdState` char(2) NOT NULL,
  `StdZip` char(10) NOT NULL,
  `StdMajor` char(6) NOT NULL,
  `StdClass` char(2) NOT NULL,
  `StdGPA` decimal(3,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- 資料表的關聯 `student`:
--

--
-- 傾印資料表的資料 `student`
--

INSERT INTO `student` (`StdSSN`, `StdFirstName`, `StdLastName`, `StdCity`, `StdState`, `StdZip`, `StdMajor`, `StdClass`, `StdGPA`) VALUES
('123-45-6789', 'HOMER', 'WELLS', 'SEATTLE', 'WA', '98121-1111', 'IS', 'FR', '3.00'),
('124-56-7890', 'BOB', 'NORBERT', 'BOTHELL', 'WA', '98011-2121', 'FIN', 'JR', '2.70'),
('234-56-7890', 'CANDY', 'KENDALL', 'TACOMA', 'WA', '99042-3321', 'ACCT', 'JR', '3.50'),
('345-67-8901', 'WALLY', 'KENDALL', 'SEATTLE', 'WA', '98123-1141', 'IS', 'SR', '2.80'),
('456-78-9012', 'JOE', 'ESTRADA', 'SEATTLE', 'WA', '98121-2333', 'FIN', 'SR', '3.20'),
('567-89-0123', 'MARIAH', 'DODGE', 'SEATTLE', 'WA', '98114-0021', 'IS', 'JR', '3.60'),
('678-90-1234', 'TESS', 'DODGE', 'REDMOND', 'WA', '98116-2344', 'ACCT', 'SO', '3.30'),
('789-01-2345', 'ROBERTO', 'MORALES', 'SEATTLE', 'WA', '98121-2212', 'FIN', 'JR', '2.50'),
('876-54-3210', 'CRISTOPHER', 'COLAN', 'SEATTLE', 'WA', '98114-1332', 'IS', 'SR', '4.00'),
('890-12-3456', 'LUKE', 'BRAZZI', 'SEATTLE', 'WA', '98116-0021', 'IS', 'SR', '2.20'),
('901-23-4567', 'WILLIAM', 'PILGRIM', 'BOTHELL', 'WA', '98113-1885', 'IS', 'SO', '3.80');

--
-- 已傾印資料表的索引
--

--
-- 資料表索引 `course`
--
ALTER TABLE `course`
  ADD PRIMARY KEY (`CourseNo`),
  ADD UNIQUE KEY `CrsDesc` (`CrsDesc`);

--
-- 資料表索引 `enrollment`
--
ALTER TABLE `enrollment`
  ADD PRIMARY KEY (`OfferNo`,`StdSSN`),
  ADD KEY `StdSSNFK` (`StdSSN`);

--
-- 資料表索引 `faculty`
--
ALTER TABLE `faculty`
  ADD PRIMARY KEY (`FacSSN`),
  ADD KEY `FacSupervisorFK` (`FacSupervisor`);

--
-- 資料表索引 `offering`
--
ALTER TABLE `offering`
  ADD PRIMARY KEY (`OfferNo`),
  ADD KEY `CourseNoFK` (`CourseNo`),
  ADD KEY `FacSSNFK` (`FacSSN`);

--
-- 資料表索引 `student`
--
ALTER TABLE `student`
  ADD PRIMARY KEY (`StdSSN`);

--
-- 已傾印資料表的限制式
--

--
-- 資料表的限制式 `enrollment`
--
ALTER TABLE `enrollment`
  ADD CONSTRAINT `OfferNoFK` FOREIGN KEY (`OfferNo`) REFERENCES `offering` (`OfferNo`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `StdSSNFK` FOREIGN KEY (`StdSSN`) REFERENCES `student` (`StdSSN`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- 資料表的限制式 `faculty`
--
ALTER TABLE `faculty`
  ADD CONSTRAINT `FacSupervisorFK` FOREIGN KEY (`FacSupervisor`) REFERENCES `faculty` (`FacSSN`) ON DELETE SET NULL ON UPDATE CASCADE;

--
-- 資料表的限制式 `offering`
--
ALTER TABLE `offering`
  ADD CONSTRAINT `CourseNoFK` FOREIGN KEY (`CourseNo`) REFERENCES `course` (`CourseNo`),
  ADD CONSTRAINT `FacSSNFK` FOREIGN KEY (`FacSSN`) REFERENCES `faculty` (`FacSSN`) ON DELETE SET NULL ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
