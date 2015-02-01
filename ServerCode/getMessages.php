<?php
require_once("database.php");

if(isset($_POST["username"])){
    $username = $con->real_escape_string($_POST["username"]);
    $results = $con->query("SELECT sessionlist FROM users WHERE username='$username' LIMIT 1");
    $row = $results->fetch_assoc();
    $sessionArray = json_decode($row["sessionlist"]);
    
    $massive_array = array();
    foreach($sessionArray as $sessionID){
        $results = $con->query("SELECT msgid, msg, from_user FROM msgs WHERE sessionid = $sessionID ORDER BY msgid DESC LIMIT 50");
        $tempArray = array($sessionID, -1);
        
        if( $results->num_rows > 0){
            $row = $results->fetch_assoc();
            $tempArray = array($sessionID, (int)$row["msgid"], array($row["from_user"], $row["msg"]));
        }
        
        while($row = $results->fetch_assoc()){
            $tempArray[] = array($row["from_user"], $row["msg"]);
        }
        if(count($tempArray) > 0){
            $massive_array[] = $tempArray;
        }
    }
    
    echo json_encode($massive_array);
}else{
    echo "Failed to find friends of current user :(";
}
?>
