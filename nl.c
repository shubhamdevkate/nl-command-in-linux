/*****************************************************************************
 * Copyright (C) Shubham A. Devkate 	shubham.devkate1998@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	/* if no file, read standard input */
	if(argc == 1){
		input();
	}
	/* if only file is specified */
	if(argc == 2){
		if(strcmp(argv[1], "--help") == 0)
			help();
		else 
			nl_print1(argv[1]);
	}
	if(argc == 4){
		if(strcmp(argv[1], "-b") == 0){
			/* nl -b a file */
			if(strcmp(argv[2], "a") == 0)
				nl_print1(argv[3]);

			/* nl -b t file */
			else if(strcmp(argv[2], "t") == 0)
				nl_print2(argv[3]);	
			/* nl -b n file */
			else if(strcmp(argv[2], "n") == 0)
				nl_print3(argv[3]);
		}
		else if(strcmp(argv[1], "-n") == 0){	
			/* nl -n ln file */
			if(strcmp(argv[2], "ln") == 0)
				nl_ln(argv[3]);
			/* nl -n rn file */
			else if(strcmp(argv[2], "rn") == 0)
				nl_print2(argv[3]);
			/* nl -n rz file */
			else if(strcmp(argv[2], "rz") == 0)
				nl_rz(argv[3]);		
		}
		else if(strcmp(argv[1], "-i") == 0){
			/* nl -i NUMBER file */
			nl_i(atoi(argv[2]), argv[3]);
		}
		else if(strcmp(argv[1], "-w") == 0){
			/* nl -w NUMBER file */
			nl_w(atoi(argv[2]), argv[3]);
		}
		else if(strcmp(argv[1], "-s") == 0){
			/* nl -s STRING file */
			nl_s(argv[2], argv[3]);
		}
	}
	return 0;
}
