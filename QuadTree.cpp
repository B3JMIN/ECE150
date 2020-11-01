//
//  QuadTree.cpp
//  QuadTree
//
//  Created by Cai Huichuan on 2020-10-27.
//

#include "QuadTree.hpp"
#include <iostream>

using namespace std;



struct data {
    string name;
    double longtitude;
    double latitude;
    double population;
    double cost;
    double salary;
};


struct node {
    data data;
    node* NW;
    node* NE;
    node* SW;
    node* SE;
    
};

class QuadTree {


    node* root;

    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->NW);
            makeEmpty(t->NE);
            makeEmpty(t->SW);
            makeEmpty(t->SE);
            delete t;
        }
        return NULL;
    }

    node* insert(data x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->NW = t->NE = t->SW = t->SE = NULL;
        }
        else if(x.latitude >= t->data.latitude && x.longtitude > t->data.longtitude)
            t->NE = insert(x, t->NE);
        else if(x.latitude < t->data.latitude && x.longtitude >= t->data.longtitude)
            t->NW = insert(x, t->NW);
        else if(x.latitude <= t->data.latitude && x.longtitude < t->data.longtitude)
            t->SW = insert(x, t->SW);
        else if(x.latitude > t->data.latitude && x.longtitude <= t->data.longtitude)
            t->SE = insert(x, t->SE);
        else if(x.latitude == t->data.latitude && x.longtitude == t->data.longtitude)
            std::cout << "already there" << std::endl;
            return t;
        return t;
    }

//    find min value
    node* findMin(node* t, string dir, string attr)
    {
        node *temp{nullptr};
        if(t == NULL)
            return NULL;
        if (dir == "NE") {
            if (t->NE == NULL) {
                return t;
            }
            if (attr == "p") {
                if (t->data.population > temp->data.population){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NE, dir, attr);
                }
            }
            if (attr == "r") {
                if (t->data.cost > temp->data.cost){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NE, dir, attr);
                }
            }
            if (attr == "s") {
                if (t->data.salary > temp->data.salary){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NE, dir, attr);
                }
            }
        }
        if (dir == "NW") {
            if (t->NW == NULL) {
                return t;
            }
            if (attr == "p") {
                if (t->data.population > temp->data.population){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NW, dir, attr);
                }
            }
            if (attr == "r") {
                if (t->data.cost > temp->data.cost){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NW, dir, attr);
                }
            }
            if (attr == "s") {
                if (t->data.salary > temp->data.salary){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NW, dir, attr);
                }
            }
        }
        if (dir == "SW") {
            if (t->SW == NULL) {
                return t;
            }
            if (attr == "p") {
                if (t->data.population > temp->data.population){
                    temp = t;
                }
                while (t->SW != NULL) {
                    findMin(t->NE, dir, attr);
                }
            }
            if (attr == "r") {
                if (t->data.cost > temp->data.cost){
                    temp = t;
                }
                while (t->SW != NULL) {
                    findMin(t->SW, dir, attr);
                }
            }
            if (attr == "s") {
                if (t->data.salary > temp->data.salary){
                    temp = t;
                }
                while (t->SW != NULL) {
                    findMin(t->SW, dir, attr);
                }
            }
        }
        if (dir == "SE") {
            if (t->SE == NULL) {
                return t;
            }
            if (attr == "p") {
                if (t->data.population > temp->data.population){
                    temp = t;
                }
                while (t->SE != NULL) {
                    findMin(t->SE, dir, attr);
                }
            }
            if (attr == "r") {
                if (t->data.cost > temp->data.cost){
                    temp = t;
                }
                while (t->SE != NULL) {
                    findMin(t->SE, dir, attr);
                }
            }
            if (attr == "s") {
                if (t->data.salary > temp->data.salary){
                    temp = t;
                }
                while (t->SE != NULL) {
                    findMin(t->SE, dir, attr);
                }
            }
        }
        return temp;
    }

    
    node* findMax(node* t, string dir, string attr)
    {
        node *temp{nullptr};
        if(t == NULL)
            return NULL;
        if (dir == "NE") {
            if (t->NE == NULL) {
                return t;
            }
            if (attr == "p") {
                if (t->data.population < temp->data.population){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NE, dir, attr);
                }
            }
            if (attr == "r") {
                if (t->data.cost < temp->data.cost){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NE, dir, attr);
                }
            }
            if (attr == "s") {
                if (t->data.salary < temp->data.salary){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NE, dir, attr);
                }
            }
        }
        if (dir == "NW") {
            if (t->NW == NULL) {
                return t;
            }
            if (attr == "p") {
                if (t->data.population < temp->data.population){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NW, dir, attr);
                }
            }
            if (attr == "r") {
                if (t->data.cost < temp->data.cost){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NW, dir, attr);
                }
            }
            if (attr == "s") {
                if (t->data.salary < temp->data.salary){
                    temp = t;
                }
                while (t->NE != NULL) {
                    findMin(t->NW, dir, attr);
                }
            }
        }
        if (dir == "SW") {
            if (t->SW == NULL) {
                return t;
            }
            if (attr == "p") {
                if (t->data.population < temp->data.population){
                    temp = t;
                }
                while (t->SW != NULL) {
                    findMin(t->NE, dir, attr);
                }
            }
            if (attr == "r") {
                if (t->data.cost < temp->data.cost){
                    temp = t;
                }
                while (t->SW != NULL) {
                    findMin(t->SW, dir, attr);
                }
            }
            if (attr == "s") {
                if (t->data.salary < temp->data.salary){
                    temp = t;
                }
                while (t->SW != NULL) {
                    findMin(t->SW, dir, attr);
                }
            }
        }
        if (dir == "SE") {
            if (t->SE == NULL) {
                return t;
            }
            if (attr == "p") {
                if (t->data.population < temp->data.population){
                    temp = t;
                }
                while (t->SE != NULL) {
                    findMin(t->SE, dir, attr);
                }
            }
            if (attr == "r") {
                if (t->data.cost < temp->data.cost){
                    temp = t;
                }
                while (t->SE != NULL) {
                    findMin(t->SE, dir, attr);
                }
            }
            if (attr == "s") {
                if (t->data.salary < temp->data.salary){
                    temp = t;
                }
                while (t->SE != NULL) {
                    findMin(t->SE, dir, attr);
                }
            }
        }
        return temp;
    }


    node* find(node* t, data x) {
//        double min_diff_x{INFINITY};
//        double min_diff_y{INFINITY};
        if(t == NULL)
            return NULL;
        double diff_x = x.latitude - t->data.latitude;
        double diff_y = x.longtitude - t->data.longtitude;
//        if () {
//            <#statements#>
//        }
        if(diff_x>=0 && diff_y>0){
            return find(t->NE, x);
        }
        else if(diff_x<0 && diff_y >= 0){
            return find(t->NW, x);
        }
        else if(diff_x <=0 && diff_y < 0){
            return find(t->SW, x);
        }
        else if(diff_x > 0 && diff_y <= 0){
            return find(t->SE, x);
        }
        else
            return t;
    }
    
    
    void inorder(node* t) {
        if(t == NULL)
            return;
        cout << "longtitude:  " << t->data.longtitude;
        cout << "latitude:  " << t->data.latitude;
        cout << "population:  " << t->data.population;
        cout << "cost:  " << t->data.cost;
        cout << "salary:  " << t->data.salary;
        inorder(t->NE);
        cout << "NE:   " << endl;
        inorder(t->NW);
        cout << "NW:   " << endl;
        inorder(t->SE);
        cout << "SE:   " << endl;
        inorder(t->SW);
        cout << "SW:   " << endl;
    }
    
