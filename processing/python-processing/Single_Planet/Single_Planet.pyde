w, h = 800, 800

pfc = (255, 255, 255)
olc = (0, 0, 0)
bgc = (255, 255, 255)

pw = 7
rw = 7

def draw_planet(position, ps):
    pushMatrix()
    
    # translate(position[0], position[1])
    starting_height = random(ps/4, ps/2)
    starting_width = random(ps*1.2, ps*2)
    rotate(random(2*PI))
    
    
    # Add colored circle
    fill(pfc[0], pfc[1], pfc[2])
    strokeWeight(pw)
    circle(0, 0, ps)
    
    # Settings for the rings
    noFill()
    strokeWeight(rw)
    for i in range(int(random(4, 12))):
        ellipse(0, 0, starting_height + i * 10, starting_width + i * 30)
    
    # Cover up part of the rings
    strokeWeight(pw)
    fill(pfc[0], pfc[1], pfc[2])
    arc(0, 0, ps, ps, 1.5*PI, 2.5*PI);
    
    popMatrix()

def setup():
    size(w, h)
    pixelDensity(2)
    frameRate(1)
    
    translate(w/2, h/2)
    
    stroke(olc[0], olc[1], olc[2])
    
    background(bgc[0], bgc[1], bgc[2])

    draw_planet((w/2, h/2), random(100, 400))
    
    save("Examples/" + str(int(random(1000))) + ".png")
        
