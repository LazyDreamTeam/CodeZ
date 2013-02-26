<form action="snippet/add" method="POST" id="new-snippet" name="new-snippet">
	<div><?php echo validation_errors(); ?></div>
	<p class="ligneForm">
		<label for="snippetName"><?php echo lang("snippetName") ;?></label>
		<input type="text" id="snippetName" name="snippetName" required
			value="<?php echo set_value('snippetName') ;?>" />
	</p>
	<p class="ligneForm">
		<label for="snippetCat"><?php echo lang("snippetCat") ;?></label>
		<select id="snippetCat" name="snippetCat">
			<option value="newCat"><?php echo lang("newCat") ;?></option>
			<?php foreach($categories as $cat) : ?>
			<option value="<?php echo $cat['id'] ; ?>"><?php echo $cat['name'] ?></option>
			<?php endforeach ;?>
		</select>
		<input type="text" id="snippetCatNew" name="snippetCatNew" placeholder=""
			value="<?php echo set_value('snippetCatNew') ;?>" />
	</p>
	<p class="ligneForm">
		<label for="snippetLang"><?php echo lang('snippetLang') ; ?></label>
		<select id="snippetLang" name="snippetLang">
			<option value="newLang"><?php echo lang('newLang') ;?></option>
			<?php foreach($languages as $lang) : ?>
			<option value="<?php echo $lang['id'] ; ?>"><?php echo $lang['name'] ?></option>
			<?php endforeach ;?>
		</select>
		<input type="text" id="snippetLangNew" name="snippetLangNew" placeholder=""
			value="<?php echo set_value('snippetLangNew') ;?>" />
	</p>
	<p class="ligneForm">
		<label for="snippetContent"><?php echo lang('snippetContent') ; ?></label>
		<textarea id="snippetContent" name="snippetContent" required><?php echo set_value('snippetContent') ;?></textarea>
	</p>
	<input type="submit" class="button" value="Envoyer" />
</form>