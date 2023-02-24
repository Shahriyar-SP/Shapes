// by Shahriyar Sadeghpoor
//
//
#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <string>
#include <windows.h>
#define PI 3.14159265 // pi number
#define RA 57.2957795 // Radian to degree conversion factor
using namespace std;
bool saveStatus(1);
struct node { // list members
    string name, stype;
    void *ptr;
    node *next;
};
ostream& operator<<(ostream &os, node &myNode){
    os << "  Shape Type: " << myNode.stype << endl;
    os << "  Shape Name: " << myNode.name << endl;
}
int shapeID(string stype){ // get "shape type" and return an "ID"
    if(stype == "square"){return 1;}
    else if(stype == "rectangle"){return 2;}
    else if(stype == "hexagon"){return 3;}
    else if(stype == "circle"){return 4;}
    else if(stype == "ellipse"){return 5;}
    else if(stype == "parallelogram"){return 6;}
    else if(stype == "rightTriangle"){return 7;}
    else if(stype == "isoscelesTriangle"){return 8;}
    else if(stype == "equilateralTriangle"){return 9;}
    else if(stype == "cube"){return 10;}
    else if(stype == "cuboid"){return 11;}
    else if(stype == "sphere"){return 12;}
    else if(stype == "pyramid"){return 13;}
    else if(stype == "cylinder"){return 14;}
    else if(stype == "ellipsoid"){return 15;}
    else if(stype == "tetrahedron"){return 16;}
    else if(stype == "ellipseCylinder"){return 17;}
    return 0;
}
string shapeType(int type){ // get "ID" and return "Shape Type"
    switch(type){
        case 1:{ return "square";}
        case 2:{ return "rectangle";}
        case 3:{ return "hexagon";}
        case 4:{ return "circle";}
        case 5:{ return "ellipse";}
        case 6:{ return "parallelogram";}
        case 7:{ return "rightTriangle";}
        case 8:{ return "isoscelesTriangle";}
        case 9:{ return "equilateralTriangle";}
        case 10:{ return "cube";}
        case 11:{ return "cuboid";}
        case 12:{ return "sphere";}
        case 13:{ return "pyramid";}
        case 14:{ return "cylinder";}
        case 15:{ return "ellipsoid";}
        case 16:{ return "tetrahedron";}
        case 17:{ return "ellipseCylinder";}
        default:{ return 0;}
    }
}
//-----------------------------------------------------
class Shape2D{
public:
    float x, y; // This is not private because we need to use or change it out of class.
    Shape2D(){
        x = y = 0;
    }
    Shape2D(float x, float y){ // get and set x, y
        this->x = x;
        this->y = y;
    }
    float Area(){};
    float Perimeter(){};
};
class Shape3D : public Shape2D{ // all 3D shapes are 2D that have z
public:
    int z; // This is not private because we need to use or change it out of class.
    Shape3D() : Shape2D() {
        z = 0;
    }
    Shape3D(int x, int y, int z) : Shape2D(x,y){
        this->z = z;
    }
    float Volume(){};
    float sideArea(){};
};
class Parallelogram : public Shape2D {
public:
    float height;
    Parallelogram() : Shape2D() {}
    Parallelogram(float x, float y, float h) : Shape2D(x, y) {
        height = h; // shape parallelogram must have x, y and the height
    }
    float Area(){
        return height*y ;
    }
    float Perimeter(){
        return (x+y)*2 ;
    }
};
class Square : public Parallelogram{ // Square is a parallelogram that have equal x, y and height
public:
    Square() : Parallelogram() {}
    Square(float x) : Parallelogram(x, x, x) {}
};
class Rectangle : public Parallelogram{ // Rectangle is a parallelogram that have equal y and height
public:
    Rectangle() : Parallelogram() {}
    Rectangle(float x, float y) : Parallelogram(x, y, x) {}
};
class RightTriangle : public Shape2D {
private:
    float a1, a2;
public:
    RightTriangle() : Shape2D() {}
    RightTriangle(float x, float y) : Shape2D(x, y) {}
    float Area(){
        return (x*y)/2 ;
    }
    float Perimeter(){
        float lastSide;
        lastSide = sqrt((x*x) + (y*y));
        return (x + y + lastSide);
    }
    string Angles(){
        a1 = atan(x/y)*RA;
        a2 = atan(y/x)*RA;
        return ("Angles: 90 - " + to_string(a1) + " - " + to_string(a2));
    }

};
class IsoscelesTriangle : public Shape2D{ // Isosceles Triangle is a triangle that have 2 equal sides
private:
    float a12, a3;
public:
    IsoscelesTriangle() : Shape2D() {}
    IsoscelesTriangle(float x, float y) : Shape2D() {
        this->x = x;
        this->y = y;
    }
    float Area(){
        float height;
        height = sqrt(y*y - (x/2)*(x/2));
        return (x*height)/2 ;
    }
    float Perimeter(){
        return x + 2*y ;
    }
    string Angles(){
        a12 = acos((x/2)/y);
        a3 = PI - (a12 * 2);
        return ("Angles: " + to_string(a12*RA) + " - " + to_string(a12*RA) + " - " + to_string(a3*RA));
    }
};
class EquilateralTriangle : public Shape2D{// Equilateral Triangle is a triangle that have 3 equal sides
public:
    EquilateralTriangle() : Shape2D() {}
    EquilateralTriangle(float x) : Shape2D(x, x) {}
    float Area(){
        return (x*x) * sin(PI/3) / 2 ;
    }
    float Perimeter(){
        return x*3 ;
    }
};
class Hexagon : public Shape2D {
public:
    Hexagon() : Shape2D() {}
    Hexagon(float x) : Shape2D(x, 0) {}
    float Area(){
        return ((3*sqrt(3))/2)*x*x ;
    }
    float Perimeter(){
        return x*6 ;
    }
};
class Circle : public Shape2D {
public:
    Circle() : Shape2D() {}
    Circle(float r) : Shape2D(r, 0) {}
    float Area(){
        return PI * x * x;
    }
    float Perimeter(){
        return PI * x * 2;
    }
};
class Ellipse : public Shape2D{
public:
    Ellipse() : Shape2D() {}
    Ellipse(float x, float y) : Shape2D(x, y) {}
    float Area(){
        return PI * x * y;
    }
    float Perimeter(){
        return PI * sqrt(2*(x*x + y*y));
    }
};
class Cuboid : public Shape3D{
public:
    Cuboid() : Shape3D() {}
    Cuboid(float x, float y, float z) : Shape3D(x, y, z) {}
    float Volume(){
        return x*y*z;
    }
    float sideArea(){
        float Area = (x*y*2) + (x*z*2) + (y*z*2);
        return Area;
    }
};
class Cube : public Cuboid{ // Cube is a Cuboid that have equal x, y, z
public:
    Cube() : Cuboid() {}
    Cube(float x) : Cuboid(x, x, x) {}
};
class Pyramid : public Shape3D{
public:
    Pyramid() : Shape3D() {}
    Pyramid(float x, float h) : Shape3D(x,x,h) {}
    float Volume(){
        return x*x*z/3 ;
    }
    float sideArea(){
        float slantLength = sqrt((x/2)*(x/2) + z*z);
        return ( x*slantLength*2 + x*x );
    }
};
class EllipseCylinder : public Shape3D {
public:
    EllipseCylinder() : Shape3D() {}
    EllipseCylinder(float a, float b, float h) : Shape3D(a, b, h) {}
    float Volume(){
        return (PI*x*y*z);
    }
    float sideArea(){
        return (PI*x*y*2)+(z*PI*sqrt(2*(x*x + y*y)));
    }
};
class Cylinder : public EllipseCylinder { // Cylinder is a Ellipse Cylinder with circle base
public:
    Cylinder() : EllipseCylinder() {}
    Cylinder(float a, float h) : EllipseCylinder(a, a, h) {}
};
class Ellipsoid : Shape3D {
public:
    Ellipsoid() : Shape3D() {}
    Ellipsoid(float a, float b, float c) : Shape3D(a, b, c) {}
    float Volume(){
        return (4*PI*x*y*z)/3;
    }
    float sideArea(){
        float result;
        result = 4*PI*pow( ( (pow(x*y,1.6) + pow(x*z,1.6) + pow(y*z,1.6))/3 ) , (1/1.6) );
        return result;
    }
};
class Sphere : public Ellipsoid { // Sphere is a Ellipsoid that have equal x, y and z
public:
    Sphere() : Ellipsoid() {}
    Sphere(float r) : Ellipsoid(r, r, r) {}
};
class Tetrahedron : public Shape3D {
public:
    Tetrahedron() : Shape3D() {}
    Tetrahedron(float a) : Shape3D(a, a, a) {}
    float Volume(){
        return (x*x*x)/(6*sqrt(2));
    }
    float sideArea(){
        return sqrt(3)*x*x;
    }
};
//-----------------------------------------------------
class linkedList{
private:
    node *first, *last;
    int listLength;
public:
    linkedList(){
        first = last = NULL;
        listLength = 0;
    };
    void addMember(string name, void *ptr, string stype){ // get name , shape type and a void pointer to create new node in the node list
        node *newNode = new node;
        newNode->name = name;
        newNode->stype = stype;
        newNode->ptr = ptr;
        newNode->next = NULL;
        if(first){
            last->next = newNode;
            last = newNode;
        }
        else{first = last = newNode;}
        listLength++;
    }
    void Delete(string name){ // get a name, search for it and delete all nodes with that name
        node *c1, *c2;
        c1 = c2 = first;
        while (c1){
            if(c1->name == name){
                if(c1 == first){
                    first = first->next;
                }
                else{
                    if(c1 == last) last = c2;
                    c2->next = c1->next;
                }
                delete c1;
                listLength--;
                break;
            }
            else{
                c2 = c1;
                c1 = c1->next;
            }
        }
    }
    void DeleteAll(){
        node *p1, *p2;
        p2 = first;
        while (p2){
            p1 = p2->next;
            delete p2;
            p2 = p1;
        }
        first = last = NULL;
        listLength = 0;
    }
    void nodeSwap(node *p1, node *p2, node *p3){
        if(p2 == first) first = p3;
        else p1->next = p3;
        p2->next = p3->next;
        p3->next = p2;
        if(p2->next == NULL) last = p2;
    }
    void listSort(int a){
        if(!(a==1) && !(a==2)) return;
        if(first == last) return;
        node *p1, *p2, *p3;
        switch (a){
            case 1:{
                for(int i = 0; i < listLength; i++){
                    p2 = first;
                    p3 = first->next;
                    while (p3){
                        if(p2->name > p3->name) nodeSwap(p1, p2, p3);
                        p1 = p2;
                        p2 = p3;
                        p3 = p3->next;
                    }
                }
                break;
            }
            case 2:{
                for(int i = 0; i < listLength; i++){
                    p2 = first;
                    p3 = first->next;
                    while (p3){
                        if(p2->stype > p3->stype) nodeSwap(p1, p2, p3);
                        p1 = p2;
                        p2 = p3;
                        p3 = p3->next;
                    }
                }
                break;
            }
        }
    }
    int Length(){return listLength;}
    node *firstNode(){return first;}
};
linkedList shapeList;
class Menu {
public:
    static int show(){ // Show the main menu options
        system("CLS");
        cout << "----------------------Menu----------------------" << endl;
        cout << "Choose an Option:         " << endl;
        cout << "   [1] Add a New Shape    " << endl;
        cout << "   [2] Show all Shapes    " << endl;
        cout << "   [3] show only one type " << endl;
        cout << "   [4] Search a Shape     " << endl;
        cout << "   [5] Delete a Shape     " << endl;
        cout << "   [6] Load Shapes        " << endl;
        cout << "   [7] Save Shapes        " << endl;
        cout << "   [8] Delete All Shapes  " << endl;
        cout << "   [9] Exit               " << endl;
        cout << "\n>>> ";
        int option;
        cin >> option;
        return option;
    }
    static int Shape(){ // Show the add shape menu options
        system("CLS");
        cout << "----------------------Menu----------------------" << endl;
        cout << " What Shape do U want? " << endl;
        cout << "  2D Shapes:                 " << endl;
        cout << "    [1] Square               " << endl;
        cout << "    [2] Rectangle            " << endl;
        cout << "    [3] Hexagon              " << endl;
        cout << "    [4] Circle               " << endl;
        cout << "    [5] Ellipse              " << endl;
        cout << "    [6] Parallelogram        " << endl;
        cout << "    [7] Right Triangle       " << endl;
        cout << "    [8] Isosceles Triangle   " << endl;
        cout << "    [9] Equilateral Triangle " << endl;
        cout << "  3D Shapes:                 " << endl;
        cout << "    [10] Cube                " << endl;
        cout << "    [11] Cuboid              " << endl;
        cout << "    [12] Sphere              " << endl;
        cout << "    [13] Pyramid             " << endl;
        cout << "    [14] Cylinder            " << endl;
        cout << "    [15] Ellipsoid           " << endl;
        cout << "    [16] Tetrahedron         " << endl;
        cout << "    [17] Ellipse Cylinder    " << endl;
        cout << "  [0] Back to main menu...    " << endl;
        cout << "\n >>> ";
        int option;
        cin >> option;
        return option;
    }
    static void sortBy(){
        cout << " 1- Sort by name" << endl;
        cout << " 2- Sort by type" << endl;
        cout << " 3- Don't Sort" << endl;
        cout << ">>> ";
        int option; cin >> option;
        shapeList.listSort(option);
    }
};
void *shapeRestore(string stype, int x, int y, int z){ // will restore shapes by get 2D or 3D shape info
    switch(shapeID(stype)){
        case 1:{Square *p = new Square(x); return p; break;}
        case 2:{class::Rectangle *p = new class::Rectangle(x, y); return p; break;}
        case 3:{Hexagon *p = new Hexagon(x); return p; break;}
        case 4:{Circle *p = new Circle(x); return p; break;}
        case 5:{class::Ellipse *p = new class::Ellipse(x, y); return p; break;}
        case 6:{Parallelogram *p = new Parallelogram(x, y, z); return p; break;}
        case 7:{RightTriangle *p = new RightTriangle(x, y); return p; break;}
        case 8:{IsoscelesTriangle *p = new IsoscelesTriangle(x, y); return p; break;}
        case 9:{EquilateralTriangle *p = new EquilateralTriangle(x); return p; break;}
        case 10:{Cube *p = new Cube(x); return p; break;}
        case 11:{Cuboid *p = new Cuboid(x, y, z); return p; break;}
        case 12:{Sphere *p = new Sphere(x); return p; break;}
        case 13:{Pyramid *p = new Pyramid(x, y); return p; break;}
        case 14:{Cylinder *p = new Cylinder(x, y); return p; break;}
        case 15:{Ellipsoid *p = new Ellipsoid(x, y, z); return p; break;}
        case 16:{Tetrahedron *p = new Tetrahedron(x); return p; break;}
        case 17:{EllipseCylinder *p = new EllipseCylinder(x, y, z); return p; break;}
        default:{ break;}
    }
}
class shapeAdder{
private:
    float v1, v2, v3; // three int for the three sides of our shape
    string stype;
    void *ptr;
    string getName(){ // a function that gets name of the shape from user
        system("CLS");
        cout << "Name your Shape: (without 'space' character) >> ";
        string name;
        cin >> name;
        return name;
    }
    void get1value(){ // get one side value for shapes that need one like square
        cout << "Enter the size of one side (radius for circle or sphere): ";
        cin >> v1;
    }
    void get2values(){ // get two sides value for shapes that need tow like rectangle
        cout << "Enter the size of two sides (radius for Ellipse or Cylinder): \n  a: ";
        cin >> v1;
        cout << "  b: ";
        cin >> v2;
    }
    void get3values(){ // get three sides value for shapes that need three like parallelogram or ellipsoid
        cout << "Enter the size of three sides (radius for Ellipsoid or Elipse Cylinder):\n  a: ";
        cin >> v1;
        cout << "  b: ";
        cin >> v2;
        cout << "  c: ";
        cin >> v3;
    }
public:
    void adder(int type){ // just gets a type to start, then create a node by some informations that will get from user
        stype = shapeType(type);
        string name = getName();
        switch(type){
            case 1: case 3: case 4: case 9: case 10: case 12: case 16:{get1value(); break;}
            case 2: case 5: case 7: case 8: case 13: case 14:{get2values(); break;}
            case 6: case 11: case 15: case 17:{get3values(); break;}
        }
        ptr = shapeRestore(stype, v1, v2, v3); // we can create a shape with shapeRestore too.
        shapeList.addMember(name, ptr, stype); // call addMember function to add new shape to the list
        saveStatus = 0;
    }
};
class Shapes{
public:
    static void addShape(){
        shapeAdder myMethod;
        int menuOption;
        while (true){
            menuOption = Menu::Shape(); // gets menu options from the user
            if (menuOption == 0) break; // if user wants to back to main menu, break the loop
            myMethod.adder(menuOption); // prepare to add new shape

        }
    }
    static void deleteShape(){ // will call delete function from list options to delete a shape
        cout << "Enter the name of the shape that you want to delete: ";
        string name;
        cin >> name;
        shapeList.Delete(name);
    }
    static void shapeInfo(node *myNode, int counter){
        Shape2D *p = (Shape2D*) (myNode->ptr); // all of our shapes are 2D
        float y, z, area, perimeter, volume;
        string Angles;
        int ShapeType = shapeID(myNode->stype); // get shapes type ID
        cout << "----------------------------------------------\n";
        cout << "Shape [" << counter << "]\n";
        cout << *myNode;
        cout << "   x: " << p->x << endl; // All shape have "x"
        y = p->y; // All shapes have "y"
        switch (ShapeType){ // create node pointers and prepare data for show informations
            case 1:{
                Square *p = (Square*) (myNode->ptr);
                area = p->Area();
                perimeter = p->Perimeter();
                break;
            }
            case 2:{
                class::Rectangle *p = (class::Rectangle*) (myNode->ptr);
                area = p->Area();
                perimeter = p->Perimeter();
                break;
            }
            case 3:{
                Hexagon *p = (Hexagon*) (myNode->ptr);
                area = p->Area();
                perimeter = p->Perimeter();
                break;
            }
            case 4:{
                Circle *p = (Circle*) (myNode->ptr);
                area = p->Area();
                perimeter = p->Perimeter();
                break;
            }
            case 5:{
                class::Ellipse *p = (class::Ellipse*) (myNode->ptr);
                area = p->Area();
                perimeter = p->Perimeter();
                break;
            }
            case 6:{
                Parallelogram *p = (Parallelogram*) (myNode->ptr);
                area = p->Area();
                perimeter = p->Perimeter();
                y = p->y;
                z = p->height;
                cout << "   y: " << y << endl;
                cout << "   height: " << z << endl;
                break;
            }
            case 7:{
                RightTriangle *p = (RightTriangle*) (myNode->ptr);
                area = p->Area();
                perimeter = p->Perimeter();
                Angles = p->Angles();
                break;
            }
            case 8:{
                IsoscelesTriangle *p = (IsoscelesTriangle*) (myNode->ptr);
                area = p->Area();
                perimeter = p->Perimeter();
                Angles = p->Angles();
                break;
            }
            case 9:{
                EquilateralTriangle *p = (EquilateralTriangle*) (myNode->ptr);
                area = p->Area();
                perimeter = p->Perimeter();
                break;
            }
            case 10:{
                Cube *p = (Cube*) (myNode->ptr);
                area = p->sideArea();
                volume = p->Volume();
                break;
            }
            case 11:{
                Cuboid *p = (Cuboid*) (myNode->ptr);
                area = p->sideArea();
                volume = p->Volume();
                break;
            }
            case 12:{
                Sphere *p = (Sphere*) (myNode->ptr);
                area = p->sideArea();
                volume = p->Volume();
                break;
            }
            case 13:{
                Pyramid *p = (Pyramid*) (myNode->ptr);
                area = p->sideArea();
                volume = p->Volume();
                break;
            }
            case 14:{
                Cylinder *p = (Cylinder*) (myNode->ptr);
                area = p->sideArea();
                volume = p->Volume();
                break;
            }
            case 15:{
                Ellipsoid *p = (Ellipsoid*) (myNode->ptr);
                area = p->sideArea();
                volume = p->Volume();
                break;
            }
            case 16:{
                Tetrahedron *p = (Tetrahedron*) (myNode->ptr);
                area = p->sideArea();
                volume = p->Volume();
                break;
            }
            case 17:{
                EllipseCylinder *p = (EllipseCylinder*) (myNode->ptr);
                area = p->sideArea();
                volume = p->Volume();
                break;
            }
            default:{break;}
        }
        switch (ShapeType){
            case 2: case 5: case 7: case 8: case 13: case 14:{ // print "y"
                cout << "   y: " << y << endl;
                break;
            }
            case 11: case 15: case 17:{ // print "y" and "z"
                Shape3D *p = (Shape3D*) (myNode->ptr);
                z = p->z;
                cout << "   y: " << y << endl;
                cout << "   z: " << z << endl;
                break;
            }
            default:{break;}
        }
        if(ShapeType < 10 && ShapeType > 0){ // if shape is 2D
            cout << "   Area: " << area << endl;
            cout << "   Perimeter: " << perimeter << endl;
        }
        else if(ShapeType > 9){ // if shape is 3D
            cout << "   Side Area: " << area << endl;
            cout << "   Volume: " << volume << endl;
        }
        if(ShapeType == 7 || ShapeType == 8) // if shape is triangle
            cout << Angles << endl;
    }
    static void searchShape(){ // Search a shape by name
        linkedList searchResult; // maybe have two or more results. so create a list
        string keyWord;
        cout << "Enter the name of the shape that you want to search: (without space character!) ";
        cin >> keyWord;
        node *navigator = shapeList.firstNode(); // create a navigator to explore the list
        while (navigator){
            if(navigator->name == keyWord){ // if found a node, add to result list
                searchResult.addMember(navigator->name, navigator->ptr, navigator->stype);
            }
            navigator = navigator->next; // move to the next node
        }
        if(searchResult.firstNode() == NULL){
            cout << "There is no result for your search...";
            getch();
        }
        else
            showAllShapes(searchResult);
    }
    static void searchByType(){
        linkedList searchResult; // maybe have two or more results. so create a list
        string type = shapeType(Menu::Shape());
        node *navigator = shapeList.firstNode(); // create a navigator to explore the list
        while (navigator){
            if(navigator->stype == type) // if found a node, add to result list
                searchResult.addMember(navigator->name, navigator->ptr, navigator->stype);
            navigator = navigator->next; // move to the next node
        }
        if(searchResult.firstNode() == NULL){
            cout << "There is no result for your search...";
            getch();
        }
        else
            showAllShapes(searchResult);
    }
    static void showAllShapes(linkedList myList){
        system("CLS");
        int counter(1);
        node *navigator = myList.firstNode(); // create a navigator to explore the list
        cout << "****************** Show All Shapes ******************" << endl;
        if(!navigator) cout << "\n  There is no member in the list!\n\n";
        while (navigator){
            shapeInfo(navigator, counter);
            navigator = navigator->next;
            counter++;
        }
        cout << "****************** End of the List ******************" << endl;
        cout << "Press any key to continue...";
        getch();
    }
};
class Files {
public:
    static void save2file(){ // to save all data to a text file
        // we need to save only things that will get from user
        ofstream myFile;
        myFile.open("myfile.txt", ios_base::app);
        node *navigator = shapeList.firstNode(); // create a navigator to explore the list
        while(navigator){
            myFile << navigator->stype << " " << navigator->name << " " ;
            switch (shapeID(navigator->stype)){ // we must use shapes
                case 1: case 3: case 4: case 9: case 10: case 12: case 16:{
                    Shape2D *p = (Shape2D*) (navigator->ptr);
                    myFile << p->x << endl;
                    break;
                }
                case 2: case 5: case 7: case 8:{
                    Shape2D *p = (Shape2D*) (navigator->ptr);
                    myFile << p->x << " " << p->y << endl;
                    break;
                }
                case 13: case 14:{
                    Shape3D *p = (Shape3D*) (navigator->ptr);
                    myFile << p->x << " " << p->z << endl;
                    break;
                }
                case 6:{
                    Parallelogram *p = (Parallelogram*) (navigator->ptr);
                    myFile << p->x << " " << p->y << " " << p->height << endl;
                    break;
                }
                case 11: case 15: case 17:{
                    Shape3D *p = (Shape3D*) (navigator->ptr);
                    myFile << p->x << " " << p->y << " " << p->z << endl;
                    break;
                }
                default:
                    break;
            }
            navigator = navigator->next;
        }
        myFile.close();
        saveStatus = 1;
    }
    static void loadFile(){
        ifstream myFile("myfile.txt");
        int x, y, z, n(0);
        string name, stype;
        void *ptr;
        while (n<50 && myFile >> stype){
            myFile >> name >> x;
            switch (shapeID(stype)){
                case 1: case 3: case 4: case 9: case 10: case 12: case 16:{
                    ptr = shapeRestore(stype, x, 0, 0);
                    break;
                }
                case 2: case 5: case 7: case 8: case 13: case 14:{
                    myFile >> y;
                    ptr = shapeRestore(stype, x, y, 0);
                    break;
                }
                case 6: case 11: case 15: case 17:{
                    myFile >> y >> z;
                    ptr = shapeRestore(stype, x, y, z);
                    break;
                }
                default: break;
            }
            shapeList.addMember(name, ptr, stype);
            n++;
        }
        myFile.close();
    }
};
class Program{ // the central control unit of the program
public:
    static void start(){
        bool showMenu = 1;
        while(showMenu){
            switch (Menu::show()){
                case 1:{Shapes::addShape(); break;}
                case 2:{
                    if(shapeList.Length()){Menu::sortBy();}
                    Shapes::showAllShapes(shapeList);
                    break;
                }
                case 3:{Shapes::searchByType(); break;}
                case 4:{Shapes::searchShape(); break;}
                case 5:{Shapes::deleteShape(); break;}
                case 6:{Files::loadFile(); break;}
                case 7:{Files::save2file(); break;}
                case 8:{shapeList.DeleteAll(); break;}
                case 9:{showMenu = 0; break;}
                default: break;
            }
        }
    }
    ~Program(){
        if(!saveStatus){
            system("CLS");
            cout << " You don't save your list. are you sure you want to exit?" << endl;
            cout << "   1- Yes, I'm sure" << endl;
            cout << "   2- No, Save my list first." << endl;
            int option; cin >> option;
            system("CLS");
            switch (option){
                case 2:{
                    Files::save2file();
                    cout << " Your list saved successfully." << endl;
                }
                default: break;
            }
        }
        cout << " Good Luck! ";
        getch();
    }
};
int main(){
    Program thisProgram; // don't use static function because I want to use destructor...
    thisProgram.start();
    return 0;
}





