<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class Snippet_model extends CI_Model {

	function __construct()
    {
        // Call the Model constructor
        parent::__construct();
    }

    function getAllCategories(){
    	return R::findAll('category');
    }

    function getAllLanguages(){
    	return R::findAll('language');
    }

    /**
     * [insertNewSnippet description]
     * @param  [type] $bigArrayFromForm [description]
     * @return [type]                   [description]
     */
    function insertNewSnippet($formData){
    	var_dump($formData);

    	$newSnippet = R::dispense('snippet');
        $newSnippet->author_id = $this->session->userdata('userID'); // utilisateur connecté
        if($formData['snippetCatNew'] !== ''){
            $newCat = '';
        }
        $newSnippet->category_id = ($formData['snippetCatNew'] !== '') ?
            $formData['snippetCatNew'] :
            $formData['snippetCat'];
        $newSnippet->language_id = ($formData['snippetLangNew'] !== '') ?
            $formData['snippetLangNew'] :
            $formData['snippetLang'];
        $newSnippet->name = $formData['snippetName'];
        $newSnippet->pub_date = R::isoDateTime();

        R::store($newSnippet);

    }

}