<div class="connexion-wrap">
	<p><?php echo lang('pourquoiSInscrire') ; ?></p>
	<form method="POST" action="connect" id="form-connexion">
		 <?php  //echo validation_errors(); ?>
		<h1>Connexion</h1>
		<h2>On se connaît ?</h2>
		<?php if(isset($connectionError)): ?>
			<p class="error"><?php echo $connectionError ; ?></p>
		<?php endif ;?>
		<?php //note : je sépare ici les erreurs de validation de formulaire car on a deux forms ?>
		<?php echo form_error('connexion_username'); ?>
		<?php echo form_error('connexion_password'); ?>
		<p class="ligneForm">
			<label for="connexion_username"><?php echo lang('connexion_username') ; ?></label>
			<input type="text" id="connexion_username" name="connexion_username" required
				<?php if(form_error('connexion_username') !== "") echo 'class="input-error"' ?>
				value="<?php echo set_value('connexion_username') ;?>" />
		</p>
		<p class="ligneForm">
			<label for="connexion_password"><?php echo lang('connexion_password') ; ?></label>
			<input type="password" id="connexion_password" name="connexion_password" required 
				<?php if(form_error('connexion_password') !== "") echo 'class="input-error"' ?>/>
		</p>
		<input type="submit" id="connexion_submit" name="connexion_submit" 
			class="button" value="<?php echo lang('connexion_submit') ; ?>" />
	</form>
	<form method="POST" action="connect" id="form-inscription">
		<h1>Inscription</h1>
		<h2>Vous voulez venir jouer ?</h2>
		<?php if(isset($inscriptionError)) : ?>
			<p class="error"><?php echo $inscriptionError ; ?></p>
		<?php endif; ?>
		<?php echo form_error('inscription_username'); ?>
		<?php echo form_error('inscription_password'); ?>
		<?php echo form_error('inscription_password_conf'); ?>
		<?php echo form_error('inscription_email'); ?>
		<p class="ligneForm">
			<label for="inscription_username"><?php echo lang('inscription_username') ; ?></label>
			<input type="text" id="inscription_username" name="inscription_username" required 
				<?php if(form_error('inscription_username') !== "") echo 'class="input-error"' ?>
				value="<?php echo set_value('inscription_username') ;?>" />
		</p>
		<p class="ligneForm">
			<label for="inscription_password"><?php echo lang('inscription_password') ; ?></label>
			<input type="password" id="inscription_password" name="inscription_password" required 
				<?php if(form_error('inscription_password') !== "") echo 'class="input-error"' ?> />
		</p>
		<p class="ligneForm">
			<label for="inscription_password_conf"><?php echo lang('inscription_password_conf') ; ?></label>
			<input type="password" id="inscription_password_conf" name="inscription_password_conf" required
				<?php if(form_error('inscription_password_conf') !== "") echo 'class="input-error"' ?> />
		</p>
		<p class="ligneForm">
			<label for="inscription_email"><?php echo lang('inscription_email') ; ?></label>
			<input type="email" id="inscription_email" name="inscription_email" required 
				<?php if(form_error('inscription_email') !== "") echo 'class="input-error"' ?>
				value="<?php echo set_value('inscription_email') ;?>" />
		</p>
		<input type="submit" id="inscription_submit" name="inscription_submit" 
			class="button" value="<?php echo lang('inscription_submit') ; ?>" />
	</form>
</div>