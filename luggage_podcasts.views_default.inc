<?php
/**
 * @file
 * luggage_podcasts.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function luggage_podcasts_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'luggage_podcasts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Podcasts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'podcast' => 'podcast',
  );

  /* Display: Page (Full Player Top) */
  $handler = $view->new_display('attachment', 'Page (Full Player Top)', 'show_page_top');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'show_page' => 'show_page',
    'default' => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'show_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '%1';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'node';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Season */
  $handler->display->display_options['fields']['field_podcast_season']['id'] = 'field_podcast_season';
  $handler->display->display_options['fields']['field_podcast_season']['table'] = 'field_data_field_podcast_season';
  $handler->display->display_options['fields']['field_podcast_season']['field'] = 'field_podcast_season';
  $handler->display->display_options['fields']['field_podcast_season']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_season']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_season']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_season']['alter']['text'] = 'S[field_podcast_season-value]:';
  $handler->display->display_options['fields']['field_podcast_season']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_podcast_season']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_podcast_season']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Episode */
  $handler->display->display_options['fields']['field_podcast_episode']['id'] = 'field_podcast_episode';
  $handler->display->display_options['fields']['field_podcast_episode']['table'] = 'field_data_field_podcast_episode';
  $handler->display->display_options['fields']['field_podcast_episode']['field'] = 'field_podcast_episode';
  $handler->display->display_options['fields']['field_podcast_episode']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_episode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_episode']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_episode']['alter']['text'] = 'E[field_podcast_episode]';
  $handler->display->display_options['fields']['field_podcast_episode']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_podcast_episode']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_podcast_episode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '([field_podcast_season][field_podcast_episode]): [title]';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'node-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_podcast_description']['id'] = 'field_podcast_description';
  $handler->display->display_options['fields']['field_podcast_description']['table'] = 'field_data_field_podcast_description';
  $handler->display->display_options['fields']['field_podcast_description']['field'] = 'field_podcast_description';
  $handler->display->display_options['fields']['field_podcast_description']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Show (field_podcast_show) */
  $handler->display->display_options['arguments']['field_podcast_show_tid']['id'] = 'field_podcast_show_tid';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['table'] = 'field_data_field_podcast_show';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['field'] = 'field_podcast_show_tid';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['field_podcast_show_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_podcast_show_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['validate_options']['vocabularies'] = array(
    'podcast_show' => 'podcast_show',
  );
  $handler->display->display_options['arguments']['field_podcast_show_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['path'] = 'podcasts/%';

  /* Display: iTunes Feed */
  $handler = $view->new_display('feed', 'iTunes Feed', 'itunes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '%1';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss_fields';
  $handler->display->display_options['style_options']['channel'] = array(
    'core' => array(
      'views_rss_core' => array(
        'title' => 'name',
        'description' => 'description',
        'language' => '',
        'category' => 'field_show_itunes_category',
        'image' => 'field_show_logo_rss',
        'copyright' => 'field_show_copyright',
        'managingEditor' => '',
        'webMaster' => '',
        'generator' => '',
        'docs' => '',
        'cloud' => '',
        'ttl' => '',
        'skipHours' => '',
        'skipDays' => '',
      ),
    ),
    'itunes' => array(
      'views_rss_itunes' => array(
        'subtitle' => '',
        'summary' => 'description',
        'category' => 'field_show_itunes_category',
        'keywords' => '',
        'image' => 'field_show_logo',
        'author' => 'field_show_author_name',
        'explicit' => 'field_show_itunes_explicit',
        'block' => '',
        'complete' => '',
        'new-feed-url' => '',
        'owner' => 'field_show_itunes_owner',
      ),
    ),
  );
  $handler->display->display_options['style_options']['item'] = array(
    'core' => array(
      'views_rss_core' => array(
        'title' => 'title',
        'link' => 'path',
        'description' => 'field_podcast_description',
        'author' => 'field_show_author_name',
        'category' => 'term_node_tid',
        'comments' => '',
        'enclosure' => 'field_podcast_file',
        'guid' => 'path',
        'pubDate' => 'created',
      ),
    ),
    'itunes' => array(
      'views_rss_itunes' => array(
        'subtitle' => 'title',
        'summary' => '',
        'duration' => 'field_podcast_file_1',
        'keywords' => '',
        'image' => '',
        'author' => 'field_show_author_name',
        'isClosedCaptioned' => '',
        'explicit' => 'field_show_itunes_explicit',
        'block' => '',
        'order' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['feed_settings'] = array(
    'absolute_paths' => 1,
    'feed_in_links' => 0,
  );
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Show (field_podcast_show) */
  $handler->display->display_options['relationships']['field_podcast_show_tid']['id'] = 'field_podcast_show_tid';
  $handler->display->display_options['relationships']['field_podcast_show_tid']['table'] = 'field_data_field_podcast_show';
  $handler->display->display_options['relationships']['field_podcast_show_tid']['field'] = 'field_podcast_show_tid';
  $handler->display->display_options['relationships']['field_podcast_show_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Season */
  $handler->display->display_options['fields']['field_podcast_season']['id'] = 'field_podcast_season';
  $handler->display->display_options['fields']['field_podcast_season']['table'] = 'field_data_field_podcast_season';
  $handler->display->display_options['fields']['field_podcast_season']['field'] = 'field_podcast_season';
  $handler->display->display_options['fields']['field_podcast_season']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_season']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_season']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_season']['alter']['text'] = 'S[field_podcast_season-value]:';
  $handler->display->display_options['fields']['field_podcast_season']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_podcast_season']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_season']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_podcast_season']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Episode */
  $handler->display->display_options['fields']['field_podcast_episode']['id'] = 'field_podcast_episode';
  $handler->display->display_options['fields']['field_podcast_episode']['table'] = 'field_data_field_podcast_episode';
  $handler->display->display_options['fields']['field_podcast_episode']['field'] = 'field_podcast_episode';
  $handler->display->display_options['fields']['field_podcast_episode']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_episode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_episode']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_episode']['alter']['text'] = 'E[field_podcast_episode-value]';
  $handler->display->display_options['fields']['field_podcast_episode']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_podcast_episode']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_episode']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_podcast_episode']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: item:title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'item:title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '([field_podcast_season][field_podcast_episode]): [title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: item:description */
  $handler->display->display_options['fields']['field_podcast_description']['id'] = 'field_podcast_description';
  $handler->display->display_options['fields']['field_podcast_description']['table'] = 'field_data_field_podcast_description';
  $handler->display->display_options['fields']['field_podcast_description']['field'] = 'field_podcast_description';
  $handler->display->display_options['fields']['field_podcast_description']['ui_name'] = 'item:description';
  $handler->display->display_options['fields']['field_podcast_description']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_podcast_description']['type'] = 'text_plain';
  /* Field: item:enclosure */
  $handler->display->display_options['fields']['field_podcast_file']['id'] = 'field_podcast_file';
  $handler->display->display_options['fields']['field_podcast_file']['table'] = 'field_data_field_podcast_file';
  $handler->display->display_options['fields']['field_podcast_file']['field'] = 'field_podcast_file';
  $handler->display->display_options['fields']['field_podcast_file']['ui_name'] = 'item:enclosure';
  $handler->display->display_options['fields']['field_podcast_file']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_podcast_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_podcast_file']['type'] = 'enclosure';
  /* Field: item:link */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['ui_name'] = 'item:link';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: item:category */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['ui_name'] = 'item:category';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['type'] = 'rss_category';
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'category' => 'category',
    'tags' => 'tags',
    'views_rss_itunes_category' => 0,
    'podcast_show' => 0,
  );
  $handler->display->display_options['fields']['term_node_tid']['rss_domain'] = 'alias';
  /* Field: item:pubDate */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['ui_name'] = 'item:pubDate';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'r';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: item:itunes:duration */
  $handler->display->display_options['fields']['field_podcast_file_1']['id'] = 'field_podcast_file_1';
  $handler->display->display_options['fields']['field_podcast_file_1']['table'] = 'field_data_field_podcast_file';
  $handler->display->display_options['fields']['field_podcast_file_1']['field'] = 'field_podcast_file';
  $handler->display->display_options['fields']['field_podcast_file_1']['ui_name'] = 'item:itunes:duration';
  $handler->display->display_options['fields']['field_podcast_file_1']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_file_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_podcast_file_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_podcast_file_1']['type'] = 'itunes:duration';
  /* Field: item:author */
  $handler->display->display_options['fields']['field_show_author_name']['id'] = 'field_show_author_name';
  $handler->display->display_options['fields']['field_show_author_name']['table'] = 'field_data_field_show_author_name';
  $handler->display->display_options['fields']['field_show_author_name']['field'] = 'field_show_author_name';
  $handler->display->display_options['fields']['field_show_author_name']['relationship'] = 'field_podcast_show_tid';
  $handler->display->display_options['fields']['field_show_author_name']['ui_name'] = 'item:author';
  $handler->display->display_options['fields']['field_show_author_name']['label'] = '';
  $handler->display->display_options['fields']['field_show_author_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_show_author_name']['type'] = 'text_plain';
  /* Field: item:itunes:explicit */
  $handler->display->display_options['fields']['field_show_itunes_explicit']['id'] = 'field_show_itunes_explicit';
  $handler->display->display_options['fields']['field_show_itunes_explicit']['table'] = 'field_data_field_show_itunes_explicit';
  $handler->display->display_options['fields']['field_show_itunes_explicit']['field'] = 'field_show_itunes_explicit';
  $handler->display->display_options['fields']['field_show_itunes_explicit']['relationship'] = 'field_podcast_show_tid';
  $handler->display->display_options['fields']['field_show_itunes_explicit']['ui_name'] = 'item:itunes:explicit';
  $handler->display->display_options['fields']['field_show_itunes_explicit']['label'] = '';
  $handler->display->display_options['fields']['field_show_itunes_explicit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_show_itunes_explicit']['type'] = 'list_key';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Show (field_podcast_show) */
  $handler->display->display_options['arguments']['field_podcast_show_tid']['id'] = 'field_podcast_show_tid';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['table'] = 'field_data_field_podcast_show';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['field'] = 'field_podcast_show_tid';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['field_podcast_show_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_podcast_show_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['validate_options']['vocabularies'] = array(
    'podcast_show' => 'podcast_show',
  );
  $handler->display->display_options['arguments']['field_podcast_show_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_podcast_show_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['path'] = 'podcasts/%/rss.xml';
  $handler->display->display_options['displays'] = array(
    'show_page' => 'show_page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $export['luggage_podcasts'] = $view;

  return $export;
}
