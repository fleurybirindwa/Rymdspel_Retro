#include <QApplication>
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

/*
Tutorial Topics:
-collidingItems() <- new topic
-QTimer and coordinate systems <- old topics (review)
*/

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels

    // add the item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(900,700);
    scene->setSceneRect(0,0,900,700);

    player->setPos(view->width()/2,view->height() - player->rect().height());

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
