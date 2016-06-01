<article<?php print $attributes; ?>>

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

  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted): ?>
  <footer class="submitted"><?php print $submitted; ?></footer>
  <?php endif; ?>  
  
  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments, links, and sharethis now so that we can render them later.
      if (isset($content['sharethis'])) {
        hide($content['sharethis']);
      }
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

  <!-- IE10+ ignore IE conditional comments, so the following conditional just hides the HTML5 player from the older versions of IE with special cases above -->
  <!--[if !IE]><!-->
  </audio>
  <script>
    var pwp_metadata = pwp_metadata || {};
    pwp_metadata["podlove-inject-<?php print $player_id; ?>"] = <?php print $options_json; ?>;
  </script>
  <!--<![endif]-->

  <?php
    if (isset($content['sharethis'])) {
      print render($content['sharethis']);
    }
  ?>

  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>
</article>
