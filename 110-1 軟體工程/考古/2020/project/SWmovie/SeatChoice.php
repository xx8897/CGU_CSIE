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
$TicketNum = $_COOKIE['TicketNum'];
//echo "TicketNum $TicketNum";

$SeatNum = @$_POST["SeatNum"];
//echo "Seat $SeatNum";
//echo "<br>";

$sqlSeat = "UPDATE `ticket information` SET `seat`= $SeatNum WHERE `ticketID`='$RecordID$TicketNum'";
//echo $sqlSeat;
                
setcookie("TicketNum", $TicketNum + 1, time()+3600);
$Num2 = $_COOKIE['TicketNum'];
//echo "Num2 $Num2";
//echo "<br>";
$result = $connect->query($sqlSeat);

$sqlNum = "SELECT `number` FROM `booking record` WHERE `recordID`= '$RecordID'";
//echo $sqlNum;
//echo "<br>";
$resultNum = $connect->query($sqlNum);

$Num = 0;
if ($resultNum->num_rows > 0) {
    while ($rowN = $resultNum->fetch_assoc())
    {
        $Num = $rowN['number']; 
    }
}
//echo "Total $Num2 $Num";
//echo "<br>";

if($Num2 >= ($Num-1))
{
    $connect->close();
    setcookie("TicketNum", 0, time()-3600);
    header("refresh:0;url = buy2.html");
    exit;
}
else
{
    $connect->close();
    header("refresh:0;url = Seat.php");
    exit;
}
?>
