-- phpMyAdmin SQL Dump
-- version 4.8.1
-- https://www.phpmyadmin.net/
--
-- 主機: 127.0.0.1
-- 產生時間： 2018 年 12 月 27 日 19:25
-- 伺服器版本: 10.1.33-MariaDB
-- PHP 版本： 7.2.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 資料庫： `atm`
--

-- --------------------------------------------------------

--
-- 資料表結構 `atm_bank_number`
--

CREATE TABLE `atm_bank_number` (
  `bank_name` varchar(10) CHARACTER SET utf8 NOT NULL,
  `bank_number` varchar(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- 資料表的匯出資料 `atm_bank_number`
--

INSERT INTO `atm_bank_number` (`bank_name`, `bank_number`) VALUES
('上海銀行', '011'),
('中國信託', '822'),
('中央信託', '001'),
('中華銀行', '804'),
('交通銀行', '003'),
('兆豐商銀', '017'),
('台中商銀', '053'),
('台北富邦', '012'),
('台新銀行', '812'),
('台灣銀行', '004'),
('合庫商銀', '006'),
('國泰世華', '013'),
('土地銀行', '005'),
('彰化銀行', '009'),
('新竹商銀', '052'),
('東亞銀行', '075'),
('渣打銀行', '052'),
('玉山銀行', '808'),
('第一銀行', '007'),
('聯邦銀行', '803'),
('臺灣企銀', '050'),
('花旗銀行', '021'),
('華南銀行', '008'),
('農業金庫', '018'),
('首都銀行', '025'),
('高雄銀行', '016');

-- --------------------------------------------------------

--
-- 資料表結構 `confirm_password`
--

CREATE TABLE `confirm_password` (
  `user_account` varchar(10) NOT NULL,
  `user_password` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `confirm_transfer_money`
--

CREATE TABLE `confirm_transfer_money` (
  `user_account` varchar(20) NOT NULL,
  `transfer_account` varchar(20) NOT NULL,
  `transfer_money` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- 資料表的匯出資料 `confirm_transfer_money`
--

INSERT INTO `confirm_transfer_money` (`user_account`, `transfer_account`, `transfer_money`) VALUES
('amy', 'jamie', 100);

-- --------------------------------------------------------

--
-- 資料表結構 `confirm_transfer_money2`
--

CREATE TABLE `confirm_transfer_money2` (
  `bank_number` varchar(3) NOT NULL,
  `user_account` varchar(20) NOT NULL,
  `transfer_account` varchar(20) NOT NULL,
  `transfer_money` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `user_ac_money`
--

CREATE TABLE `user_ac_money` (
  `user_account` varchar(10) NOT NULL,
  `account_money` int(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- 資料表的匯出資料 `user_ac_money`
--

INSERT INTO `user_ac_money` (`user_account`, `account_money`) VALUES
('amy', 123231362),
('B0529021', 6000000),
('B0529039', 60000000),
('jamie', 1221131759),
('test', 1276);

-- --------------------------------------------------------

--
-- 資料表結構 `user_ac_pw`
--

CREATE TABLE `user_ac_pw` (
  `user_account` varchar(10) NOT NULL,
  `user_password` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- 資料表的匯出資料 `user_ac_pw`
--

INSERT INTO `user_ac_pw` (`user_account`, `user_password`) VALUES
('B0529021', '12345678'),
('B0529039', '12345678'),
('B0529053', '12345678'),
('jamie', '1997'),
('test', '1234567');

-- --------------------------------------------------------

--
-- 資料表結構 `user_bank_account`
--

CREATE TABLE `user_bank_account` (
  `bank_number` varchar(3) NOT NULL,
  `user_account` varchar(10) NOT NULL,
  `account_money` int(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- 資料表的匯出資料 `user_bank_account`
--

INSERT INTO `user_bank_account` (`bank_number`, `user_account`, `account_money`) VALUES
('001', 'ach', 44453742),
('003', 'test', 10000),
('008', 'test', 10000),
('009', 'test', 10000),
('011', 'test', 10000),
('808', 'test', 10000),
('812', 'test', 10000);

--
-- 已匯出資料表的索引
--

--
-- 資料表索引 `atm_bank_number`
--
ALTER TABLE `atm_bank_number`
  ADD PRIMARY KEY (`bank_name`,`bank_number`);

--
-- 資料表索引 `confirm_password`
--
ALTER TABLE `confirm_password`
  ADD PRIMARY KEY (`user_account`);

--
-- 資料表索引 `confirm_transfer_money`
--
ALTER TABLE `confirm_transfer_money`
  ADD PRIMARY KEY (`user_account`);

--
-- 資料表索引 `confirm_transfer_money2`
--
ALTER TABLE `confirm_transfer_money2`
  ADD PRIMARY KEY (`user_account`);

--
-- 資料表索引 `user_ac_money`
--
ALTER TABLE `user_ac_money`
  ADD PRIMARY KEY (`user_account`);

--
-- 資料表索引 `user_ac_pw`
--
ALTER TABLE `user_ac_pw`
  ADD PRIMARY KEY (`user_account`,`user_password`);

--
-- 資料表索引 `user_bank_account`
--
ALTER TABLE `user_bank_account`
  ADD PRIMARY KEY (`bank_number`,`user_account`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
