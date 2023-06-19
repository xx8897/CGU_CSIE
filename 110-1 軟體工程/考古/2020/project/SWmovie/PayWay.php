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
//echo "State $State";
$UserName = $_COOKIE['UserName'];
//echo "Name $UserName";
$MemberID = $_COOKIE['MemberID'];
//echo "Member $MemberID";
$RecordID = $_COOKIE['RecordID'];
//echo "re $RecordID";

$Way = @$_POST["pay"];
//echo "Way $Way";
//echo "<br>";

$sqlWay = "UPDATE `booking record` SET `paymentMethod`= '$Way' WHERE `recordID`= '$RecordID'";
//echo $sqlWay;
//echo "<br>";
$resultWay = $connect->query($sqlWay);

if($Way == 'cash')
{
    $connect->close();
    header("refresh:0;url = ticketInformation.php");
    exit;
}
else if($Way == 'online')
{
    $connect->close();
    header("refresh:0;url = Pay.php");
    exit;
}

?>