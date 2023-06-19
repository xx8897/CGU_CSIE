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
//echo "<br>";

$FState = @$_POST["FState"];
//echo "FState $FState";
//echo "<br>";
if($FState == "確定訂票"){
    $sqlShow = "UPDATE `booking record` SET `Finish` = '1' WHERE `booking record`.`recordID` = '$RecordID'";
    //echo $sqlShow;
    $resultShow = $connect->query($sqlShow);
}

$connect->close();
header("refresh:0;url = history.php");
exit;
?>

