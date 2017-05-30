#include "player_window.h"
#include "ui_player_window.h"
#include <iostream>

player_window::player_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::player_window)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged, this, &player_window::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &player_window::on_durationChanged);

}

player_window::~player_window()
{
    delete ui;
}

void player_window::on_horizontalSlider_progress_sliderMoved(int position)
{
        player->setPosition(position);
}

void player_window::on_horizontalSlider_volume_sliderMoved(int position)
{
        player->setVolume(position);
}

void player_window::on_pushButton_clicked()
{
    std::cout << "Play button pressed" << std::endl;
    player->setMedia(QUrl::fromLocalFile("/Users/henryknowakowski/Projekt2_rozgrzewka2/mp3_files/BeBop25.mp3"));
    player->play();
    std::cout << "Play button pressed" << std::endl;
    qDebug() << player->errorString();
}

void player_window::on_pushButton_2_clicked()
{
    player->stop();
}

void player_window::on_positionChanged(qint64 position)
{
        ui->horizontalSlider_progress->setValue(position);
}

void player_window::on_durationChanged(qint64 position)
{
        ui->horizontalSlider_progress->setMaximum(position);
}

void player_window::on_pushButton_3_clicked()
{
    std::cout << "Push button pressed" << std::endl;

}
