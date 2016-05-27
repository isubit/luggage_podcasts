<?php
/**
 * @file
 * luggage_podcasts.multifield.inc
 */

/**
 * Implements hook_multifield_default_multifield().
 */
function luggage_podcasts_multifield_default_multifield() {
  $export = array();

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->api_version = 1;
  $multifield->machine_name = 'podcast_chapters';
  $multifield->label = 'Chapters';
  $multifield->description = '';
  $export['podcast_chapters'] = $multifield;

  return $export;
}
