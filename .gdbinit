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
#break a la entrade de una función
#break eleme_hittables_sph.c:hit_sphere 
# Set other breakpoint
#break init.c:108
#break init.c:117
break main.c:
#break win_init.c:75

#break draw_fractal.c:21
# 1000 * 9/16 = 562   | 500 * 9/16 = 281
# 562 / 2     = 281   | 281 / 2    = 140
#break is_scene4.c:73  if ((wy0 == 140) && (wx0 ==250))
#break eleme_hittables_sph.c:63 if (discriminant > 0)
#break hitrecord_copy
break is_scene4.c:53
break eleme_hit.c:33
#break eleme_init.c:44
#break win_create_world.c:41
#break eleme_hittables_pln.c:46
run ./miniRT tirame
