<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="content-type" content="text/html;charset=utf-8" />
<style type="text/css">
	
	body{
		font-family:Verdana;
		font-size:11px;
	}
	.initialColoration{

	}
	.coloration{
		padding:10px;
		float:left;
		list-style-type: none;
	}
	.coloration textarea{
		height: 222px;
		width: 192px;
	}
	.coloration #color{
		border:1px solid #cecece;
		border-right:15px solid #cecece;
	}

	.clear{
		clear:both;
	}

	.noList{
		list-style-type: none;
	}

	.hidden{
		display:none;
	}

</style>
<script type="text/javascript" src="jquery.js"></script>
<script type="text/javascript">
	idColoration = 0;

	function deleteColoration(colorationId){
		$('#coloration_'+colorationId).remove();
	}

	function addColoration(colorationJson){


		var coloration = $('#colorationModel').clone();
		coloration.insertBefore('#colorationHorizon');
		$(coloration).attr('id',"coloration_"+idColoration);
		$(coloration).removeClass('hidden');

		$('.deleteColoration',coloration).attr('onclick','deleteColoration('+idColoration+')');

		$('input,textarea',coloration).each(function(){
			$(this).attr('id',$(this).attr('id').replace('-0','_'+idColoration));
			$(this).attr('onclick','previewColoration('+idColoration+');');
			$(this).attr('name',$(this).attr('name').replace('-0','_'+idColoration));
		});


		if(colorationJson!=null){

			$('input[name^="color_"]',coloration).val(colorationJson.color);
			if(colorationJson.underline) $('input[name^="underline_"]',coloration).attr('checked','checked');
			if(colorationJson.italic) $('input[name^="italic_"]',coloration).attr('checked','checked');
			if(colorationJson.bold) $('input[name^="bold_"]',coloration).attr('checked','checked');
			if(colorationJson.strike) $('input[name^="strike_"]',coloration).attr('checked','checked');

			$('textarea[name^="expressions_"]',coloration).val(colorationJson.values.join('\n'));
			previewColoration(idColoration);
		}

		idColoration++;


	}

	function previewColoration(colorationId){

		var elem = $('#coloration_'+colorationId);
		var example = $('#coloration_'+colorationId+' span');

		if($('input[name^="bold"]:checked',elem).length!=0){
			example.css('font-weight','bold');
		}else{
			example.css('font-weight','normal');
		}
		if($('input[name^="italic"]:checked',elem).length!=0){
			example.css('font-style','italic');
		}else{
			example.css('font-style','normal');
		}
		
		if($('input[name^="underline"]:checked',elem).length!=0){
			example.css('text-decoration','underline');
		}else if($('input[name^="strike"]:checked',elem).length!=0){
			example.css('text-decoration','line-through');
		}else{
			example.css('text-decoration','none');
		}
		example.css('color',$('input[name^="color"]',elem).val());
		$('input[name^="color"]',elem).css('border-color',$('input[name^="color"]',elem).val());
	}



</script>
</head>
<body>
<?php

ini_set('error_reporting', 'E_ALL & ~E_DEPRECATED');
//var_dump(json_decode(file_get_contents('php.lang')));
if(isset($_POST['buttonGenerate'])){

$value['name'] = $_POST['name'];
$value['author'] = $_POST['author'];
$value['pubdate'] = time();
$value['version'] = $_POST['version'];
$value['linkSheet'] = $_POST['linkSheet'];
$value['comment'] = $_POST['comment']; 

$colorations = array();
foreach($_POST as $key=>$val){
	$col = explode('_',$key);
	if(count($col)==2){
	
		if(!isset($value['colorations'][$col[1]]['italic']))$value['colorations'][$col[1]]['italic'] = false;
		if(!isset($value['colorations'][$col[1]]['strike']))$value['colorations'][$col[1]]['strike'] = false;
		if(!isset($value['colorations'][$col[1]]['underline']))$value['colorations'][$col[1]]['underline'] = false;
		if(!isset($value['colorations'][$col[1]]['bold']))$value['colorations'][$col[1]]['bold'] = false;
		
		switch($col[0]){
			case 'italic':
			case 'bold':
			case 'strike':
			case 'underline':
				$value['colorations'][$col[1]][$col[0]] = ($val=='on'?true:false);
			break;
			case 'color':
				$value['colorations'][$col[1]]['color'] = hex2rgb($val);
			break;
			case 'expressions':
			
				$value['colorations'][$col[1]]['values'] = explode("\r\n",$val);
			break;
			default:
				$value['colorations'][$col[1]][$col[0]] = $val;
			break;
		}
	}
}

$out = json_encode($value);
file_put_contents($_POST['fileName'], $out);

}

