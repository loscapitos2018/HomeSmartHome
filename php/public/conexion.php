<?php
$host="localhost";
$user="root";
$password="12345678";
$based="luz";
$con=mysqli_connect($host,$user,$password) or die ("No se ha podido conectar al servidor de Base de datos");
$db=mysqli_select_db($con,$based);
?>

