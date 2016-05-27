<!-- for IE 8 show just the rendered node, which contains a link to download the podcast file -->
<!-- for IE 9 show a simple audio element followed by the rendered node -->
<!-- for IE 10+ and any other browser, show the html5 player, with the rendered node inside the audio tag as a fallback -->

<!--[if IE 9]>
<audio src="<?php print $file_url; ?>" controls></audio>
<![endif]-->

<!-- IE10+ ignore IE conditional comments, so the following conditional just hides the HTML5 player from the older versions of IE with special cases above -->
<!--[if !IE]><!-->
<audio id="podlove-inject-<?php print $player_id; ?>" class="podlove-player-src">
  <source src="<?php print $file_url; ?>" type="audio/mpeg" />
<!--<![endif]-->

  <?php print $content; ?>

<!-- IE10+ ignore IE conditional comments, so the following conditional just hides the HTML5 player from the older versions of IE with special cases above -->
<!--[if !IE]><!-->
</audio>
<script>
  var pwp_metadata = pwp_metadata || {};
  pwp_metadata["podlove-inject-<?php print $player_id; ?>"] = <?php print $options_json; ?>;
</script>
<!--<![endif]-->