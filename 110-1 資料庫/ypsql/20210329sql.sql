-- phpMyAdmin SQL Dump
-- version 4.6.6
-- https://www.phpmyadmin.net/
--
-- 主機: localhost
-- 產生時間： 2021-03-29 07:15:55
-- 伺服器版本: 5.7.17-log
-- PHP 版本： 5.6.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 資料庫： `20210329sql`
--

-- --------------------------------------------------------

--
-- 資料表結構 `course`
--

CREATE TABLE `course` (
  `course_id` varchar(7) NOT NULL DEFAULT '',
  `title` varchar(50) DEFAULT NULL,
  `dept_name` varchar(20) DEFAULT NULL,
  `credits` decimal(2,0) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 資料表的匯出資料 `course`
--

INSERT INTO `course` (`course_id`, `title`, `dept_name`, `credits`) VALUES
('BIO-101', 'Intro. to Biology', 'Biology', '4'),
('BIO-301', 'Genetics', 'Biology', '4'),
('BIO-399', 'Computational Biology', 'Biology', '3'),
('CS-101', 'Intro. to Computer Science', 'Comp. Sci.', '4'),
('CS-190', 'Game Design', 'Comp. Sci.', '4'),
('CS-315', 'Robotics', 'Comp. Sci.', '3'),
('CS-319', 'Image Processing.', 'Comp. Sci.', '3'),
('CS-347', 'Database System Concepts', 'Comp. Sci.', '3'),
('EE-181', 'Intro. to Digital Systems', 'Elec. Eng.', '3'),
('FIN-201', 'Investment Banking', 'Finance', '3'),
('HIS-351', 'World History', 'History', '3'),
('MU-199', 'Music Video Production', 'Music', '3'),
('PHY-101', 'Physical Principles', 'Physics', '4');

-- --------------------------------------------------------

--
-- 資料表結構 `department`
--

CREATE TABLE `department` (
  `dept_name` varchar(20) NOT NULL DEFAULT '',
  `building` varchar(15) DEFAULT NULL,
  `budget` decimal(12,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 資料表的匯出資料 `department`
--

INSERT INTO `department` (`dept_name`, `building`, `budget`) VALUES
('Biology', 'Watson', '90000.00'),
('Comp. Sci.', 'Taylor', '100000.00'),
('Elec. Eng.', 'Taylor', '85000.00'),
('Finance', 'Painter', '120000.00'),
('History', 'Painter', '50000.00'),
('Music', 'Packard', '80000.00'),
('Physics', 'Watson', '70000.00');

-- --------------------------------------------------------

--
-- 資料表結構 `instructor`
--

CREATE TABLE `instructor` (
  `ID` varchar(5) NOT NULL DEFAULT '',
  `name` varchar(20) NOT NULL,
  `dept_name` varchar(20) DEFAULT NULL,
  `salary` decimal(8,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 資料表的匯出資料 `instructor`
--

INSERT INTO `instructor` (`ID`, `name`, `dept_name`, `salary`) VALUES
('10101', 'Srinivasan', 'Comp. Sci.', '65000.00'),
('12121', 'Wu', 'Finance', '90000.00'),
('15151', 'Mozart', 'Music', '40000.00'),
('22222', 'Einstein', 'Physics', '95000.00'),
('32343', 'El Said', 'History', '60000.00'),
('33456', 'Gold', 'Physics', '87000.00'),
('45565', 'Katz', 'Comp. Sci.', '75000.00'),
('58583', 'Califieri', 'History', '62000.00'),
('76543', 'Singh', 'Finance', '80000.00'),
('76766', 'Crick', 'Biology', '72000.00'),
('83821', 'Brandt', 'Comp. Sci.', '92000.00'),
('98345', 'Kim', 'Elec. Eng.', '80000.00');

-- --------------------------------------------------------

--
-- 資料表結構 `section`
--

CREATE TABLE `section` (
  `course_id` varchar(8) NOT NULL DEFAULT '',
  `sec_id` varchar(8) NOT NULL DEFAULT '',
  `semester` varchar(6) NOT NULL DEFAULT '',
  `year` decimal(4,0) NOT NULL DEFAULT '0',
  `building` varchar(15) DEFAULT NULL,
  `room_number` varchar(7) DEFAULT NULL,
  `time_slot_id` varchar(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 資料表的匯出資料 `section`
--

INSERT INTO `section` (`course_id`, `sec_id`, `semester`, `year`, `building`, `room_number`, `time_slot_id`) VALUES
('Bio-101', '1', 'Summer', '2009', 'Painter', '514', 'B'),
('BIO-301', '1', 'Summer', '2010', 'Painter', '514', 'A'),
('CS-101', '1', 'Fall', '2009', 'Packard', '101', 'H'),
('CS-101', '1', 'Spring', '2010', 'Packard', '101', 'F'),
('CS-190', '1', 'Spring', '2009', 'Taylor', '3128', 'E'),
('CS-190', '2', 'Spring', '2009', 'Taylor', '3128', 'A'),
('CS-315', '1', 'Spring', '2010', 'Watson', '120', 'D'),
('CS-319', '1', 'Spring', '2010', 'Watson', '100', 'B'),
('CS-319', '2', 'Spring', '2010', 'Taylor', '3128', 'C'),
('CS-347', '1', 'Fall', '2009', 'Taylor', '3128', 'A'),
('EE-181', '1', 'Spring', '2009', 'Taylor', '3128', 'C'),
('FIN-201', '1', 'Spring', '2010', 'Packard', '101', 'B'),
('HIS-351', '1', 'Spring', '2010', 'Painter', '514', 'C'),
('MU-199', '1', 'Spring', '2010', 'Packard', '101', 'D'),
('PHY-101', '1', 'Fall', '2009', 'Watson', '100', 'A');

-- --------------------------------------------------------

--
-- 資料表結構 `teaches`
--

CREATE TABLE `teaches` (
  `ID` varchar(5) NOT NULL DEFAULT '',
  `course_id` varchar(8) NOT NULL DEFAULT '',
  `sec_id` varchar(8) NOT NULL DEFAULT '',
  `semester` varchar(6) NOT NULL DEFAULT '',
  `year` decimal(4,0) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 資料表的匯出資料 `teaches`
--

INSERT INTO `teaches` (`ID`, `course_id`, `sec_id`, `semester`, `year`) VALUES
('76766', 'BIO-101', '1', 'Summer', '2009'),
('76766', 'BIO-301', '1', 'Summer', '2010'),
('10101', 'CS-101', '1', 'Fall', '2009'),
('45565', 'CS-101', '1', 'Spring', '2010'),
('83821', 'CS-190', '1', 'Spring', '2009'),
('83821', 'CS-190', '2', 'Spring', '2009'),
('10101', 'CS-315', '1', 'Spring', '2010'),
('45565', 'CS-319', '1', 'Spring', '2010'),
('83821', 'CS-319', '2', 'Spring', '2010'),
('10101', 'CS-347', '1', 'Fall', '2009'),
('98345', 'EE-181', '1', 'Spring', '2009'),
('12121', 'FIN-201', '1', 'Spring', '2010'),
('32343', 'HIS-351', '1', 'Spring', '2010'),
('15151', 'MU-199', '1', 'Spring', '2010'),
('22222', 'PHY-101', '1', 'Fall', '2009');

--
-- 已匯出資料表的索引
--

--
-- 資料表索引 `course`
--
ALTER TABLE `course`
  ADD PRIMARY KEY (`course_id`),
  ADD KEY `dept_name` (`dept_name`);

--
-- 資料表索引 `department`
--
ALTER TABLE `department`
  ADD PRIMARY KEY (`dept_name`);

--
-- 資料表索引 `instructor`
--
ALTER TABLE `instructor`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `dept_name` (`dept_name`);

--
-- 資料表索引 `section`
--
ALTER TABLE `section`
  ADD PRIMARY KEY (`course_id`,`sec_id`,`semester`,`year`);

--
-- 資料表索引 `teaches`
--
ALTER TABLE `teaches`
  ADD PRIMARY KEY (`ID`,`course_id`,`sec_id`,`semester`,`year`),
  ADD KEY `course_id` (`course_id`,`sec_id`,`semester`,`year`);

--
-- 已匯出資料表的限制(Constraint)
--

--
-- 資料表的 Constraints `course`
--
ALTER TABLE `course`
  ADD CONSTRAINT `course_ibfk_1` FOREIGN KEY (`dept_name`) REFERENCES `department` (`dept_name`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- 資料表的 Constraints `instructor`
--
ALTER TABLE `instructor`
  ADD CONSTRAINT `instructor_ibfk_1` FOREIGN KEY (`dept_name`) REFERENCES `department` (`dept_name`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- 資料表的 Constraints `section`
--
ALTER TABLE `section`
  ADD CONSTRAINT `section_ibfk_1` FOREIGN KEY (`course_id`) REFERENCES `course` (`course_id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- 資料表的 Constraints `teaches`
--
ALTER TABLE `teaches`
  ADD CONSTRAINT `teaches_ibfk_1` FOREIGN KEY (`course_id`,`sec_id`,`semester`,`year`) REFERENCES `section` (`course_id`, `sec_id`, `semester`, `year`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `teaches_ibfk_2` FOREIGN KEY (`ID`) REFERENCES `instructor` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
