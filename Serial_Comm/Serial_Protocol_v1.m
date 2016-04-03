# Opens serial port ttyUSB1 with baudrate of 9600 and 8 bits data
pkg load instrument-control 
Serial_Object=serial("/dev/ttyUSB0", 9600); 
# Flush input and output buffers
srl_flush(Serial_Object);
Data_Buffer= cell(50,1);
y=0; 
t=0;
while t<50
for i = 1:50
   srl_write(Serial_Object, 's');
   Frame= srl_read(Serial_Object,3);
   if Frame(3)=='e'
    Accepted_Data=int32(Frame(1:2));
    Ten_Bit_Data=bitshift(Accepted_Data(2),8)+ Accepted_Data(1);
    Data_Buffer{i,1} = Ten_Bit_Data;
   else 
       srl_flush(Serial_Object);
       srl_write(Serial_Object, 'r');
   end 
endfor
 t=t+1;
 y = cat(1, y, y_temp{1:50})
 plot(y)
 pause(0)
 #drawnow;
 y=0;
endwhile
# Convert uint8 array to string, 
char(data);
srl_close(s1)