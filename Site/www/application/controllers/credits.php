<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

/**
 * Fausse classe, création du contrôleur pour la page de crédits
 * @author AkaiKen
 */
class Credits extends Codez_Controller {

	function index(){
		// head
 		$data['pageTitle'] = 'Connexion à CodeZ';

		// body
		$data['bodyClass'] = 'connexion';

		// aside
		$data['sidebarContent'] = $this->load->view('aside_welcome', '', TRUE); // devra varier suivant si l'on
		// est connecté ou non @TODO
		
		$data['mainContent'] = $this->load->view('credits', '', TRUE);

		// chargement dans le gabarit
		$this->load->view('template', $data);

	}
}