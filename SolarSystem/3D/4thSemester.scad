
difference(){ 
    translate([-45,-45,0])
    cube([90, 90, 100],center=false);
    
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
    cube([40,40,60]);
     
    translate([-45.7,5,60])
    cube([41,41,40]);
    
    translate([5,-45.7,80])
    cube([40,41,40]);
    
    cylinder(h=100, r = 5,center =false,$fn=500);
    
}
        
    
difference(){
    //translate([42,42,0])
    cylinder(h=40, r = 75,center =false,$fn=500);
    //translate([42,42,0])
    cylinder(h=40, r = 65,center =false,$fn=500);
    difference(){
    translate([0,0,37.5]) 
    cylinder(h=2.5, r = 62.5,center =false,$fn=500); 
    translate([0,0,37.5])    
    cylinder(h=2.5, r = 57.5,center =false,$fn=500);    
}}

/*difference(){
    translate([0,0,50])
    cylinder(h=10, r = 65,center =false,$fn=500);
    translate([0,0,50])
    cylinder(h=10, r = 55,center =false,$fn=500);
    difference(){
    translate([0,0,50]) 
    cylinder(h=2.5, r = 62.5,center =false,$fn=500); 
    translate([0,0,50])    
    cylinder(h=2.5, r = 57.5,center =false,$fn=500); 
    }
    difference(){
    translate([0,0,53.5]) 
    cylinder(h=2.5, r = 62.5,center =false,$fn=500); 
    translate([0,0,53.5])    
    cylinder(h=2.5, r = 57.5,center =false,$fn=500); 
    }
    }
    

    

    
/*
difference(){
translate([0,0,40]) 
cylinder(h=5, r = 62.5,center =false,$fn=100); 
 
translate([0,0,40])    
cylinder(h=5, r = 57.5,center =false,$fn=100);    
    
}


    
/*difference(){    
    translate([40,0,0])
    cube([45, 45, 40],center=false);
    translate([45,5,5])
    cube([35.3,35.3,35],center=false);  
    }
    
!difference(){    
    translate([0,40,0])
    cube([45, 45, 40],center=false);
    translate([5,45,5])
    cube([35.3,35.3,35],center=false);  
    }
difference(){    
    translate([40,40,0])
    cube([45, 45, 40],center=false);
    translate([45,45,5])
    cube([35.3,35.3,35],center=false);  
    }
 


 /*   
!difference(){
    circle(50,$fn=50);
    circle(45,$fn=50);
 
     }
//cylinder(h=5, r = 5,true);
//cylinder(h=5, r = 5);}
//union();
//cylinder(h=5, r = 5);}

//difference();
