<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class User_model extends CI_Model {

	function __construct()
    {
        // Call the Model constructor
        parent::__construct();
    }

    /**
    * renvoie l'utilisateur de nom $username et de mot de passe $password
    * qui a activé son compte (à modifier, je pense)
    * (renvoie un array vide s'il ne trouve pas, cas possibles : utilisateur inexistant, ou 
    * mauvais mot de passe, ou pas activé)
    * @param string $username
    * @param string $password
    * @return object $user
   	*/
    function checkUserPassword($username,$password){

    	$haystack = array(
			':name' => $username, 
			':password' => sha1($password)
		);

    	$user = R::find(
			'user',
			'name = :name 
				AND password = :password
				AND state = "active"', 
            $haystack
        );

        return $user;
    }

    /**
    * enregistre effectivement l'utilisateur
    * @param string $username
    * @param string $password
    * @param string $email
    * @return object $newUser (contient notamment la clé de confirmation)
    */
    function registerUser($username,$password,$email){
		$newUser = R::dispense('user');
		$newUser->name = $username;
		$newUser->password = sha1($password);
		$newUser->e_mail = $email;
		$newUser->inscription_date = R::isoDateTime();
		$newUser->validation_key = sha1(microtime(TRUE)*100000);

		R::store($newUser);

		return $newUser;
    }

    /**
    * vérifie s'il y a bien un utilisateur avec ce $mail et ce $code de validation
    * @param string $mail
    * @param string $code
    * @return object $user
    */
    function checkUserKey($mail, $code){

    	$haystack = array(
			':mail' => $mail, 
			':code' => $code
		);

		$user = R::findOne(
			'user',
			'sha1(e_mail) = :mail AND validation_key = :code', 
            $haystack
        );

        return $user;
    }

    /**
	* confirme l'inscription de l'utilisateur
	* @param object $user
	* @return nothing
   	*/
    function confirmUserRegistration($user){
    	$user->state = 'active';
        R::store($user);
    }

     /**
	* vérifie l'existence d'un utilisateur de nom donné
	* @param string $name
	* @return object $user
   	*/
    function checkUsername($name){
    	$user = R::find(
			'user',
			'name = :name', 
            array('name' => $name)
        );

    	return $user;
    }

    /**
     * [getUserID description]
     * @param  string $name [description]
     * @return integer        [description]
     * à fusionner avec checkUserName ?
     */
    function getUserID($name){
        $user = R::findOne(
            'user',
            'name = :name', 
            array('name' => $name)
        );

        return $user->id;
    }
}