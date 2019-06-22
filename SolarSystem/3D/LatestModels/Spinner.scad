

difference(){
//Big Cilinder
union(){
difference(){
    union(){
    translate([0,0,50])
    cylinder(h=20, r = 110,center =false,$fn=500);
    
    ///////////////////////////
 translate([0,-101,50])
 
 difference(){
    difference(){ 
        translate ([-45,-50,0])
        cube ([90,50,20]);
        
        translate ([-45,-30,0])
        cylinder (h = 20, r=30, center = false, $fn=100);
        
        translate ([45,-30,0])
        cylinder (h = 20, r=30, center = false, $fn=100); 
        }
        
    translate ([0,0,10])
rotate(a=[90,90,0],v=[0,0,1]) { 
    cylinder(h=50, r=6.4, center=false, $fn=500);}
       
  
    translate ([0,-15,0])
    cylinder (h = 20, r=2, center = false, $fn=100);
    
    translate ([0,-30,0])
    cylinder (h = 20, r=2, center = false, $fn=100);
    
    translate ([0,-45,0])
    cylinder (h = 20, r=2, center = false, $fn=100);
    
    rotate(a=[0,90,0],v=[0,0,1]) { 
    translate ([-10,-45,-20])
    cylinder (h = 40, r=2, center = false, $fn=100);
    }    
        
    translate ([-25,-50,0])
    cube ([10,20,20]);
     
    translate ([15,-50,0])
    cube ([10,20,20]);
}
}
////////////////////////////////
//Inner circle cut out
translate([0,0,50])
    cylinder(h=20, r = 89,center =false,$fn=500);

//translate([-5,-144,55])
//cube([10,55,10])    
    
//Gear teeth 
    translate([0,0,50])
    linear_extrude(height=20){
    for  (i = [0:360]){
    rotate (a=i *360/360, v=[0,0,90])
    translate([0,88,0])
    polygon([[-1,0],[-0.2,4],[0.2,4],[1,0]]);
        }}



//Bottom cut out for bearing 
      
    difference(){ 
    translate([0,0,50]) 
    cylinder(h=4.5, r = 105,center =false,$fn=500); 
    translate([0,0,50])    
    cylinder(h=4.5, r = 95,center =false,$fn=500); 
    }
 
    
//Top cut out for bearing 
    difference(){
    translate([0,0,65]) 
    cylinder(h=5, r = 105,center =false,$fn=500); 
    translate([0,0,65])    
    cylinder(h=5, r = 95,center =false,$fn=500); 
    }
    }
}

/*
//Uncomment to make a cut out to fit the 3d printer.
translate([0,0,0])
    cube([360, 360, 100],center=false);


translate([-360,0,0])
    cube([360, 360, 100],center=false);


translate([0,-360,0])
    cube([360, 360, 100],center=false);

translate([-360,-360,0])
    cube([360, 360, 100],center=false);




}
*/
//Small gear
 union(){   
difference(){
translate([37,37,65])
cylinder(h=10,r=15,center =false,$fn=500);
translate([37,37,65])   
cylinder(h=10, r =2.5,$fn=500);
 translate([37,37,70])   
 rotate(a=[0,90,0],v=[0,0,1]) { 
 cylinder(h=15,r=2,center=false,$fn=500);
  }
translate([37,37,70])
  rotate(a=[90,0,0],v=[0,0,1]) { 
 cylinder(h=15,r=2,center=false,$fn=500);}  
}

difference (){
    translate([37,37,55])
    cylinder(h=10, r=36,center=false,$fn=500);
    translate([37,37,55])   
    cylinder(h=10, r =2.5,center=false,$fn=500);
}

//Teeth for gear
translate([37,37,55])
linear_extrude(height=10){
    for (i = [0:120]){
        rotate (a=i *360/120, v=[0,0,35])
        translate([0,35,0])
        polygon([[-1,0],[-0.2,4],        [0.2,4],[1,0]]);
        }
     }
 }
 }
 /*
 translate([0,-102.5,50])
 difference(){
    difference(){ 
        translate ([-40,-40,0])
        cube ([80,40,20]);
        
        translate ([-40,-30,0])
        cylinder (h = 20, r=30, center = false, $fn=100);
        
        translate ([40,-30,0])
        cylinder (h = 20, r=30, center = false, $fn=100);
     }

    translate ([-5,-40,5])
    cube ([10,40,10]);
 
    translate ([0,-30,0])
    cylinder (h = 20, r=2, center = false, $fn=100);
    
    translate ([-20,-40,0])
    cube ([10,10,20]);
     
    translate ([10,-40,0])
    cube ([10,10,20]);
}