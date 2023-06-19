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
$PayAccount = @$_POST["PayAccount"];
//echo "PayAccount $PayAccount";
//echo "<br>";


$PState = false;
$sqlPay = "SELECT `pay` FROM `member profile` WHERE `memberID` = $MemberID";
//echo $sqlPay;
//echo "<br>";
$resultPay = $connect->query($sqlPay);

if ($resultPay->num_rows > 0) {
    while ($rowP = $resultPay->fetch_assoc())
    {
        $Pay = $rowP['pay'];
       // echo "Pay $Pay <br>";
       // echo "PayAccount $PayAccount";
       // echo "<br>";
       // echo "$PayAccount" == "$Pay";
       // echo "<br>";
        if("$PayAccount" == "$Pay")
        {
            $PState = true;
          //  echo "True <br>";
            $sqlWay = "UPDATE `booking record` SET `payment`= 1 WHERE `recordID`= '$RecordID'";
           // echo $sqlWay;
           // echo "<br>";
            $resultWay = $connect->query($sqlWay);

            break;
        }
    }
}
if(!$PState)
{
    echo "<script>alert('付款帳號錯誤，請重新輸入！');</script>";
    $connect->close();
    
    header("refresh:0;url = Pay.php");
    exit;
} 
else
{
    $connect->close();
    header("refresh:0;url = ticketInformation.php");
    exit;
}

?>