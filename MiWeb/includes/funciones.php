<?php

    function enviarDatos(){
        try {
            //importar conexion
            require 'clientes.php'; 
            
            
            //código sql
            $nombre = $_POST['name'];
            $telefono = $_POST['telephone'];
            $correo = $_POST['email'];
            $mensaje = $_POST['message'];
            $sql =  "INSERT INTO clientes(nombre, telefono, correo, mensaje) VALUES('$nombre', '$telefono', '$correo', '$mensaje');";
            $consulta = mysqli_query( $con, $sql);
        
            //resultados
            while($row =mysqli_fetch_assoc($consulta)){
                echo "<pre>";
                var_dump($row);
                echo "</pre>";
            }
            

        } catch (\Throwable $th) {
            //throw $th;

            var_dump($th);
        }
    }
    enviarDatos();
?>