public:
    QuadTree() {
        root = NULL;
    }

    ~QuadTree() {
        root = makeEmpty(root);
    }

    void insert(data x) {
        root = insert(x, root);
    }
    
    double cumulate(node* t, string dir, string attr){
        double res{0};
        if (t== NULL) {
            return NULL;
        }
        if (dir == "NE") {
            if (attr == "p") {
                res += t->NE->data.population;
                return cumulate(t->NE, dir, attr);
            }
            else if (attr == "r"){
                res += t->NE->data.cost;
                return cumulate(t->NE, dir, attr);
            }
            else if (attr == "s"){
                res += t->NE->data.salary;
                return cumulate(t->NE, dir, attr);
            }
            else if (attr == "name"){
                res += 1;
                return cumulate(t->NE, dir, attr);
            }
        }
        if (dir == "NW") {
            if (attr == "p") {
                res += t->NW->data.population;
                return cumulate(t->NW, dir, attr);
            }
            else if (attr == "r"){
                res += t->NW->data.cost;
                return cumulate(t->NW, dir, attr);
            }
            else if (attr == "s"){
                res += t->NW->data.salary;
                return cumulate(t->NW, dir, attr);
            }
            else if (attr == "name"){
                res += 1;
                return cumulate(t->NW, dir, attr);
            }
        }
        if (dir == "SW") {
            if (attr == "p") {
                res += t->SW->data.population;
                return cumulate(t->SW, dir, attr);
            }
            else if (attr == "r"){
                res += t->SW->data.cost;
                return cumulate(t->SW, dir, attr);
            }
            else if (attr == "s"){
                res += t->SW->data.salary;
                return cumulate(t->SW, dir, attr);
            }
            else if (attr == "name"){
                res += 1;
                return cumulate(t->SW, dir, attr);
            }
        }
        if (dir == "SE") {
            if (attr == "p") {
                res += t->SE->data.population;
                return cumulate(t->SE, dir, attr);
            }
            else if (attr == "r"){
                res += t->SE->data.cost;
                return cumulate(t->SE, dir, attr);
            }
            else if (attr == "s"){
                res += t->SE->data.salary;
                return cumulate(t->SE, dir, attr);
            }
            else if (attr == "name"){
                res += 1;
                return cumulate(t->SE, dir, attr);
            }
        }
        else return 0;
        return res;
    }
    
    int numberOfCities(){
        double res{0};
        res += cumulate(root, "NW", "city");
        res += cumulate(root, "NE", "city");
        res += cumulate(root, "SW", "city");
        res += cumulate(root, "SE", "city");
        return res;
    }

    double find_max_value(node* t, string dir, string attr){
        if (attr == "p") {
            return findMax(t, dir, attr)->data.population;
        }
        if (attr == "r") {
            return findMax(t, dir, attr)->data.cost;
        }
        if (attr == "s") {
            return findMax(t, dir, attr)->data.salary;
        }
        return 0;
    }
    
    double find_min_value(node* t, string dir, string attr){
        if (attr == "p") {
            return findMin(t, dir, attr)->data.population;
        }
        if (attr == "r") {
            return findMin(t, dir, attr)->data.cost;
        }
        if (attr == "s") {
            return findMin(t, dir, attr)->data.salary;
        }
        return 0;
    }
    
    void display() {
        inorder(root);
        cout << endl;
    }
    
     string find(data x){
        return find(root, x)->data.name;
    }
    
};
