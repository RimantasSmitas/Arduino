difference(){
translate([37,37,65])
cylinder(h=10,r=15,center =false,$fn=500);
translate([37,37,65])   
cylinder(h=10, r =2.5,center =false,$fn=500);
 translate([37,37,70])   
 rotate(a=[0,90,0],v=[0,0,1]) { 
 cylinder(h=15,r=2.5,center=false,$fn=500);
  }
   
 
 translate([37,37,70])
  rotate(a=[90,0,0],v=[0,0,1]) { 
 cylinder(h=15,r=2.5,center=false,$fn=500);
  } 

}
difference (){
    translate([37,37,55])
    cylinder(h=10, r=36,center=false,$fn=500);
    translate([37,37,55])   
    cylinder(h=10, r =2.5,center=false,$fn=500);}

//Teeth for gear
translate([37,37,55])
linear_extrude(height=10){
    for (i = [0:150]){
        rotate (a=i *360/120, v=[0,0,35])
        translate([0,35,0])
        polygon([[-1,0],[-0.2,3],        [0.2,3],[1,0]]);
        }
     }