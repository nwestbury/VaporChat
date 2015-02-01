<?php
require_once("database.php");
if(isset($_POST["username"])){
    $username = $con->real_escape_string($_POST["username"]);
    $results = $con->query("SELECT friends FROM users WHERE username='$username' LIMIT 1");
    $row =  $results->fetch_assoc();
    echo $row["friends"];
}else{
    echo "Failed to find friends of current user :(";
}
?>
