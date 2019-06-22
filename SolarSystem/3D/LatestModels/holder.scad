 
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