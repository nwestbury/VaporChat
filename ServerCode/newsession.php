<?php
require_once("database.php");

$_POST["username"] = "Nico";
$_POST["userlist"] = "['Nico', 'James']";
$_POST["hashedsessionkey"] = "sadsaddsasadasfdfs";

if(isset($_POST["username"]) && isset($_POST["userlist"]) && isset($_POST["hashedsessionkey"])){
    /*$userlist = $con->real_escape_string($_POST["userlist"]);
    $username = $con->real_escape_string($_POST["username"]);
    $hashedsessionkey = $con->real_escape_string($_POST["hashedsessionkey"]);
    $userarray = json_encode($userlist);
    
    $results = $con->query("SELECT `AUTO_INCREMENT` FROM  INFORMATION_SCHEMA.TABLES WHERE TABLE_SCHEMA = 'vaporchat'
AND TABLE_NAME = 'sessions'");
    $row = $results->fetch_row();
    
    $sessionID = $row[0];
    $con->query("INSERT INTO `sessions` (sessionid, listofusers, hashedsessionkey) VALUES ($sessionID, '$userarray', '$hashedsessionkey')");
    $results = $con->query("SELECT sessionlist from `users` WHERE username = $username LIMIT 1");
    if( $results->num_rows > 0){
        $row = $results->fetch_assoc();
        $sessionArray = json_decode($row["sessionlist"]);
        $sessionArray[] 
        $tempArray = array($sessionID, (int)$row["msgid"], array($row["from_user"], $row["msg"]));
    }*/
}else{
    echo "Failed: no user list :(";
}
?>
