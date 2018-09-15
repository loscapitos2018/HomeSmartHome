<?php


 require("conexion.php");
 $sql = "UPDATE `luces` SET `idluz`='1',`estado`='1'";
 $query = $con -> query($sql);
echo "<script>location.href='device.php'</script>";
?>