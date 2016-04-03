# Opens serial port ttyUSB1 with baudrate of 115200 (config defaults to 8-N-1)
pkg load instrument-control 
s1 = serial("/dev/ttyUSB0", 9600); 
# Flush input and output buffers
srl_flush(s1);
y_temp = cell(50,1);
y=0; 
t=0;
# Blocking write call, currently only accepts strings
while t<50
for i = 1:50
   srl_write(s1, 's');
   y_serial = srl_read(s1,3);
   # Blocking read call, returns uint8 array of exactly 12 bytes read
   Without_e=int32(y_serial(1:end-1));
   Signals=bitshift(Without_e(2),8)+Without_e(1)
   y_temp {i,1} = Signals;
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