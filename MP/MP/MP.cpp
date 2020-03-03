#include "MP.h"

MP::MP(QWidget *parent)
	: QMainWindow(parent),player(new QMediaPlayer(this)),playlist(new QMediaPlaylist(this))
{
	ui.setupUi(this);
	//playlist->addMedia(QUrl::fromLocalFile("D:/Users/HP/Music/01.Time (Official).flac"));
	playlist->addMedia(QUrl::fromLocalFile("D:/Users/HP/Music/Alan Walker - Alone.mp3"));
	playlist->setPlaybackMode(QMediaPlaylist::Loop);
	player->setPlaylist(playlist);
	player->setVolume(80);
	connect(ui.playBtn, SIGNAL(clicked()), this, SLOT(OnPlay()));
	connect(ui.pauseBtn, SIGNAL(clicked()), this, SLOT(OnPause()));
	connect(ui.addBtn, SIGNAL(clicked()), this, SLOT(OnAdd()));
	connect(ui.nextBtn, SIGNAL(clicked()), this, SLOT(OnNext()));
	connect(ui.lastBtn, SIGNAL(clicked()), this, SLOT(OnLast()));
	connect(ui.volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(OnChangeVolume()));
}
