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

$State = $_COOKIE['LoginState'];
//echo $State;
//echo "<br>";
$UserName = $_COOKIE['UserName'];
//echo $UserName;
//echo "<br>";
$MemberID = $_COOKIE['MemberID'];
//echo $MemberID;
//echo "<br>";
$RecordID = $_COOKIE['RecordID'];
//echo $RecordID;
//echo "<br>";

$Total = 0;
$Type1 = @$_POST["優待票"];
//echo $Type1;

for($i = 0;$i < $Type1;$i++)
{
    //echo $RecordID;
    //echo "<br>";
    $sqlType = "INSERT INTO `ticket information`(`recordID`, `ticketID`, `ticketType` ) VALUES ('$RecordID', '$RecordID$Total', '優待票')";
    //echo $sqlType;
    //echo "<br>";
    $resulType = $connect->query($sqlType);
    $Total ++;
}

$Type2 = @$_POST["學生票"];
//echo $Type2;

for($i = 0;$i < $Type2;$i++)
{
    
    $sqlType = "INSERT INTO `ticket information`(`recordID`, `ticketID`, `ticketType` ) VALUES ('$RecordID', '$RecordID$Total', '學生票')";
    //echo $sqlType;
    //echo "<br>";
    $resulType = $connect->query($sqlType);
    $Total ++;
}

$Type3 = @$_POST["普通票"];
//echo $Type3;

for($i = 0;$i < $Type3;$i++)
{
    
    $sqlType = "INSERT INTO `ticket information`(`recordID`, `ticketID`, `ticketType` ) VALUES ('$RecordID', '$RecordID$Total', '普通票')";
    //echo $sqlType;
    //echo "<br>";
    $resulType = $connect->query($sqlType);
    $Total ++;
}

//echo " Total $Total";

$sqlNum = "UPDATE `booking record` SET `number`= $Total WHERE `recordID`='$RecordID'";
//echo $sqlNum;
//echo "<br>";
$resultNum = $connect->query($sqlNum);
setcookie("TicketNum", 0, time()+3600);

$connect->close();
header("refresh:0;url = Seat.php"); 
exit;
?>