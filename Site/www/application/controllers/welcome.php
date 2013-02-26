<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class Welcome extends Codez_Controller {

	/**
	 * Index Page for this controller.
	 *
	 * Maps to the following URL
	 * 		http://example.com/index.php/welcome
	 *	- or -  
	 * 		http://example.com/index.php/welcome/index
	 *	- or -
	 * Since this controller is set as the default controller in 
	 * config/routes.php, it's displayed at http://example.com/
	 *
	 * So any other public methods not prefixed with an underscore will
	 * map to /index.php/welcome/<method_name>
	 * @see http://codeigniter.com/user_guide/general/urls.html
	 */
	public function index()
	{

		// head
 		$data['pageTitle'] = 'CodeZ > Bienvenue !';

		if($this->session->userdata('isLogged') === TRUE){

			// body
			$data['bodyClass'] = 'home';

			// aside
			$data['sidebarContent'] = $this->load->view('aside_snippets_list', '', TRUE);

			// contenu principal
			$data['mainContent'] = $this->load->view('new_snippet_button', '', TRUE);

		}
		else {

			// body
			$data['bodyClass'] = 'welcome';

			// aside
			$data['sidebarContent'] = $this->load->view('aside_welcome', '', TRUE);

			// contenu principal
			$data['mainContent'] = $this->load->view('welcome_to_codez', '', TRUE);

		}

		// chargement dans le gabarit
		$this->load->view('template', $data);
	}
}

/* End of file welcome.php */
/* Location: ./application/controllers/welcome.php */