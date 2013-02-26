<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

/**
 * Classe gérant la connexion, l'inscription des utilisateurs (incluant mot de passe perdu @TODO)
 * @author AkaiKen
 */
class Connect extends Codez_Controller {

	function __construct() {
        parent::__construct();

        $this->load->helper(array('form', 'url'));

		$this->load->library('form_validation');
    }

	function index()
	{

 		// head
 		$data['pageTitle'] = 'Connexion à CodeZ';

		// body
		$data['bodyClass'] = 'connexion';

		// aside
		$data['sidebarContent'] = $this->load->view('aside_welcome', '', TRUE);

		// connexion
		if($this->input->post('connexion_submit')){
			$this->form_validation->set_rules('connexion_username', 'lang:connexion_username_short', 'required');
			$this->form_validation->set_rules('connexion_password', 'lang:password_short', 'required');
		}
		// inscription
		if($this->input->post('inscription_submit')){
			$this->form_validation->set_rules('inscription_username', 'lang:inscription_username_short', 'required');
			$this->form_validation->set_rules('inscription_password', 'lang:inscription_password_short', 'required|min_length[6]');
			$this->form_validation->set_rules('inscription_password_conf', 
				'lang:inscription_password_conf_short', 'required|matches[inscription_password]');
			$this->form_validation->set_rules('inscription_email', 'lang:inscription_email_short', 'required|valid_email');
		}

		// contenu principal
		// si le formulaire n'a pas été lancé OU que les vérifs de validation sont fausses
		if ($this -> form_validation->run() == FALSE) {
			$data['mainContent'] = $this->load->view('connexion', '', TRUE);
		}
		else {
			if($this->input->post('connexion_submit')){
				// on tente de connecter
				$connexion = $this->_connexion();
				// si _connexion renvoie quelque chose au lieu de mettre en session et rediriger :
				if($connexion === 0) {
					$dataForm['connectionError'] = lang('connectionError');
					$data['mainContent'] = $this->load->view('connexion', $dataForm, TRUE);
				}
			}
			else {
				if($this->input->post('inscription_submit')){
					$inscription = $this->_inscription();
					if($inscription === -2){
						$dataForm['inscriptionError'] = lang('userNameNotFree');
						$data['mainContent'] = $this->load->view('connexion', $dataForm, TRUE);
					}
					else {
						if($inscription === 1){
							$data['mainContent'] = $this->load->view('confirmation', '', TRUE);
						}
					}
				}
			}
		}

		// chargement dans le gabarit
		$this->load->view('template', $data);
	}

	function _connexion(){

		$this->load->model('user_model');

		// on extrait toutes les variables de la version CodeIgniter de $_POST (filtre XSS inside :3)
		extract($this->input->post(NULL, TRUE));

		$user = $this->user_model->checkUserPassword($connexion_username,$connexion_password);

		if($user !== array()){
			// ok, on a bien un utilisateur avec ce mot de passe
			// on connecte
			$userIsLogged = array(
				'isLogged' => TRUE,
				'userName' => $connexion_username,
				'userID' => $this->user_model->getUserID($connexion_username),
				'userType' => $user->user_type
				);
			$this->session->set_userdata($userIsLogged);
			
			// et on redirige vers l'accueil (ou autre, si AJAX, plus tard)
			redirect('/');
		}
		// sinon, on renvoie une erreur
		return 0;
	}

	function _inscription(){

		$this->load->model('user_model');

		// on extrait toutes les variables de la version CodeIgniter de $_POST (filtre XSS inside :3)
		extract($this->input->post(NULL, TRUE));

		// ce pseudo est-il déjà pris ? (TODO faire une vérif en AJAX plus tard)
		$userNameIsFree = $this->checkUsername($inscription_username);
		if($userNameIsFree){

			// azy, on t'inscrit !
			$newUser = $this->user_model->registerUser($inscription_username,$inscription_password,$inscription_email);

			if($newUser){
				$this->load->library('email');

				// TODO mettre un vrai expéditeur
				$this->email->from(CODEZ_E_MAIL_ADDRESS, 'L\'équipe CodeZ');
				$this->email->to($inscription_email);

				$this->email->subject('Validation Codez');

				$dataMail['userMail'] = sha1($newUser->e_mail);
				$dataMail['validationKey'] = $newUser->validation_key;
				$this->email->message($this->load->view('emails/confirmation_mail', $dataMail, TRUE));

				$this->email->send();

				return 1;

			}
			else{
				// on fait quoi si erreur ? les cas d'erreur seront
				// plus des fatal error renvoyées par sql, genre viol de contrainte d'intégrité
				// on peut faire quelque chose contre ça ?
				// @TODO voir dans RedBean comment attraper les exceptions
			}
		}
		else {
			return -2; // username déjà pris
		}
	}

	function confirmation(){

		$this->load->model('user_model');

		$mail = $this->uri->rsegment(3);
		$code = $this->uri->rsegment(4);

		$user = $this->user_model->checkUserKey($mail, $code);

        if($user !== NULL){
        	// la validation est bonne : on a bien un utilisateur avec cet e-mail, et
        	// cette clé de validation

        	$this->user_model->confirmUserRegistration($user); 

        	// on connecte l'utilisateur, allez, on lui doit bien ça
        	$userIsLogged = array(
				'isLogged' => TRUE,
				'userName' => $user->name
				);
			$this->session->set_userdata($userIsLogged);

			// et on repart vers l'accueil (on pourrait afficher un truc avant, peut-être ?)
			redirect('/');
        }
        else {
        	// la validation n'est pas bonne, on repart à l'accueil
        	redirect('/');
        }


	}

	/**
	* gestion de la réinitialisation de mot de passe TODO
	*/
	function password(){

	}

	/**
	* faut vraiment que j'explique =D ?
	*/
	function deconnexion(){
		$this->session->sess_destroy();
		redirect('/');
	}

	/**
	* on vérifie l'existence du nom d'utilisateur
	* but premier : signaler à l'utilisateur qui s'inscrit que le nom est déjà pris
	* pourquoi pas directement dans le modèle ? Pour pouvoir l'appeler en AJAX plus tard (on sait jamais)
	*/
	function checkUsername($name){
		
        $this->load->model('user_model');

        $user = $this->user_model->checkUsername($name);

        if($user !== array()){
        	return FALSE;
        }
        return TRUE;

	}


}

/* End of file connect.php */
/* Location: ./application/controllers/connect.php */