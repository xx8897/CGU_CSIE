/*******************************************************************************
 *
 * to list directory content
 *
 ******************************************************************************/

#include <unistd.h>

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

#include <stdio.h>

#define MAX_PATH_LEN	500

main()
{
	char cwd[MAX_PATH_LEN];
	DIR *dp;
	struct dirent *dir_ent_info;
	char ent_path_name[MAX_PATH_LEN];
	struct stat inode_info;
	int is_file;
	int is_dir;

	getcwd (cwd, MAX_PATH_LEN);
	dp = opendir (cwd);
	while ((dir_ent_info=readdir(dp))!=NULL) {
		//get inode info of an directory entry
		sprintf (ent_path_name, "%s/%s", cwd, dir_ent_info->d_name);
		stat (ent_path_name, &inode_info);

		//check type of a directory entry
		is_file = S_ISREG (inode_info.st_mode);
		is_dir = S_ISDIR (inode_info.st_mode);

		//print-out info
		if (is_file)
			printf ("%s:\tinode=%d\tsize=%d\tn_link=%d\n",
				dir_ent_info->d_name,
				inode_info.st_ino,
				inode_info.st_size,
				inode_info.st_nlink
			);

		if (is_dir)
			printf ("%s:\tinode=%d\t<DIR>\tn_link=%d\n",
				dir_ent_info->d_name,
				inode_info.st_ino,
				inode_info.st_nlink
			);
	}

	return 0;
}//main()

















