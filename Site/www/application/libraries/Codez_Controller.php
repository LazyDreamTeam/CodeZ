<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

/**
 * classe étendue de Controller 
 * qui permet d'ajouter des fonctions au demarrage de chaque page
 */
class Codez_Controller extends CI_Controller {

	function __construct() {
        parent::__construct();

        /** Carabiner : minification+combinaison de js et css **/
		$this->load->library('carabiner');
		$carabiner_config = array(
		    'script_dir' => 'assets/js/', 
		    'style_dir'  => 'assets/css/',
		    'cache_dir'  => 'assets/cache/',
		    'minify_js'  => FALSE,
		    'minify_css' => FALSE,
		    'combine'    => FALSE
		);

		// ajoutons quelques fichiers css
		$this->carabiner->css('normalize.css');
		$this->carabiner->css('layout.css');
		$this->carabiner->css('forms.css');
		$this->carabiner->css('style.css');
		$this->carabiner->css('utils.css');

		$this->carabiner->config($carabiner_config);

		$this->carabiner->empty_cache('both', 'yesterday');

		/** RedBean : ORM automagique **/
		// DOIT être à true en prod ! IMPORTANT !!!!1!!1
		R::freeze( TRUE );

		/** Validation de formulaires **/
		// m'a forcé à autoloader form_validation, j'aime pas, mais bon
		// on aura des formulaires partout, alors ça sert
		$this->form_validation->set_error_delimiters('<p class="error">', '</p>');
	}


}