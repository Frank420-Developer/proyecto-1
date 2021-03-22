<?php
    $server = 'localhost';
    $user = 'root';
    $psw = '';
    $db = 'miweb';
    
    $con = mysqli_connect($server, $user, $psw, $db);

    if(!$con){
        echo 'conexion fallida';
        exit;        
    }

?>

    
