
difference(){ 
    translate([-45,-45,0])
    cube([90, 90, 120],center=false);
    
    translate([5,5,5])
    cube([35.3,35.3,35],center=false); 
    
    translate([-40,5,25])
    cube([35.3,35.3,35],center=false);  
    
    translate([5,-40,45])
    cube([35.3,35.3,35],center=false);  
    
    translate([-40,-40,65])
    cube([35.3,35.3,35],center=false);  
    
    
    translate([35,15,5])
    cube([15,15,75],center=false);
    
    translate([-45,15,25])
    cube([15,15,65],center=false);
    
    translate([40,-30,45])
    cube([15,15,50],center=false);
    
    translate([-45,-30,65])
    cube([15,15,45],center=false);
    
    
    translate([5,5,40])
    cube([40,40,80]);
     
    translate([-45.7,5,60])
    cube([41,41,60]);
    
    translate([5,-45.7,80])
    cube([40,41,40]);
    
    translate([-45.7,-45.7,100])
    cube([41,41,20]);
    
    cylinder(h=125, r = 5,center = false,$fn=500);
    
    translate([35,0,0])
    cylinder(h=125, r = 2.5,center = false,$fn=500);
    
    translate([0,35,0])
    cylinder(h=125, r = 2.5,center = false,$fn=500);
    
    translate([-35,0,0])
    cylinder(h=125, r = 2.5,center = false,$fn=500);
    
    translate([0,-35,0])
    cylinder(h=125, r = 2.5,center = false,$fn=500);
}
        
    
difference(){
    cylinder(h=40, r = 85,center =false,$fn=500);
    
    cylinder(h=40, r = 65,center =false,$fn=500);
    
    difference(){
    translate([0,0,35]) 
    cylinder(h=5, r = 80,center =false,$fn=500); 
    translate([0,0,35])    
    cylinder(h=5, r = 70,center =false,$fn=500);    
}}

difference(){
    cylinder(h=5,r=85, center =false, $fn=500);
    
    cylinder(h=5,r=5, center = false,$fn=500);
    
    translate([35,0,0])
    cylinder(h=5, r = 2.5,center = false,$fn=500);
    
    translate([0,35,0])
    cylinder(h=5, r = 2.5,center = false,$fn=500);
    
    translate([-35,0,0])
    cylinder(h=5, r = 2.5,center = false,$fn=500);
    
    translate([0,-35,0])
    cylinder(h=5, r = 2.5,center = false,$fn=500);    
}