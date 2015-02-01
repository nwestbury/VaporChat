<?php
require_once("database.php");

if(isset($_POST["username"]) && isset($_POST["password"] && isset($_POST["privkey"]) && isset($_POST["pubkey"])){
    $hash = hash('sha256', $_POST["password"]); //no need for string escape since it is hashed
    $username = $con->real_escape_string($_POST["username"]);
    $privkey = $con->real_escape_string($_POST["privkey"]);
    $pubkey = $con->real_escape_string($_POST["pubkey"]);
    $con -> query("INSERT INTO users (username, passhash, privkey, pubkey) VALUES ($username, $hash, $privkey, $pubkey)");
}else{
    echo "Failed to create username: no password or username provided";
}
?>
