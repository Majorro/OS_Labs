#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

typedef struct
{
    char file_names[100][100];
    int cnt;
    int inode;
} file;

const int MAXN = 1e2;
char* root_dir = "tmp";

int main()
{
    file files[MAXN];
    DIR* dir = opendir(root_dir);

    for(int i=0; i<MAXN; ++i)
        files[i].inode = -1;

    struct dirent* cur_entry = readdir(dir);
    while(cur_entry != NULL)
    {
        struct stat cur_stat;
        char path[100] = "";
        strcat(path, root_dir);
        strcat(path, "/");
        char inode_found = 0;
        stat(strcat(path, cur_entry->d_name), &cur_stat);

        if(cur_stat.st_nlink <= 1)
        {
            cur_entry = readdir(dir);
            continue;
        }
        
        for(int i=0; i<MAXN; ++i)
        {
            if(files[i].inode == cur_stat.st_ino)
            {
                strcat(files[i].file_names[files[i].cnt], cur_entry->d_name);
                ++files[i].cnt;
                inode_found = 1;
                break;
            }
        }

        if(!inode_found)
            for(int i=0; i<MAXN; i++)
                if(files[i].inode == -1)
                {
                    files[i].inode = cur_stat.st_ino;
                    strcat(files[i].file_names[files[i].cnt], cur_entry->d_name);
                    ++files[i].cnt;
                    break;
                }

        cur_entry = readdir(dir);
    }
    (void)closedir(dir);
    

    for(int i=0; i<MAXN; i++)
    {
        if(files[i].inode == -1)
            break;

        printf("%d - ", files[i].inode);
        for(int j=0; j<files[i].cnt; j++)
            printf("%s ", files[i].file_names[j]);
        printf("\n");
    }

    return 0;
}