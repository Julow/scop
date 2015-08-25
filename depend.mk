O_FILES :=	o/srcs/init.o o/srcs/key_events.o o/srcs/main.o \
			o/srcs/math_utils/ft_math/ft_mat4identity.o \
			o/srcs/math_utils/ft_math/ft_mat4mult.o \
			o/srcs/math_utils/ft_math/ft_mat4rotate.o \
			o/srcs/math_utils/ft_math/ft_mat4scale.o \
			o/srcs/math_utils/ft_math/ft_mat4translate.o \
			o/srcs/mesh_loader/create_mesh.o o/srcs/mesh_loader/ft_loadmesh.o \
			o/srcs/shader_loader/create_shader.o \
			o/srcs/texture_loader/ft_loadimage.o \
			o/srcs/texture_loader/tga_parser.o o/srcs/utils/ft_subint.o \
			o/srcs/utils/ft_time.o

o/srcs/init.o: srcs/init.c include/scop.h include/ft_loadimg.h \
	include/ft_loadmesh.h include/ft_3dmath.h include/ft_3dmath.h | o/srcs
o/srcs/key_events.o: srcs/key_events.c include/scop.h include/ft_loadimg.h \
	include/ft_loadmesh.h include/ft_3dmath.h include/ft_3dmath.h | o/srcs
o/srcs/main.o: srcs/main.c include/scop.h include/ft_loadimg.h \
	include/ft_loadmesh.h include/ft_3dmath.h include/ft_3dmath.h | o/srcs
o/srcs/math_utils/ft_math/ft_mat4identity.o: \
	srcs/math_utils/ft_math/ft_mat4identity.c include/ft_3dmath.h \
	| o/srcs/math_utils/ft_math
o/srcs/math_utils/ft_math/ft_mat4mult.o: srcs/math_utils/ft_math/ft_mat4mult.c \
	include/ft_3dmath.h | o/srcs/math_utils/ft_math
o/srcs/math_utils/ft_math/ft_mat4rotate.o: \
	srcs/math_utils/ft_math/ft_mat4rotate.c include/ft_3dmath.h \
	| o/srcs/math_utils/ft_math
o/srcs/math_utils/ft_math/ft_mat4scale.o: \
	srcs/math_utils/ft_math/ft_mat4scale.c include/ft_3dmath.h \
	| o/srcs/math_utils/ft_math
o/srcs/math_utils/ft_math/ft_mat4translate.o: \
	srcs/math_utils/ft_math/ft_mat4translate.c include/ft_3dmath.h \
	| o/srcs/math_utils/ft_math
o/srcs/mesh_loader/create_mesh.o: srcs/mesh_loader/create_mesh.c \
	include/scop.h include/ft_loadimg.h include/ft_loadmesh.h \
	include/ft_3dmath.h include/ft_3dmath.h | o/srcs/mesh_loader
o/srcs/mesh_loader/ft_loadmesh.o: srcs/mesh_loader/ft_loadmesh.c \
	include/scop.h include/ft_loadimg.h include/ft_loadmesh.h \
	include/ft_3dmath.h include/ft_3dmath.h include/ft_loadmesh.h \
	include/ft_3dmath.h | o/srcs/mesh_loader
o/srcs/shader_loader/create_shader.o: srcs/shader_loader/create_shader.c \
	include/scop.h include/ft_loadimg.h include/ft_loadmesh.h \
	include/ft_3dmath.h include/ft_3dmath.h | o/srcs/shader_loader
o/srcs/texture_loader/ft_loadimage.o: srcs/texture_loader/ft_loadimage.c \
	include/ft_loadimg.h | o/srcs/texture_loader
o/srcs/texture_loader/tga_parser.o: srcs/texture_loader/tga_parser.c \
	include/ft_loadimg.h | o/srcs/texture_loader
o/srcs/utils/ft_subint.o: srcs/utils/ft_subint.c | o/srcs/utils
o/srcs/utils/ft_time.o: srcs/utils/ft_time.c include/scop.h \
	include/ft_loadimg.h include/ft_loadmesh.h include/ft_3dmath.h \
	include/ft_3dmath.h | o/srcs/utils
