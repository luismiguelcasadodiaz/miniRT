#234567890123456789012345678901234567890123456789012345678901234567890123456789#
#        1         2         3         4         5         6         7         #
#..............................................................................#
# Luis Miguel Casado Díaz (LMCD) .gdbinit configuration file                   #
#                                                                              #
# 2024_06_09                                                                   #
#..............................................................................#

# To enable execution of this file, ensure you have a inside file
# ~/.config/gdb/gdbinit
# a line starting with add-auto-load-safe-path <absolute path to this file>
# add-auto-load-safe-path /home/......../circle4/namada_minshell/.gdbinit

# to enable Debuginfo
set debuginfod enabled on
# To print structs in a more readable form
set print pretty on
# Follow child at fork()
set follow-fork-mode child
# To keep father & child under control with "inferior" command
set detach-on-fork off
# Set Breakpoint at main function
break main.c:47
# Set other breakpoint
#break init.c:108
#break init.c:117
break win_init.c:111
break is_scene3.c:84 if wy0 == 280
break is_scene3.c:84 if wx0 == 435
#break is_scene4.c:83 if wx0 == 500
#break is_scene4.c:83 if wx0 == 565
#break is_scene2.c:71
#break is_scene2.c:62 if wy0 == 5
#break is_scene2.c:62 if wy0 == 23
#break is_scene2.c:62 if wy0 == 50
# set alias
run ./miniRT tirame
