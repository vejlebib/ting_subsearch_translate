<?php

/**
 * @file
 * Configuration of module.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function ting_subsearch_translate_form_ting_admin_ting_settings_alter(&$form, &$form_state) {

  $facets = array();
  foreach (variable_get('ding_facetbrowser_facets', array()) as $facet) {
    $facets[] = $facet['name'];
  }

  if (!in_array('facet.genreCategory', $facets)) {
    drupal_set_message(
      t(
        'Translated search requires !facet. Please insert on !adminpage',
        array(
          '!facet' => 'facet.genreCategory',
          '!adminpage' => l(
            t('Configure facets'),
            'admin/config/ting/facets'
          ),
        )
      ),
      'warning'
    );
  }

  $form['subsearch_settings']['subsearch_translation']['#type'] = 'fieldset';
  $form['subsearch_settings']['subsearch_translation']['#title'] = t('Translation Settings');
  $form['subsearch_settings']['subsearch_translation']['#tree'] = FALSE;
  $form['subsearch_settings']['subsearch_translation']['#description'] = t('With translated subsearch you get the option for translated keys when the challenge is passed.');

  $form['subsearch_settings']['subsearch_translation']['translation_google_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Cloud Translation API key'),
    '#default_value' => variable_get('translation_google_key', ''),
    '#description' => t('You need to have an API key configured with billing for this to work. take a look at <a href="https://cloud.google.com/translate/pricing">Pricing</a>')
  );

  $form['subsearch_settings']['subsearch_translation']['google_translate_factor'] = array(
    '#type' => 'textfield',
    '#title' => t('Challenge: Factor for calculating ratio between nonfiction and fiction'),
    '#default_value' => variable_get('google_translate_factor', 2),
    '#description' => t('The condition is as following (nonfiction / factor) > fiction'),
  );

}