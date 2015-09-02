<?php
//Register 2 more menu items ‘detective/add’ ‘detective/<detective_id>’. 
//For time being, just make dummy callback that returns some text. 
//Set access parameters such that users with ‘add detective’ permissions can access detective/add and 
//with ‘view detective’ can access detective/<detective_id>.
// create menu item for detective module
function detective_menu() {
  $items = array();  

  $items['detective'] = array(
    'title'             => 'World of Detectives',
    'description'       => 'Detective Info',
    'page callback'     => 'detective_landing',
    'access callback'   => true,
  );
  $items['detective/add'] = array(
      'title'             => 'Add New Detective',
      'description'       => 'Add new detective information',
      'access callback'   => 'access_detective_add',
      'page callback'     => 'detective_new',
      'access arguments' => array('Add Detective'),
  );
  $items['detective/view/%'] = array(
    'title' => 'View Detective',
    'description' => 'View detective',
    'access callback'   => 'access_detective_view',
    'page callback' => 'detective_view',
    'access arguments' => array('View Detective'),
  );

  return $items;
}

//permission hook
function detective_permission() {

    $items = array(
    'view detective' => array(
        'title' => 'View Detective',
        'description' => 'Allow users to view detective pages/links',
    ),
    'add detective' => array(
        'title' => 'Add Detective',
        'description' => 'Allow users to add detective',
    ),
  );

    return $items;
}

function access_detective_add() {
    global $user;

    $text = "gmail.com";
    if (user_access('add detective') && strpos($user->mail,$text) !== false) {
       return true;
  }
}
function access_detective_view() {
    global $user;  
    if (user_access('view detective')  && $user->uid != 3) {
        return true;
  }
}
