//Lucas Fulmer


#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "BSTree.h"
#include "BSTree.hpp"
#include <vector>
#include <iostream>

using namespace std;
void actorMenu(BSTree<Actor, string>* _actorTree);
void pictureMenu(BSTree<Picture, string>* _pictureTree);
void searchActor(BSTree<Actor, string>* _actorTree);
void searchPicture(BSTree<Picture, string>* _pictureTree);
void sortActor(BSTree<Actor, string>* _actorTree);
void sortPicture(BSTree<Picture, string>* _pictureTree);
void modifyOrRemoveActor(BSTree<Actor, string>* _actorTree);
void modifyOrRemovePic(BSTree<Picture, string>* _pictureTree);

#endif // !FUNCTIONS_H
