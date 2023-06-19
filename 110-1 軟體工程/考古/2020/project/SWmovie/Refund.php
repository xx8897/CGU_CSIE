<?php
$host = 'localhost';
//改成你登入phpmyadmin帳號
$user = 'root';
//改成你登入phpmyadmin密碼
$passwd = '20000206';
//資料庫名稱
$database = 'movie';
//實例化mysqli(資料庫路徑, 登入帳號, 登入密碼, 資料庫)
$connect = new mysqli($host, $user, $passwd, $database);
//設定連線編碼，防止中文字亂碼
$connect->query("SET NAMES 'utf8'");

if ($connect->connect_error) {
    die("連線失敗: " . $connect->connect_error);
}
//echo "連線成功";
//echo "<br>";
$UserName = $_COOKIE['UserName'];
$MemberID = 0;

$sqlID = "SELECT `memberID` FROM `member profile` WHERE `account` = '$UserName'";

$resultID = $connect->query($sqlID);

if ($resultID->num_rows > 0) {
    while ($rowID = $resultID->fetch_assoc())
    {
        $MemberID = $rowID['memberID'];
    }
}

$sqlBook = "SELECT * FROM `booking record` WHERE `memberID` = '$MemberID' AND `Finish` = 1";
$resultBook = $connect->query($sqlBook);
if ($resultBook->num_rows > 0) 
{
	while ($rowB = $resultBook->fetch_assoc())
	{						
        $RecordID = $rowB["recordID"];
        //echo "<br>";
        if(@$_POST["$RecordID"])
        {
            //echo "RefunID $RecordID";
            $sqldelBook = "DELETE FROM `booking record` WHERE `recordID` = '$RecordID'";

            $sqldelTicket = "DELETE FROM `ticket information` WHERE `recordID` = '$RecordID'";
            echo $sqldelTicket;
            $resultdelBook = $connect->query($sqldelBook);
            $resultTicket = $connect->query($sqldelTicket);
            break;
        }
								
    }
}



$connect->close();
header("refresh:0;url = history.php");
exit;
?>

