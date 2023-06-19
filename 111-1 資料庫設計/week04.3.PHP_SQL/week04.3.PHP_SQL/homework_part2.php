<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<pre>
<?php


$buffer = "ABC;123;xyz";
$a = explode(";", $buffer);
print_r($a);



$fptr = fopen("input_small.txt", "r");
while (!feof($fptr)) {
    $buffer = fgets($fptr);
    echo $buffer;
}
fclose($fptr);

?>
</pre>
