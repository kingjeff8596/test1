#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wiringPiI2C.h>


int main(int argc, char **argv)
{

	int fd;			// File descrition

	char *fileName = "/dev/i2c-1";				// Name of the port we will be using
	int  address = 0x74;	

								// Address of the SRF08 shifted right 1 bit
	unsigned char buf[6]={0,0,0,0,0,0}; 
 	unsigned char buff[6]={0,0,0,0,0,0}; 
  __u8 reg; 								
  __s32 res;
  
  FILE *fptr1;


float fdata1[1000];
 
	if ((fd = open(fileName, O_RDWR)) < 0) {	// Open port for reading and writing
		printf("Failed to open i2c port\n");
		exit(1);
	}
	
	if (ioctl(fd, I2C_SLAVE, address) < 0) {		// Set the port options and set the address of the device we wish to speak to
		printf("Unable to get bus access to talk to slave\n");
		exit(1);
	}
	
	
while(1)
{
	printf("**** NOW POSITION ****\n");
	buff[0]=0x01;
  res=i2c_smbus_write_i2c_block_data(fd, 0, 1, buff);
  usleep(100000);
                   
  res=i2c_smbus_read_i2c_block_data(fd, 2, 1, buf);

  c=buf[0];
 
     printf("position: %X \n",c);
     while(1);
    
   /*fdata1[s++]=speed1/619.0;
   
    if(ii<1)
   	{
   		++ii;

   	}   
    
   
    if(s==1000)
    {
        fdata1[0]=0;     
        fptr1=fopen("/home/pi/txt/l_speed1.txt","w"); 
       
        if(fptr1!=NULL)
	      {  
           for(l_speed=0;l_speed<=999;l_speed++)
           {
              fprintf(fptr1,"%f\n",fdata1[l_speed]); 
           }          
		
	      }
	      else
	      {
           printf("OPEN FAILED!\n"); 
	      }	
             
        fclose(fptr1);
    }	*/
   
   
   } 
}
