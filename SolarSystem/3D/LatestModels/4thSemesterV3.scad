//difference for making halfs of the model to fit it to a printer
//difference(){
union(){
//Big circle
difference(){ 
    //Main Cube
    translate([-60,-60,0])
    cube([120, 120, 120],center=false);
    
    //Small inner cube Cut out    
    translate([20,20,5])
    cube([35.3,35.3,35],center=false); 
    
    translate([-55,20,25])
    cube([35.3,35.3,35],center=false);  
    
    translate([20,-55,45])
    cube([35.3,35.3,35],center=false);  
    
    translate([-55,-55,65])
    cube([35.3,35.3,35],center=false);  
    
    //Wire Cut outs 
    translate([30,55,5])
    cube([15,15,115],center=false);
    
    translate([-45,55,25])
    cube([15,15,95],center=false);
    
    translate([30,-60,45])
    cube([15,15,75],center=false);
    
    translate([-45,-60,65])
    cube([15,15,55],center=false);
    
    //Cube cut outs above the motors
    translate([15,15,40])
    cube([45,45,80]);
    
    translate([-60.7,15,60])
    cube([45,45,60]);
    
    translate([15,-60.7,80])
    cube([45,45,40]);
    
    translate([-60.7,-60.7,100])
    cube([45,45,20]);
    
    //Cut outs to fit the gears 
    translate([37,37,40])
    cylinder(h=80,r=37,center = false,$fn=500);
    
    translate([-37,37,60])
    cylinder(h=60,r=37,center = false,$fn=500);
    
    translate([37,-37,80])
    cylinder(h=40,r=37,center = false,$fn=500);
    
    translate([-37,-37,100])
    cylinder(h=20,r=37,center = false,$fn=500);
    
    
    //Holes for bolts
    //Center
    cylinder(h=125, r = 5,center = false,$fn=500);
    //Middle on the sides
    translate([55,0,0])
    cylinder(h=125, r = 2.5,center = false,$fn=500);
    
    translate([0,55,0])
    cylinder(h=125, r = 2.5,center = false,$fn=500);
    
    translate([-55,0,0])
    cylinder(h=125, r = 2.5,center = false,$fn=500);
    
    translate([0,-55,0])
    cylinder(h=125, r = 2.5,center = false,$fn=500);
}
        
 
difference(){
//Foundation
    cylinder(h=40, r = 110,center =false,$fn=500);
    
    cylinder(h=40, r = 89,center =false,$fn=500);
    //Bearing holders
    difference(){
    translate([0,0,35]) 
    cylinder(h=5, r = 105,center =false,$fn=500); 
    translate([0,0,35])    
    cylinder(h=5, r = 95,center =false,$fn=500);    
}}

difference(){
   
    cylinder(h=5,r=90, center =false, $fn=500);
    //Mount cut outs
    cylinder(h=5,r=5, center = false,$fn=500);
    
    translate([55,0,0])
    cylinder(h=5, r = 2.5,center = false,$fn=500);
    
    translate([0,55,0])
    cylinder(h=5, r = 2.5,center = false,$fn=500);
    
    translate([-55,0,0])
    cylinder(h=5, r = 2.5,center = false,$fn=500);
    
    translate([0,-55,0])
    cylinder(h=5, r = 2.5,center = false,$fn=500);    
}  

}

/*
//First half
translate([-120,-120,0])
    cube([240, 120, 120],center=false);

//Second half 
translate([-120,-120,0])
    cube([240, 120, 120],center=false);
//}  