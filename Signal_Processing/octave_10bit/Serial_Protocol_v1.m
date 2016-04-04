# Opens serial port ttyUSB1 with baudrate of 9600 and 8 bits data
pkg load instrument-control 
Serial_Object=serial("/dev/ttyUSB0", 9600); 
# Flush input and output buffers
srl_flush(Serial_Object);
Samples_Number=50;
Data_Buffer= cell(Samples_Number,1);
Acquired_Data=0; 
While_Counter=0;
while While_Counter<50
for i = 1:Samples_Number
   srl_write(Serial_Object, 's');
   Frame= srl_read(Serial_Object,3);
   if Frame(3)=='e'
    Accepted_Data=int16(Frame(1:2));
    Ten_Bit_Data=bitshift(Accepted_Data(2),8)+ Accepted_Data(1);
    Data_Buffer{i,1} = Ten_Bit_Data;
   else 
       srl_flush(Serial_Object);
       srl_write(Serial_Object, 'r');
   endif
endfor
While_Counter++;
Acquired_Data= cat(1,Acquired_Data,Data_Buffer{:});
XStart=(While_Counter-1)*Samples_Number;
XEnd=((While_Counter-1)*Samples_Number)+Samples_Number;
plot(Acquired_Data);
xlim([XStart XEnd]);
pause(0);
endwhile
srl_close(s1)