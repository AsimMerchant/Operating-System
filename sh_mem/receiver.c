#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{

  shm_open(const char *name, int oflag, mode_t mode);

  shm_unlink(const char *name);

  return 0;
}
