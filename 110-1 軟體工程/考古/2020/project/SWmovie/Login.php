<?php 
session_start();
setcookie("LoginState", '', time()-3600);
setcookie("UserName", '', time()-3600);
setcookie("RecordID", '', time()-3600);
setcookie("MemberID", "", time()-3600);


// 建立MySQL的資料庫連接 
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

$sqlUser = "SELECT * FROM `member profile`";
$resultUser = $connect->query($sqlUser);

$IDnumber = @$_POST["account"];
//echo $IDnumber;//輸入的帳號
//echo "<br>";

$Password = @$_POST["password"];
//echo $Password;//輸入的密碼
//echo "<br>";

$sqlID = "SELECT `account` FROM `member profile`";

//echo "<br>";
$resultID = $connect->query($sqlID);

$AState = false;
$PState = false;
if ($resultID->num_rows > 0) {
    while ($rowID = $resultID->fetch_assoc())
    {
        $ID = $rowID['account'];
        //echo $ID;
        if($ID == $IDnumber)
        {
            $AState = true;
            //echo "<br>";
            //echo $ID;
            break;
        }
    }
}
//echo "<meta http-equiv='Refresh' content='0; URL=login.php'>"; 
if(!$AState)
{
    echo "<script>alert('帳號錯誤，請重新輸入！');</script>";
    $connect->close();
    setcookie("LoginState", false, time()+3600);
    header("meta http-equiv='Refresh' content='0; url = login.html");
    exit;
} 

//echo "<br>";
$sqlPass = "SELECT `password` FROM `member profile` WHERE `account`= '$IDnumber'";
//echo $sqlPass;
//echo "<br>";
$resultPass = $connect->query($sqlPass);

if ($resultPass->num_rows > 0) {
    while ($rowPass = $resultPass->fetch_assoc())
    {
        $password = $rowPass['password'];
        //echo $password;
        if($password == $Password)
        {
            $PState = true;
            //echo "<br>";
            //echo $password;
            break;
        }
            
    }
}
//echo "<br>";
if($AState && $PState)
{
    $_SESSION['username'] = $IDnumber.", 登出";
    echo "<script>alert('登入成功！');</script>";
    echo "<meta http-equiv='Refresh' content='0; URL=home.php'>"; 

    $connect->close();
    setcookie("LoginState", true, time()+3600);
    setcookie("UserName", $IDnumber, time()+3600);
    
    exit;
} 
else
{
    echo "<script>alert('密碼錯誤...');</script>";
    $connect->close();
    session_start();
    setcookie("LoginState", false, time()+3600);
    header("refresh:1;url = login.html"); 
    exit;
}

?>