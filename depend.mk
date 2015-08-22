O_FILES := \
	o/srcs/mesh_loader/ft_loadmesh.o \
	o/srcs/main.o \
	o/srcs/ft_math/ft_mat4translate.o \
	o/srcs/ft_math/ft_mat4identity.o \
	o/srcs/ft_time.o \
	o/srcs/ft_math/ft_mat4scale.o \
	o/srcs/window.o \
	o/srcs/create_shader.o \
	o/srcs/ft_loadimg/tga_parser.o \
	o/srcs/ft_math/ft_mat4rotate.o \
	o/srcs/ft_math/ft_mat4mult.o \
	o/srcs/create_mesh.o \
	o/srcs/callback.o \
	o/srcs/ft_loadimg/ft_loadimage.o \


o/srcs/mesh_loader/ft_loadmesh.o: srcs/mesh_loader/ft_loadmesh.c include/ft_loadmesh.h | o/srcs/mesh_loader

o/srcs/main.o: srcs/main.c include/scop.h include/ft_loadimg.h include/ft_loadmesh.h include/ft_3dmath.h | o/srcs

o/srcs/ft_math/ft_mat4translate.o: srcs/ft_math/ft_mat4translate.c include/ft_3dmath.h | o/srcs/ft_math

o/srcs/ft_math/ft_mat4identity.o: srcs/ft_math/ft_mat4identity.c include/ft_3dmath.h | o/srcs/ft_math

o/srcs/ft_time.o: srcs/ft_time.c include/scop.h include/ft_loadimg.h include/ft_loadmesh.h include/ft_3dmath.h | o/srcs

o/srcs/ft_math/ft_mat4scale.o: srcs/ft_math/ft_mat4scale.c include/ft_3dmath.h | o/srcs/ft_math

o/srcs/window.o: srcs/window.c include/scop.h include/ft_loadimg.h include/ft_loadmesh.h include/ft_3dmath.h | o/srcs

o/srcs/create_shader.o: srcs/create_shader.c include/scop.h include/ft_loadimg.h include/ft_loadmesh.h include/ft_3dmath.h | o/srcs

o/srcs/ft_loadimg/tga_parser.o: srcs/ft_loadimg/tga_parser.c include/ft_loadimg.h | o/srcs/ft_loadimg

o/srcs/ft_math/ft_mat4rotate.o: srcs/ft_math/ft_mat4rotate.c include/ft_3dmath.h | o/srcs/ft_math

o/srcs/ft_math/ft_mat4mult.o: srcs/ft_math/ft_mat4mult.c include/ft_3dmath.h | o/srcs/ft_math

o/srcs/create_mesh.o: srcs/create_mesh.c include/scop.h include/ft_loadimg.h include/ft_loadmesh.h include/ft_3dmath.h | o/srcs

o/srcs/callback.o: srcs/callback.c include/scop.h include/ft_loadimg.h include/ft_loadmesh.h include/ft_3dmath.h | o/srcs

o/srcs/ft_loadimg/ft_loadimage.o: srcs/ft_loadimg/ft_loadimage.c include/ft_loadimg.h | o/srcs/ft_loadimg
