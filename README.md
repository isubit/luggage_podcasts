# luggage_podcasts

A podcast feature that provides iTunes/RSS feeds and an HTML5 podcast player [Podlove Web Player](http://podlove.org/podlove-web-player/).

## Installation

Commandline where $DRUPAL_ROOT is the root of your Drupal site:

```bash
cd $DRUPAL_ROOT/sites/all/libraries

curl -L 'https://sourceforge.net/projects/getid3/files/getID3%28%29%201.x/1.8.5/getid3-1.8.5-20110218.zip' > getid3-1.8.5-20110218.zip
unzip getid3-1.8.5-20110218.zip
rm getid3-1.8.5-20110218.zip
mv getid3-1.8.5-20110218 getid3
rm -rf getid3/demos

git clone https://github.com/njbooher/podlove-web-player-dist.git podlove-web-player

cd $DRUPAL_ROOT/sites/all/modules

# this specific version is required by views_rss_itunes
drush dl getid3-7.x-1.0
drush en getid3

git clone https://github.com/isubit/luggage_podcasts
drush en luggage_podcasts
```

As part of enabling luggage_podcasts, drush will have downloaded the jquery_update module. After enabling the feature, go to the jQuery update config page and set 'Default jQuery Version' to 1.8. The omega base theme used by suitcase requires jQuery.browser which was removed in 1.9.