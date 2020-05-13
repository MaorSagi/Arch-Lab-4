#include "lab4_util.h"

#define SYS_GETDENTS 78
#define SYS_READ 0
#define SYS_WRITE 1
#define SYS_OPEN 2
#define SYS_LSEEK 8
#define STDIN 0
#define STDOUT 1
#define RDONLY 0
#define EXIT 60

int argc2;
char** argv2;


void
copy (char *tmp_buf, char *name, char *tmp_buf2)
{
  int j = 0;

  while (j < simple_strlen (tmp_buf))
    {
      tmp_buf2[j] = tmp_buf[j];
      j++;
    }
  tmp_buf2[j] = '/';
  int i = 0;
  while (i < simple_strlen (name))
    {
      tmp_buf2[i + j+1] = name[i];
      i++;
    }
  tmp_buf2[i + j+1] = '\0';

}




struct linux_dirent
{
  unsigned long d_ino;
  unsigned long d_off;
  unsigned short d_reclen;
  char d_name[];
} linux_dirent;



void
recur_get_dents (char *tmp_buf)
{


  int size = 1024;
  char buffer[size];
  int get_dents;
  char d_type;
  struct linux_dirent *d_ent;
  int file = 0;
  file = system_call (SYS_OPEN, tmp_buf, RDONLY, 0x400);
  if (file < 0)
    system_call (EXIT, 85);
  int i = 0;


  while(1){
    
      get_dents =
	system_call (SYS_GETDENTS, file, buffer, sizeof (char) * size);
      if (get_dents < 0)
	system_call (EXIT, 85);
      if (get_dents == 0)
	break;

      
      while (get_dents > i)
	{

	  d_ent = buffer + i;
	  d_type = *(buffer + i + d_ent->d_reclen - 1);

	  if (d_ent->d_ino > 0)
	    {

	      if (d_type == 8 || d_type == 4)
		{
		  if (*(d_ent->d_name) != '.')
		    {
		      char tmp_buf2[simple_strlen(tmp_buf) +
				    simple_strlen(d_ent->d_name) + 2];
		      copy(tmp_buf, d_ent->d_name, tmp_buf2);
			if(argc2>1 && simple_strcmp(argv2[1],"-n")==0 && simple_strcmp(d_ent->d_name,argv2[2])==0){
		      system_call (SYS_WRITE, STDOUT, tmp_buf2,
				   sizeof (char) * simple_strlen(tmp_buf2));
		      system_call (SYS_WRITE, STDOUT, "\n", sizeof (char));
			}
		      if (d_type == 4)
			recur_get_dents (tmp_buf2);
		    }

		}


	    }
		i = i + d_ent->d_reclen;
	}

      
    }

}





int
main (int argc, char *argv[])
{
  argc2=argc;
  argv2=argv;
  recur_get_dents (".");
  return 0;
}

