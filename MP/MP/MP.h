#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MP.h"
#include<qmediaplayer.h>
#include<qmediaplaylist.h>
#include<qfiledialog>
#include<qdialog.h>
class MP : public QMainWindow
{
	Q_OBJECT

public:
	MP(QWidget *parent = Q_NULLPTR);
	QMediaPlayer* player;
	QMediaPlaylist* playlist;
private slots:
	void OnPlay()
	{
		player->play();
	}
	void OnAdd()
	{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("D:/Users/HP/Music"), tr("(*.mp3)"));
		playlist->addMedia(QUrl::fromLocalFile(fileName));
		
		ui.list->addItem(fileName);
	}
	void OnPause()
	{
		player->pause();
	}
	void OnChangeVolume()
	{
		player->setVolume(ui.volumeSlider->value());
	}
	void OnNext()
	{
		int row = playlist->mediaCount();
		int cur = playlist->currentIndex();
		if (++cur >= row)
		{
			cur = 0;
		}
		playlist->setCurrentIndex(cur);
		ui.list->scrollToItem(ui.list->item(cur));
		player->play();
	}
	void OnLast()
	{
		int row = playlist->mediaCount();
		int cur = playlist->currentIndex();
		if (--cur < 0)
		{
			cur = row-1;
		}
		playlist->setCurrentIndex(cur);
		ui.list->scrollToItem(ui.list->item(cur));
		player->play();
	}
private:
	Ui::MPClass ui;
};
