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

$Name = @$_POST["name"];
$Gender = @$_POST["gender"];
$Birth = @$_POST["birth"];
$Phone = @$_POST["phone"];
$Email = @$_POST["email"];
$Pay = @$_POST["pay"];
$Account = @$_POST["account"];
$Password = @$_POST["password"];

$sqluser = "SELECT * FROM `member profile`";
$resultuser = $connect->query($sqluser);

$MemberID = $resultuser->num_rows + 1;

$Acc = 0;
while ($row = $resultuser->fetch_assoc())
{
    //echo "1";
    $Acc = $row['account'];
    //echo $Acc;
    //echo $Account;
    //echo "2";
    if($Acc == $Account)
    {
        //echo "3";
        echo "<script>alert('帳號重複，請重新註冊！');</script>";
        $resultuser = $connect->query($sqluser);
        $connect->close();
        header("refresh:0;url = register.html");
        exit;
    }
}


$sqlAdd = "INSERT INTO `member profile`(`memberID`, `name`, `gender`, `birthday`, `phone`, `email`, `pay`, `account`, `password`) VALUES('202000000$MemberID', '$Name', '$Gender', '$Birth', '$Phone', '$Email', '$Pay', '$Account', '$Password')";

//echo $sqlAdd;
//echo "<br>";

$sqlNum = "SELECT * FROM `member profile`";
$resultNum = $connect->query($sqlNum);

$Number = $resultuser->num_rows + 1;
//echo $Number;
//echo "<br>";
//echo $MemberID;
if($Number == ($MemberID))
{
    echo "<script>alert('註冊成功！');</script>";
    $result = $connect->query($sqlAdd);
    $connect->close();
    header("refresh:0;url = login.html");
    exit;
}
else
{
    echo "<script>alert('註冊失敗！');</script>";
    $result = $connect->query($sqlAdd);
    $connect->close();
    header("refresh:10;url = register.html");
    exit;
}

?>