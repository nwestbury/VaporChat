<?php
error_reporting(E_ALL);

require_once("database.php");

if(isset($_POST["username"]) && isset($_POST["password"])){
    $hash = hash('sha256', $_POST["password"]); //no need for string escape since it is hashed
    $username = $con->real_escape_string($_POST["username"]);
    $res = $con->query("SELECT pubkey, privkey FROM `users` WHERE `username`='$username' AND `passhash`='$hash'") or die("Failed, SQL Error");

    if($res->num_rows !== 1) {
        die("Failed bad password or username");
    }
    
    
    
    $row = $res->fetch_assoc();
    die(json_encode(array($row["pubkey"], $row["privkey"])));
    
}else{
    echo "Failed to login :(";
}
?>
