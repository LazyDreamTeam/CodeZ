<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

/**
* Classe servant de controleur principal pour les snippets
* @author : AkaiKen
*/
class Snippet extends Codez_Controller {

	function __construct() {
    	parent::__construct();

    	/* l'accès aux snippets ne peut se faire qu'une fois connecté */
    	if( $this->session->userdata('isLogged') !== TRUE){
    		redirect('/');
    	}
    }

	function index(){
		/* statuer : qu'affiche-t-on ? le(s) dernier(s) snippet(s) ? juste un bouton "créer" ? */
	}

	function add(){

		$this->load->helper(array('form', 'url'));
		$this->load->library('form_validation');
		$this->load->model('snippet_model');

		// var_dump($this->input->post());	die();

		/* préparation des règles de formulaire */
		$this->form_validation->set_rules('snippetName', 'lang:snippetName', 'required');
		$this->form_validation->set_rules('snippetContent', 'lang:snippetContent', 'required');
		if($this->input->post('snippetCat') === 'newCat') {
			$this->form_validation->set_rules('snippetCatNew', 'lang:snippetCatNew', 'required');
		}
		if($this->input->post('snippetLang') === 'newLang') {
			$this->form_validation->set_rules('snippetLangNew', 'lang:snippetLangNew', 'required');
		}

		// récupération des catégories existantes
		$dataMain['categories'] = $this->snippet_model->getAllCategories();
		// et des langages existants
		$dataMain['languages'] = $this->snippet_model->getAllLanguages();

		// AFFICHAGE (préparation)
		// head
 		$data['pageTitle'] = 'Créer un nouveau snippet > CodeZ';
 		// body
		$data['bodyClass'] = 'snippet add';
		// aside
		$data['sidebarContent'] = $this->load->view('aside_snippets_list', '', TRUE);

		// si le formulaire n'a pas été lancé OU que les vérifs de validation
		// sont fausses
		if ($this->form_validation->run() === FALSE) {
			// contenu principal
			$data['mainContent'] = $this->load->view('new_snippet_create', $dataMain, TRUE);
			// chargement dans le gabarit
			$this->load->view('template', $data);
		}
		else {
			// traitement du formulaire
			$userID = $this->session->userdata('userID');
			// 1) la catégorie existe-t-elle ? si non, on la crée !
			if($this->input->post('snippetCatNew', TRUE) !== ''){
				$this->load->model('category_model');
				// d'abord on vérifie l'existence d'une catégorie de ce nom
				// pour cet utilisateur
				// si elle existe, on ne crée pas de catégorie
				$categoryExists = $this->category_model->getCategory($this->input->post('snippetCatNew', TRUE),$userID);
				// var_dump($existingCategoryID);die();
				if($categoryExists !== NULL) {
					$category = $categoryExists->id;
				}
				else {
					$category = $this->category_model
            		->createNewCategory($this->input->post('snippetCatNew', TRUE),"",$userID);
				}
        	}
        	else {
        		$category = $this->input->post('snippetCat', TRUE);
        	}

			// 2) le langage existe-t-il ? si non, on le crée !
			

			// 3) on a tout, hop, on insère
			 
			//$this->snippet_model->insertNewSnippet($author,$category,$language,$name,$content,$pubDate);
		}

		

	}
}