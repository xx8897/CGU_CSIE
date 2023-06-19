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

$Date = @$_POST["Date"];
//echo $Date;

$State = $_COOKIE['LoginState'];
//echo $State;
$UserName = $_COOKIE['UserName'];
//echo $UserName;


$MemberID = 0;
$sqlUser = "SELECT * FROM `member profile` WHERE `account`='$UserName'";
$resultUser = $connect->query($sqlUser);
if ($resultUser->num_rows > 0) {
    while ($rowU = $resultUser->fetch_assoc())
    {
        $MemberID = $rowU["memberID"];
    }
}

//echo "ID $MemberID";
setcookie("MemberID", "$MemberID", time()+3600);


for($i = 1001;$i <= 1012;$i++)
{
    if(@$_POST["$i"]){
        $MovieID = $i;
        $Time = @$_POST["$i"];
        //echo $MovieID;
        //echo $Time;
        $sqlShow = "SELECT `showingID` FROM `showing` WHERE `movieID`= $MovieID AND `startTime`='$Time' AND `day`=$Date";
        //echo $sqlShow;
        
        $resultShow = $connect->query($sqlShow);
        if ($resultShow->num_rows > 0) {
            while ($rowS = $resultShow->fetch_assoc())
            {
                $ShowingID = $rowS['showingID'];
                //echo "showingid $ShowingID<br>";
                //echo "$UserName$ShowingID<br>";
                $sqlRecord = "INSERT INTO `booking record`(`memberID`, `showingID`, `recordID`) VALUES ('$MemberID', '$ShowingID', '$UserName$ShowingID')";
                //echo $sqlRecord;
                setcookie("RecordID", $UserName.$ShowingID, time()+3600);
                //echo "RID ";
                //echo$_COOKIE["RecordID"];
                $result = $connect->query($sqlRecord);
    
                break;
            }
        }
    }
    //echo "<br>";
}
$connect->close();
header("refresh:0.1;url = Number.php"); 
exit;
?>