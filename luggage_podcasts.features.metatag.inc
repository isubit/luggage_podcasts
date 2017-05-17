<?php
/**
 * @file
 * luggage_podcasts.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function luggage_podcasts_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:podcast.
  $config['node:podcast'] = array(
    'instance' => 'node:podcast',
    'config' => array(
      'description' => array(
        'value' => '[node:field-podcast-description:summary]',
      ),
    ),
  );

  return $config;
}