if(isset($_POST['openFile'])){
	$decode = json_decode(file_get_contents($_POST['openFile']));
}

?>

<form method="POST" name="openFileForm" action="index.php">
	Ouvrir un langage <select onchange="openFileForm.submit();" name="openFile">
		<option value="-">-</option>
		<?php 
			$files = scandir('./');
			foreach($files as $file){
				if(is_file($file) && strpos($file,'.lang')!==false){
					?><option value="<?php echo $file ?>"><?php echo $file ?></option><?php
				}
			}
		?>
		
	</select>
</form>

<form method="POST" action="index.php">

<h1>Infos g&eacute;n&eacute;rales</h1>
<ul>
	<li>
		<label for="name">Nom du fichier : </label><input id="name" name="fileName" value="<?php echo $_POST['openFile']; ?>" type="text">
	</li>
	<li>
		<label for="name">Nom : </label><input id="name" name="name" value="<?php echo $decode->name; ?>" type="text">
	</li>
	<li>
		<label for="author">Auteur : </label><input id="author" value="<?php echo $decode->author; ?>" name="author" type="text">
	</li>
	<li>
		<label for="version">Version : </label><input id="version" value="<?php echo $decode->version; ?>" name="version" type="text">
	</li>
	<li>
		<label for="linkSheet">Lien : </label><input id="linkSheet" value="<?php echo $decode->linkSheet; ?>" name="linkSheet" type="text">
	</li>
	<li>
		<label for="comment">Commentaire</label><br/><textarea id="comment" name="comment"><?php echo $decode->comment; ?></textarea>
	</li>
</ul>
<h1>Colorations</h1>

<script type="text/javascript">
	$(document).ready(function(){
	<?php 
	if(isset($decode->colorations) && count($decode->colorations)>0){
		foreach($decode->colorations as $coloration){
			$coloration->color = rgb2hex($coloration->color);
			?>
addColoration(<?php echo json_encode($coloration); ?>);
			<?php
		}
	} 
	?>
	});
</script>
<ul>

	<li class="coloration hidden" id="colorationModel"> 
		<div class="deleteColoration" onclick="deleteColoration(0)">x</div>
		<ul>
			<li>
				<label for="example">Exemple : </label><span>Mise en forme</span>
			</li>
			<li>
				<label for="color">Couleur : </label><input onkeyup="previewColoration(0);" id="color" name="color-0" type="text">
			</li>
			<li>
				<ul>
					<li><label for="strike">Barr&eacute; : </label><input onclick="previewColoration(0);" id="strike" name="strike-0" type="checkbox"></li>
					<li><label for="underline">Soulign&eacute; : </label><input onclick="previewColoration(0);" id="underline" name="underline-0" type="checkbox"></li>
					<li><label for="italic">Italique : </label><input onclick="previewColoration(0);" id="italic" name="italic-0" type="checkbox"></li>
					<li><label for="bold">Gras : </label><input onclick="previewColoration(0);" id="bold" name="bold-0" type="checkbox"></li>
				</ul>
			</li>
			<li>
				<label for="expressions">Expressions : </label><br/><textarea id="expressions" name="expressions-0"></textarea>
			</li>
		</ul>
	</li>




	<li class="clear noList" id="colorationHorizon"></li>
</ul>

<div onclick="addColoration();">+ Coloration</div>
<input type="submit" name="buttonGenerate" value="Generer">
</form>
</body>
</html>


<?php 


function hex2rgb($hex){ 
  $hex = substr($hex,1);
  if(! ereg("[0-9a-fA-F]{6}", $hex)) { 
  echo "Error : input is not a valid hexadecimal number :".$hex; 
  return 0; 
  } 
  
  for($i=0; $i<3; $i++) { 
  $temp = substr($hex, 2*$i, 2); 
  $rgb[$i] = 16 * hexdec(substr($temp, 0, 1)) + 
  hexdec(substr($temp, 1, 1)); 
  } 
  
  return implode(',',$rgb); 
} 


function rgb2hex($rgb)
{
	list($r, $g, $b) = explode(',',$rgb);

	if (is_array($r) && sizeof($r) == 3)
	list($r, $g, $b) = $r;

	$r = intval($r); $g = intval($g);
	$b = intval($b);

	$r = dechex(($r<0?0:($r>255?255:$r)));
	$g = dechex(($g<0?0:($g>255?255:$g)));
	$b = dechex(($b<0?0:($b>255?255:$b)));

	$color = (strlen($r) < 2?'0':'').$r;
	$color .= (strlen($g) < 2?'0':'').$g;
	$color .= (strlen($b) < 2?'0':'').$b;
	return '#'.$color;
} 

?>