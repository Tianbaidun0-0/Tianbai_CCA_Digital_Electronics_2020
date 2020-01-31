import processing.video.*;

Capture video;
void setup(){
 size(600,600);
video = new Capture(this,320,240,30);
video.resize(600,600);
video.start();
}

void draw(){

 noStroke();
if(video.available()){video.read();}
image(video,0,0,600,600);
 video.loadPixels();
for(int i=0;i<video.width;i++){
   for(int j=0;j<video.height;j++){
      int loc = video.width * j + i;
     color c= video.pixels[loc];
     float r =red(c);
     float g = green(c); 
     float b = blue(c);
     
       if((r>200&&g<100&&b<100)||(r>200&&g>200&&b<100)||(r<20&&g<20&&b<20)){
         float ii = map(i,0,video.width,0,width);
          float jj = map(j,0,video.height,0,height);
         fill(c);
        ellipse(ii,jj,15,15);
       }
   
    
   }
}

}
