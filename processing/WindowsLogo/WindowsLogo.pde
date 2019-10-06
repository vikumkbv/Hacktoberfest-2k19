// When the shape hits the ese of the window, it reversses its direction
// update in italian means 'aggiornamento'

// windows 95 screensaver that i used to stare for hours when i was young 
PImage img;

// shape, flag logo windows
//int rad = 60;
float xpos, ypos; // STARTING POSITION

//speed of the shape
float xspeed = 3;
float yspeed = 3;

int xdirection = 1; //Left or right
int ydirection = 1; // Top to Bottom

void setup()
{
  size(640,360);
  
  img = loadImage("logo.png");
  
  //noStroke();
  frameRate(30); 
  //ellipseMode(RADIUS);
  
  //set starting position, usually the center
  xpos = width/2;
  ypos = height/2;
  
}
void draw()
{
  background(#008080);
  
  //Update POSITION of the shape 
  // velocity = space / time

  xpos = xpos + ( xspeed * xdirection );
  ypos = ypos + ( yspeed * ydirection );  
  
  // reverse direction
  if (xpos > width-img.width/2 || xpos < img.width/2) {
    xdirection *= -1;
  }
  if (ypos > height-img.height/2 || ypos < img.height/2) {
    ydirection *= -1;
  }

  // DRAW SHAPE
  image(img, xpos, ypos, img.width/2, img.height/2);
  //ellipse(xpos, ypos, rad, rad);
}
