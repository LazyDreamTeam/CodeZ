<!doctype html>
<!--[if lt IE 7]> <html class="no-js lt-ie9 lt-ie8 lt-ie7" lang="fr"> <![endif]-->
<!--[if IE 7]>    <html class="no-js lt-ie9 lt-ie8" lang="fr"> <![endif]-->
<!--[if IE 8]>    <html class="no-js lt-ie9" lang="fr"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js" lang="fr"> <!--<![endif]-->
<head>
  <meta charset="utf-8">
  <!-- <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" /> -->
  <title><?php echo isset($pageTitle) ? $pageTitle : lang('defautTitle') ; ?></title>
  <meta name="description" content="<?php echo isset($pageDescription) ? $pageDescription : lang('siteDescription'); ?>">
  <base href="<?php echo base_url() ; ?>" />
  <meta name="viewport" content="width=device-width" />

  <!-- favicons -->
  <!-- pour les navigateurs normaux -->
  <link rel="icon" href="favicon.ico" type="image/ico" />
  <!-- For third-generation iPad with high-resolution Retina display: -->
  <link rel="apple-touch-icon-precomposed" sizes="144x144" href="apple-touch-icon-144x144-precomposed.png">
  <!-- For iPhone with high-resolution Retina display: -->
  <link rel="apple-touch-icon-precomposed" sizes="114x114" href="apple-touch-icon-114x114-precomposed.png">
  <!-- For first- and second-generation iPad: -->
  <link rel="apple-touch-icon-precomposed" sizes="72x72" href="apple-touch-icon-72x72-precomposed.png">
  <!-- For non-Retina iPhone, iPod Touch, and Android 2.1+ devices: -->
  <link rel="apple-touch-icon-precomposed" href="apple-touch-icon-precomposed.png">
  <?php // note interne : font ch..., les iTrucs, sérieux ; ?>

  <?php $this->carabiner->display('css'); ?>

  <!--<script src="js/libs/modernizr-2.5.3.min.js"></script>-->
</head>
<body class="<?php echo $bodyClass ; ?>">
  <!--[if lt IE 7]><p class=chromeframe>Your browser is <em>ancient!</em> 
  <a href="http://browsehappy.com/">Upgrade to a different browser</a> to experience this site.</p><![endif]-->
  <?php // note interne : à traduire et styler ;?>
  <section class="sidebar" role="complementary">
    <div class="sidebar-wrapper">
      <div class="sidebar-content">
      <header>
        <!-- logo --><!-- markup pas très satisfaisant -->
        <h1 class="">
          <a href="index.php">
            <img src="assets/img/spritesheet.png" alt="CodeZ" />
          </a>
        </h1>
      </header>
      <?php $isLogged = $this->session->userdata('isLogged');
      if ($isLogged === TRUE) : ?>
      <div class="user-account" itemtype="http://microformats.org/profile/hcard" itemscope>
        <img 
          src="../www/assets/img/avatar-default.png" 
          alt="avatar de <?php echo $this->session->userdata('userName') ; ?>" 
          itemprop="photo" 
          height="39"
          width="39"
        />
        <span class="user-account-name" itemprop="fn"><?php echo $this->session->userdata('userName') ; ?></span>
        <div class="user-account-options">
          <span class="button">Options</span>
          <ul>
          <?php if($this->session->userdata('userType') === 'admin') : ?>
            <li><a href="admin">Admin</a></li>
          <?php endif; ?>
            <li>Paramètres</li>
            <li>Messages</li>
            <li><a href="connect/deconnexion">Déconnexion</a></li>
          </ul>
        </div>
      </div>
       
      <? else : ?>
      <div class="connexion">
        <a href="connect" id="connexion" class="button">Connexion au site</a>
      </div>
    <?php endif ; ?>
      <aside>
        <?php echo isset($sidebarContent) ? $sidebarContent : '' ; ?>
      </aside>
    </div>
    <footer>
      <p><a href="credits">Crédits et remerciements</a></p>
    </footer>
    </div>
  </section>
  <section class="main" role="main">
      <?php echo $mainContent ; ?>
  </section>
 
  <!--<script src="//ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>
  <script>window.jQuery || document.write('<script src="js/libs/jquery-1.7.1.min.js"><\/script>')</script>
  <script src="js/plugins.js"></script>
  <script src="js/script.js"></script>-->
  <?php $this->carabiner->display('js'); ?>
</body>
</html>