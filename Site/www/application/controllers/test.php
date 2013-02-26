<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class Test extends Codez_Controller {

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


    function __construct() {
        parent::__construct();
		
		
    }


	public function index()
	{
		echo 'hop';		

		$snippet = R::load('snippet', 1);
		$snippet2 = R::load('snippet', 4);

		echo '<pre>';
		// var_dump($snippet);
		var_dump($snippet2);
		echo '</pre>';

		echo $snippet2->category->name;
		


		// $snippet = R::dispense('snippet');
		// $snippet->content = 'blabla';
		// $snippet->name = 'Snippet2';
		// $snippet->pub_date = R::isoDateTime();
		// $snippet->author_id = 1;
		// $snippet->category_id = 2;
		// $id = R::store($snippet);





	}

	

		

	
}

/* End of file test.php */
/* Location: ./application/controllers/test.php */