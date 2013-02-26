<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class Category_model extends CI_Model {

	/**
	 * crée une nouvelle catégorie
	 * @param  string $name        le nom de la catégorie
	 * @param  string $description la description (optionnelle)
	 * @return integer             l'id de la catégorie nouvellement créée
	 */
	function createNewCategory($name,$description="",$user){

	
		$newCat = R::dispense('category');
		$newCat->name = $name;
		$newCat->description = $description;
		$newCat->user_id = $user;
		$catId = R::store($newCat);

		return $catId;

	}

	function getCategory($name,$user){
		$haystack = array(
			':name' => $name, // à mettre en lowercase ?
			':user' => $user
		);

		return R::findOne('category', ' name = :name AND user_id = :user ', $haystack);
	}

}
