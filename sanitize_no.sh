#!/usr/bin/bash
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/ambil/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/camer/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/chunk/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/color/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/eleme/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/getnl/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/hitrecord/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/hittable/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/interval/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/libft/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/light/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/point/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/ray/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/vec3/Makefile

#sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/error/Makefile
#sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/ftpri/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' Makefile
